FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += "file://init-readonly-rootfs-overlay-boot.sh"

S = "${WORKDIR}"

do_install:append() {
    install -d ${D}/init.d
    install -m 0755 ${WORKDIR}/init-readonly-rootfs-overlay-boot.sh ${D}/init.d/91-overlayroot
}

