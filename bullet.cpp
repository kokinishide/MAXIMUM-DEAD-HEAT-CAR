////=============================================================================
////
//// バレット処理 [bullet.cpp]
//// Author :: Koki_Nishide
////
////=============================================================================
//#include "main.h"
//#include "bullet.h"
//#include "player.h"
//#include "input.h"
//#include "explosion.h"
//#include "enemy.h"
//#include"manager.h"
//#include"object.h"
//#include"object2D.h"
//#include "block.h"
//#include"helicopter.h"
//
////===================================
//// 
////マクロ定義
////
////===================================
//#define BULLET_SIZE_X (50.0f)//玉の横幅
//#define BULLET_SIZE_Y (50.0f)//玉の縦幅
//
////===================================
//// 
////コンストラクタ
////
////===================================
//CBullet::CBullet()
//{
//
//}
////===================================
//// 
////デスストラクタ
////
////===================================
//CBullet::~CBullet()
//{
//
//}
//
////===================================
//// 
////弾の初期化処理
////
////===================================
//HRESULT CBullet::Init(void)
//{
//	
//	Load();
//	return S_OK;
//}
//
////===================================
//// 
////弾の終了処理
////
////===================================
//void CBullet::Uninit()
//{
//	CObject3D::Uninit();//this->Release();自身の開放
//	CObject::Release();
//}
////===================================
//// 
////弾の更新処理
////
////===================================
//void CBullet::Update()
//{
//	//VERTEX_2D* pVtx; //頂点情報のポインタ
//	m_pos += m_move;
//	m_nBulletLife--;
//	if (m_nBulletLife <= 0)
//	{
//		CObject::Release();
//		return;
//	}
//	//else
//	//{
//	//	//頂点バッファをロックし、頂点データへのポインタを取得
//	//	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
//
//	//	//頂点座標の更新
//	//	pVtx[0].pos = D3DXVECTOR3(m_pos.x - BULLET_SIZE_X / 2, m_pos.y - BULLET_SIZE_Y / 2, 0.0f);
//	//	pVtx[1].pos = D3DXVECTOR3(m_pos.x + BULLET_SIZE_X / 2, m_pos.y - BULLET_SIZE_Y / 2, 0.0f);
//	//	pVtx[2].pos = D3DXVECTOR3(m_pos.x - BULLET_SIZE_X / 2, m_pos.y + BULLET_SIZE_Y / 2, 0.0f);
//	//	pVtx[3].pos = D3DXVECTOR3(m_pos.x + BULLET_SIZE_X / 2, m_pos.y + BULLET_SIZE_Y / 2, 0.0f);
//
//	//	//頂点バッファをアンロックする
//	//	m_pVtxBuff->Unlock();
//	//}
//
//	//if(m_pos = D3DXVECTOR3(0.0f, 585.0f, 0.0f) || nLife = 0)
//	//{
//	//	CExplosion::Create(m_pos, m_col);//爆発生成
//	//	CObject::Release();//自信を削除
//	//	return;
//	//}
//	for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
//	{
//		//敵との当たり判定（配列を順番にチェック）
//		for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
//		{
//			//オブジェクト取得
//			CObject* pObj = CObject::GetMyObject(nCntPriority,nCntObj);
//			if (pObj != nullptr)
//			{
//				//種類の取得（敵なら当たり判定）
//				CObject::TYPE type = pObj->GetType();
//				CBullet::BULLETTYPE Bullettype = m_Bullettype;
//				if (type == CObject::TYPE::HELICOPTER)
//				{
//					if (Bullettype == CBullet::BULLETTYPE::BULLETTYPE_PLAYER)
//					{
//						CHelicopter* pHelicopter = (CHelicopter*)pObj;
//						D3DXVECTOR3 HelicopterPos = pHelicopter->GetPos();//位置の取得
//						D3DXVECTOR3 vec = m_TargetPos - m_pos;
//						m_pos += vec / 10.0f;
//
//						if (m_pos.x >= HelicopterPos.x - 35.0f
//							&& m_pos.x <= HelicopterPos.x + 35.0f
//							&& m_pos.z >= HelicopterPos.z - 35.0f
//							&& m_pos.z <= HelicopterPos.z + 35.0f)
//						{
//							pHelicopter->Hit(1);
//							//CExplosion::Create(m_pos, m_col);//爆発の生成
//							//pEnemy->Uninit();//敵の終了処理
//							CBullet::Uninit();//玉の終了処理
//							break;
//						}
//						
//					}
//				}
//
//				if (type == CObject::TYPE::PLAYER)
//				{
//					if (Bullettype == CBullet::BULLETTYPE::BULLETTYPE_HELICOPTER)
//					{
//						CPlayer* pPlayer = (CPlayer*)pObj;
//						D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//位置の取得
//						
//
//						if (m_pos.x >= PlayerPos.x - 10.0f
//							&& m_pos.x <= PlayerPos.x + 10.0f
//							&& m_pos.z >= PlayerPos.z - 10.0f
//							&& m_pos.z <= PlayerPos.z + 10.0f)
//						{
//							pPlayer->Hit(1);
//							//CExplosion::Create(m_pos, m_col);//爆発の生成
//							//pPlayer->Uninit();//プレイヤーの終了処理
//							CBullet::Uninit();//玉の終了処理
//							break;
//						}
//						
//					}
//				}
//				if (type == CObject::TYPE::PLAYER)
//				{
//					if (Bullettype == CBullet::BULLETTYPE::BULLETTYPE_TRUCK)
//					{
//						CPlayer* pPlayer = (CPlayer*)pObj;
//						D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//位置の取得
//
//
//						if (m_pos.x >= PlayerPos.x - 15
//							&& m_pos.x <= PlayerPos.x + 15
//							&& m_pos.z >= PlayerPos.z - 15
//							&& m_pos.z <= PlayerPos.z + 15)
//						{
//							pPlayer->Hit(1);
//							//CExplosion::Create(m_pos, m_col);//爆発の生成
//							//pBlock->Uninit();//ブロックの終了処理
//							CBullet::Uninit();//玉の終了処理
//							break;
//							
//						}
//					}
//				}
//			}
//		}
//			
//		
//	}
//}
//
////===================================
//// 
////弾の描画処理
////
////===================================
//void CBullet::Draw()
//{
//	CObject3D::Draw();//ポリゴン描画
//}
//
////===================================
//// 
////CBullet生成
////
////===================================
//CBullet* CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nBulletLife, BULLETTYPE type)
//{
//	LPDIRECT3DDEVICE9 pDevice;
//	//デバイスの取得
//	pDevice = CManager::GetRenderer()->GetDevice();
//	CBullet* pBullet = new CBullet();
//	
//	
//	pBullet->Init();
//	pBullet->SetPos(pos);//生成位置設定
//	pBullet->SetMove(move);
//	pBullet->SetBulletLife(nBulletLife);
//	pBullet->SetBulletType(type);
//	float fNearDistance = 10000.0f;
//	//LPDIRECT3DTEXTURE9 pTex;
//	for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
//	{
//		//敵との当たり判定（配列を順番にチェック）
//		for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
//		{
//			//オブジェクト取得
//			CObject* pObj = CObject::GetMyObject(nCntPriority, nCntObj);
//			if (pObj != nullptr)
//			{
//				
//				CEnemy* pEnemy = (CEnemy*)pObj;
//				if (pEnemy != nullptr)
//				{
//					D3DXVECTOR3 vec = pBullet->m_TargetPos - pEnemy->GetPos();
//					float fLength = D3DXVec3Length(&vec);
//					if (fLength > fNearDistance)
//					{
//						pBullet->m_TargetPos = pEnemy->GetPos();
//					}
//				}
//					
//				
//			}
//		}
//	}
//
//	//テクスチャの設定
//	pBullet->BindMesh(pBullet->GetMatModel(), pBullet->GetBuffer(), pBullet->GetMesh(),nullptr);
//	return pBullet;
//}
////===================================
////
////玉のロード処理
////
////===================================
//HRESULT CBullet::Load()
//{
//	LPDIRECT3DDEVICE9 pDevice;
//	//デバイスの取得
//	pDevice = CManager::GetRenderer()->GetDevice();
//	LPD3DXBUFFER BulletBuffer = GetBuffer();
//	DWORD BulletMatModel = GetMatModel();
//	LPD3DXMESH BulletMesh = GetMesh();
//	/*if (FAILED(D3DXLoadMeshFromX("data\\misile.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &BulletBuffer, nullptr, &BulletMatModel, &BulletMesh)))
//	{
//		return E_FAIL;
//	}*/
//	
//	SetBuffer(BulletBuffer);
//	SetMatModel(BulletMatModel);
//	SetMesh(BulletMesh);
//	return S_OK;
//}
////===================================
//// 
////玉のアンロード処理
////
////===================================
//void CBullet::Unload()
//{
//	CObject3D::Unload();
//}
////===================================
////
////玉のライフ設定
////
////===================================
//void CBullet::SetBulletLife(int nBulletLife)
//{
//	m_nBulletLife = nBulletLife;
//}
//
////===================================
//// 
////玉のタイプ設定
////
////===================================
//void CBullet::SetBulletType(BULLETTYPE Bullettype)
//{
//	m_Bullettype = Bullettype;
//}