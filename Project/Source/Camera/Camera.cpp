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

	int size = 23.5 * 23.5;//マップの1区画
	int xRange = (int)player.body.pos.x / size;	
	int yRange = (int)player.body.pos.y / size;	
	
	//カメラ取得
	CameraData* camera = GetCamera();

	camera->pos.x = xRange * size-(800-25*25/2);
	camera->pos.y = yRange * size-(450 - 25 * 25 / 2);
}

void DrawCamera()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "カメラの座標＝[%f, %f]", g_CameraData.pos.x, g_CameraData.pos.y);
}

CameraData* GetCamera()
{
	return &g_CameraData;
}

