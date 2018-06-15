LICENSE = "GPLv2"

require recipes-kernel/linux/linux-qca-ipq.inc
require recipes-kernel/linux/linux-ipq-fit.inc
DEPENDS += "dtc-native"

LINUX_VERSION ?= "3.14"
LINUX_DESCRIPTION = "QCA IPQ Linux 3.14"

KBRANCH ?= "coconut_20140924"
SRCREV_msm ?= "93c371a98d6efdcddc8a879c9972dcacc24b008f"
SRC_URI += "git://source.codeaurora.org/quic/qsdk/oss/kernel/linux-msm;protocol=https;branch=${KBRANCH};name=msm"
SRC_URI += "file://ipq40xx-defconfig \
       "

S = "${WORKDIR}/git"
B = "${S}"
SRC_URI += "file://fit"

COMPATIBLE_MACHINE = "(ipq806x|ipq40xx)"
KERNEL_IMAGETYPE ?= "Image"

