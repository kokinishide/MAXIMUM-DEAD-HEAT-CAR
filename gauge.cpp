//=============================================================================
//
// ゲージ表示処理 [gauge.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "gauge.h"
#include "manager.h"
#include "scene.h"
#include "title.h"
#include "result.h"
#include "object3D.h"

//===================================
// 
//コンストラクタ
//
//===================================
CGauge::CGauge(int nPriority) : CObject2D(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}
//===================================
// 
//デスストラクタ
//
//===================================
CGauge::~CGauge()
{

}

//===================================
// 
//ゲージの初期化処理
// 
//===================================
HRESULT CGauge::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();
	SetType(CObject::TYPE::GAUGE);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\playergauge.png", &m_pTexture);
	//モデル設定
	//CTexture* pTexure = CManager::GetTexture();//取得
	//m_nTextureIdx = pTexure->Regist("data\\playergauge.png");//登録
	//LPDIRECT3DTEXTURE9 pTex = pTexure->GetAddress(m_nTextureIdx);
	//BindTexture(pTex);//設定

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
	pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(900.0f, 600.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(900.0f, 700.0f, 0.0f);

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
//ゲージの終了処理
// 
//===================================
void CGauge::Uninit()
{
	//テクスチャの破棄
	if (m_pTexture != nullptr)
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
	}

	//頂点バッファの破棄
	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}

	//CObject::Release();
	m_bDeath = true;
}
//===================================
// 
//ゲージの更新処理
// 
//===================================
void CGauge::Update()
{
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

				if (CObject::PLAYER == pObj->GetType())
				{
					CPlayer* pPlayer = (CPlayer*)pObj;
					D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//位置の取得
					int PlayerLife = pPlayer->GetLife();//ライフの取得
					VERTEX_2D* pVtx;
					//頂点バッファをロックし、頂点データへのポインタを取得
					m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

					if (pPlayer->GetLife() <= 15)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(850.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(850.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 14)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(800.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(800.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 13)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(750.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(750.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 12)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(700.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(700.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 11)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(650.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(650.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 10)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(600.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(600.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 9)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(550.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(550.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 8)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(500.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(500.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 7)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(450.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(450.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 6)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(400.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(400.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 5)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(350.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(350.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 4)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(300.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(300.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 3)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(250.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(250.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 2)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(200.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(200.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 1)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(150.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(150.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 0)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
					}

					//頂点バッファをアンロックする
					m_pVtxBuff->Unlock();
				}
				// ポインタを次のポインタへ変更
				pObj = pNext;
			}
		//}
	//}
}
//===================================
// 
//ゲージの描画処理
// 
//===================================
void CGauge::Draw()
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
//ゲージの生成処理
//
//===================================
CGauge* CGauge::Create(const D3DXVECTOR3& pos)
{
	CGauge* pGauge = new CGauge(1);//Gauge生成
	pGauge->Init();
	//pGauge->SetType(CObject::GAUGE);
	return pGauge;
}