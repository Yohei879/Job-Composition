#include "EnemySlime.h"
#include "DxLib.h"
#include "../Camera/Camera.h"

EnemyData g_Enemies[ENEMY_MAX];

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
				g_Enemies[enemyNum].body.pos.x = x * MAP_CHIP_WIDTH;
				g_Enemies[enemyNum].body.pos.y = y * MAP_CHIP_HEIGHT;
				g_Enemies[enemyNum].handle = slimeHandle;
				g_Enemies[enemyNum].body.width = ENEMYSLIME_WIDTH;
				g_Enemies[enemyNum].body.height = ENEMYSLIME_HEIGHT;
				g_Enemies[enemyNum].active = true;
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
	CameraData* camera = GetCamera();

	EnemyData* enemy = g_Enemies;
	for (int i = 0; i < enemyNum; i++, enemy++)
	{
		DrawExtendGraph(
			(int)(enemy->body.pos.x - camera->pos.x) * camera->pos.z,
			(int)(enemy->body.pos.y - camera->pos.y) * camera->pos.z,
			((int)(enemy->body.pos.x - camera->pos.x) + MAP_CHIP_WIDTH) * camera->pos.z,
			((int)(enemy->body.pos.y - camera->pos.y) + MAP_CHIP_HEIGHT) * camera->pos.z,
			enemy->handle,
			TRUE);
	}
	
}

void FinSlime()
{
}

EnemyData* GetSlime()
{
	return g_Enemies;
}

void SlimeHitPlayer(int index)
{
	EnemyData slime = g_Enemies[index];

	//衝突したら死亡
	slime.active = false;
}
