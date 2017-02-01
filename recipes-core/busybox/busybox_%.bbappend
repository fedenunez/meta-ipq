SRC_URI += "file://fragment.cfg;subdir=busybox-1.24.1 \
            file://lock.c;subdir=busybox-1.24.1/miscutils \
            file://Add_lock_command.patch \
            file://telnet.init"

do_install_append() {
	install -d ${D}/etc/init.d/
	install -m 0755 ${WORKDIR}/telnet.init ${D}/etc/init.d/telnet
}

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
