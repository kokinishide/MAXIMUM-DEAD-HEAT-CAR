//=============================================================================
//
// �p�[�e�B�N������ [particle.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _PARTICLE_H_//���̃}�N����`������ĂȂ�������
#define _PARTICLE_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object2D.h"

//�}�N����`
#define MAX_PARTICLE (1024)//�p�[�e�B�N���̍ő吔
//�p�[�e�B�N���N���X
class CParticle :public CObject2D
{
public:
	//�p�[�e�B�N���̎��
	typedef enum
	{
		PARTICLETYPE_MODEL = 0,//�v���C���[�̃p�[�e�B�N��
		PARTICLETYPE_ENEMY, //�G�̃p�[�e�B�N��
		PARTICLETYPE_MAX
	}PARTICLETYPE;
	CParticle(int nPriority = 1);
	~CParticle()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CParticle* Create(const D3DXVECTOR3& pos);//Particle����
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//���_�o�b�t�@
	LPDIRECT3DTEXTURE9 m_pTexture;//�e�N�X�`��
};
//�v���g�^�C�v�錾
//void InitParticle(void);
//void UninitParticle(void);
//void UpdateParticle(void);
//void DrawParticle(void);
//void SetParticle(D3DXVECTOR3 pos, int nType, D3DXVECTOR3 move, float fRadius);

#endif //_PARTICLE_H_
