//=============================================================================
//
// オブジェクト2D処理 [object2D.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _OBJECT2D_H_//このマクロ定義がされてなかったら
#define _OBJECT2D_H_//2重インクルード防止のマクロ定義

#include"object.h"

//2Dポリゴン管理クラス
class CObject2D :public CObject
{
public:

	CObject2D();
	CObject2D(int nPriority);
	virtual ~CObject2D()override;//object.hにvirtualがなければ、overrideを消す。
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	void BindTexture(LPDIRECT3DTEXTURE9 pTex);//テクスチャ割当
	void SetPos(D3DXVECTOR3 pos); //位置を設定
	void SetMove(D3DXVECTOR3 move); //動きを設定
	void SetRot(D3DXVECTOR3 rot); //向きを設定
	void SetCol(D3DXCOLOR col) { m_col = col; }//カラーを設定
	void SetColA(float fAlpha) { m_col.a = fAlpha; }
	static CObject2D* Create();//Object2D生成
	D3DXVECTOR3 GetPos() { return m_pos; }//位置取得など用意
	D3DXVECTOR3 GetMove() { return m_move; }//動き取得など用意
	void SetPosX(float x);
	void SetPosY(float y);
	void SetSizeW(float w);
	void SetSizeH(float h);
	int nCounterAnim;//アニメーションカウンター
	int nPatternAnim;//アニメーションパターンNo.

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//頂点バッファ
	int m_nTextureIdx;//テクスチャのインデックス
private:
	/*static CObject2D* m_pObject2D;*/
	D3DXVECTOR3 m_pos; //現在の位置
	D3DXVECTOR3 m_move; //現在の動き
	D3DXVECTOR3 m_rot; // 向き
	D3DXCOLOR m_col;//カラー
	LPDIRECT3DTEXTURE9 m_pTexture;//テクスチャ


	//float m_posX;	// 位置のX座標
	//float m_posY;	// 位置のY座標
	float m_sizeW;	// 幅
	float m_sizeH;	// 高さ
};


#endif //_OBJECT2D_H_