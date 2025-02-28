//=============================================================================
//
// �G�̃o���b�g���� [enemy_bullet.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _ENEMY_BULLET_H_//���̃}�N����`������ĂȂ�������
#define _ENEMY_BULLET_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include"object3D.h"
#include "bullet.h"
//�}�N����`
#define MAX_BULLET (128) //�e�̍ő吔
//�G�̒e
class CEnemy_Bullet : public CObject3D
{
public:
	//�e�̎��
	typedef enum
	{
		BULLETTYPE_HELICOPTER = 0, //�w���R�v�^�[�̒e
		BULLETTYPE_TRUCK, //�g���b�N�̒e
		BULLETTYPE_MAX
	}BULLETTYPE;
	CEnemy_Bullet();
	virtual~CEnemy_Bullet()override;
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	//virtual void Hit(int nDamage)override;
	//void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, BULLETTYPE type);
	static CEnemy_Bullet* Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nBulletLife, BULLETTYPE Bullettype);
	virtual HRESULT Load()override; //�e�N�X�`���̃��[�h
	void Unload();//�e�N�X�`���̃A�����[�h
	void SetBulletLife(int nBulletLife); //�ʒu�擾�ȂǗp��
	void SetBulletType(BULLETTYPE Bullettype);
private:
	//�K�v�ȃ����o
	static CEnemy_Bullet* m_apBullet[MAX_BULLET];//�I�u�W�F�N�g�Ǘ�
	D3DXVECTOR3 m_TargetPos;//�^�[�Q�b�g�̈ʒu
	BULLETTYPE m_Bullettype;//�ʂ̎��
	int m_nBulletLife;//�e�̎�������
};

#endif//_ENEMY_BULLET_H_