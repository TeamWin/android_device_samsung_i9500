#include <utils/threads.h>
#include <utils/RefBase.h>
#include <binder/MemoryBase.h>
#include <binder/MemoryHeapBase.h>
#include <hardware/camera.h>
#include <hardware/gralloc.h>
#include <camera/Camera.h>
#include <camera/CameraParameters.h>

#include "ExynosCameraHWImpl.h"


namespace android {

ExynosCameraHWImpl::ExynosCameraHWImpl(int cameraId, camera_device_t *dev) {
}

ExynosCameraHWImpl::~ExynosCameraHWImpl() {
}


void ExynosCameraHWImpl::setCallbacks(camera_notify_callback notify_cb,
                                 camera_data_callback data_cb,
                                 camera_data_timestamp_callback data_cb_timestamp,
                                 camera_request_memory get_memory,
                                 void *user) {
}

void ExynosCameraHWImpl::enableMsgType(int32_t msgType) {
}

void ExynosCameraHWImpl::disableMsgType(int32_t msgType) {
}

bool ExynosCameraHWImpl::msgTypeEnabled(int32_t msgType) {
  return 0;
}

status_t ExynosCameraHWImpl::startPreviewLocked() {
  return 0;
}

void ExynosCameraHWImpl::stopPreviewLocked() {
}

status_t ExynosCameraHWImpl::setParametersLocked(const CameraParameters& params) {
  return 0;
}

status_t ExynosCameraHWImpl::setPreviewWindowLocked(preview_stream_ops *w) {
  return 0;
}

bool ExynosCameraHWImpl::previewEnabled() {
  return 0;
}

status_t ExynosCameraHWImpl::storeMetaDataInBuffers(bool enable) {
  return 0;
}

status_t ExynosCameraHWImpl::startRecording() {
  return 0;
}

void ExynosCameraHWImpl::stopRecording() {
}

bool ExynosCameraHWImpl::recordingEnabled() {
  return 0;
}

void ExynosCameraHWImpl::releaseRecordingFrame(const void *opaque) {
}

status_t ExynosCameraHWImpl::autoFocus() {
  return 0;
}

status_t ExynosCameraHWImpl::cancelAutoFocus() {
  return 0;
}

status_t ExynosCameraHWImpl::takePicture() {
  return 0;
}

status_t ExynosCameraHWImpl::cancelPicture() {
  return 0;
}

CameraParameters ExynosCameraHWImpl::getParameters() const {
  return m_params;
}
status_t ExynosCameraHWImpl::sendCommand(int32_t command, int32_t arg1, int32_t arg2) {
  return 0;
}

void ExynosCameraHWImpl::release() {
}

status_t ExynosCameraHWImpl::dump(int fd) const {
  return 0;
}

inline int ExynosCameraHWImpl::getCameraId() const {
  return 0;
}

}; // namespace android

