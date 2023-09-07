SUMMARY = "Nethogs python bindings"
HOMEPAGE = "https://github.com/raboof/nethogs"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

SRC_URI = "git://github.com/raboof/nethogs.git;protocol=https;branch=main"
PV = "1.0+git${SRCPV}"
SRCREV = "cd55fef395b1c1a67152cb88d9b8ef72158d4a22"

S = "${WORKDIR}/git"

inherit setuptools3

do_compile:append () {
    oe_runmake 'CC=${CC}' 'LD=${LD}' 'LDFLAGS=${LDFLAGS}' nethogs
}

do_install:append () {
    oe_runmake 'PREFIX=${D}${bindir}' 'CC=${CC}' 'LD=${LD}' 'LDFLAGS=${LDFLAGS}' install
    mv ${D}${bindir}/sbin/nethogs ${D}${bindir}
    rmdir ${D}${bindir}/sbin/
    rm -rf ${D}${bindir}/share/man
}

RDEPENDS:${PN} += "python3-core python3-pybind11"
DEPENDS += "libpcap python3-pybind11-native"