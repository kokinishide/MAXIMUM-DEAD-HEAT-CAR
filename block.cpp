//=============================================================================
//
// ブロック処理 [block.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "block.h"
#include "bullet.h"
#include "explosion.h"
#include "object2D.h"
#include "manager.h"
#include "enemy.h"
//#include "game.h"
//#include "score.h"


//マクロ定義
#define NUM_BLOCK	(4) //ブロックの種類

//===================================
// 
//コンストラクタ
//
//===================================
CBlock::CBlock()
{

}
//===================================
// 
//デスストラクタ
//
//===================================
CBlock::~CBlock()
{

}


//===================================
// 
//ブロックの初期化処理
// 
//===================================
HRESULT CBlock::Init()
{
	if (FAILED(CObject3D::Init()))//頂点バッファ作成
	{//失敗
		return E_FAIL;
	}
	Load();
	CBlock::m_nLife = 3;
	//頂点情報設定に必要な
	//短形サイズなどのパラメータ設定
	CObject3D::SetSizeW(40.0f);
	CObject3D::SetSizeH(40.0f);
	SetType(CObject::TYPE::BLOCK);
	return S_OK;//成功

}

//===================================
// 
//ブロックのヒット処理
//
//===================================
void CBlock::Hit(int nDamage)
{
	CObject3D::Hit(nDamage);
}
//===================================
// 
//ブロックの終了処理
// 
//===================================
void CBlock::Uninit()
{
	CObject3D::Uninit();//this->Release();自身の開放
}

//===================================
// 
//ブロックの更新処理
// 
//===================================
void CBlock::Update()
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
				pObj->GetType();
				if (CObject::TYPE::PLAYER)
				{
					CPlayer* pPlayer = (CPlayer*)pObj;
					D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//位置の取得
					D3DXVECTOR3 PlayerPosOld = pPlayer->GetPosOld();//古い位置の取得
					D3DXVECTOR3 PlayerMove = pPlayer->GetMove();//動きの取得

					
						if (PlayerPosOld.x <= m_pos.x - 20.0f
						&& PlayerPos.x > m_pos.x - 20.0f
						&& PlayerPos.y > m_pos.y - 10.0f
						&& PlayerPos.y < m_pos.y + 10.0f
						&& PlayerPos.z > m_pos.z - 130.0f
						&& PlayerPos.z < m_pos.z + 130.0f)
						{
						//bIsLanding = true;
						PlayerPos.x = m_pos.x - 20.0f;
						PlayerMove.x = 0.0f;

						pPlayer->SetPos(PlayerPos); //位置を設定
						pPlayer->SetMove(PlayerMove); //動きを設定
						//pPlayer->SetIsLanding(bIsLanding); //着地を設定

						}
						if (PlayerPosOld.x >= m_pos.x + 20.0f
							&& PlayerPos.x < m_pos.x + 20.0f
							&& PlayerPos.y < m_pos.y + 10.0f
							&& PlayerPos.y > m_pos.y - 10.0f
							&& PlayerPos.z < m_pos.z + 130.0f
							&& PlayerPos.z > m_pos.z - 130.0f)
						{
							//bIsLanding = true;
							PlayerPos.x = m_pos.x + 20.0f;
							PlayerMove.x = 0.0f;

							pPlayer->SetPos(PlayerPos); //位置を設定
							pPlayer->SetMove(PlayerMove); //動きを設定
							//pPlayer->SetIsLanding(bIsLanding); //着地を設定
						}
						//if (PlayerPosOld.y <= m_pos.y - 20.0f
						//&& PlayerPos.y > m_pos.y - 20.0f
						//&& PlayerPos.x > m_pos.x - 10.0f
						//&& PlayerPos.x < m_pos.x + 10.0f
						//&& PlayerPos.z > m_pos.z - 130.0f
						//&& PlayerPos.z < m_pos.z + 130.0f)
						//{
						//	bIsLanding = true;
						//	PlayerPos.y = m_pos.y - 20.0f;
						//	PlayerMove.y = 0.0f;

						//	pPlayer->SetPos(PlayerPos); //位置を設定
						//	pPlayer->SetMove(PlayerMove); //動きを設定
						//	pPlayer->SetIsLanding(bIsLanding); //着地を設定
						//}
						if (PlayerPosOld.y >= m_pos.y + 50.0f
							&& PlayerPos.y < m_pos.y + 50.0f
							&& PlayerPos.x < m_pos.x + 10.0f
							&& PlayerPos.x > m_pos.x - 10.0f
							&& PlayerPos.z < m_pos.z + 130.0f
							&& PlayerPos.z > m_pos.z - 130.0f)
						{
							bIsLanding = true;
							PlayerPos.y = m_pos.y + 50.0f;
							PlayerMove.y = 0.0f;

							pPlayer->SetPos(PlayerPos); //位置を設定
							pPlayer->SetMove(PlayerMove); //動きを設定
							pPlayer->SetIsLanding(bIsLanding); //着地を設定
						}
				}
				if (CObject::TYPE::ENEMY)
				{
					CEnemy* pEnemy = (CEnemy*)pObj;
					D3DXVECTOR3 EnemyPos = pEnemy->GetPos();//位置の取得
					D3DXVECTOR3 EnemyPosOld = pEnemy->GetPosOld();//古い位置の取得
					D3DXVECTOR3 EnemyMove = pEnemy->GetMove();//動きの取得

					if (EnemyPosOld.x <= m_pos.x - 20.0f
						&& EnemyPos.x > m_pos.x - 20.0f
						&& EnemyPos.y > m_pos.y - 10.0f
						&& EnemyPos.y < m_pos.y + 10.0f
						&& EnemyPos.z > m_pos.z - 130.0f
						&& EnemyPos.z < m_pos.z + 130.0f)
					{
						//bIsLanding = true;
						EnemyPos.x = m_pos.x - 20.0f;
						EnemyMove.x = 0.0f;

						pEnemy->SetPos(EnemyPos); //位置を設定
						pEnemy->SetMove(EnemyMove); //動きを設定
						//pEnemy->SetIsLanding(bIsLanding); //着地を設定

					}
					if (EnemyPosOld.x >= m_pos.x + 20.0f
						&& EnemyPos.x < m_pos.x + 20.0f
						&& EnemyPos.y < m_pos.y + 10.0f
						&& EnemyPos.y > m_pos.y - 10.0f
						&& EnemyPos.z < m_pos.z + 130.0f
						&& EnemyPos.z > m_pos.z - 130.0f)
					{
						//bIsLanding = true;
						EnemyPos.x = m_pos.x + 20.0f;
						EnemyMove.x = 0.0f;

						pEnemy->SetPos(EnemyPos); //位置を設定
						pEnemy->SetMove(EnemyMove); //動きを設定
						//pPlayer->SetIsLanding(bIsLanding); //着地を設定
					}
					//if (PlayerPosOld.y <= m_pos.y - 20.0f
					//&& PlayerPos.y > m_pos.y - 20.0f
					//&& PlayerPos.x > m_pos.x - 10.0f
					//&& PlayerPos.x < m_pos.x + 10.0f
					//&& PlayerPos.z > m_pos.z - 130.0f
					//&& PlayerPos.z < m_pos.z + 130.0f)
					//{
					//	bIsLanding = true;
					//	PlayerPos.y = m_pos.y - 20.0f;
					//	PlayerMove.y = 0.0f;

					//	pPlayer->SetPos(PlayerPos); //位置を設定
					//	pPlayer->SetMove(PlayerMove); //動きを設定
					//	pPlayer->SetIsLanding(bIsLanding); //着地を設定
					//}
					if (EnemyPosOld.y >= m_pos.y + 50.0f
						&& EnemyPos.y < m_pos.y + 50.0f
						&& EnemyPos.x < m_pos.x + 10.0f
						&& EnemyPos.x > m_pos.x - 10.0f
						&& EnemyPos.z < m_pos.z + 130.0f
						&& EnemyPos.z > m_pos.z - 130.0f)
					{
						bIsLanding = true;
						EnemyPos.y = m_pos.y + 50.0f;
						EnemyMove.y = 0.0f;

						pEnemy->SetPos(EnemyPos); //位置を設定
						pEnemy->SetMove(EnemyMove); //動きを設定
						pEnemy->SetIsLanding(bIsLanding); //着地を設定
					}
				}
				// ポインタを次のポインタへ変更
				pObj = pNext;
			}
		//}
	//}
}

