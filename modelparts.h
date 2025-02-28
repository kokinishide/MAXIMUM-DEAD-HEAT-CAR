//=============================================================================
//
// モデルパーツ処理 [modelparts.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _MODELPARTS_H_//このマクロ定義がされてなかったら
#define	_MODELPARTS_H_//2重インクルード防止のマクロ定義
#include"objectX.h"

class CModelParts:public CObjectX
{
public:
	CModelParts();//コンストラクタ
	virtual~CModelParts()override;//デストラクタ
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	void SetMotionPos(D3DXVECTOR3 pos); //位置
	void SetMotionRot(D3DXVECTOR3 rot); //向き
	static CModelParts* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, LPD3DXMESH pMesh, LPD3DXBUFFER pBuffMat, DWORD dwNumMat);
private: 
	D3DXVECTOR3 m_MotionPos;//相対位置
	D3DXVECTOR3 m_MotionRot;//相対向き
	CModelParts* m_pParent;//親モデルパーツへのポインタ
};

#endif //_MODELPARTS_H_