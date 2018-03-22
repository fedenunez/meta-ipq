LICENSE = "ISC"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://ipq-power-save.sh"

do_install_append() {
	install -d ${D}/etc/pm/power.d/
	install -m 0755 ${WORKDIR}/ipq-power-save.sh ${D}/etc/pm/power.d/
	rm -rf ${D}/usr/lib/pm-utils/power.d/
}

FILES_${PN} += "${sysconfdir}/*"
