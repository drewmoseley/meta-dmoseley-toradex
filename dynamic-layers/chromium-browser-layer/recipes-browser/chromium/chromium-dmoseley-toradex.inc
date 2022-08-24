DEPENDS_append = "\
        at-spi2-atk \
"

GN_ARGS_append = " \
   ${@bb.utils.contains_any('MACHINE','colibri-imx6ull colibri-imx6ull-emmc colibri-imx6 apalis-imx6','use_system_minigbm=false use_wayland_gbm=false','',d)} \
   ${@bb.utils.contains_any('MACHINE','verdin-imx8mm verdin-imx8mp apalis-imx8 colibri-imx8x','use_system_minigbm=false','',d)} \
"

do_install_append() {
    # Remove ANGLE libraries to allow proper GPU acceleration
    echo MACHINE=${MACHINE} >> /work/dmoseley/log.txt
    echo GN_ARGS=${GN_ARGS} >> /work/dmoseley/log.txt
    if [ ${@bb.utils.contains_any('MACHINE','colibri-imx6ull colibri-imx6ull-emmc colibri-imx6 apalis-imx6','true','false',d)} ] ||
       [ ${@bb.utils.contains_any('MACHINE','verdin-imx8mm verdin-imx8mp apalis-imx8 colibri-imx8x','true','false',d)} ]; then
         [ ${D}${libdir}/chromium/libEGL.so ] && echo "Removing libEGL.so" >> /work/dmoseley/log.txt && rm -f ${D}${libdir}/chromium/libEGL.so
         [ ${D}${libdir}/chromium/libGLESv2.so ] && echo "Removing libGLESv2.so" >> /work/dmoseley/log.txt && rm -f ${D}${libdir}/chromium/libGLESv2.so
    fi
}