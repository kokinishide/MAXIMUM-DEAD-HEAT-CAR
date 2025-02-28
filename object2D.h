//=============================================================================
//
// �I�u�W�F�N�g2D���� [object2D.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _OBJECT2D_H_//���̃}�N����`������ĂȂ�������
#define _OBJECT2D_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include"object.h"

//2D�|���S���Ǘ��N���X
class CObject2D :public CObject
{
public:

	CObject2D();
	CObject2D(int nPriority);
	virtual ~CObject2D()override;//object.h��virtual���Ȃ���΁Aoverride�������B
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	void BindTexture(LPDIRECT3DTEXTURE9 pTex);//�e�N�X�`������
	void SetPos(D3DXVECTOR3 pos); //�ʒu��ݒ�
	void SetMove(D3DXVECTOR3 move); //������ݒ�
	void SetRot(D3DXVECTOR3 rot); //������ݒ�
	void SetCol(D3DXCOLOR col) { m_col = col; }//�J���[��ݒ�
	void SetColA(float fAlpha) { m_col.a = fAlpha; }
	static CObject2D* Create();//Object2D����
	D3DXVECTOR3 GetPos() { return m_pos; }//�ʒu�擾�ȂǗp��
	D3DXVECTOR3 GetMove() { return m_move; }//�����擾�ȂǗp��
	void SetPosX(float x);
	void SetPosY(float y);
	void SetSizeW(float w);
	void SetSizeH(float h);
	int nCounterAnim;//�A�j���[�V�����J�E���^�[
	int nPatternAnim;//�A�j���[�V�����p�^�[��No.

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//���_�o�b�t�@
	int m_nTextureIdx;//�e�N�X�`���̃C���f�b�N�X
private:
	/*static CObject2D* m_pObject2D;*/
	D3DXVECTOR3 m_pos; //���݂̈ʒu
	D3DXVECTOR3 m_move; //���݂̓���
	D3DXVECTOR3 m_rot; // ����
	D3DXCOLOR m_col;//�J���[
	LPDIRECT3DTEXTURE9 m_pTexture;//�e�N�X�`��


	//float m_posX;	// �ʒu��X���W
	//float m_posY;	// �ʒu��Y���W
	float m_sizeW;	// ��
	float m_sizeH;	// ����
};


#endif //_OBJECT2D_H_