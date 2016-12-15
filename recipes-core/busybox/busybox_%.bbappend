SRC_URI += "file://fragment.cfg;subdir=busybox-1.24.1 \
            file://lock.c;subdir=busybox-1.24.1/miscutils \
            file://Add_lock_command.patch"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

