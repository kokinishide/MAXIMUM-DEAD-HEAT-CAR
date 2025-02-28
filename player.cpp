//=============================================================================
//
// �v���C���[���� [player.cpp]
// Author :: Koki_Nishide
//
//=============================================================================

#include "main.h"
#include "player.h"
#include "input.h"
#include "manager.h"
#include "bullet.h"
#include "object3D.h"
#include "ground.h"
#include "enemy.h"
#include "truck.h"
#include "player_bullet.h"
#include "boss.h"

//===================================
//
//�R���X�g���N�^
//
//===================================
CPlayer::CPlayer()
{
	nCounterDushAttack;//�_�b�V���A�^�b�N�J�E���^�[

	m_nNumKey = 0; //�L�[�̑���
	m_nCurKey = 0; //���݂̃L�[�ԍ�
	m_nCntMotion = 0; //���[�V�����J�E���^�[
	
	for (int nCntKeySet = 0; nCntKeySet < MAX_KEY_SET; nCntKeySet++)
	{
		m_aKeySet[nCntKeySet].nFrame = 0;
		for (int nCntKey = 0; nCntKey < MAX_PARTS; nCntKey++)
		{
			//�ʒu
			m_aKeySet[nCntKeySet].aKey[nCntKey].fPosX = 0.0f;
			m_aKeySet[nCntKeySet].aKey[nCntKey].fPosY = 0.0f;
			m_aKeySet[nCntKeySet].aKey[nCntKey].fPosZ = 0.0f;
			//����
			m_aKeySet[nCntKeySet].aKey[nCntKey].fRotX = 0.0f;
			m_aKeySet[nCntKeySet].aKey[nCntKey].fRotY = 0.0f;
			m_aKeySet[nCntKeySet].aKey[nCntKey].fRotZ = 0.0f;
		}
	}
}
//===================================
// 
//�f�X�X�g���N�^
//
//===================================
CPlayer::~CPlayer()
{

}

