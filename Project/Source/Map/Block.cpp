#include "Block.h"
#include "../Camera/Camera.h"

BlockData g_Blocks[BLOCK_MAX] = { 0 };

int g_BlockHandle[MAP_CHIP_MAX] = { 0 };


void InitBlock()
{
	BlockData* block = g_Blocks;
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		block->active = false;
		block->pos = VGet(0.0f, 0.0f, 0.0f);
		block->type = MAP_CHIP_NONE;
	}
}

void LoadBlock()
{
	g_BlockHandle[KABE1] = LoadGraph("Data/Map/Kabe1.png");
	g_BlockHandle[KABE2] = LoadGraph("Data/Map/Kabe2.png");
	g_BlockHandle[KABE3] = LoadGraph("Data/Map/Kabe3.png");
	g_BlockHandle[KABE4] = LoadGraph("Data/Map/Kabe4.png");
	g_BlockHandle[KABE5] = LoadGraph("Data/Map/Kabe5.png");
	g_BlockHandle[KABE6] = LoadGraph("Data/Map/Kabe6.png");
	g_BlockHandle[KABE7] = LoadGraph("Data/Map/Kabe7.png");
	g_BlockHandle[KABE8] = LoadGraph("Data/Map/Kabe8.png");
	g_BlockHandle[KABE9] = LoadGraph("Data/Map/Kabe9.png");
	g_BlockHandle[KABE10] = LoadGraph("Data/Map/Kabe10.png");
	g_BlockHandle[KABE11] = LoadGraph("Data/Map/Kabe11.png");
	g_BlockHandle[KABE12] = LoadGraph("Data/Map/Kabe12.png");
	g_BlockHandle[FLOOR] = LoadGraph("Data/Map/Yuka.png");
}

void StartBlock()
{
}

void StepBlock()
{
}

void DrawBlock()
{
	// スクロールのためカメラを取得
	CameraData camera = GetCamera();

	BlockData* block = g_Blocks;
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (block->active)
		{
			//DrawGraph((int)(block->pos.x - camera.pos.x), (int)(block->pos.y - camera.pos.y), block->handle, TRUE);
			DrawExtendGraph(
				(int)block->pos.x * camera.pos.z,
				(int)block->pos.y * camera.pos.z,
				((int)block->pos.x + MAP_CHIP_WIDTH) * camera.pos.z,
				((int)block->pos.y + MAP_CHIP_HEIGHT) * camera.pos.z,
				block->handle,
				TRUE);
		}
	}
}

void FinBlock()
{
}

BlockData* CreateBlock(MapChipType type, VECTOR pos)
{
	// 未使用のブロックを探す
	BlockData* block = g_Blocks;
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (!block->active)
		{
			// ブロック生成
			block->active = true;
			block->handle = g_BlockHandle[type];
			block->pos = pos;
			block->type = type;
			block->width = MAP_CHIP_WIDTH;
			block->height = MAP_CHIP_HEIGHT;
			return block;
		}
	}

	return nullptr;
}

BlockData* GetBlocks()
{
	return g_Blocks;
}
