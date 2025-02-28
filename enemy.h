//=============================================================================
//
// �G�l�~�[���� [enemy.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _ENEMY_H_//���̃}�N����`������ĂȂ�������
#define _ENEMY_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object3D.h"

//�}�N����`
#define MAX_ENEMY (128) //�G�̍ő吔

//�G�l�~�[�N���X
class CEnemy : public CObject3D
{
public:
	CEnemy();
	virtual~CEnemy()override;
	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int nDamage)override;

	static CEnemy* Create(const D3DXVECTOR3& pos);
	HRESULT Load();
	void Unload();
	LPDIRECT3DTEXTURE9* GetTexture() { return &m_pObj_Texture[0]; }
private:
	static const int MAX_MAT = 100;
	static LPDIRECT3DTEXTURE9 m_pObj_Texture[MAX_MAT];
	int nCounterBullet;
	int m_nTextureIdx;
	D3DXVECTOR3 m_TargetPos;//�^�[�Q�b�g�̈ʒu

};

#endif// _ENEMY_H_

