#pragma once

namespace Argus
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define AS_KEY_SPACE           ::Argus::Key::Space
#define AS_KEY_APOSTROPHE      ::Argus::Key::Apostrophe    /* ' */
#define AS_KEY_COMMA           ::Argus::Key::Comma         /* , */
#define AS_KEY_MINUS           ::Argus::Key::Minus         /* - */
#define AS_KEY_PERIOD          ::Argus::Key::Period        /* . */
#define AS_KEY_SLASH           ::Argus::Key::Slash         /* / */
#define AS_KEY_0               ::Argus::Key::D0
#define AS_KEY_1               ::Argus::Key::D1
#define AS_KEY_2               ::Argus::Key::D2
#define AS_KEY_3               ::Argus::Key::D3
#define AS_KEY_4               ::Argus::Key::D4
#define AS_KEY_5               ::Argus::Key::D5
#define AS_KEY_6               ::Argus::Key::D6
#define AS_KEY_7               ::Argus::Key::D7
#define AS_KEY_8               ::Argus::Key::D8
#define AS_KEY_9               ::Argus::Key::D9
#define AS_KEY_SEMICOLON       ::Argus::Key::Semicolon     /* ; */
#define AS_KEY_EQUAL           ::Argus::Key::Equal         /* = */
#define AS_KEY_A               ::Argus::Key::A
#define AS_KEY_B               ::Argus::Key::B
#define AS_KEY_C               ::Argus::Key::C
#define AS_KEY_D               ::Argus::Key::D
#define AS_KEY_E               ::Argus::Key::E
#define AS_KEY_F               ::Argus::Key::F
#define AS_KEY_G               ::Argus::Key::G
#define AS_KEY_H               ::Argus::Key::H
#define AS_KEY_I               ::Argus::Key::I
#define AS_KEY_J               ::Argus::Key::J
#define AS_KEY_K               ::Argus::Key::K
#define AS_KEY_L               ::Argus::Key::L
#define AS_KEY_M               ::Argus::Key::M
#define AS_KEY_N               ::Argus::Key::N
#define AS_KEY_O               ::Argus::Key::O
#define AS_KEY_P               ::Argus::Key::P
#define AS_KEY_Q               ::Argus::Key::Q
#define AS_KEY_R               ::Argus::Key::R
#define AS_KEY_S               ::Argus::Key::S
#define AS_KEY_T               ::Argus::Key::T
#define AS_KEY_U               ::Argus::Key::U
#define AS_KEY_V               ::Argus::Key::V
#define AS_KEY_W               ::Argus::Key::W
#define AS_KEY_X               ::Argus::Key::X
#define AS_KEY_Y               ::Argus::Key::Y
#define AS_KEY_Z               ::Argus::Key::Z
#define AS_KEY_LEFT_BRACKET    ::Argus::Key::LeftBracket   /* [ */
#define AS_KEY_BACKSLASH       ::Argus::Key::Backslash     /* \ */
#define AS_KEY_RIGHT_BRACKET   ::Argus::Key::RightBracket  /* ] */
#define AS_KEY_GRAVE_ACCENT    ::Argus::Key::GraveAccent   /* ` */
#define AS_KEY_WORLD_1         ::Argus::Key::World1        /* non-US #1 */
#define AS_KEY_WORLD_2         ::Argus::Key::World2        /* non-US #2 */

