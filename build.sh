#!/bin/sh

# Kernel, BusyBox, and musl Toolchain Versions and URLs
KERNEL_VERSION="4.19.322"
KERNEL_URL="https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-$KERNEL_VERSION.tar.xz"
BUSYBOX_VERSION="1.36.0"
BUSYBOX_URL="https://busybox.net/downloads/busybox-$BUSYBOX_VERSION.tar.bz2"
MUSL_TOOLCHAIN_URL="https://musl.cc/i486-linux-musl-cross.tgz"

# Directories
BUILD_ROOT_DIR=$(pwd)
CONFIG_DIR="./configs"
CONFIG_FILE="$CONFIG_DIR/linux.config"
BUILD_DIR="$BUILD_ROOT_DIR/build"
TOOLCHAIN_DIR="$BUILD_DIR/toolchain"
ROOTFS_DIR="$BUILD_DIR/rootfs"  # Root filesystem directory
FLOPPY_IMG="$BUILD_DIR/floppy.img"  # Virtual floppy disk image file
MNT_DIR="$BUILD_DIR/mnt"  # Temporary mount directory for the floppy
SYSLINUX_CFG="$MNT_DIR/syslinux.cfg"  # Syslinux configuration file path

set -xe

# Function to download and extract Linux kernel
download_kernel() {
    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR" || exit 1
    wget -c -q "$KERNEL_URL" -O "linux-$KERNEL_VERSION.tar.xz"
    tar xf "linux-$KERNEL_VERSION.tar.xz"
}

# Function to download and extract BusyBox
download_busybox() {
    cd "$BUILD_DIR" || exit 1
    wget -c -q "$BUSYBOX_URL" -O "busybox-$BUSYBOX_VERSION.tar.bz2"
    tar xf "busybox-$BUSYBOX_VERSION.tar.bz2"
}

# Function to download and extract musl toolchain
download_toolchain() {
    mkdir -p "$TOOLCHAIN_DIR"
    cd "$TOOLCHAIN_DIR" || exit 1
    wget -c -q "$MUSL_TOOLCHAIN_URL" -O "i486-linux-musl-cross.tgz"
    tar xf "i486-linux-musl-cross.tgz"
}

# Function to copy kernel config
copy_config() {
    cp "$1" "$2"
}

# Function to build Linux kernel
build_kernel() {
    cd "$BUILD_DIR/linux-$KERNEL_VERSION" || exit 1
    copy_config "$BUILD_ROOT_DIR"/"$CONFIG_FILE" "$BUILD_DIR/linux-$KERNEL_VERSION/.config"
    make -j"$(nproc)"
}

# Function to build BusyBox using musl toolchain
build_busybox() {
    cd "$BUILD_DIR/busybox-$BUSYBOX_VERSION" || exit 1

    # Set up the cross-compilation environment
    export CROSS_COMPILE="$TOOLCHAIN_DIR/i486-linux-musl-cross/bin/i486-linux-musl-"
    export ARCH=i486

    copy_config "$BUILD_ROOT_DIR"/"configs/busybox.config" "$BUILD_DIR/busybox-$BUSYBOX_VERSION/.config"
    make -j"$(nproc)"
    make install
}

# Function to create the root filesystem structure
setup_rootfs() {
    mkdir -p "$ROOTFS_DIR"

    cd "$ROOTFS_DIR" || exit 1

    mkdir -p bin etc sbin usr lib proc

    cp -r "$BUILD_DIR/busybox-$BUSYBOX_VERSION/_install"/* "$ROOTFS_DIR"

    cd -
}

setup_init() {
    cp -a "$BUILD_ROOT_DIR/init/." "$ROOTFS_DIR/"
}

# Function to create CPIO archive of the root filesystem
create_cpio_archive() {
    cd "$ROOTFS_DIR" || exit 1
    find . | cpio -o -H newc | gzip > "$BUILD_DIR/rootfs.cpio.xz"
}

# Function to create and format a virtual floppy image in FAT32
create_floppy_image() {
    # Size of floppy image in bytes (1.44MB)
    FLOPPY_SIZE=$((1440 * 1024))

    # Create a blank floppy image
    dd if=/dev/zero of="$FLOPPY_IMG" bs=512 count=$((FLOPPY_SIZE / 512))

    mkfs.fat -F 12 "$FLOPPY_IMG"
}

# Function to install Syslinux bootloader on the floppy image
install_syslinux() {
    mkdir -p "$MNT_DIR"
    # Mount the floppy image
    sudo mount -o loop "$FLOPPY_IMG" "$MNT_DIR"

    # Create Syslinux configuration file
    sudo bash -c "cat > $SYSLINUX_CFG" <<EOF
	DEFAULT linux
	LABEL linux
  	KERNEL /bzImage
  	APPEND initrd=/rootfs.cpio.xz
EOF

    # Unmount the floppy image
    sudo umount "$MNT_DIR"
    sudo syslinux --install "$FLOPPY_IMG"
}

# Function to mount the floppy image and copy the kernel and rootfs to it
copy_files_to_floppy() {
    mkdir -p "$MNT_DIR"
    
    # Mount the floppy image
    sudo mount -o loop "$FLOPPY_IMG" "$MNT_DIR"

    sudo cp "$BUILD_DIR/linux-$KERNEL_VERSION/arch/x86/boot/bzImage" "$MNT_DIR/bzImage"
    sudo cp "$BUILD_DIR/rootfs.cpio.xz" "$MNT_DIR/rootfs.cpio.xz"

    # Unmount the floppy image
    sudo umount "$MNT_DIR"
}

# Main execution
download_toolchain
download_kernel
build_kernel

download_busybox
build_busybox

setup_rootfs
setup_init
create_cpio_archive

create_floppy_image
copy_files_to_floppy
install_syslinux
