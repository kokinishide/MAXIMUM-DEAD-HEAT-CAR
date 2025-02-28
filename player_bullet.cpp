//=============================================================================
//
// プレイヤーのバレット処理 [player_bullet.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player_bullet.h"
#include "player.h"
#include "input.h"
#include "explosion.h"
#include "enemy.h"
#include"manager.h"
#include"object.h"
#include"object2D.h"
#include "block.h"
#include"helicopter.h"

//===================================
// 
//マクロ定義
//
//===================================
#define BULLET_SIZE_X (50.0f)//玉の横幅
#define BULLET_SIZE_Y (50.0f)//玉の縦幅

//===================================
// 
//コンストラクタ
//
//===================================
CPlayer_Bullet::CPlayer_Bullet()
{
	m_TargetPos;//ターゲットの位置
	m_nBulletLife;//弾の寿命処理
	bHoming = false;
}
//===================================
// 
//デスストラクタ
//
//===================================
CPlayer_Bullet::~CPlayer_Bullet()
{

}

//===================================
// 
//プレイヤーの弾の初期化処理
//
//===================================
HRESULT CPlayer_Bullet::Init(void)
{
	Load();
	//モデル設定
	CModel* pModel = CManager::GetModel();//取得
	m_nModelIdx = pModel->Regist("data\\misile.x");//登録
	DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//設定
	return S_OK;
}

//===================================
// 
//プレイヤーの弾の終了処理
//
//===================================
void CPlayer_Bullet::Uninit()
{
	CObject3D::Uninit();//this->Release();自身の開放
	m_bDeath = true;
}
//===================================
// 
//プレイヤーの弾の更新処理
//
//===================================
void CPlayer_Bullet::Update()
{
	if (bHoming == true)
	{
		m_move = (m_TargetPos - m_pos) * 0.3f;
	}

	m_pos += m_move;
	m_nBulletLife--;
	if (m_nBulletLife <= 0)
	{
		m_bDeath = true;
		return;
	}
	//else
	//{
	//	//頂点バッファをロックし、頂点データへのポインタを取得
	//	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//	//頂点座標の更新
	//	pVtx[0].pos = D3DXVECTOR3(m_pos.x - BULLET_SIZE_X / 2, m_pos.y - BULLET_SIZE_Y / 2, 0.0f);
	//	pVtx[1].pos = D3DXVECTOR3(m_pos.x + BULLET_SIZE_X / 2, m_pos.y - BULLET_SIZE_Y / 2, 0.0f);
	//	pVtx[2].pos = D3DXVECTOR3(m_pos.x - BULLET_SIZE_X / 2, m_pos.y + BULLET_SIZE_Y / 2, 0.0f);
	//	pVtx[3].pos = D3DXVECTOR3(m_pos.x + BULLET_SIZE_X / 2, m_pos.y + BULLET_SIZE_Y / 2, 0.0f);

	//	//頂点バッファをアンロックする
	//	m_pVtxBuff->Unlock();
	//}

	//if(m_pos = D3DXVECTOR3(0.0f, 585.0f, 0.0f) || nLife = 0)
	//{
	//	CExplosion::Create(m_pos, m_col);//爆発生成
	//	CObject::Release();//自信を削除
	//	return;
	//}
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
				//CPlayer_Bullet::BULLETTYPE Bullettype = m_Bullettype;
				if (CObject::TYPE::HELICOPTER == pObj->GetType())
				{
					/*if (Bullettype == CPlayer_Bullet::BULLETTYPE::BULLETTYPE_PLAYER)
					{*/
						CHelicopter* pHelicopter = (CHelicopter*)pObj;
						D3DXVECTOR3 HelicopterPos = pHelicopter->GetPos();//位置の取得
						D3DXVECTOR3 vec = m_TargetPos - m_pos;
						//m_pos += vec / 10.0f;

						if (m_pos.x >= HelicopterPos.x - 35.0f
							&& m_pos.x <= HelicopterPos.x + 35.0f
							&& m_pos.z >= HelicopterPos.z - 35.0f
							&& m_pos.z <= HelicopterPos.z + 35.0f)
						{
							pHelicopter->Hit(1);
							//CExplosion::Create(m_pos, m_col);//爆発の生成
							//pEnemy->Uninit();//敵の終了処理
							CPlayer_Bullet::Uninit();//玉の終了処理
							//break;
						}

					//}
				}

				//if (CObject::TYPE::PLAYER)
				//{
				//	if (Bullettype == CBullet::BULLETTYPE::BULLETTYPE_HELICOPTER)
				//	{
				//		CPlayer* pPlayer = (CPlayer*)pObj;
				//		D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//位置の取得


				//		if (m_pos.x >= PlayerPos.x - 10.0f
				//			&& m_pos.x <= PlayerPos.x + 10.0f
				//			&& m_pos.z >= PlayerPos.z - 10.0f
				//			&& m_pos.z <= PlayerPos.z + 10.0f)
				//		{
				//			pPlayer->Hit(1);
				//			//CExplosion::Create(m_pos, m_col);//爆発の生成
				//			//pPlayer->Uninit();//プレイヤーの終了処理
				//			CBullet::Uninit();//玉の終了処理
				//			break;
				//		}

				//	}
				//}
				//if (CObject::TYPE::PLAYER)
				//{
				//	if (Bullettype == CBullet::BULLETTYPE::BULLETTYPE_TRUCK)
				//	{
				//		CPlayer* pPlayer = (CPlayer*)pObj;
				//		D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//位置の取得


				//		if (m_pos.x >= PlayerPos.x - 15
				//			&& m_pos.x <= PlayerPos.x + 15
				//			&& m_pos.z >= PlayerPos.z - 15
				//			&& m_pos.z <= PlayerPos.z + 15)
				//		{
				//			pPlayer->Hit(1);
				//			//CExplosion::Create(m_pos, m_col);//爆発の生成
				//			//pBlock->Uninit();//ブロックの終了処理
				//			CBullet::Uninit();//玉の終了処理
				//			break;

				//		}
				//	}
				//}
				// ポインタを次のポインタへ変更
				pObj = pNext;
			}
		//}


	//}
}

