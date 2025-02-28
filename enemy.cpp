//=============================================================================
//
// �G�l�~�[���� [enemy.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "enemy.h"
#include "bullet.h"
#include "explosion.h"
#include "manager.h"
#include "texture.h"
#include "sound.h"
#include "score.h"
#include "model.h"

LPDIRECT3DTEXTURE9 CEnemy::m_pObj_Texture[CEnemy::MAX_MAT] = {};

//===================================
// 
//�R���X�g���N�^
//
//===================================
CEnemy::CEnemy()
{
	nCounterBullet;
	m_nTextureIdx;
	m_TargetPos;//�^�[�Q�b�g�̈ʒu
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CEnemy::~CEnemy()
{

}

//===================================
// 
//�G�̏���������
// 
//===================================
HRESULT CEnemy::Init(void)
{
	//LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	////�f�o�C�X�̎擾
	//pDevice = CManager::GetRenderer()->GetDevice();
	
	if (FAILED(CObject3D::Init()))//���_�o�b�t�@�쐬
	{
		return E_FAIL;
	}
	Load();
	CEnemy::m_nLife = 1;
	//�����_���[�̐���
	CObject3D::SetSizeW(40.0f);
	CObject3D::SetSizeH(40.0f);
	SetType(CObject::TYPE::ENEMY);
	//���f���ݒ�
	//CModel* pModel = CManager::GetModel();//�擾
	//m_nModelIdx = pModel->Regist("data\\carenemy.x");//�o�^
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);
	//
	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//�ݒ�

	return S_OK;

}

//===================================
// 
//�G�̃q�b�g����
//
//===================================
void CEnemy::Hit(int nDamage)
{
	CObject3D::Hit(nDamage);
}
//===================================
// 
//�G�̏I������
// 
//===================================
void CEnemy::Uninit()
{
	CObject3D::Uninit();//this->Release();���g�̊J��
	Unload();
}

//===================================
// 
//�G�̍X�V����
// 
//===================================
void CEnemy::Update()
{
	D3DXVECTOR3 EnemyPos = GetPos();
	D3DXVECTOR3 EnemyMove = GetMove();
	//�ʒu���X�V
	EnemyPos += EnemyMove;
		

	/*if (m_pos.x >= 1280.0f || m_pos.x <= 0.0f)
	{
		m_move.x *= -1;
	}
	else if (m_pos.y >= 720.0f || m_pos.y <= 0.0f)
	{
		m_move.y *= -1;
	}*/
		//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
		//{
		//	//�G�Ƃ̓����蔻��i�z������ԂɃ`�F�b�N�j
		//	for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
		//	{
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
						//D3DXVECTOR3 PlayerMove = pPlayer->GetMove();//�ʒu�̎擾
						//D3DXVECTOR3 PlayerTargetPos = pPlayer->GetTargetPos();//�^�[�Q�b�g�̈ʒu�̎擾
						//bool PlayerDushAttack = GetDushAttack();//�_�b�V���A�^�b�N�̎擾
						////�ʒu���X�V
						////PlayerPos += PlayerMove;
						//D3DXVECTOR3 vec = PlayerTargetPos - PlayerMove;
						//PlayerMove -= vec * 5.0f;
						
						if (PlayerPos.z >= EnemyPos.z - 200)
						{
							EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 4.0f);
						}
						
					}
					// �|�C���^�����̃|�C���^�֕ύX
					pObj = pNext;
				}
			//}

		//}
		//EnemyMove.y -= 10.0f;//�d��
		if (EnemyPos.y <= -50.0f)
		{
			CEnemy::Uninit();
		}
		SetPos(EnemyPos);
		SetMove(EnemyMove);
	////nCounterBullet--;
	//if (nCounterBullet <= 0)
	//{
	//	//�e�̐ݒ�
	//	CBullet::Create(m_pos, D3DXVECTOR3(-3.0f, 0.0f, 0.0f), 15, CBullet::BULLETTYPE::BULLETTYPE_ENEMY);//�G�̒e�̌����ݒ�\
	//	nCounterBullet = 60;
	//	//�T�E���h�̍Đ�
	//	//CSound* pSound = CManager::GetSound();//�T�E���h�̎擾
	//	//pSound->PlaySound(CSound::SOUND_LABEL::SOUND_SE_MONSTER);
	//}
}

//===================================
// 
//�G�̕`�揈��
// 
//===================================
void CEnemy::Draw()
{
	CObject3D::Draw();//�|���S���`��
}
//===================================
// 
//�G�̐�������
//
//===================================
CEnemy* CEnemy::Create(const D3DXVECTOR3& pos)
{
	CEnemy* pEnemy = nullptr;
	pEnemy = new CEnemy();
	if (FAILED(pEnemy->Init())) {
	}
	pEnemy->SetPos(pos);
	pEnemy->BindMesh(pEnemy->GetMatModel(), pEnemy->GetBuffer(), pEnemy->GetMesh(),&m_pObj_Texture[0]);
	//pEnemy->SetType(CObject::TYPE::ENEMY);

	return pEnemy;
}
//===================================
// 
//�G�̃��[�h����
//
//===================================
HRESULT CEnemy::Load()
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER EnemyBuffer = GetBuffer();
	DWORD EnemyMatModel = GetMatModel();
	LPD3DXMESH EnemyMesh = GetMesh();
	//�e�N�X�`������
	if (FAILED(D3DXLoadMeshFromX("data\\carenemy.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &EnemyBuffer, nullptr, &EnemyMatModel, &EnemyMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)EnemyBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(EnemyMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
				&m_pObj_Texture[nCntMat]);
		}
	}
	SetBuffer(EnemyBuffer);
	SetMatModel(EnemyMatModel);
	SetMesh(EnemyMesh);
	return S_OK;

}
//===================================
// 
//�G�̃A�����[�h����
//
//===================================
void CEnemy::Unload()
{
	
	for (int nCntTexture = 0; nCntTexture < MAX_MAT; nCntTexture++)
	{
		if (m_pObj_Texture[nCntTexture] != nullptr)
		{
			m_pObj_Texture[nCntTexture]->Release();
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
