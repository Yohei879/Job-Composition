#include "EnemySlime.h"
#include "DxLib.h"
#include "../Camera/Camera.h"

BlockData g_Enemys[BLOCK_MAX] = { 0 };

int enemyNum = 0;

int g_EnemyHandle[MAP_CHIP_ENEMY_MAX] = { 0 };

// 生存できるエリア
#define ENEMY_DRAGON_FLY_ACTIVE_AREA_LEFT	(-100)
#define ENEMY_DRAGON_FLY_ACTIVE_AREA_TOP	(-100)
#define ENEMY_DRAGON_FLY_ACTIVE_AREA_RIGHT	(2000)
#define ENEMY_DRAGON_FLY_ACTIVE_AREA_BOTTOM	(1000)

//スライムのID 
#define SLIME_ID (1)

void InitSlime()
{
}

void StartSlime()
{
}

void StepSlime()
{
}

void LoadSlime()
{
	int slimeHandle = LoadGraph("Data/Enemy/EnemySlime.png");


	FILE* fp;
	if (fopen_s(&fp, "Data/Map/Enemy.bin", "rb") != 0)return;


	for (int y = 0; y < MAP_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM; x++)
		{
			//マップ情報は1バイトずつ保存されているので、
			//fgetc関数でちょうど1バイト取得できる
			int map = fgetc(fp);
			if (map == 0) continue;

			if (map == SLIME_ID)
			{
				g_Enemys[enemyNum].pos.x = x * MAP_CHIP_WIDTH;
				g_Enemys[enemyNum].pos.y = y * MAP_CHIP_HEIGHT;
				g_Enemys[enemyNum].handle = slimeHandle;

				enemyNum++;

			}
		}
	}
}

void UpdateSlime()
{

}

void DrawSlime()
{
	// スクロールのためカメラを取得
	CameraData camera = GetCamera();

	BlockData* block = g_Enemys;
	for (int i = 0; i < enemyNum; i++, block++)
	{
		DrawExtendGraph(
			(int)block->pos.x * camera.pos.z,
			(int)block->pos.y * camera.pos.z,
			((int)block->pos.x + MAP_CHIP_WIDTH) * camera.pos.z,
			((int)block->pos.y + MAP_CHIP_HEIGHT) * camera.pos.z,
			block->handle,
			TRUE);
	}
	
}

void FinSlime()
{
}

BlockData Slime()
{
	return *g_Enemys;
}

void SlimeHitPlayer(int index)
{
	BlockData slime = g_Enemys[index];

	//衝突したら死亡
	slime.active = false;
}
