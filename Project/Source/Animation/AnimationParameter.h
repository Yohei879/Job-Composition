#pragma once

//アニメーションの種類
enum AnimationType
{
	KINOKEN,
	ANIMATION_TYPE_MAX,
};

//	エフェクトの種類毎のマスターパラメータ
//画像の大きさコマ数など
struct AnimationMasterParameter
{
	int frameNum;		//フレーム数
	int frameWidth;		//1コマの横幅
	int frameHeight;	//1コマの縦幅
};

const AnimationMasterParameter ANIMATION_MASTER_PARAM[ANIMATION_TYPE_MAX] =
{
	12, 16, 16,		//KINOKEN
};