//=============================================================================
//
// �{�X�̃��b�Z�[�W�\������ [boss_message.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _BOSS_MESSAGE_H_//���̃}�N����`������ĂȂ�������
#define _BOSS_MESSAGE_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "object2D.h"
//�{�X���b�Z�[�W�N���X
class CBoss_Message :public CObject2D
{
public:
	CBoss_Message(int nPriority = 1);
	~CBoss_Message()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CBoss_Message* Create(const D3DXVECTOR3& pos);//�{�X���b�Z�[�W����
	
private:
	int nCounterAnimBoss;//�A�j���[�V�����J�E���^�[
	int nPatternAnimBoss;//�A�j���[�V�����p�^�[��No.
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//���_�o�b�t�@
	LPDIRECT3DTEXTURE9 m_pTexture;//�e�N�X�`��
};

#endif//_BOSS_MESSAGE_H_