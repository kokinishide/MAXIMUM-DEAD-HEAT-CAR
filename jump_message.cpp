//=============================================================================
//
// �W�����v���b�Z�[�W�\������ [jump_message.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "jump_message.h"
#include "manager.h"

//===================================
// 
//�R���X�g���N�^
//
//===================================
CJump_Message::CJump_Message(int nPriority) : CObject2D(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CJump_Message::~CJump_Message()
{

}

//===================================
// 
//�W�����v���b�Z�[�W�̏���������
// 
//===================================
HRESULT CJump_Message::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	SetType(CObject::TYPE::JUMP_MESSAGE);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\jump1.png", &m_pTexture);
	//���f���ݒ�
	//CTexture* pTexure = CManager::GetTexture();//�擾
	//m_nTextureIdx = pTexure->Regist("data\\jump1.png");//�o�^
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
//�W�����v���b�Z�[�W�̏I������
// 
//===================================
void CJump_Message::Uninit()
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
//�W�����v���b�Z�[�W�̍X�V����
// 
//===================================
void CJump_Message::Update()
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

					if (PlayerPos.z >= 5160.0f)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(530.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(930.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(530.0f, 200.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(930.0f, 200.0f, 0.0f);
					}
					if (PlayerPos.z >= 5960.0f)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					}
					if (PlayerPos.z >= 24620.0f)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(530.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(930.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(530.0f, 200.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(930.0f, 200.0f, 0.0f);
					}
					if (PlayerPos.z >= 25820.0f)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					}
					if (PlayerPos.z >= 45300.0f)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(530.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(930.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(530.0f, 200.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(930.0f, 200.0f, 0.0f);
					}
					if (PlayerPos.z >= 47300.0f)
					{
						//���_���W�̐ݒ�
						pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					}

					nCounterAnimJump++; //�J�E���^�[�����Z
					if (nCounterAnimJump >= 2)
					{
						nCounterAnimJump = 0;//�J�E���^�[�������l�ɖ߂�
						nPatternAnimJump++;//�p�^�[��No.���X�V����
						if (nPatternAnimJump >= 2)
						{
							nPatternAnimJump = 0;//�p�^�[��No.�������l�ɖ߂�
						}

						//�e�N�X�`�����W�̍X�V
						pVtx[0].tex = D3DXVECTOR2(0.0f + nPatternAnimJump * 0.5f, 0.0f);
						pVtx[1].tex = D3DXVECTOR2(0.5f + nPatternAnimJump * 0.5f, 0.0f);
						pVtx[2].tex = D3DXVECTOR2(0.0f + nPatternAnimJump * 0.5f, 1.0f);//1.0f
						pVtx[3].tex = D3DXVECTOR2(0.5f + nPatternAnimJump * 0.5f, 1.0f);//1.0f

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
//�W�����v���b�Z�[�W�̕`�揈��
// 
//===================================
void CJump_Message::Draw()
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
//�W�����v���b�Z�[�W�̐�������
//
//===================================
CJump_Message* CJump_Message::Create(const D3DXVECTOR3& pos)
{
	CJump_Message* pJump_Message = new CJump_Message(1);//Jump_Message����
	pJump_Message->Init();
	//pJump_Message->SetType(CObject::JUMP_MESSAGE);
	return pJump_Message;
}