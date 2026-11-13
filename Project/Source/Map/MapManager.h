#pragma once
#include "MapParameter.h"
#include "../Collision/CollsionParameter.h"

void InitMap();
void LoadMap();
void StartMap();
void DrawMap();
void FinMap();

void MoveWithMapCollision(Body* body);
void CalcCollision(Body* body, float& x, float& y, float& w, float& h, float& offsetX, float& offsetY);