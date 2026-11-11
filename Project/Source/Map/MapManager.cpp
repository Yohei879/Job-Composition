#include "MapManager.h"
#include "MapParameter.h"
#include "MapChip.h"
#include "Block.h"
#include "../Collision/Collsion.h"
#include "../Player/Player.h"

// キャラクターの周囲何マスまでチェックするか
#define CHECK_ROUND_NUM (2)

void InitMap()
{
}

void LoadMap()
{
	LoadMapChipData();
	LoadBlock();
}

void StartMap()
{
	CreateMap();
}

void DrawMap()
{
	// ブロック描画
	DrawBlock();
}

void FinMap()
{
}

void MoveWithMapCollision(Body* body)
{
	//X軸だけ移動する
	body->pos.x += body->move.x;

	//マップチップと当たり判定&押し出し
	for (int y = 0; y < MAP_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM; x++)
		{
			//マップチップが0の場合は何もない
			MapChipData mapChipData = GetMapChipData(x, y);
			//マップが0の場合は何もない
			if (mapChipData.mapChip == 0)continue;

			//ブロックを取り出して当たり判定
			BlockData* block = mapChipData.data;
			//当たり判定
			if (CheckStartSoftSoundPlayer(body->pos.x,body->pos.y,body->width,body->height
											block->pos.x))
			{

			}

			
		}
	}

}
