//=============================================================================
//
// ���f������ [model.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _MODEL_H_//���̃}�N����`������ĂȂ�������
#define _MODEL_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object3D.h"
#include "scene.h"
//�}�N����`
#define MAX_MODEL (100) //���f���̍ő吔
#define MAX_ROW (100) //���f���̍s
#define MAX_COL (100) //���f���̗�

//���f���Ǘ�
class CModel : public CObject3D
{
public:
	CModel();//�R���X�g���N�^
	~CModel();//�f�X�g���N�^
	void Unload();//���f���j��
	int Regist(const char* pModelName);//���f���o�^
	//LPDIRECT3DTEXTURE9 GetAddress(int nIdx);//���f���擾
	LPD3DXMESH GetMesh(int nIdx) { return pMesh[nIdx]; }//���b�V���擾�ȂǗp��
	LPD3DXBUFFER GetBuffer(int nIdx) { return pBuff[nIdx]; }//�}�e���A���ւ̃|�C���^�̎擾�ȂǗp��
	DWORD GetMatModel(int nIdx) { return dwNumMatModel[nIdx]; }//�}�e���A���̐��̎擾�ȂǗp��
	LPDIRECT3DTEXTURE9 GetTexture(int nIdx) { return m_pTexture[nIdx]; }//�e�N�X�`���̎擾�ȂǗp��
private:
	static LPDIRECT3DTEXTURE9 m_pTexture[MAX_MODEL];
	//const char* m_pModelName[MAX_MODEL];//�ۊǃf�[�^�̔z��
	//char m_pModelName;
	//int row = MAX_ROW;//�s
	//int col = MAX_COL;//��
	char m_pModelName[MAX_ROW][MAX_COL];		//�ۊǃf�[�^�̔z��
	static int m_nNumAll;//���f���̑���
	LPD3DXMESH pMesh[MAX_MODEL];
	LPD3DXBUFFER pBuff[MAX_MODEL];
	DWORD dwNumMatModel[MAX_MODEL];
	
};

#endif //_MODEL_H_