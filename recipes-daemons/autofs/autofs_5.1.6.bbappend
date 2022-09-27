do_install_append () {
    install -d -m 755 ${D}/misc ${D}/net
}
FILES_${PN}_append = " /misc /net "
