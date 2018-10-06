LICENSE = "GPLv2"

require recipes-kernel/linux/linux-qca-ipq.inc
require recipes-kernel/linux/linux-ipq-fit.inc

LINUX_VERSION ?= "4.4"
LINUX_DESCRIPTION = "QCA IPQ Linux 4.4"

FILESPATH =+ "${TOPDIR}/../:"
SRC_URI = "file://kernel \
	   file://defconfig \
	   file://ipq40xx-default \
           file://ipq807x-default \
	   file://ipq807x_64-default \
	   "
S = "${WORKDIR}/kernel"
SRC_URI += "file://fit"

COMPATIBLE_MACHINE = "(ipq806x|ipq40xx|ipq807x|ipq807x_64)"
KERNEL_IMAGETYPE ?= "Image"
