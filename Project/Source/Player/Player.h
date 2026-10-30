#pragma once
#include "../UI/UIText.h"
#include "../Animation/Animation.h"




struct PlayerData
{
	bool active;				//生存フラグ
	bool invisible;				//無敵フラグ
	int handle;					//画像ハンドル
	int respawnTimer;			// リスポーン待機タイマー
	int invisibleTimer;			// 無敵時間タイマー
	int life;					// 残機数
	VECTOR pos;					//座標
	VECTOR move;				//
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