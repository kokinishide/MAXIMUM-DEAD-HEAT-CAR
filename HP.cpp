//=============================================================================
//
// HP文字表示処理 [HP.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "HP.h"
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
CHP::CHP(int nPriority) : CObject2D(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}
//===================================
// 
//デスストラクタ
//
//===================================
CHP::~CHP()
{

}

//===================================
// 
//HP文字の初期化処理
// 
//===================================
HRESULT CHP::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();
	SetType(CObject::TYPE::HP);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\HP.png", &m_pTexture);
	//モデル設定
	//CTexture* pTexure = CManager::GetTexture();//取得
	//m_nTextureIdx = pTexure->Regist("data\\HP.png");//登録
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
	pVtx[0].pos = D3DXVECTOR3(0.0f, 600.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 700.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);

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
//HP文字の終了処理
// 
//===================================
void CHP::Uninit()
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
//HP文字の更新処理
// 
//===================================
void CHP::Update()
{
	
}
//===================================
// 
//HP文字の描画処理
// 
//===================================
void CHP::Draw()
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
//HP文字の生成処理
//
//===================================
CHP* CHP::Create(const D3DXVECTOR3& pos)
{
	CHP* pHP = new CHP(1);//HP文字生成
	pHP->Init();
	//pHP->SetType(CObject::HP);
	return pHP;
}