//=============================================================================
//
// 背景処理 [bg.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "bg.h"
#include "manager.h"
#include "scene.h"
#include "title.h"
#include "result.h"
#include "object3D.h"
#include "tutoreal.h"
#include "tutoreal2.h"
#include "tutoreal3.h"
//#include "ground.h"

//マクロ定義
//#define NUM_BG	(1)	//背景の数

//===================================
// 
//コンストラクタ
//
//===================================
CBG::CBG(int nPriority) : CObject(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}
//===================================
// 
//デスストラクタ
//
//===================================
CBG::~CBG()
{

}

//===================================
// 
//背景の初期化処理
// 
//===================================
HRESULT CBG::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	//int nCntBG;

	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();
	//モードの取得（敵なら当たり判定）
	CScene::MODE mode = CManager::GetScene()->GetMode();
	
	SetType(CObject::TYPE::BG);
	switch (mode)
	{
	case CScene::MODE_TITLE: //タイトル画面
		D3DXCreateTextureFromFile(pDevice, "data\\title.png", &m_pTexture);
		break;
	//case CScene::MODE_TUTOREAL: //チュートリアル画面
	//	D3DXCreateTextureFromFile(pDevice, "data\\tutoreal1.png", &m_pTexture);
	//	break;
	//case CScene::MODE_TUTOREAL2: //チュートリアル2画面
	//	D3DXCreateTextureFromFile(pDevice, "data\\tutoreal message.png", &m_pTexture);
	//	break;
	//case CScene::MODE_TUTOREAL3: //チュートリアル3画面
	//	D3DXCreateTextureFromFile(pDevice, "data\\tutoreal sousa.png", &m_pTexture);
	//	break;
	case CScene::MODE_GAME: //ゲーム画面


		break;
	case CScene::MODE_RESULT: //リザルト画面
		if (CManager::GetScene()->GetEnd() == 0)
		{
			D3DXCreateTextureFromFile(pDevice, "data\\gameoverlife.png", &m_pTexture);
		}
		else if (CManager::GetScene()->GetEnd() == 1)
		{
			D3DXCreateTextureFromFile(pDevice, "data\\gameoverfalling.png", &m_pTexture);
		}
		else if (CManager::GetScene()->GetEnd() == 2)
		{
			D3DXCreateTextureFromFile(pDevice, "data\\stageclear.png", &m_pTexture);
		}
		break;

	}

//テクスチャの読み込み
	/*D3DXCreateTextureFromFile(pDevice, "data\\download.jpg", &m_pTexture);*/


	//頂点バッファの生成
	//pDevice = GetDevice();
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		nullptr);

	VERTEX_2D* pVtx;
	//頂点バッファをロックし、頂点データへのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);


	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1300.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 800.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1300.0f, 800.0f, 0.0f);

	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}
//===================================
// 
//背景の終了処理
// 
//===================================
void CBG::Uninit()
{
	//テクスチャの破棄
	if (m_pTexture != nullptr)
	{
		//m_pTexture->Release();
		m_pTexture = nullptr;
	}

	//頂点バッファの破棄
	if (m_pVtxBuff != nullptr)
	{
		//m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}

	//CObject::Release();
	m_bDeath = true;
}
//===================================
// 
//背景の更新処理
// 
//===================================
void CBG::Update()
{
	

				
	//VERTEX_2D* pVtx;
	//頂点バッファをロックし、頂点データへのポインタを取得
	//m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//nCounterAnimBG++; //カウンターを加算
	//if (nCounterAnimBG >= 18)
	//{
	//	nCounterAnimBG = 0;//カウンターを初期値に戻す
	//	nPatternAnimBG++;//パターンNo.を更新する
	//	if (nPatternAnimBG >= 18)
	//	{
	//		nPatternAnimBG = 0;//パターンNo.を初期値に戻す
	//	}

	//	//テクスチャ座標の更新
	//	pVtx[0].tex = D3DXVECTOR2(0.0f + nPatternAnimBG * 0.5f, 0.0f);
	//	pVtx[1].tex = D3DXVECTOR2(0.5f + nPatternAnimBG * 0.5f, 0.0f);
	//	pVtx[2].tex = D3DXVECTOR2(0.0f + nPatternAnimBG * 0.5f, 1.0f);//1.0f
	//	pVtx[3].tex = D3DXVECTOR2(0.5f + nPatternAnimBG * 0.5f, 1.0f);//1.0f

	//}
	//
	////頂点バッファをアンロックする
	//m_pVtxBuff->Unlock();
	
}
//===================================
// 
//背景の描画処理
// 
//===================================
void CBG::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));
	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);
	//テクスチャの設定
	pDevice->SetTexture(0, m_pTexture);

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

}
//===================================
//
//背景の生成処理
//
//===================================
CBG* CBG::Create()
{
	CBG* pBG = new CBG(2);//BG生成
	pBG->Init();
	//pBG->SetType(CObject::BG);
	return pBG;
}