SUMMARY = "Read only rootfs with overlay init script"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"
DEPENDS = "virtual/kernel"
SRC_URI = "file://init-readonly-rootfs-overlay-boot.sh"

do_install() {
        install -m 0755 ${UNPACKDIR}/init-readonly-rootfs-overlay-boot.sh ${D}/init
        install -d "${D}/media/rfs/ro"
        install -d "${D}/media/rfs/rw"
}

FILES:${PN} += " /init /media/rfs"

QA_EMPTY_DIRS:remove = "/media"
QA_EMPTY_DIRS:append = " \
    /media/rfs/ro \
    /media/rfs/rw \
"

# Due to kernel dependency
PACKAGE_ARCH = "${MACHINE_ARCH}"
