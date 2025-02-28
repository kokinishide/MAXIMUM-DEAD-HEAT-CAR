//=============================================================================
//
// フェード処理 [fade.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "enemy.h"
#include "fade.h"
#include "game.h"
#include "result.h"
#include"object2D.h"
#include "manager.h"
#include"scene.h"
//#include "sound.h"

LPDIRECT3DTEXTURE9 CFade::m_pTextureFade = nullptr;//テクスチャ
//===================================
//
//コンストラクタ
// 
//===================================
CFade::CFade() : CObject2D(4)
{
	m_pTextureFade = nullptr;
}
//===================================
//
//コンストラクタ(プライオリティ)
//
//===================================
CFade::CFade(int nPriority) : CObject2D(4)
{
	m_pTextureFade = nullptr;
}

//===================================
//
//デストラクタ
//
//===================================
CFade::~CFade()
{
}
//===================================
// 
//フェードの初期化処理
//
//===================================
HRESULT CFade::Init(void)
{
	
	m_colora = 1.0f;

	m_nfade = FADE_IN;
	CObject2D::Init();
	SetCol(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	//m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	SetType(CObject::TYPE::FADE);
	return S_OK;
}

//===================================
// 
//フェードの終了処理
// 
//===================================
void CFade::Uninit()
{
	//サウンドの停止
	//StopSound();

	//if (m_pVtxBuff != NULL)
	//{
	//	m_pVtxBuff->Release();
	//	m_pVtxBuff = NULL;
	//}


	//CObject2D::Uninit();
}
//===================================
// 
//フェードの更新処理
// 
//===================================
void CFade::Update()
{

	LPDIRECT3DDEVICE9 pDevice;//デバイスへのポインタ

	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();

	CObject2D::Update();

	if (m_nfade != FADE_NONE)
	{
		if (m_nfade == FADE_IN)
		{//フェードイン状態
			m_colora -= 0.01f;//ポリゴンを透明にしていく
			//m_col.a = m_colora;
			if (m_colora <= 0.0f)
			{
				m_colora = 0.0f;
				m_nfade = FADE_NONE;//何もしていない状態に戻す
			}

		}

		else if (m_nfade == FADE_OUT)
		{//フェードアウト状態
			m_colora += 0.01f;//ポリゴンを不透明にしていく
			if (m_colora >= 1.0f)
			{
				m_colora = 1.0f;

				CManager::SetMode(m_ModeNext);
				m_nfade = FADE_IN;
			}

		}
		SetColA(m_colora);
	}
}
//===================================
// 
//フェードの描画処理
// 
//===================================
void CFade::Draw()
{
	return;
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	//アルファテストを有効(アルファ値が０より大きい場合に描画する）
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	CObject2D::Draw();
	//アルファテスト無効に戻す
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}
//===================================
//
//フェードの設定処理
//
//===================================
void CFade::SetFade(CScene::MODE modenext)
{
	if (m_nfade == FADE_NONE)
	{
		m_nfade = FADE_OUT;
		m_ModeNext = modenext;
	}
}
//===================================
// 
//フェードの生成処理
//
//===================================
CFade* CFade::Create()
{
	CFade* pFade = new CFade(4);
	pFade->Init();
	pFade->SetSizeW(620.0f);
	pFade->SetSizeH(360.0f);
	pFade->SetPos(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f));

	//pFade->BindTexture(m_pTextureFade);
	//pFade->SetType(CObject::TYPE::FADE);
	return pFade;
}
//===================================
// 
//フェードのロード処理
//	　
//===================================
HRESULT CFade::Load()
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	//テクスチャの読み込み

	return S_OK;

}
//===================================
// 
//フェードのアンロード処理
// 
//===================================
void CFade::Unload()
{
	if (m_pTextureFade != nullptr)
	{
		m_pTextureFade->Release();
		m_pTextureFade = nullptr;
	}
}
