//=============================================================================
//
// 真ん中通路のメッセージ表示処理 [middle_message.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _MIDDLE_MESSAGE_H_//このマクロ定義がされてなかったら
#define _MIDDLE_MESSAGE_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "object2D.h"
//真ん中メッセージクラス
class CMiddle_Message :public CObject2D
{
public:
	CMiddle_Message(int nPriority = 1);
	~CMiddle_Message()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CMiddle_Message* Create(const D3DXVECTOR3& pos);//真ん中メッセージ生成
	int nCounterAnimJump;//アニメーションカウンター
	int nPatternAnimJump;//アニメーションパターンNo.
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//頂点バッファ
	LPDIRECT3DTEXTURE9 m_pTexture;//テクスチャ
};

#endif//_MIDDLE_MESSAGE_H_