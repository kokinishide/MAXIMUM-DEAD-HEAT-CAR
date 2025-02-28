//=============================================================================
//
// �u���b�N���� [block.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "input.h"
#include "block.h"
#include "bullet.h"
#include "explosion.h"
#include "object2D.h"
#include "manager.h"
#include "enemy.h"
//#include "game.h"
//#include "score.h"


//�}�N����`
#define NUM_BLOCK	(4) //�u���b�N�̎��

//===================================
// 
//�R���X�g���N�^
//
//===================================
CBlock::CBlock()
{

}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CBlock::~CBlock()
{

}


//===================================
// 
//�u���b�N�̏���������
// 
//===================================
HRESULT CBlock::Init()
{
	if (FAILED(CObject3D::Init()))//���_�o�b�t�@�쐬
	{//���s
		return E_FAIL;
	}
	Load();
	CBlock::m_nLife = 3;
	//���_���ݒ�ɕK�v��
	//�Z�`�T�C�Y�Ȃǂ̃p�����[�^�ݒ�
	CObject3D::SetSizeW(40.0f);
	CObject3D::SetSizeH(40.0f);
	SetType(CObject::TYPE::BLOCK);
	return S_OK;//����

}

//===================================
// 
//�u���b�N�̃q�b�g����
//
//===================================
void CBlock::Hit(int nDamage)
{
	CObject3D::Hit(nDamage);
}
//===================================
// 
//�u���b�N�̏I������
// 
//===================================
void CBlock::Uninit()
{
	CObject3D::Uninit();//this->Release();���g�̊J��
}

