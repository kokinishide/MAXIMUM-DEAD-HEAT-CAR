//=============================================================================
//
// �{�X���� [boss.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "boss.h"
#include "bullet.h"
#include "explosion.h"
#include "manager.h"
#include "texture.h"
#include "sound.h"
#include "score.h"
#include "boss_bullet.h"

LPDIRECT3DTEXTURE9 CBoss::m_pObj_Texture[CBoss::MAX_MAT] = {};

//===================================
// 
//�R���X�g���N�^
//
//===================================
CBoss::CBoss()
{
	nCounterBullet;
	m_nTextureIdx;
	m_TargetPos;
	m_wasMove = false;
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CBoss::~CBoss()
{

}

//===================================
// 
//�{�X�̏���������
// 
//===================================
HRESULT CBoss::Init(void)
{
	//LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	////�f�o�C�X�̎擾
	//pDevice = CManager::GetRenderer()->GetDevice();

	if (FAILED(CObject3D::Init()))//���_�o�b�t�@�쐬
	{
		return E_FAIL;
	}
	Load();
	CBoss::m_nLife = 3;
	//�����_���[�̐���
	CObject3D::SetSizeW(40.0f);
	CObject3D::SetSizeH(40.0f);
	SetType(CObject::TYPE::BOSS);
	//���f���ݒ�
	//CModel* pModel = CManager::GetModel();//�擾
	//m_nModelIdx = pModel->Regist("data\\boss.x");//�o�^
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//�ݒ�

	return S_OK;

}

//===================================
// 
//�{�X�̃q�b�g����
//
//===================================
void CBoss::Hit(int nDamage)
{
	CObject3D::Hit(nDamage);
}
//===================================
// 
//�{�X�̏I������
// 
//===================================
void CBoss::Uninit()
{
	CObject3D::Uninit();//this->Release();���g�̊J��
	m_bDeath = true;
}

//===================================
// 
//�{�X�̍X�V����
// 
//===================================
void CBoss::Update()
{
	D3DXVECTOR3 BossPos = GetPos();
	D3DXVECTOR3 BossMove = GetMove();
	//�ʒu���X�V
	BossPos += BossMove;
	BossMove.y -= 3.0f;//�d��
	//BossMove = D3DXVECTOR3(10.0f, 0.0f, 1.0f);
	
	
	
	
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
					D3DXVECTOR3 PlayerTargetPos = pPlayer->GetTargetPos();//�^�[�Q�b�g�̈ʒu�̎擾
					bool PlayerDushAttack = GetDushAttack();//�_�b�V���A�^�b�N�̎擾
					//�ʒu���X�V
					//PlayerPos += PlayerMove;
					if (PlayerPos.z >= 34060.0f)
					{
						if (m_wasMove == false)
						{
							m_wasMove = true;
							BossMove = D3DXVECTOR3(5.0f, 0.0f, 5.0f);
						}
					}
					
					/*pPlayer->SetPos(PlayerPos);
					D3DXVECTOR3 vec = PlayerTargetPos - PlayerMove;
					PlayerMove -= vec * 5.0f;
					
					
					
					if (BossPos.x >= PlayerPos.x - 85.0f
						&& BossPos.x <= PlayerPos.x + 85.0f
						&& BossPos.z >= PlayerPos.z - 115.0f
						&& BossPos.z <= PlayerPos.z + 5.0f)
					{

						pPlayer->Hit(1);
						PlayerMove.y = 0.0f;
						pPlayer->SetMove(-PlayerMove);
						
					}*/
					
				}
				// �|�C���^�����̃|�C���^�֕ύX
				pObj = pNext;
			}
		//}

	//}


	if (BossPos.x >= 225.0f || BossPos.x <= -225.0f)
	{
		BossMove.x *= -1.0f;

	}
	if (BossPos.y <= -50.0f)
	{
		CBoss::Uninit();
	}
	SetPos(BossPos);
	SetMove(BossMove);
	nCounterBullet--;
	if (nCounterBullet <= 0)
	{
		//�e�̐ݒ�
		CBoss_Bullet::Create(m_pos, D3DXVECTOR3(0.0f, 0.0f, -10.0f), 15);//�e�̌����ݒ�\
		nCounterBullet = 25;
		//�T�E���h�̍Đ�
		//CSound* pSound = CManager::GetSound();//�T�E���h�̎擾
		//pSound->PlaySound(CSound::SOUND_LABEL::SOUND_SE_MONSTER);
	}
	
}

//===================================
// 
//�{�X�̕`�揈��
// 
//===================================
void CBoss::Draw()
{
	CObject3D::Draw();//�|���S���`��
}
//===================================
// 
//�{�X�̐�������
//
//===================================
CBoss* CBoss::Create(const D3DXVECTOR3& pos)
{
	CBoss* pBoss = nullptr;
	pBoss = new CBoss();
	if (FAILED(pBoss->Init())) {
	}
	pBoss->SetPos(pos);
	pBoss->BindMesh(pBoss->GetMatModel(), pBoss->GetBuffer(), pBoss->GetMesh(), &m_pObj_Texture[0]);
	//pBoss->SetType(CObject::TYPE::BOSS);

	return pBoss;
}
//===================================
// 
//�{�X�̃��[�h����
//
//===================================
HRESULT CBoss::Load()
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER BossBuffer = GetBuffer();
	DWORD BossMatModel = GetMatModel();
	LPD3DXMESH BossMesh = GetMesh();
	//�e�N�X�`������
	if (FAILED(D3DXLoadMeshFromX("data\\boss.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &BossBuffer, nullptr, &BossMatModel, &BossMesh)))
	{
		return E_FAIL;
	}
	D3DXMATERIAL* pMat;
	pMat = (D3DXMATERIAL*)BossBuffer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < int(BossMatModel); nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename,
				&m_pObj_Texture[nCntMat]);
		}
	}
	SetBuffer(BossBuffer);
	SetMatModel(BossMatModel);
	SetMesh(BossMesh);
	return S_OK;

}
//===================================
// 
//�{�X�̃A�����[�h����
//
//===================================
void CBoss::Unload()
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
