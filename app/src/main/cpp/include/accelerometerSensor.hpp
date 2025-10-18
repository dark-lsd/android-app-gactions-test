//
// Created by ariyaltharun on 10/18/25.
//
#pragma once

#include <android/sensor.h>
#include <android/looper.h>
#include <raylib.h>

class AccelerometerSensor {
private:
    Vector3 sensorValues{};
    ASensorManager *sensorManager{};
    const ASensor *sensor{};
    ASensorEventQueue *sensorEventQueue{};
    void start();
    void stop();
    static void sensorEventCallback(int fd, int events, void *data);
public:
    AccelerometerSensor();
    Vector3 getSensorValues();
    ~AccelerometerSensor();
};

