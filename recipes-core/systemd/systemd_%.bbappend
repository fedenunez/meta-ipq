
FILESEXTRAPATHS_append := "${THISDIR}/files:"
SRC_URI += "file://95-gpio-buttons.rules \
	    "

do_install_append() {
	install -d ${D}/lib/udev/rules.d/
	install -m 0755 ${WORKDIR}/95-gpio-buttons.rules ${D}/lib/udev/rules.d/
}

FILES_${PN} += " \
		/lib/udev/rules.d/95-gpio-buttons.rules \
		"
