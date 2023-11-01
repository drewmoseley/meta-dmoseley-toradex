FILESEXTRAPATHS:prepend := "/work/dmoseley/local:"

SRC_URI:append = " \
    file://caribbean-Lab.config \
"

do_install:append() {
	install -d ${D}/var/lib/${PN}
	install -m 0600 ${WORKDIR}/*.config ${D}/var/lib/${PN}/
}
