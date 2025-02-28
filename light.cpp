//=============================================================================
//
// ���C�g���� [light.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "light.h"
#include "manager.h"
#include "renderer.h"

//===================================
// 
//�R���X�g���N�^
//
//===================================
CLight::CLight()
{
	//���C�g���̃N���A
	ZeroMemory(&m_aLight, sizeof(D3DLIGHT9));
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CLight::~CLight()
{

}
//===================================
// 
//���C�g�̏���������
//
//===================================
HRESULT CLight::Init(void)
{

	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	D3DXVECTOR3 vecDir; //�ݒ�p�����x�N�g��

	//���C�g�̏����N���A����
	ZeroMemory(&m_aLight, sizeof(D3DLIGHT9));

	//���C�g�̎�ނ�ݒ�
	m_aLight[MAX_DATA].Type = D3DLIGHT_DIRECTIONAL;

	//���C�g�̊g�U����ݒ�
	m_aLight[MAX_DATA].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//���C�g�̕�����ݒ�
	vecDir = D3DXVECTOR3(0.2f, -0.8f, 0.4f);
	D3DXVec3Normalize(&vecDir, &vecDir);//�x�N�g���𐳋K������

	m_aLight[MAX_DATA].Direction = vecDir;
	//���C�g��ݒ肷��
	pDevice->SetLight(0, &m_aLight[MAX_DATA]);
	//���C�g��L���ɂ���
	pDevice->LightEnable(0, TRUE);
	return S_OK;
}
