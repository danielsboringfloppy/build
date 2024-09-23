/* This is a generated file, don't edit */

#define NUM_APPLETS 96
#define KNOWN_APPNAME_OFFSETS 4

const uint16_t applet_nameofs[] ALIGN2 = {
125,
264,
409,
};

const char applet_names[] ALIGN1 = ""
"arch" "\0"
"ash" "\0"
"base32" "\0"
"base64" "\0"
"beep" "\0"
"bzip2" "\0"
"cal" "\0"
"cat" "\0"
"chgrp" "\0"
"chmod" "\0"
"chown" "\0"
"chroot" "\0"
"clear" "\0"
"cp" "\0"
"cpio" "\0"
"cut" "\0"
"date" "\0"
"dd" "\0"
"df" "\0"
"dmesg" "\0"
"dos2unix" "\0"
"du" "\0"
"echo" "\0"
"eject" "\0"
"false" "\0"
"fdisk" "\0"
"find" "\0"
"free" "\0"
"grep" "\0"
"gunzip" "\0"
"gzip" "\0"
"halt" "\0"
"head" "\0"
"hwclock" "\0"
"id" "\0"
"init" "\0"
"insmod" "\0"
"install" "\0"
"kill" "\0"
"killall" "\0"
"less" "\0"
"link" "\0"
"ln" "\0"
"lsmod" "\0"
"man" "\0"
"md5sum" "\0"
"mkdir" "\0"
"mkfs.vfat" "\0"
"mkswap" "\0"
"modinfo" "\0"
"mount" "\0"
"mv" "\0"
"nice" "\0"
"nl" "\0"
"poweroff" "\0"
"printf" "\0"
"pwd" "\0"
"readahead" "\0"
"reboot" "\0"
"reset" "\0"
"rm" "\0"
"rmdir" "\0"
"rmmod" "\0"
"sed" "\0"
"seq" "\0"
"sh" "\0"
"sha1sum" "\0"
"sha256sum" "\0"
"sha512sum" "\0"
"sleep" "\0"
"sort" "\0"
"stat" "\0"
"strings" "\0"
"stty" "\0"
"swapoff" "\0"
"swapon" "\0"
"switch_root" "\0"
"tar" "\0"
"time" "\0"
"top" "\0"
"touch" "\0"
"true" "\0"
"umount" "\0"
"uname" "\0"
"uniq" "\0"
"unix2dos" "\0"
"unxz" "\0"
"uptime" "\0"
"vi" "\0"
"wc" "\0"
"which" "\0"
"whoami" "\0"
"xxd" "\0"
"xz" "\0"
"xzcat" "\0"
"yes" "\0"
;

