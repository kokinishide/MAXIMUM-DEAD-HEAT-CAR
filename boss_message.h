//=============================================================================
//
// ボスのメッセージ表示処理 [boss_message.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _BOSS_MESSAGE_H_//このマクロ定義がされてなかったら
#define _BOSS_MESSAGE_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "object2D.h"
//ボスメッセージクラス
class CBoss_Message :public CObject2D
{
public:
	CBoss_Message(int nPriority = 1);
	~CBoss_Message()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CBoss_Message* Create(const D3DXVECTOR3& pos);//ボスメッセージ生成
	
private:
	int nCounterAnimBoss;//アニメーションカウンター
	int nPatternAnimBoss;//アニメーションパターンNo.
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//頂点バッファ
	LPDIRECT3DTEXTURE9 m_pTexture;//テクスチャ
};

#endif//_BOSS_MESSAGE_H_