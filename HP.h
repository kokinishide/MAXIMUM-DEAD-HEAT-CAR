//=============================================================================
//
// HP文字表示処理 [HP.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _HP_H_//このマクロ定義がされてなかったら
#define _HP_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "object2D.h"
//HP文字クラス
class CHP :public CObject2D
{
public:
	CHP(int nPriority = 1);
	~CHP()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CHP* Create(const D3DXVECTOR3& pos);//HP文字生成
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//頂点バッファ
	LPDIRECT3DTEXTURE9 m_pTexture;//テクスチャ
};

#endif// _HP_H_