//===================================
// 
//プレイヤーの弾の描画処理
//
//===================================
void CPlayer_Bullet::Draw()
{
	CObject3D::Draw();//ポリゴン描画
}

//===================================
// 
//CPlayer_Bullet生成
//
//===================================
CPlayer_Bullet* CPlayer_Bullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nBulletLife)
{
	LPDIRECT3DDEVICE9 pDevice;
	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();
	CPlayer_Bullet* pPlayer_Bullet = new CPlayer_Bullet();
	pPlayer_Bullet->Init();
	pPlayer_Bullet->SetPos(pos);//生成位置設定
	pPlayer_Bullet->SetMove(move);
	pPlayer_Bullet->SetBulletLife(nBulletLife);
	float fNearDistance = 1000.0f;
	
	//LPDIRECT3DTEXTURE9 pTex;
	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	//{
	//	//敵との当たり判定（配列を順番にチェック）
	//	for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
			//オブジェクト取得
			CObject* pObj = CObject::GetMyObject();
			if (pObj != nullptr)
			{
				//種類の取得（敵なら当たり判定）
				CObject::TYPE type = pObj->GetType();
				if (type == CObject::TYPE::HELICOPTER)
				{
					CHelicopter* pHelicopter = (CHelicopter*)pObj;
					if (pHelicopter != nullptr)
					{
						D3DXVECTOR3 vec = pHelicopter->GetPos() - pPlayer_Bullet->m_pos;
						float fLength = D3DXVec3Length(&vec);
						if (fLength < fNearDistance)
						{
							fNearDistance = fLength;
							pPlayer_Bullet->m_TargetPos = pHelicopter->GetPos();
							pPlayer_Bullet->bHoming = true;
							//int n = 0;
							//break;
						}
					}
				}
			}
		//}
	//}

	//テクスチャの設定
	pPlayer_Bullet->BindMesh(pPlayer_Bullet->GetMatModel(), pPlayer_Bullet->GetBuffer(), pPlayer_Bullet->GetMesh(), nullptr);
	return pPlayer_Bullet;
}
//===================================
//
//プレイヤーの玉のロード処理
//
//===================================
HRESULT CPlayer_Bullet::Load()
{
	LPDIRECT3DDEVICE9 pDevice;
	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER Player_BulletBuffer = GetBuffer();
	DWORD Player_BulletMatModel = GetMatModel();
	LPD3DXMESH Player_BulletMesh = GetMesh();
	CPlayer_Bullet* pBullet = new CPlayer_Bullet();
	if (FAILED(D3DXLoadMeshFromX("data\\misile.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &Player_BulletBuffer, nullptr, &Player_BulletMatModel, &Player_BulletMesh)))
	{
		return E_FAIL;
	}
	SetBuffer(Player_BulletBuffer);
	SetMatModel(Player_BulletMatModel);
	SetMesh(Player_BulletMesh);
	return S_OK;
}
//===================================
// 
//プレイヤーの玉のアンロード処理
//
//===================================
void CPlayer_Bullet::Unload()
{
	CObject3D::Unload();
}
//===================================
//
//プレイヤーの玉のライフ設定
//
//===================================
void CPlayer_Bullet::SetBulletLife(int nBulletLife)
{
	m_nBulletLife = nBulletLife;
}