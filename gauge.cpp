//=============================================================================
//
// �Q�[�W�\������ [gauge.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "gauge.h"
#include "manager.h"
#include "scene.h"
#include "title.h"
#include "result.h"
#include "object3D.h"

//===================================
// 
//�R���X�g���N�^
//
//===================================
CGauge::CGauge(int nPriority) : CObject2D(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CGauge::~CGauge()
{

}

//===================================
// 
//�Q�[�W�̏���������
// 
//===================================
HRESULT CGauge::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	SetType(CObject::TYPE::GAUGE);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\playergauge.png", &m_pTexture);
	//���f���ݒ�
	//CTexture* pTexure = CManager::GetTexture();//�擾
	//m_nTextureIdx = pTexure->Regist("data\\playergauge.png");//�o�^
	//LPDIRECT3DTEXTURE9 pTex = pTexure->GetAddress(m_nTextureIdx);
	//BindTexture(pTex);//�ݒ�

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
	pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(900.0f, 600.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(900.0f, 700.0f, 0.0f);

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
//�Q�[�W�̏I������
// 
//===================================
void CGauge::Uninit()
{
	//�e�N�X�`���̔j��
	if (m_pTexture != nullptr)
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
	}

	//���_�o�b�t�@�̔j��
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
//�Q�[�W�̍X�V����
// 
//===================================
void CGauge::Update()
{
	/*for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	{
		for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
		{*/
			//�I�u�W�F�N�g�擾
			CObject* pObj = CObject::GetMyObject();

			//�ő吔���s���Ȃ̂�While���g�p
			while (pObj != nullptr)
			{
				// ���̃|�C���^��ۑ����Ă���
				CObject* pNext = pObj->GetNext();
				// ��肽�����������s�i����̓^�C�v�擾�j

				if (CObject::PLAYER == pObj->GetType())
				{
					CPlayer* pPlayer = (CPlayer*)pObj;
					D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//�ʒu�̎擾
					int PlayerLife = pPlayer->GetLife();//���C�t�̎擾
					VERTEX_2D* pVtx;
					//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
					m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

					if (pPlayer->GetLife() <= 15)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(850.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(850.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 14)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(800.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(800.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 13)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(750.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(750.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 12)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(700.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(700.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 11)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(650.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(650.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 10)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(600.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(600.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 9)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(550.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(550.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 8)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(500.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(500.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 7)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(450.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(450.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 6)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(400.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(400.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 5)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(350.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(350.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 4)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(300.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(300.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 3)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(250.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(250.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 2)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(200.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(200.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 1)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(150.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(150.0f, 700.0f, 0.0f);
					}
					if (pPlayer->GetLife() <= 0)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(100.0f, 600.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(100.0f, 700.0f, 0.0f);
					}

					//���_�o�b�t�@���A�����b�N����
					m_pVtxBuff->Unlock();
				}
				// �|�C���^�����̃|�C���^�֕ύX
				pObj = pNext;
			}
		//}
	//}
}
//===================================
// 
//�Q�[�W�̕`�揈��
// 
//===================================
void CGauge::Draw()
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
//�Q�[�W�̐�������
//
//===================================
CGauge* CGauge::Create(const D3DXVECTOR3& pos)
{
	CGauge* pGauge = new CGauge(1);//Gauge����
	pGauge->Init();
	//pGauge->SetType(CObject::GAUGE);
	return pGauge;
}