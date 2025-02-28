//=============================================================================
//
// �w���R�v�^�[�G�l�~�[���� [helicopter.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "helicopter.h"
#include "bullet.h"
#include "explosion.h"
#include "manager.h"
#include "texture.h"
#include "enemy_bullet.h"

LPDIRECT3DTEXTURE9 CHelicopter::m_pObj_Texture[CHelicopter::MAX_MAT] = {};

//===================================
// 
//�R���X�g���N�^
//
//===================================
CHelicopter::CHelicopter()
{
	nCounterBullet;
	m_nTextureIdx;
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CHelicopter::~CHelicopter()
{

}

//===================================
// 
//�G�̏���������
// 
//===================================
HRESULT CHelicopter::Init(void)
{
	//LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	////�f�o�C�X�̎擾
	//pDevice = CManager::GetRenderer()->GetDevice();

	if (FAILED(CObject3D::Init()))//���_�o�b�t�@�쐬
	{
		return E_FAIL;
	}
	Load();
	CHelicopter::m_nLife = 1;
	//�����_���[�̐���
	CObject3D::SetSizeW(40.0f);
	CObject3D::SetSizeH(40.0f);
	SetType(CObject::TYPE::HELICOPTER);
	//���f���ݒ�
	//CModel* pModel = CManager::GetModel();//�擾
	//m_nModelIdx = pModel->Regist("data\\helicopter.x");//�o�^
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//�ݒ�

	return S_OK;

}

//===================================
// 
//�w���R�v�^�[�̃q�b�g����
//
//===================================
void CHelicopter::Hit(int nDamage)
{
	CObject3D::Hit(nDamage);
}
//===================================
// 
//�w���R�v�^�[�̏I������
// 
//===================================
void CHelicopter::Uninit()
{
	CObject3D::Uninit();//this->Release();���g�̊J��
}

//===================================
// 
//�w���R�v�^�[�̍X�V����
// 
//===================================
void CHelicopter::Update()
{
	D3DXVECTOR3 HelicopterPos = GetPos();
	D3DXVECTOR3 HelicopterMove = GetMove();
	//�ʒu���X�V
	HelicopterPos += HelicopterMove;
	HelicopterMove = D3DXVECTOR3(0.0f, 0.0f, 4.0f);

	SetPos(HelicopterPos);
	SetMove(HelicopterMove);
	
	nCounterBullet--;
	if (nCounterBullet <= 0)
	{
		//�e�̐ݒ�
		CEnemy_Bullet::Create(m_pos, D3DXVECTOR3(0.0f, -5.0f, 0.0f), 15, CEnemy_Bullet::BULLETTYPE::BULLETTYPE_HELICOPTER);//�e�̌����ݒ�\
		nCounterBullet = 60;
		//�T�E���h�̍Đ�
		//PlaySound(SOUND_SE_MONSTER);
	}
}

//===================================
// 
//�w���R�v�^�[�̕`�揈��
// 
//===================================
void CHelicopter::Draw()
{
	CObject3D::Draw();//�|���S���`��
}
//===================================
// 
//�w���R�v�^�[�̐�������
//
//===================================
CHelicopter* CHelicopter::Create(const D3DXVECTOR3& pos)
{
	CHelicopter* pHelicopter = nullptr;
	pHelicopter = new CHelicopter();
	if (FAILED(pHelicopter->Init())) {
	}
	pHelicopter->SetPos(pos);
	pHelicopter->BindMesh(pHelicopter->GetMatModel(), pHelicopter->GetBuffer(), pHelicopter->GetMesh(), &m_pObj_Texture[0]);
	//pHelicopter->SetType(CObject::TYPE::HELICOPTER);

	return pHelicopter;
}
//===================================
// 
//�w���R�v�^�[�̃��[�h����
//
//===================================
HRESULT CHelicopter::Load()
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER HelicopterBuffer = GetBuffer();
	DWORD HelicopterMatModel = GetMatModel();
	LPD3DXMESH HelicopterMesh = GetMesh();
	//�e�N�X�`������
	if (FAILED(D3DXLoadMeshFromX("data\\helicopter.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &HelicopterBuffer, nullptr, &HelicopterMatModel, &HelicopterMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)HelicopterBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(HelicopterMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
				&m_pObj_Texture[nCntMat]);
		}
	}
	SetBuffer(HelicopterBuffer);
	SetMatModel(HelicopterMatModel);
	SetMesh(HelicopterMesh);
	return S_OK;

}
//===================================
// 
//�w���R�v�^�[�̃A�����[�h����
//
//===================================
void CHelicopter::Unload()
{
	for (int nCntTexture = 0; nCntTexture < MAX_MAT; nCntTexture++)
	{
		if (m_pObj_Texture[nCntTexture] != nullptr)
		{
			//m_pTexture[nCntTexture]->Release();
			m_pObj_Texture[nCntTexture] = nullptr;
		}
	}
	//���b�V���̔j��
	if (m_pMeshModel != nullptr)
	{
		m_pMeshModel->Release();
		m_pMeshModel = nullptr;

	}
	//�}�e���A���̔j��
	if (m_pBuffMatModel != nullptr)
	{
		m_pBuffMatModel->Release();
		m_pBuffMatModel = nullptr;
	}

	//�e�N�X�`���̊J��
	if (m_pTexture != nullptr)
	{
		delete[] m_pTexture;
		m_pTexture = nullptr;
	}


	m_bDeath = true;

	CObject3D::Unload();
}
