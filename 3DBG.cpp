//=============================================================================
//
// 3D�w�i���� [3DBG.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "3DBG.h"
#include "bullet.h"
#include "explosion.h"
#include "object2D.h"
#include "manager.h"
#include "enemy.h"

LPDIRECT3DTEXTURE9 C3DBG::m_pObj_Texture[C3DBG::MAX_MAT] = {};

//�R���X�g���N�^
C3DBG::C3DBG()
{
	nCounterBullet;
	m_nTextureIdx;
	m_aTextureFilename;
}
//�f�X�X�g���N�^
C3DBG::~C3DBG()
{

}


//===================================
//
//3D�w�i�̏���������
// 
//===================================
HRESULT C3DBG::Init()
{
	if (FAILED(CObject3D::Init()))//���_�o�b�t�@�쐬
	{//���s
		return E_FAIL;
	}
	Load();
	//���_���ݒ�ɕK�v��
	//�Z�`�T�C�Y�Ȃǂ̃p�����[�^�ݒ�
	CObject3D::SetSizeW(40.0f);
	CObject3D::SetSizeH(40.0f);
	SetType(CObject::TYPE::BG);
	//���f���ݒ�
	//CModel* pModel = CManager::GetModel();//�擾
	//m_nModelIdx = pModel->Regist("data\\downtown.x");//�o�^
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//�ݒ�

	return S_OK;//����

}

//===================================
//
//3D�w�i�̏I������
// 
//===================================
void C3DBG::Uninit()
{
	CObject3D::Uninit();//this->Release();���g�̊J��
}

//===================================
//
//3D�w�i�̍X�V����
//
//===================================
void C3DBG::Update()
{

}

//===================================
//
//3D�w�i�̕`�揈��
// 
//===================================
void C3DBG::Draw()
{
	CObject3D::Draw();//�|���S���`��
}
//===================================
//
//C3DBG����
//
//===================================
C3DBG* C3DBG::Create(const D3DXVECTOR3& pos)
{
	C3DBG* p3DBG = nullptr;
	p3DBG = new C3DBG();
	if (FAILED(p3DBG->Init())) {
	}
	p3DBG->SetPos(pos);
	p3DBG->BindMesh(p3DBG->GetMatModel(), p3DBG->GetBuffer(), p3DBG->GetMesh(), &m_pObj_Texture[0]);
	//p3DBG->SetType(CObject::TYPE::BG);
	return p3DBG;
}
//===================================
//
//3D�w�i�̃��[�h����
// 
//===================================
HRESULT C3DBG::Load()
{
	
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER BGBuffer = GetBuffer();
	DWORD BGMatModel = GetMatModel();
	LPD3DXMESH BGMesh = GetMesh();
	if (FAILED(D3DXLoadMeshFromX("data\\downtown.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &BGBuffer, nullptr, &BGMatModel, &BGMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)BGBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(BGMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			strcat(&m_aTextureFilename[0],pMat[nCntMat].pTextureFilename);
			
			if (m_pObj_Texture == nullptr)
			{
				if (FAILED(D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
					&m_pObj_Texture[nCntMat])))
				{
					return E_FAIL;
				}
			}
		}
	}
	SetBuffer(BGBuffer);
	SetMatModel(BGMatModel);
	SetMesh(BGMesh);
	return S_OK;
}
//===================================
//
//3D�w�i�̃A�����[�h����
// 
//===================================
void C3DBG::Unload()
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