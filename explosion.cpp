////=============================================================================
////
//// 爆発処理 [explosion.cpp]
//// Author :: Koki_Nishide
////
////=============================================================================
//#include "main.h"
//#include "player.h"
//#include "input.h"
//#include "explosion.h"
//#include "manager.h"
//#include "object2D.h"
//
////===================================
//// 
////マクロ定義
////
////===================================
//#define MAX_EXPLOSION (128) //爆発の最大数
////#define NUM_EXPLOSION (2) //爆発の種類
//
////===================================
//// 
////爆発の初期化処理
////
////===================================
//HRESULT CExplosion::Init(void)
//{
//	CObject2D::SetSizeW(40.0f);
//	CObject2D::SetSizeH(40.0f);
//	CObject2D::Init();
//	
//	return S_OK;
//}
////===================================
//// 
////爆発の終了処理
////
////===================================
//void CExplosion::Uninit()
//{
//	CObject2D::Uninit();
//	
//}
////===================================
//// 
////爆発の更新処理
////
////===================================
//void CExplosion::Update()
//{
//
//	CObject2D::Update();//頂点情報更新
//}
////===================================
//// 
////爆発の描画処理
////
////===================================
//void CExplosion::Draw()
//{
//	CObject2D::Draw();
//}
////===================================
//// 
////CExplosion生成
////
////===================================
//CExplosion* CExplosion::Create(D3DXVECTOR3 m_pos, D3DXCOLOR m_col)
//{
//	LPDIRECT3DDEVICE9 pDevice;
//	//デバイスの取得
//	pDevice = CManager::GetRenderer()->GetDevice();
//	CExplosion* pExplosion = new CExplosion();
//	pExplosion->Init();
//	pExplosion->SetPos(m_pos);//生成位置設定
//	LPDIRECT3DTEXTURE9 pTex;
//
//	//テクスチャの設定
//	D3DXCreateTextureFromFile(pDevice,
//		"data\\explosion000.png",
//		&pTex);
//	pExplosion->BindTexture(pTex);
//	return pExplosion;
//}
