FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " \
    file://dmoseley.cfg \
"

do_configure:append() {
	# Not sure why the config fragment is not being automatically applied
	# but I can figure that out later
	sed -i -e 's@CONFIG_TOUCHSCREEN_ILITEK=m@CONFIG_TOUCHSCREEN_ILITEK=y@' ${B}/.config
}