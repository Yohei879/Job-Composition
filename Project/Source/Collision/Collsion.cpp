#include"DxLib.h"
#include "Collsion.h"
#include "../Enemy/EnemySlime.h"
#include "../Map/Block.h"
#include "../Map//MapManager.h"
#include "../Map/MapParameter.h"
#include "../Player/Player.h"
#include "../Player/PlayerAnimation.h"
#include <math.h>

bool CheckSquareSquare(float squareA_PosX, float squareA_PosY, float squareA_Width, float squareA_Height, float squareB_PosX, float squareB_PosY, float squareB_Width, float squareB_Height)
{
	// 矩形Aの各辺の位置を計算する
	float leftA = squareA_PosX;
	float rightA = squareA_PosX + squareA_Width;
	float topA = squareA_PosY;
	float bottomA = squareA_PosY + squareA_Height;

	// 矩形Bの各辺の位置を計算する
	float leftB = squareB_PosX;
	float rightB = squareB_PosX + squareB_Width;
	float topB = squareB_PosY;
	float bottomB = squareB_PosY + squareB_Height;

	// 左右の辺がめり込んでいるかチェック
	if (rightA > leftB && leftA < rightB)
	{
		// 上下の片がめり込んでいるかチェック
		if (bottomA > topB && topA < bottomB)
		{
			//当たっている
			return  true;
		}
	}
	return false;
}

bool CheckCircleCircle(float circleA_PosX, float circleA_PosY, float circleA_Radius, float circleB_PosX, float circleB_PosY, float circleB_Radius)
{
	// 円の中心間の距離を計算する
	float distance = sqrtf((circleB_PosX - circleA_PosX) * (circleB_PosX - circleA_PosX) + (circleB_PosY - circleA_PosY) * (circleB_PosY - circleA_PosY));

	// 中心間の距離が2つの円の半径の合計以下であれば当たっている
	if (distance <= (circleA_Radius + circleB_Radius))
	{
		return true;
	}

	return false;
}

void CheckPlayerSlime()
{
	// プレイヤーとSlimeの当たり判定
	PlayerData player = GetPlayer();

	EnemyData* enemy = GetSlime();

	// プレイヤーが生きていて無敵でない時だけ判定する
	if (player.active && !player.invisible)
	{
		// プレイヤーの中心座標
		float playerCenterX = player.body.pos.x + PLAYER_WIDTH / 2;
		float playerCenterY = player.body.pos.y + PLAYER_HEIGHT / 2;

		for (int i = 0; i < ENEMY_MAX; i++, enemy++)
		{
			// 死んでいたら判定しない
			if (!enemy->active) continue;

			// Slimeの中心座標
			float enemyCenterX = enemy->body.pos.x + enemy->body.width / 2;
			float enemyCenterY = enemy->body.pos.y + enemy->body.height / 2;

			// 円で当たり判定をとる
			if (CheckCircleCircle(playerCenterX, playerCenterY, PLAYER_RADIUS / 2,
				enemyCenterX, enemyCenterY, ENEMY_SLIME_RADIUS))
			{
				PlayerHitEnemy();
				SlimeHitPlayer(i);
			}
		}
	}

}

void CheckCollision()
{
	//PlayerとSlimeの当たり判定
	CheckPlayerSlime();
}
