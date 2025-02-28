//=============================================================================
//
// �}�l�[�W���[���� [manager.cpp]
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
//�ÓI�����o������
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
//�R���X�g���N�^
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
//�f�X�g���N�^
//
//===================================
CManager::~CManager()
{

}
//===================================
// 
//�}�l�[�W���[�̏���������
//
//===================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	//�����_���[�̐���
	m_pRenderer = new CRenderer();
	m_pRenderer->Init(hWnd, bWindow);
	//�J�����̐���
	m_pCamera = new CCamera();
	m_pCamera->Init();
	//���C�g�̐���
	m_pLight = new CLight();
	m_pLight->Init();
	//���͂̐���
	m_pKeyboard = new CInputKeyboard();
	m_pKeyboard->Init(hInstance, hWnd);
	//�Q�[���p�b�h���͂̐���
	m_pGamePad = new CInputGamePad();
	m_pGamePad->Init(hInstance, hWnd);
	//�t�F�[�h�̐���
	m_pFade = CFade::Create();
	m_pFade->SetUseRelease(false);
	m_pFade->SetFade(CScene::MODE::MODE_TITLE);

	//�T�E���h�̐���
	m_pSound = new CSound();
	m_pSound->InitSound(hWnd);
	//���f���̐���
	m_pModel = new CModel();
	//�e�N�X�`���̐���
	m_pTexture = new CTexture();

	//�ŏ��̃V�[���̐ݒ�
	SetMode(CScene::MODE_TITLE);

	return S_OK;
}
//===================================
// 
//�}�l�[�W���[�̏I������
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
//�}�l�[�W���[�̍X�V����(�����_���[�̍X�V)
//
//===================================
void CManager::Update()
{
	// TODO: null �`�F�b�N

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
//�}�l�[�W���[�̕`�揈��(�����_���[�̕`��)
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
//�}�l�[�W���[�̃��[�h�ݒ�
//
//===================================
void CManager::SetMode(CScene::MODE mode)
{
	//�I������
	if (m_pScene != nullptr)
	{
		m_pScene->Uninit();
		delete m_pScene;
		m_pScene = nullptr;
	}
	//����
	m_pScene = CScene::Create(mode);
}
//===================================
// 
//���f���擾
//
//===================================
CModel* CManager::GetModel()
{
	return m_pModel;
}
//===================================
// 
//�e�N�X�`���擾
//
//===================================
CTexture* CManager::GetTexture()
{
	return m_pTexture;
}
//===================================
// 
//�����_���[�擾
//
//===================================
CRenderer* CManager::GetRenderer()
{
	return m_pRenderer;
}
//===================================
// 
//���͎擾
// 
//===================================
CInputKeyboard* CManager::GetKeyboard()
{
	return 	m_pKeyboard;
}
//===================================
// 
//�Q�[���p�b�h���͎擾
// 
//===================================
CInputGamePad* CManager::GetGamePad()
{
	return 	m_pGamePad;
}
//===================================
// 
//���C�g�擾
//
//===================================
CLight* CManager::GetLight()
{
	return 	m_pLight;
}
//===================================
// 
//�J�����擾
//
//===================================
CCamera* CManager::GetCamera()
{
	return 	m_pCamera;
}
//===================================
// 
//�T�E���h�擾
//
//===================================
//CSound* CManager::GetSound()
//{
//	return 	m_pSound;
//}