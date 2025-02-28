//=============================================================================
//
// �W�����v�̃��b�Z�[�W�\������ [jump_message.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _JUMP_MESSAGE_H_//���̃}�N����`������ĂȂ�������
#define _JUMP_MESSAGE_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "object2D.h"
//�W�����v���b�Z�[�W�N���X
class CJump_Message :public CObject2D
{
public:
	CJump_Message(int nPriority = 1);
	~CJump_Message()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CJump_Message* Create(const D3DXVECTOR3& pos);//�W�����v���b�Z�[�W����
	int nCounterAnimJump;//�A�j���[�V�����J�E���^�[
	int nPatternAnimJump;//�A�j���[�V�����p�^�[��No.
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//���_�o�b�t�@
	LPDIRECT3DTEXTURE9 m_pTexture;//�e�N�X�`��
};

#endif//_JUMP_MESSAGE_H_