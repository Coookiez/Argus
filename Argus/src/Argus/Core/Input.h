#pragma once

#include <glm/glm.hpp>

#include "Argus/Core/KeyCodes.h"
#include "Argus/Core/MouseCodes.h"

namespace Argus {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}