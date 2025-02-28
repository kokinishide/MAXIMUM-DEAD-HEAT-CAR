////=============================================================================
////
//// �o���b�g���� [bullet.cpp]
//// Author :: Koki_Nishide
////
////=============================================================================
//#include "main.h"
//#include "bullet.h"
//#include "player.h"
//#include "input.h"
//#include "explosion.h"
//#include "enemy.h"
//#include"manager.h"
//#include"object.h"
//#include"object2D.h"
//#include "block.h"
//#include"helicopter.h"
//
////===================================
//// 
////�}�N����`
////
////===================================
//#define BULLET_SIZE_X (50.0f)//�ʂ̉���
//#define BULLET_SIZE_Y (50.0f)//�ʂ̏c��
//
////===================================
//// 
////�R���X�g���N�^
////
////===================================
//CBullet::CBullet()
//{
//
//}
////===================================
//// 
////�f�X�X�g���N�^
////
////===================================
//CBullet::~CBullet()
//{
//
//}
//
////===================================
//// 
////�e�̏���������
////
////===================================
//HRESULT CBullet::Init(void)
//{
//	
//	Load();
//	return S_OK;
//}
//
////===================================
//// 
////�e�̏I������
////
////===================================
//void CBullet::Uninit()
//{
//	CObject3D::Uninit();//this->Release();���g�̊J��
//	CObject::Release();
//}
////===================================
//// 
////�e�̍X�V����
////
////===================================
//void CBullet::Update()
//{
//	//VERTEX_2D* pVtx; //���_���̃|�C���^
//	m_pos += m_move;
//	m_nBulletLife--;
//	if (m_nBulletLife <= 0)
//	{
//		CObject::Release();
//		return;
//	}
//	//else
//	//{
//	//	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
//	//	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
//
//	//	//���_���W�̍X�V
//	//	pVtx[0].pos = D3DXVECTOR3(m_pos.x - BULLET_SIZE_X / 2, m_pos.y - BULLET_SIZE_Y / 2, 0.0f);
//	//	pVtx[1].pos = D3DXVECTOR3(m_pos.x + BULLET_SIZE_X / 2, m_pos.y - BULLET_SIZE_Y / 2, 0.0f);
//	//	pVtx[2].pos = D3DXVECTOR3(m_pos.x - BULLET_SIZE_X / 2, m_pos.y + BULLET_SIZE_Y / 2, 0.0f);
//	//	pVtx[3].pos = D3DXVECTOR3(m_pos.x + BULLET_SIZE_X / 2, m_pos.y + BULLET_SIZE_Y / 2, 0.0f);
//
//	//	//���_�o�b�t�@���A�����b�N����
//	//	m_pVtxBuff->Unlock();
//	//}
//
//	//if(m_pos = D3DXVECTOR3(0.0f, 585.0f, 0.0f) || nLife = 0)
//	//{
//	//	CExplosion::Create(m_pos, m_col);//��������
//	//	CObject::Release();//���M���폜
//	//	return;
//	//}
//	for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
//	{
//		//�G�Ƃ̓����蔻��i�z������ԂɃ`�F�b�N�j
//		for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
//		{
//			//�I�u�W�F�N�g�擾
//			CObject* pObj = CObject::GetMyObject(nCntPriority,nCntObj);
//			if (pObj != nullptr)
//			{
//				//��ނ̎擾�i�G�Ȃ瓖���蔻��j
//				CObject::TYPE type = pObj->GetType();
//				CBullet::BULLETTYPE Bullettype = m_Bullettype;
//				if (type == CObject::TYPE::HELICOPTER)
//				{
//					if (Bullettype == CBullet::BULLETTYPE::BULLETTYPE_PLAYER)
//					{
//						CHelicopter* pHelicopter = (CHelicopter*)pObj;
//						D3DXVECTOR3 HelicopterPos = pHelicopter->GetPos();//�ʒu�̎擾
//						D3DXVECTOR3 vec = m_TargetPos - m_pos;
//						m_pos += vec / 10.0f;
//
//						if (m_pos.x >= HelicopterPos.x - 35.0f
//							&& m_pos.x <= HelicopterPos.x + 35.0f
//							&& m_pos.z >= HelicopterPos.z - 35.0f
//							&& m_pos.z <= HelicopterPos.z + 35.0f)
//						{
//							pHelicopter->Hit(1);
//							//CExplosion::Create(m_pos, m_col);//�����̐���
//							//pEnemy->Uninit();//�G�̏I������
//							CBullet::Uninit();//�ʂ̏I������
//							break;
//						}
//						
//					}
//				}
//
//				if (type == CObject::TYPE::PLAYER)
//				{
//					if (Bullettype == CBullet::BULLETTYPE::BULLETTYPE_HELICOPTER)
//					{
//						CPlayer* pPlayer = (CPlayer*)pObj;
//						D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//�ʒu�̎擾
//						
//
//						if (m_pos.x >= PlayerPos.x - 10.0f
//							&& m_pos.x <= PlayerPos.x + 10.0f
//							&& m_pos.z >= PlayerPos.z - 10.0f
//							&& m_pos.z <= PlayerPos.z + 10.0f)
//						{
//							pPlayer->Hit(1);
//							//CExplosion::Create(m_pos, m_col);//�����̐���
//							//pPlayer->Uninit();//�v���C���[�̏I������
//							CBullet::Uninit();//�ʂ̏I������
//							break;
//						}
//						
//					}
//				}
//				if (type == CObject::TYPE::PLAYER)
//				{
//					if (Bullettype == CBullet::BULLETTYPE::BULLETTYPE_TRUCK)
//					{
//						CPlayer* pPlayer = (CPlayer*)pObj;
//						D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//�ʒu�̎擾
//
//
//						if (m_pos.x >= PlayerPos.x - 15
//							&& m_pos.x <= PlayerPos.x + 15
//							&& m_pos.z >= PlayerPos.z - 15
//							&& m_pos.z <= PlayerPos.z + 15)
//						{
//							pPlayer->Hit(1);
//							//CExplosion::Create(m_pos, m_col);//�����̐���
//							//pBlock->Uninit();//�u���b�N�̏I������
//							CBullet::Uninit();//�ʂ̏I������
//							break;
//							
//						}
//					}
//				}
//			}
//		}
//			
//		
//	}
//}
//
////===================================
//// 
////�e�̕`�揈��
////
////===================================
//void CBullet::Draw()
//{
//	CObject3D::Draw();//�|���S���`��
//}
//
////===================================
//// 
////CBullet����
////
////===================================
//CBullet* CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nBulletLife, BULLETTYPE type)
//{
//	LPDIRECT3DDEVICE9 pDevice;
//	//�f�o�C�X�̎擾
//	pDevice = CManager::GetRenderer()->GetDevice();
//	CBullet* pBullet = new CBullet();
//	
//	
//	pBullet->Init();
//	pBullet->SetPos(pos);//�����ʒu�ݒ�
//	pBullet->SetMove(move);
//	pBullet->SetBulletLife(nBulletLife);
//	pBullet->SetBulletType(type);
//	float fNearDistance = 10000.0f;
//	//LPDIRECT3DTEXTURE9 pTex;
//	for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
//	{
//		//�G�Ƃ̓����蔻��i�z������ԂɃ`�F�b�N�j
//		for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
//		{
//			//�I�u�W�F�N�g�擾
//			CObject* pObj = CObject::GetMyObject(nCntPriority, nCntObj);
//			if (pObj != nullptr)
//			{
//				
//				CEnemy* pEnemy = (CEnemy*)pObj;
//				if (pEnemy != nullptr)
//				{
//					D3DXVECTOR3 vec = pBullet->m_TargetPos - pEnemy->GetPos();
//					float fLength = D3DXVec3Length(&vec);
//					if (fLength > fNearDistance)
//					{
//						pBullet->m_TargetPos = pEnemy->GetPos();
//					}
//				}
//					
//				
//			}
//		}
//	}
//
//	//�e�N�X�`���̐ݒ�
//	pBullet->BindMesh(pBullet->GetMatModel(), pBullet->GetBuffer(), pBullet->GetMesh(),nullptr);
//	return pBullet;
//}
////===================================
////
////�ʂ̃��[�h����
////
////===================================
//HRESULT CBullet::Load()
//{
//	LPDIRECT3DDEVICE9 pDevice;
//	//�f�o�C�X�̎擾
//	pDevice = CManager::GetRenderer()->GetDevice();
//	LPD3DXBUFFER BulletBuffer = GetBuffer();
//	DWORD BulletMatModel = GetMatModel();
//	LPD3DXMESH BulletMesh = GetMesh();
//	/*if (FAILED(D3DXLoadMeshFromX("data\\misile.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &BulletBuffer, nullptr, &BulletMatModel, &BulletMesh)))
//	{
//		return E_FAIL;
//	}*/
//	
//	SetBuffer(BulletBuffer);
//	SetMatModel(BulletMatModel);
//	SetMesh(BulletMesh);
//	return S_OK;
//}
////===================================
//// 
////�ʂ̃A�����[�h����
////
////===================================
//void CBullet::Unload()
//{
//	CObject3D::Unload();
//}
////===================================
////
////�ʂ̃��C�t�ݒ�
////
////===================================
//void CBullet::SetBulletLife(int nBulletLife)
//{
//	m_nBulletLife = nBulletLife;
//}
//
////===================================
//// 
////�ʂ̃^�C�v�ݒ�
////
////===================================
//void CBullet::SetBulletType(BULLETTYPE Bullettype)
//{
//	m_Bullettype = Bullettype;
//}