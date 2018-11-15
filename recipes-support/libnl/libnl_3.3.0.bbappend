
FILESEXTRAPATHS_append := "${THISDIR}/files:"
SRC_URI += " \
	    file://01-fix-compile-errors.patch \
	    "
addtask copy_files_sysroot after do_populate_sysroot before do_package
do_copy_files_sysroot() {
	cp -fR ${WORKDIR}/libnl-3.3.0/include/* ${STAGING_DIR_TARGET}/usr/include/libnl3/
}
