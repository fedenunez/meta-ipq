# This include forces the generation of a ubinize UBI image
# file with having total three UBI volumes as kernel, ubi_rootfs
# and rootfs_data.

IMAGE_TYPEDEP_ubi        = "squashfs squashfs-xz"
ITB_IMAGE_NAME_ipq40xx   = "fit-qcom-ipq40xx-ap.dkxx.itb"
ITB_IMAGE_NAME_ipq807x   = "fit-qcom-ipq807x-ap.hkxx.itb"
ITB_IMAGE_NAME_ipq807x_64   = "fit-qcom-ipq807x-ap.hkxx.itb"
UBINIZE_CFG              = "${DEPLOY_DIR_IMAGE}/ubinize-${MACHINE}.cfg"

IMAGE_PREPROCESS_COMMAND += "create_ipq_ubi_img;"
SOC_TYPE="${@bb.data.getVar('MACHINE', d, 1).split('-')[0]}"
IMAGE_NAME_SUFFIX ??= ".rootfs"

create_ipq_ubi_img() {
   create_ubinize_config
}

create_ubinize_config() {
   echo \[kernel\] > "${UBINIZE_CFG}"
   echo mode=ubi >> "${UBINIZE_CFG}"
   echo image="${DEPLOY_DIR_IMAGE}/${ITB_IMAGE_NAME_${SOC_TYPE}}" >> "${UBINIZE_CFG}"
   echo vol_id=0 >> "${UBINIZE_CFG}"
   echo vol_type=dynamic >> "${UBINIZE_CFG}"
   echo vol_name=kernel >> "${UBINIZE_CFG}"

   echo \[rootfs\] >> "${UBINIZE_CFG}"
   echo mode=ubi >> "${UBINIZE_CFG}"
   echo image="${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.squashfs-xz" >> "${UBINIZE_CFG}"
   echo vol_id=1 >> "${UBINIZE_CFG}"
   echo vol_type=dynamic >> "${UBINIZE_CFG}"
   echo vol_name=ubi_rootfs >> "${UBINIZE_CFG}"

   echo \[rootfs_data\] >> "${UBINIZE_CFG}"
   echo mode=ubi >> "${UBINIZE_CFG}"
   echo vol_id=2 >> "${UBINIZE_CFG}"
   echo vol_type=dynamic >> "${UBINIZE_CFG}"
   echo vol_name=rootfs_data >> "${UBINIZE_CFG}"
   echo vol_size=1KiB >> "${UBINIZE_CFG}"
   echo vol_flags=autoresize >> "${UBINIZE_CFG}"
}

IMAGE_CMD_ubi() {

   ubinize ${UBINIZE_ARGS} -o ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubi ${UBINIZE_CFG}

# Create own symlinks for ubi image in deploy dir
   cd ${DEPLOY_DIR_IMAGE}
	if [ -e ${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubi ] && [ ! -e ${IMAGE_LINK_NAME}.ubi]; then
		ln -sf ${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubifs \
		${IMAGE_LINK_NAME}.ubi
	fi
   cd -
}
