#include <KatalystPCH.h>
#include <GLFW/glfw3.h>

#include "Core/Application.h"
#include "Platforms/GLFW/GLFWInput.h"
namespace Katalyst
{
    Input* Input::s_Instance = new KatalystGLFWInput();

    bool KatalystGLFWInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);

        return state == GLFW_PRESS || state == GLFW_RELEASE;
    }

    bool KatalystGLFWInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);

        return state == GLFW_PRESS;
    }

    std::pair<float, float> KatalystGLFWInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;

        glfwGetCursorPos(window, &xPos, &yPos);
        return { (float)xPos, (float)yPos };
    }

    float KatalystGLFWInput::GetMouseXImpl()
    {
        auto[x, y] = GetMousePositionImpl();
        return x;
    }

    float KatalystGLFWInput::GetMouseYImpl()
    {
        auto[x, y] = GetMousePositionImpl();
        return y;
    }
}
