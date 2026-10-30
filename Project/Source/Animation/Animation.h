#pragma once

// エフェクトの種類
enum AnimationEffectType
{
	ANIMATION_EFFECT_TYPE_MAX,
	WALK_UP,
	WALK_RIGHT,
	WALK_LEFT,
	WALK_DOWN
};
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
	float posX;
	float posY;
};

void InitAnimation(AnimationData* animData);
void UpdateAnimation(AnimationData* animData);
void DrawAnimation(AnimationData* animData, bool isTurnX = false, bool isTurnY = false);
void DrawAnimation(AnimationData* animData, float posX, float posY, bool isTurnX = false, bool isTurnY = false);
void StartAnimation(AnimationData* animData, float posX, float posY, int interval, int frameNum, int width, int height, bool isLoop);
