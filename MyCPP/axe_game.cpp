//#include <cstdio>
//#include <iostream>
//#include "raylib.h"
//
//
//int main()
//{
//
//	int Height = 400;
//	int Width = 800;
//
//	int CircleLocX = Width / 2;
//	int CircleLocY = Height / 2;
//
//	int BoxLocX = (Width / 2) + 150;
//	int BoxLocY = Height / 2;
//	int BoxHeight = 50;
//	int BoxWidth = 50;
//	int BoxDirection = 1;
//
//	int BallSpeed = 1;
//	int BallRadius = 50;
//
//	InitWindow(Width, Height, "Axe Game");
//	//system("pause");
//
//
//	SetTargetFPS(60);
//
//	while (!WindowShouldClose())
//	{
//		BeginDrawing();
//		ClearBackground(GREEN);
//
//
//		//Inputs
//		if (IsKeyDown(KEY_D))
//		{
//			if (CircleLocX < Width - BallRadius) { CircleLocX += BallSpeed; }
//		}
//		if (IsKeyDown(KEY_A))
//		{
//			if (CircleLocX > BallRadius) { CircleLocX -= BallSpeed; }
//		}
//		if (IsKeyDown(KEY_S))
//		{
//			if (CircleLocY < Height - BallRadius) { CircleLocY += BallSpeed; }
//		}
//		if (IsKeyDown(KEY_W))
//		{
//			if (CircleLocY > BallRadius) { CircleLocY -= BallSpeed; }
//		}
//
//		if (IsKeyPressed(KEY_Q))
//		{
//			if (BallSpeed > 0) { BallSpeed--; }
//		}
//
//		if (IsKeyPressed(KEY_E))
//		{
//			if (BallSpeed < 5) { BallSpeed++; }
//		}
//
//		//std::clamp(5,4,4);
//
//		DrawCircle(CircleLocX, CircleLocY, (float)BallRadius, BLUE);
//
//
//
//		//Box or Axe
//		//if (BoxLocY < Height+50 && BoxLocY > -50) { BoxLocY++; }		else { BoxLocY = Height + 45; }	//Continuous
//		if (BoxLocY > Height-50 || BoxLocY < 0) { BoxDirection *= -1; }	//Bounce
//		BoxLocY += BoxDirection;
//		DrawRectangle(BoxLocX, BoxLocY, BoxWidth, BoxHeight, RED);
//
//
//		//Collision Detection
//
//		int RE_C_Loc = CircleLocX + BallRadius;	//Right Edge
//		int LE_C_Loc = CircleLocX - BallRadius;	//Left Edge
//		int UE_C_Loc = CircleLocY - BallRadius;	//Upper Edge
//		int DE_C_Loc = CircleLocY + BallRadius;	//Down Edge
//
//		int RE_B_Loc = BoxLocX + BoxWidth;
//		int LE_B_Loc = BoxLocX;
//		int UE_B_Loc = BoxLocY;
//		int DE_B_Loc = BoxLocY + BoxHeight;
//
//		bool IsColliding = (RE_C_Loc >= LE_B_Loc) && (DE_C_Loc >= UE_B_Loc) && (LE_C_Loc <= RE_B_Loc) && (UE_C_Loc <= DE_B_Loc);
//
//		if (IsColliding)
//		{
//			DrawText("Game Over!!!", Width / 2, Height / 2, 50, RED);
//		}
//
//
//
//		EndDrawing();
//
//	}
//
//		
//}