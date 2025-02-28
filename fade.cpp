//=============================================================================
//
// �t�F�[�h���� [fade.cpp]
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

LPDIRECT3DTEXTURE9 CFade::m_pTextureFade = nullptr;//�e�N�X�`��
//===================================
//
//�R���X�g���N�^
// 
//===================================
CFade::CFade() : CObject2D(4)
{
	m_pTextureFade = nullptr;
}
//===================================
//
//�R���X�g���N�^(�v���C�I���e�B)
//
//===================================
CFade::CFade(int nPriority) : CObject2D(4)
{
	m_pTextureFade = nullptr;
}

//===================================
//
//�f�X�g���N�^
//
//===================================
CFade::~CFade()
{
}
//===================================
// 
//�t�F�[�h�̏���������
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
//�t�F�[�h�̏I������
// 
//===================================
void CFade::Uninit()
{
	//�T�E���h�̒�~
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
//�t�F�[�h�̍X�V����
// 
//===================================
void CFade::Update()
{

	LPDIRECT3DDEVICE9 pDevice;//�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();

	CObject2D::Update();

	if (m_nfade != FADE_NONE)
	{
		if (m_nfade == FADE_IN)
		{//�t�F�[�h�C�����
			m_colora -= 0.01f;//�|���S���𓧖��ɂ��Ă���
			//m_col.a = m_colora;
			if (m_colora <= 0.0f)
			{
				m_colora = 0.0f;
				m_nfade = FADE_NONE;//�������Ă��Ȃ���Ԃɖ߂�
			}

		}

		else if (m_nfade == FADE_OUT)
		{//�t�F�[�h�A�E�g���
			m_colora += 0.01f;//�|���S����s�����ɂ��Ă���
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
//�t�F�[�h�̕`�揈��
// 
//===================================
void CFade::Draw()
{
	return;
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	//�A���t�@�e�X�g��L��(�A���t�@�l���O���傫���ꍇ�ɕ`�悷��j
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	CObject2D::Draw();
	//�A���t�@�e�X�g�����ɖ߂�
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}
//===================================
//
//�t�F�[�h�̐ݒ菈��
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
//�t�F�[�h�̐�������
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
//�t�F�[�h�̃��[�h����
//	�@
//===================================
HRESULT CFade::Load()
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	//�e�N�X�`���̓ǂݍ���

	return S_OK;

}
//===================================
// 
//�t�F�[�h�̃A�����[�h����
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
