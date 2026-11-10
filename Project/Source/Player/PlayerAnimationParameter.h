#pragma once

//アニメーションの種類
enum PlayerAnimationType
{
	PLAYER_WALK_UP,
	PLAYER_WALK_LEFT,
	PLAYER_WALK_RIGHT,
	PLAYER_WALK_DOWN,

	PLAYER_KINOKEN_UP,
	PLAYER_KINOKEN_LEFT,
	PLAYER_KINOKEN_RIGHT,
	PLAYER_KINOKEN_DOWN,
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
	1, 100, 100,    //PLAYER_WAIT_UP,
	1, 100, 100,    //PLAYER_WAIT_LEFT,
	1, 100, 100,    //PLAYER_WAIT_RIGHT,
	1, 100, 100,    //PLAYER_WAIT_DOWN,
	3, 400, 400,    //PLAYER_KINOKEN_UP,
	3, 400, 400,	//PLAYER_KINOKEN_LEFT,
	3, 400, 400,	//PLAYER_KINOKEN_RIGHT,
	3, 400, 400,	//PLAYER_KINOKEN_DOWN,
};