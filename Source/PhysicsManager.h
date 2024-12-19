#pragma once

#include <memory>

class PhysicsManager
{
public:
	PhysicsManager() {}
	~PhysicsManager() {}

	void Update(float deltaTime);

private:
	bool CheckCircleAABBCollision(float circleX, float circleY, float radius,
		float rectX, float rectY, float rectWidth, float rectHeight);
};

