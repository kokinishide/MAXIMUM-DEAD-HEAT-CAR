//=============================================================================
//
// オブジェクト3D処理 [object3D.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include<stdio.h>
#include"object3D.h"
#include "renderer.h"
#include "manager.h"
#include"main.h"
#include"input.h"


//int m_nNumObject3D = 0;
bool CObject3D::m_bDisp;
int CObject3D::m_nCounterState;
int CObject3D::nNumObject3D;

//===================================
// 
//コンストラクタ
//
//===================================
CObject3D::CObject3D()
{
	/*m_pVtxBuff = nullptr;
	m_pTexture = nullptr;*/
	m_pMeshModel = nullptr;
	m_pBuffMatModel = nullptr;
	m_dwNumMatModel;
	m_mtxWorldModel;
	m_pTexture = nullptr;
	/*m_pos.x = 80.0f;
	m_pos.y = 560.0f;*/

	m_sizeW = 1280.0f;
	m_sizeH = 720.0f;
}
//===================================
// 
//デスストラクタ
//
//===================================
CObject3D::~CObject3D()
{

}
//===================================
// 
//オブジェクト3Dの初期設定（頂点バッファ生成）
//
//===================================
HRESULT CObject3D::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();

	//m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //移動量を初期化する
	//m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	////Xファイルの読み込み
	//D3DXLoadMeshFromX("data\\airplane000.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &m_pBuffMatModel, nullptr, &m_dwNumMatModel, &m_pMeshModel);
	//頂点バッファの生成
	/*pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		nullptr);*/



	return S_OK;
}
//===================================
//
//オブジェクト3Dのヒット処理
//
//===================================
void CObject3D::Hit(int nDamage)
{
	m_nLife -= nDamage;
	if (m_nLife <= 0)
	{
		nNumObject3D--; //総数カウントダウン
		m_bDisp = false;
	}
}
//===================================
//
//オブジェクト3Dのゴールヒット処理
//
//===================================
void CObject3D::HitGoal(int nHit)
{
	m_nGoal -= nHit;
	if (m_nGoal <= 0)
	{
		nNumObject3D--; //総数カウントダウン
		m_bDisp = false;
	}
}
//===================================
//
//オブジェクト3Dのワープヒット処理
//
//===================================
void CObject3D::HitWarp(int nHitWarp)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}
//===================================
// 
//オブジェクト3D終了処理（頂点バッファ破棄）
//
//===================================
void CObject3D::Uninit()
{
	// モデルの一括管理を実装したならReleaseしない

	//メッシュの破棄
	if (m_pMeshModel != nullptr)
	{
		//m_pMeshModel->Release();
		m_pMeshModel = nullptr;

	}
	//マテリアルの破棄
	if (m_pBuffMatModel != nullptr)
	{
		//m_pBuffMatModel->Release();
		m_pBuffMatModel = nullptr;
	}

	//テクスチャの開放
	if (m_pTexture != nullptr)
	{
		delete[] m_pTexture;
		m_pTexture = nullptr;
	}

	//CObject::Release();
	m_bDeath = true;
}
//===================================
// 
//オブジェクト3Dの更新処理（頂点情報の更新）
//
//===================================
void CObject3D::Update()
{

}
//===================================
// 
//オブジェクト3Dの描画処理（ポリゴン描画）
//
//===================================
void CObject3D::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;
	D3DXMATRIX mtxWorld; //ワールドマトリックス
	D3DXMATRIX mtxRot, mtxTrans; //計算用マトリックス
	D3DMATERIAL9 matDef; //現在のマテリアル保存用
	D3DXMATERIAL* pMat;//マテリアルデータへのポインタ
	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();
	//現在のマテリアルを取得
	pDevice->GetMaterial(&matDef);

	//ワールド変換行列の作成

	//ワールド変換行列の初期化
	D3DXMatrixIdentity(&mtxWorld);
	//向きをワールド変換行列へ反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxRot);

	//位置をワールド変換行列へ反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxTrans);

	//ワールド変換行列の設定
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);
	//マテリアルデータへのポインタを取得
	if (m_pBuffMatModel != nullptr)
	{
		pMat = (D3DXMATERIAL*)m_pBuffMatModel->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)m_dwNumMatModel; nCntMat++)
		{

			//マテリアルの設定
			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
			if (m_pTexture != nullptr)
			{
				//テクスチャの設定
				pDevice->SetTexture(0, m_pTexture[nCntMat]);//nullptr
			}
			else
			{
				pDevice->SetTexture(0,nullptr);//nullptr
			}
			//モデル（パーツ）の描画
			m_pMeshModel->DrawSubset(nCntMat);
		}
	}
	//保存していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);
}
//===================================
//
//オブジェクト3Dの生成処理
//
//===================================
CObject3D* CObject3D::Create(D3DXVECTOR3 pos)
{
	CObject3D* pObject3D = new CObject3D();//3Dオブジェクト生成
	pObject3D->Init();
	return nullptr;
}

