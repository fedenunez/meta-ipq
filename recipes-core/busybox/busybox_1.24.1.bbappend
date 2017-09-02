SRC_URI += "file://lock.c;subdir=busybox-1.24.1/miscutils \
            file://Add_lock_command.patch \
            file://telnet.init \
            file://memset_ipv6_addr.patch"

do_install_append() {
	install -d ${D}/etc/init.d/
	install -m 0755 ${WORKDIR}/telnet.init ${D}/etc/init.d/telnet
}

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
