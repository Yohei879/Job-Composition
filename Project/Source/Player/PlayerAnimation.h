#pragma once
#include "PlayerAnimationParameter.h"
#include"DxLib.h"

//画面に表示できるエフェクトの最大数
#define PLAYER_ANIMATION_MAX 1

//エフェクトデータ
struct PlayerAnimationData
{
	bool active;
	bool isLoop;
	int handle;
	int nowFrame;
	int frameNum;
	int frameWidth;
	int frameHeight;
	int timer;
	int interval;
	VECTOR pos;
};

//各関数の宣言
void InitPlayerAnimation();
void LoadPlayerAnimation();
void StepPlayerAnimation();
void UpdatePlayerAnimation();
void DrawPlayerAnimation();
void FinPlayerAnimation();

//アニメーション開始
void PlayPlayerAnimation(PlayerAnimationType type, int interval, bool isLoop);