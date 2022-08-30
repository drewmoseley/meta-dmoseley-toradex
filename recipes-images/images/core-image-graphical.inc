IMAGE_INSTALL_append = " gst-examples mesa-demos phoronix-test-suite "

IMAGE_INSTALL_append_apalis-imx8 = " imx-gst1.0-plugin "
IMAGE_INSTALL_append_verdin-imx8mm = " imx-gst1.0-plugin "
IMAGE_INSTALL_append_colibri-imx7-emmc = " imx-gst1.0-plugin "
IMAGE_INSTALL_append_colibri-imx8x = " imx-gst1.0-plugin "
IMAGE_INSTALL_append = " wxwidgets "

IMAGE_FEATURES += "hwcodecs"

IMAGE_INSTALL_append = " pciutils usbutils "
