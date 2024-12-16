#include "TimeManager.h"

void TimeManager::Update()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	m_DeltaTime = std::chrono::duration<float>(currentTime - previousTime).count();
	previousTime = currentTime;
}

float TimeManager::GetDeltaTime() const
{
	return m_DeltaTime;
}
