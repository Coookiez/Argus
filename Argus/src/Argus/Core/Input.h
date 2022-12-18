#pragma once

#include "Argus/Core/Base.h"
#include "Argus/Core/KeyCodes.h"
#include "Argus/Core/MouseCodes.h"

namespace Argus {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}