//===================================
// 
//�v���C���[�̏���������
//
//===================================
HRESULT CPlayer::Init(void)
{
	//���f���p�[�c����
	//m_apModel[6] = CModelParts::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	/*CPlayer::SetPos();
	CPlayer::SetRot();*/

	Load();

	CPlayer::m_nLife = 15;
	CPlayer::m_nGoal = 1;

	SetType(CObject::TYPE::PLAYER);
	//���f���ݒ�
	//CModel* pModel = CManager::GetModel();//�擾
	//m_nModelIdx = pModel->Regist("data\\carplayer.x");//�o�^
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//�ݒ�
	// �L�[����ݒ�

	m_aKeySet[0].nFrame = 0;
	m_aKeySet[0].aKey[0].fPosX = 0.00f, m_aKeySet[0].aKey[0].fPosY = 0.00f, m_aKeySet[0].aKey[0].fPosZ = 0.00f;
	m_aKeySet[0].aKey[0].fRotX = 0.00f, m_aKeySet[0].aKey[0].fRotY = 0.00f, m_aKeySet[0].aKey[0].fRotZ = 0.00f;
	m_aKeySet[0].aKey[1].fPosX = 0.00f, m_aKeySet[0].aKey[1].fPosY = 0.00f, m_aKeySet[0].aKey[1].fPosZ = 0.00f;
	m_aKeySet[0].aKey[1].fRotX = 0.03f, m_aKeySet[0].aKey[1].fRotY = 0.00f, m_aKeySet[0].aKey[1].fRotZ = 0.00f;
	m_aKeySet[0].aKey[2].fPosX = 0.00f, m_aKeySet[0].aKey[2].fPosY = 0.00f, m_aKeySet[0].aKey[2].fPosZ = 0.00f;
	m_aKeySet[0].aKey[2].fRotX = 0.00f, m_aKeySet[0].aKey[2].fRotY = -0.25f, m_aKeySet[0].aKey[2].fRotZ = 0.50f;
	m_aKeySet[0].aKey[3].fPosX = 0.00f, m_aKeySet[0].aKey[3].fPosY = 0.00f, m_aKeySet[0].aKey[3].fPosZ = 0.00f;
	m_aKeySet[0].aKey[3].fRotX = 0.00f, m_aKeySet[0].aKey[3].fRotY = -0.25f, m_aKeySet[0].aKey[3].fRotZ = 0.00f;
	m_aKeySet[0].aKey[4].fPosX = 0.00f, m_aKeySet[0].aKey[4].fPosY = 0.00f, m_aKeySet[0].aKey[4].fPosZ = 0.00f;
	m_aKeySet[0].aKey[4].fRotX = 0.00f, m_aKeySet[0].aKey[4].fRotY = 0.25f, m_aKeySet[0].aKey[4].fRotZ = -0.50f;
	m_aKeySet[0].aKey[5].fPosX = 0.00f, m_aKeySet[0].aKey[5].fPosY = 0.00f, m_aKeySet[0].aKey[5].fPosZ = 0.00f;
	m_aKeySet[0].aKey[5].fRotX = 0.00f, m_aKeySet[0].aKey[5].fRotY = 0.25f, m_aKeySet[0].aKey[5].fRotZ = 0.00f;
	m_aKeySet[0].aKey[6].fPosX = 0.00f, m_aKeySet[0].aKey[6].fPosY = 0.00f, m_aKeySet[0].aKey[6].fPosZ = 0.00f;
	m_aKeySet[0].aKey[6].fRotX = 0.00f, m_aKeySet[0].aKey[6].fRotY = 0.00f, m_aKeySet[0].aKey[6].fRotZ = -0.09f;
	m_aKeySet[0].aKey[7].fPosX = 0.00f, m_aKeySet[0].aKey[7].fPosY = 0.00f, m_aKeySet[0].aKey[7].fPosZ = 0.00f;
	m_aKeySet[0].aKey[7].fRotX = 0.00f, m_aKeySet[0].aKey[7].fRotY = 0.00f, m_aKeySet[0].aKey[7].fRotZ = 0.00f;
	m_aKeySet[0].aKey[8].fPosX = 0.00f, m_aKeySet[0].aKey[8].fPosY = 0.00f, m_aKeySet[0].aKey[8].fPosZ = 0.00f;
	m_aKeySet[0].aKey[8].fRotX = 0.00f, m_aKeySet[0].aKey[8].fRotY = 0.00f, m_aKeySet[0].aKey[8].fRotZ = 0.09f;
	m_aKeySet[0].aKey[9].fPosX = 0.00f, m_aKeySet[0].aKey[9].fPosY = 0.00f, m_aKeySet[0].aKey[9].fPosZ = 0.00f;
	m_aKeySet[0].aKey[9].fRotX = 0.00f, m_aKeySet[0].aKey[9].fRotY = 0.00f, m_aKeySet[0].aKey[9].fRotZ = 0.00f;
	m_aKeySet[1].nFrame = 0;
	m_aKeySet[1].aKey[0].fPosX = 0.00f, m_aKeySet[1].aKey[0].fPosY = -1.00f, m_aKeySet[1].aKey[0].fPosZ = 0.00f;
	m_aKeySet[1].aKey[0].fRotX = -0.03f, m_aKeySet[1].aKey[0].fRotY = 0.00f, m_aKeySet[1].aKey[0].fRotZ = 0.00f;
	m_aKeySet[1].aKey[1].fPosX = 0.00f, m_aKeySet[1].aKey[1].fPosY = 0.00f, m_aKeySet[1].aKey[1].fPosZ = 0.00f;
	m_aKeySet[1].aKey[1].fRotX = -0.06f, m_aKeySet[1].aKey[1].fRotY = 0.00f, m_aKeySet[1].aKey[1].fRotZ = 0.00f;
	m_aKeySet[1].aKey[2].fPosX = 0.00f, m_aKeySet[1].aKey[2].fPosY = 0.00f, m_aKeySet[1].aKey[2].fPosZ = 0.00f;
	m_aKeySet[1].aKey[2].fRotX = 0.00f, m_aKeySet[1].aKey[2].fRotY = -0.25f, m_aKeySet[1].aKey[2].fRotZ = 0.79f;
	m_aKeySet[1].aKey[3].fPosX = 0.00f, m_aKeySet[1].aKey[3].fPosY = 0.00f, m_aKeySet[1].aKey[3].fPosZ = 0.00f;
	m_aKeySet[1].aKey[3].fRotX = 0.00f, m_aKeySet[1].aKey[3].fRotY = -0.53f, m_aKeySet[1].aKey[3].fRotZ = 0.00f;
	m_aKeySet[1].aKey[4].fPosX = 0.00f, m_aKeySet[1].aKey[4].fPosY = 0.00f, m_aKeySet[1].aKey[4].fPosZ = 0.00f;
	m_aKeySet[1].aKey[4].fRotX = 0.00f, m_aKeySet[1].aKey[4].fRotY = 0.25f, m_aKeySet[1].aKey[4].fRotZ = -0.79f;
	m_aKeySet[1].aKey[5].fPosX = 0.00f, m_aKeySet[1].aKey[5].fPosY = 0.00f, m_aKeySet[1].aKey[5].fPosZ = 0.00f;
	m_aKeySet[1].aKey[5].fRotX = 0.00f, m_aKeySet[1].aKey[5].fRotY = 0.53f, m_aKeySet[1].aKey[5].fRotZ = 0.00f;
	m_aKeySet[1].aKey[6].fPosX = 0.00f, m_aKeySet[1].aKey[6].fPosY = 0.50f, m_aKeySet[1].aKey[6].fPosZ = 0.00f;
	m_aKeySet[1].aKey[6].fRotX = 0.06f, m_aKeySet[1].aKey[6].fRotY = 0.00f, m_aKeySet[1].aKey[6].fRotZ = -0.09f;
	m_aKeySet[1].aKey[7].fPosX = 0.00f, m_aKeySet[1].aKey[7].fPosY = 0.00f, m_aKeySet[1].aKey[7].fPosZ = 0.00f;
	m_aKeySet[1].aKey[7].fRotX = 0.00f, m_aKeySet[1].aKey[7].fRotY = -0.18f, m_aKeySet[1].aKey[7].fRotZ = 0.00f;
	m_aKeySet[1].aKey[8].fPosX = 0.00f, m_aKeySet[1].aKey[8].fPosY = 0.50f, m_aKeySet[1].aKey[8].fPosZ = 0.00f;
	m_aKeySet[1].aKey[8].fRotX = 0.06f, m_aKeySet[1].aKey[8].fRotY = 0.00f, m_aKeySet[1].aKey[8].fRotZ = 0.09f;
	m_aKeySet[1].aKey[9].fPosX = 0.00f, m_aKeySet[1].aKey[9].fPosY = 0.00f, m_aKeySet[1].aKey[9].fPosZ = 0.00f;
	m_aKeySet[1].aKey[9].fRotX = -0.18f, m_aKeySet[1].aKey[9].fRotY = 0.00f, m_aKeySet[1].aKey[9].fRotZ = 0.00f;

	return S_OK;
}

