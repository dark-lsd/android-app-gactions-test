//
// Created by ariyaltharun on 10/18/25.
//

#pragma once

#ifndef BALL_BALANCING_GAME_LOGGER_HPP
#define BALL_BALANCING_GAME_LOGGER_HPP

#include <android/log.h>

#define LOG_TAG "native-ball-balancing-game"

inline void LOGI(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    __android_log_vprint(ANDROID_LOG_INFO, LOG_TAG, fmt, args);
    va_end(args);
}

inline void LOGD(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    __android_log_vprint(ANDROID_LOG_DEBUG, LOG_TAG, fmt, args);
    va_end(args);
}

inline void LOGE(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    __android_log_vprint(ANDROID_LOG_ERROR, LOG_TAG, fmt, args);
    va_end(args);
}

inline void LOGW(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    __android_log_vprint(ANDROID_LOG_WARN, LOG_TAG, fmt, args);
    va_end(args);
}

#endif //BALL_BALANCING_GAME_LOGGER_HPP
