//=============================================================================
//
// 左のメッセージ表示処理 [left_message.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _LEFT_MESSAGE_H_//このマクロ定義がされてなかったら
#define _LEFT_MESSAGE_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "object2D.h"
//左のメッセージクラス
class CLeft_Message :public CObject2D
{
public:
	CLeft_Message(int nPriority = 1);
	~CLeft_Message()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CLeft_Message* Create(const D3DXVECTOR3& pos);//左のメッセージ生成
	int nCounterAnimLeft;//アニメーションカウンター
	int nPatternAnimLeft;//アニメーションパターンNo.
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//頂点バッファ
	LPDIRECT3DTEXTURE9 m_pTexture;//テクスチャ
};

#endif//_LEFT_MESSAGE_H_