//===================================
// 
//�v���C���[�̃q�b�g����
//
//===================================
void CPlayer::Hit(int nDamage)
{
	CObject3D::Hit(nDamage);
}
//===================================
// 
//�v���C���[�̃q�b�g�S�[������
//
//===================================
void CPlayer::HitGoal(int nHit)
{
	CObject3D::HitGoal(nHit);
}
//===================================
// 
//�v���C���[�̃q�b�g���[�v����
//
//===================================
void CPlayer::HitWarp(int nHitWarp)
{
	CObject3D::HitWarp(nHitWarp);
}
//===================================
// 
//�v���C���[�̏I������
//
//===================================
void CPlayer::Uninit()
{
	CObject3D::Uninit();//this->Release();���g�̊J��
}
//===================================
// 
//�v���C���[�̍X�V����
//
//===================================
void CPlayer::Update()
{

	m_PosOld = m_pos;

	D3DXVECTOR3 PlayerPos = GetPos();
	D3DXVECTOR3 PlayerMove = GetMove();

	if (PlayerPos.z >= 49120.0f)
	{
		PlayerMove.z = 0.0f;
	}
	//Move += D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	////�ʒu���X�V
	//Pos += Move;
	/*for (int nCntModel = 0; nCntModel < MAX_PARTS; nCntModel++)
	{
		m_nCntMotion / 40;
		
	}*/
	m_nCntMotion++; //���[�V�����J�E���^�[��i�߂�

	/*if ()
	{
		if ()
		{

		}
	}*/

	/*if (Pos.x >= 230.0f)
	{
		Pos.x = 230.0f;
		Move.x = 0.0f;
	}
	else if (Pos.x <= -300.0f)
	{
		Pos.x = -300.0f;
		Move.x = 0.0f;
	}*/
	/*if (PlayerPos.y >= 60.0f)
	{
		PlayerPos.y = 60.0f;
		PlayerMove.y = 0.0f;
	}*/
	/*if (Pos.z >= 100.0f)
	{
		Pos.z = 100.0f;
		Move.z = 0.0f;
	}*/
	/*if (Pos.z <= -100.0f)
	{
		Pos.z = -100.0f;
		Move.z = 0.0f;
	}*/

	CInputGamePad* pButton = CManager::GetGamePad();
	//�g���K�[�̒l���擾
	int TriggerValue = pButton->GetTriggerValue();
	float NorTriggerValue = pButton->GetNorTriggerValue();
	PlayerMove.y -= 1.0f;//�d��
	if (CManager::GetKeyboard()->GetTrigger(DIK_SPACE) == true)
	{//SPACE�L�[�������ꂽ
		if (IsLanding == true)
		{
			PlayerMove.y += 5.0f;
			IsLanding = false;
		}
	}
	//�E�g���K�[
	//if (NorTriggerValue < 1.0)
	//{
	//	//RT�������ꂽ
	//	if (IsLanding == true)
	//	{
	//		Move.y += 190.0f;
	//		IsLanding = false;
	//	}
	//}
	////���g���K�[
	//if (NorTriggerValue > 1.0)
	//{
	//	//LT�������ꂽ
	//	if (IsLanding == true)
	//	{
	//		Move.y += 190.0f;
	//		IsLanding = false;
	//	}
	//}
	
	if (CManager::GetKeyboard()->GetTrigger(DIK_UPARROW) == true)
	{//UPARROW�L�[�������ꂽ
		//�e�̐ݒ�
		CPlayer_Bullet::Create(m_pos, D3DXVECTOR3(0.0f, 10.0f, 7.0f), 30);

	}
	//if (CManager::GetGamePad()->GetTrigger(1) == true)
	//{//B�������ꂽ
	//	//�e�̐ݒ�
	//	CPlayer_Bullet::Create(m_pos, D3DXVECTOR3(0.0f, 10.0f, 7.0f), 30);
	//}
	
	if (CManager::GetKeyboard()->GetPress(DIK_A) == true)
	{//A�L�[�������ꂽ
		//m_pos.x = 1.0f;
		//W�L�[�������ꂽ
		if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
			//m_pos.y = -1.0f;
		{//����ړ�

			PlayerMove.x += sinf(-D3DX_PI * 0.25f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 0.25f) * 1.0f;
		}
		//S�L�[�������ꂽ
		else if (CManager::GetKeyboard()->GetPress(DIK_S) == true)
		{//�����ړ�
			PlayerMove.x += sinf(-D3DX_PI * 0.75f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 0.75f) * 1.0f;
		}
		//A�̂�
		else
		{//���ړ�
			PlayerMove.x += sinf(-D3DX_PI * 0.5f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 0.5f) * 1.0f;

		}

	}
	//D�L�[�������ꂽ
	else if (CManager::GetKeyboard()->GetPress(DIK_D) == true)
	{
		//W�L�[�������ꂽ
		if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
		{//�E��ړ�

			PlayerMove.x += sinf(D3DX_PI * 0.25f) * 1.0f;
			PlayerMove.z += cosf(D3DX_PI * 0.25f) * 1.0f;
		}
		//S�L�[�������ꂽ
		else if (CManager::GetKeyboard()->GetPress(DIK_S) == true)
		{//�E���ړ�
			PlayerMove.x += sinf(D3DX_PI * 0.75f) * 1.0f;
			PlayerMove.z += cosf(D3DX_PI * 0.75f) * 1.0f;
		}
		//D�̂�
		else
		{//�E�ړ�
			PlayerMove.x += sinf(D3DX_PI * 0.5f) * 1.0f;
			PlayerMove.z += cosf(D3DX_PI * 0.5f) * 1.0f;
		}
	}

	//W�L�[�������ꂽ
	else if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
	{
		//A�L�[�������ꂽ
		if (CManager::GetKeyboard()->GetPress(DIK_A) == true)
		{//����ړ�
			PlayerMove.x += sinf(-D3DX_PI * 1.0f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 1.0f) * 1.0f;//75
		}
		//D�L�[�������ꂽ
		else if (CManager::GetKeyboard()->GetPress(DIK_D) == true)
		{//�E��ړ�
			PlayerMove.x += sinf(-D3DX_PI * 0.75f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 0.75f) * 1.0f;
		}
		//W�̂�
		else
		{//��ړ�
			PlayerMove.x += sinf(D3DX_PI * 0.0f) * 1.0f;
			PlayerMove.z += cosf(D3DX_PI * 0.0f) * 1.0f;
		}
	}

	//S�L�[�������ꂽ
	else if (CManager::GetKeyboard()->GetPress(DIK_S) == true)
	{
		//A�L�[�������ꂽ
		if (CManager::GetKeyboard()->GetPress(DIK_A) == true)
		{//�����ړ�
			PlayerMove.x += sinf(-D3DX_PI * 0.25f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 0.25f) * 1.0f;
		}
		//D�L�[�������ꂽ
		else if (CManager::GetKeyboard()->GetPress(DIK_D) == true)
		{//�E���ړ�
			PlayerMove.x += sinf(+D3DX_PI * 0.25f) * 1.0f;
			PlayerMove.z += cosf(+D3DX_PI * 0.25f) * 1.0f;
		}
		//S�̂�
		else
		{//���ړ�
			PlayerMove.x += sinf(-D3DX_PI * 1.0f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 1.0f) * 1.0f;
		}
	}

	//if (pButton->GetNorStick_lx() < 0.2)
	//{//�X�e�B�b�N���������ɂ͂����ꂽ
	//	//�X�e�B�b�N��������ɂ͂����ꂽ
	//	//if (pButton->GetNorStick_ly() < 0.2)
	//	//	//m_pos.y = -1.0f;
	//	//{//����ړ�
	//
	//	//	Move.x += sinf(-D3DX_PI * 0.25f) * 1.0f;
	//	//	Move.z += cosf(-D3DX_PI * 0.25f) * 1.0f;
	//	//}
	//	////�X�e�B�b�N���������ɂ͂����ꂽ
	//	//else if (pButton->GetNorStick_ly() > 1.8)
	//	//{//�����ړ�
	//	//	Move.x += sinf(-D3DX_PI * 0.75f) * 1.0f;
	//	//	Move.z += cosf(-D3DX_PI * 0.75f) * 1.0f;
	//	//}
	//	////���̂�
	//	//else
	//	//{//���ړ�
	//		Move.x += sinf(-D3DX_PI * 0.5f) * 1.5f;
	//		Move.z += cosf(-D3DX_PI * 0.5f) * 1.5f;
	//	//}
	//}
	////�X�e�B�b�N���E�����ɂ͂����ꂽ
	//else if (pButton->GetNorStick_lx() > 1.8)//<0.2
	//{
	//	////�X�e�B�b�N��������ɂ͂����ꂽ���ꂽ
	//	//if (pButton->GetNorStick_ly() < 0.2)
	//	//{//�E��ړ�

	//	//	Move.x += sinf(D3DX_PI * 0.25f) * 1.0f;
	//	//	Move.z += cosf(D3DX_PI * 0.25f) * 1.0f;
	//	//}
	//	////�X�e�B�b�N���������ɂ͂����ꂽ
	//	//else if (pButton->GetNorStick_ly() > 1.8)
	//	//{//�E���ړ�
	//	//	Move.x += sinf(D3DX_PI * 0.75f) * 1.0f;
	//	//	Move.z += cosf(D3DX_PI * 0.75f) * 1.0f;
	//	//}
	//	////�E�̂�
	//	//else
	//	//{//�E�ړ�
	//		Move.x += sinf(D3DX_PI * 0.5f) * 1.5f;
	//		Move.z += cosf(D3DX_PI * 0.5f) * 1.5f;
	//	//}
	//}
	////�X�e�B�b�N��������ɂ͂����ꂽ
	//else if (pButton->GetNorStick_ly() < 0.2)
	//{
	//	//�X�e�B�b�N���������ɂ͂����ꂽ
	//	if (pButton->GetNorStick_lx() < 0.2)
	//	{//����ړ�
	//		Move.x += sinf(-D3DX_PI * 1.0f) * 1.0f;
	//		Move.z += cosf(-D3DX_PI * 1.0f) * 1.0f;//75
	//	}
	//	//�X�e�B�b�N���E�����ɂ͂����ꂽ
	//	else if (pButton->GetNorStick_lx() > 1.8)
	//	{//�E��ړ�
	//		Move.x += sinf(-D3DX_PI * 0.75f) * 1.0f;
	//		Move.z += cosf(-D3DX_PI * 0.75f) * 1.0f;
	//	}
	//	//��̂�
	//	else
	//	{//��ړ�
	//		Move.x += sinf(D3DX_PI * 0.0f) * 1.0f;
	//		Move.z += cosf(D3DX_PI * 0.0f) * 1.0f;
	//	}
	//}
	////�X�e�B�b�N���������ɂ͂����ꂽ
	//else if (pButton->GetNorStick_ly() > 1.8)
	//{
	////�X�e�B�b�N���������ɂ͂����ꂽ
	//if (pButton->GetNorStick_lx() < 0.2)
	//{//�����ړ�
	//	Move.x += sinf(-D3DX_PI * 0.25f) * 1.0f;
	//	Move.z += cosf(-D3DX_PI * 0.25f) * 1.0f;
	//}
	////�X�e�B�b�N���E�����ɂ͂����ꂽ
	//else if (pButton->GetNorStick_lx() > 1.8)
	//{//�E���ړ�
	//	Move.x += sinf(+D3DX_PI * 0.25f) * 1.0f;
	//	Move.z += cosf(+D3DX_PI * 0.25f) * 1.0f;
	//}
	////���̂�
	//else
	//{//���ړ�
	//	Move.x += sinf(-D3DX_PI * 1.0f) * 1.0f;
	//	Move.z += cosf(-D3DX_PI * 1.0f) * 1.0f;
	//}
	//}

	bool bDushAttack = GetDushAttack();//�_�b�V���A�^�b�N�̎擾

	if (CManager::GetKeyboard()->GetTrigger(DIK_RETURN) == true)
	{//RETURN�L�[�������ꂽ
		
		if (CManager::GetKeyboard()->GetPress(DIK_A) == true)
		{//A�L�[�������ꂽ
			//m_pos.x = 1.0f;
			//W�L�[�������ꂽ
			if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
				//m_pos.y = -1.0f;
			{//����ړ�

				PlayerMove.x += sinf(-D3DX_PI * 0.25f) * 2.0f;
				PlayerMove.z += cosf(-D3DX_PI * 0.25f) * 2.0f;
			}
			//S�L�[�������ꂽ
			else if (CManager::GetKeyboard()->GetPress(DIK_S) == true)
			{//�����ړ�
				PlayerMove.x += sinf(-D3DX_PI * 0.75f) * 2.0f;
				PlayerMove.z += cosf(-D3DX_PI * 0.75f) * 2.0f;
			}
			//A�̂�
			else
			{//���ړ�
				PlayerMove.x += sinf(-D3DX_PI * 0.5f) * 2.5f;
				PlayerMove.z += cosf(-D3DX_PI * 0.5f) * 2.5f;
			}
			bDushAttack = true;
		}
		//D�L�[�������ꂽ
		else if (CManager::GetKeyboard()->GetPress(DIK_D) == true)
		{
			//W�L�[�������ꂽ
			if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
			{//�E��ړ�

				PlayerMove.x += sinf(D3DX_PI * 0.25f) * 2.0f;
				PlayerMove.z += cosf(D3DX_PI * 0.25f) * 2.0f;
			}
			//S�L�[�������ꂽ
			else if (CManager::GetKeyboard()->GetPress(DIK_S) == true)
			{//�E���ړ�
				PlayerMove.x += sinf(D3DX_PI * 0.75f) * 2.0f;
				PlayerMove.z += cosf(D3DX_PI * 0.75f) * 2.0f;
			}
			//D�̂�
			else
			{//�E�ړ�
				PlayerMove.x += sinf(D3DX_PI * 0.5f) * 2.5f;
				PlayerMove.z += cosf(D3DX_PI * 0.5f) * 2.5f;
			}
			bDushAttack = true;
		}
		//W�L�[�������ꂽ
		else if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
		{//��ړ�
			PlayerMove.x += sinf(D3DX_PI * 0.0f) * 2.0f;
			PlayerMove.z += cosf(D3DX_PI * 0.0f) * 2.0f;
			bDushAttack = true;
		}
		
	}
	//else if (CManager::GetGamePad()->GetTrigger(2) == true)
	//{//X�������ꂽ

	//	if (pButton->GetNorStick_lx() < 0.2)
	//	{//�X�e�B�b�N���������ɂ͂����ꂽ
	//		//�X�e�B�b�N��������ɂ͂����ꂽ
	//		if (pButton->GetNorStick_ly() < 0.2)
	//			//m_pos.y = -1.0f;
	//		{//����ړ�

	//			Move.x += sinf(-D3DX_PI * 0.25f) * 2.0f;
	//			Move.z += cosf(-D3DX_PI * 0.25f) * 2.0f;
	//		}
	//		//�X�e�B�b�N���������ɂ͂����ꂽ
	//		else if (pButton->GetNorStick_ly() > 1.8)
	//		{//�����ړ�
	//			Move.x += sinf(-D3DX_PI * 0.75f) * 2.0f;
	//			Move.z += cosf(-D3DX_PI * 0.75f) * 2.0f;
	//		}
	//		//���̂�
	//		else
	//		{//���ړ�
	//			Move.x += sinf(-D3DX_PI * 0.5f) * 2.5f;
	//			Move.z += cosf(-D3DX_PI * 0.5f) * 2.5f;
	//		}
	//		bDushAttack = true;
	//	}
	//	//�X�e�B�b�N���E�����ɂ͂����ꂽ
	//	else if (pButton->GetNorStick_lx() > 1.8)//<0.2
	//	{
	//		//�X�e�B�b�N��������ɂ͂����ꂽ���ꂽ
	//		if (pButton->GetNorStick_ly() < 0.2)
	//		{//�E��ړ�

	//			Move.x += sinf(D3DX_PI * 0.25f) * 2.0f;
	//			Move.z += cosf(D3DX_PI * 0.25f) * 2.0f;
	//		}
	//		//�X�e�B�b�N���������ɂ͂����ꂽ
	//		else if (pButton->GetNorStick_ly() > 1.8)
	//		{//�E���ړ�
	//			Move.x += sinf(D3DX_PI * 0.75f) * 2.0f;
	//			Move.z += cosf(D3DX_PI * 0.75f) * 2.0f;
	//		}
	//		//�E�̂�
	//		else
	//		{//�E�ړ�
	//			Move.x += sinf(D3DX_PI * 0.5f) * 2.5f;
	//			Move.z += cosf(D3DX_PI * 0.5f) * 2.5f;
	//		}
	//		bDushAttack = true;
	//	}
	//	//�X�e�B�b�N��������ɂ͂����ꂽ
	//	else if (pButton->GetNorStick_ly() < 0.2)
	//	{//��ړ�
	//		Move.x += sinf(D3DX_PI * 0.0f) * 2.0f;
	//		Move.z += cosf(D3DX_PI * 0.0f) * 2.0f;
	//		bDushAttack = true;
	//	}

	//}

	//�ʒu���X�V
	D3DXVECTOR3 PlayerPosOld = GetPosOld();
	PlayerPosOld = m_pos;
	PlayerPos += PlayerMove;
	//�ړ��ʂ��X�V�i����������j
	PlayerMove.x += (0.0f - PlayerMove.x) * 0.2f;

	PlayerMove.z += (0.0f - PlayerMove.z) * 0.2f;
	
	SetPos(PlayerPos);//�v���C���[��Pos�ݒ�
	SetMove(PlayerMove);//�v���C���[��Move�ݒ�
	

	// �_�b�V���A�^�b�N
	if (bDushAttack == true)
	{
		nCounterDushAttack++; //�J�E���^�[�����Z
		if (nCounterDushAttack >= 100)
		{
			nCounterDushAttack = 0;//�J�E���^�[�������l�ɖ߂�
			bDushAttack = false;
		}
	}

	

	// �����蔻��J�n
	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	//{
	//	//�G�Ƃ̓����蔻��i�z������ԂɃ`�F�b�N�j
	//	for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
			//�I�u�W�F�N�g�擾
			CObject* pObj = CObject::GetMyObject();
			//�ő吔���s���Ȃ̂�While���g�p
			while (pObj != nullptr)
			{
				// ���̃|�C���^��ۑ����Ă���
				CObject* pNext = pObj->GetNext();
				// ��肽�����������s�i����̓^�C�v�擾�j
				if (CObject::TYPE::ENEMY == pObj->GetType())
				{
					CEnemy* pEnemy = (CEnemy*)pObj;
					D3DXVECTOR3 EnemyPos = pEnemy->GetPos();//�G�̈ʒu�̎擾
					D3DXVECTOR3 EnemyMove = pEnemy->GetMove();//�G�̓����̎擾

					//�ʒu���X�V
					//EnemyPos += EnemyMove;
					D3DXVECTOR3 vec = EnemyPos - PlayerPos;
					D3DXVECTOR3 move = vec * 1.0f;

					if (m_pos.x >= EnemyPos.x - 20.0f
						&& m_pos.x <= EnemyPos.x + 20.0f
						&& m_pos.z >= EnemyPos.z - 20.0f
						&& m_pos.z <= EnemyPos.z + 20.0f)
					{
						if (bDushAttack == true)
						{

							pEnemy->Hit(1);
							EnemyMove.y = 0.0f;
							pEnemy->SetMove(move);
							pEnemy->SetDushAttack(true);
							

						}
						else
						{
							Hit(1);
							PlayerMove.y = 0.0f;
							SetMove(-move);

						}
						
					}
					
				}
				if (CObject::TYPE::TRUCK == pObj->GetType())
				{
					CTruck* pTruck = (CTruck*)pObj;
					D3DXVECTOR3 TruckPos = pTruck->GetPos();//�g���b�N�̈ʒu�̎擾
					D3DXVECTOR3 TruckMove = pTruck->GetMove();//�g���b�N�̓����̎擾
					
					//�ʒu���X�V
					//EnemyPos += EnemyMove;
					D3DXVECTOR3 vec = TruckPos - PlayerPos;
					D3DXVECTOR3 move = vec * 1.0f;

					if (m_pos.x >= TruckPos.x - 25.0f
						&& m_pos.x <= TruckPos.x + 25.0f
						&& m_pos.z >= TruckPos.z - 30.0f
						&& m_pos.z <= TruckPos.z + 30.0f)
					{
						if (bDushAttack == true)
						{

							pTruck->Hit(1);
							TruckMove.y = 0.0f;
							pTruck->SetMove(move);
							pTruck->SetDushAttack(true);


						}
						else
						{
							Hit(1);
							PlayerMove.y = 0.0f;
							SetMove(-move);

						}

					}

				}
				if (CObject::TYPE::BOSS == pObj->GetType())
				{
					CBoss* pBoss = (CBoss*)pObj;
					D3DXVECTOR3 BossPos = pBoss->GetPos();//�{�X�̈ʒu�̎擾
					D3DXVECTOR3 BossMove = pBoss->GetMove();//�{�X�̓����̎擾

					//�ʒu���X�V
					//EnemyPos += EnemyMove;
					D3DXVECTOR3 vec = BossPos - PlayerPos;
					D3DXVECTOR3 move = vec * 0.5f;

					if (m_pos.x >= BossPos.x - 85.0f
						&& m_pos.x <= BossPos.x + 85.0f
						&& m_pos.z >= BossPos.z - 25.0f
						&& m_pos.z <= BossPos.z + 105.0f)
					{
						
						Hit(1);
						PlayerMove.y = 0.0f;
						SetMove(-move);

					}

				}
				// �|�C���^�����̃|�C���^�֕ύX
				pObj = pNext;
			}
		//}
	//}
	
	SetDushAttack(bDushAttack);//�v���C���[��DushAttack�ݒ�

}
//===================================
// 
//�v���C���[�̕`�揈��
//
//===================================
void CPlayer::Draw()
{
	CObject3D::Draw();//�|���S���`��
	/*for (int nCntMat = 0; nCntMat < (int)m_dwNumMatModel; nCntMat++)
	{
		m_apModel[6]->Draw();
	}*/
}

