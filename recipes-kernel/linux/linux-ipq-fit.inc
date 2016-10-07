
LICENSE = "GPLv2"

LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

COMPATIBLE_MACHINE = "(ipq806x|ipq40xx)"

KMACHINE = "${MACHINE}"

INSANE_SKIP_kernel-dev = "debug-files"

PARALLEL_MAKE = ""
KARCH ?= "arm"
DEPENDS += "u-boot-mkimage-native"

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

generate_FDT() {
	name=$1
	board_name=$2

	cat << EOF >> ${B}/../fit/multi.its
		fdt@${board_name} {
			description = "${name} Tree blob";
			data = /incbin/("${B}/arch/${KARCH}/boot/dts/${name}.dtb");
			type = "flat_dt";
			arch = "arm";
			compression = "none";
			hash@1 {
				algo = "crc32";
			};
			hash@2 {
				algo = "sha1";
			};
		};
EOF
}

generate_CONFIG() {
	board_name=$1

	cat << EOF >> ${B}/../fit/multi.its
		config@${board_name} {
			description = DESCRIPTION;
			kernel = "kernel@1";
			fdt = "fdt@${board_name}";
		};
EOF
}

mk_multi_fit_image() {
	name=$1
	addr=$2

	echo "pwd = `pwd`"
	cd ../fit
	sed -i -e 's/ARCH/${KARCH}/' -e "s/LOAD/${addr}/" \
		-e "s/ENTRY/${addr}/" \
		-e 's/DESCRIPTION/"IPQ Yocto Linux FIT (Flattened Image Tree)"/' ${B}/../fit/multi.its

	oe_runmake multi.fit
	mv multi.fit fit-${name}.itb
	cd ${B}
}

do_compile_append() {

	for d in ${KERNEL_DEVICETREE}; do
		if [ ! -e "$d" ]; then
			mk_fit_images "${d%.dtb}" ${KERNEL_LOADADDR}
		fi
	done

	cp ${B}/../fit/multi.its.in ${B}/../fit/multi.its
	i=0
	for d in ${KERNEL_DEVICETREE}; do
		if [ ! -e "$d" ]; then
			board_name=$(basename $d .dtb | sed -e 's/^\([^\(.*?-?\)]*-\)//g')
			generate_FDT "${d%.dtb}" $board_name
		fi
	done

	cat << EOF >> ${B}/../fit/multi.its
	};
	configurations {
		default = "config@1";
EOF

	i=0
	for d in ${KERNEL_DEVICETREE}; do
		if [ ! -e "$d" ]; then
			board_name=$(basename $d .dtb | sed -e 's/^\([^\(.*?-?\)]*-\)//g')
			generate_CONFIG $board_name
		fi
	done
	cat << EOF >> ${B}/../fit/multi.its
	};
};
EOF
	mk_multi_fit_image qcom-ipq40xx-ap.dkxx ${KERNEL_LOADADDR}
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
	install_fit_images qcom-ipq40xx-ap.dkxx
}
