#include "DxLib.h"
#include "Animation.h"

void InitAnimation(AnimationData* animData)
{
	animData->active = false;
	animData->handle = 0;
	animData->nowFrame = 0;
	animData->frameNum = 0;
	animData->frameWidth = 0;
	animData->frameHeight = 0;
	animData->timer = 0;
	animData->posX = 0.0f;
	animData->posY = 0.0f;
}

void UpdateAnimation(AnimationData* animData)
{
}

void DrawAnimation(AnimationData* animData, bool isTurnX, bool isTurnY)
{
}

void DrawAnimation(AnimationData* animData, float posX, float posY, bool isTurnX, bool isTurnY)
{
	if (!animData->active)return;

	// コマの切り取り位置計算（横１行の画像の想定）
	int frameX = animData->frameWidth * animData->nowFrame;

	// 画像から表示するコマの部分だけ描画
	DrawRectGraph((int)posX, (int)posY, frameX, 0, animData->frameWidth, animData->frameHeight, animData->handle, TRUE, isTurnX, isTurnY);
}


void StartAnimation(AnimationData* animData, float posX, float posY, int interval, int frameNum, int width, int height, bool isLoop)
{
	// アクティブ
	animData->active = true;

	// 座標設定
	animData->posX = posX;
	animData->posY = posY;

	// インターバル設定
	animData->interval = interval;

	// タイマー設定
	animData->timer = animData->interval;

	// 0コマ目にする
	animData->nowFrame = 0;

	// コマ数
	animData->frameNum = frameNum;

	// 1コマのサイズ
	animData->frameWidth = width;
	animData->frameHeight = height;

	// ループするか
	animData->isLoop = isLoop;
}
