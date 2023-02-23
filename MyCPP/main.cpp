#include <cstdio>
#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"
#include <string>

const int WindowWidth = 400;
const int WindowHeight = 400;

int main()
{
	SetTargetFPS(60);
	InitWindow(WindowWidth, WindowHeight, "Classy Clash");

	Texture2D MapTex = LoadTexture("nature_tileset/WorldMap.png");
	Vector2 mapPos{ 0.0, 0.0 };
	const float mapScale{ 4.f };

	Character Knight{WindowWidth, WindowHeight};

	Enemy goblin{
		Vector2{800.f, 300.f},
		LoadTexture("characters/goblin_idle_spritesheet.png"),
		LoadTexture("characters/goblin_run_spritesheet.png")
	};
	goblin.setTarget(&Knight);

	Enemy slime{
		Vector2{500.f, 700.f},
		LoadTexture("characters/slime_idle_spritesheet.png"),
		LoadTexture("characters/slime_run_spritesheet.png")
	};

	Enemy* enemies[]{
		&goblin,
		&slime
	};

	for (auto enemy : enemies)
	{
		enemy->setTarget(&Knight);
	}

	Prop props[]{
		Prop{{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
		Prop{{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")},
	};
	
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		mapPos = Vector2Scale(Knight.getWorldPos(), -1.f);
		//Draw Map
		DrawTextureEx(MapTex, mapPos, 0.0, mapScale, WHITE);
		
		//Draw Props
		for(auto p : props)	//same as for each (Range based for loop)
		{
			p.Render(Knight.getWorldPos());
		}


		if (!Knight.getAlive())
		{
			DrawText("Game Over!", 55.f, 45.f, 40, RED);
			EndDrawing();
			continue;	//Everything below this will get ignored (similar to return just doesn't close the game)
		}
		else
		{
			std::string knihtHealth = "Health : ";
			knihtHealth.append(std::to_string(Knight.getHealth()), 0, 5);
			DrawText(knihtHealth.c_str(), 55.f, 45.f, 40, RED);
		}

		Knight.tick(GetFrameTime());

		goblin.tick(GetFrameTime());
		
		for (auto enemy : enemies)
		{
			enemy->tick(GetFrameTime());
		}
		//Check Map Bounds
		Vector2 wPos = Knight.getWorldPos();
		if (wPos.x < 0.f ||
			wPos.y < 0.f ||
			wPos.x + WindowWidth > MapTex.width * mapScale ||
			wPos.y + WindowHeight > MapTex.height * mapScale)
		{
			Knight.undoMovement();
		}


		//Collision Check
		for (auto p : props)
		{
			if ( CheckCollisionRecs( p.getColRec(Knight.getWorldPos()), Knight.getColRec() ) )
			{
				Knight.undoMovement();
			}
		}

		//Weapon Collision
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			for (auto enemy : enemies)
			{
				if (CheckCollisionRecs(Knight.getWeaponColRec(), enemy->getColRec()))
				{
					enemy->setAlive(false);
				}
			}

			
		}

		EndDrawing();
	}

	CloseWindow();

}