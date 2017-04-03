# Copyright (C) 2016 The Android Open Source Project
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

LOCAL_PATH := $(call my-dir)

#################
# libexynoscamera

include $(CLEAR_VARS)

LOCAL_PRELINK_MODULE := false

LOCAL_SHARED_LIBRARIES:= libutils libcutils libbinder liblog libcamera_client libhardware

LOCAL_CFLAGS += -DGAIA_FW_BETA

LOCAL_C_INCLUDES += \
    system/media/camera/include \
    framworks/av/include/camera

LOCAL_SRC_FILES:= \
    ExynosCameraHWImpl.cpp

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := libexynoscamera

include $(BUILD_SHARED_LIBRARY)

#################
# libcamera

include $(CLEAR_VARS)

# HAL module implemenation stored in
# hw/<COPYPIX_HARDWARE_MODULE_ID>.<ro.product.board>.so
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw

LOCAL_C_INCLUDES += \
    system/media/camera/include \
    framworks/av/include/camera

LOCAL_SRC_FILES := \
    ExynosCameraHWInterface.cpp

LOCAL_SHARED_LIBRARIES := \
    libhardware liblog libcamera_client libutils libexynoscamera


LOCAL_CFLAGS += -DGAIA_FW_BETA

ifneq ($(BOARD_CAMERA_FRONT_ROTATION),)
LOCAL_CFLAGS += -DFRONT_ROTATION=$(BOARD_CAMERA_FRONT_ROTATION)
else
LOCAL_CFLAGS += -DFRONT_ROTATION=0
endif

ifneq ($(BOARD_CAMERA_BACK_ROTATION),)
LOCAL_CFLAGS += -DBACK_ROTATION=$(BOARD_CAMERA_BACK_ROTATION)
else
LOCAL_CFLAGS += -DBACK_ROTATION=0
endif

LOCAL_MODULE := camera.$(TARGET_BOOTLOADER_BOARD_NAME)


LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
