//=============================================================================
//
// ブロック処理 [block.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _BLOCK_H_//このマクロ定義がされてなかったら
#define _BLOCK_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "object3D.h"

//マクロ定義
#define MAX_BLOCK (128) //敵の最大数

//ブロックの状態
typedef enum
{
	BLOCKSTATE_NORMAL = 0, //通常状態
	BLOCKSTATE_DAMAGE, //ダメージ状態
	BLOCKSTATE_MAX

}BLOCKSTATE;

//ブロック
class CBlock :public CObject3D
{
public:
	CBlock();//コンストラクタ
	virtual~CBlock()override;//デストラクタ
	virtual HRESULT Init()override;//初期設定
	virtual void Uninit()override;//終了処理
	virtual void Update()override;//更新処理
	virtual void Draw()override;//描画処理
	virtual void Hit(int nDamage)override;//ヒット処理
	static CBlock* Create(const D3DXVECTOR3& pos);//生成処理
	HRESULT Load(); //Textureロード
	void Unload();//Textureアンロード
};


#endif //_BLOCK_H_


