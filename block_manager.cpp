//=============================================================================
//
// �u���b�N�̃}�l�[�W���[���� [block_manager.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include<stdio.h>
#include"block.h"
#include"block_manager.h"
#include"manager.h"
#include"object.h"
#include"object2D.h"
#include"renderer.h"

//===================================
// 
//�R���X�g���N�^
//
//===================================
CBlock_Manager::CBlock_Manager()
{
	m_apBlockList[1] = nullptr;

}
//===================================
// 
//�f�X�g���N�^
//
//===================================
CBlock_Manager::~CBlock_Manager()
{

}
//===================================
// 
//�u���b�N�}�l�[�W���[�̏���������
//
//===================================
HRESULT CBlock_Manager::Init()
{
	//int nIndex;

	////�u���b�N�̔z�u
	////CBlock::Load();//�ǂݍ���(�j����CManager::Uninit��)
	//m_apBlockList[1] = CBlock::Create(D3DXVECTOR3(-220.0f, -1.0f, 0.0f));


	//m_apBlockList[1] = CBlock::Create(D3DXVECTOR3(220.0f, -1.0f, 0.0f));
	//m_apBlockList[1] = CBlock::Create(D3DXVECTOR3(220.0f, -1.0f, 400.0f));
	////�o�^
	//for (nIndex = 0; nIndex < 1; nIndex++)
	//{
	//	m_apBlockList[nIndex] = pBlock;
	//}
	return S_OK;
}
//===================================
// 
//�u���b�N�}�l�[�W���[�̏I������
// 
//===================================
void CBlock_Manager::Uninit()
{
	
}