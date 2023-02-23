#pragma once
#include "raylib.h"

class BaseCharacter
{
public:
	BaseCharacter();

	Vector2 getWorldPos() { return worldPos; }
	void undoMovement();
	Rectangle getColRec();
	virtual void tick(float deltaTime);
	virtual Vector2 getScreenPos() = 0;	//Pure Virtual func = This class is "Abstract Class" now
	bool getAlive() { return alive; }
	void setAlive(bool isAlive) { alive = isAlive; }

protected:
	Texture2D texture{ LoadTexture("characters/knight_idle_spritesheet.png") };
	Texture2D idle{ texture };
	Texture2D run{ LoadTexture("characters/knight_run_spritesheet.png") };
	float width{};
	float height{};
	float scale{ 5 };
	Vector2 worldPos{};
	Vector2 worldPosLastFrame{};
	//Flip the sprite
	float FlipDirection{ 1 };
	//Animation Vars
	float runningTime{};
	int frame{};
	int maxFrames{ 6 };
	float updateTime{ 1.f / 12.f };
	float speed{ 4.f };
	Vector2 velocity{};

private:
	bool alive{ true };
};

