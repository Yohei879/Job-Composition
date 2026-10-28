#pragma once

// UIImageの種類
enum UIImageType
{
	// Playシーンで使う
	LIVELUP,
	LIFE,
	PLAY_FOOTR_FRAME,

	// 種類最大数
	UI_IMAGE_TYPE_MAX,
};

// UIImageのデータ
struct UIImageData
{
	bool active;
	int handle;
	float posX;
	float posY;
};

// 各ロジックごとの関数
void InitUIImage();
void LoadUIImage();
void StepUIImage();
void UpdateUIImage();
void DrawUIImage();
void FinUIImage();

// UIImageを生成する
void CreateUIImage(UIImageType type, float posX, float posY);

// 表示中のUIImageを未使用にする
// シーンの切り替え時などで使う
void ResetUIImage();
