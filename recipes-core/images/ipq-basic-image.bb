# Base this image on core-image-minimal

include recipes-core/images/core-image-minimal.bb
include recipes-core/images/ipq-pkgs.inc

# Include modules in rootfs
IMAGE_INSTALL += " \
	kernel-modules \
	${IPQ_BASE_PKGS} \
	${RFS_PKGS} \
	${SSDK_HNAT_PKGS} \
	qca-edma \
	"

EXTRA_IMAGEDEPENDS += " \
		${TEST_PKGS} \
		"
