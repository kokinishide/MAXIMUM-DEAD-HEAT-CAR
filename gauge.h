//=============================================================================
//
// ゲージ表示処理 [gauge.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _GAUGE_H_//このマクロ定義がされてなかったら
#define _GAUGE_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "object2D.h"
//ゲージクラス
class CGauge :public CObject2D
{
public:
	CGauge(int nPriority = 1);
	~CGauge()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CGauge* Create(const D3DXVECTOR3& pos);//ゲージ生成
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//頂点バッファ
	LPDIRECT3DTEXTURE9 m_pTexture;//テクスチャ
};

#endif// _GAUGE_H_