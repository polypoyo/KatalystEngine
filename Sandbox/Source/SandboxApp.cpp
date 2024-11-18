#include "Katalyst.h"

class ExampleLayer : public Katalyst::Layer 
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override 
	{
		KL_INFO("Example Layer Update");
	}

	void OnEvent(Katalyst::Event& event) override 
	{
	}
};

class Sandbox : public Katalyst::Application 
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	} // Sample Constructor logic
	~Sandbox() {} // Undefined destructor
};

Katalyst::Application* Katalyst::CreateApplication() 
{
	return new Sandbox();
}