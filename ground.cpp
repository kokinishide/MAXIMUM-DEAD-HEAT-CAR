//=============================================================================
//
// �O���E���h���� [ground.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "ground.h"
#include "bullet.h"
#include "explosion.h"
#include "object2D.h"
#include "manager.h"
#include "enemy.h"
#include "truck.h"
#include "boss.h"
#include "object3D.h"
//#include "game.h"
//#include "score.h"

LPDIRECT3DTEXTURE9 CGround::m_pObj_Texture[CGround::MAX_MAT] = {};

//===================================
// 
//�R���X�g���N�^
//
//===================================
CGround::CGround()
{
	m_nTextureIdx;
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CGround::~CGround()
{

}



//===================================
// 
//�O���E���h�̏���������
// 
//===================================
HRESULT CGround::Init()
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
	SetType(CObject::TYPE::GROUND);
	//���f���ݒ�
	//CModel* pModel = CManager::GetModel();//�擾
	//m_nModelIdx = pModel->Regist("data\\ground.x");//�o�^
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//�ݒ�
	return S_OK;//����

}

//===================================
// 
//�O���E���h�̏I������
// 
//===================================
void CGround::Uninit()
{
	CObject3D::Uninit();//this->Release();���g�̊J��
	Unload();
}

//===================================
// 
//�O���E���h�̍X�V����
// 
//===================================
void CGround::Update()
{

	CObject3D::Update();//���_���X�V
	bool bIsLanding = false; //���n���Ă��邩�ǂ���

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
				if (CObject::TYPE::PLAYER == pObj->GetType())
				{
					CPlayer* pPlayer = (CPlayer*)pObj;
					D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//�ʒu�̎擾
					D3DXVECTOR3 PlayerPosOld = pPlayer->GetPosOld();//�Â��ʒu�̎擾
					D3DXVECTOR3 PlayerMove = pPlayer->GetMove();//�����̎擾

					//if (PlayerPosOld.y < m_pos.y - 0.0f
					//	&& PlayerPos.y >= m_pos.y - 0.0f
					//	&& PlayerPos.x > m_pos.x - 200.0f
					//	&& PlayerPos.x < m_pos.x + 200.0f
					//	&& PlayerPos.z > m_pos.z - 200.0f
					//	&& PlayerPos.z < m_pos.z + 200.0f)
					//{
					//	bIsLanding = true;
					//	PlayerPos.y = m_pos.y - 0.0f;
					//	PlayerMove.y = 0.0f;
					//}
					if (PlayerPosOld.y >= m_pos.y + 0.0f
						&& PlayerPos.y <= m_pos.y + 0.0f
						&& PlayerPos.x < m_pos.x + 225.0f
						&& PlayerPos.x > m_pos.x - 225.0f
						&& PlayerPos.z < m_pos.z + 440.0f
						&& PlayerPos.z > m_pos.z - 440.0f)
					{
						bIsLanding = true;
						PlayerPos.y = m_pos.y + 0.0f;
						PlayerMove.y = 0.0f;

						pPlayer->SetPos(PlayerPos); //�ʒu��ݒ�
						pPlayer->SetMove(PlayerMove); //������ݒ�
						pPlayer->SetIsLanding(bIsLanding); //���n��ݒ�

					}
					/*if (PlayerPosOld.y <= m_pos.y - 10.0f
						&& PlayerPos.y > m_pos.y - 10.0f
						)
					{
						bIsLanding = true;
						PlayerPos.y = m_pos.y - 10.0f;
						PlayerMove.y = 0.0f;
					}
					if (PlayerPosOld.y >= m_pos.y + 10.0f
						&& PlayerPos.y < m_pos.y + 10.0f
						)
					{
						bIsLanding = true;
						PlayerPos.y = m_pos.y + 10.0f;
						PlayerMove.y = 0.0f;
					}*/

				}
			
				if (CObject::TYPE::ENEMY == pObj->GetType())
				{
					CEnemy* pEnemy = (CEnemy*)pObj;
					D3DXVECTOR3 EnemyPos = pEnemy->GetPos();//�ʒu�̎擾
					D3DXVECTOR3 EnemyPosOld = pEnemy->GetPosOld();//�Â��ʒu�̎擾
					D3DXVECTOR3 EnemyMove = pEnemy->GetMove();//�����̎擾

					if (EnemyPosOld.y >= m_pos.y + 0.0f
						&& EnemyPos.y <= m_pos.y + 0.0f
						&& EnemyPos.x < m_pos.x + 225.0f
						&& EnemyPos.x > m_pos.x - 225.0f
						&& EnemyPos.z < m_pos.z + 440.0f
						&& EnemyPos.z > m_pos.z - 440.0f)
					{
						EnemyPos.y = m_pos.y + 0.0f;
						EnemyMove.y = 0.0f;

						pEnemy->SetPos(EnemyPos); //�ʒu��ݒ�
						pEnemy->SetMove(EnemyMove); //������ݒ�

					}
				}
				
				if (CObject::TYPE::TRUCK == pObj->GetType())
				{
					CTruck* pTruck = (CTruck*)pObj;
					D3DXVECTOR3 TruckPos = pTruck->GetPos();//�ʒu�̎擾
					D3DXVECTOR3 TruckPosOld = pTruck->GetPosOld();//�Â��ʒu�̎擾
					D3DXVECTOR3 TruckMove = pTruck->GetMove();//�����̎擾

					if (TruckPosOld.y >= m_pos.y + 0.0f
						&& TruckPos.y <= m_pos.y + 0.0f
						&& TruckPos.x < m_pos.x + 225.0f
						&& TruckPos.x > m_pos.x - 225.0f
						&& TruckPos.z < m_pos.z + 440.0f
						&& TruckPos.z > m_pos.z - 440.0f)
					{
						TruckPos.y = m_pos.y + 0.0f;
						TruckMove.y = 0.0f;

						pTruck->SetPos(TruckPos); //�ʒu��ݒ�
						pTruck->SetMove(TruckMove); //������ݒ�

					}
				}
				
				if (CObject::TYPE::BOSS == pObj->GetType())
				{
					CBoss* pBoss = (CBoss*)pObj;
					D3DXVECTOR3 BossPos = pBoss->GetPos();//�ʒu�̎擾
					D3DXVECTOR3 BossPosOld = pBoss->GetPosOld();//�Â��ʒu�̎擾
					D3DXVECTOR3 BossMove = pBoss->GetMove();//�����̎擾

					if (BossPosOld.y >= m_pos.y + 0.0f
						&& BossPos.y <= m_pos.y + 0.0f
						&& BossPos.x < m_pos.x + 225.0f
						&& BossPos.x > m_pos.x - 225.0f
						&& BossPos.z < m_pos.z + 440.0f
						&& BossPos.z > m_pos.z - 440.0f)
					{
						BossPos.y = m_pos.y + 0.0f;
						BossMove.y = 0.0f;

						pBoss->SetPos(BossPos); //�ʒu��ݒ�
						pBoss->SetMove(BossMove); //������ݒ�

					}
				}



				// �|�C���^�����̃|�C���^�֕ύX
				pObj = pNext;
			}

			//if (pObj != nullptr)
			//{
			//	//��ނ̎擾�i�u���b�N�Ȃ瓖���蔻��j
			//	CObject::TYPE type = pObj->GetType();
			//	
			//	//SetType(CObject::TYPE::BOSS);
			//}
		//}
	//}
}

