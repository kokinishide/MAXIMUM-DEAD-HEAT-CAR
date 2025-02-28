////================================
////
//// ポーズ画面遷移処理 [pause.cpp]
//// Author Koki_Nishide
////
////================================
//#include "input.h"
//#include "pause.h"
//#include "main.h"
//#include "player.h"
//#include "game.h"
//
////マクロ定義
//#define NUM_PAUSE	(4) //ポーズ用部品の数
//typedef enum
//{
//	PAUSETYPE_TITLE = 0,
//	PAUSETYPE_CONTINUE,
//	PAUSETYPE_RETRY,
//	PAUSETYPE_GOTITLE,
//	PAUSETYPE_MAX
//}PAUSETYPE;
//
////グローバル変数
//CPause::PAUSE_MENU m_PauseMenu; //ポーズメニューの情報
//
////================
////ポーズの初期化処理
////================
//void InitPause(void)
//{
//	LPDIRECT3DDEVICE9 pDevice;
//	int nCntPause;
//	m_nPause = PAUSETYPE_CONTINUE;
//
//	VERTEX_2D* pVtx;//頂点情報へのポインタ
//
//	//デバイスの取得
//	pDevice = GetDevice();
//	//テクスチャの読み込み
//	//D3DXCreateTextureFromFile(pDevice, "data\\cloudpilot001.png", &g_apTextureBG[0]);
//	//D3DXCreateTextureFromFile(pDevice, "data\\cloudpilot001.png", &g_apTextureBG[1]);
//	//D3DXCreateTextureFromFile(pDevice, "data\\cloudpilot001.png", &g_apTextureBG[2]);
//
//	//テクスチャ座標の開始位置(V値)の初期化
//	/*for (nCnt = 0; nCntBG < NUM_BG; nCntBG++)
//	{
//		g_aPosTexV[nCntBG] = 0.0f;
//
//	}*/
//
//	//頂点バッファの生成
//	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * NUM_PAUSE,
//		D3DUSAGE_WRITEONLY,
//		FVF_VERTEX_2D,
//		D3DPOOL_MANAGED,
//		&g_pVtxBuffPause,
//		NULL);
//
//
//	//頂点バッファをロックし、頂点データへのポインタを取得
//	g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);
//
//	for (nCntPause = 0; nCntPause < NUM_PAUSE; nCntPause++)
//	{
//		//頂点座標の設定
//		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//		pVtx[1].pos = D3DXVECTOR3(1300.0f, 0.0f, 0.0f);
//		pVtx[2].pos = D3DXVECTOR3(0.0f, 800.0f, 0.0f);
//		pVtx[3].pos = D3DXVECTOR3(1300.0f, 800.0f, 0.0f);
//
//		//頂点カラーの設定
//		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//
//		//テクスチャ座標の設定
//		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
//		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
//		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
//		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
//
//		pVtx += 4; //頂点データのポインタを4つ分進める
//	}
//	//頂点バッファをアンロックする
//	g_pVtxBuffPause->Unlock();
//}
////==================
////背景の終了処理
////==================
//void UninitPause(void)
//{
//	//テクスチャの破棄	
//	for (int nCnt = 0; nCnt < NUM_PAUSE; nCnt++)
//	{
//		if (g_apTexturePause[nCnt] != NULL)
//		{
//			g_apTexturePause[nCnt]->Release();
//			g_apTexturePause[nCnt] = NULL;
//		}
//
//		//頂点バッファの破棄
//		if (g_pVtxBuffPause != NULL)
//		{
//			g_pVtxBuffPause->Release();
//			g_pVtxBuffPause = NULL;
//		}
//	}
//}
////==================
////ポーズの更新処理
////==================
//void UpdatePause(void)
//{
//	
//	VERTEX_2D* pVtx; //頂点情報へのポインタ
//
//	//頂点バッファをロックし、頂点情報へのポインタを取得
//	g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);
//
//
//	if (GetKeyboardTrigger(DIK_DOWNARROW) == true)
//	{
//		m_nPause++;
//
//		if (m_nPause == PAUSETYPE_MAX)
//		{
//			m_nPause = PAUSETYPE_CONTINUE;
//		}
//	}
//	if (GetKeyboardTrigger(DIK_UPARROW) == true)
//	{
//		m_nPause--;
//
//		if (m_nPause == PAUSETYPE_CONTINUE - 1)
//		{
//			m_nPause = PAUSETYPE_GOTITLE;
//		}
//	}
//
//	for (nCntPause = 0; nCntPause < NUM_PAUSE; nCntPause++)
//	{
//		//頂点カラーの設定
//		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		if (nCntPause == m_nPause)
//		{
//			switch (m_nPause)
//			{
//			case 1:
//				pVtx[0].col = D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f);
//				pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
//				pVtx[2].col = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
//				pVtx[3].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
//				break;
//			case 2:
//				pVtx[0].col = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
//				pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
//				pVtx[2].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
//				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
//				break;
//			case 3:
//				pVtx[0].col = D3DXCOLOR(0.0f, 1.0f, 0.5f, 1.0f);
//				pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
//				pVtx[2].col = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
//				pVtx[3].col = D3DXCOLOR(0.0f, 0.0f, 0.5f, 1.0f);
//				break;
//			}
//		}
//		pVtx += 4;
//	}
//	if (GetKeyboardTrigger(DIK_RETURN) == true)
//	{//決定キー(ENTERキー)が押された
//		switch (m_nPause)
//		{
//		case PAUSETYPE_CONTINUE:
//			SetEnablePause(false);
//			break;
//		case PAUSETYPE_RETRY:
//			Set(MODE_GAME);
//			break;
//		case PAUSETYPE_GOTITLE:
//			Set(MODE_TITLE);
//			break;
//		default:
//			break;
//		}
//	}
//	//頂点バッファをアンロックする
//	g_pVtxBuffPause->Unlock();
//}
////==================
////ポーズの描画処理
////==================
//void DrawPause(void)
//{
//	LPDIRECT3DDEVICE9 pDevice;
//	int nCntPause;
//
//	//デバイスの取得
//	pDevice = GetDevice();
//
//	//頂点バッファをデータストリームに設定
//	pDevice->SetStreamSource(0, g_pVtxBuffPause, 0, sizeof(VERTEX_2D));
//	//頂点フォーマットの設定
//	pDevice->SetFVF(FVF_VERTEX_2D);
//
//
//	//テクスチャの設定
//	for (nCntPause = 0; nCntPause < NUM_PAUSE; nCntPause++)
//	{
//		pDevice->SetTexture(0, g_apTexturePause[nCntPause]);
//
//		//ポリゴンの描画
//		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntPause * 4, 2);
//	}
//}