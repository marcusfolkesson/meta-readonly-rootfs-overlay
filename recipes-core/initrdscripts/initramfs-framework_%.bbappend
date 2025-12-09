FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += "file://init-readonly-rootfs-overlay-boot.sh"

do_install:append() {
    install -d ${D}/init.d
    install -m 0755 ${UNPACKDIR}/init-readonly-rootfs-overlay-boot.sh ${D}/init.d/91-overlayroot
}

