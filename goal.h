//=============================================================================
//
// �S�[������ [goal.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _GOAL_H_//���̃}�N����`������ĂȂ�������
#define _GOAL_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "object3D.h"

//�S�[��
class CGoal :public CObject3D
{
public:
	CGoal();//�R���X�g���N�^
	virtual~CGoal()override;//�f�X�g���N�^
	virtual HRESULT Init()override;//�����ݒ�
	virtual void Uninit()override;//�I������
	virtual void Update()override;//�X�V����
	virtual void Draw()override;//�`�揈��
	static CGoal* Create(const D3DXVECTOR3& pos);//��������
	HRESULT Load(); //Texture���[�h
	void Unload();//Texture�A�����[�h
	LPDIRECT3DTEXTURE9* GetTexture() { return &m_pObj_Texture[0]; }
private:
	static const int MAX_MAT = 100;
	static LPDIRECT3DTEXTURE9 m_pObj_Texture[MAX_MAT];
};


#endif //_GOAL_H_


