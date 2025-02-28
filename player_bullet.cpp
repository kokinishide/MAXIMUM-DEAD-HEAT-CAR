//=============================================================================
//
// �v���C���[�̃o���b�g���� [player_bullet.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player_bullet.h"
#include "player.h"
#include "input.h"
#include "explosion.h"
#include "enemy.h"
#include"manager.h"
#include"object.h"
#include"object2D.h"
#include "block.h"
#include"helicopter.h"

//===================================
// 
//�}�N����`
//
//===================================
#define BULLET_SIZE_X (50.0f)//�ʂ̉���
#define BULLET_SIZE_Y (50.0f)//�ʂ̏c��

//===================================
// 
//�R���X�g���N�^
//
//===================================
CPlayer_Bullet::CPlayer_Bullet()
{
	m_TargetPos;//�^�[�Q�b�g�̈ʒu
	m_nBulletLife;//�e�̎�������
	bHoming = false;
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CPlayer_Bullet::~CPlayer_Bullet()
{

}

//===================================
// 
//�v���C���[�̒e�̏���������
//
//===================================
HRESULT CPlayer_Bullet::Init(void)
{
	Load();
	//���f���ݒ�
	CModel* pModel = CManager::GetModel();//�擾
	m_nModelIdx = pModel->Regist("data\\misile.x");//�o�^
	DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//�ݒ�
	return S_OK;
}

//===================================
// 
//�v���C���[�̒e�̏I������
//
//===================================
void CPlayer_Bullet::Uninit()
{
	CObject3D::Uninit();//this->Release();���g�̊J��
	m_bDeath = true;
}
//===================================
// 
//�v���C���[�̒e�̍X�V����
//
//===================================
void CPlayer_Bullet::Update()
{
	if (bHoming == true)
	{
		m_move = (m_TargetPos - m_pos) * 0.3f;
	}

	m_pos += m_move;
	m_nBulletLife--;
	if (m_nBulletLife <= 0)
	{
		m_bDeath = true;
		return;
	}
	//else
	//{
	//	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	//	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//	//���_���W�̍X�V
	//	pVtx[0].pos = D3DXVECTOR3(m_pos.x - BULLET_SIZE_X / 2, m_pos.y - BULLET_SIZE_Y / 2, 0.0f);
	//	pVtx[1].pos = D3DXVECTOR3(m_pos.x + BULLET_SIZE_X / 2, m_pos.y - BULLET_SIZE_Y / 2, 0.0f);
	//	pVtx[2].pos = D3DXVECTOR3(m_pos.x - BULLET_SIZE_X / 2, m_pos.y + BULLET_SIZE_Y / 2, 0.0f);
	//	pVtx[3].pos = D3DXVECTOR3(m_pos.x + BULLET_SIZE_X / 2, m_pos.y + BULLET_SIZE_Y / 2, 0.0f);

	//	//���_�o�b�t�@���A�����b�N����
	//	m_pVtxBuff->Unlock();
	//}

	//if(m_pos = D3DXVECTOR3(0.0f, 585.0f, 0.0f) || nLife = 0)
	//{
	//	CExplosion::Create(m_pos, m_col);//��������
	//	CObject::Release();//���M���폜
	//	return;
	//}
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
				//CPlayer_Bullet::BULLETTYPE Bullettype = m_Bullettype;
				if (CObject::TYPE::HELICOPTER == pObj->GetType())
				{
					/*if (Bullettype == CPlayer_Bullet::BULLETTYPE::BULLETTYPE_PLAYER)
					{*/
						CHelicopter* pHelicopter = (CHelicopter*)pObj;
						D3DXVECTOR3 HelicopterPos = pHelicopter->GetPos();//�ʒu�̎擾
						D3DXVECTOR3 vec = m_TargetPos - m_pos;
						//m_pos += vec / 10.0f;

						if (m_pos.x >= HelicopterPos.x - 35.0f
							&& m_pos.x <= HelicopterPos.x + 35.0f
							&& m_pos.z >= HelicopterPos.z - 35.0f
							&& m_pos.z <= HelicopterPos.z + 35.0f)
						{
							pHelicopter->Hit(1);
							//CExplosion::Create(m_pos, m_col);//�����̐���
							//pEnemy->Uninit();//�G�̏I������
							CPlayer_Bullet::Uninit();//�ʂ̏I������
							//break;
						}

					//}
				}

				//if (CObject::TYPE::PLAYER)
				//{
				//	if (Bullettype == CBullet::BULLETTYPE::BULLETTYPE_HELICOPTER)
				//	{
				//		CPlayer* pPlayer = (CPlayer*)pObj;
				//		D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//�ʒu�̎擾


				//		if (m_pos.x >= PlayerPos.x - 10.0f
				//			&& m_pos.x <= PlayerPos.x + 10.0f
				//			&& m_pos.z >= PlayerPos.z - 10.0f
				//			&& m_pos.z <= PlayerPos.z + 10.0f)
				//		{
				//			pPlayer->Hit(1);
				//			//CExplosion::Create(m_pos, m_col);//�����̐���
				//			//pPlayer->Uninit();//�v���C���[�̏I������
				//			CBullet::Uninit();//�ʂ̏I������
				//			break;
				//		}

				//	}
				//}
				//if (CObject::TYPE::PLAYER)
				//{
				//	if (Bullettype == CBullet::BULLETTYPE::BULLETTYPE_TRUCK)
				//	{
				//		CPlayer* pPlayer = (CPlayer*)pObj;
				//		D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//�ʒu�̎擾


				//		if (m_pos.x >= PlayerPos.x - 15
				//			&& m_pos.x <= PlayerPos.x + 15
				//			&& m_pos.z >= PlayerPos.z - 15
				//			&& m_pos.z <= PlayerPos.z + 15)
				//		{
				//			pPlayer->Hit(1);
				//			//CExplosion::Create(m_pos, m_col);//�����̐���
				//			//pBlock->Uninit();//�u���b�N�̏I������
				//			CBullet::Uninit();//�ʂ̏I������
				//			break;

				//		}
				//	}
				//}
				// �|�C���^�����̃|�C���^�֕ύX
				pObj = pNext;
			}
		//}


	//}
}