//===================================
// 
//CObject3Dのロード処理
//
//===================================
HRESULT CObject3D::Load()
{
	return S_OK;
}
//===================================
// 
//CObject3Dのアンロード処理
//
//===================================
void CObject3D::Unload()
{

}

//===================================
// 
//Xファイル設定
//
//===================================
void CObject3D::BindMesh(DWORD dwNumMatModel, LPD3DXBUFFER pBuff, LPD3DXMESH pMesh, LPDIRECT3DTEXTURE9* pTexture)
{
	m_dwNumMatModel = dwNumMatModel;
	m_pMeshModel = pMesh;
	m_pBuffMatModel = pBuff;
	if (pTexture != nullptr)
	{
	    m_pTexture = new LPDIRECT3DTEXTURE9[int(dwNumMatModel)];
		for (int nCnt = 0; nCnt < int(dwNumMatModel); nCnt++)
		{
			m_pTexture[nCnt] = pTexture[nCnt];
		}
	}
}
//===================================
// 
//モデル設定
//
//===================================
void CObject3D::BindModel(DWORD dwNumMatModel, LPD3DXBUFFER pBuff, LPD3DXMESH pMesh, LPDIRECT3DTEXTURE9 pTexture)
{
	//m_dwNumMatModel = dwNumMatModel;
	//m_pMeshModel = pMesh;
	//m_pBuffMatModel = pBuff;
	//if (pTexture != nullptr)
	//{
	//	m_pTexture = new LPDIRECT3DTEXTURE9[int(dwNumMatModel)];
	//	for (int nCnt = 0; nCnt < int(dwNumMatModel); nCnt++)
	//	{
	//		m_pTexture[nCnt] = pTexture;
	//	}
	//}
}
//===================================
//
//位置設定
//
//===================================
void CObject3D::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;

}
//===================================
//
//古い位置設定
//
//===================================
void CObject3D::SetPosOld(D3DXVECTOR3 posold)
{
	m_PosOld = posold;

}
//===================================
//
//動き設定
//
//===================================
void CObject3D::SetMove(D3DXVECTOR3 move)
{
	m_move = move;
}//===================================
//
//向き設定
//
//===================================
void CObject3D::SetRot(D3DXVECTOR3 rot)
{
	m_rot = rot;
}
//===================================
//
//ターゲットの位置設定
//
//===================================
void CObject3D::SetTargetPos(D3DXVECTOR3 TargetPos)
{
	m_TargetPos = TargetPos;
}
//===================================
//
//ダッシュアタック設定
//
//===================================
void CObject3D::SetDushAttack(bool DushAttack)
{
	m_DushAttack = DushAttack;
}
//===================================
//
//着地設定
//
//===================================
void CObject3D::SetIsLanding(bool bIsLanding)
{
	IsLanding = bIsLanding;
}
//void CObject2D::SetPosX(float x)
//{
//	m_pos.x = x;
//}
//void CObject2D::SetPosY(float y)
//{
//	m_pos.y = y;
//}

//===================================
//
//幅のサイズ設定
//
//===================================
void CObject3D::SetSizeW(float w)
{
	m_sizeW = w;
}
//===================================
//
//高さのサイズ設定
//
//===================================
void CObject3D::SetSizeH(float h)
{
	m_sizeH = h;
}
//===================================
//
//ライフ設定
//
//===================================
void CObject3D::SetLife(int nLife)
{
	m_nLife = nLife;
}
//===================================
//
//ゴールのヒット設定
//
//===================================
void CObject3D::SetGoalHit(int nGoal)
{
	m_nGoal = nGoal;
}

//===================================
//
//幅のサイズ設定
//
//===================================
void CObject3D::SetMesh(LPD3DXMESH pMeshModel)
{
	m_pMeshModel = pMeshModel;
}
//===================================
//
//Xファイルのバッファー設定
//
//===================================
void CObject3D::SetBuffer(LPD3DXBUFFER pBuffMatModel)
{
	m_pBuffMatModel = pBuffMatModel;
}
//===================================
//
//Xファイルのマット設定
//
//===================================
void CObject3D::SetMatModel(DWORD dwNumMatModel)
{
	m_dwNumMatModel = dwNumMatModel;
}
//===================================
//
//Xファイルのワールド設定
//
//===================================
void CObject3D::SetWorldModel(D3DXMATRIX mtxWorldModel)
{
	m_mtxWorldModel = mtxWorldModel;
}