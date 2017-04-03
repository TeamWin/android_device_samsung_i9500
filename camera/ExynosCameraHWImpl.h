/*
**
** Copyright 2012, Samsung Electronics Co. LTD
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef EXYNOS_CAMERA_HW_IMPLEMENTATION_H
#define EXYNOS_CAMERA_HW_IMPLEMENTATION_H

#define START_HW_THREAD_ENABLE

#include <utils/threads.h>
#include <utils/RefBase.h>
#include <binder/MemoryBase.h>
#include <binder/MemoryHeapBase.h>
#include <hardware/camera.h>
#include <hardware/gralloc.h>
#include <camera/Camera.h>
#include <camera/CameraParameters.h>
#include <media/hardware/MetadataBufferType.h>

#include <fcntl.h>
#include <sys/mman.h>

#include "ExynosCameraHWInterface.h"

namespace android {

class ExynosCameraHWInterface;

class ExynosCameraHWImpl : public ExynosCameraHWInterface {
public:
    ExynosCameraHWImpl() : ExynosCameraHWInterface(){};
    ExynosCameraHWImpl(int cameraId, camera_device_t *dev);
    virtual             ~ExynosCameraHWImpl();

 //setPreviewWindowLocked +0

    void        setCallbacks(camera_notify_callback notify_cb,
                                     camera_data_callback data_cb,
                                     camera_data_timestamp_callback data_cb_timestamp,
                                     camera_request_memory get_memory,
                                     void *user); //+4

    void        enableMsgType(int32_t msgType); //+8
    void        disableMsgType(int32_t msgType); //+12
    bool        msgTypeEnabled(int32_t msgType); //+16

    /* startPreview(), stopPreview(), setParameters(), setPreviewWindows() must be excuted exclusively
       related lock is m_startStopLock; */
    status_t    startPreviewLocked();
    void        stopPreviewLocked();
    status_t    setParametersLocked(const CameraParameters& params);
    status_t    setPreviewWindowLocked(preview_stream_ops *w);

    bool        previewEnabled(); //+28

    status_t    storeMetaDataInBuffers(bool enable); //+32

    status_t    startRecording(); //+36
    void        stopRecording(); //+40
    bool        recordingEnabled(); //+44
    void        releaseRecordingFrame(const void *opaque);

    status_t    autoFocus(); //+52
    status_t    cancelAutoFocus(); //+56

    status_t    takePicture(); //+60
    status_t    cancelPicture();

    CameraParameters  getParameters() const; //+72
    status_t    sendCommand(int32_t command, int32_t arg1, int32_t arg2);

    void        release(); //+80

    status_t    dump(int fd) const; //+84

    inline  int         getCameraId() const; //+88

#if 0
setPreviewWindowLocked
priv +  4 = &deviceSetCallbacks
priv +  8 = &deviceEnableMsgType
priv + 12 = &deviceDisableMsgType
priv + 16 = &deviceMsgTypeEnabled

priv + 28 = &devicePreviewEnabled
priv + 32 = &deviceStoreMetadataInBuffers
priv + 36 = &deviceStartRecording
priv + 40 = &deviceStopRecording
priv + 44 = &deviceRecordingEnabled

priv + 52 = &deviceAutoFocus
priv + 56 = &deviceCancelAutoFocus
priv + 60 = &deviceTakePicture

priv + 72 = &deviceGetParameters

priv + 80 = &deviceRelease
priv + 84 = $deviceDump
priv + 88 = cameraId
#endif
private:
  CameraParameters m_params;
  unsigned int reserved[1053];
  
  //0x24
  //0x1098
};

}; // namespace android

#endif
