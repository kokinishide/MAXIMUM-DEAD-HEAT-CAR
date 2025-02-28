//=============================================================================
//
// ゴール処理 [goal.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "goal.h"
#include "bullet.h"
#include "explosion.h"
#include "object2D.h"
#include "manager.h"
#include "enemy.h"
//#include "game.h"
//#include "score.h"

LPDIRECT3DTEXTURE9 CGoal::m_pObj_Texture[CGoal::MAX_MAT] = {};

//===================================
// 
//コンストラクタ
//
//===================================
CGoal::CGoal()
{

}
//===================================
// 
//デスストラクタ
//
//===================================
CGoal::~CGoal()
{

}


//===================================
// 
//ゴールの初期化処理
// 
//===================================
HRESULT CGoal::Init()
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
	SetType(CObject::TYPE::GOAL);
	//モデル設定
	//CModel* pModel = CManager::GetModel();//取得
	//m_nModelIdx = pModel->Regist("data\\goal.x");//登録
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//設定
	return S_OK;//成功

}

//===================================
// 
//ゴールの終了処理
// 
//===================================
void CGoal::Uninit()
{
	CObject3D::Uninit();//this->Release();自身の開放
}

//===================================
// 
//ゴールの更新処理
// 
//===================================
void CGoal::Update()
{

	CObject3D::Update();//頂点情報更新
	//bool bIsLanding = false; //着地しているかどうか

	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	//{
	//	for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
	//		//オブジェクト取得
	//		CObject* pObj = CObject::GetMyObject(nCntPriority, nCntObj);
	//		if (pObj != nullptr)
	//		{
	//			//種類の取得（ブロックなら当たり判定）
	//			CObject::TYPE type = pObj->GetType();
	//			if (type == CObject::TYPE::PLAYER)
	//			{
	//				CPlayer* pPlayer = (CPlayer*)pObj;
	//				D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//位置の取得
	//				D3DXVECTOR3 PlayerPosOld = pPlayer->GetPosOld();//古い位置の取得
	//				D3DXVECTOR3 PlayerMove = pPlayer->GetMove();//動きの取得

	//				//if (PlayerPosOld.y < m_pos.y - 0.0f
	//				//	&& PlayerPos.y >= m_pos.y - 0.0f
	//				//	&& PlayerPos.x > m_pos.x - 200.0f
	//				//	&& PlayerPos.x < m_pos.x + 200.0f
	//				//	&& PlayerPos.z > m_pos.z - 200.0f
	//				//	&& PlayerPos.z < m_pos.z + 200.0f)
	//				//{
	//				//	bIsLanding = true;
	//				//	PlayerPos.y = m_pos.y - 0.0f;
	//				//	PlayerMove.y = 0.0f;
	//				//}
	//				if (PlayerPosOld.y >= m_pos.y + 0.0f
	//					&& PlayerPos.y <= m_pos.y + 0.0f
	//					&& PlayerPos.x < m_pos.x + 225.0f
	//					&& PlayerPos.x > m_pos.x - 225.0f
	//					&& PlayerPos.z < m_pos.z + 10.0f
	//					&& PlayerPos.z > m_pos.z - 10.0f)
	//				{
	//					pPlayer->HitGoal(1);
	//					bIsLanding = true;
	//					PlayerPos.y = m_pos.y + 0.0f;
	//					PlayerMove.y = 0.0f;

	//					pPlayer->SetPos(PlayerPos); //位置を設定
	//					pPlayer->SetMove(PlayerMove); //動きを設定
	//					pPlayer->SetIsLanding(bIsLanding); //着地を設定

	//				}
	//				/*if (PlayerPosOld.y <= m_pos.y - 10.0f
	//					&& PlayerPos.y > m_pos.y - 10.0f
	//					)
	//				{
	//					bIsLanding = true;
	//					PlayerPos.y = m_pos.y - 10.0f;
	//					PlayerMove.y = 0.0f;
	//				}
	//				if (PlayerPosOld.y >= m_pos.y + 10.0f
	//					&& PlayerPos.y < m_pos.y + 10.0f
	//					)
	//				{
	//					bIsLanding = true;
	//					PlayerPos.y = m_pos.y + 10.0f;
	//					PlayerMove.y = 0.0f;
	//				}*/

	//			}
	//			
	//		}
	//	}
	//}
}

//===================================
// 
//ゴールの描画処理
// 
//===================================
void CGoal::Draw()
{
	CObject3D::Draw();//ポリゴン描画
}
//===================================
// 
//ゴールの生成処理
//
//===================================
CGoal* CGoal::Create(const D3DXVECTOR3& pos)
{
	CGoal* pGoal = nullptr;
	pGoal = new CGoal();
	if (FAILED(pGoal->Init())) {
	}
	pGoal->SetPos(pos);
	pGoal->BindMesh(pGoal->GetMatModel(), pGoal->GetBuffer(), pGoal->GetMesh(), &m_pObj_Texture[0]);
	//pGoal->SetType(CObject::TYPE::GOAL);
	return pGoal;
}
//===================================
//
//ゴールのロード処理
//
//===================================
HRESULT CGoal::Load()
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER GoalBuffer = GetBuffer();
	DWORD GoalMatModel = GetMatModel();
	LPD3DXMESH GoalMesh = GetMesh();
	if (FAILED(D3DXLoadMeshFromX("data\\goal.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &GoalBuffer, nullptr, &GoalMatModel, &GoalMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)GoalBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(GoalMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
				&m_pObj_Texture[nCntMat]);
		}
	}
	SetBuffer(GoalBuffer);
	SetMatModel(GoalMatModel);
	SetMesh(GoalMesh);
	return S_OK;
}
//===================================
//
//ゴールのアンロード処理
//
//===================================
void CGoal::Unload()
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
