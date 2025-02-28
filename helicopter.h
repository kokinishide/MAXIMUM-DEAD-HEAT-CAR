//=============================================================================
//
// �w���R�v�^�[�G�l�~�[���� [helicopter.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _HELICOPTER_H_//���̃}�N����`������ĂȂ�������
#define _HELICOPTER_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object3D.h"

//�}�N����`
#define MAX_HELICOPTER (128) //�w���R�v�^�[�̍ő吔

//�w���R�v�^�[�N���X
class CHelicopter : public CObject3D
{
public:
	CHelicopter();
	virtual~CHelicopter()override;
	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int nDamage)override;

	static CHelicopter* Create(const D3DXVECTOR3& pos);
	HRESULT Load();
	void Unload();
	LPDIRECT3DTEXTURE9* GetTexture() { return &m_pObj_Texture[0]; }
private:
	static const int MAX_MAT = 100;
	static LPDIRECT3DTEXTURE9 m_pObj_Texture[MAX_MAT];
	int nCounterBullet;
	int m_nTextureIdx;


};

#endif// _HELICOPTER_H_

