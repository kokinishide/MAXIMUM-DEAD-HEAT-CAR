//=============================================================================
//
// �w�i���� [bg.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "bg.h"
#include "manager.h"
#include "scene.h"
#include "title.h"
#include "result.h"
#include "object3D.h"
#include "tutoreal.h"
#include "tutoreal2.h"
#include "tutoreal3.h"
//#include "ground.h"

//�}�N����`
//#define NUM_BG	(1)	//�w�i�̐�

//===================================
// 
//�R���X�g���N�^
//
//===================================
CBG::CBG(int nPriority) : CObject(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CBG::~CBG()
{

}

//===================================
// 
//�w�i�̏���������
// 
//===================================
HRESULT CBG::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	//int nCntBG;

	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	//���[�h�̎擾�i�G�Ȃ瓖���蔻��j
	CScene::MODE mode = CManager::GetScene()->GetMode();
	
	SetType(CObject::TYPE::BG);
	switch (mode)
	{
	case CScene::MODE_TITLE: //�^�C�g�����
		D3DXCreateTextureFromFile(pDevice, "data\\title.png", &m_pTexture);
		break;
	//case CScene::MODE_TUTOREAL: //�`���[�g���A�����
	//	D3DXCreateTextureFromFile(pDevice, "data\\tutoreal1.png", &m_pTexture);
	//	break;
	//case CScene::MODE_TUTOREAL2: //�`���[�g���A��2���
	//	D3DXCreateTextureFromFile(pDevice, "data\\tutoreal message.png", &m_pTexture);
	//	break;
	//case CScene::MODE_TUTOREAL3: //�`���[�g���A��3���
	//	D3DXCreateTextureFromFile(pDevice, "data\\tutoreal sousa.png", &m_pTexture);
	//	break;
	case CScene::MODE_GAME: //�Q�[�����


		break;
	case CScene::MODE_RESULT: //���U���g���
		if (CManager::GetScene()->GetEnd() == 0)
		{
			D3DXCreateTextureFromFile(pDevice, "data\\gameoverlife.png", &m_pTexture);
		}
		else if (CManager::GetScene()->GetEnd() == 1)
		{
			D3DXCreateTextureFromFile(pDevice, "data\\gameoverfalling.png", &m_pTexture);
		}
		else if (CManager::GetScene()->GetEnd() == 2)
		{
			D3DXCreateTextureFromFile(pDevice, "data\\stageclear.png", &m_pTexture);
		}
		break;

	}

//�e�N�X�`���̓ǂݍ���
	/*D3DXCreateTextureFromFile(pDevice, "data\\download.jpg", &m_pTexture);*/


	//���_�o�b�t�@�̐���
	//pDevice = GetDevice();
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		nullptr);

	VERTEX_2D* pVtx;
	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);


	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1300.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 800.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1300.0f, 800.0f, 0.0f);

	//rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}
//===================================
// 
//�w�i�̏I������
// 
//===================================
void CBG::Uninit()
{
	//�e�N�X�`���̔j��
	if (m_pTexture != nullptr)
	{
		//m_pTexture->Release();
		m_pTexture = nullptr;
	}

	//���_�o�b�t�@�̔j��
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
//�w�i�̍X�V����
// 
//===================================
void CBG::Update()
{
	

				
	//VERTEX_2D* pVtx;
	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	//m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//nCounterAnimBG++; //�J�E���^�[�����Z
	//if (nCounterAnimBG >= 18)
	//{
	//	nCounterAnimBG = 0;//�J�E���^�[�������l�ɖ߂�
	//	nPatternAnimBG++;//�p�^�[��No.���X�V����
	//	if (nPatternAnimBG >= 18)
	//	{
	//		nPatternAnimBG = 0;//�p�^�[��No.�������l�ɖ߂�
	//	}

	//	//�e�N�X�`�����W�̍X�V
	//	pVtx[0].tex = D3DXVECTOR2(0.0f + nPatternAnimBG * 0.5f, 0.0f);
	//	pVtx[1].tex = D3DXVECTOR2(0.5f + nPatternAnimBG * 0.5f, 0.0f);
	//	pVtx[2].tex = D3DXVECTOR2(0.0f + nPatternAnimBG * 0.5f, 1.0f);//1.0f
	//	pVtx[3].tex = D3DXVECTOR2(0.5f + nPatternAnimBG * 0.5f, 1.0f);//1.0f

	//}
	//
	////���_�o�b�t�@���A�����b�N����
	//m_pVtxBuff->Unlock();
	
}
//===================================
// 
//�w�i�̕`�揈��
// 
//===================================
void CBG::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));
	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);
	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

}
//===================================
//
//�w�i�̐�������
//
//===================================
CBG* CBG::Create()
{
	CBG* pBG = new CBG(2);//BG����
	pBG->Init();
	//pBG->SetType(CObject::BG);
	return pBG;
}