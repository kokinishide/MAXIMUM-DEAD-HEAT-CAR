//=============================================================================
//
// �w�i���� [bg.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _BG_H_//���̃}�N����`������ĂȂ�������
#define	_BG_H_//2�d�C���N���[�h�h�~�̃}�N����`
#include "object.h"

class CBG :public CObject
{
public:
	CBG(int nPriority = 1);
	~CBG()override;
	 HRESULT Init()override;
	 void Uninit()override;
	 void Update()override;
	 void Draw()override;
	//void BindTexture(LPDIRECT3DTEXTURE9 pTex);//�e�N�X�`������
	//D3DXVECTOR3 m_pos; //���݂̈ʒu
	//D3DXVECTOR3& GetPos() { return m_pos; }//�ʒu�擾�ȂǗp��
	//D3DXVECTOR3& SetPos(D3DXVECTOR3 pos); //�ʒu�擾�ȂǗp��
	static CBG* Create();//BG����
	int nCounterAnimBG;//�A�j���[�V�����J�E���^�[
	int nPatternAnimBG;//�A�j���[�V�����p�^�[��No.
private:
	/*static CObject2D* m_pObject2D;*/
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//���_�o�b�t�@
	LPDIRECT3DTEXTURE9 m_pTexture;//�e�N�X�`��
};

#endif //_BG_H_

