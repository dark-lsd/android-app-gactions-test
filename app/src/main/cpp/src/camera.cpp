//
// Created by ariyaltharun on 10/18/25.
//
#include <camera.hpp>
#include <logger.hpp>

GameCamera* GameCamera::instance = nullptr;

GameCamera::GameCamera(Vector3 initPosition) {
    LOGI("Creating New Gamera Camera Instance");
    setupCamera(initPosition);
}

void GameCamera::setupCamera(Vector3 initPosition) {
    /*
     * 3D Game Camera
     * Position: Position of camera in 3D space
     * Target: Target Vector is a view vector, where the camera is looking at
     * UP: Up vector is the camera's top upward vector */
    LOGI("Setting Up Game Camera....");
    camera.position = { initPosition.x, initPosition.y, -1000.0f };
    camera.target = { initPosition.x, initPosition.y, 0.0f };
    camera.fovy = 45.0f;
    camera.up = {0.0, -1.0f, 0.0f}; // Y Axis
    camera.projection = CAMERA_PERSPECTIVE;
    LOGI("Camera Position: x=%f, y=%f, z=%f", camera.position.x, camera.position.y, camera.position.z);
    LOGI("Camera Target: x=%f, y=%f, z=%f", camera.target.x, camera.target.y, camera.target.z);
    LOGI("Camera UP: x=%f, y=%f, z=%f", camera.up.x, camera.up.y, camera.up.z);
    LOGI("Camera Projection: %s", "CAMERA_PERSPECTIVE");
    LOGI("Camera Setup Complete!!");
}

void GameCamera::updateCamera(Vector3 updatedPosition) {
    LOGD("Updating Camera Positon and Target to x=%f, y=%f", updatedPosition.x, updatedPosition.y);
    camera.position = { updatedPosition.x, updatedPosition.y, -1000.0f };
    camera.target = { updatedPosition.x, updatedPosition.y, 0.0f };
}

GameCamera* GameCamera::getInstance(Vector3 initPosition) {
    if (instance == nullptr)
        instance = new GameCamera(initPosition);
    return instance;
}

Camera3D *GameCamera::getCamera() {
    return &camera;
}

GameCamera::~GameCamera() {
    LOGI("Deleting the GameCamera Instance");
    delete(instance);
}