#define APPLET_NO_arch 0
#define APPLET_NO_ash 1
#define APPLET_NO_base32 2
#define APPLET_NO_base64 3
#define APPLET_NO_beep 4
#define APPLET_NO_bzip2 5
#define APPLET_NO_cal 6
#define APPLET_NO_cat 7
#define APPLET_NO_chgrp 8
#define APPLET_NO_chmod 9
#define APPLET_NO_chown 10
#define APPLET_NO_chroot 11
#define APPLET_NO_clear 12
#define APPLET_NO_cp 13
#define APPLET_NO_cpio 14
#define APPLET_NO_cut 15
#define APPLET_NO_date 16
#define APPLET_NO_dd 17
#define APPLET_NO_df 18
#define APPLET_NO_dmesg 19
#define APPLET_NO_dos2unix 20
#define APPLET_NO_du 21
#define APPLET_NO_echo 22
#define APPLET_NO_eject 23
#define APPLET_NO_false 24
#define APPLET_NO_fdisk 25
#define APPLET_NO_find 26
#define APPLET_NO_free 27
#define APPLET_NO_grep 28
#define APPLET_NO_gunzip 29
#define APPLET_NO_gzip 30
#define APPLET_NO_halt 31
#define APPLET_NO_head 32
#define APPLET_NO_hwclock 33
#define APPLET_NO_id 34
#define APPLET_NO_init 35
#define APPLET_NO_insmod 36
#define APPLET_NO_install 37
#define APPLET_NO_kill 38
#define APPLET_NO_killall 39
#define APPLET_NO_less 40
#define APPLET_NO_link 41
#define APPLET_NO_ln 42
#define APPLET_NO_lsmod 43
#define APPLET_NO_man 44
#define APPLET_NO_md5sum 45
#define APPLET_NO_mkdir 46
#define APPLET_NO_mkswap 48
#define APPLET_NO_modinfo 49
#define APPLET_NO_mount 50
#define APPLET_NO_mv 51
#define APPLET_NO_nice 52
#define APPLET_NO_nl 53
#define APPLET_NO_poweroff 54
#define APPLET_NO_printf 55
#define APPLET_NO_pwd 56
#define APPLET_NO_readahead 57
#define APPLET_NO_reboot 58
#define APPLET_NO_reset 59
#define APPLET_NO_rm 60
#define APPLET_NO_rmdir 61
#define APPLET_NO_rmmod 62
#define APPLET_NO_sed 63
#define APPLET_NO_seq 64
#define APPLET_NO_sh 65
#define APPLET_NO_sha1sum 66
#define APPLET_NO_sha256sum 67
#define APPLET_NO_sha512sum 68
#define APPLET_NO_sleep 69
#define APPLET_NO_sort 70
#define APPLET_NO_stat 71
#define APPLET_NO_strings 72
#define APPLET_NO_stty 73
#define APPLET_NO_swapoff 74
#define APPLET_NO_swapon 75
#define APPLET_NO_switch_root 76
#define APPLET_NO_tar 77
#define APPLET_NO_time 78
#define APPLET_NO_top 79
#define APPLET_NO_touch 80
#define APPLET_NO_true 81
#define APPLET_NO_umount 82
#define APPLET_NO_uname 83
#define APPLET_NO_uniq 84
#define APPLET_NO_unix2dos 85
#define APPLET_NO_unxz 86
#define APPLET_NO_uptime 87
#define APPLET_NO_vi 88
#define APPLET_NO_wc 89
#define APPLET_NO_which 90
#define APPLET_NO_whoami 91
#define APPLET_NO_xxd 92
#define APPLET_NO_xz 93
#define APPLET_NO_xzcat 94
#define APPLET_NO_yes 95

#ifndef SKIP_applet_main
int (*const applet_main[])(int argc, char **argv) = {
uname_main,
ash_main,
baseNUM_main,
baseNUM_main,
beep_main,
bzip2_main,
cal_main,
cat_main,
chgrp_main,
chmod_main,
chown_main,
chroot_main,
clear_main,
cp_main,
cpio_main,
cut_main,
date_main,
dd_main,
df_main,
dmesg_main,
dos2unix_main,
du_main,
echo_main,
eject_main,
false_main,
fdisk_main,
find_main,
free_main,
grep_main,
gunzip_main,
gzip_main,
halt_main,
head_main,
hwclock_main,
id_main,
init_main,
modprobe_main,
install_main,
kill_main,
kill_main,
less_main,
link_main,
ln_main,
lsmod_main,
man_main,
md5_sha1_sum_main,
mkdir_main,
mkfs_vfat_main,
mkswap_main,
modinfo_main,
mount_main,
mv_main,
nice_main,
nl_main,
halt_main,
printf_main,
pwd_main,
readahead_main,
halt_main,
reset_main,
rm_main,
rmdir_main,
modprobe_main,
sed_main,
seq_main,
ash_main,
md5_sha1_sum_main,
md5_sha1_sum_main,
md5_sha1_sum_main,
sleep_main,
sort_main,
stat_main,
strings_main,
stty_main,
swap_on_off_main,
swap_on_off_main,
switch_root_main,
tar_main,
time_main,
top_main,
touch_main,
true_main,
umount_main,
uname_main,
uniq_main,
dos2unix_main,
unxz_main,
uptime_main,
vi_main,
wc_main,
which_main,
whoami_main,
xxd_main,
unxz_main,
unxz_main,
yes_main,
};
#endif

const uint8_t applet_install_loc[] ALIGN1 = {
0x11,
0x11,
0x33,
0x13,
0x11,
0x41,
0x13,
0x31,
0x11,
0x11,
0x33,
0x31,
0x21,
0x33,
0x11,
0x21,
0x23,
0x23,
0x32,
0x31,
0x13,
0x21,
0x33,
0x21,
0x22,
0x11,
0x31,
0x32,
0x41,
0x32,
0x11,
0x12,
0x13,
0x33,
0x13,
0x13,
0x13,
0x22,
0x12,
0x33,
0x11,
0x11,
0x33,
0x33,
0x31,
0x33,
0x33,
0x33,
};
