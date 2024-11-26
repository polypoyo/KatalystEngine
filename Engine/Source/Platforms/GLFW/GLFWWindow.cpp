#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include "Utilities/Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#include "Platforms/GLFW/GLFWWindow.h"
namespace Katalyst 
{
	static bool s_GlFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) 
	{
		KL_CORE_ERROR("GLFW Error {0}: {1}", error, description);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new KatalystGLFWWindow(props);
	}

	KatalystGLFWWindow::KatalystGLFWWindow(const WindowProps& props) 
	{
		Init(props);
	}

	KatalystGLFWWindow::~KatalystGLFWWindow()
	{
		Shutdown();
	}

	void KatalystGLFWWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		KL_CORE_INFO("Creating Window: {0} ({1}x{2}) on GLFW", props.Title, props.Width, props.Height);

		// Initialize GLFW
		if (!s_GlFWInitialized)
		{
			int success = glfwInit();
			const char* errorMessage;
			int errorCode = glfwGetError(&errorMessage);
			KL_CORE_ASSERT(success, "Unable to initialize GLFW: " + std::format("0x{:x} {:s}", errorCode, errorMessage));

			s_GlFWInitialized = true;
		}

		m_Window = glfwCreateWindow(props.Width, props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		// Initialize OpenGL Context
        	KL_CORE_INFO("Initializing OpenGL Context");
		int GlInitStatus = gladLoadGL(glfwGetProcAddress);
		KL_CORE_ASSERT(GlInitStatus, "Unable to initialize OpenGL using Glad2");

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW Callbacks

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, true);
						data.EventCallback(event);
						break;
					}
				}
			});

        	glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
            		{
                		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                		KeyTypedEvent event(keycode);
                		data.EventCallback(event);
            		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action) 
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE: 
					{
						MouseButtonReleasedEvent event(button);
						data.EventCallback(event);
						break;
					}
				}	
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
            });
    }

	void KatalystGLFWWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void KatalystGLFWWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void KatalystGLFWWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool KatalystGLFWWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