//===================================
// 
//ブロックの描画処理
// 
//===================================
void CBlock::Draw()
{
	CObject3D::Draw();//ポリゴン描画
}
//===================================
// 
//CBlock生成
//
//===================================
CBlock* CBlock::Create(const D3DXVECTOR3& pos)
{
	CBlock* pBlock = nullptr;
	pBlock = new CBlock();
	if (FAILED(pBlock->Init())) {
	}
	pBlock->SetPos(pos);
	pBlock->BindMesh(pBlock->GetMatModel(), pBlock->GetBuffer(), pBlock->GetMesh(),nullptr);
	//pBlock->SetType(CObject::TYPE::BLOCK);
	return pBlock;
}
//===================================
//
//ブロックのロード処理
//
//===================================
HRESULT CBlock::Load()
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER BlockBuffer = GetBuffer();
	DWORD BlockMatModel = GetMatModel();
	LPD3DXMESH BlockMesh = GetMesh();
	if (FAILED(D3DXLoadMeshFromX("data\\guardleale.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &BlockBuffer, nullptr, &BlockMatModel, &BlockMesh)))
	{
		return E_FAIL;
	}
	SetBuffer(BlockBuffer);
	SetMatModel(BlockMatModel);
	SetMesh(BlockMesh);
	return S_OK;
}
//===================================
//
//ブロックのアンロード処理
//
//===================================
void CBlock::Unload()
{
	CObject3D::Unload();
}


////タイプ設定
//void CBlock::SetBulletType(BULLETTYPE type)
//{
//	m_type = type;
//}