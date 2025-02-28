//=============================================================================
//
// �J�������� [camera.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "camera.h"
#include "input.h"
#include "game.h"
#include "renderer.h"
#include "manager.h"
#include "object3D.h"
#include "player.h"
//#include "model.h"

//===================================
// 
//�R���X�g���N�^
//
//===================================
CCamera::CCamera()
{
	m_posV; //���_
	m_posR; //�����X
	m_targetPosR;
	m_targetPosV;
	m_vecU; //������x�N�g��
	m_fDistance; //����
	m_mtxProjection; //�v���W�F�N�V�����}�g���b�N�X
	m_mtxView; //�r���[�}�g���b�N�X
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CCamera::~CCamera()
{

}
//===================================
// 
//�J�����̏���������
//
//===================================
HRESULT CCamera::Init(void)
{
	//m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //�ړ��ʂ�����������
	//m_posV = D3DXVECTOR3(0.0f, 50.0f, -200.0f);
	//m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fDistance = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_pos = m_posV;
	m_targetPosR = m_posR;
	m_targetPosV = m_posV;

	return S_OK;

}
//===================================
// 
//�J�����̏I������
//
//===================================
void CCamera::Uninit()
{

}
//===================================
// 
//�J�����̍X�V����
//
//===================================
void CCamera::Update()
{
	if (CGame::GetPlayer() != nullptr)
	{
		m_posR = CGame::GetPlayer()->GetPos();
		m_posV = m_posR + D3DXVECTOR3(0.0f, 250.0f, -180.0f);
	}

	//�ʒu���X�V
	/*model* Model = GetModel();
	g_posCamera = Model->pos;*/

	//XINPUT_STATE joykeystate;
	//if(XINPUT_STATE(0,&joykeystate))
	//m_pos += m_move;
	//if (CManager::GetKeyboard()->GetPress(DIK_Z) == true)//LEFT
	//{
	//	m_rot.y += 0.07f;
	//}
	//else if (CManager::GetKeyboard()->GetPress(DIK_C) == true)//RIGHT
	//{
	//	m_rot.y -= 0.07f;
	//}
	///*if (Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	//{
	//	g_camera.rot.y += 0.07f;
	//}*/

	////if (GetJoypadPress(STICKANGLE_LEFT) == true)//LEFT
	////{
	////	g_camera.rot.y += 0.07f;
	////}
	////else if (GetJoypadPress(STICKANGLE_RIGHT) == true)//RIGHT
	////{
	////	g_camera.rot.y -= 0.07f;
	////}

	//m_posR = m_pos;
	//m_posV.x = sinf(m_rot.y) * -180.0f + m_posR.x;//�ς���̂͂���
	//m_posV.z = cosf(m_rot.y) * -180.0f + m_posR.z;//�ς���̂͂���
	//m_posV.y = m_posR.y + 250;

	//m_pos.x = m_pos.x;
	//m_pos.y = m_pos.y;
	//m_pos.z = m_pos.z;

	////�ړ��ʂ��X�V�i����������j
	//m_move.x += (0.0f - m_move.x) * 0.2f;

	//m_move.y += (0.0f - m_move.y) * 0.2f;

	//m_move.z += (0.0f - m_move.z) * 0.2f;

	//m_posR.x += (0.1f - 0.0f) * 0.2f;
	//m_posV.x += (0.1f - 0.0f) * 0.2f;
}
//===================================
// 
//�J�����̐ݒ菈��
//
//===================================
void CCamera::SetCamera()
{
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);
	//�v���W�F�N�V�����}�g���b�N�X���쐬
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection, D3DXToRadian(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 10.0f, 1000.0f);
	////���s���e(���ˉe)
	//D3DXMatrixOrthoLH(&m_mtxProjection, (float)SCREEN_HEIGHT, (float)SCREEN_WIDTH, 10.0f, 1000.0f);

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);
	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&m_mtxView, &m_posV, &m_posR, &m_vecU);

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

}