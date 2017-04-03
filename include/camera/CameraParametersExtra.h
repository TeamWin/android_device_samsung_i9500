/*
 * Copyright (C) 2016 The CyanogenMod Project
 * Copyright (C) 2017 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define CAMERA_PARAMETERS_EXTRA_C \
\
const char CameraParameters::PIXEL_FORMAT_YUV420SP_NV21[] = "nv21"; \
const char CameraParameters::KEY_CITYID[] = "cityid"; \
const char CameraParameters::KEY_WEATHER[] = "weather"; \
const char CameraParameters::ISO_AUTO[] = "auto"; \
const char CameraParameters::ISO_100[] = "ISO100"; \
const char CameraParameters::ISO_200[] = "ISO200"; \
const char CameraParameters::ISO_400[] = "ISO400"; \
const char CameraParameters::ISO_800[] = "ISO800"; \
\
int CameraParameters::getInt64(const char *key __attribute__ ((unused))) const \
{ \
    return -1; \
} \
\
extern "C" { \
    void acquire_dvfs_lock(void) { } \
    void release_dvfs_lock(void) { } \
} \

#define CAMERA_PARAMETERS_EXTRA_H \
\
int getInt64(const char *key) const; \
\
static const char PIXEL_FORMAT_YUV420SP_NV21[]; \
static const char KEY_CITYID[]; \
static const char KEY_WEATHER[]; \
static const char ISO_AUTO[]; \
static const char ISO_100[]; \
static const char ISO_200[]; \
static const char ISO_400[]; \
static const char ISO_800[]; \
    /* LAST_LINE OF CAMERA_PARAMETERS_EXTRA_H, every line before this one *MUST* have
     * a backslash \ at the end of the line or else everything will break.
     */