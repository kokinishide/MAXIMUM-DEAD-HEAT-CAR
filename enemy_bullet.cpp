//=============================================================================
//
// �G�̃o���b�g���� [enemy_bullet.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "enemy_bullet.h"
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
CEnemy_Bullet::CEnemy_Bullet()
{
	m_TargetPos;//�^�[�Q�b�g�̈ʒu
	m_Bullettype;//�ʂ̎��
	m_nBulletLife;//�e�̎�������
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CEnemy_Bullet::~CEnemy_Bullet()
{

}

//===================================
// 
//�G�̒e�̏���������
//
//===================================
HRESULT CEnemy_Bullet::Init(void)
{
	Load();
	//���f���ݒ�
	CModel* pModel = CManager::GetModel();//�擾
	m_nModelIdx = pModel->Regist("data\\bullet.x");//�o�^
	DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//�ݒ�
	return S_OK;
}

//===================================
// 
//�G�̒e�̏I������
//
//===================================
void CEnemy_Bullet::Uninit()
{
	CObject3D::Uninit();//this->Release();���g�̊J��
	m_bDeath = true;
}
//===================================
// 
//�G�̒e�̍X�V����
//
//===================================
void CEnemy_Bullet::Update()
{
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
				CEnemy_Bullet::BULLETTYPE Bullettype = m_Bullettype;
				//if (CObject::TYPE::HELICOPTER == pObj->GetType())
				//{
				//	if (Bullettype == CEnemy_Bullet::BULLETTYPE::BULLETTYPE_PLAYER)
				//	{
				//		CHelicopter* pHelicopter = (CHelicopter*)pObj;
				//		D3DXVECTOR3 HelicopterPos = pHelicopter->GetPos();//�ʒu�̎擾
				//		D3DXVECTOR3 vec = m_TargetPos - m_pos;
				//		m_pos += vec / 10.0f;

				//		if (m_pos.x >= HelicopterPos.x - 35.0f
				//			&& m_pos.x <= HelicopterPos.x + 35.0f
				//			&& m_pos.z >= HelicopterPos.z - 35.0f
				//			&& m_pos.z <= HelicopterPos.z + 35.0f)
				//		{
				//			pHelicopter->Hit(1);
				//			//CExplosion::Create(m_pos, m_col);//�����̐���
				//			//pEnemy->Uninit();//�G�̏I������
				//			CEnemy_Bullet::Uninit();//�ʂ̏I������
				//			break;
				//		}

				//	}
				//}

				if (CObject::TYPE::PLAYER == pObj->GetType())
				{
					if (Bullettype == CEnemy_Bullet::BULLETTYPE::BULLETTYPE_HELICOPTER)
					{
						CPlayer* pPlayer = (CPlayer*)pObj;
						D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//�ʒu�̎擾


						if (m_pos.x >= PlayerPos.x - 10.0f
							&& m_pos.x <= PlayerPos.x + 10.0f
							&& m_pos.z >= PlayerPos.z - 10.0f
							&& m_pos.z <= PlayerPos.z + 10.0f)
						{
							pPlayer->Hit(1);
							//CExplosion::Create(m_pos, m_col);//�����̐���
							//pPlayer->Uninit();//�v���C���[�̏I������
							CEnemy_Bullet::Uninit();//�ʂ̏I������
							//break;
						}

					}
				}
				if (CObject::TYPE::PLAYER == pObj->GetType())
				{
					if (Bullettype == CEnemy_Bullet::BULLETTYPE::BULLETTYPE_TRUCK)
					{
						CPlayer* pPlayer = (CPlayer*)pObj;
						D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//�ʒu�̎擾


						if (m_pos.x >= PlayerPos.x - 15
							&& m_pos.x <= PlayerPos.x + 15
							&& m_pos.z >= PlayerPos.z - 15
							&& m_pos.z <= PlayerPos.z + 15)
						{
							pPlayer->Hit(1);
							//CExplosion::Create(m_pos, m_col);//�����̐���
							//pBlock->Uninit();//�u���b�N�̏I������
							CEnemy_Bullet::Uninit();//�ʂ̏I������
							//break;

						}
					}
				}
				// �|�C���^�����̃|�C���^�֕ύX
				pObj = pNext;
			}
		//}


	//}
}

//===================================
// 
//�G�̒e�̕`�揈��
//
//===================================
void CEnemy_Bullet::Draw()
{
	CObject3D::Draw();//�|���S���`��
}

//===================================
// 
//CEnemy_Bullet����
//
//===================================
CEnemy_Bullet* CEnemy_Bullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nBulletLife, BULLETTYPE type)
{
	LPDIRECT3DDEVICE9 pDevice;
	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	CEnemy_Bullet* pEnemy_Bullet = new CEnemy_Bullet();
	pEnemy_Bullet->Init();
	pEnemy_Bullet->SetPos(pos);//�����ʒu�ݒ�
	pEnemy_Bullet->SetMove(move);
	pEnemy_Bullet->SetBulletLife(nBulletLife);
	pEnemy_Bullet->SetBulletType(type);
	//�e�N�X�`���̐ݒ�
	pEnemy_Bullet->BindMesh(pEnemy_Bullet->GetMatModel(), pEnemy_Bullet->GetBuffer(), pEnemy_Bullet->GetMesh(), nullptr);
	return pEnemy_Bullet;
}
//===================================
//
//�G�̋ʂ̃��[�h����
//
//===================================
HRESULT CEnemy_Bullet::Load()
{
	LPDIRECT3DDEVICE9 pDevice;
	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER Enemy_BulletBuffer = GetBuffer();
	DWORD Enemy_BulletMatModel = GetMatModel();
	LPD3DXMESH Enemy_BulletMesh = GetMesh();
	CEnemy_Bullet* pBullet = new CEnemy_Bullet();
	if (FAILED(D3DXLoadMeshFromX("data\\bullet.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &Enemy_BulletBuffer, nullptr, &Enemy_BulletMatModel, &Enemy_BulletMesh)))
	{
		return E_FAIL;
	}
	SetBuffer(Enemy_BulletBuffer);
	SetMatModel(Enemy_BulletMatModel);
	SetMesh(Enemy_BulletMesh);
	return S_OK;
}
//===================================
// 
//�G�̋ʂ̃A�����[�h����
//
//===================================
void CEnemy_Bullet::Unload()
{
	CObject3D::Unload();
}
//===================================
//
//�G�̋ʂ̃��C�t�ݒ�
//
//===================================
void CEnemy_Bullet::SetBulletLife(int nBulletLife)
{
	m_nBulletLife = nBulletLife;
}

//===================================
// 
//�G�̋ʂ̃^�C�v�ݒ�
//
//===================================
void CEnemy_Bullet::SetBulletType(BULLETTYPE Bullettype)
{
	m_Bullettype = Bullettype;
}