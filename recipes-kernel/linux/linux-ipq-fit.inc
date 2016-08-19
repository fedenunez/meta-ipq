
LICENSE = "GPLv2"

LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

COMPATIBLE_MACHINE = "(ipq806x|ipq40xx)"

KMACHINE = "${MACHINE}"

INSANE_SKIP_kernel-dev = "debug-files"

PARALLEL_MAKE = ""
KARCH ?= "arm"

mk_fit_images() {
	name=$1
	addr=$2

	oe_runmake ${name}.dtb
	echo "pwd = `pwd`"
	cd ../fit
	oe_runmake "ARCH=${KARCH}" \
			'DESCRIPTION=IPQ Yocto Linux FIT (Flattened Image Tree)' \
			"ADDRESS=${addr}" \
			'KERNEL_IMAGE=${B}/arch/${KARCH}/boot/Image' \
			"DTB=${B}/arch/${KARCH}/boot/dts/${name}.dtb" \
			"DTB_NAME=${name}"
	mv linux.fit fit-${name}.itb
	mv fdt.fit fdt.fit-${name}
	cd ${B}
}

do_compile_append() {

	for d in ${KERNEL_DEVICETREE}; do
		if [ ! -e "$d" ]; then
			mk_fit_images "${d%.dtb}" ${KERNEL_LOADADDR}
		fi
	done
}

install_fit_images() {
	name=$1
	install ${B}/../fit/fit-${name}.itb ${DEPLOYDIR}/fit-${name}.itb

}

do_deploy_append() {

	for d in ${KERNEL_DEVICETREE}; do
		if [ ! -e "$d" ]; then
			install_fit_images "${d%.dtb}"
		fi
	done
}
