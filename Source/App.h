#pragma once

#include <memory>

#include "Window.h"
#include "TimeManager.h"
#include "PhysicsManager.h"

class App
{
public:
	App() {}
	~App() {}

	void Run();

private:
	void InternalInit();

	void InternalInput();
	void InternalUpdate();
	void InternalRender();

private:
	std::unique_ptr<Window> m_Window = nullptr;
	std::unique_ptr<TimeManager> m_TimeManager = nullptr;
	std::unique_ptr<PhysicsManager> m_PhysicsManager = nullptr;
};

