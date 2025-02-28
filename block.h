//=============================================================================
//
// �u���b�N���� [block.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _BLOCK_H_//���̃}�N����`������ĂȂ�������
#define _BLOCK_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "object3D.h"

//�}�N����`
#define MAX_BLOCK (128) //�G�̍ő吔

//�u���b�N�̏��
typedef enum
{
	BLOCKSTATE_NORMAL = 0, //�ʏ���
	BLOCKSTATE_DAMAGE, //�_���[�W���
	BLOCKSTATE_MAX

}BLOCKSTATE;

//�u���b�N
class CBlock :public CObject3D
{
public:
	CBlock();//�R���X�g���N�^
	virtual~CBlock()override;//�f�X�g���N�^
	virtual HRESULT Init()override;//�����ݒ�
	virtual void Uninit()override;//�I������
	virtual void Update()override;//�X�V����
	virtual void Draw()override;//�`�揈��
	virtual void Hit(int nDamage)override;//�q�b�g����
	static CBlock* Create(const D3DXVECTOR3& pos);//��������
	HRESULT Load(); //Texture���[�h
	void Unload();//Texture�A�����[�h
};


#endif //_BLOCK_H_


