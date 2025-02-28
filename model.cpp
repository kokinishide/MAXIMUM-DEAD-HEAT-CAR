//=============================================================================
//
// ���f���Ǘ����� [model.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "manager.h"
#include"model.h"
#include"game.h"
#include"object.h"
#include"texture.h"
#include<string.h>
LPDIRECT3DTEXTURE9 CModel::m_pTexture[MAX_MODEL] = {};
int CModel::m_nNumAll = 0;


//===================================
// 
//�R���X�g���N�^
//
//===================================
CModel::CModel()
{
	for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
	{
		//�e�����o�̏�����
		m_pTexture[nCnt] = nullptr;
		pMesh[nCnt] = nullptr;
		pBuff[nCnt] = nullptr;
		//m_pModelName[nCnt] = nullptr;
	}
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CModel::~CModel()
{

}
//===================================
// 
//���f���j��
// 
//===================================
void CModel::Unload()
{
	for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
	{
		//�e�N�X�`���z��̔j��
		if (m_pTexture[nCnt] != nullptr)
		{
			//m_pTexture[nCnt]->Release();
			m_pTexture[nCnt] = nullptr;
		}
		//���b�V���z��̔j��
		if (pMesh[nCnt] != nullptr)
		{
			//pMesh[nCnt]->Release();
			pMesh[nCnt] = nullptr;
		}
		//�o�b�t�@�z��̔j��
		if (pBuff[nCnt] != nullptr)
		{
			//pBuff[nCnt]->Release();
			pBuff[nCnt] = nullptr;
		}
		////�ۊǃf�[�^�̔j��
		//if (m_pModelName[nCnt] != nullptr)
		//{
		//	m_pModelName[nCnt] = nullptr;
		//}
	}
}
//===================================
// 
//���f���o�^
//
//===================================
int CModel::Regist(const char* pModelName)
{
	
	CTexture* pTexture = CManager::GetTexture();//�e�N�X�`���̎擾;
	int nIdx = 0;//���f��ID
	for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
	{
		if (pBuff[nCnt] == nullptr)
		{//�o�^����ĂȂ�����
			nIdx = nCnt;//ID�ݒ�
			//���f���ǂݍ���
			LPDIRECT3DDEVICE9 pDevice = nullptr;
			pDevice = CManager::GetRenderer()->GetDevice();
			//�e�N�X�`������
			if (FAILED(D3DXLoadMeshFromX(pModelName, D3DXMESH_SYSTEMMEM, pDevice, nullptr, &pBuff[nIdx], nullptr, &dwNumMatModel[nIdx], &pMesh[nIdx])))
			{
				return E_FAIL;
			}
			D3DXMATERIAL* pMat;
			pMat = (D3DXMATERIAL*)pBuff[nIdx]->GetBufferPointer();
			for (int nCntMat = 0; nCntMat < int(dwNumMatModel[nIdx]); nCntMat++)
			{
				if (pMat[nCntMat].pTextureFilename != nullptr)
				{
					pTexture->Regist(pMat[nCntMat].pTextureFilename);
				}
			}

			//�p�X�̓o�^
			m_pModelName[nCnt][0];
			//�������������
			strcpy(&m_pModelName[nCnt][0],pModelName);
			m_nNumAll++;//���f����
			break;
		}
		else if (strcmp(&m_pModelName[nCnt][0], pModelName) == 0)
		{//���łɐ�������Ă��郂�f���ƈ�v����
			nIdx = nCnt;//ID�ݒ�
			break;
		}
	}
	return nIdx;//ID��Ԃ�
}
//���f���擾(����ID�̃��f����Ԃ�)
//LPDIRECT3DTEXTURE9 CModel::GetAddress(int nIdx)//���f���擾
//{
//	return m_pModel[nIdx];
//}