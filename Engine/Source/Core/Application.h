#pragma once

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "Layers/LayerStack.h"

namespace Katalyst
{
	class KL_API Application
	{
	public:
		Application(); // Application constructor
		virtual ~Application(); // Inheritable Application destructor

		void Run(); // Runtime Loop

		void OnEvent(Event& e); // Event handler

		void PushLayer(Layer* layer); // Adds layers - To a spot
		void PushOverlay(Layer* overlay); // Adds overlays - Towards the end

        // Getters for Application
        inline Window& GetWindow() { return *m_Window; }
        inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
    private:
        static Application* s_Instance; // Application instance
	};

	Application* CreateApplication();
}
