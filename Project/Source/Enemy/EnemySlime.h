#pragma once
#include "../Map/MapParameter.h"
#include "../Map/MapChip.h"
#include "../Collision/CollsionParameter.h"

#define ENEMYSLIME_HEIGHT (46)
#define ENEMYSLIME_WIDTH (44)
#define ENEMY_SLIME_RADIUS (ENEMYSLIME_WIDTH / 2)
#define ENEMY_MAX (120)
struct EnemyData
{
	EnemyType enemyType;
	Body body;
	bool active;				//生存フラグ
	bool invisible;				//無敵フラグ
	int handle;					//画像ハンドル
};

void InitSlime();
void StartSlime();
void StepSlime();
void LoadSlime();
void UpdateSlime();
void DrawSlime();
void FinSlime();

//Slimes取得
EnemyData* GetSlime();

//当たり判定関連
void SlimeHitPlayer(int index);
