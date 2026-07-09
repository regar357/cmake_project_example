#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[]) {
    SPDLOG_INFO("Start program");

    // glfw 라이브러리 초기화, 실패하면 에러 출력 후 종료
    SPDLOG_INFO("Initialize glfw");
    if (!glfwInit())
    {
        const char* description = nullptr;
        glfwGetError(&description);
        SPDLOG_ERROR("failed to initialize glfw: {}", description);
        return -1;
    }

    // glfw 윈도우 생성, 실패하면 에러 출력 후 종료
    SPDLOG_INFO("Create window");
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);
    if (!window)
    {
        SPDLOG_ERROR("failed to create window");
        glfwTerminate();
        return -1;
    }

    // glfw 루프 실행, 윈도우 closw 버튼을 누르면 정상 종료
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
} 