//=============================================================================
//
// �p�[�e�B�N������ [particle.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "enemy.h"
//#include "title.h"
//#include "game.h"
//#include "result.h"
#include "bullet.h"
#include "explosion.h"
#include "bg.h"
#include "enemy.h"
#include "effect.h"
#include "particle.h"
#include "manager.h"

//===================================
// 
//�R���X�g���N�^
//
//===================================
CParticle::CParticle(int nPriority) : CObject2D(nPriority)
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CParticle::~CParticle()
{

}
//===================================
// 
//�p�[�e�B�N���̏���������
// 
//===================================
HRESULT CParticle::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntParticle;

	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\particle.png", &m_pTexture);


	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		nullptr);

	VERTEX_2D* pVtx;
	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntParticle = 0; nCntParticle < MAX_PARTICLE; nCntParticle++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-5.0f, 5.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(5.0f, 5.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-5.0f, -5.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(5.0f, -5.0f, 0.0f);

		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//1.0f
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//1.0f

		pVtx += 4; //���_�f�[�^�̃|�C���^��4���i�߂�
	}
	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//===================================
// 
//�p�[�e�B�N���̏I������
// 
//===================================
void CParticle::Uninit()
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
//�p�[�e�B�N���̍X�V����
// 
//===================================
void CParticle::Update()
{
	VERTEX_3D* pVtx; //���_���̃|�C���^
	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	int nCntParticle;
	D3DXVECTOR3 Pos = GetPos();
	D3DXVECTOR3 Move = GetMove();
	//for (nCntParticle = 0; nCntParticle < MAX_PARTICLE; nCntParticle++)
	//{
	//	if (g_aParticle[nCntParticle].bUse == true)
	//	{
	//		//���_�J���[�̐ݒ�
	//		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//		//���_���W�̐ݒ�
	//		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//		pVtx[1].pos = D3DXVECTOR3(780.0f, 0.0f, 0.0f);
	//		pVtx[2].pos = D3DXVECTOR3(0.0f, 500.0f, 0.0f);
	//		pVtx[3].pos = D3DXVECTOR3(780.0f, 500.0f, 0.0f);

	//		if (g_aParticle[nCntParticle].nLife <= 0)
	//		{
	//			g_aParticle[nCntParticle].bUse = false;
	//		}
	//	}
	//	pVtx += 4;
	//}
	for (nCntParticle = 0; nCntParticle < MAX_PARTICLE; nCntParticle++)
	{
		
			//���_���W�̐ݒ�
			//pVtx[0].pos = D3DXVECTOR3(-g_aParticle[nCntParticle].fRadius,g_aParticle[nCntParticle].fRadius,0.0f);
			//pVtx[1].pos = D3DXVECTOR3(g_aParticle[nCntParticle].fRadius, g_aParticle[nCntParticle].fRadius, 0.0f);
			//pVtx[2].pos = D3DXVECTOR3(-g_aParticle[nCntParticle].fRadius, -g_aParticle[nCntParticle].fRadius, 0.0f);
			//pVtx[3].pos = D3DXVECTOR3(g_aParticle[nCntParticle].fRadius, -g_aParticle[nCntParticle].fRadius, 0.0f);

		Pos.x += Move.x;
		Pos.y += Move.y;
		Pos.z += Move.z;

			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			/*g_aParticle[nCntParticle].nLife--;

			if (g_aParticle[nCntParticle].nLife <= 0)
			{
				g_aParticle[nCntParticle].bUse = false;
			}*/
		
		pVtx += 4;
	}
	SetPos(Pos);
	SetMove(Move);
	m_pVtxBuff->Unlock();
}
//===================================
// 
//�p�[�e�B�N���̕`�揈��
// 
//===================================
void CParticle::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntParticle;
	D3DXVECTOR3 Pos = GetPos();
	D3DXVECTOR3 Move = GetMove();
	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATRIX mtxTrans; //�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxView;
	D3DXMATRIX mtxWorld;



	//a�u�����f�B���O�����Z�����ɐݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));
	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);

	////�e�N�X�`���̐ݒ�
	//pDevice->SetTexture(0, g_pTextureParticle);
	for (nCntParticle = 0; nCntParticle < MAX_PARTICLE; nCntParticle++)
	{
		
			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&mtxWorld);


			//�r���[�}�g���b�N�X���擾
			pDevice->GetTransform(D3DTS_VIEW, &mtxView);

			//�|���S�����J�����ɑ΂��Đ��ʂɌ�����
			D3DXMatrixInverse(&mtxWorld, NULL, &mtxView);//�t�s������߂�

			mtxWorld._41 = 0.0f;
			mtxWorld._42 = 0.0f;
			mtxWorld._43 = 0.0f;



			////�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, Pos.x, Pos.y, Pos.z);

			D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxTrans);
			//���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);


			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntParticle * 4, 2);
		
	}

	//a�u�����f�B���O�����ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	SetPos(Pos);
	SetMove(Move);
}
//===================================
//
//�p�[�e�B�N���̐�������
//
//===================================
CParticle* CParticle::Create(const D3DXVECTOR3& pos)
{
	CParticle* pParticle = new CParticle();//�p�[�e�B�N������
	pParticle->Init();
	pParticle->SetType(CObject::PARTICLE);
	return pParticle;
}

//===================================
// 
//�p�[�e�B�N���̐ݒ菈��
// 
//===================================
//void SetParticle(D3DXVECTOR3 pos, int nType, D3DXVECTOR3 move, float fRadius)
//{
//	int nCntParticle;
//
//	for (nCntParticle = 0; nCntParticle < MAX_PARTICLE; nCntParticle++)
//	{
//		if (g_aParticle[nCntParticle].bUse == false)
//		{
//
//			g_aParticle[nCntParticle].pos = pos;
//			g_aParticle[nCntParticle].move = move;
//			g_aParticle[nCntParticle].fRadius = fRadius;
//			g_aParticle[nCntParticle].nLife = 100;
//			/*g_aParticle[nCntParticle].col = col;
//			g_aParticle[nCntParticle].fRadius = fRadius;*/
//			//g_aParticle[nCntParticle].nType = nType;
//			g_aParticle[nCntParticle].bUse = true;
//
//			break;
//		}
//	}
//}