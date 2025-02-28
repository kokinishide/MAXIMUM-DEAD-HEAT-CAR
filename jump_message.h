//=============================================================================
//
// ジャンプのメッセージ表示処理 [jump_message.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _JUMP_MESSAGE_H_//このマクロ定義がされてなかったら
#define _JUMP_MESSAGE_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "object2D.h"
//ジャンプメッセージクラス
class CJump_Message :public CObject2D
{
public:
	CJump_Message(int nPriority = 1);
	~CJump_Message()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CJump_Message* Create(const D3DXVECTOR3& pos);//ジャンプメッセージ生成
	int nCounterAnimJump;//アニメーションカウンター
	int nPatternAnimJump;//アニメーションパターンNo.
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//頂点バッファ
	LPDIRECT3DTEXTURE9 m_pTexture;//テクスチャ
};

#endif//_JUMP_MESSAGE_H_