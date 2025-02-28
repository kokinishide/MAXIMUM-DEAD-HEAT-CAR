//=============================================================================
//
// �I�u�W�F�N�g3D���� [object3D.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include<stdio.h>
#include"object3D.h"
#include "renderer.h"
#include "manager.h"
#include"main.h"
#include"input.h"


//int m_nNumObject3D = 0;
bool CObject3D::m_bDisp;
int CObject3D::m_nCounterState;
int CObject3D::nNumObject3D;

//===================================
// 
//�R���X�g���N�^
//
//===================================
CObject3D::CObject3D()
{
	/*m_pVtxBuff = nullptr;
	m_pTexture = nullptr;*/
	m_pMeshModel = nullptr;
	m_pBuffMatModel = nullptr;
	m_dwNumMatModel;
	m_mtxWorldModel;
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
CObject3D::~CObject3D()
{

}
//===================================
// 
//�I�u�W�F�N�g3D�̏����ݒ�i���_�o�b�t�@�����j
//
//===================================
HRESULT CObject3D::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();

	//m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //�ړ��ʂ�����������
	//m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	////X�t�@�C���̓ǂݍ���
	//D3DXLoadMeshFromX("data\\airplane000.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &m_pBuffMatModel, nullptr, &m_dwNumMatModel, &m_pMeshModel);
	//���_�o�b�t�@�̐���
	/*pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		nullptr);*/



	return S_OK;
}
//===================================
//
//�I�u�W�F�N�g3D�̃q�b�g����
//
//===================================
void CObject3D::Hit(int nDamage)
{
	m_nLife -= nDamage;
	if (m_nLife <= 0)
	{
		nNumObject3D--; //�����J�E���g�_�E��
		m_bDisp = false;
	}
}
//===================================
//
//�I�u�W�F�N�g3D�̃S�[���q�b�g����
//
//===================================
void CObject3D::HitGoal(int nHit)
{
	m_nGoal -= nHit;
	if (m_nGoal <= 0)
	{
		nNumObject3D--; //�����J�E���g�_�E��
		m_bDisp = false;
	}
}
//===================================
//
//�I�u�W�F�N�g3D�̃��[�v�q�b�g����
//
//===================================
void CObject3D::HitWarp(int nHitWarp)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}
//===================================
// 
//�I�u�W�F�N�g3D�I�������i���_�o�b�t�@�j���j
//
//===================================
void CObject3D::Uninit()
{
	// ���f���̈ꊇ�Ǘ������������Ȃ�Release���Ȃ�

	//���b�V���̔j��
	if (m_pMeshModel != nullptr)
	{
		//m_pMeshModel->Release();
		m_pMeshModel = nullptr;

	}
	//�}�e���A���̔j��
	if (m_pBuffMatModel != nullptr)
	{
		//m_pBuffMatModel->Release();
		m_pBuffMatModel = nullptr;
	}

	//�e�N�X�`���̊J��
	if (m_pTexture != nullptr)
	{
		delete[] m_pTexture;
		m_pTexture = nullptr;
	}

	//CObject::Release();
	m_bDeath = true;
}
//===================================
// 
//�I�u�W�F�N�g3D�̍X�V�����i���_���̍X�V�j
//
//===================================
void CObject3D::Update()
{

}
//===================================
// 
//�I�u�W�F�N�g3D�̕`�揈���i�|���S���`��j
//
//===================================
void CObject3D::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;
	D3DXMATRIX mtxWorld; //���[���h�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans; //�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef; //���݂̃}�e���A���ۑ��p
	D3DXMATERIAL* pMat;//�}�e���A���f�[�^�ւ̃|�C���^
	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	//���݂̃}�e���A�����擾
	pDevice->GetMaterial(&matDef);

	//���[���h�ϊ��s��̍쐬

	//���[���h�ϊ��s��̏�����
	D3DXMatrixIdentity(&mtxWorld);
	//���������[���h�ϊ��s��֔��f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxRot);

	//�ʒu�����[���h�ϊ��s��֔��f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxTrans);

	//���[���h�ϊ��s��̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);
	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	if (m_pBuffMatModel != nullptr)
	{
		pMat = (D3DXMATERIAL*)m_pBuffMatModel->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)m_dwNumMatModel; nCntMat++)
		{

			//�}�e���A���̐ݒ�
			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
			if (m_pTexture != nullptr)
			{
				//�e�N�X�`���̐ݒ�
				pDevice->SetTexture(0, m_pTexture[nCntMat]);//nullptr
			}
			else
			{
				pDevice->SetTexture(0,nullptr);//nullptr
			}
			//���f���i�p�[�c�j�̕`��
			m_pMeshModel->DrawSubset(nCntMat);
		}
	}
	//�ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
}
//===================================
//
//�I�u�W�F�N�g3D�̐�������
//
//===================================
CObject3D* CObject3D::Create(D3DXVECTOR3 pos)
{
	CObject3D* pObject3D = new CObject3D();//3D�I�u�W�F�N�g����
	pObject3D->Init();
	return nullptr;
}

