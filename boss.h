//=============================================================================
//
// �{�X���� [boss.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _BOSS_H_//���̃}�N����`������ĂȂ�������
#define _BOSS_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object3D.h"

//�{�X�N���X
class CBoss : public CObject3D
{
public:
	CBoss();
	virtual~CBoss()override;
	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int nDamage)override;

	static CBoss* Create(const D3DXVECTOR3& pos);
	HRESULT Load();
	void Unload();
	LPDIRECT3DTEXTURE9* GetTexture() { return &m_pObj_Texture[0]; }
private:
	static const int MAX_MAT = 100;
	static LPDIRECT3DTEXTURE9 m_pObj_Texture[MAX_MAT];
	int nCounterBullet;
	int m_nTextureIdx;
	D3DXVECTOR3 m_TargetPos;//�^�[�Q�b�g�̈ʒu

	bool m_wasMove;//�����������Ȃ���
};

#endif// _BOSS_H_
