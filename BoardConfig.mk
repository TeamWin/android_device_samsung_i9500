#
# Copyright (C) 2013 The CyanogenMod Project
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := device/samsung/i9500

BOARD_VENDOR := samsung

# Include path
TARGET_SPECIFIC_HEADER_PATH := $(LOCAL_PATH)/include

# Assert
TARGET_OTA_ASSERT_DEVICE := ja3g,i9500,GT-I9500

# Bootloader
TARGET_BOOTLOADER_BOARD_NAME := universal5410
TARGET_NO_BOOTLOADER := true

# Platform
TARGET_BOARD_PLATFORM := exynos5
TARGET_SLSI_VARIANT := cm
TARGET_SOC := exynos5410

# Architecture
TARGET_ARCH := arm
TARGET_ARCH_VARIANT := armv7-a-neon
TARGET_ARCH_VARIANT_CPU := cortex-a15
TARGET_CPU_ABI := armeabi-v7a
TARGET_CPU_ABI2 := armeabi
TARGET_CPU_VARIANT := cortex-a15

# Kernel
BOARD_KERNEL_BASE := 0x10000000
BOARD_KERNEL_PAGESIZE := 2048
TARGET_KERNEL_CONFIG := lineageos_i9500_defconfig
TARGET_KERNEL_CROSS_COMPILE_PREFIX := arm-eabi-
TARGET_KERNEL_SOURCE := kernel/samsung/exynos5410
KERNEL_TOOLCHAIN := $(ANDROID_BUILD_TOP)/prebuilts/gcc/$(HOST_OS)-x86/arm/arm-eabi-4.8/bin

# ANT+
BOARD_ANT_WIRELESS_DEVICE := "vfs-prerelease"

# Audio
TARGET_AUDIOHAL_VARIANT := samsung

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(LOCAL_PATH)/bluetooth
BOARD_CUSTOM_BT_CONFIG := $(LOCAL_PATH)/bluetooth/libbt_vndcfg.txt
BOARD_HAVE_BLUETOOTH := true
BOARD_HAVE_BLUETOOTH_BCM := true
BCM_BLUETOOTH_MANTA_BUG := true

# Boot animation
TARGET_BOOTANIMATION_PRELOAD := true
TARGET_BOOTANIMATION_TEXTURE_CACHE := true
TARGET_BOOTANIMATION_HALF_RES := true

# Camera
BOARD_CAMERA_BACK_ROTATION := 90
BOARD_CAMERA_FRONT_ROTATION := 270
BOARD_NEEDS_MEMORYHEAPION := true
BOARD_USE_ANB_OUTBUF_SHARE := true
BOARD_USE_CSC_HW := false
BOARD_USE_DMA_BUF := true
BOARD_USE_GSC_RGB_ENCODER := true
BOARD_USE_H264_PREPEND_SPS_PPS := false
BOARD_USE_IMPROVED_BUFFER := true
BOARD_USE_METADATABUFFERTYPE := true
BOARD_USE_S3D_SUPPORT := false
BOARD_USE_STOREMETADATA := true
BOARD_USE_QOS_CTRL := false
BOARD_USES_CEC := true
BOARD_USES_FB_PHY_LINEAR := false
BOARD_USES_GSC_VIDEO := true
BOARD_USES_NEON_BLITANTIH := true
BOARD_USES_SKIA_FIMGAPI := true
BOARD_USES_VIRTUAL_DISPLAY := true
TARGET_HAS_LEGACY_CAMERA_HAL1 := true

# Charger
BOARD_CHARGER_SHOW_PERCENTAGE := true
BOARD_CHARGING_MODE_BOOTING_LPM := /sys/class/power_supply/battery/batt_lp_charging
RED_LED_PATH := "/sys/class/leds/led_r/brightness"
GREEN_LED_PATH := "/sys/class/leds/led_g/brightness"
BLUE_LED_PATH := "/sys/class/leds/led_b/brightness"
BACKLIGHT_PATH := "/sys/class/backlight/panel/brightness"
CHARGING_ENABLED_PATH := "/sys/class/power_supply/battery/batt_lp_charging"

# CMHW
BOARD_HARDWARE_CLASS := hardware/samsung/cmhw

# Filesystems
BOARD_BOOTIMAGE_PARTITION_SIZE := 8388608
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_CACHEIMAGE_PARTITION_SIZE := 2172649472
BOARD_FLASH_BLOCK_SIZE := 4096
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 88388608
BOARD_SYSTEMIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2898264064
BOARD_USERDATAIMAGE_FILE_SYSTEM_TYPE := ext4
# 9604956160 <real size> - 16384 <encryption footer>
BOARD_USERDATAIMAGE_PARTITION_SIZE := 9604939776
TARGET_KERNEL_HAVE_EXFAT := true

# Fonts
EXTENDED_FONT_FOOTPRINT := true

