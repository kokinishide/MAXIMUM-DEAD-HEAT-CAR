////=============================================================================
////
//// モデルパーツ処理 [modelparts.cpp]
//// Author :: Koki_Nishide
////
////=============================================================================
//#include "main.h"
//#include "player.h"
//#include "input.h"
//#include "manager.h"
//#include "modelparts.h"
//#include "object3D.h"
//
//
////コンストラクタ
//CModelParts::CModelParts()
//{
//	m_MotionPos = D3DXVECTOR3(0.0f,0.0f,0.0f);
//	m_MotionRot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//}
////デスストラクタ
//CModelParts::~CModelParts()
//{
//
//}
//
//
////初期設定
//HRESULT CModelParts::Init()
//{
//	LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
//	//デバイスの取得
//	pDevice = CManager::GetRenderer()->GetDevice();
//
//	//Xファイルの読み込み
//	//D3DXLoadMeshFromX("data\\MODEL\\00_body.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMatModelParts, NULL, &m_dwNumMatModelParts, &m_pMeshModelParts);
//	
//
//	//CObject::SetType(PLAYER);
//	return S_OK;
//}
//
////モデルパーツの終了処理
//void CModelParts::Uninit()
//{
//	CObject::Uninit();//this->Release();自身の開放
//}
//
////モデルパーツの更新処理
//void CModelParts::Update()
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
//void CModelParts::Draw()
//{
//	CObject::Draw();//ポリゴン描画
//}
//void CModelParts::SetMotionPos(D3DXVECTOR3 pos)
//{
//	m_MotionPos = pos;
//
//}
//void CModelParts::SetMotionRot(D3DXVECTOR3 rot)
//{
//	m_MotionRot = rot;
//}
//
//CModelParts* CModelParts::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, LPD3DXMESH pMesh, LPD3DXBUFFER pBuffMat, DWORD dwNumMat)
//{
//	CModelParts* pModelParts = nullptr;
//	pModelParts = new CModelParts();
//	if (FAILED(pModelParts->Init())) {
//		pModelParts->Uninit();
//		return nullptr;
//	}
//	pModelParts->SetPos( pos);
//	pModelParts->SetRot( rot);
//	return pModelParts;
//}
