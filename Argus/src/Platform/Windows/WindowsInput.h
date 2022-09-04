#pragma once

#include "Argus/Input.h"

namespace Argus
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual bool IsMouseXImpl() override;
		virtual bool IsMouseYImpl() override;

	};
}