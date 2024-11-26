#pragma once

#include <KatalystPCH.h>
#include <GLFW/glfw3.h>

#include "Core/Window.h"

namespace Katalyst 
{
	class KatalystGLFWWindow : public Window
	{
	public:
		KatalystGLFWWindow(const WindowProps& props);
		virtual ~KatalystGLFWWindow();

		void OnUpdate() override;

        	inline unsigned int GetWidth() const override { return m_Data.Width; }
        	inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window Attributes
        	inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

        	// Should return GLFWwindow
        	inline void* GetNativeWindow() const override { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}
