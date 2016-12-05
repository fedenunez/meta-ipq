#List of the packages for IPQ Platform categorized

# UBI image generation support
include recipes-core/images/ipq-images.inc

IMAGE_FEATURES += "package-management"

IPQ_BASE_PKGS = "sysstat strace dropbear e2fsprogs kexec-tools libnl uci bridge-utils u-boot-fw-utils mtd initoverlay procps"

NETWORK_PKGS = "ethtool iproute2 iptables iputils dhcp-server wireless-tools"

NSS_PKGS = " \
	    qca-nss-drv \
	    qca-nss-gmac \
	    qca-edma \
	    shortcut-fe \
	    "

SSDK_PKGS ="qca-ssdk qca-ssdk-shell"

WIFI_PKGS = "qca-hostapd qca-wpasupplicant qca-wififw qca-wifi qca-wifi-tools"

TEST_PKGS = "iozone3 dosfstools lrzsz"