//===================================
// 
//�u���b�N�̍X�V����
// 
//===================================
void CBlock::Update()
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
				pObj->GetType();
				if (CObject::TYPE::PLAYER)
				{
					CPlayer* pPlayer = (CPlayer*)pObj;
					D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//�ʒu�̎擾
					D3DXVECTOR3 PlayerPosOld = pPlayer->GetPosOld();//�Â��ʒu�̎擾
					D3DXVECTOR3 PlayerMove = pPlayer->GetMove();//�����̎擾

					
						if (PlayerPosOld.x <= m_pos.x - 20.0f
						&& PlayerPos.x > m_pos.x - 20.0f
						&& PlayerPos.y > m_pos.y - 10.0f
						&& PlayerPos.y < m_pos.y + 10.0f
						&& PlayerPos.z > m_pos.z - 130.0f
						&& PlayerPos.z < m_pos.z + 130.0f)
						{
						//bIsLanding = true;
						PlayerPos.x = m_pos.x - 20.0f;
						PlayerMove.x = 0.0f;

						pPlayer->SetPos(PlayerPos); //�ʒu��ݒ�
						pPlayer->SetMove(PlayerMove); //������ݒ�
						//pPlayer->SetIsLanding(bIsLanding); //���n��ݒ�

						}
						if (PlayerPosOld.x >= m_pos.x + 20.0f
							&& PlayerPos.x < m_pos.x + 20.0f
							&& PlayerPos.y < m_pos.y + 10.0f
							&& PlayerPos.y > m_pos.y - 10.0f
							&& PlayerPos.z < m_pos.z + 130.0f
							&& PlayerPos.z > m_pos.z - 130.0f)
						{
							//bIsLanding = true;
							PlayerPos.x = m_pos.x + 20.0f;
							PlayerMove.x = 0.0f;

							pPlayer->SetPos(PlayerPos); //�ʒu��ݒ�
							pPlayer->SetMove(PlayerMove); //������ݒ�
							//pPlayer->SetIsLanding(bIsLanding); //���n��ݒ�
						}
						//if (PlayerPosOld.y <= m_pos.y - 20.0f
						//&& PlayerPos.y > m_pos.y - 20.0f
						//&& PlayerPos.x > m_pos.x - 10.0f
						//&& PlayerPos.x < m_pos.x + 10.0f
						//&& PlayerPos.z > m_pos.z - 130.0f
						//&& PlayerPos.z < m_pos.z + 130.0f)
						//{
						//	bIsLanding = true;
						//	PlayerPos.y = m_pos.y - 20.0f;
						//	PlayerMove.y = 0.0f;

						//	pPlayer->SetPos(PlayerPos); //�ʒu��ݒ�
						//	pPlayer->SetMove(PlayerMove); //������ݒ�
						//	pPlayer->SetIsLanding(bIsLanding); //���n��ݒ�
						//}
						if (PlayerPosOld.y >= m_pos.y + 50.0f
							&& PlayerPos.y < m_pos.y + 50.0f
							&& PlayerPos.x < m_pos.x + 10.0f
							&& PlayerPos.x > m_pos.x - 10.0f
							&& PlayerPos.z < m_pos.z + 130.0f
							&& PlayerPos.z > m_pos.z - 130.0f)
						{
							bIsLanding = true;
							PlayerPos.y = m_pos.y + 50.0f;
							PlayerMove.y = 0.0f;

							pPlayer->SetPos(PlayerPos); //�ʒu��ݒ�
							pPlayer->SetMove(PlayerMove); //������ݒ�
							pPlayer->SetIsLanding(bIsLanding); //���n��ݒ�
						}
				}
				if (CObject::TYPE::ENEMY)
				{
					CEnemy* pEnemy = (CEnemy*)pObj;
					D3DXVECTOR3 EnemyPos = pEnemy->GetPos();//�ʒu�̎擾
					D3DXVECTOR3 EnemyPosOld = pEnemy->GetPosOld();//�Â��ʒu�̎擾
					D3DXVECTOR3 EnemyMove = pEnemy->GetMove();//�����̎擾

					if (EnemyPosOld.x <= m_pos.x - 20.0f
						&& EnemyPos.x > m_pos.x - 20.0f
						&& EnemyPos.y > m_pos.y - 10.0f
						&& EnemyPos.y < m_pos.y + 10.0f
						&& EnemyPos.z > m_pos.z - 130.0f
						&& EnemyPos.z < m_pos.z + 130.0f)
					{
						//bIsLanding = true;
						EnemyPos.x = m_pos.x - 20.0f;
						EnemyMove.x = 0.0f;

						pEnemy->SetPos(EnemyPos); //�ʒu��ݒ�
						pEnemy->SetMove(EnemyMove); //������ݒ�
						//pEnemy->SetIsLanding(bIsLanding); //���n��ݒ�

					}
					if (EnemyPosOld.x >= m_pos.x + 20.0f
						&& EnemyPos.x < m_pos.x + 20.0f
						&& EnemyPos.y < m_pos.y + 10.0f
						&& EnemyPos.y > m_pos.y - 10.0f
						&& EnemyPos.z < m_pos.z + 130.0f
						&& EnemyPos.z > m_pos.z - 130.0f)
					{
						//bIsLanding = true;
						EnemyPos.x = m_pos.x + 20.0f;
						EnemyMove.x = 0.0f;

						pEnemy->SetPos(EnemyPos); //�ʒu��ݒ�
						pEnemy->SetMove(EnemyMove); //������ݒ�
						//pPlayer->SetIsLanding(bIsLanding); //���n��ݒ�
					}
					//if (PlayerPosOld.y <= m_pos.y - 20.0f
					//&& PlayerPos.y > m_pos.y - 20.0f
					//&& PlayerPos.x > m_pos.x - 10.0f
					//&& PlayerPos.x < m_pos.x + 10.0f
					//&& PlayerPos.z > m_pos.z - 130.0f
					//&& PlayerPos.z < m_pos.z + 130.0f)
					//{
					//	bIsLanding = true;
					//	PlayerPos.y = m_pos.y - 20.0f;
					//	PlayerMove.y = 0.0f;

					//	pPlayer->SetPos(PlayerPos); //�ʒu��ݒ�
					//	pPlayer->SetMove(PlayerMove); //������ݒ�
					//	pPlayer->SetIsLanding(bIsLanding); //���n��ݒ�
					//}
					if (EnemyPosOld.y >= m_pos.y + 50.0f
						&& EnemyPos.y < m_pos.y + 50.0f
						&& EnemyPos.x < m_pos.x + 10.0f
						&& EnemyPos.x > m_pos.x - 10.0f
						&& EnemyPos.z < m_pos.z + 130.0f
						&& EnemyPos.z > m_pos.z - 130.0f)
					{
						bIsLanding = true;
						EnemyPos.y = m_pos.y + 50.0f;
						EnemyMove.y = 0.0f;

						pEnemy->SetPos(EnemyPos); //�ʒu��ݒ�
						pEnemy->SetMove(EnemyMove); //������ݒ�
						pEnemy->SetIsLanding(bIsLanding); //���n��ݒ�
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
//�u���b�N�̕`�揈��
// 
//===================================
void CBlock::Draw()
{
	CObject3D::Draw();//�|���S���`��
}
//===================================
// 
//CBlock����
//
//===================================
CBlock* CBlock::Create(const D3DXVECTOR3& pos)
{
	CBlock* pBlock = nullptr;
	pBlock = new CBlock();
	if (FAILED(pBlock->Init())) {
	}
	pBlock->SetPos(pos);
	pBlock->BindMesh(pBlock->GetMatModel(), pBlock->GetBuffer(), pBlock->GetMesh(),nullptr);
	//pBlock->SetType(CObject::TYPE::BLOCK);
	return pBlock;
}
//===================================
//
//�u���b�N�̃��[�h����
//
//===================================
HRESULT CBlock::Load()
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER BlockBuffer = GetBuffer();
	DWORD BlockMatModel = GetMatModel();
	LPD3DXMESH BlockMesh = GetMesh();
	if (FAILED(D3DXLoadMeshFromX("data\\guardleale.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &BlockBuffer, nullptr, &BlockMatModel, &BlockMesh)))
	{
		return E_FAIL;
	}
	SetBuffer(BlockBuffer);
	SetMatModel(BlockMatModel);
	SetMesh(BlockMesh);
	return S_OK;
}
//===================================
//
//�u���b�N�̃A�����[�h����
//
//===================================
void CBlock::Unload()
{
	CObject3D::Unload();
}


////�^�C�v�ݒ�
//void CBlock::SetBulletType(BULLETTYPE type)
//{
//	m_type = type;
//}