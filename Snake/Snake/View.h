#pragma once

//Òþ²Ø¹â±ê
void ViewInit(int width, int height);
void DisplayWall(int width, int height);
//´òÓ¡Éß
void DisplaySnake(Snake *pSnake);
void DisplaySnakeBlock(int x, int y);
void DisplayFood(int x, int y);
void CleanSnakeBlock(int x, int y);
void DisplayScore(int score);