//===================================
// 
//CObject3D�̃��[�h����
//
//===================================
HRESULT CObject3D::Load()
{
	return S_OK;
}
//===================================
// 
//CObject3D�̃A�����[�h����
//
//===================================
void CObject3D::Unload()
{

}

//===================================
// 
//X�t�@�C���ݒ�
//
//===================================
void CObject3D::BindMesh(DWORD dwNumMatModel, LPD3DXBUFFER pBuff, LPD3DXMESH pMesh, LPDIRECT3DTEXTURE9* pTexture)
{
	m_dwNumMatModel = dwNumMatModel;
	m_pMeshModel = pMesh;
	m_pBuffMatModel = pBuff;
	if (pTexture != nullptr)
	{
	    m_pTexture = new LPDIRECT3DTEXTURE9[int(dwNumMatModel)];
		for (int nCnt = 0; nCnt < int(dwNumMatModel); nCnt++)
		{
			m_pTexture[nCnt] = pTexture[nCnt];
		}
	}
}
//===================================
// 
//���f���ݒ�
//
//===================================
void CObject3D::BindModel(DWORD dwNumMatModel, LPD3DXBUFFER pBuff, LPD3DXMESH pMesh, LPDIRECT3DTEXTURE9 pTexture)
{
	//m_dwNumMatModel = dwNumMatModel;
	//m_pMeshModel = pMesh;
	//m_pBuffMatModel = pBuff;
	//if (pTexture != nullptr)
	//{
	//	m_pTexture = new LPDIRECT3DTEXTURE9[int(dwNumMatModel)];
	//	for (int nCnt = 0; nCnt < int(dwNumMatModel); nCnt++)
	//	{
	//		m_pTexture[nCnt] = pTexture;
	//	}
	//}
}
//===================================
//
//�ʒu�ݒ�
//
//===================================
void CObject3D::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;

}
//===================================
//
//�Â��ʒu�ݒ�
//
//===================================
void CObject3D::SetPosOld(D3DXVECTOR3 posold)
{
	m_PosOld = posold;

}
//===================================
//
//�����ݒ�
//
//===================================
void CObject3D::SetMove(D3DXVECTOR3 move)
{
	m_move = move;
}//===================================
//
//�����ݒ�
//
//===================================
void CObject3D::SetRot(D3DXVECTOR3 rot)
{
	m_rot = rot;
}
//===================================
//
//�^�[�Q�b�g�̈ʒu�ݒ�
//
//===================================
void CObject3D::SetTargetPos(D3DXVECTOR3 TargetPos)
{
	m_TargetPos = TargetPos;
}
//===================================
//
//�_�b�V���A�^�b�N�ݒ�
//
//===================================
void CObject3D::SetDushAttack(bool DushAttack)
{
	m_DushAttack = DushAttack;
}
//===================================
//
//���n�ݒ�
//
//===================================
void CObject3D::SetIsLanding(bool bIsLanding)
{
	IsLanding = bIsLanding;
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
//���̃T�C�Y�ݒ�
//
//===================================
void CObject3D::SetSizeW(float w)
{
	m_sizeW = w;
}
//===================================
//
//�����̃T�C�Y�ݒ�
//
//===================================
void CObject3D::SetSizeH(float h)
{
	m_sizeH = h;
}
//===================================
//
//���C�t�ݒ�
//
//===================================
void CObject3D::SetLife(int nLife)
{
	m_nLife = nLife;
}
//===================================
//
//�S�[���̃q�b�g�ݒ�
//
//===================================
void CObject3D::SetGoalHit(int nGoal)
{
	m_nGoal = nGoal;
}

//===================================
//
//���̃T�C�Y�ݒ�
//
//===================================
void CObject3D::SetMesh(LPD3DXMESH pMeshModel)
{
	m_pMeshModel = pMeshModel;
}
//===================================
//
//X�t�@�C���̃o�b�t�@�[�ݒ�
//
//===================================
void CObject3D::SetBuffer(LPD3DXBUFFER pBuffMatModel)
{
	m_pBuffMatModel = pBuffMatModel;
}
//===================================
//
//X�t�@�C���̃}�b�g�ݒ�
//
//===================================
void CObject3D::SetMatModel(DWORD dwNumMatModel)
{
	m_dwNumMatModel = dwNumMatModel;
}
//===================================
//
//X�t�@�C���̃��[���h�ݒ�
//
//===================================
void CObject3D::SetWorldModel(D3DXMATRIX mtxWorldModel)
{
	m_mtxWorldModel = mtxWorldModel;
}