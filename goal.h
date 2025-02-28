//=============================================================================
//
// ゴール処理 [goal.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _GOAL_H_//このマクロ定義がされてなかったら
#define _GOAL_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "object3D.h"

//ゴール
class CGoal :public CObject3D
{
public:
	CGoal();//コンストラクタ
	virtual~CGoal()override;//デストラクタ
	virtual HRESULT Init()override;//初期設定
	virtual void Uninit()override;//終了処理
	virtual void Update()override;//更新処理
	virtual void Draw()override;//描画処理
	static CGoal* Create(const D3DXVECTOR3& pos);//生成処理
	HRESULT Load(); //Textureロード
	void Unload();//Textureアンロード
	LPDIRECT3DTEXTURE9* GetTexture() { return &m_pObj_Texture[0]; }
private:
	static const int MAX_MAT = 100;
	static LPDIRECT3DTEXTURE9 m_pObj_Texture[MAX_MAT];
};


#endif //_GOAL_H_


