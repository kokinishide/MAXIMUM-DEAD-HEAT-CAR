//=============================================================================
//
// �^�񒆒ʘH�̃��b�Z�[�W�\������ [middle_message.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _MIDDLE_MESSAGE_H_//���̃}�N����`������ĂȂ�������
#define _MIDDLE_MESSAGE_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "object2D.h"
//�^�񒆃��b�Z�[�W�N���X
class CMiddle_Message :public CObject2D
{
public:
	CMiddle_Message(int nPriority = 1);
	~CMiddle_Message()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CMiddle_Message* Create(const D3DXVECTOR3& pos);//�^�񒆃��b�Z�[�W����
	int nCounterAnimJump;//�A�j���[�V�����J�E���^�[
	int nPatternAnimJump;//�A�j���[�V�����p�^�[��No.
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//���_�o�b�t�@
	LPDIRECT3DTEXTURE9 m_pTexture;//�e�N�X�`��
};

#endif//_MIDDLE_MESSAGE_H_