//===================================
// 
//�v���C���[�̐�������
// 
//===================================
CPlayer* CPlayer::Create(D3DXVECTOR3 pos)
{
	CPlayer* pPlayer = new CPlayer();//�v���C���[����
	if (FAILED(pPlayer->Init())) {
	}
	pPlayer->SetPos(pos);
	pPlayer->BindMesh(pPlayer->GetMatModel(), pPlayer->GetBuffer(), pPlayer->GetMesh(), nullptr);
	//pPlayer->SetType(CObject::PLAYER);
	return pPlayer;
}
//===================================
// 
//�v���C���[�̃��[�h����
//
//===================================
HRESULT CPlayer::Load()
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER PlayerBuffer = GetBuffer();
	DWORD PlayerMatModel = GetMatModel();
	LPD3DXMESH PlayerMesh = GetMesh();
	
	if (FAILED(D3DXLoadMeshFromX("data\\carplayer.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &PlayerBuffer, nullptr, &PlayerMatModel, &PlayerMesh)))
	{
		return E_FAIL;
	}
	SetBuffer(PlayerBuffer);
	SetMatModel(PlayerMatModel);
	SetMesh(PlayerMesh);
	return S_OK;

}
//===================================
// 
//�v���C���[�̃A�����[�h����
//
//===================================
void CPlayer::Unload()
{
	CObject3D::Unload();
}