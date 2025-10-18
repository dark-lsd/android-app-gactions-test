//
// Created by ariyaltharun on 10/18/25.
//
#include <ball.hpp>
#include <logger.hpp>

/* Constructor */
Ball::Ball(Vector3 initPosition) {
    LOGI("Initializing Ball Object");
    position = {initPosition.x, initPosition.y, 0.0f};
    radius = 25.0f;
    accelSensor = new AccelerometerSensor();
    velocity = {0.0f, 0.0f, 0.0f};
    acceleration = 20.0f;
    gameCamera = GameCamera::getInstance(position);
}

/* Draw Ball on the screen */
void Ball::draw() {
    DrawSphere(position, radius, PURPLE);
}

/* Update ball position */
void Ball::move() {
    // Move the ball
    moveAlongAxis(velocity.x, position.x, accelSensor->getSensorValues().x);
    moveAlongAxis(velocity.y, position.y, accelSensor->getSensorValues().y);
    // Update the camera Positon
    gameCamera->updateCamera(position);
}

/* Move the ball along the axis */
void Ball::moveAlongAxis(float &velocityAxis, float &positionAxis, float accelSenAxis) {
    /*
     * velocity = (change in displacement) / (change in time)
     * acceleration = (change in velocity) / (change in time)
     *
     * Magnitude denotes how much the position to be changes
     * Sign denotes which direction to move
     * Velocity Decay = ??? | What is stopping velocity
     *
     * */
    if (fabs(accelSenAxis) >= 2.0f) {
        velocityAxis += (10*accelSenAxis) * GetFrameTime();
        LOGD("Ball is moving");
        positionAxis += velocityAxis * GetFrameTime();
    } else {
        if (fabs(velocityAxis) > 0.1f) {
            LOGD("Ball is stopping");
            velocityAxis *= 0.98; // Decay Velocity
            positionAxis += velocityAxis * GetFrameTime();
        } else {
            velocityAxis = 0.0f;
        }
    }
}

/* Destructor */
Ball::~Ball() = default;
