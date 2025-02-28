//=============================================================================
//
// 背景処理 [bg.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _BG_H_//このマクロ定義がされてなかったら
#define	_BG_H_//2重インクルード防止のマクロ定義
#include "object.h"

class CBG :public CObject
{
public:
	CBG(int nPriority = 1);
	~CBG()override;
	 HRESULT Init()override;
	 void Uninit()override;
	 void Update()override;
	 void Draw()override;
	//void BindTexture(LPDIRECT3DTEXTURE9 pTex);//テクスチャ割当
	//D3DXVECTOR3 m_pos; //現在の位置
	//D3DXVECTOR3& GetPos() { return m_pos; }//位置取得など用意
	//D3DXVECTOR3& SetPos(D3DXVECTOR3 pos); //位置取得など用意
	static CBG* Create();//BG生成
	int nCounterAnimBG;//アニメーションカウンター
	int nPatternAnimBG;//アニメーションパターンNo.
private:
	/*static CObject2D* m_pObject2D;*/
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//頂点バッファ
	LPDIRECT3DTEXTURE9 m_pTexture;//テクスチャ
};

#endif //_BG_H_

