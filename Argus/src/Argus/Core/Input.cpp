#include "aspch.h"
#include "Argus/Core/Input.h"

#ifdef AS_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace Argus {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef AS_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		AS_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}