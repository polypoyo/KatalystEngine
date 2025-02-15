#include <KatalystPCH.h>
#include <GLFW/glfw3.h>

#include "Utilities/Log.h"
#include "Core/Application.h"
namespace Katalyst 
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	//Application construction logic
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	//Application destruction logic
	Application::~Application() 
	{
	}

	void Application::OnEvent(Event& e) 
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		KL_CORE_TRACE("{0}", e.ToString());

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) 
		{
			// I have absolutely no flipping clue as to what that operator behind 
			// 'it' does apart from it's accessing the 'it''s pointer.
			(*--it)->OnEvent(e);
			if (e.Handled) break;
		}
	}

	void Application::Run() 
	{

		while (m_Running) 
		{
			glClearColor(0.16, 0.17, 20, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer) 
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}