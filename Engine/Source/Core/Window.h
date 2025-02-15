#pragma once

#include <KatalystPCH.h>

#include "Core.h"
#include "Events/Event.h"
namespace Katalyst {

    // Stores basic window properties
    struct WindowProps {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Katalyst Engine", unsigned int width = 800, unsigned int height = 450)
            : Title(title), Width(width), Height(height) {}
    };

    class KL_API Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;
        
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
        
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}
