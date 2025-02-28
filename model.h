//=============================================================================
//
// モデル処理 [model.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _MODEL_H_//このマクロ定義がされてなかったら
#define _MODEL_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object3D.h"
#include "scene.h"
//マクロ定義
#define MAX_MODEL (100) //モデルの最大数
#define MAX_ROW (100) //モデルの行
#define MAX_COL (100) //モデルの列

//モデル管理
class CModel : public CObject3D
{
public:
	CModel();//コンストラクタ
	~CModel();//デストラクタ
	void Unload();//モデル破棄
	int Regist(const char* pModelName);//モデル登録
	//LPDIRECT3DTEXTURE9 GetAddress(int nIdx);//モデル取得
	LPD3DXMESH GetMesh(int nIdx) { return pMesh[nIdx]; }//メッシュ取得など用意
	LPD3DXBUFFER GetBuffer(int nIdx) { return pBuff[nIdx]; }//マテリアルへのポインタの取得など用意
	DWORD GetMatModel(int nIdx) { return dwNumMatModel[nIdx]; }//マテリアルの数の取得など用意
	LPDIRECT3DTEXTURE9 GetTexture(int nIdx) { return m_pTexture[nIdx]; }//テクスチャの取得など用意
private:
	static LPDIRECT3DTEXTURE9 m_pTexture[MAX_MODEL];
	//const char* m_pModelName[MAX_MODEL];//保管データの配列
	//char m_pModelName;
	//int row = MAX_ROW;//行
	//int col = MAX_COL;//列
	char m_pModelName[MAX_ROW][MAX_COL];		//保管データの配列
	static int m_nNumAll;//モデルの総数
	LPD3DXMESH pMesh[MAX_MODEL];
	LPD3DXBUFFER pBuff[MAX_MODEL];
	DWORD dwNumMatModel[MAX_MODEL];
	
};

#endif //_MODEL_H_