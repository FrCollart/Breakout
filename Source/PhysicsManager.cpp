#include "PhysicsManager.h"

#include "EntityManager.h"
#include "Entity.h"
#include "Player.h"
#include "Ball.h"
#include "Brick.h"

void PhysicsManager::Update(float deltaTime)
{
	auto balls = EntityManager::GetInstance().GetEntitiesByType<Ball>();
	auto players = EntityManager::GetInstance().GetEntitiesByType<Player>();
	auto bricks = EntityManager::GetInstance().GetEntitiesByType<Brick>();

	for (auto& ball : balls)
	{
        float ballX = ball->GetX();
        float ballY = ball->GetY();
        float radius = ball->GetSize();

        if (ballX - radius < 0 || ballX + radius > WINDOW_WIDTH)
        {
            ball->OnCollideWithBorder(true);
        }

        if (ballY - radius < 0 || ballY + radius > WINDOW_HEIGHT)
        {
            ball->OnCollideWithBorder(false);
        }

        for (auto& player : players)
        {
            float playerCenterX = player->GetX();
            float playerCenterY = player->GetY();
            float playerX = playerCenterX - DEFAULT_PLAYER_WIDTH / 2.0f;
            float playerY = playerCenterY - DEFAULT_PLAYER_HEIGHT / 2.0f;

            if (CheckCircleAABBCollision(ballX, ballY, radius, playerX, playerY, DEFAULT_PLAYER_WIDTH, DEFAULT_PLAYER_HEIGHT))
            {
                ball->OnCollide(*player);
                player->OnCollide(*ball);
            }
        }

        for (auto& brick : bricks)
        {
            if (CheckCircleAABBCollision(ballX, ballY, radius, brick->GetX(), brick->GetY(), brick->GetWidth(), brick->GetHeight()))
            {
                ball->OnCollide(*brick);
                brick->OnCollide(*ball);
            }
        }
	}
}

bool PhysicsManager::CheckCircleAABBCollision(float circleX, float circleY, float radius,
                                              float rectX, float rectY, float rectWidth, float rectHeight)
{
    float closestX = std::max(rectX, std::min(circleX, rectX + rectWidth));
    float closestY = std::max(rectY, std::min(circleY, rectY + rectHeight));

    float distanceX = circleX - closestX;
    float distanceY = circleY - closestY;

    return (distanceX * distanceX + distanceY * distanceY) < (radius * radius);
}
