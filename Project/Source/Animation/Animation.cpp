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
		animation->isLoop = false;
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
	g_AnimationHandle[PLAYER] = LoadGraph("Data/Player/PlayerMo-syon.png");
	g_AnimationHandle[KINOKEN] = LoadGraph("Data/Player/PlayerMo-syon.png");
}

void StepAnimation()
{
	AnimationData* animation = g_AnimationData;
	for (int i = 0; i < ANIMATION_MAX; i++,animation)
	{
		if (!animation->active)continue;

		if (animation->timer <= 0)
		{
			animation->timer = animation->interval;
			animation->nowFrame++;

			if (animation->nowFrame>=animation->frameNum)
			{
				if (animation->isLoop == true)
				{
					animation->nowFrame = 0;
				}
				else
				{
					animation->active = false;
					continue;
				}
			}
		}
		animation->timer--;
	}
}

void UpdateAnimation()
{
}

void DrawAnimation()
{
	AnimationData* animation = g_AnimationData;
	for (int i = 0; i < ANIMATION_MAX; i++,animation++)
	{
		//
		if (!animation->active)continue;
		
		//1コマ分の横幅(animation->frameWidth)と
		//現在のコマ数(animation->nowFrame)から、
		//切り取る部分を計算する　

		int srcX = animation->nowFrame * animation->frameWidth;
		int srcY = 0.0f;

		//DrawRectGraph関数で描画すべきコマの部分で描画する
		DrawRectGraph((int)animation->pos.x, (int)animation->pos.y, srcX, srcY, animation->frameWidth, animation->frameHeight, animation->handle, TRUE);
	}
}

void FinAnimation()
{
	for (int i = 0; i < ANIMATION_TYPE_MAX; i++)
	{
		DeleteGraph(g_AnimationHandle[i]);
	}
}

//アニメーション再生
void PlayAnimation(AnimationType type, float posX, float posY, int interval, bool isLoop)
{
	//
	AnimationMasterParameter param = ANIMATION_MASTER_PARAM[type];

	AnimationData* animation = g_AnimationData;
	for (int i = 0; i < ANIMATION_MAX; i++, animation++)
	{
		//
		if (!animation->active)
		{
			// アクティブ
			animation->active = true;

			// ループ
			animation->isLoop = isLoop;

			// 座標設定
			animation->pos.x = posX;
			animation->pos.y = posY;

			// インターバル設定
			animation->interval = interval;

			// タイマー設定
			animation->timer = animation->interval;

			// 画像ハンドル
			animation->handle = g_AnimationHandle[type];

			// 0コマ目にする
			animation->nowFrame = 0;

			// コマ数
			animation->frameNum = param.frameNum;

			// 1コマのサイズ
			animation->frameWidth = param.frameWidth;
			animation->frameHeight = param.frameHeight;

			break;
		}
	}
}


