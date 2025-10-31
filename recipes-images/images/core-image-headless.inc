IMAGE_FEATURES += "hwcodecs"

IMAGE_INSTALL:append = " pciutils usbutils nano strace parted v4l-utils lshw rsync bzip2 "

ROOTFS_POSTPROCESS_COMMAND:append = " add_dmoseley_data "

add_dmoseley_data() {
   local buildhost=$(hostname)
   cat > ${IMAGE_ROOTFS}/dmoseley-builddata <<-EOF
	yocto_image=${IMAGE_BASENAME}
	yocto_buildhost=$buildhost
	OSTREE_BRANCHNAME=${OSTREE_BRANCHNAME}
	GARAGE_TARGET_VERSION=${GARAGE_TARGET_VERSION}
	POSTINSTALL_RETURN_CODE=${POSTINSTALL_RETURN_CODE}
	EOF
}