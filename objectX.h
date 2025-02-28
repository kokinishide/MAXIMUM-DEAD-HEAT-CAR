//=============================================================================
//
// オブジェクトX処理 [objectX.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _OBJECTX_H_//このマクロ定義がされてなかったら
#define _OBJECTX_H_//2重インクルード防止のマクロ定義

#include"object.h"
#define MAX_MOTION_TEXTURE (16)

//クラス
class CObjectX :public CObject
{
public:
	CObjectX();//コンストラクタ
	virtual~CObjectX()override;//デストラクタ
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	void SetPos(D3DXVECTOR3 pos); //位置
	void SetRot(D3DXVECTOR3 rot); //向き
	static CObjectX* Create(D3DXVECTOR3 pos,D3DXVECTOR3 rot, LPD3DXMESH pMesh, LPD3DXBUFFER pBuffMat, DWORD dwNumMat);
	D3DXMATRIX GetWorldMat();
private:
	D3DXVECTOR3 m_pos;//位置
	D3DXVECTOR3 m_rot;//向き
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//頂点バッファ
	LPD3DXMESH m_pMesh; //メッシュ（頂点情報）へのポインタ
	LPD3DXBUFFER m_pBuffMat; //マテリアルへのポインタ
	DWORD m_dwNumMat; //マテリアルの数
	D3DXMATRIX m_mtxWorld; //ワールドマトリックス
	LPDIRECT3DTEXTURE9 m_pTexture[MAX_MOTION_TEXTURE];//テクスチャへのポインタ

};
#endif //_OBJECTX_H_