//===================================
// 
//�v���C���[�̒e�̕`�揈��
//
//===================================
void CPlayer_Bullet::Draw()
{
	CObject3D::Draw();//�|���S���`��
}

//===================================
// 
//CPlayer_Bullet����
//
//===================================
CPlayer_Bullet* CPlayer_Bullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nBulletLife)
{
	LPDIRECT3DDEVICE9 pDevice;
	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	CPlayer_Bullet* pPlayer_Bullet = new CPlayer_Bullet();
	pPlayer_Bullet->Init();
	pPlayer_Bullet->SetPos(pos);//�����ʒu�ݒ�
	pPlayer_Bullet->SetMove(move);
	pPlayer_Bullet->SetBulletLife(nBulletLife);
	float fNearDistance = 1000.0f;
	
	//LPDIRECT3DTEXTURE9 pTex;
	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	//{
	//	//�G�Ƃ̓����蔻��i�z������ԂɃ`�F�b�N�j
	//	for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
			//�I�u�W�F�N�g�擾
			CObject* pObj = CObject::GetMyObject();
			if (pObj != nullptr)
			{
				//��ނ̎擾�i�G�Ȃ瓖���蔻��j
				CObject::TYPE type = pObj->GetType();
				if (type == CObject::TYPE::HELICOPTER)
				{
					CHelicopter* pHelicopter = (CHelicopter*)pObj;
					if (pHelicopter != nullptr)
					{
						D3DXVECTOR3 vec = pHelicopter->GetPos() - pPlayer_Bullet->m_pos;
						float fLength = D3DXVec3Length(&vec);
						if (fLength < fNearDistance)
						{
							fNearDistance = fLength;
							pPlayer_Bullet->m_TargetPos = pHelicopter->GetPos();
							pPlayer_Bullet->bHoming = true;
							//int n = 0;
							//break;
						}
					}
				}
			}
		//}
	//}

	//�e�N�X�`���̐ݒ�
	pPlayer_Bullet->BindMesh(pPlayer_Bullet->GetMatModel(), pPlayer_Bullet->GetBuffer(), pPlayer_Bullet->GetMesh(), nullptr);
	return pPlayer_Bullet;
}
//===================================
//
//�v���C���[�̋ʂ̃��[�h����
//
//===================================
HRESULT CPlayer_Bullet::Load()
{
	LPDIRECT3DDEVICE9 pDevice;
	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER Player_BulletBuffer = GetBuffer();
	DWORD Player_BulletMatModel = GetMatModel();
	LPD3DXMESH Player_BulletMesh = GetMesh();
	CPlayer_Bullet* pBullet = new CPlayer_Bullet();
	if (FAILED(D3DXLoadMeshFromX("data\\misile.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &Player_BulletBuffer, nullptr, &Player_BulletMatModel, &Player_BulletMesh)))
	{
		return E_FAIL;
	}
	SetBuffer(Player_BulletBuffer);
	SetMatModel(Player_BulletMatModel);
	SetMesh(Player_BulletMesh);
	return S_OK;
}
//===================================
// 
//�v���C���[�̋ʂ̃A�����[�h����
//
//===================================
void CPlayer_Bullet::Unload()
{
	CObject3D::Unload();
}
//===================================
//
//�v���C���[�̋ʂ̃��C�t�ݒ�
//
//===================================
void CPlayer_Bullet::SetBulletLife(int nBulletLife)
{
	m_nBulletLife = nBulletLife;
}