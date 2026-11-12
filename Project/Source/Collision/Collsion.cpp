#include "Collsion.h"

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
