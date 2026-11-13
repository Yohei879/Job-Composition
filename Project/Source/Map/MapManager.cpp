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
			//マップチップが取得
			MapChipData mapChipData = GetMapChipData(x, y);
			//マップが0の場合は何もない
			if (mapChipData.mapChip == 0)continue;

			if (mapChipData.data->type == FLOOR)continue;

			float cx, cy, cw, ch, ox, oy;
			CalcCollision(body, cx, cy, cw, ch, ox, oy);

			//ブロックを取り出して当たり判定
			BlockData* block = mapChipData.data;
			//当たり判定
			if (CheckSquareSquare(cx, cy, cw, ch,
				block->pos.x, block->pos.y, block->width, block->height))
			{
				//左から当たったか
				if (body->move.x > 0.0f)
				{
					//左に押し出す
					body->pos.x -= (body->pos.x + cw) - block->pos.x + ox;
				}

				//右から当たったか
				else if (body->move.x < 0.0f)
				{
					//右に押し出す
					body->pos.x += (block->pos.x + block->width) - body->pos.x - ox;
				}
				//移動量は0にする
				body->move.x = 0.0f;
			}
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

			if (mapChipData.data->type == FLOOR)continue;

			float cx, cy, cw, ch, ox, oy;
			CalcCollision(body, cx, cy, cw, ch, ox, oy);

			// ブロックを取り出して当たり判定
			BlockData* block = mapChipData.data;
			// 当たり判定
			if (CheckSquareSquare(cx, cy, cw, ch,
				block->pos.x, block->pos.y, block->width, block->height))
			{
				// 上からあたったか
				if (body->move.y > 0.0f)
				{
					// 上に押し出す
					body->pos.y -= (body->pos.y + ch) - block->pos.y + oy;

					// 空中フラグを折る
					body->isAir = false;
				}
				// 下からあたったか
				else if (body->move.y < 0.0f)
				{
					// 下に押し出す
					body->pos.y += (block->pos.y + block->height) - body->pos.y - oy;
				}
				// 移動量は0にする
				body->move.y = 0.0f;
			}
		}
	}
}

void CalcCollision(Body* body, float& x, float& y, float& w, float& h, float& offsetX, float& offsetY)
{
	float centerX = body->pos.x + body->width / 2;
	float centerY = body->pos.y + body->height / 2;

	x = centerX - body->collisionWidth / 2;
	y = centerY - body->collisionHeight / 2;
	w = body->collisionWidth;
	h = body->collisionHeight;
	offsetX = x - body->pos.x;
	offsetY = y - body->pos.y;
}
