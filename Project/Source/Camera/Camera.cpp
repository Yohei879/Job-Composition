#include "DxLib.h"
#include "Camera.h"
#include "../Input/Input.h"
#include "../Player/Player.h"

#define DEBUG_CAMERA_SPEED (10.0f)
#define CAMERA_SCROLL_START_X (300.0f)

CameraData g_CameraData = { 0 };

void InitCamera()
{
	g_CameraData.pos.z = 1.0f;
}

void StepCamera()
{
	//プレイヤー取得
	PlayerData player = GetPlayer();

	//g_CameraData.pos.x = player.body.pos.x - 800;
	//g_CameraData.pos.y = player.body.pos.y - 450;

	int size = 24 * 24;
	int xRange = (int)player.body.pos.x / size;	//マップの1区画
	int yRange = (int)player.body.pos.y / size;	//マップの1区画
	
	//カメラ取得
	CameraData* camera = GetCamera();

	camera->pos.x = xRange * size;
	camera->pos.y = yRange * size;
}

void DrawCamera()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "カメラの座標＝[%f, %f]", g_CameraData.pos.x, g_CameraData.pos.y);
}

CameraData* GetCamera()
{
	return &g_CameraData;
}

