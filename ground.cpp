//=============================================================================
//
// グラウンド処理 [ground.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "ground.h"
#include "bullet.h"
#include "explosion.h"
#include "object2D.h"
#include "manager.h"
#include "enemy.h"
#include "truck.h"
#include "boss.h"
#include "object3D.h"
//#include "game.h"
//#include "score.h"

LPDIRECT3DTEXTURE9 CGround::m_pObj_Texture[CGround::MAX_MAT] = {};

//===================================
// 
//コンストラクタ
//
//===================================
CGround::CGround()
{
	m_nTextureIdx;
}
//===================================
// 
//デスストラクタ
//
//===================================
CGround::~CGround()
{

}



//===================================
// 
//グラウンドの初期化処理
// 
//===================================
HRESULT CGround::Init()
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
	SetType(CObject::TYPE::GROUND);
	//モデル設定
	//CModel* pModel = CManager::GetModel();//取得
	//m_nModelIdx = pModel->Regist("data\\ground.x");//登録
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//設定
	return S_OK;//成功

}

//===================================
// 
//グラウンドの終了処理
// 
//===================================
void CGround::Uninit()
{
	CObject3D::Uninit();//this->Release();自身の開放
	Unload();
}

//===================================
// 
//グラウンドの更新処理
// 
//===================================
void CGround::Update()
{

	CObject3D::Update();//頂点情報更新
	bool bIsLanding = false; //着地しているかどうか

	/*for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	{
		for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
		{*/
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
					D3DXVECTOR3 PlayerPosOld = pPlayer->GetPosOld();//古い位置の取得
					D3DXVECTOR3 PlayerMove = pPlayer->GetMove();//動きの取得

					//if (PlayerPosOld.y < m_pos.y - 0.0f
					//	&& PlayerPos.y >= m_pos.y - 0.0f
					//	&& PlayerPos.x > m_pos.x - 200.0f
					//	&& PlayerPos.x < m_pos.x + 200.0f
					//	&& PlayerPos.z > m_pos.z - 200.0f
					//	&& PlayerPos.z < m_pos.z + 200.0f)
					//{
					//	bIsLanding = true;
					//	PlayerPos.y = m_pos.y - 0.0f;
					//	PlayerMove.y = 0.0f;
					//}
					if (PlayerPosOld.y >= m_pos.y + 0.0f
						&& PlayerPos.y <= m_pos.y + 0.0f
						&& PlayerPos.x < m_pos.x + 225.0f
						&& PlayerPos.x > m_pos.x - 225.0f
						&& PlayerPos.z < m_pos.z + 440.0f
						&& PlayerPos.z > m_pos.z - 440.0f)
					{
						bIsLanding = true;
						PlayerPos.y = m_pos.y + 0.0f;
						PlayerMove.y = 0.0f;

						pPlayer->SetPos(PlayerPos); //位置を設定
						pPlayer->SetMove(PlayerMove); //動きを設定
						pPlayer->SetIsLanding(bIsLanding); //着地を設定

					}
					/*if (PlayerPosOld.y <= m_pos.y - 10.0f
						&& PlayerPos.y > m_pos.y - 10.0f
						)
					{
						bIsLanding = true;
						PlayerPos.y = m_pos.y - 10.0f;
						PlayerMove.y = 0.0f;
					}
					if (PlayerPosOld.y >= m_pos.y + 10.0f
						&& PlayerPos.y < m_pos.y + 10.0f
						)
					{
						bIsLanding = true;
						PlayerPos.y = m_pos.y + 10.0f;
						PlayerMove.y = 0.0f;
					}*/

				}
			
				if (CObject::TYPE::ENEMY == pObj->GetType())
				{
					CEnemy* pEnemy = (CEnemy*)pObj;
					D3DXVECTOR3 EnemyPos = pEnemy->GetPos();//位置の取得
					D3DXVECTOR3 EnemyPosOld = pEnemy->GetPosOld();//古い位置の取得
					D3DXVECTOR3 EnemyMove = pEnemy->GetMove();//動きの取得

					if (EnemyPosOld.y >= m_pos.y + 0.0f
						&& EnemyPos.y <= m_pos.y + 0.0f
						&& EnemyPos.x < m_pos.x + 225.0f
						&& EnemyPos.x > m_pos.x - 225.0f
						&& EnemyPos.z < m_pos.z + 440.0f
						&& EnemyPos.z > m_pos.z - 440.0f)
					{
						EnemyPos.y = m_pos.y + 0.0f;
						EnemyMove.y = 0.0f;

						pEnemy->SetPos(EnemyPos); //位置を設定
						pEnemy->SetMove(EnemyMove); //動きを設定

					}
				}
				
				if (CObject::TYPE::TRUCK == pObj->GetType())
				{
					CTruck* pTruck = (CTruck*)pObj;
					D3DXVECTOR3 TruckPos = pTruck->GetPos();//位置の取得
					D3DXVECTOR3 TruckPosOld = pTruck->GetPosOld();//古い位置の取得
					D3DXVECTOR3 TruckMove = pTruck->GetMove();//動きの取得

					if (TruckPosOld.y >= m_pos.y + 0.0f
						&& TruckPos.y <= m_pos.y + 0.0f
						&& TruckPos.x < m_pos.x + 225.0f
						&& TruckPos.x > m_pos.x - 225.0f
						&& TruckPos.z < m_pos.z + 440.0f
						&& TruckPos.z > m_pos.z - 440.0f)
					{
						TruckPos.y = m_pos.y + 0.0f;
						TruckMove.y = 0.0f;

						pTruck->SetPos(TruckPos); //位置を設定
						pTruck->SetMove(TruckMove); //動きを設定

					}
				}
				
				if (CObject::TYPE::BOSS == pObj->GetType())
				{
					CBoss* pBoss = (CBoss*)pObj;
					D3DXVECTOR3 BossPos = pBoss->GetPos();//位置の取得
					D3DXVECTOR3 BossPosOld = pBoss->GetPosOld();//古い位置の取得
					D3DXVECTOR3 BossMove = pBoss->GetMove();//動きの取得

					if (BossPosOld.y >= m_pos.y + 0.0f
						&& BossPos.y <= m_pos.y + 0.0f
						&& BossPos.x < m_pos.x + 225.0f
						&& BossPos.x > m_pos.x - 225.0f
						&& BossPos.z < m_pos.z + 440.0f
						&& BossPos.z > m_pos.z - 440.0f)
					{
						BossPos.y = m_pos.y + 0.0f;
						BossMove.y = 0.0f;

						pBoss->SetPos(BossPos); //位置を設定
						pBoss->SetMove(BossMove); //動きを設定

					}
				}



				// ポインタを次のポインタへ変更
				pObj = pNext;
			}

			//if (pObj != nullptr)
			//{
			//	//種類の取得（ブロックなら当たり判定）
			//	CObject::TYPE type = pObj->GetType();
			//	
			//	//SetType(CObject::TYPE::BOSS);
			//}
		//}
	//}
}

