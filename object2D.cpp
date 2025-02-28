//=============================================================================
//
// オブジェクト2D処理 [object2D.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include<stdio.h>
#include"object2D.h"
#include "renderer.h"
#include "manager.h"
#include"main.h"

//===================================
// 
//コンストラクタ
//
//===================================
CObject2D::CObject2D()
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;

	/*m_pos.x = 80.0f;
	m_pos.y = 560.0f;*/

	m_sizeW = 1280.0f;
	m_sizeH = 720.0f;
}
//===================================
//
//コンストラクタ(プライオリティ)
//
//===================================
CObject2D::CObject2D(int nPriority) : CObject(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;

	/*m_pos.x = 80.0f;
	m_pos.y = 560.0f;*/

	m_sizeW = 1280.0f;
	m_sizeH = 720.0f;
}
//===================================
// 
//デスストラクタ
//
//===================================
CObject2D::~CObject2D()
{

}
//===================================
// 
//オブジェクト2Dの初期設定（頂点バッファ生成）
//
//===================================
HRESULT CObject2D::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();
	////テクスチャの読み込み
	//D3DXCreateTextureFromFile(pDevice, "data\\download.jpg", &m_pTexture);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D* pVtx;
	//頂点バッファをロックし、頂点データへのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);


	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);

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
//オブジェクト2Dの終了処理（頂点バッファ破棄）
//
//===================================
void CObject2D::Uninit()
{
	//if (m_pTexture != NULL)
	//{
	//	m_pTexture->Release();
	//	m_pTexture = NULL;
	//}

	//頂点バッファの破棄
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//CObject::Release();
	m_bDeath = true;
}
//===================================
// 
//オブジェクト2Dの更新処理（頂点情報の更新）
//
//===================================
void CObject2D::Update()
{
	VERTEX_2D* pVtx;

	//CObject::TYPE type = GetType();

	//頂点バッファをロックし、頂点データへのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);


	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_sizeW, m_pos.y - m_sizeH, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_sizeW, m_pos.y - m_sizeH, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_sizeW, m_pos.y + m_sizeH, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_sizeW, m_pos.y + m_sizeH, 0.0f);

	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;
	if (GetType() == CObject::TYPE::FADE)
	{
		int n = 0;
	}
	//弾の寿命を減らす処理
	//nLife -= 1;
	//if (nLife <= 0)//寿命が尽きた
	//{
	//	CExplosion::Uninit();
	//}
	nCounterAnim++; //カウンターを加算
	if (nCounterAnim >= 10)
	{
		nCounterAnim = 0;//カウンターを初期値に戻す
		nPatternAnim++;//パターンNo.を更新する
		if (nPatternAnim >= 8)
		{
			nPatternAnim = 0;//パターンNo.を初期値に戻す
		}

		//テクスチャ座標の更新
		pVtx[0].tex = D3DXVECTOR2(0.0f + nPatternAnim * 0.125f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.125f + nPatternAnim * 0.125f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f + nPatternAnim * 0.125f, 1.0f);//1.0f
		pVtx[3].tex = D3DXVECTOR2(0.125f + nPatternAnim * 0.125f, 1.0f);//1.0f

	}

	//-50.-50.+50.+25.+25

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();


}
//===================================
// 
//オブジェクト2Dの描画処理（ポリゴン描画）
//
//===================================
void CObject2D::Draw()
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
//オブジェクト2Dの生成処理
//
//===================================
CObject2D* CObject2D::Create()
{
	CObject2D* pObject2D = new CObject2D();//2Dオブジェクト生成
	pObject2D->Init();
	return pObject2D;
}
//===================================
// 
//テクスチャ設定
//
//===================================
void CObject2D::BindTexture(LPDIRECT3DTEXTURE9 pTex)
{
	m_pTexture = pTex;
}

//===================================
//
//位置設定
//
//===================================
void CObject2D::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;

}
//void CObject2D::SetPosX(float x)
//{
//	m_pos.x = x;
//}
//void CObject2D::SetPosY(float y)
//{
//	m_pos.y = y;
//}
//===================================
//
//動き設定
//
//===================================
void CObject2D::SetMove(D3DXVECTOR3 move)
{
	m_move = move;
}
//===================================
//
//幅のサイズ設定
//
//===================================
void CObject2D::SetSizeW(float w)
{
	m_sizeW = w;
}
//===================================
//
//高さのサイズ設定
//
//===================================
void CObject2D::SetSizeH(float h)
{
	m_sizeH = h;
}
