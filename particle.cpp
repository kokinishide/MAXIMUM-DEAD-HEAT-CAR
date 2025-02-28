//=============================================================================
//
// パーティクル処理 [particle.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "enemy.h"
//#include "title.h"
//#include "game.h"
//#include "result.h"
#include "bullet.h"
#include "explosion.h"
#include "bg.h"
#include "enemy.h"
#include "effect.h"
#include "particle.h"
#include "manager.h"

//===================================
// 
//コンストラクタ
//
//===================================
CParticle::CParticle(int nPriority) : CObject2D(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}
//===================================
// 
//デスストラクタ
//
//===================================
CParticle::~CParticle()
{

}
//===================================
// 
//パーティクルの初期化処理
// 
//===================================
HRESULT CParticle::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntParticle;

	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\particle.png", &m_pTexture);


	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		nullptr);

	VERTEX_2D* pVtx;
	//頂点バッファをロックし、頂点データへのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntParticle = 0; nCntParticle < MAX_PARTICLE; nCntParticle++)
	{
		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(-5.0f, 5.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(5.0f, 5.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-5.0f, -5.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(5.0f, -5.0f, 0.0f);

		//rhwの設定
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//テクスチャ座標の設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//1.0f
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//1.0f

		pVtx += 4; //頂点データのポインタを4つ分進める
	}
	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

//===================================
// 
//パーティクルの終了処理
// 
//===================================
void CParticle::Uninit()
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
//パーティクルの更新処理
// 
//===================================
void CParticle::Update()
{
	VERTEX_3D* pVtx; //頂点情報のポインタ
	//頂点バッファをロックし、頂点データへのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	int nCntParticle;
	D3DXVECTOR3 Pos = GetPos();
	D3DXVECTOR3 Move = GetMove();
	//for (nCntParticle = 0; nCntParticle < MAX_PARTICLE; nCntParticle++)
	//{
	//	if (g_aParticle[nCntParticle].bUse == true)
	//	{
	//		//頂点カラーの設定
	//		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//		//頂点座標の設定
	//		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//		pVtx[1].pos = D3DXVECTOR3(780.0f, 0.0f, 0.0f);
	//		pVtx[2].pos = D3DXVECTOR3(0.0f, 500.0f, 0.0f);
	//		pVtx[3].pos = D3DXVECTOR3(780.0f, 500.0f, 0.0f);

	//		if (g_aParticle[nCntParticle].nLife <= 0)
	//		{
	//			g_aParticle[nCntParticle].bUse = false;
	//		}
	//	}
	//	pVtx += 4;
	//}
	for (nCntParticle = 0; nCntParticle < MAX_PARTICLE; nCntParticle++)
	{
		
			//頂点座標の設定
			//pVtx[0].pos = D3DXVECTOR3(-g_aParticle[nCntParticle].fRadius,g_aParticle[nCntParticle].fRadius,0.0f);
			//pVtx[1].pos = D3DXVECTOR3(g_aParticle[nCntParticle].fRadius, g_aParticle[nCntParticle].fRadius, 0.0f);
			//pVtx[2].pos = D3DXVECTOR3(-g_aParticle[nCntParticle].fRadius, -g_aParticle[nCntParticle].fRadius, 0.0f);
			//pVtx[3].pos = D3DXVECTOR3(g_aParticle[nCntParticle].fRadius, -g_aParticle[nCntParticle].fRadius, 0.0f);

		Pos.x += Move.x;
		Pos.y += Move.y;
		Pos.z += Move.z;

			//頂点カラーの設定
			pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			/*g_aParticle[nCntParticle].nLife--;

			if (g_aParticle[nCntParticle].nLife <= 0)
			{
				g_aParticle[nCntParticle].bUse = false;
			}*/
		
		pVtx += 4;
	}
	SetPos(Pos);
	SetMove(Move);
	m_pVtxBuff->Unlock();
}
//===================================
// 
//パーティクルの描画処理
// 
//===================================
void CParticle::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntParticle;
	D3DXVECTOR3 Pos = GetPos();
	D3DXVECTOR3 Move = GetMove();
	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATRIX mtxTrans; //計算用マトリックス
	D3DXMATRIX mtxView;
	D3DXMATRIX mtxWorld;



	//aブレンディングを加算合成に設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));
	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//テクスチャの設定
	pDevice->SetTexture(0, m_pTexture);

	////テクスチャの設定
	//pDevice->SetTexture(0, g_pTextureParticle);
	for (nCntParticle = 0; nCntParticle < MAX_PARTICLE; nCntParticle++)
	{
		
			//ワールドマトリックスの初期化
			D3DXMatrixIdentity(&mtxWorld);


			//ビューマトリックスを取得
			pDevice->GetTransform(D3DTS_VIEW, &mtxView);

			//ポリゴンをカメラに対して正面に向ける
			D3DXMatrixInverse(&mtxWorld, NULL, &mtxView);//逆行列を求める

			mtxWorld._41 = 0.0f;
			mtxWorld._42 = 0.0f;
			mtxWorld._43 = 0.0f;



			////位置を反映
			D3DXMatrixTranslation(&mtxTrans, Pos.x, Pos.y, Pos.z);

			D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxTrans);
			//ワールドマトリックスの設定
			pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);


			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntParticle * 4, 2);
		
	}

	//aブレンディングを元に戻す
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	SetPos(Pos);
	SetMove(Move);
}
//===================================
//
//パーティクルの生成処理
//
//===================================
CParticle* CParticle::Create(const D3DXVECTOR3& pos)
{
	CParticle* pParticle = new CParticle();//パーティクル生成
	pParticle->Init();
	pParticle->SetType(CObject::PARTICLE);
	return pParticle;
}

//===================================
// 
//パーティクルの設定処理
// 
//===================================
//void SetParticle(D3DXVECTOR3 pos, int nType, D3DXVECTOR3 move, float fRadius)
//{
//	int nCntParticle;
//
//	for (nCntParticle = 0; nCntParticle < MAX_PARTICLE; nCntParticle++)
//	{
//		if (g_aParticle[nCntParticle].bUse == false)
//		{
//
//			g_aParticle[nCntParticle].pos = pos;
//			g_aParticle[nCntParticle].move = move;
//			g_aParticle[nCntParticle].fRadius = fRadius;
//			g_aParticle[nCntParticle].nLife = 100;
//			/*g_aParticle[nCntParticle].col = col;
//			g_aParticle[nCntParticle].fRadius = fRadius;*/
//			//g_aParticle[nCntParticle].nType = nType;
//			g_aParticle[nCntParticle].bUse = true;
//
//			break;
//		}
//	}
//}