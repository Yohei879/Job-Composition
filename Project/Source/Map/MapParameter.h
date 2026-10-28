#pragma once
#include "DxLib.h"

#define BLOCK_MAX 10000
#define MAP_CHIP_X_NUM (70)
#define MAP_CHIP_Y_NUM (69)
#define MAP_CHIP_WIDTH (25.0f)
#define MAP_CHIP_HEIGHT (25.0f)

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
	
};

struct BlockData
{
	bool active;
	int handle;
	MapChipType type;
	VECTOR pos;
};

struct MapChipData
{
	int mapChip;
	BlockData* data;
};
