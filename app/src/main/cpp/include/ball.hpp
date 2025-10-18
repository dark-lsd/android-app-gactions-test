//
// Created by ariyaltharun on 10/18/25.
//
#pragma once

#include <raylib.h>
#include <accelerometerSensor.hpp>
#include <camera.hpp>

class Ball {
private:
    Vector3 position{};
    Vector3 velocity{};
    float radius;
    float acceleration;
    void moveAlongAxis(float &velocityAxis, float &positionAxis, float accelSenAxis);
    AccelerometerSensor *accelSensor;
    GameCamera *gameCamera;
public:
    Ball(Vector3 initPosition);
    void draw();
    void move();
    ~Ball();
};
