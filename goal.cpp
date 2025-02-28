//=============================================================================
//
// �S�[������ [goal.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "goal.h"
#include "bullet.h"
#include "explosion.h"
#include "object2D.h"
#include "manager.h"
#include "enemy.h"
//#include "game.h"
//#include "score.h"

LPDIRECT3DTEXTURE9 CGoal::m_pObj_Texture[CGoal::MAX_MAT] = {};

//===================================
// 
//�R���X�g���N�^
//
//===================================
CGoal::CGoal()
{

}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CGoal::~CGoal()
{

}


//===================================
// 
//�S�[���̏���������
// 
//===================================
HRESULT CGoal::Init()
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
	SetType(CObject::TYPE::GOAL);
	//���f���ݒ�
	//CModel* pModel = CManager::GetModel();//�擾
	//m_nModelIdx = pModel->Regist("data\\goal.x");//�o�^
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//�ݒ�
	return S_OK;//����

}

//===================================
// 
//�S�[���̏I������
// 
//===================================
void CGoal::Uninit()
{
	CObject3D::Uninit();//this->Release();���g�̊J��
}

//===================================
// 
//�S�[���̍X�V����
// 
//===================================
void CGoal::Update()
{

	CObject3D::Update();//���_���X�V
	//bool bIsLanding = false; //���n���Ă��邩�ǂ���

	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	//{
	//	for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
	//		//�I�u�W�F�N�g�擾
	//		CObject* pObj = CObject::GetMyObject(nCntPriority, nCntObj);
	//		if (pObj != nullptr)
	//		{
	//			//��ނ̎擾�i�u���b�N�Ȃ瓖���蔻��j
	//			CObject::TYPE type = pObj->GetType();
	//			if (type == CObject::TYPE::PLAYER)
	//			{
	//				CPlayer* pPlayer = (CPlayer*)pObj;
	//				D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//�ʒu�̎擾
	//				D3DXVECTOR3 PlayerPosOld = pPlayer->GetPosOld();//�Â��ʒu�̎擾
	//				D3DXVECTOR3 PlayerMove = pPlayer->GetMove();//�����̎擾

	//				//if (PlayerPosOld.y < m_pos.y - 0.0f
	//				//	&& PlayerPos.y >= m_pos.y - 0.0f
	//				//	&& PlayerPos.x > m_pos.x - 200.0f
	//				//	&& PlayerPos.x < m_pos.x + 200.0f
	//				//	&& PlayerPos.z > m_pos.z - 200.0f
	//				//	&& PlayerPos.z < m_pos.z + 200.0f)
	//				//{
	//				//	bIsLanding = true;
	//				//	PlayerPos.y = m_pos.y - 0.0f;
	//				//	PlayerMove.y = 0.0f;
	//				//}
	//				if (PlayerPosOld.y >= m_pos.y + 0.0f
	//					&& PlayerPos.y <= m_pos.y + 0.0f
	//					&& PlayerPos.x < m_pos.x + 225.0f
	//					&& PlayerPos.x > m_pos.x - 225.0f
	//					&& PlayerPos.z < m_pos.z + 10.0f
	//					&& PlayerPos.z > m_pos.z - 10.0f)
	//				{
	//					pPlayer->HitGoal(1);
	//					bIsLanding = true;
	//					PlayerPos.y = m_pos.y + 0.0f;
	//					PlayerMove.y = 0.0f;

	//					pPlayer->SetPos(PlayerPos); //�ʒu��ݒ�
	//					pPlayer->SetMove(PlayerMove); //������ݒ�
	//					pPlayer->SetIsLanding(bIsLanding); //���n��ݒ�

	//				}
	//				/*if (PlayerPosOld.y <= m_pos.y - 10.0f
	//					&& PlayerPos.y > m_pos.y - 10.0f
	//					)
	//				{
	//					bIsLanding = true;
	//					PlayerPos.y = m_pos.y - 10.0f;
	//					PlayerMove.y = 0.0f;
	//				}
	//				if (PlayerPosOld.y >= m_pos.y + 10.0f
	//					&& PlayerPos.y < m_pos.y + 10.0f
	//					)
	//				{
	//					bIsLanding = true;
	//					PlayerPos.y = m_pos.y + 10.0f;
	//					PlayerMove.y = 0.0f;
	//				}*/

	//			}
	//			
	//		}
	//	}
	//}
}

//===================================
// 
//�S�[���̕`�揈��
// 
//===================================
void CGoal::Draw()
{
	CObject3D::Draw();//�|���S���`��
}
//===================================
// 
//�S�[���̐�������
//
//===================================
CGoal* CGoal::Create(const D3DXVECTOR3& pos)
{
	CGoal* pGoal = nullptr;
	pGoal = new CGoal();
	if (FAILED(pGoal->Init())) {
	}
	pGoal->SetPos(pos);
	pGoal->BindMesh(pGoal->GetMatModel(), pGoal->GetBuffer(), pGoal->GetMesh(), &m_pObj_Texture[0]);
	//pGoal->SetType(CObject::TYPE::GOAL);
	return pGoal;
}
//===================================
//
//�S�[���̃��[�h����
//
//===================================
HRESULT CGoal::Load()
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER GoalBuffer = GetBuffer();
	DWORD GoalMatModel = GetMatModel();
	LPD3DXMESH GoalMesh = GetMesh();
	if (FAILED(D3DXLoadMeshFromX("data\\goal.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &GoalBuffer, nullptr, &GoalMatModel, &GoalMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)GoalBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(GoalMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
				&m_pObj_Texture[nCntMat]);
		}
	}
	SetBuffer(GoalBuffer);
	SetMatModel(GoalMatModel);
	SetMesh(GoalMesh);
	return S_OK;
}
//===================================
//
//�S�[���̃A�����[�h����
//
//===================================
void CGoal::Unload()
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
