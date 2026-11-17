#pragma once
#include "../Map/MapParameter.h"
#include "../Map/MapChip.h"
#include "../Collision/CollsionParameter.h"

void InitSlime();
void StartSlime();
void StepSlime();
void LoadSlime();
void UpdateSlime();
void DrawSlime();
void FinSlime();

//SlimesŽæ“¾
BlockData Slime();

//“–‚½‚è”»’èŠÖ˜A
void SlimeHitPlayer(int index);
