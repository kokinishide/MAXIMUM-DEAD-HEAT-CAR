//=============================================================================
//
// 3D背景処理 [3DBG.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _3DBG_H_//このマクロ定義がされてなかったら
#define _3DBG_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "object3D.h"

//マクロ定義
#define MAX_3DBG (128) //3D背景の最大数

//3D背景
class C3DBG :public CObject3D
{
public:
	C3DBG();//コンストラクタ
	virtual~C3DBG()override;//デストラクタ
	virtual HRESULT Init()override;//初期設定
	virtual void Uninit()override;//終了処理
	virtual void Update()override;//更新処理
	virtual void Draw()override;//描画処理
	static C3DBG* Create(const D3DXVECTOR3& pos);//生成処理
	HRESULT Load(); //Xファイルロード
	void Unload();//Xファイルアンロード
	LPDIRECT3DTEXTURE9* GetTexture() { return &m_pObj_Texture[0]; }
private:
	static const int MAX_MAT = 100;
	static LPDIRECT3DTEXTURE9 m_pObj_Texture[MAX_MAT];
	int nCounterBullet;
	int m_nTextureIdx;
	char m_aTextureFilename[100] = "data\\";
};

#endif //_3DBG_H_


