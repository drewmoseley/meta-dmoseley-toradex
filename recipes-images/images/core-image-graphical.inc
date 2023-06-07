IMAGE_INSTALL:append = " gst-examples mesa-demos phoronix-test-suite "

IMAGE_INSTALL:append_apalis-imx8 = " imx-gst1.0-plugin "
IMAGE_INSTALL:append_verdin-imx8mm = " imx-gst1.0-plugin "
IMAGE_INSTALL:append_colibri-imx7-emmc = " imx-gst1.0-plugin "
IMAGE_INSTALL:append_colibri-imx8x = " imx-gst1.0-plugin "
IMAGE_INSTALL:append = " wxwidgets "

IMAGE_FEATURES += "hwcodecs"

IMAGE_INSTALL:append = " pciutils usbutils "