//===================================
// 
//グラウンドの描画処理
// 
//===================================
void CGround::Draw()
{
	CObject3D::Draw();//ポリゴン描画
}
//===================================
// 
//グラウンドの生成処理
//
//===================================
CGround* CGround::Create(const D3DXVECTOR3& pos)
{
	CGround* pGround = nullptr;
	pGround = new CGround();
	if (FAILED(pGround->Init())) {
	}
	pGround->SetPos(pos);
	pGround->BindMesh(pGround->GetMatModel(), pGround->GetBuffer(), pGround->GetMesh(), &m_pObj_Texture[0]);
	//pGround->SetType(CObject::TYPE::GROUND);
	return pGround;
}
//===================================
//
//グラウンドのロード処理
//
//===================================
HRESULT CGround::Load()
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER GroundBuffer = GetBuffer();
	DWORD GroundMatModel = GetMatModel();
	LPD3DXMESH GroundMesh = GetMesh();
	if (FAILED(D3DXLoadMeshFromX("data\\ground1.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &GroundBuffer, nullptr, &GroundMatModel, &GroundMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)GroundBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(GroundMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
				&m_pTexture[nCntMat]);
		}
	}
	SetBuffer(GroundBuffer);
	SetMatModel(GroundMatModel);
	SetMesh(GroundMesh);
	return S_OK;
}
//===================================
//
//グラウンドのアンロード処理
//
//===================================
void CGround::Unload()
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