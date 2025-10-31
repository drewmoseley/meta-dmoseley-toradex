#require recipes-bsp/u-boot/u-boot-rollback.inc

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " \
    file://0001-Add-boot-tag-to-determine-whether-uBoot-is-in-sd-or-.patch \
"
