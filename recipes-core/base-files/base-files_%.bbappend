do_install:append() {
	# Configure update mode
	if [ "${TORIZON_SOTA_PROV_MODE}" == "offline" ]; then
	    echo HIDREW-offline >> /work/dmoseley/foo.txt
	    install -d ${D}${sysconfdir}/sota/conf.d
	cat >${D}${sysconfdir}/sota/conf.d/100-offline-updates.toml <<EOF
[uptane]
enable_online_updates = false
enable_offline_updates = true
offline_updates_source = /var/rootdirs/media/Toradex/update
EOF
	elif [ "${TORIZON_SOTA_PROV_MODE}" == "online" ]; then
	    echo HIDREW-online >> /work/dmoseley/foo.txt
	    install -d ${D}${sysconfdir}/sota/conf.d
	cat >${D}${sysconfdir}/sota/conf.d/100-offline-updates.toml <<EOF
[uptane]
enable_online_updates = true
enable_offline_updates = false
offline_updates_source = /var/rootdirs/media/Toradex/update
EOF
	fi
}
# No FILES modifications needed.  The bbfile includes /
