//=============================================================================
//
// �{�X�̃o���b�g���� [boss_bullet.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _BOSS_BULLET_H_//���̃}�N����`������ĂȂ�������
#define _BOSS_BULLET_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include"object3D.h"
#include "bullet.h"
//�}�N����`
#define MAX_BULLET (128) //�e�̍ő吔
//�{�X�̒e
class CBoss_Bullet : public CObject3D
{
public:
	CBoss_Bullet();
	virtual~CBoss_Bullet()override;
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	//virtual void Hit(int nDamage)override;
	//void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, BULLETTYPE type);
	static CBoss_Bullet* Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nBulletLife);
	virtual HRESULT Load()override; //�e�N�X�`���̃��[�h
	void Unload();//�e�N�X�`���̃A�����[�h
	void SetBulletLife(int nBulletLife); //�ʒu�擾�ȂǗp��
private:
	//�K�v�ȃ����o
	static CBoss_Bullet* m_apBullet[MAX_BULLET];//�I�u�W�F�N�g�Ǘ�
	D3DXVECTOR3 m_TargetPos;//�^�[�Q�b�g�̈ʒu
	int m_nBulletLife;//�e�̎�������

};

#endif//_BOSS_BULLET_H_