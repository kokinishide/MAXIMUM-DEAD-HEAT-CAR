//=============================================================================
//
// �I�u�W�F�N�gX���� [objectX.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _OBJECTX_H_//���̃}�N����`������ĂȂ�������
#define _OBJECTX_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include"object.h"
#define MAX_MOTION_TEXTURE (16)

//�N���X
class CObjectX :public CObject
{
public:
	CObjectX();//�R���X�g���N�^
	virtual~CObjectX()override;//�f�X�g���N�^
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	void SetPos(D3DXVECTOR3 pos); //�ʒu
	void SetRot(D3DXVECTOR3 rot); //����
	static CObjectX* Create(D3DXVECTOR3 pos,D3DXVECTOR3 rot, LPD3DXMESH pMesh, LPD3DXBUFFER pBuffMat, DWORD dwNumMat);
	D3DXMATRIX GetWorldMat();
private:
	D3DXVECTOR3 m_pos;//�ʒu
	D3DXVECTOR3 m_rot;//����
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//���_�o�b�t�@
	LPD3DXMESH m_pMesh; //���b�V���i���_���j�ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMat; //�}�e���A���ւ̃|�C���^
	DWORD m_dwNumMat; //�}�e���A���̐�
	D3DXMATRIX m_mtxWorld; //���[���h�}�g���b�N�X
	LPDIRECT3DTEXTURE9 m_pTexture[MAX_MOTION_TEXTURE];//�e�N�X�`���ւ̃|�C���^

};
#endif //_OBJECTX_H_