#pragma once

#include <chrono>

class TimeManager
{
public:
	TimeManager()
	{
		previousTime = std::chrono::steady_clock::now();
	}
	~TimeManager() {}

	void Update();
	float GetDeltaTime() const;

private:
	std::chrono::steady_clock::time_point previousTime;
	float m_DeltaTime = 0.0f;
};

