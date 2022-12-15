#pragma once

namespace Argus
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define AS_MOUSE_BUTTON_0      ::Argus::Mouse::Button0
#define AS_MOUSE_BUTTON_1      ::Argus::Mouse::Button1
#define AS_MOUSE_BUTTON_2      ::Argus::Mouse::Button2
#define AS_MOUSE_BUTTON_3      ::Argus::Mouse::Button3
#define AS_MOUSE_BUTTON_4      ::Argus::Mouse::Button4
#define AS_MOUSE_BUTTON_5      ::Argus::Mouse::Button5
#define AS_MOUSE_BUTTON_6      ::Argus::Mouse::Button6
#define AS_MOUSE_BUTTON_7      ::Argus::Mouse::Button7
#define AS_MOUSE_BUTTON_LAST   ::Argus::Mouse::ButtonLast
#define AS_MOUSE_BUTTON_LEFT   ::Argus::Mouse::ButtonLeft
#define AS_MOUSE_BUTTON_RIGHT  ::Argus::Mouse::ButtonRight
#define AS_MOUSE_BUTTON_MIDDLE ::Argus::Mouse::ButtonMiddle