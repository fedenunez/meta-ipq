DESCRIPTION = "U-boot bootloader for IPQ40xx"
LICENSE = "GPLv2"
SECTION = "bootloaders"

require recipes-bsp/u-boot/u-boot.inc

DEPENDS = "dtc-native"
FILESPATH =+ "${TOPDIR}/../boot/:"
LIC_FILES_CHKSUM = "file://Licenses/gpl-2.0.txt;md5=b234ee4d69f5fce4486a80fdaf4a4263"

LOCALVERSION ?= "+yocto"
PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "ipq40xx"
DEPENDS +="u-boot-mkimage-native"

SRC_URI = "file://u-boot-2016"
S = "${WORKDIR}/u-boot-2016"

UBOOT_MACHINE = "ipq40xx_defconfig"
EXTRA_OEMAKE = 'CROSS_COMPILE=${TARGET_PREFIX} CC="${TARGET_PREFIX}gcc ${TOOLCHAIN_OPTIONS}" STRIP=true V=1'
EXTRA_OEMAKE += 'TARGETCC="${CC} ${BUILD_CFLAGS} ${BUILD_LDFLAGS}"'

# Image files for Uboot
UBOOT_IMAGETYPE ?= "bin"
UBOOT_ELF_SUFFIX ?= "elf"
UBOOT_ELF = "u-boot"
UBOOT_ELF_IMAGE ?= "u-boot-${MACHINE}-${PV}-${PR}.${UBOOT_ELF_SUFFIX}"
UBOOT_ELF_BINARY ?= "u-boot.${UBOOT_ELF_SUFFIX}"


do_compile_prepend() {
	mkdir -p ${B}/arch/ ${B}/arch/${UBOOT_ARCH}/ ${B}/arch/${UBOOT_ARCH}/dts
	cp -rf  ${S}/arch/${UBOOT_ARCH}/dts/* ${B}/arch/${UBOOT_ARCH}/dts/
}

do_deploy_append() {
	cp u-boot-${MACHINE}-${PV}-${PR}.${UBOOT_ELF_SUFFIX} u-boot-${MACHINE}-${PV}-${PR}-stripped.${UBOOT_ELF_SUFFIX}
	${STRIP} u-boot-${MACHINE}-${PV}-${PR}-stripped.${UBOOT_ELF_SUFFIX}
}
