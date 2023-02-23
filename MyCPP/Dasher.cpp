//#include <cstdio>
//#include <iostream>
//#include "raylib.h"
//
//struct AnimData 
//{
//	Rectangle rec;
//	Vector2 pos;
//	int frame;
//	float updateTime;
//	float runningTime;
//};
//
//
////Constants
//const int Gravity{ 2'000 };	//apostrophe ' is ignored by compiler (2'000 = 2000)
//const int JumpVel{ 7'00 }; //pixels/sec
//const float UpdateTime{ 1.0 / 12.0 };
//
//
//int WindowWidth = 800;
//int WindowHeight = 400;
//
//int BallVelocityX = 1;
//int BallVelocityY = 0;
//
//bool IsInAir{};
//
//float RunningTime{};
//
//float BGOffset{};
//float MGOffset{};
//float FGOffset{};
//
//int NebCount{};
//int ScoreToWin{5};
//bool HasWon{};
//bool HasLost{};
//
//
//void DrawBackground(Texture2D bg, float scale, float &bgOffs)
//{
//	for (int i = 0; i < 3; i++)
//	{
//
//		Vector2 bgPos = { (bg.width*scale*i)+bgOffs, 0 };
//
//		DrawTextureEx(bg, bgPos, 0, scale , WHITE);
//		
//	}
//
//	if (bgOffs < -(bg.width*scale))	//resets function (-)  = as moving left
//	{
//		bgOffs = 0;	//Sets by reference (as value is passed by ref)
//	}
//
//}
//
//
//
//int main()
//{
//		
//	InitWindow(WindowWidth, WindowHeight, "Axe Game");
//	//system("pause");
//
//	//Scarfy
//	Texture2D Scarfy = LoadTexture("textures/scarfy.png");	//Must be after Init WIndow
//	Rectangle ScarfyRec;
//	ScarfyRec.width = Scarfy.width / 6;
//	ScarfyRec.height = Scarfy.height;
//	ScarfyRec.x = 0;
//	ScarfyRec.y = 0;
//	Vector2 ScarfyPos;
//	ScarfyPos.x = WindowWidth / 2 - ScarfyRec.width/2;
//	ScarfyPos.y = WindowHeight - ScarfyRec.height;
//	
//	//Nebula
//	Texture2D Nebula = LoadTexture("textures/nebula.png");
//	Rectangle NebulaRec{ 0, 0, Nebula.width / 8, Nebula.height / 8 };
//	Vector2 NebulaPos{WindowWidth, WindowHeight-NebulaRec.height};
//	int NebulaVelX = 500;
//
//
//	int frame{};
//
//
//	//Backgrounds
//	Texture2D BG = LoadTexture("textures/bg.png");
//	Texture2D MG = LoadTexture("textures/mg.png");
//	Texture2D FG = LoadTexture("textures/fg.png");
//
//	SetTargetFPS(60);
//
//	while (!WindowShouldClose())
//	{
//		BeginDrawing();
//		ClearBackground(WHITE);			   		 		
//
//		//Delta Time = Time since last frame (time between 2 frames)
//		float dT{ GetFrameTime() };
//
//
//		
//		//Background Drawing
//		BGOffset -= 100.0*dT;
//		MGOffset -= 200.0*dT;
//		FGOffset -= 300.0*dT;
//
//		DrawBackground(BG, 2.1, BGOffset);
//		DrawBackground(MG, 2.1, MGOffset);
//		DrawBackground(FG, 2.1, FGOffset);
//
//
//
//		if (CheckCollisionPointCircle(ScarfyPos, NebulaPos, 100.0))	//Lose Condition
//		{
//			DrawText("GAME OVER \n Press 'R' to Restart", WindowWidth / 2, WindowHeight / 2, 25, RED);
//			HasLost = true;
//		}
//		else if (NebCount >= ScoreToWin)	//Win Condition
//		{
//			DrawText("Winner \n Press 'R' to Restart", WindowWidth / 2, WindowHeight / 2, 25, GREEN);
//			HasWon = true;
//		}
//		else //Draw Scarfy and Nebulae
//		{
//			//Ground Check
//			if (ScarfyPos.y >= WindowHeight - ScarfyRec.height)
//			{
//				//On Ground
//				IsInAir = false;
//				BallVelocityY = 0;
//			}
//
//			else
//			{	//In Air
//				IsInAir = true;
//				BallVelocityY += Gravity * dT;
//			}
//
//			//Jump Check
//			if (IsKeyPressed(KEY_SPACE) && !IsInAir)
//			{
//				BallVelocityY -= JumpVel;
//			}
//
//			//Finally Update Y position (On Tick)
//			ScarfyPos.y += BallVelocityY * dT;
//			NebulaPos.x -= NebulaVelX * dT;
//			if (NebulaPos.x <= -NebulaRec.width) { NebulaPos.x = WindowWidth; NebCount++; }
//
//			DrawTextureRec(Scarfy, ScarfyRec, ScarfyPos, WHITE);
//			DrawTextureRec(Nebula, NebulaRec, NebulaPos, RED);
//
//			//Update Running Time
//			RunningTime += dT;
//			if (RunningTime >= UpdateTime)
//			{
//				RunningTime = 0;
//				//Update Animation Frame
//				if (!IsInAir) { ScarfyRec.x = frame * ScarfyRec.width; }
//				NebulaRec.x = frame * NebulaRec.width;
//				if (++frame > 5) { frame = 0; }
//			}
//						
//		}
//		
//		//Shows Score
//		DrawText(TextFormat("Score: %i", NebCount), 10, 10, 20, YELLOW);
//		DrawText(TextFormat("Score %i to Win", ScoreToWin), WindowWidth - 200, 10, 20, LIGHTGRAY);
//
//		if (IsKeyPressed(KEY_R) )	//Game Restart
//		{
//			NebCount = 0;
//			HasWon = HasLost = false;
//			NebulaPos = {float(WindowWidth), float(WindowHeight-NebulaRec.height)};
//		}
//
//		
//			
//		EndDrawing();
//
//	}
//
//	UnloadTexture(Scarfy);
//	UnloadTexture(Nebula);
//	UnloadTexture(BG);
//	UnloadTexture(MG);
//	UnloadTexture(FG);
//
//	CloseWindow();
//		
//}