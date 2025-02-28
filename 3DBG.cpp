//=============================================================================
//
// 3D背景処理 [3DBG.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "3DBG.h"
#include "bullet.h"
#include "explosion.h"
#include "object2D.h"
#include "manager.h"
#include "enemy.h"

LPDIRECT3DTEXTURE9 C3DBG::m_pObj_Texture[C3DBG::MAX_MAT] = {};

//コンストラクタ
C3DBG::C3DBG()
{
	nCounterBullet;
	m_nTextureIdx;
	m_aTextureFilename;
}
//デスストラクタ
C3DBG::~C3DBG()
{

}


//===================================
//
//3D背景の初期化処理
// 
//===================================
HRESULT C3DBG::Init()
{
	if (FAILED(CObject3D::Init()))//頂点バッファ作成
	{//失敗
		return E_FAIL;
	}
	Load();
	//頂点情報設定に必要な
	//短形サイズなどのパラメータ設定
	CObject3D::SetSizeW(40.0f);
	CObject3D::SetSizeH(40.0f);
	SetType(CObject::TYPE::BG);
	//モデル設定
	//CModel* pModel = CManager::GetModel();//取得
	//m_nModelIdx = pModel->Regist("data\\downtown.x");//登録
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//設定

	return S_OK;//成功

}

//===================================
//
//3D背景の終了処理
// 
//===================================
void C3DBG::Uninit()
{
	CObject3D::Uninit();//this->Release();自身の開放
}

//===================================
//
//3D背景の更新処理
//
//===================================
void C3DBG::Update()
{

}

//===================================
//
//3D背景の描画処理
// 
//===================================
void C3DBG::Draw()
{
	CObject3D::Draw();//ポリゴン描画
}
//===================================
//
//C3DBG生成
//
//===================================
C3DBG* C3DBG::Create(const D3DXVECTOR3& pos)
{
	C3DBG* p3DBG = nullptr;
	p3DBG = new C3DBG();
	if (FAILED(p3DBG->Init())) {
	}
	p3DBG->SetPos(pos);
	p3DBG->BindMesh(p3DBG->GetMatModel(), p3DBG->GetBuffer(), p3DBG->GetMesh(), &m_pObj_Texture[0]);
	//p3DBG->SetType(CObject::TYPE::BG);
	return p3DBG;
}
//===================================
//
//3D背景のロード処理
// 
//===================================
HRESULT C3DBG::Load()
{
	
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER BGBuffer = GetBuffer();
	DWORD BGMatModel = GetMatModel();
	LPD3DXMESH BGMesh = GetMesh();
	if (FAILED(D3DXLoadMeshFromX("data\\downtown.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &BGBuffer, nullptr, &BGMatModel, &BGMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)BGBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(BGMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			strcat(&m_aTextureFilename[0],pMat[nCntMat].pTextureFilename);
			
			if (m_pObj_Texture == nullptr)
			{
				if (FAILED(D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
					&m_pObj_Texture[nCntMat])))
				{
					return E_FAIL;
				}
			}
		}
	}
	SetBuffer(BGBuffer);
	SetMatModel(BGMatModel);
	SetMesh(BGMesh);
	return S_OK;
}
//===================================
//
//3D背景のアンロード処理
// 
//===================================
void C3DBG::Unload()
{
	for (int nCntTexture = 0; nCntTexture < MAX_MAT; nCntTexture++)
	{
		if (m_pObj_Texture[nCntTexture] != nullptr)
		{
			//m_pTexture[nCntTexture]->Release();
			m_pObj_Texture[nCntTexture] = nullptr;
		}
	}
	//メッシュの破棄
	if (m_pMeshModel != nullptr)
	{
		m_pMeshModel->Release();
		m_pMeshModel = nullptr;

	}
	//マテリアルの破棄
	if (m_pBuffMatModel != nullptr)
	{
		m_pBuffMatModel->Release();
		m_pBuffMatModel = nullptr;
	}

	//テクスチャの開放
	if (m_pTexture != nullptr)
	{
		delete[] m_pTexture;
		m_pTexture = nullptr;
	}


	m_bDeath = true;
	CObject3D::Unload();
}