#pragma once
#include "AnimationParameter.h"
#include"DxLib.h"

//画面に表示できるエフェクトの最大数
#define ANIMATION_MAX 255

//エフェクトデータ
struct AnimationData
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
void InitAnimation();
void LoadAnimation();
void StepAnimation();
void UpdateAnimation();
void DrawAnimation();
void FinAnimation();

//アニメーション開始
void PlayAnimation(AnimationType type, float posX, float posY, int interval, bool isLoop);