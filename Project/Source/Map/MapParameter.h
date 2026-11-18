#pragma once
#include "DxLib.h"
#include "../Collision/CollsionParameter.h"

#define BLOCK_MAX 100000
#define MAP_CHIP_X_NUM (70)
#define MAP_CHIP_Y_NUM (69)
#define MAP_CHIP_WIDTH (25.0f)
#define MAP_CHIP_HEIGHT (25.0f)
#define MAP_CHIP_RADIUS (12.5)

enum MapChipType
{
	MAP_CHIP_NONE,
	KABE1,
	KABE2,
	KABE3,
	KABE4,
	KABE5,
	KABE6,
	KABE7,
	KABE8,
	KABE9,
	KABE10,
	KABE11,
	KABE12,
	FLOOR,
	MAP_CHIP_MAX,
};

enum EnemyType
{
	MAP_CHIP_ENEMY_NONE,
	ENEMY_SLIME,
	MAP_CHIP_ENEMY_MAX
};

struct BlockData
{
	bool active;
	int handle;
	MapChipType type;
	VECTOR pos;
	Body body;
	float width;
	float height;
};

struct MapChipData
{
	int mapChip;
	BlockData* data;
};
