//=============================================================================
//
// �{�X�̃��b�Z�[�W�\������ [boss_message.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "boss_message.h"
#include "manager.h"

//===================================
// 
//�R���X�g���N�^
//
//===================================
CBoss_Message::CBoss_Message(int nPriority) : CObject2D(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
	nCounterAnimBoss;//�A�j���[�V�����J�E���^�[
	nPatternAnimBoss;//�A�j���[�V�����p�^�[��No.
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CBoss_Message::~CBoss_Message()
{

}

//===================================
// 
//�{�X���b�Z�[�W�̏���������
// 
//===================================
HRESULT CBoss_Message::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	SetType(CObject::TYPE::BOSS_MESSAGE);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\the boss.png", &m_pTexture);
	//���f���ݒ�
	//CTexture* pTexure = CManager::GetTexture();//�擾
	//m_nTextureIdx = pTexure->Regist("data\\the boss.png");//�o�^
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
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

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
//�{�X���b�Z�[�W�̏I������
// 
//===================================
void CBoss_Message::Uninit()
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
//�{�X���b�Z�[�W�̍X�V����
// 
//===================================
void CBoss_Message::Update()
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
					VERTEX_2D* pVtx;
					//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
					m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

					if (PlayerPos.z >= 33060.0f)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(330.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(1230.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(330.0f, 700.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(1230.0f, 700.0f, 0.0f);
					}
					if (PlayerPos.z >= 34060.0f)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					}

					nCounterAnimBoss++; //�J�E���^�[�����Z
					if (nCounterAnimBoss >= 2)
					{
						nCounterAnimBoss = 0;//�J�E���^�[�������l�ɖ߂�
						nPatternAnimBoss++;//�p�^�[��No.���X�V����
						if (nPatternAnimBoss >= 2)
						{
							nPatternAnimBoss = 0;//�p�^�[��No.�������l�ɖ߂�
						}

						//�e�N�X�`�����W�̍X�V
						pVtx[0].tex = D3DXVECTOR2(0.0f + nPatternAnimBoss * 0.5f, 0.0f);
						pVtx[1].tex = D3DXVECTOR2(0.5f + nPatternAnimBoss * 0.5f, 0.0f);
						pVtx[2].tex = D3DXVECTOR2(0.0f + nPatternAnimBoss * 0.5f, 1.0f);//1.0f
						pVtx[3].tex = D3DXVECTOR2(0.5f + nPatternAnimBoss * 0.5f, 1.0f);//1.0f

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
//�{�X���b�Z�[�W�̕`�揈��
// 
//===================================
void CBoss_Message::Draw()
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
//�{�X���b�Z�[�W�̐�������
//
//===================================
CBoss_Message* CBoss_Message::Create(const D3DXVECTOR3& pos)
{
	CBoss_Message* pBoss_Message = new CBoss_Message(1);//Boss_Message����
	pBoss_Message->Init();
	//pBoss_Message->SetType(CObject::BOSS_MESSAGE);
	return pBoss_Message;
}