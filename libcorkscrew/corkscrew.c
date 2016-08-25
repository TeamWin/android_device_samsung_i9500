/*
 * Copyright (c) 2015 The CyanogenMod Project
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

/* Stubs for blobs depending on libcorkscrew */

#include <sys/types.h>
#include <inttypes.h>

#include "corkscrew.h"

ssize_t unwind_backtrace(__unused void* backtrace, __unused size_t ignore_depth, __unused size_t max_depth)
{
    return -1;
}

ssize_t unwind_backtrace_thread(__unused pid_t tid, __unused void* backtrace,
        __unused size_t ignore_depth, __unused size_t max_depth)
{
    return -1;
}

ssize_t unwind_backtrace_ptrace(__unused pid_t tid, __unused const void* context,
        __unused void* backtrace, __unused size_t ignore_depth, __unused size_t max_depth)
{
    return -1;
}

void get_backtrace_symbols(__unused const void* backtrace, __unused size_t frames,
        __unused void* backtrace_symbols)
{
}

void get_backtrace_symbols_ptrace(__unused const void* context,
        __unused const void* backtrace, __unused size_t frames,
        __unused void* backtrace_symbols)
{
}

void free_backtrace_symbols(__unused void* backtrace_symbols, __unused size_t frames)
{
}

void format_backtrace_line(__unused unsigned frameNumber, __unused const void* frame,
        __unused const void* symbol, char* buffer, size_t bufferSize)
{
    if (bufferSize > 0)
        buffer[0] = 0x00;
}
