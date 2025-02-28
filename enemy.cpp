//=============================================================================
//
// エネミー処理 [enemy.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "enemy.h"
#include "bullet.h"
#include "explosion.h"
#include "manager.h"
#include "texture.h"
#include "sound.h"
#include "score.h"
#include "model.h"

LPDIRECT3DTEXTURE9 CEnemy::m_pObj_Texture[CEnemy::MAX_MAT] = {};

//===================================
// 
//コンストラクタ
//
//===================================
CEnemy::CEnemy()
{
	nCounterBullet;
	m_nTextureIdx;
	m_TargetPos;//ターゲットの位置
}
//===================================
// 
//デスストラクタ
//
//===================================
CEnemy::~CEnemy()
{

}

//===================================
// 
//敵の初期化処理
// 
//===================================
HRESULT CEnemy::Init(void)
{
	//LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
	////デバイスの取得
	//pDevice = CManager::GetRenderer()->GetDevice();
	
	if (FAILED(CObject3D::Init()))//頂点バッファ作成
	{
		return E_FAIL;
	}
	Load();
	CEnemy::m_nLife = 1;
	//レンダラーの生成
	CObject3D::SetSizeW(40.0f);
	CObject3D::SetSizeH(40.0f);
	SetType(CObject::TYPE::ENEMY);
	//モデル設定
	//CModel* pModel = CManager::GetModel();//取得
	//m_nModelIdx = pModel->Regist("data\\carenemy.x");//登録
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);
	//
	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//設定

	return S_OK;

}

//===================================
// 
//敵のヒット処理
//
//===================================
void CEnemy::Hit(int nDamage)
{
	CObject3D::Hit(nDamage);
}
//===================================
// 
//敵の終了処理
// 
//===================================
void CEnemy::Uninit()
{
	CObject3D::Uninit();//this->Release();自身の開放
	Unload();
}

//===================================
// 
//敵の更新処理
// 
//===================================
void CEnemy::Update()
{
	D3DXVECTOR3 EnemyPos = GetPos();
	D3DXVECTOR3 EnemyMove = GetMove();
	//位置を更新
	EnemyPos += EnemyMove;
		

	/*if (m_pos.x >= 1280.0f || m_pos.x <= 0.0f)
	{
		m_move.x *= -1;
	}
	else if (m_pos.y >= 720.0f || m_pos.y <= 0.0f)
	{
		m_move.y *= -1;
	}*/
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
						//D3DXVECTOR3 PlayerMove = pPlayer->GetMove();//位置の取得
						//D3DXVECTOR3 PlayerTargetPos = pPlayer->GetTargetPos();//ターゲットの位置の取得
						//bool PlayerDushAttack = GetDushAttack();//ダッシュアタックの取得
						////位置を更新
						////PlayerPos += PlayerMove;
						//D3DXVECTOR3 vec = PlayerTargetPos - PlayerMove;
						//PlayerMove -= vec * 5.0f;
						
						if (PlayerPos.z >= EnemyPos.z - 200)
						{
							EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 4.0f);
						}
						
					}
					// ポインタを次のポインタへ変更
					pObj = pNext;
				}
			//}

		//}
		//EnemyMove.y -= 10.0f;//重力
		if (EnemyPos.y <= -50.0f)
		{
			CEnemy::Uninit();
		}
		SetPos(EnemyPos);
		SetMove(EnemyMove);
	////nCounterBullet--;
	//if (nCounterBullet <= 0)
	//{
	//	//弾の設定
	//	CBullet::Create(m_pos, D3DXVECTOR3(-3.0f, 0.0f, 0.0f), 15, CBullet::BULLETTYPE::BULLETTYPE_ENEMY);//敵の弾の向き設定可能
	//	nCounterBullet = 60;
	//	//サウンドの再生
	//	//CSound* pSound = CManager::GetSound();//サウンドの取得
	//	//pSound->PlaySound(CSound::SOUND_LABEL::SOUND_SE_MONSTER);
	//}
}

//===================================
// 
//敵の描画処理
// 
//===================================
void CEnemy::Draw()
{
	CObject3D::Draw();//ポリゴン描画
}
//===================================
// 
//敵の生成処理
//
//===================================
CEnemy* CEnemy::Create(const D3DXVECTOR3& pos)
{
	CEnemy* pEnemy = nullptr;
	pEnemy = new CEnemy();
	if (FAILED(pEnemy->Init())) {
	}
	pEnemy->SetPos(pos);
	pEnemy->BindMesh(pEnemy->GetMatModel(), pEnemy->GetBuffer(), pEnemy->GetMesh(),&m_pObj_Texture[0]);
	//pEnemy->SetType(CObject::TYPE::ENEMY);

	return pEnemy;
}
//===================================
// 
//敵のロード処理
//
//===================================
HRESULT CEnemy::Load()
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER EnemyBuffer = GetBuffer();
	DWORD EnemyMatModel = GetMatModel();
	LPD3DXMESH EnemyMesh = GetMesh();
	//テクスチャ生成
	if (FAILED(D3DXLoadMeshFromX("data\\carenemy.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &EnemyBuffer, nullptr, &EnemyMatModel, &EnemyMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)EnemyBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(EnemyMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
				&m_pObj_Texture[nCntMat]);
		}
	}
	SetBuffer(EnemyBuffer);
	SetMatModel(EnemyMatModel);
	SetMesh(EnemyMesh);
	return S_OK;

}
//===================================
// 
//敵のアンロード処理
//
//===================================
void CEnemy::Unload()
{
	
	for (int nCntTexture = 0; nCntTexture < MAX_MAT; nCntTexture++)
	{
		if (m_pObj_Texture[nCntTexture] != nullptr)
		{
			m_pObj_Texture[nCntTexture]->Release();
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