//===================================
// 
//�O���E���h�̕`�揈��
// 
//===================================
void CGround::Draw()
{
	CObject3D::Draw();//�|���S���`��
}
//===================================
// 
//�O���E���h�̐�������
//
//===================================
CGround* CGround::Create(const D3DXVECTOR3& pos)
{
	CGround* pGround = nullptr;
	pGround = new CGround();
	if (FAILED(pGround->Init())) {
	}
	pGround->SetPos(pos);
	pGround->BindMesh(pGround->GetMatModel(), pGround->GetBuffer(), pGround->GetMesh(), &m_pObj_Texture[0]);
	//pGround->SetType(CObject::TYPE::GROUND);
	return pGround;
}
//===================================
//
//�O���E���h�̃��[�h����
//
//===================================
HRESULT CGround::Load()
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER GroundBuffer = GetBuffer();
	DWORD GroundMatModel = GetMatModel();
	LPD3DXMESH GroundMesh = GetMesh();
	if (FAILED(D3DXLoadMeshFromX("data\\ground1.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &GroundBuffer, nullptr, &GroundMatModel, &GroundMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)GroundBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(GroundMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
				&m_pTexture[nCntMat]);
		}
	}
	SetBuffer(GroundBuffer);
	SetMatModel(GroundMatModel);
	SetMesh(GroundMesh);
	return S_OK;
}
//===================================
//
//�O���E���h�̃A�����[�h����
//
//===================================
void CGround::Unload()
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