#include "DxLib.h"
#include "../../Scene/SceneManager.h"
#include "../../Map/MapManager.h"
#include "../../Player/Player.h"
#include "../../Camera/Camera.h"
#include "../../Collision/Collsion.h"
#include "../../Player/PlayerAnimation.h"
#include "../../Enemy/EnemyManager.h"
#include "../../UI/UIImage.h"
#include "../../UI/UIText.h"


// 背景のスピード
#define BACK_GROUND_SPEED (-1.5f)

void InitPlayScene()
{
	// プレイヤー初期化
	InitPlayer();

	//プレイヤーアニメーション初期化
	InitPlayerAnimation();

	// マップ初期化
	InitMap();

	// カメラ初期化
	InitCamera();

	//アニメーション初期化
	InitAnimation();

	//エネミー初期化
	InitEnemy();
}

void LoadPlayScene()
{
	// プレイヤーロード
	LoadPlayer();

	//プレイヤーアニメーションロード
	LoadPlayerAnimation();

	// マップをロード
	LoadMap();

	//アニメーションロード
	LoadAnimation();

	//エネミーロード
	LoadEnemy();
}

void StartPlayScene()
{
	// プレイヤー開始
	StartPlayer();

	//エネミー開始
	StartEnemy();

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

	//プレイヤーアニメーションステップ
	StepPlayerAnimation();

	//エネミーステップ
	StepEnemy();
	
	// カメラステップ
	StepCamera();

	// UIステップ
	StepUIImage();
	StepUIText();

	//アニメーションステップ
	StepAnimation();
}

void UpdatePlayScene()
{
	// マップ更新
	// プレイヤー更新
	UpdatePlayer();

	//プレイヤーアニメーション更新
	UpdatePlayerAnimation();

	//エネミー更新
	UpdateEnemy();

	// 当たり判定
	CheckCollision();

	// UI更新
	UpdateUIImage();
	UpdateUIText();

	//アニメーション更新
	UpdateAnimation();
}

void DrawPlayScene()
{
	// マップ描画
	DrawMap();

	// プレイヤー描画
	DrawPlayer();

	//プレイヤーアニメーション描画
	DrawPlayerAnimation();

	//エネミー描画
	DrawEnemy();

	// カメラ描画
	DrawCamera();

	// UI描画
	DrawUIImage();
	DrawUIText();

	//アニメーション描画
	DrawAnimation();
}

void FinPlayScene()
{
	// マップ終了
	FinMap();

	// UIリセット
	ResetUIImage();
	ResetUIText();

	// プレイヤー終了
	FinPlayer();

	//エネミー終了
	FinEnemy();

	//プレイヤーアニメーション終了
	InitPlayerAnimation();

	//アニメーション終了
	FinAnimation();
}
