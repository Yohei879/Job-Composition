#include "DxLib.h"
#include "Attack.h"

//攻撃の配列
AttackData g_AttackData[ATTACK_MAX] = {0};

//各攻撃のハンドル
int g_AttackHandle = 0;

void InitAttack()
{
	// 処理高速化のためポインタを使う
	AttackData* attack = g_AttackData;
	for (int i = 0; i < ATTACK_MAX; i++)
	{
		attack->handle = 0;
		attack->life = 0;
		attack->pos.x = 0.0f;
		attack->pos.y = 0.0f;
		attack->move.x = 0.0f;
		attack->move.y = 0.0f;
		attack->active = false;
	}
}

void LoadAttack()
{
	//画像をロード
	g_AttackHandle = LoadGraph("Data/Attack/Kinoken.png");
}

void StartAttack()
{
}

void StepAttack()
{
	AttackData* attack = g_AttackData;

	for (int i = 0; i < ATTACK_MAX; attack++, i++)
	{
		if (!attack->active)continue;

		attack->life--;
	}
}

void UpdateAttack()
{
}

void DrawAttack()
{
	// 処理高速化のためポインタを使う
	AttackData* attack = g_AttackData;
	for (int i = 0; i < ATTACK_MAX; i++, attack++)
	{
		// 生きている弾だけ描画する
		if (!attack->active) continue;

		DrawGraph((int)attack->pos.x, (int)attack->pos.y, attack->handle, TRUE);
	}
}



void FinAttack()
{
	DeleteGraph(g_AttackHandle);
}

void FireAttack(int life, float posX, float posY, float moveX, float moveY, float radius)
{
	//処理高速化のためポインタを使う
	AttackData* attack = g_AttackData;
	for (int i = 0; i < ATTACK_MAX; i++, attack++)
	{
		//配列内で使われていないところを探す
		if (!attack->active)
		{
			//アクティブにする
			attack->active = true;

			//画像ハンドル
			attack->handle = g_AttackHandle;

			//寿命設定
			attack->life = life;

			//座標設定
			attack->pos.x = posX;
			attack->pos.y = posY;

			//移動設定
			attack->move.x = moveX;
			attack->move.y = moveY;

			//半径(当たり判定)
			attack->radius = radius;

			//発射したらfor文を抜ける
			break;
		}
	}
}

AttackData* GetAttack()
{
	return g_AttackData;
}