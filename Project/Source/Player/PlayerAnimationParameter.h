#pragma once

//アニメーションの種類
enum PlayerAnimationType
{
	PLAYER_LEFT,
	PLAYER_KINOKEN,
	PLAYER_ANIMATION_TYPE_MAX,
};

//	エフェクトの種類毎のマスターパラメータ
//画像の大きさコマ数など
struct PlayerAnimationMasterParameter
{
	int frameNum;		//フレーム数
	int frameWidth;		//1コマの横幅
	int frameHeight;	//1コマの縦幅
};

const PlayerAnimationMasterParameter PLAYER_ANIMATION_MASTER_PARAM[PLAYER_ANIMATION_TYPE_MAX] =
{
	1, 100, 100,    //PLAYER_LEFT
	3, 400, 400,    //PLAYER_KINOKEN
};