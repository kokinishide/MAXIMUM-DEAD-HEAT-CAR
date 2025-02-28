//=============================================================================
//
// マネージャー処理 [manager.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include<stdio.h>
#include"object2D.h"
#include"manager.h"
#include"input.h"
#include"object3D.h"
#include"scene.h"
#include"title.h"
#include"result.h"
#include"sound.h"
#include"score.h"

//===================================
// 
//静的メンバ初期化
//
//===================================
CRenderer* CManager::m_pRenderer = nullptr;
CInputKeyboard* CManager::m_pKeyboard = nullptr;
CInputGamePad* CManager::m_pGamePad = nullptr;
CLight* CManager::m_pLight = nullptr;
CCamera* CManager::m_pCamera = nullptr;
CScene* CManager::m_pScene = nullptr;
CFade* CManager::m_pFade = nullptr;
CSound* CManager::m_pSound = nullptr;
CModel* CManager::m_pModel = nullptr;
CTexture* CManager::m_pTexture = nullptr;
//m_bDisp = nullptr;
//m_nCounterState = nullptr;
//m_nLife = nullptr;
//nNumObject3D = nullptr;

//===================================
// 
//コンストラクタ
//
//===================================
CManager::CManager()
{
	m_pRenderer = nullptr;
	m_pKeyboard = nullptr;
	m_pGamePad = nullptr;
	m_pLight = nullptr;
	m_pCamera = nullptr;
	m_pScene = nullptr;
	m_pFade = nullptr;
	m_pSound = nullptr;
	m_pModel = nullptr;
	m_pTexture = nullptr;
}
//===================================
// 
//デストラクタ
//
//===================================
CManager::~CManager()
{

}
//===================================
// 
//マネージャーの初期化処理
//
//===================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	//レンダラーの生成
	m_pRenderer = new CRenderer();
	m_pRenderer->Init(hWnd, bWindow);
	//カメラの生成
	m_pCamera = new CCamera();
	m_pCamera->Init();
	//ライトの生成
	m_pLight = new CLight();
	m_pLight->Init();
	//入力の生成
	m_pKeyboard = new CInputKeyboard();
	m_pKeyboard->Init(hInstance, hWnd);
	//ゲームパッド入力の生成
	m_pGamePad = new CInputGamePad();
	m_pGamePad->Init(hInstance, hWnd);
	//フェードの生成
	m_pFade = CFade::Create();
	m_pFade->SetUseRelease(false);
	m_pFade->SetFade(CScene::MODE::MODE_TITLE);

	//サウンドの生成
	m_pSound = new CSound();
	m_pSound->InitSound(hWnd);
	//モデルの生成
	m_pModel = new CModel();
	//テクスチャの生成
	m_pTexture = new CTexture();

	//最初のシーンの設定
	SetMode(CScene::MODE_TITLE);

	return S_OK;
}
//===================================
// 
//マネージャーの終了処理
//
//===================================
void CManager::Uninit()
{

	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}
	if (m_pKeyboard != nullptr)
	{
		m_pKeyboard->Uninit();
		delete m_pKeyboard;
		m_pKeyboard = nullptr;
	}
	if (m_pGamePad != nullptr)
	{
		m_pGamePad->Uninit();
		delete m_pGamePad;
		m_pGamePad = nullptr;
	}
	//if (m_pCamera != nullptr)
	//{
	//	m_pCamera->Uninit();
	//	delete m_pCamera;
	//	m_pCamera = nullptr;
	//}
	if (m_pScene != nullptr)
	{
		m_pScene->Uninit();
		delete m_pScene;
		m_pScene = nullptr;
	}
	//if (m_pFade != nullptr)
	//{
	//	m_pFade->Uninit();
	//	m_pFade = nullptr;
	//}
	if (m_pSound != nullptr)
	{
		m_pSound->UninitSound();
		m_pSound = nullptr;
	}

}
//===================================
// 
//マネージャーの更新処理(レンダラーの更新)
//
//===================================
void CManager::Update()
{
	// TODO: null チェック

	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Update();
	}

	if (m_pKeyboard != nullptr)
	{
		m_pKeyboard->Update();
	}

	if (m_pGamePad != nullptr)
	{
		m_pGamePad->Update();
	}

	if (m_pCamera != nullptr)
	{
		m_pCamera->Update();
	}

	if (m_pScene != nullptr)
	{
		m_pScene->Update();
	}

	if (m_pFade != nullptr)
	{
		m_pFade->Update();
	}

}
//===================================
// 
//マネージャーの描画処理(レンダラーの描画)
//
//===================================
void CManager::Draw()
{
	m_pRenderer->Draw();
	//m_pScene->Draw();Release
	//m_pFade->Draw();

}
//===================================
//
//マネージャーのモード設定
//
//===================================
void CManager::SetMode(CScene::MODE mode)
{
	//終了処理
	if (m_pScene != nullptr)
	{
		m_pScene->Uninit();
		delete m_pScene;
		m_pScene = nullptr;
	}
	//生成
	m_pScene = CScene::Create(mode);
}
//===================================
// 
//モデル取得
//
//===================================
CModel* CManager::GetModel()
{
	return m_pModel;
}
//===================================
// 
//テクスチャ取得
//
//===================================
CTexture* CManager::GetTexture()
{
	return m_pTexture;
}
//===================================
// 
//レンダラー取得
//
//===================================
CRenderer* CManager::GetRenderer()
{
	return m_pRenderer;
}
//===================================
// 
//入力取得
// 
//===================================
CInputKeyboard* CManager::GetKeyboard()
{
	return 	m_pKeyboard;
}
//===================================
// 
//ゲームパッド入力取得
// 
//===================================
CInputGamePad* CManager::GetGamePad()
{
	return 	m_pGamePad;
}
//===================================
// 
//ライト取得
//
//===================================
CLight* CManager::GetLight()
{
	return 	m_pLight;
}
//===================================
// 
//カメラ取得
//
//===================================
CCamera* CManager::GetCamera()
{
	return 	m_pCamera;
}
//===================================
// 
//サウンド取得
//
//===================================
//CSound* CManager::GetSound()
//{
//	return 	m_pSound;
//}