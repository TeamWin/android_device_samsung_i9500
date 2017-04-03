/*
**
** Copyright 2013, Samsung Electronics Co. LTD
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

/*!
 * \file      ExynosCameraAutoTimer.h
 * \brief     hearder file for ExynosCameraAutoTimer
 * \author    Sangwoo.Park(sw5771.park@samsung.com)
 * \date      2013/06/18
 *
 * <b>Revision History: </b>
 * - 2013/06/18 : Sangwoo.Park(sw5771.park@samsung.com) \n
 *   Initial version
 *
 */

#ifndef EXYNOS_CAMERA_AUTO_TIMER_H
#define EXYNOS_CAMERA_AUTO_TIMER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <camera/CameraParametersExtra.h>
#include <utils/threads.h>

namespace android {

class DurationTimer {
public:
    DurationTimer() {}
    ~DurationTimer() {}
    void start();
    void stop();
    long long durationUsecs() const;
    static long long subtractTimevals(const struct timeval* ptv1,
        const struct timeval* ptv2);
    static void addToTimeval(struct timeval* ptv, long usec);
private:
    struct timeval  mStartWhen;
    struct timeval  mStopWhen;
};

void DurationTimer::start(void) 
{
    gettimeofday(&mStartWhen, NULL);
}

void DurationTimer::stop(void)
{
    gettimeofday(&mStopWhen, NULL);
}

long long DurationTimer::durationUsecs(void) const
{
    return (long) subtractTimevals(&mStopWhen, &mStartWhen);
}

/*static*/ long long DurationTimer::subtractTimevals(const struct timeval* ptv1,
    const struct timeval* ptv2)
{
    long long stop  = ((long long) ptv1->tv_sec) * 1000000LL +
                      ((long long) ptv1->tv_usec);
    long long start = ((long long) ptv2->tv_sec) * 1000000LL +
                      ((long long) ptv2->tv_usec);
    return stop - start;
}

/*static*/ void DurationTimer::addToTimeval(struct timeval* ptv, long usec)
{
    if (usec < 0) {
        ALOG(LOG_WARN, "", "Negative values not supported in addToTimeval\n");
        return;
    }

    if (ptv->tv_usec >= 1000000) {
        ptv->tv_sec += ptv->tv_usec / 1000000;
        ptv->tv_usec %= 1000000;
    }

    ptv->tv_usec += usec % 1000000;
    if (ptv->tv_usec >= 1000000) {
        ptv->tv_usec -= 1000000;
        ptv->tv_sec++;
    }
    ptv->tv_sec += usec / 1000000;
}

class ExynosCameraAutoTimer {
private:
    ExynosCameraAutoTimer(void)
    {}

public:
    inline ExynosCameraAutoTimer(char *strLog)
    {
        if (m_create(strLog) == false)
            ALOGE("ERR(%s):m_create() fail", __func__);
    }

    inline ExynosCameraAutoTimer(const char *strLog)
    {
        char *strTemp = (char*)strLog;

        if (m_create(strTemp) == false)
            ALOGE("ERR(%s):m_create() fail", __func__);
    }

    inline virtual ~ExynosCameraAutoTimer()
    {
        long long durationTime;

        m_timer.stop();

        durationTime = m_timer.durationUsecs();

        if (m_logStr) {
            ALOGD("DEBUG:duration time(%5d msec):(%s)",
                (int)durationTime / 1000, m_logStr);
        } else {
            ALOGD("DEBUG:duration time(%5d msec):(NULL)",
                (int)durationTime / 1000);
        }
    }

private:
    bool m_create(char *strLog)
    {
        m_logStr = strLog;

        m_timer.start();

        return true;
    }

private:
    DurationTimer m_timer;
    char         *m_logStr;
};

}; // namespace android

#endif // EXYNOS_CAMERA_AUTO_TIMER_H
