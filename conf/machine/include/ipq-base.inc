SOC_FAMILY = "IPQ"

include conf/machine/include/soc-family.inc
include conf/machine/include/tune-cortexa7.inc

IMAGE_FSTYPES = "squashfs squashfs-xz ext4"
SYSVINIT_ENABLED_GETTYS = ""

KARCH = "arm"
KERNEL_IMAGETYPE ?= "Image"

MACHINE_FEATURES += "apm usbhost keyboard squashfs vfat ext2 screen touchscreen bluetooth wifi sdio"

MACHINE_EXTRA_RRECOMMENDS += " kernel-modules kernel-devicetree"

RDEPENDS_kernel-base = ""
