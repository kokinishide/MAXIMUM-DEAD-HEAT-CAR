//=============================================================================
//
// ボス処理 [boss.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "boss.h"
#include "bullet.h"
#include "explosion.h"
#include "manager.h"
#include "texture.h"
#include "sound.h"
#include "score.h"
#include "boss_bullet.h"

LPDIRECT3DTEXTURE9 CBoss::m_pObj_Texture[CBoss::MAX_MAT] = {};

//===================================
// 
//コンストラクタ
//
//===================================
CBoss::CBoss()
{
	nCounterBullet;
	m_nTextureIdx;
	m_TargetPos;
	m_wasMove = false;
}
//===================================
// 
//デスストラクタ
//
//===================================
CBoss::~CBoss()
{

}

//===================================
// 
//ボスの初期化処理
// 
//===================================
HRESULT CBoss::Init(void)
{
	//LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
	////デバイスの取得
	//pDevice = CManager::GetRenderer()->GetDevice();

	if (FAILED(CObject3D::Init()))//頂点バッファ作成
	{
		return E_FAIL;
	}
	Load();
	CBoss::m_nLife = 3;
	//レンダラーの生成
	CObject3D::SetSizeW(40.0f);
	CObject3D::SetSizeH(40.0f);
	SetType(CObject::TYPE::BOSS);
	//モデル設定
	//CModel* pModel = CManager::GetModel();//取得
	//m_nModelIdx = pModel->Regist("data\\boss.x");//登録
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//設定

	return S_OK;

}

//===================================
// 
//ボスのヒット処理
//
//===================================
void CBoss::Hit(int nDamage)
{
	CObject3D::Hit(nDamage);
}
//===================================
// 
//ボスの終了処理
// 
//===================================
void CBoss::Uninit()
{
	CObject3D::Uninit();//this->Release();自身の開放
	m_bDeath = true;
}

//===================================
// 
//ボスの更新処理
// 
//===================================
void CBoss::Update()
{
	D3DXVECTOR3 BossPos = GetPos();
	D3DXVECTOR3 BossMove = GetMove();
	//位置を更新
	BossPos += BossMove;
	BossMove.y -= 3.0f;//重力
	//BossMove = D3DXVECTOR3(10.0f, 0.0f, 1.0f);
	
	
	
	
	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	//{
	//	//敵との当たり判定（配列を順番にチェック）
	//	for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
			//オブジェクト取得
			CObject* pObj = CObject::GetMyObject();
			//最大数が不明なのでWhileを使用
			while (pObj != nullptr)
			{
				// 次のポインタを保存しておく
				CObject* pNext = pObj->GetNext();
				// やりたい処理を実行（今回はタイプ取得）
				if (CObject::TYPE::PLAYER == pObj->GetType())
				{
					CPlayer* pPlayer = (CPlayer*)pObj;
					D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//位置の取得
					D3DXVECTOR3 PlayerTargetPos = pPlayer->GetTargetPos();//ターゲットの位置の取得
					bool PlayerDushAttack = GetDushAttack();//ダッシュアタックの取得
					//位置を更新
					//PlayerPos += PlayerMove;
					if (PlayerPos.z >= 34060.0f)
					{
						if (m_wasMove == false)
						{
							m_wasMove = true;
							BossMove = D3DXVECTOR3(5.0f, 0.0f, 5.0f);
						}
					}
					
					/*pPlayer->SetPos(PlayerPos);
					D3DXVECTOR3 vec = PlayerTargetPos - PlayerMove;
					PlayerMove -= vec * 5.0f;
					
					
					
					if (BossPos.x >= PlayerPos.x - 85.0f
						&& BossPos.x <= PlayerPos.x + 85.0f
						&& BossPos.z >= PlayerPos.z - 115.0f
						&& BossPos.z <= PlayerPos.z + 5.0f)
					{

						pPlayer->Hit(1);
						PlayerMove.y = 0.0f;
						pPlayer->SetMove(-PlayerMove);
						
					}*/
					
				}
				// ポインタを次のポインタへ変更
				pObj = pNext;
			}
		//}

	//}


	if (BossPos.x >= 225.0f || BossPos.x <= -225.0f)
	{
		BossMove.x *= -1.0f;

	}
	if (BossPos.y <= -50.0f)
	{
		CBoss::Uninit();
	}
	SetPos(BossPos);
	SetMove(BossMove);
	nCounterBullet--;
	if (nCounterBullet <= 0)
	{
		//弾の設定
		CBoss_Bullet::Create(m_pos, D3DXVECTOR3(0.0f, 0.0f, -10.0f), 15);//弾の向き設定可能
		nCounterBullet = 25;
		//サウンドの再生
		//CSound* pSound = CManager::GetSound();//サウンドの取得
		//pSound->PlaySound(CSound::SOUND_LABEL::SOUND_SE_MONSTER);
	}
	
}

//===================================
// 
//ボスの描画処理
// 
//===================================
void CBoss::Draw()
{
	CObject3D::Draw();//ポリゴン描画
}
//===================================
// 
//ボスの生成処理
//
//===================================
CBoss* CBoss::Create(const D3DXVECTOR3& pos)
{
	CBoss* pBoss = nullptr;
	pBoss = new CBoss();
	if (FAILED(pBoss->Init())) {
	}
	pBoss->SetPos(pos);
	pBoss->BindMesh(pBoss->GetMatModel(), pBoss->GetBuffer(), pBoss->GetMesh(), &m_pObj_Texture[0]);
	//pBoss->SetType(CObject::TYPE::BOSS);

	return pBoss;
}
//===================================
// 
//ボスのロード処理
//
//===================================
HRESULT CBoss::Load()
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER BossBuffer = GetBuffer();
	DWORD BossMatModel = GetMatModel();
	LPD3DXMESH BossMesh = GetMesh();
	//テクスチャ生成
	if (FAILED(D3DXLoadMeshFromX("data\\boss.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &BossBuffer, nullptr, &BossMatModel, &BossMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)BossBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(BossMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
				&m_pObj_Texture[nCntMat]);
		}
	}
	SetBuffer(BossBuffer);
	SetMatModel(BossMatModel);
	SetMesh(BossMesh);
	return S_OK;

}
//===================================
// 
//ボスのアンロード処理
//
//===================================
void CBoss::Unload()
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
