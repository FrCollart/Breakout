#pragma once

// Window
constexpr int WINDOW_WIDTH = 600;
constexpr int WINDOW_HEIGHT = 800;
constexpr const char* WINDOW_TITLE = "Breakout";

// Gameplay
constexpr const int GRID_WIDTH = WINDOW_WIDTH;
constexpr const int GRID_HEIGHT = 300;
constexpr const int GRID_Y = 100;
constexpr const int GRID_X = 0;
constexpr const int GRID_INTER = 5;

constexpr const float DEFAULT_BRICK_WIDTH = 60.0f;
constexpr const float DEFAULT_BRICK_HEIGHT = 20.0f;

constexpr const float DEFAULT_BALL_SPEED = 100.0f;
constexpr const float DEFAULT_BALL_DIRECTIONX = 0.0f;
constexpr const float DEFAULT_BALL_DIRECTIONY = -1.0f;
constexpr const float DEFAULT_BALL_SIZE = 10.0f;

constexpr const float DEFAULT_PLAYER_WIDTH = 100.0f;
constexpr const float DEFAULT_PLAYER_HEIGHT = 20.0f;

// Textures path
constexpr const char* TEXTUREPLAYER = "";
constexpr const char* TEXTUREBALL = "Sprite/test.png";
constexpr const char* TEXTUREBRICK = "";