////=============================================================================
////
//// オブジェクトX処理 [objectX.cpp]
//// Author :: Koki_Nishide
////
////=============================================================================
//#include "main.h"
//#include "player.h"
//#include "input.h"
//#include "manager.h"
//#include "object3D.h"
//#include "objectX.h"
//
//
//
////コンストラクタ
//CObjectX::CObjectX()
//{
//	 m_pVtxBuff = nullptr;//頂点バッファ
//	 m_pMesh = nullptr; //メッシュ（頂点情報）へのポインタ
//	 m_pBuffMat = nullptr; //マテリアルへのポインタ
//	 m_dwNumMat = 0; //マテリアルの数
//	 for (int nCnt = 0; nCnt < MAX_MOTION_TEXTURE; nCnt++)
//	 {
//		 m_pTexture[nCnt] = nullptr;
//		 
//	 }
//	 m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//	 m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//}
////デスストラクタ
//CObjectX::~CObjectX()
//{
//
//}
//
//
////初期設定
//HRESULT CObjectX::Init()
//{
//	LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
//	//デバイスの取得
//	pDevice = CManager::GetRenderer()->GetDevice();
//
//	return S_OK;
//}
//
////モデルパーツの終了処理
//void CObjectX::Uninit()
//{
//	//メッシュの破棄
//	if (m_pMesh != nullptr)
//	{
//		m_pMesh->Release();
//		m_pMesh = nullptr;
//
//	}
//	//マテリアルの破棄
//	if (m_pBuffMat != nullptr)
//	{
//		m_pBuffMat->Release();
//		m_pBuffMat = nullptr;
//	}
//	for (int nCnt = 0; nCnt < MAX_MOTION_TEXTURE; nCnt++)
//	{
//		//テクスチャの開放
//		if (m_pTexture[nCnt] != nullptr)
//		{
//			delete m_pTexture[nCnt];
//			m_pTexture[nCnt] = nullptr;
//		}
//	}
//	CObject::Release();
//}
//
////モデルパーツの更新処理
//void CObjectX::Update()
//{
//	//LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
//	////デバイスの取得
//	//pDevice = CManager::GetRenderer()->GetDevice();
//	////親の行列を取得する
//	//D3DXMATRIX mtxParent;
//	//if (m_pParent != nullptr)
//	//{
//	//	//親のワールド変換行列を取得
//	//	mtxParent = m_pParent->GetWorldMatrix();
//	//}
//	//else
//	//{
//	//	//最新のワールド変換行列を取得(=プレイヤーの行列)
//	//	pDevice->GetTransform(D3DTS_WORLD, &mtxParent);
//	//}
//}
//
////モデルパーツの描画処理
//void CObjectX::Draw()
//{
//	CObject::Draw();//ポリゴン描画
//}
//void CObjectX::SetPos(D3DXVECTOR3 pos)
//{
//	m_pos = pos;
//	
//}
//void CObjectX::SetRot(D3DXVECTOR3 rot)
//{
//	m_rot = rot;
//}
//
//CObjectX* CObjectX::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, LPD3DXMESH pMesh, LPD3DXBUFFER pBuffMat, DWORD dwNumMat)
//{
//	CObjectX* pObjectX = nullptr;
//	pObjectX = new CObjectX();
//	if (FAILED(pObjectX->Init())) {
//		pObjectX->Uninit();
//		return nullptr;
//	}
//	pObjectX->SetPos(pos);
//	pObjectX->SetRot(rot);
//	return pObjectX;
//}
