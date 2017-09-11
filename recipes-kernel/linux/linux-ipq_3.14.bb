LICENSE = "GPLv2"

require recipes-kernel/linux/linux-qca-ipq.inc
require recipes-kernel/linux/linux-ipq-fit.inc

LINUX_VERSION ?= "3.14"
LINUX_DESCRIPTION = "QCA IPQ Linux 3.14"

SRC_URI = "file://kernel \
	   file://ipq40xx-defconfig \
	   "
S = "${WORKDIR}/kernel"
SRC_URI += "file://fit"

COMPATIBLE_MACHINE = "(ipq806x|ipq40xx)"
KERNEL_IMAGETYPE ?= "Image"
