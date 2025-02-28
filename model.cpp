//=============================================================================
//
// モデル管理処理 [model.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "manager.h"
#include"model.h"
#include"game.h"
#include"object.h"
#include"texture.h"
#include<string.h>
LPDIRECT3DTEXTURE9 CModel::m_pTexture[MAX_MODEL] = {};
int CModel::m_nNumAll = 0;


//===================================
// 
//コンストラクタ
//
//===================================
CModel::CModel()
{
	for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
	{
		//各メンバの初期化
		m_pTexture[nCnt] = nullptr;
		pMesh[nCnt] = nullptr;
		pBuff[nCnt] = nullptr;
		//m_pModelName[nCnt] = nullptr;
	}
}
//===================================
// 
//デスストラクタ
//
//===================================
CModel::~CModel()
{

}
//===================================
// 
//モデル破棄
// 
//===================================
void CModel::Unload()
{
	for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
	{
		//テクスチャ配列の破棄
		if (m_pTexture[nCnt] != nullptr)
		{
			//m_pTexture[nCnt]->Release();
			m_pTexture[nCnt] = nullptr;
		}
		//メッシュ配列の破棄
		if (pMesh[nCnt] != nullptr)
		{
			//pMesh[nCnt]->Release();
			pMesh[nCnt] = nullptr;
		}
		//バッファ配列の破棄
		if (pBuff[nCnt] != nullptr)
		{
			//pBuff[nCnt]->Release();
			pBuff[nCnt] = nullptr;
		}
		////保管データの破棄
		//if (m_pModelName[nCnt] != nullptr)
		//{
		//	m_pModelName[nCnt] = nullptr;
		//}
	}
}
//===================================
// 
//モデル登録
//
//===================================
int CModel::Regist(const char* pModelName)
{
	
	CTexture* pTexture = CManager::GetTexture();//テクスチャの取得;
	int nIdx = 0;//モデルID
	for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
	{
		if (pBuff[nCnt] == nullptr)
		{//登録されてなかった
			nIdx = nCnt;//ID設定
			//モデル読み込み
			LPDIRECT3DDEVICE9 pDevice = nullptr;
			pDevice = CManager::GetRenderer()->GetDevice();
			//テクスチャ生成
			if (FAILED(D3DXLoadMeshFromX(pModelName, D3DXMESH_SYSTEMMEM, pDevice, nullptr, &pBuff[nIdx], nullptr, &dwNumMatModel[nIdx], &pMesh[nIdx])))
			{
				return E_FAIL;
			}
			D3DXMATERIAL* pMat;
			pMat = (D3DXMATERIAL*)pBuff[nIdx]->GetBufferPointer();
			for (int nCntMat = 0; nCntMat < int(dwNumMatModel[nIdx]); nCntMat++)
			{
				if (pMat[nCntMat].pTextureFilename != nullptr)
				{
					pTexture->Regist(pMat[nCntMat].pTextureFilename);
				}
			}

			//パスの登録
			m_pModelName[nCnt][0];
			//文字列を代入する
			strcpy(&m_pModelName[nCnt][0],pModelName);
			m_nNumAll++;//モデル数
			break;
		}
		else if (strcmp(&m_pModelName[nCnt][0], pModelName) == 0)
		{//すでに生成されているモデルと一致した
			nIdx = nCnt;//ID設定
			break;
		}
	}
	return nIdx;//IDを返す
}
//モデル取得(引数IDのモデルを返す)
//LPDIRECT3DTEXTURE9 CModel::GetAddress(int nIdx)//モデル取得
//{
//	return m_pModel[nIdx];
//}