#include "AttackManager.h"
#include "Attack.h"

void InitAllAttack()
{
	//全ての攻撃初期化
	InitAttack();
}

void LoadAllAttack()
{
	//全ての攻撃ロード
	LoadAttack();
}

void StepAllAttack()
{
	//全ての攻撃ステップ
	StepAttack();
}

void UpdateAllAttack()
{
	//全ての攻撃更新
	UpdateAttack();
}

void DrawAllAttack()
{
	//全ての攻撃描画
	DrawAttack();
}

void FinAllAttack()
{
	//全ての攻撃終了
	FinAttack();
}

void RequestFireAttack(int life, float posX, float posY, float moveX, float moveY, float radius)
{
	//攻撃
	FireAttack(life, posX, posY, moveX, moveY, radius);
}