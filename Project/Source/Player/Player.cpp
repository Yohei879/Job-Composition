#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Collision/Collsion.h"
#include "../Camera/Camera.h"
#include "../Effect/AnimationEffect.h"
#include "../Scene/SceneManager.h"
#include "../Sound/SoundManager.h"

// アニメーション用パラメータ
struct PlayerAnimationParam
{
	int interval;
	int frameNum;
	int width;
	int height;
};

// 残機表示の文字列
#define PLAYER_LIFE_STRING ("x%02d")

// プレイヤー設定関連
#define PLAYER_DEFAULT_POS_X (200.0f)
#define PLAYER_DEFAULT_POS_Y (250.0f)
#define PLAYER_MOVE_SPEED (3.0f)
#define PLAYER_NORMAL_SHOT_INTERVAL (5)

// 移動可能エリア
#define PLAYER_MOVE_AREA_LEFT (0.0f)
#define PLAYER_MOVE_AREA_RIGHT (1536.0f)
#define PLAYER_MOVE_AREA_TOP (0.0f)
#define PLAYER_MOVE_AREA_BOTTOM (743.0f)

// プレイヤーの残機
#define PLAYER_DEFAULT_LIFE (2)

// リスポーンまでの待機時間
#define PLAYER_RESPAWN_WAIT (180)

// リスポーン時の無敵時間
#define PLAYER_RESPAWN_INVISIBLE_TIME (180)

PlayerData g_PlayerData = { 0 };

void InitPlayer()
{
	g_PlayerData.life = 0;
	g_PlayerData.pos.x = PLAYER_DEFAULT_POS_X;
	g_PlayerData.pos.y = PLAYER_DEFAULT_POS_Y;
	g_PlayerData.move.x = 0.0f;
	g_PlayerData.move.y = 0.0f;

	g_PlayerData.respawnTimer = 0;
	g_PlayerData.active = false;
	g_PlayerData.invisible = false;
	g_PlayerData.lifeText = nullptr;
}


void LoadPlayer()
{
	g_PlayerData.handle = LoadGraph("Data/Player/Player.png");
}

void StartPlayer()
{
	// 生存フラグを立てる
	g_PlayerData.active = true;

	// 残機の初期値設定
	g_PlayerData.life = PLAYER_DEFAULT_LIFE;

	// 残機のUI生成
	char text[256];
	sprintf_s(text, PLAYER_LIFE_STRING, g_PlayerData.life);
	g_PlayerData.lifeText = CreateUIText(60.0f, 795.0f, text);
}

void StepPlayer()
{
	// 死んでいたら専用処理
	if (!g_PlayerData.active)
	{
		// 待機時間が過ぎたらリスポーン
		if (g_PlayerData.respawnTimer <= 0)
		{
			bool isSuccessRespawn = RespawnPlayer();
			// リスポーンできなかったらゲームオーバー
			if (!isSuccessRespawn)
			{
				ChangeScene(SCENE_GAME_OVER);
			}
		}
		g_PlayerData.respawnTimer--;

		return;
	}
	// 移動量は毎回リセットする
	g_PlayerData.move.x = 0.0f;
	g_PlayerData.move.y = 0.0f;

	// 上入力
	if (IsInputKey(KEY_UP))
	{
		g_PlayerData.move.y = -PLAYER_MOVE_SPEED;
	}
	// 下入力
	if (IsInputKey(KEY_DOWN))
	{
		g_PlayerData.move.y = PLAYER_MOVE_SPEED;
	}
	// 左入力
	if (IsInputKey(KEY_LEFT))
	{
		g_PlayerData.move.x = -PLAYER_MOVE_SPEED;
	}
	// 右入力
	if (IsInputKey(KEY_RIGHT))
	{
		g_PlayerData.move.x = PLAYER_MOVE_SPEED;
	}

	
}

void UpdatePlayer()
{
	// 死んでいたら処理しない
	if (!g_PlayerData.active) return;

	// 移動処理
	g_PlayerData.pos.x += g_PlayerData.move.x;
	g_PlayerData.pos.y += g_PlayerData.move.y;

	// 画面外に出ないように移動制限
	if (g_PlayerData.pos.x < PLAYER_MOVE_AREA_LEFT) g_PlayerData.pos.x = PLAYER_MOVE_AREA_LEFT;
	if (g_PlayerData.pos.x > PLAYER_MOVE_AREA_RIGHT) g_PlayerData.pos.x = PLAYER_MOVE_AREA_RIGHT;
	if (g_PlayerData.pos.y < PLAYER_MOVE_AREA_TOP) g_PlayerData.pos.y = PLAYER_MOVE_AREA_TOP;
	if (g_PlayerData.pos.y > PLAYER_MOVE_AREA_BOTTOM) g_PlayerData.pos.y = PLAYER_MOVE_AREA_BOTTOM;

	

	// 無敵中の処理
	if (g_PlayerData.invisible)
	{
		g_PlayerData.invisibleTimer--;
	}

	// 無敵解除チェック
	if (g_PlayerData.invisible && g_PlayerData.invisibleTimer <= 0)
	{
		g_PlayerData.invisible = false;
	}
}

void DrawPlayer()
{
	// 死んでいたら処理しない
	if (!g_PlayerData.active) return;

	//カメラ取得
	CameraData camera = GetCamera();

	g_PlayerData.pos.x - camera.pos.x, g_PlayerData.pos.x - camera.pos.y;
	DrawGraph(
		(int)(g_PlayerData.pos.x - camera.pos.x),
		(int)(g_PlayerData.pos.y - camera.pos.y),
		g_PlayerData.handle,
		TRUE
	);

	{
		// 通常描画
		DrawGraph((int)g_PlayerData.pos.x, (int)g_PlayerData.pos.y, g_PlayerData.handle, TRUE);


	}
}

void FinPlayer()
{
	DeleteGraph(g_PlayerData.handle);
}

PlayerData* GetPlayer()
{
	return &g_PlayerData;
}

// リスポーン処理(リスポーンできなかったらfalseを返す)
bool RespawnPlayer()
{
	// 残機チェック
	if (g_PlayerData.life > 0)
	{
		// アクティブ
		g_PlayerData.active = true;

		// 無敵状態
		g_PlayerData.invisible = true;
		g_PlayerData.invisibleTimer = PLAYER_RESPAWN_INVISIBLE_TIME;

		// 初期位置に配置
		g_PlayerData.pos.x = PLAYER_DEFAULT_POS_X;
		g_PlayerData.pos.y = PLAYER_DEFAULT_POS_Y;

		// 残機を減らす
		g_PlayerData.life--;

		// 残機UI更新
		char text[256];
		sprintf_s(text, PLAYER_LIFE_STRING, g_PlayerData.life);
		SetUIText(g_PlayerData.lifeText, text);

		// リスポーン成功
		return true;
	}

	// リスポーン不可
	return false;
}

void PlayerDead()
{
	// 死亡
	g_PlayerData.active = false;

	// リスポーン待機開始
	g_PlayerData.respawnTimer = PLAYER_RESPAWN_WAIT;
}
