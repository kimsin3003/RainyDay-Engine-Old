#include "stdafx.h"
#include "SystemClass.h"
#include "Scene.h"
#include "MainScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	bool result;


	// Create the system object.

	SystemClass* system = SystemClass::GetInstance();
	if (!system)
	{
		return 0;
	}

	// Initialize and run the system object.
	result = system->Initialize(1024, 768);

	SystemClass::GetInstance()->SetBoolVariable("started", false);

	Scene* scene = new MainScene();
	system->SetScene(scene);
	if (result)
	{
		system->Run();
	}

	// Shutdown and release the system object.
	system->Shutdown();
	delete system;
	system = 0;

	return 0;
}