#include <KatalystPCH.h>
#include "Layers/Layer.h"

namespace Katalyst 
{
	Layer::Layer(const std::string& debugName) : m_DebugName(debugName) {}
	Layer::~Layer() {}
}