//=============================================================================
//
// �v���C���[���� [player.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _PLAYER_H_//���̃}�N����`������ĂȂ�������
#define _PLAYER_H_//�Q�d�C���N���[�h�h�~�̃}�N����`
#include"object3D.h"
#include"modelparts.h"
#include"bullet.h"

//�}�N����`
#define PLAYER_HEIGHT (40.0f)
#define MAX_PARTS (32)
#define MAX_KEY_SET (2)
//�L�[�f�[�^
struct KEY
{
	//�ʒu
	float fPosX;
	float fPosY;
	float fPosZ;

	//����
	float fRotX;
	float fRotY;
	float fRotZ;
};
//�L�[���
struct KEYSET
{
	int nFrame;
	KEY aKey[MAX_PARTS];
};

//�v���C���[�|���S���Ǘ��N���X
class CPlayer :public CObject3D
{
public:
	CPlayer();
	virtual ~CPlayer()override;
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Hit(int nDamage)override;
	virtual void HitGoal(int nHit)override;
	virtual void HitWarp(int nHitWarp)override;
	//CBullet::BULLETTYPE type;
	static CPlayer* Create(D3DXVECTOR3 pos);//Object2D����
	HRESULT Load();
	void Unload();

private:
	//�L�[���
	KEYSET m_aKeySet[MAX_KEY_SET];
	CModelParts* m_apModel[MAX_PARTS];
	int m_nNumKey; //�L�[�̑���
	int m_nCurKey; //���݂̃L�[�ԍ�
	int m_nCntMotion; //���[�V�����J�E���^�[
	int nCounterDushAttack;//�_�b�V���A�^�b�N�J�E���^�[
};

#endif//_PLAYER_H_

