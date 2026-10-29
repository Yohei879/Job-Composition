#pragma once
#include "../UI/UIText.h"
#include "../Animation/Animation.h"

// アニメーションタイプ
enum PlayerAnimationType
{
	ANIME_UP,
	ANIME_DOWN,
	ANIME_LEFT,
	ANIME_RIGHT,
	ANIME_IDLE,
	ANIME_MAX,
	ANIME_NONE = -1
};

struct PlayerData
{
	bool active;				//生存フラグ
	bool invisible;				//無敵フラグ
	int handle;					//画像ハンドル
	int respawnTimer;			// リスポーン待機タイマー
	int invisibleTimer;			// 無敵時間タイマー
	int life;					// 残機数
	float posX;					// X座標
	float posY;					// Y座標
	float moveX;				// X移動量
	float moveY;				// Y移動量
	AnimationData animation[ANIME_MAX];	// アニメーション
	PlayerAnimationType playAnim;				// 再生中のアニメーション
	UITextData* lifeText;		//残機UIText
};

// 関数のプロトタイプ宣言
void InitPlayer();
void LoadPlayer();
void StartPlayer();
void StepPlayer();
void UpdatePlayer();
void DrawPlayer();
void FinPlayer();
void DrawPlayer();

// 取得関数
PlayerData* GetPlayer();

// リスポーン処理(リスポーンできなかったらfalseを返す)
bool RespawnPlayer();

