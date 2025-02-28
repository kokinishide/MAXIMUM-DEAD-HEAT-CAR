//=============================================================================
//
// 真ん中通路メッセージ表示処理 [middle_message.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "middle_message.h"
#include "manager.h"

//===================================
// 
//コンストラクタ
//
//===================================
CMiddle_Message::CMiddle_Message(int nPriority) : CObject2D(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}
//===================================
// 
//デスストラクタ
//
//===================================
CMiddle_Message::~CMiddle_Message()
{

}

//===================================
// 
//真ん中通路メッセージの初期化処理
// 
//===================================
HRESULT CMiddle_Message::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();
	SetType(CObject::TYPE::MIDDLE_MESSAGE);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\middle.png", &m_pTexture);
	//モデル設定
	//CTexture* pTexure = CManager::GetTexture();//取得
	//m_nTextureIdx = pTexure->Regist("data\\middle.png");//登録
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
//真ん中通路メッセージの終了処理
// 
//===================================
void CMiddle_Message::Uninit()
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
//真ん中通路メッセージの更新処理
// 
//===================================
void CMiddle_Message::Update()
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
					VERTEX_2D* pVtx;
					//頂点バッファをロックし、頂点データへのポインタを取得
					m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

					if (PlayerPos.z >= 17020.0f)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(530.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(930.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(530.0f, 200.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(930.0f, 200.0f, 0.0f);
					}
					if (PlayerPos.z >= 17900.0f)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					}
					if (PlayerPos.z >= 29500.0f)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(530.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(930.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(530.0f, 200.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(930.0f, 200.0f, 0.0f);
					}
					if (PlayerPos.z >= 30900.0f)
					{
						//頂点座標の設定
						pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					}

					nCounterAnimJump++; //カウンターを加算
					if (nCounterAnimJump >= 2)
					{
						nCounterAnimJump = 0;//カウンターを初期値に戻す
						nPatternAnimJump++;//パターンNo.を更新する
						if (nPatternAnimJump >= 2)
						{
							nPatternAnimJump = 0;//パターンNo.を初期値に戻す
						}

						//テクスチャ座標の更新
						pVtx[0].tex = D3DXVECTOR2(0.0f + nPatternAnimJump * 0.5f, 0.0f);
						pVtx[1].tex = D3DXVECTOR2(0.5f + nPatternAnimJump * 0.5f, 0.0f);
						pVtx[2].tex = D3DXVECTOR2(0.0f + nPatternAnimJump * 0.5f, 1.0f);//1.0f
						pVtx[3].tex = D3DXVECTOR2(0.5f + nPatternAnimJump * 0.5f, 1.0f);//1.0f

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
//真ん中通路メッセージの描画処理
// 
//===================================
void CMiddle_Message::Draw()
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
//真ん中通路メッセージの生成処理
//
//===================================
CMiddle_Message* CMiddle_Message::Create(const D3DXVECTOR3& pos)
{
	CMiddle_Message* pMiddle_Message = new CMiddle_Message(1);//Middle_Message生成
	pMiddle_Message->Init();
	//pMiddle_Message->SetType(CObject::MIDDLE_MESSAGE);
	return pMiddle_Message;
}