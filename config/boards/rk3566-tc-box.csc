# Rockchip RK3566 quad core 4/8GB RAM SoC WIFI/BT eMMC USB2 USB3 NVMe PCIe GbE HDMI SPI
BOARD_NAME="rk3566-tc-box"
BOARDFAMILY="rk35xx"
BOARD_MAINTAINER=""
BOOTCONFIG="radxa-zero3-rk3566_defconfig"
BOOT_SOC="rk3566"
KERNEL_TARGET="current,stable,legacy,vendor"
FULL_DESKTOP="yes"
BOOT_LOGO="desktop"
BOOT_FDT_FILE="rockchip/rk3566-box-demo.dtb"
IMAGE_PARTITION_TABLE="gpt"
EXTRAWIFI="no"
BOOT_SCENARIO="spl-blobs"

# Override family config for this board; let's avoid conditionals in family config.
function post_family_config__stationm2_use_radxa_vendor_uboot() {
	BOOTSOURCE='https://github.com/radxa/u-boot.git'
	BOOTBRANCH='branch:rk35xx-2024.01'
	BOOTPATCHDIR="u-boot-radxa-latest"

	UBOOT_TARGET_MAP="BL31=$RKBIN_DIR/$BL31_BLOB ROCKCHIP_TPL=$RKBIN_DIR/$DDR_BLOB;;u-boot-rockchip.bin"

	unset uboot_custom_postprocess write_uboot_platform write_uboot_platform_mtd

	function write_uboot_platform() {
		dd if=$1/u-boot-rockchip.bin of=$2 seek=64 conv=notrunc status=none
	}
}
