////=============================================================================
////
//// �o���b�g���� [bullet.h]
//// Author :: Koki_Nishide
////
////=============================================================================
//#ifndef _BULLET_H_//���̃}�N����`������ĂȂ�������
//#define _BULLET_H_//2�d�C���N���[�h�h�~�̃}�N����`
//
//#include "main.h"
//#include"object3D.h"
////�}�N����`
//#define MAX_BULLET (128) //�e�̍ő吔
//
////�e
//class CBullet : public CObject3D
//{
//public:
//	//�e�̎��
//	typedef enum
//	{
//		BULLETTYPE_PLAYER = 0,//�v���C���[�̒e
//		BULLETTYPE_HELICOPTER, //�w���R�v�^�[�̒e
//		BULLETTYPE_TRUCK, //�g���b�N�̒e
//		BULLETTYPE_MAX
//	}BULLETTYPE;
//	CBullet();
//	virtual~CBullet()override;
//	virtual HRESULT Init()override;
//	virtual void Uninit()override;
//	virtual void Update()override;
//	virtual void Draw()override;
//	//virtual void Hit(int nDamage)override;
//	//void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, BULLETTYPE type);
//	static CBullet* Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nBulletLife, BULLETTYPE Bullettype);
//	virtual HRESULT Load();//�e�N�X�`���̃��[�h
//	void Unload();//�e�N�X�`���̃A�����[�h
//
//	int m_nBulletLife;//�e�̎�������
//	void SetBulletLife(int nBulletLife); //�ʒu�擾�ȂǗp��
//	void SetBulletType(BULLETTYPE Bullettype);
//private:
//	//�K�v�ȃ����o
//	static CBullet* m_apBullet[MAX_BULLET];//�I�u�W�F�N�g�Ǘ�
//	D3DXVECTOR3 m_TargetPos;//�^�[�Q�b�g�̈ʒu
//	BULLETTYPE m_Bullettype;//�ʂ̎��
//
//};
//
//#endif//_BULLET_H_
//
