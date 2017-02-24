#List of the packages for IPQ Platform categorized

# UBI image generation support
include recipes-core/images/ipq-images.inc

IMAGE_FEATURES += "package-management"

IPQ_BASE_PKGS = "sysstat strace dropbear e2fsprogs kexec-tools libnl uci bridge-utils u-boot-fw-utils mtd initoverlay procps watchdog"

NETWORK_PKGS = "ethtool iproute2 iproute2-tc iptables iputils dhcp-server wireless-tools mcproxy qca-mcs-lkm qca-mcs-app"

NSS_PKGS = " \
	    qca-nss-drv \
	    qca-nss-gmac \
	    qca-edma \
	    shortcut-fe \
	    "

RFS_PKGS = "qca-rfs"

SSDK_NOHNAT_PKGS ="qca-ssdk-nohnat qca-ssdk-shell"

SSDK_HNAT_PKGS ="qca-ssdk-hnat qca-ssdk-shell"

WIFI_PKGS = "qca-hostapd qca-wpasupplicant qca-wififw qca-wifi qca-wifi-tools qca-wrapd"

TEST_PKGS = "iozone3 dosfstools lrzsz i2c-tools gptfdisk samba tcpdump"

UTILS = "perf pm-utils sysstat file rng-tools iperf"
