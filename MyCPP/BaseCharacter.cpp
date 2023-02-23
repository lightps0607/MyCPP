#include "BaseCharacter.h"
#include "raymath.h"


BaseCharacter::BaseCharacter()
{
}


void BaseCharacter::undoMovement()
{
	worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getColRec()
{
	return Rectangle{
		getScreenPos().x,
		getScreenPos().y,
		width * scale,
		height * scale
	};
}

void BaseCharacter::tick(float deltaTime)
{
	worldPosLastFrame = worldPos;

	//Update Animation Frame
	runningTime += deltaTime;
	if (runningTime >= updateTime)
	{
		frame++;
		runningTime = 0.f;
		if (frame > maxFrames) frame = 0;
	}
	
	//Movement
	if (Vector2Length(velocity) != 0.0)
	{
		//set worldPos = worldPos - direction
		worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));

		velocity.x < 0.f ? FlipDirection = -1 : FlipDirection = 1;	//Ternary operation
		texture = run;
	}
	else
	{
		texture = idle;
	}
	velocity = {};	//Resets Velocity

	//Draw the character
	Rectangle source{ frame * width, 0.f, FlipDirection * width, height };
	Rectangle dest{ getScreenPos().x, getScreenPos().y, scale * width, scale * height };
	DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);

}
