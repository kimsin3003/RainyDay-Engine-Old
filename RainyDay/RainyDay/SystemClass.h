#pragma once

#include <windows.h>
#include "Model.h"
#include <string>
#include "Time.h"
#include <unordered_map>

namespace RainyDay {
	class Scene;
	class InputClass;
	class Renderer;

	const bool FULL_SCREEN = false;

	class DLL_API SystemClass
	{
	public:
		static SystemClass* GetInstance();
		~SystemClass();
		void SetScene(Scene* scene);
		bool Initialize(int screenWidth, int screenHeight);
		void Shutdown();
		void Run();
		void StopSound(std::string fileName);
		void PlaySoundFile(std::string fileName);
		void LoadTexture(WCHAR* fileName);
		void SetLightDirection(XMFLOAT4 lightDirection);
		void CloseSoundFile(std::string fileName);
		void PreLoadSoundFile(std::string fileName);
		void StoreBoolVariable(std::string name, bool value);
		bool HasBoolVariable(std::string name);
		bool GetBoolVariable(std::string name);
		void SetBoolVariable(std::string name, bool value);
		LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

	private:
		SystemClass();
		bool Frame();
		void InitializeWindows(int screenWidth, int screenHeight);
		void ShutdownWindows();

	private:
		static SystemClass* instance;
		LPCWSTR m_applicationName;
		HINSTANCE m_hinstance;
		HWND m_hwnd;

		InputClass* m_input;
		Time m_timer;
		Renderer* m_renderer;
		Scene* m_currentScene = nullptr;

		std::unordered_map<std::string, int> m_intStorage;

	};


	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


	static SystemClass* ApplicationHandle = nullptr;
}