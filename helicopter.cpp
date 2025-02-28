//=============================================================================
//
// ヘリコプターエネミー処理 [helicopter.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "helicopter.h"
#include "bullet.h"
#include "explosion.h"
#include "manager.h"
#include "texture.h"
#include "enemy_bullet.h"

LPDIRECT3DTEXTURE9 CHelicopter::m_pObj_Texture[CHelicopter::MAX_MAT] = {};

//===================================
// 
//コンストラクタ
//
//===================================
CHelicopter::CHelicopter()
{
	nCounterBullet;
	m_nTextureIdx;
}
//===================================
// 
//デスストラクタ
//
//===================================
CHelicopter::~CHelicopter()
{

}

//===================================
// 
//敵の初期化処理
// 
//===================================
HRESULT CHelicopter::Init(void)
{
	//LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
	////デバイスの取得
	//pDevice = CManager::GetRenderer()->GetDevice();

	if (FAILED(CObject3D::Init()))//頂点バッファ作成
	{
		return E_FAIL;
	}
	Load();
	CHelicopter::m_nLife = 1;
	//レンダラーの生成
	CObject3D::SetSizeW(40.0f);
	CObject3D::SetSizeH(40.0f);
	SetType(CObject::TYPE::HELICOPTER);
	//モデル設定
	//CModel* pModel = CManager::GetModel();//取得
	//m_nModelIdx = pModel->Regist("data\\helicopter.x");//登録
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//設定

	return S_OK;

}

//===================================
// 
//ヘリコプターのヒット処理
//
//===================================
void CHelicopter::Hit(int nDamage)
{
	CObject3D::Hit(nDamage);
}
//===================================
// 
//ヘリコプターの終了処理
// 
//===================================
void CHelicopter::Uninit()
{
	CObject3D::Uninit();//this->Release();自身の開放
}

//===================================
// 
//ヘリコプターの更新処理
// 
//===================================
void CHelicopter::Update()
{
	D3DXVECTOR3 HelicopterPos = GetPos();
	D3DXVECTOR3 HelicopterMove = GetMove();
	//位置を更新
	HelicopterPos += HelicopterMove;
	HelicopterMove = D3DXVECTOR3(0.0f, 0.0f, 4.0f);

	SetPos(HelicopterPos);
	SetMove(HelicopterMove);
	
	nCounterBullet--;
	if (nCounterBullet <= 0)
	{
		//弾の設定
		CEnemy_Bullet::Create(m_pos, D3DXVECTOR3(0.0f, -5.0f, 0.0f), 15, CEnemy_Bullet::BULLETTYPE::BULLETTYPE_HELICOPTER);//弾の向き設定可能
		nCounterBullet = 60;
		//サウンドの再生
		//PlaySound(SOUND_SE_MONSTER);
	}
}

//===================================
// 
//ヘリコプターの描画処理
// 
//===================================
void CHelicopter::Draw()
{
	CObject3D::Draw();//ポリゴン描画
}
//===================================
// 
//ヘリコプターの生成処理
//
//===================================
CHelicopter* CHelicopter::Create(const D3DXVECTOR3& pos)
{
	CHelicopter* pHelicopter = nullptr;
	pHelicopter = new CHelicopter();
	if (FAILED(pHelicopter->Init())) {
	}
	pHelicopter->SetPos(pos);
	pHelicopter->BindMesh(pHelicopter->GetMatModel(), pHelicopter->GetBuffer(), pHelicopter->GetMesh(), &m_pObj_Texture[0]);
	//pHelicopter->SetType(CObject::TYPE::HELICOPTER);

	return pHelicopter;
}
//===================================
// 
//ヘリコプターのロード処理
//
//===================================
HRESULT CHelicopter::Load()
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER HelicopterBuffer = GetBuffer();
	DWORD HelicopterMatModel = GetMatModel();
	LPD3DXMESH HelicopterMesh = GetMesh();
	//テクスチャ生成
	if (FAILED(D3DXLoadMeshFromX("data\\helicopter.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &HelicopterBuffer, nullptr, &HelicopterMatModel, &HelicopterMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)HelicopterBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(HelicopterMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
				&m_pObj_Texture[nCntMat]);
		}
	}
	SetBuffer(HelicopterBuffer);
	SetMatModel(HelicopterMatModel);
	SetMesh(HelicopterMesh);
	return S_OK;

}
//===================================
// 
//ヘリコプターのアンロード処理
//
//===================================
void CHelicopter::Unload()
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
