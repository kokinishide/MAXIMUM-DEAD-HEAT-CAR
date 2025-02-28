//=============================================================================
//
// HP�����\������ [HP.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _HP_H_//���̃}�N����`������ĂȂ�������
#define _HP_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "object2D.h"
//HP�����N���X
class CHP :public CObject2D
{
public:
	CHP(int nPriority = 1);
	~CHP()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CHP* Create(const D3DXVECTOR3& pos);//HP��������
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//���_�o�b�t�@
	LPDIRECT3DTEXTURE9 m_pTexture;//�e�N�X�`��
};

#endif// _HP_H_