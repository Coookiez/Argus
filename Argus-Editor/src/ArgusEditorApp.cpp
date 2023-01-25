#include <Argus.h>
#include <Argus/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Argus
{
	class ArgusEditor : public Application
	{
	public:
		ArgusEditor(ApplicationCommandLineArgs args)
			: Application("Argus Editor", args)
		{
			PushLayer(new EditorLayer());
		}

		~ArgusEditor()
		{

		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new ArgusEditor(args);
	}
}