/* Function keys */
#define AS_KEY_ESCAPE          ::Argus::Key::Escape
#define AS_KEY_ENTER           ::Argus::Key::Enter
#define AS_KEY_TAB             ::Argus::Key::Tab
#define AS_KEY_BACKSPACE       ::Argus::Key::Backspace
#define AS_KEY_INSERT          ::Argus::Key::Insert
#define AS_KEY_DELETE          ::Argus::Key::Delete
#define AS_KEY_RIGHT           ::Argus::Key::Right
#define AS_KEY_LEFT            ::Argus::Key::Left
#define AS_KEY_DOWN            ::Argus::Key::Down
#define AS_KEY_UP              ::Argus::Key::Up
#define AS_KEY_PAGE_UP         ::Argus::Key::PageUp
#define AS_KEY_PAGE_DOWN       ::Argus::Key::PageDown
#define AS_KEY_HOME            ::Argus::Key::Home
#define AS_KEY_END             ::Argus::Key::End
#define AS_KEY_CAPS_LOCK       ::Argus::Key::CapsLock
#define AS_KEY_SCROLL_LOCK     ::Argus::Key::ScrollLock
#define AS_KEY_NUM_LOCK        ::Argus::Key::NumLock
#define AS_KEY_PRINT_SCREEN    ::Argus::Key::PrintScreen
#define AS_KEY_PAUSE           ::Argus::Key::Pause
#define AS_KEY_F1              ::Argus::Key::F1
#define AS_KEY_F2              ::Argus::Key::F2
#define AS_KEY_F3              ::Argus::Key::F3
#define AS_KEY_F4              ::Argus::Key::F4
#define AS_KEY_F5              ::Argus::Key::F5
#define AS_KEY_F6              ::Argus::Key::F6
#define AS_KEY_F7              ::Argus::Key::F7
#define AS_KEY_F8              ::Argus::Key::F8
#define AS_KEY_F9              ::Argus::Key::F9
#define AS_KEY_F10             ::Argus::Key::F10
#define AS_KEY_F11             ::Argus::Key::F11
#define AS_KEY_F12             ::Argus::Key::F12
#define AS_KEY_F13             ::Argus::Key::F13
#define AS_KEY_F14             ::Argus::Key::F14
#define AS_KEY_F15             ::Argus::Key::F15
#define AS_KEY_F16             ::Argus::Key::F16
#define AS_KEY_F17             ::Argus::Key::F17
#define AS_KEY_F18             ::Argus::Key::F18
#define AS_KEY_F19             ::Argus::Key::F19
#define AS_KEY_F20             ::Argus::Key::F20
#define AS_KEY_F21             ::Argus::Key::F21
#define AS_KEY_F22             ::Argus::Key::F22
#define AS_KEY_F23             ::Argus::Key::F23
#define AS_KEY_F24             ::Argus::Key::F24
#define AS_KEY_F25             ::Argus::Key::F25

/* Keypad */
#define AS_KEY_KP_0            ::Argus::Key::KP0
#define AS_KEY_KP_1            ::Argus::Key::KP1
#define AS_KEY_KP_2            ::Argus::Key::KP2
#define AS_KEY_KP_3            ::Argus::Key::KP3
#define AS_KEY_KP_4            ::Argus::Key::KP4
#define AS_KEY_KP_5            ::Argus::Key::KP5
#define AS_KEY_KP_6            ::Argus::Key::KP6
#define AS_KEY_KP_7            ::Argus::Key::KP7
#define AS_KEY_KP_8            ::Argus::Key::KP8
#define AS_KEY_KP_9            ::Argus::Key::KP9
#define AS_KEY_KP_DECIMAL      ::Argus::Key::KPDecimal
#define AS_KEY_KP_DIVIDE       ::Argus::Key::KPDivide
#define AS_KEY_KP_MULTIPLY     ::Argus::Key::KPMultiply
#define AS_KEY_KP_SUBTRACT     ::Argus::Key::KPSubtract
#define AS_KEY_KP_ADD          ::Argus::Key::KPAdd
#define AS_KEY_KP_ENTER        ::Argus::Key::KPEnter
#define AS_KEY_KP_EQUAL        ::Argus::Key::KPEqual

#define AS_KEY_LEFT_SHIFT      ::Argus::Key::LeftShift
#define AS_KEY_LEFT_CONTROL    ::Argus::Key::LeftControl
#define AS_KEY_LEFT_ALT        ::Argus::Key::LeftAlt
#define AS_KEY_LEFT_SUPER      ::Argus::Key::LeftSuper
#define AS_KEY_RIGHT_SHIFT     ::Argus::Key::RightShift
#define AS_KEY_RIGHT_CONTROL   ::Argus::Key::RightControl
#define AS_KEY_RIGHT_ALT       ::Argus::Key::RightAlt
#define AS_KEY_RIGHT_SUPER     ::Argus::Key::RightSuper
#define AS_KEY_MENU            ::Argus::Key::Menu