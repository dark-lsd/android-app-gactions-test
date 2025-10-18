//
// Created by ariyaltharun on 10/18/25.
//
#pragma once

#include <raylib.h>

/*
 * Game Camera
 * Design Pattern used: Singleton
 * Only one instance of the camera exist
 * */
class GameCamera {
private:
    GameCamera(Vector3 initPosition);
    Camera3D camera{};
    void setupCamera(Vector3 initPosition);
    ~GameCamera();
    static GameCamera* instance;
public:
    static GameCamera* getInstance(Vector3 initPosition);
    void updateCamera(Vector3 updatePosition);
    Camera3D *getCamera();
};
