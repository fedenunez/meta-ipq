# Base this image on core-image-minimal

include recipes-core/images/core-image-minimal.bb
include recipes-core/images/ipq-pkgs.inc

# Include modules in rootfs
IMAGE_INSTALL += " \
	kernel-modules \
	${IPQ_BASE_PKGS} \
	${SSDK_PKGS}	\
	${NETWORK_PKGS} \
	${NSS_PKGS} \
	${WIFI_PKGS} \
	"

EXTRA_IMAGEDEPENDS += " \
		${TEST_PKGS} \
		"
