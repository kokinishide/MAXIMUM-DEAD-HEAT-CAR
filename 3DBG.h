//=============================================================================
//
// 3D�w�i���� [3DBG.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _3DBG_H_//���̃}�N����`������ĂȂ�������
#define _3DBG_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "object3D.h"

//�}�N����`
#define MAX_3DBG (128) //3D�w�i�̍ő吔

//3D�w�i
class C3DBG :public CObject3D
{
public:
	C3DBG();//�R���X�g���N�^
	virtual~C3DBG()override;//�f�X�g���N�^
	virtual HRESULT Init()override;//�����ݒ�
	virtual void Uninit()override;//�I������
	virtual void Update()override;//�X�V����
	virtual void Draw()override;//�`�揈��
	static C3DBG* Create(const D3DXVECTOR3& pos);//��������
	HRESULT Load(); //X�t�@�C�����[�h
	void Unload();//X�t�@�C���A�����[�h
	LPDIRECT3DTEXTURE9* GetTexture() { return &m_pObj_Texture[0]; }
private:
	static const int MAX_MAT = 100;
	static LPDIRECT3DTEXTURE9 m_pObj_Texture[MAX_MAT];
	int nCounterBullet;
	int m_nTextureIdx;
	char m_aTextureFilename[100] = "data\\";
};

#endif //_3DBG_H_


