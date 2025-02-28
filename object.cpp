//=============================================================================
//
// �I�u�W�F�N�g���� [object.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include<stdio.h>
#include"object.h"
#include"object2D.h"
#include"player.h"

//===================================
// 
//�ÓI�����o������
//
//===================================
int CObject::m_nNumAll = 0;
CObject* CObject::m_apMyObject[m_nMAX_PRIORITY][MAX_DATA] = {};
CObject* CObject::m_pTop = nullptr;//�擪�̃I�u�W�F�N�g�̃|�C���^
CObject* CObject::m_pCur = nullptr;//���݁i�Ō���j�̃|�C���^

//CObject* CObject::m_apObject = {};
//CObject2D* CObject2D::m_pObject2D;
////CPlayer* CPlayer;

//===================================
//
//�R���X�g���N�^(�v���C�I���e�B)
//
//===================================
CObject::CObject(int nPriority)
{

	m_pPrev = nullptr;
	m_pNext = nullptr;
	if (m_pTop == nullptr)
	{ //�擪���󂾂�����
		m_pTop = this;//�������g����
		m_pCur = this;
	}

	if (m_pCur != nullptr)
	{//�Ō�������݂���
		m_pCur->m_pNext = this;//�����̈�O�̃I�u�W�F�N�g�̎��̃I�u�W�F�N�g�Ɏ������g����
		m_pPrev = m_pCur;//�����̈�O�̃I�u�W�F�N�g�Ƃ��čŌ����ݒ�
	}

	// �Ō�����������g�ɍX�V
	m_pCur = this;

	m_nPriority = nPriority;//�`��D��x�ݒ�
	m_bUseRelease = true;
	m_bDeath = false;
	m_nNumAll++;//�������J�E���g�A�b�vRelease


#if 0
	//m_type = NONE;
	int nCnt;
	m_nPriority = nPriority;//�`��D��x�ݒ�
	m_bUseRelease = true;
	m_bDeath = false;
	for (nCnt = 0; nCnt < MAX_DATA; nCnt++)
	{
		if (m_apMyObject[nPriority][nCnt] == nullptr)
		{
			m_apMyObject[nPriority][nCnt] = this;//�������g����
			m_nID = nCnt;//�������g��ID����
			m_nNumAll++;//�������J�E���g�A�b�vRelease
			break; //���[�v�𔲂���
		}
	}
#endif
}
//===================================
// 
//�f�X�g���N�^
//
//===================================
CObject::~CObject()
{

}
//===================================
// 
//�I�u�W�F�N�g�̏���������
//
//===================================
HRESULT CObject::Init(void)
{
	return S_OK;
}
//===================================
// 
//�S�I�u�W�F�N�g���
//
//===================================
void CObject::ReleaseAll()
{
	//int nCntObj;
	CObject* pObj = m_pTop;//�擪�擾
	//�ő吔���s���Ȃ̂�While���g�p
	while (pObj != nullptr)
	{
		CObject* pNext = pObj->m_pNext;
		pObj->Uninit();
		pObj = pNext;
	}

	pObj = m_pTop;//�擪�擾
	while (pObj != nullptr)
	{
		CObject* pNext = pObj->m_pNext;

		if (pObj->m_bDeath == true)
		{
			pObj->Release();
		}

		pObj = pNext;
	}

	//CObject* pObj = m_pTop;//�擪�擾
	////�ő吔���s���Ȃ̂�While���g�p
	//while (pObj != nullptr)
	//{
	//	CObject* pNext = pObj->m_pNext;
	//	pObj->Release();
	//	pObj = pNext;
	//}
	//int nCntObj;


	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)//NULL
	//{

	//	for (nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
	//		if (m_apMyObject[nCntPriority][nCntObj] != nullptr)
	//		{
	//			//if (m_apMyObject[nCntPriority][nCntObj]->m_type == TYPE::FADE)
	//			//{
	//			//	int n = 0;
	//			//}
	//			if (m_apMyObject[nCntPriority][nCntObj]->m_bUseRelease == true)
	//			{

	//				m_apMyObject[nCntPriority][nCntObj]->Uninit();//�������g����
	//			}
	//		}
	//	}
	//}
}
//===================================
// 
//�S�I�u�W�F�N�g�X�V
//
//===================================
void CObject::UpdateAll()
{
	//int nCntObj;
	CObject* pObj = m_pTop;//�擪�擾
	//�ő吔���s���Ȃ̂�While���g�p
	while (pObj != nullptr)
	{
		// ���̃|�C���^��ۑ����Ă���
		CObject* pNext = pObj->m_pNext;
		// ��肽�����������s�i����͍X�V�j
		pObj->Update();
		// �|�C���^�����̃|�C���^�֕ύX
		pObj = pNext;
	}

	//pObj = m_pTop;//�擪�擾
	//while (pObj != nullptr)
	//{
	//	CObject* pNext = pObj->m_pNext;

	//	if (pObj->m_bDeath == true)
	//	{
	//		pObj->Release();
	//	}

	//	pObj = pNext;
	//}
	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	//{

	//	for (nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
	//		//CObject::TYPE type = m_apMyObject[nCntPriority][nCntObj]->GetType();

	//		if (m_apMyObject[nCntPriority][nCntObj] != nullptr)
	//		{
	//			m_apMyObject[nCntPriority][nCntObj]->Update();//�������g����

	//		}
	//	}
	//}

}
//===================================
// 
//�S�I�u�W�F�N�g�`��
//
//===================================
void CObject::DrawAll()
{
	CObject* pObj = m_pTop;//�擪�擾
	//�ő吔���s���Ȃ̂�While���g�p
	while (pObj != nullptr)
	{
		// ���̃|�C���^��ۑ����Ă���
		CObject* pNext = pObj->m_pNext;

		// ��肽�����������s�i����͕`��j
		pObj->Draw();

		// �|�C���^�����̃|�C���^�֕ύX
		pObj = pNext;
	}
	//int nCntObj;
	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	//{
	//	for (nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
	//		if (m_apMyObject[nCntPriority][nCntObj] != nullptr)
	//		{
	//			m_apMyObject[nCntPriority][nCntObj]->Draw();//�������g����

	//		}
	//	}
	//}

}
//===================================
// 
//�������g�̉��
//
//===================================
void CObject::Release()
{
	//Uninit();
	if (m_pTop == this)
	{
		m_pTop = m_pNext;
	}

	if (m_pCur == this)
	{
		m_pCur = m_pPrev;
	}

	if (m_pPrev != nullptr)
	{
		m_pPrev->m_pNext = m_pNext;
	}

	if (m_pNext != nullptr)
	{
		m_pNext->m_pPrev = m_pPrev;
	}
	
	//if (m_pTop == nullptr)
	//{ //�擪���󂾂�����
	//	m_pTop = this;//�������g����
	//}

	//if (m_pCur != nullptr)
	//{//�Ō�������݂���
	//	m_pCur->m_pNext = this;//�����̈�O�̃I�u�W�F�N�g�̎��̃I�u�W�F�N�g�Ɏ������g����
	//	m_pPrev = m_pCur;//�����̈�O�̃I�u�W�F�N�g�Ƃ��čŌ����ݒ�
	//}


	//int nID = m_nID;
	//int nPriority = m_nPriority;
	//
	//if (m_apMyObject[nPriority][nID] != nullptr)
	//{
	//	delete m_apMyObject[nPriority][nID];
	//	m_apMyObject[nPriority][nID] = nullptr;
	//	m_nNumAll--;//�������J�E���g�_�E��
	//}
	delete this;
}

//===================================
// 
//�I�u�W�F�N�g�擾(�v���C�I���e�B)
//
//===================================
CObject* CObject::GetMyObject()
{
	return m_pTop;//�擪�擾

	//return m_apMyObject[nPriority][nIdx];

}
//===================================
// 
//�^�C�v�擾
//
//===================================
CObject::TYPE CObject::GetType()
{
	return m_type;
}
//===================================
// 
//�l�N�X�g�擾
//
//===================================
CObject* CObject::GetNext()
{
	return m_pNext;
}
//===================================
// 
//�^�C�v�ݒ�
//
//===================================
void CObject::SetType(TYPE type)
{
	m_type = type;
}
//===================================
// 
//�q�b�g����
//
//===================================
//void CObject::Hit(int nDamage)
//{
//	
//}
////===================================
//// 
////�S�[���q�b�g����
////
////===================================
//void CObject::HitGoal(int nHit)
//{
//
//}
////===================================
//// 
////���[�v�q�b�g����
////
////===================================
//void CObject::HitWarp(int nHitWarp)
//{
//
//}