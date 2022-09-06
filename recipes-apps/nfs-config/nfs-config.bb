DESCRIPTION = "NFS configuration for dual SOM update demo"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
    file://exports \
    file://01-nfs-share.conf \
"

S = "${WORKDIR}"

do_install() {
	install -d ${D}${sysconfdir}
	install -m 0644 ${WORKDIR}/exports ${D}${sysconfdir}

    install -d ${D}${sysconfdir}/tmpfiles.d
    install -m 0644 ${WORKDIR}/01-nfs-share.conf ${D}${sysconfdir}/tmpfiles.d
}
