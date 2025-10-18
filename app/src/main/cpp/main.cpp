#include <android/log.h>
#include <raylib.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "ariyal", __VA_ARGS__))
#define SCREEN_WIDTH GetScreenWidth()
#define SCREEN_HEIGHT GetScreenHeight()

int main() {
    LOGI("Raylib initiated!!!");
    InitWindow(0, 0, "Hi");
    LOGI("Width = %d, Height = %d", SCREEN_WIDTH, SCREEN_HEIGHT);
    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BLACK);
            DrawCircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 25.0f, BLUE);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
