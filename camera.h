//=============================================================================
//
// �J�������� [camera.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _CAMERA_H_//���̃}�N����`������ĂȂ�������
#define	_CAMERA_H_//2�d�C���N���[�h�h�~�̃}�N����`
#include "main.h"
#include"object3D.h"

//�J����
class CCamera : public CObject3D
{
public:
	CCamera();
	~CCamera();
	HRESULT Init();
	void Uninit();
	void Update();
	void SetCamera();//�J�����̐ݒ�
	//void SetShake(10,0.2f);//�ݒ�p
private:
	D3DXVECTOR3 m_posV; //���_
	D3DXVECTOR3 m_posR; //�����X
	/*int 10;
	float 0.2f;*/
	D3DXVECTOR3 m_targetPosR;
	D3DXVECTOR3 m_targetPosV;
	D3DXVECTOR3 m_vecU; //������x�N�g��
	D3DXVECTOR3 m_fDistance; //����
	D3DXMATRIX m_mtxProjection; //�v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX m_mtxView; //�r���[�}�g���b�N�X
	//D3DXVECTOR3 m_moveV; //���_�ړ�
	//D3DXVECTOR3 m_moveR; //���_�ړ�
	
};


#endif//_CAMERA_H_