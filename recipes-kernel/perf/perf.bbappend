

RDEPENDS_${PN}_remove = "elfutils"
DEPENDS_${PN}_append = "elfutils"

EXTRA_OEMAKE = '\
    -C ${S}/tools/perf \
    O=${B} \
    CROSS_COMPILE=${TARGET_PREFIX} \
    ARCH=${ARCH} \
    CC="${CC}" \
    AR="${AR}" \
    LD="${LD}" \
    EXTRA_CFLAGS="-Wno-error=format -lpthread  -include ${TOPDIR}/../meta-ipq/recipes-kernel/perf/files/musl-compat.h -D__UCLIBC__" \
    perfexecdir=${libexecdir} \
    JOBS=1 NO_GTK2=1 ${TUI_DEFINES} NO_DWARF=1 NO_LIBUNWIND=1 NO_LIBDW_DWARF_UNWIND=1 ${LIBUNWIND_DEFINES} \
    ${SCRIPTING_DEFINES} ${LIBNUMA_DEFINES} ${SYSTEMTAP_DEFINES} \
'

EXTRA_OEMAKE += "\
    'DESTDIR=${D}' \
    'prefix=${prefix}' \
    'bindir=${bindir}' \
    'sharedir=${datadir}' \
    'sysconfdir=${sysconfdir}' \
    'perfexecdir=${libexecdir}/perf-core' \
    'ETC_PERFCONFIG=${@os.path.relpath(sysconfdir, prefix)}' \
    'sharedir=${@os.path.relpath(datadir, prefix)}' \
    'mandir=${@os.path.relpath(mandir, prefix)}' \
    'infodir=${@os.path.relpath(infodir, prefix)}' \
"
