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
			if (CheckSquareSquare(body->pos.x, body->pos.y, body->width, body->height,
				                  block->pos.x, block->pos.y, block->width, block->height))
			{
				//左から当たったか
				if (body->move.x>0.0f)
				{
					//左に押し出す
					body->pos.x -= (body->pos.x + body->width) - block->pos.x;
				}

				//右から当たったか
				else if (body->move.x < 0.0f)
				{
					//右に押し出す
					body->pos.x += (block->pos.x + block->width) - body->pos.x;
				}
			}
			//移動量は0にする
			body->move.x = 0.0f;
		}
	}
	// Y軸だけ移動する
	body->pos.y += body->move.y;

	// マップチップと当たり判定＆押し出し
	for (int y = 0; y < MAP_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM; x++)
		{
			// マップチップ取得
			MapChipData mapChipData = GetMapChipData(x, y);
			// マップチップが0の場合は何もない
			if (mapChipData.mapChip == 0) continue;

			// ブロックを取り出して当たり判定
			BlockData* block = mapChipData.data;
			// 当たり判定
			if (CheckSquareSquare(body->pos.x, body->pos.y, body->width, body->height,
				block->pos.x, block->pos.y, block->width, block->height))
			{
				// 上からあたったか
				if (body->move.y > 0.0f)
				{
					// 上に押し出す
					body->pos.y -= (body->pos.y + body->width) - block->pos.y
						;

					// 空中フラグを折る
					body->isAir = false;
				}
				// 下からあたったか
				else if (body->move.y < 0.0f)
				{
					// 下に押し出す
					body->pos.y += (block->pos.y + block->width) - body->pos.y;

				}

				// 移動量は0にする
				body->move.y = 0.0f;
			}

		}
	}
}
