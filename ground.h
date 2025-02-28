//=============================================================================
//
// �O���E���h���� [ground.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _GROUND_H_//���̃}�N����`������ĂȂ�������
#define _GROUND_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "object3D.h"

//�}�N����`
#define MAX_GROUND (1) //�n�ʂ̍ő吔

//�O���E���h
class CGround :public CObject3D
{
public:
	CGround();//�R���X�g���N�^
	virtual~CGround()override;//�f�X�g���N�^
	virtual HRESULT Init()override;//�����ݒ�
	virtual void Uninit()override;//�I������
	virtual void Update()override;//�X�V����
	virtual void Draw()override;//�`�揈��
	static CGround* Create(const D3DXVECTOR3& pos);//��������
	HRESULT Load(); //Texture���[�h
	void Unload();//Texture�A�����[�h
	LPDIRECT3DTEXTURE9* GetTexture() { return &m_pObj_Texture[0]; }
private:
	static const int MAX_MAT = 100;
	static LPDIRECT3DTEXTURE9 m_pObj_Texture[MAX_MAT];
	int m_nTextureIdx;
};

#endif //_GROUND_H_

