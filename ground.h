//=============================================================================
//
// グラウンド処理 [ground.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _GROUND_H_//このマクロ定義がされてなかったら
#define _GROUND_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "object3D.h"

//マクロ定義
#define MAX_GROUND (1) //地面の最大数

//グラウンド
class CGround :public CObject3D
{
public:
	CGround();//コンストラクタ
	virtual~CGround()override;//デストラクタ
	virtual HRESULT Init()override;//初期設定
	virtual void Uninit()override;//終了処理
	virtual void Update()override;//更新処理
	virtual void Draw()override;//描画処理
	static CGround* Create(const D3DXVECTOR3& pos);//生成処理
	HRESULT Load(); //Textureロード
	void Unload();//Textureアンロード
	LPDIRECT3DTEXTURE9* GetTexture() { return &m_pObj_Texture[0]; }
private:
	static const int MAX_MAT = 100;
	static LPDIRECT3DTEXTURE9 m_pObj_Texture[MAX_MAT];
	int m_nTextureIdx;
};

#endif //_GROUND_H_

