#pragma once

#include "Core/Core.h"
#include "Layers/Layer.h"

namespace Katalyst
{
    class KL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        virtual ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnUpdate() override;
        virtual void OnEvent(Event& event) override;
    private:
        float m_Time = 0.0f; // Track time for ImGui
    };
}
