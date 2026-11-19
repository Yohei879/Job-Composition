#pragma once
#include "DxLib.h"

enum ActionState
{
	ACTION_STATE_WALK,
	ACTION_STATE_ATTACK,
};

struct Body
{
	bool isAir;
	VECTOR pos;
	VECTOR move;
	float width;
	float height;
	float radius;
	float reflactPower;
	float dir;
	float collisionWidth;
	float collisionHeight;
	ActionState state;
	VECTOR prevPos;
	const Body* hitBlock;
	const Body* groundBlock;
};
