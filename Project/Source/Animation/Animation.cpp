#include "DxLib.h"
#include "Animation.h"
#include "AnimationParameter.h"

//アニメーションエフェクトデータ
AnimationData g_AnimationData[ANIMATION_MAX] = { 0 };

//エフェクト初期化
int g_AnimationHandle[ANIMATION_TYPE_MAX];

//エフェクト初期化
void InitAnimation()
{
	AnimationData* animation = g_AnimationData;
	for (int i = 0; i < ANIMATION_MAX; i++, animation++)
	{
		animation->active = false;
		animation->handle = 0;
		animation->nowFrame = 0;
		animation->frameNum = 0;
		animation->frameWidth = 0;
		animation->frameHeight = 0;
		animation->timer = 0;
		animation->pos.x = 0.0f;
		animation->pos.y = 0.0f;
	}
}

void LoadAnimation()
{
	g_AnimationHandle[]
}

void StepAnimation()
{
}

void UpdateAnimation()
{
}

void DrawAnimation()
{
}

void FinAnimation()
{
}
