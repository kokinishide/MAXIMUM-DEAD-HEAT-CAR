//=============================================================================
//
// �Q�[�W�\������ [gauge.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _GAUGE_H_//���̃}�N����`������ĂȂ�������
#define _GAUGE_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "object2D.h"
//�Q�[�W�N���X
class CGauge :public CObject2D
{
public:
	CGauge(int nPriority = 1);
	~CGauge()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CGauge* Create(const D3DXVECTOR3& pos);//�Q�[�W����
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//���_�o�b�t�@
	LPDIRECT3DTEXTURE9 m_pTexture;//�e�N�X�`��
};

#endif// _GAUGE_H_