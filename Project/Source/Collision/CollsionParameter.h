#pragma once
#include "DxLib.h"

enum PlayerState
{
	PLAYER_STATE_WALK,
	PLAYER_STATE_ATTACK,
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
	PlayerState state;
	VECTOR prevPos;
	const Body* hitBlock;
	const Body* groundBlock;
};
