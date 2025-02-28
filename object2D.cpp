//=============================================================================
//
// �I�u�W�F�N�g2D���� [object2D.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include<stdio.h>
#include"object2D.h"
#include "renderer.h"
#include "manager.h"
#include"main.h"

//===================================
// 
//�R���X�g���N�^
//
//===================================
CObject2D::CObject2D()
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;

	/*m_pos.x = 80.0f;
	m_pos.y = 560.0f;*/

	m_sizeW = 1280.0f;
	m_sizeH = 720.0f;
}
//===================================
//
//�R���X�g���N�^(�v���C�I���e�B)
//
//===================================
CObject2D::CObject2D(int nPriority) : CObject(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;

	/*m_pos.x = 80.0f;
	m_pos.y = 560.0f;*/

	m_sizeW = 1280.0f;
	m_sizeH = 720.0f;
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CObject2D::~CObject2D()
{

}
//===================================
// 
//�I�u�W�F�N�g2D�̏����ݒ�i���_�o�b�t�@�����j
//
//===================================
HRESULT CObject2D::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	////�e�N�X�`���̓ǂݍ���
	//D3DXCreateTextureFromFile(pDevice, "data\\download.jpg", &m_pTexture);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

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
	pVtx[0].col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);

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
//�I�u�W�F�N�g2D�̏I�������i���_�o�b�t�@�j���j
//
//===================================
void CObject2D::Uninit()
{
	//if (m_pTexture != NULL)
	//{
	//	m_pTexture->Release();
	//	m_pTexture = NULL;
	//}

	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//CObject::Release();
	m_bDeath = true;
}
//===================================
// 
//�I�u�W�F�N�g2D�̍X�V�����i���_���̍X�V�j
//
//===================================
void CObject2D::Update()
{
	VERTEX_2D* pVtx;

	//CObject::TYPE type = GetType();

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);


	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_sizeW, m_pos.y - m_sizeH, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_sizeW, m_pos.y - m_sizeH, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_sizeW, m_pos.y + m_sizeH, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_sizeW, m_pos.y + m_sizeH, 0.0f);

	//rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;
	if (GetType() == CObject::TYPE::FADE)
	{
		int n = 0;
	}
	//�e�̎��������炷����
	//nLife -= 1;
	//if (nLife <= 0)//�������s����
	//{
	//	CExplosion::Uninit();
	//}
	nCounterAnim++; //�J�E���^�[�����Z
	if (nCounterAnim >= 10)
	{
		nCounterAnim = 0;//�J�E���^�[�������l�ɖ߂�
		nPatternAnim++;//�p�^�[��No.���X�V����
		if (nPatternAnim >= 8)
		{
			nPatternAnim = 0;//�p�^�[��No.�������l�ɖ߂�
		}

		//�e�N�X�`�����W�̍X�V
		pVtx[0].tex = D3DXVECTOR2(0.0f + nPatternAnim * 0.125f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.125f + nPatternAnim * 0.125f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f + nPatternAnim * 0.125f, 1.0f);//1.0f
		pVtx[3].tex = D3DXVECTOR2(0.125f + nPatternAnim * 0.125f, 1.0f);//1.0f

	}

	//-50.-50.+50.+25.+25

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();


}
//===================================
// 
//�I�u�W�F�N�g2D�̕`�揈���i�|���S���`��j
//
//===================================
void CObject2D::Draw()
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
//�I�u�W�F�N�g2D�̐�������
//
//===================================
CObject2D* CObject2D::Create()
{
	CObject2D* pObject2D = new CObject2D();//2D�I�u�W�F�N�g����
	pObject2D->Init();
	return pObject2D;
}
//===================================
// 
//�e�N�X�`���ݒ�
//
//===================================
void CObject2D::BindTexture(LPDIRECT3DTEXTURE9 pTex)
{
	m_pTexture = pTex;
}

//===================================
//
//�ʒu�ݒ�
//
//===================================
void CObject2D::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;

}
//void CObject2D::SetPosX(float x)
//{
//	m_pos.x = x;
//}
//void CObject2D::SetPosY(float y)
//{
//	m_pos.y = y;
//}
//===================================
//
//�����ݒ�
//
//===================================
void CObject2D::SetMove(D3DXVECTOR3 move)
{
	m_move = move;
}
//===================================
//
//���̃T�C�Y�ݒ�
//
//===================================
void CObject2D::SetSizeW(float w)
{
	m_sizeW = w;
}
//===================================
//
//�����̃T�C�Y�ݒ�
//
//===================================
void CObject2D::SetSizeH(float h)
{
	m_sizeH = h;
}
