FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

POSTINSTALL_RETURN_CODE ??= "0"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
    file://60-polling-interval.toml \
    file://99-offline-updates.toml \
    file://post-install-check.sh.in \
    "

# This is actually set in torizon_base_image_type.inc which we have not included in this recipe
# Fake it here since this is just for debugging anyway.
TORIZON_OSTREE_BRANCHNAME = "${TDX_MAJOR}/${MACHINE}/${DISTRO}/${IMAGE_BASENAME}/${TDX_OSTREE_PURPOSE}"
do_install() {
    # Generic install of custom files for Torizon testing
    install -m 0755 -d ${D}${sysconfdir}/sota/conf.d
    install -m 0644 ${WORKDIR}/60-polling-interval.toml ${D}${sysconfdir}/sota/conf.d
    install -m 0644 ${WORKDIR}/99-offline-updates.toml ${D}${sysconfdir}/sota/conf.d

    install -m 0755 -d ${D}${sysconfdir}/greenboot/check/required.d
    install -m 0755 ${WORKDIR}/post-install-check.sh.in ${D}${sysconfdir}/greenboot/check/required.d/post-install-check.sh
    sed -i -e 's~@POSTINSTALL_RETURN_CODE@~${POSTINSTALL_RETURN_CODE}~' \
        ${D}${sysconfdir}/greenboot/check/required.d/post-install-check.sh
}
FILES:${PN} = "${sysconfdir}"