# Graphics
BOARD_EGL_SYSTEMUI_PBSIZE_HACK := true
BOARD_EGL_WORKAROUND_BUG_10194508 := true
BOARD_USE_BGRA_8888_FB := true
BOARD_USE_SAMSUNG_CAMERAFORMAT_NV21 := true
BOARD_USES_WFD := true
BOARD_GLOBAL_CFLAGS += -DSURFACE_IS_BGR32
NUM_FRAMEBUFFER_SURFACE_BUFFERS := 3
USE_OPENGL_RENDERER := true

# frameworks/native/services/surfaceflinger
# Set the phase offset of the system's vsync event relative to the hardware
# vsync. The system's vsync event drives Choreographer and SurfaceFlinger's
# rendering. This value is the number of nanoseconds after the hardware vsync
# that the system vsync event will occur.
#
# This phase offset allows adjustment of the minimum latency from application
# wake-up (by Choregographer) time to the time at which the resulting window
# image is displayed.  This value may be either positive (after the HW vsync)
# or negative (before the HW vsync).  Setting it to 0 will result in a
# minimum latency of two vsync periods because the app and SurfaceFlinger
# will run just after the HW vsync.  Setting it to a positive number will
# result in the minimum latency being:
#
#     (2 * VSYNC_PERIOD - (vsyncPhaseOffsetNs % VSYNC_PERIOD))
#
# Note that reducing this latency makes it more likely for the applications
# to not have their window content image ready in time.  When this happens
# the latency will end up being an additional vsync period, and animations
# will hiccup.  Therefore, this latency should be tuned somewhat
# conservatively (or at least with awareness of the trade-off being made).
VSYNC_EVENT_PHASE_OFFSET_NS := 7500000
SF_VSYNC_EVENT_PHASE_OFFSET_NS := 5000000

# Shader cache config options
# Maximum size of the  GLES Shaders that can be cached for reuse.
# Increase the size if shaders of size greater than 12KB are used.
MAX_EGL_CACHE_KEY_SIZE := 12*1024

# Maximum GLES shader cache size for each app to store the compiled shader
# binaries. Decrease the size if RAM or Flash Storage size is a limitation
# of the device.
MAX_EGL_CACHE_SIZE := 2048*1024

# IR
IR_HAL_SUFFIX := universal5410

# Linker
LINKER_FORCED_SHIM_LIBS := /system/bin/gpsd|libdmitry.so

# Media
TARGET_OMX_LEGACY_RESCALING := true

# NFC
BOARD_NFC_HAL_SUFFIX := universal5410

# Radio
BOARD_MODEM_TYPE := xmm6360
BOARD_PROVIDES_LIBRIL := true
BOARD_RIL_CLASS := ../../../device/samsung/i9500/ril
TARGET_GLOBAL_CFLAGS += -DDISABLE_ASHMEM_TRACKING

# Recovery
BOARD_HAS_DOWNLOAD_MODE := true
BOARD_HAS_LARGE_FILESYSTEM := true
LZMA_RAMDISK_TARGETS := recovery
TARGET_RECOVERY_FSTAB := $(LOCAL_PATH)/rootdir/etc/fstab.universal5410
TARGET_USERIMAGES_USE_EXT4 := true

# Releasetools
TARGET_RELEASETOOLS_EXTENSIONS := $(LOCAL_PATH)/releasetools
TARGET_BOARD_INFO_FILE ?= $(LOCAL_PATH)/board-info.txt

# Seccomp filters
BOARD_SECCOMP_POLICY := device/samsung/i9500/seccomp

# SELinux
BOARD_SEPOLICY_DIRS += \
    device/samsung/i9500/sepolicy_common \
    device/samsung/i9500/sepolicy_specific

# Sensors
TARGET_NEEDS_PLATFORM_TEXT_RELOCATIONS := true
TARGET_NO_SENSOR_PERMISSION_CHECK := true

# Wifi
BOARD_HAVE_SAMSUNG_WIFI          := true
BOARD_WLAN_DEVICE                := bcmdhd
WPA_SUPPLICANT_VERSION           := VER_0_8_X
BOARD_WPA_SUPPLICANT_DRIVER      := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_bcmdhd
BOARD_HOSTAPD_DRIVER             := NL80211
BOARD_HOSTAPD_PRIVATE_LIB        := lib_driver_cmd_bcmdhd
WIFI_DRIVER_FW_PATH_PARAM        := "/sys/module/dhd/parameters/firmware_path"
WIFI_DRIVER_FW_PATH_STA          := "/system/etc/wifi/bcmdhd_sta.bin"
WIFI_DRIVER_FW_PATH_AP           := "/system/etc/wifi/bcmdhd_apsta.bin"
WIFI_BAND                        := 802_11_ABG

# inherit from the proprietary version
-include vendor/samsung/i9500/BoardConfigVendor.mk
