FILESEXTRAPATHS_prepend_sota := "${THISDIR}/${BPN}:"

SRC_URI_append_sota = " file://10-nfs-utils-ostree.conf "

do_install_append_sota () {
    install -d -m 0755 ${D}${sysconfdir}/tmpfiles.d
    install -m 0644 ${WORKDIR}/10-nfs-utils-ostree.conf ${D}${sysconfdir}/tmpfiles.d
}
FILES_${PN}_append_sota = " ${sysconfdir}/tmpfiles.d/10-nfs-utils-ostree.conf "
