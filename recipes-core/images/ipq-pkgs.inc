#List of the packages for IPQ Platform categorized

IMAGE_FEATURES += "package-management"

IPQ_BASE_PKGS = "sysstat strace dropbear e2fsprogs kexec-tools libnl uci bridge-utils u-boot-fw-utils"

NETWORK_PKGS = "ethtool iproute2 iptables iputils dhcp-server wireless-tools"

NSS_PKGS = " \
	    qca-nss-drv \
	    qca-nss-gmac \
	    qca-edma \
	    "

SSDK_PKGS ="qca-ssdk qca-ssdk-shell"

WIFI_PKGS = "qca-hostapd qca-wpasupplicant qca-wififw qca-wifi qca-wifi-tools"
