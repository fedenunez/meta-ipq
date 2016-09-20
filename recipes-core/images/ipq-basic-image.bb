# Base this image on core-image-minimal

IMAGE_FEATURES += "package-management"

include recipes-core/images/core-image-minimal.bb

# Include modules in rootfs
IMAGE_INSTALL += " \
	kernel-modules \
	"
