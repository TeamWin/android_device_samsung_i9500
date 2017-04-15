###########################################################
### TWRP RECOVERY
###########################################################

RECOVERY_VARIANT := twrp

TARGET_RECOVERY_DEVICE_MODULES += init.recovery.usb.rc

# Do not link again libion_exynos.so
BOARD_NEEDS_MEMORYHEAPION := false

BOARD_HAS_NO_REAL_SDCARD := true
RECOVERY_SDCARD_ON_DATA := true

TW_THEME := portrait_hdpi

# Add logcat support
TWRP_INCLUDE_LOGCAT := true
# Use toolbox instead of busybox
TW_USE_TOOLBOX := true

TW_BRIGHTNESS_PATH := /sys/class/backlight/panel/brightness
TW_MAX_BRIGHTNESS := 255

TW_NO_REBOOT_BOOTLOADER := true
TW_HAS_DOWNLOAD_MODE := true

# Enable support for encrypted fs
TW_INCLUDE_CRYPTO := true

# The kernel has exfat support.
TW_NO_EXFAT_FUSE := true
TW_EXCLUDE_SUPERSU := true
