#include "DxLib.h"
#include "../../Scene/SceneManager.h"
#include "../../Map/MapManager.h"
#include "../../Player/Player.h"
#include "../../Attack/AttackManager.h"
#include "../../Camera/Camera.h"
#include "../../Collision/Collsion.h"
#include "../../UI/UIImage.h"
#include "../../UI/UIText.h"


// 背景のスピード
#define BACK_GROUND_SPEED (-1.5f)

void InitPlayScene()
{
	// プレイヤー初期化
	InitPlayer();

	// マップ初期化
	InitMap();

	// カメラ初期化
	InitCamera();

	//攻撃初期化
	InitAllAttack();
}

void LoadPlayScene()
{
	// プレイヤーロード
	LoadPlayer();

	// マップをロード
	LoadMap();

	//攻撃ロード
	LoadAllAttack();
}

void StartPlayScene()
{
	// プレイヤー開始
	StartPlayer();

	// 各UI生成
	CreateUIImage(PLAY_FOOTR_FRAME, 0.0f, 775.0f);// フッター枠
	CreateUIImage(LIFE, 24.0f, 800.0f);			// 残機ハート
	CreateUIText(990.0f, 840.0f, "TARGET");					// ターゲット文字
	CreateUIImage(LIVELUP, 1140.0f, 800.0f);	// ターゲットエネミー画像

	// マップを開始
	StartMap();
}

void StepPlayScene()
{
	// プレイヤーステップ
	StepPlayer();

	//攻撃ステップ
	StepAllAttack();

	// カメラステップ
	StepCamera();

	// UIステップ
	StepUIImage();
	StepUIText();
}

void UpdatePlayScene()
{
	// マップ更新
	// プレイヤー更新
	UpdatePlayer();

	// 当たり判定
	//CheckCollision();

	//攻撃更新
	UpdateAllAttack();

	// UI更新
	UpdateUIImage();
	UpdateUIText();
}

void DrawPlayScene()
{
	// マップ描画
	DrawMap();

	// プレイヤー描画
	DrawPlayer();

	//攻撃描画
	DrawAllAttack();

	// カメラ描画
	DrawCamera();

	// UI描画
	DrawUIImage();
	DrawUIText();
}

void FinPlayScene()
{
	// マップ終了
	FinMap();

	// UIリセット
	ResetUIImage();
	ResetUIText();

	//攻撃終了
	FinAllAttack();

	// プレイヤー終了
	FinPlayer();
}
