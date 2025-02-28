//=============================================================================
//
// ���f���p�[�c���� [modelparts.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _MODELPARTS_H_//���̃}�N����`������ĂȂ�������
#define	_MODELPARTS_H_//2�d�C���N���[�h�h�~�̃}�N����`
#include"objectX.h"

class CModelParts:public CObjectX
{
public:
	CModelParts();//�R���X�g���N�^
	virtual~CModelParts()override;//�f�X�g���N�^
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	void SetMotionPos(D3DXVECTOR3 pos); //�ʒu
	void SetMotionRot(D3DXVECTOR3 rot); //����
	static CModelParts* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, LPD3DXMESH pMesh, LPD3DXBUFFER pBuffMat, DWORD dwNumMat);
private: 
	D3DXVECTOR3 m_MotionPos;//���Έʒu
	D3DXVECTOR3 m_MotionRot;//���Ό���
	CModelParts* m_pParent;//�e���f���p�[�c�ւ̃|�C���^
};

#endif //_MODELPARTS_H_