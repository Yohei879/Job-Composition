#include "DxLib.h"
#include "PlayerAnimation.h"
#include "PlayerAnimationParameter.h"
#include "Player.h"
#include "../Camera/Camera.h"

//アニメーションエフェクトデータ
PlayerAnimationData g_AnimationData[PLAYER_ANIMATION_MAX] = { 0 };

//エフェクト初期化
int g_PlayerAnimationHandle[PLAYER_ANIMATION_TYPE_MAX];

PlayerAnimationType current;

//エフェクト初期化
void InitPlayerAnimation()
{
	PlayerAnimationData* animation = g_AnimationData;
	for (int i = 0; i < PLAYER_ANIMATION_MAX; i++, animation++)
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

void LoadPlayerAnimation()
{
	g_PlayerAnimationHandle[PLAYER_WALK_UP] = LoadGraph("Data/Player/PlayerUp.png");
	g_PlayerAnimationHandle[PLAYER_WALK_DOWN] = LoadGraph("Data/Player/PlayerDown.png");
	g_PlayerAnimationHandle[PLAYER_WALK_LEFT] = LoadGraph("Data/Player/PlayerLeft.png");
	g_PlayerAnimationHandle[PLAYER_WALK_RIGHT] = LoadGraph("Data/Player/PlayerRight.png");
	g_PlayerAnimationHandle[PLAYER_KINOKEN_UP] = LoadGraph("Data/Player/PalyerMo-syonUp.png");
	g_PlayerAnimationHandle[PLAYER_KINOKEN_LEFT] = LoadGraph("Data/Player/PlayerMo-syonLeft.png");
	g_PlayerAnimationHandle[PLAYER_KINOKEN_RIGHT] = LoadGraph("Data/Player/PlayerMo-syonRight.png");
	g_PlayerAnimationHandle[PLAYER_KINOKEN_DOWN] = LoadGraph("Data/Player/PlayerMo-syonDown.png");

	
}

void StepPlayerAnimation()
{
	PlayerAnimationData* animation = g_AnimationData;
	for (int i = 0; i < PLAYER_ANIMATION_MAX; i++,animation)
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
					PlayerAnimationEnd(current);
					continue;
				}
			}
		}
		animation->timer--;
	}
}

void UpdatePlayerAnimation()
{
}

void DrawPlayerAnimation()
{
	PlayerData player = GetPlayer();
	PlayerAnimationData* animation = g_AnimationData;
	CameraData camera = GetCamera();

	for (int i = 0; i < PLAYER_ANIMATION_MAX; i++,animation++)
	{
		//
		if (!animation->active)continue;
		
		//1コマ分の横幅(animation->frameWidth)と
		//現在のコマ数(animation->nowFrame)から、
		//切り取る部分を計算する　

		int srcX = animation->nowFrame * animation->frameWidth;
		int srcY = 0.0f;

		//DrawRectGraph関数で描画すべきコマの部分で描画する
		DrawRectGraph((int)player.body.pos.x, (int)player.body.pos.y, srcX, srcY, animation->frameWidth, animation->frameHeight, animation->handle, TRUE);
	}
}

void FinPlayerAnimation()
{
	for (int i = 0; i < PLAYER_ANIMATION_TYPE_MAX; i++)
	{
		DeleteGraph(g_PlayerAnimationHandle[i]);
	}
}

//アニメーション再生
void PlayPlayerAnimation(PlayerAnimationType type, int interval, bool isLoop)
{
	 current = type;
	//
	PlayerAnimationMasterParameter param = PLAYER_ANIMATION_MASTER_PARAM[type];

	PlayerAnimationData* animation = g_AnimationData;
	for (int i = 0; i < PLAYER_ANIMATION_MAX; i++, animation++)
	{
		// アクティブ
		animation->active = true;

		// ループ
		animation->isLoop = isLoop;

		// 座標設定
		//animation->pos.x = posX;
		//animation->pos.y = posY;

		// インターバル設定
		animation->interval = interval;

		// タイマー設定
		animation->timer = animation->interval;

		// 画像ハンドル
		animation->handle = g_PlayerAnimationHandle[type];

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


