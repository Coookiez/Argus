#pragma once

#include "Argus/Core/Core.h"

namespace Argus
{
	class ARGUS_API Input
	{
	public:
		static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
		static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		static bool GetMouseX() { return s_Instance->IsMouseXImpl(); }
		static bool GetMouseY() { return s_Instance->IsMouseYImpl(); }
		static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual bool IsMouseXImpl() = 0;
		virtual bool IsMouseYImpl() = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;

	private:
		static Input* s_Instance;
	};
}