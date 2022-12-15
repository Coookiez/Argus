#include <Argus.h>
#include <Argus/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Argus
{
	class ArgusEditor : public Application
	{
	public:
		ArgusEditor()
			: Application("Argus Editor")
		{
			PushLayer(new EditorLayer());
		}

		~ArgusEditor()
		{

		}
	};

	Application* CreateApplication()
	{
		return new ArgusEditor();
	}
}