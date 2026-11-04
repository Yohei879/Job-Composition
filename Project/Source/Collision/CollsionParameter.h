#pragma once
#include "DxLib.h"

struct Body
{
	bool isAir;
	VECTOR pos;
	VECTOR move;
	float width;
	float height;
	float radius;
	float reflactPower;
	VECTOR prevPos;
	const Body* hitBlock;
	const Body* groundBlock;
};