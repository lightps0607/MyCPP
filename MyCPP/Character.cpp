#include "Character.h"
#include "raymath.h"


Character::Character(int winWidth, int winHeight):
	windowWidth(winWidth),
	windowHeight(winHeight)
{
	width = texture.width / maxFrames;
	height = texture.height;
}



void Character::tick(float deltaTime)	//this stills gets called every frame not with delta sec
{
	if (!getAlive()) return;	//Dead

	//Inputs
	if (IsKeyDown(KEY_A)) velocity.x = -1.0;
	if (IsKeyDown(KEY_D)) velocity.x = 1.0;
	if (IsKeyDown(KEY_W)) velocity.y = -1.0;
	if (IsKeyDown(KEY_S)) velocity.y = 1.0;

	BaseCharacter::tick(deltaTime);

	Vector2 origin{};
	Vector2 offset{};
	float rotation{};
	if (FlipDirection > 0.f)
	{
		origin = { 0.f, weapon.height * scale };	//bottom-left corner
		offset = { 45.f, 75.f };
		IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? rotation = 35.f : rotation = 0.f;
		weaponColRec = {
			getScreenPos().x + offset.x,
			getScreenPos().y + offset.y - weapon.height * scale,
			weapon.width * scale,
			weapon.height * scale
		};
		
	} 
	else
	{
		origin = {weapon.width * scale, weapon.height * scale};	//bottom-right corner
		offset = { 25.f, 75.f };
		IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? rotation = -35.f : rotation = 0.f;
		weaponColRec = {
			getScreenPos().x + offset.x - weapon.width * scale,
			getScreenPos().y + offset.y - weapon.height * scale,
			weapon.width * scale,
			weapon.height * scale
		};
	}
	//Draw Sword
	Rectangle source{ 0.f, 0.f, static_cast<float>(weapon.width) * FlipDirection, static_cast<float>(weapon.height) };
	Rectangle dest{ getScreenPos().x + offset.x, getScreenPos().y + offset.y, weapon.width*scale, weapon.height*scale };
	DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);

	//DrawRectangleLines(weaponColRec.x, weaponColRec.y, weaponColRec.width, weaponColRec.height, RED);

}

Vector2 Character::getScreenPos()
{
	return Vector2{
		static_cast<float>(windowWidth / 2 - scale * (0.5 * width)),
		static_cast<float>(windowHeight / 2 - scale * (0.5 * height))
	};
}

void Character::takeDamage(float damage)
{
	health -= damage;
	if (health <= 0.f)
	{
		setAlive(false);
	}
}


