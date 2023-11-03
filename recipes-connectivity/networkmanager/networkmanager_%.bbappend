FILESEXTRAPATHS:prepend := "/work/dmoseley/local:"

SRC_URI:append = " \
    file://caribbean-Lab.nmconnection \
"

do_install:append () {
    # Setup my standard connection profiles
    install -d ${D}${sysconfdir}/NetworkManager/system-connections
    install -m 0600 ${WORKDIR}/*.nmconnection ${D}${sysconfdir}/NetworkManager/system-connections
}