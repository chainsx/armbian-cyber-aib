#
# SPDX-License-Identifier: GPL-2.0
#
# Copyright (c) Martin Schmiedel
#
# This file is a part of the Armbian Build Framework
# https://github.com/armbian/build/
#

ARCH="arm64"
KERNEL_IMAGE_TYPE="Image"
SRC_EXTLINUX="yes" # use extlinux as default
IMX_FIRMWARE="${IMX_FIRMWARE:-"firmware-imx-8.12"}"
# ATF_PLAT musst set in board
# ATF_UART_BASE musst set in board
# MAP = target_make,target_patchdir,target_files
# use xxx:xxx to rename files after build
ATF_TARGET_MAP="PLAT=${ATF_PLAT} IMX_BOOT_UART_BASE=${ATF_UART_BASE} bl31;;build/imx8mp/release/bl31.bin"
UBOOT_TARGET_MAP="flash.bin;;flash.bin"

# linux releated

LINUXCONFIG="linux-imx8m-${BRANCH}"

case $BRANCH in
	legacy)
		KERNELSOURCE='https://github.com/Avnet/linux-imx.git'
		KERNELBRANCH="branch:maaxboard_lf-6.1.22-2.0.0"
		declare -g KERNEL_MAJOR_MINOR="6.1"
		KERNELPATCHDIR="imx8m-${BRANCH}"
	;;
	current) # active lts mainline kernel
		KERNEL_MAJOR_MINOR="6.6"
		KERNELBRANCH='branch:linux-6.6.y'
		KERNELPATCHDIR="archive/imx8m-6.6"
	;;

	edge | default) # use for tests with recent mainline kernels
	;;
esac
