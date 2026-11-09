#pragma once
#include "DxLib.h"

#define ATTACK_MAX (128)

struct AttackData
{
	int handle;
	int life;
	VECTOR pos;
	VECTOR move;
	float width;
	float height;
	float radius;
	bool active;
};

// 関数のプロトタイプ宣言
void InitAttack();
void LoadAttack();
void StartAttack();
void StepAttack();
void UpdateAttack();
void DrawAttack();
void FinAttack();
void DrawAttack();

//攻撃関数
void FireAttack(int life, float posX, float posY, float moveX, float moveY, float radius);

//攻撃取得
AttackData* GetAttack();