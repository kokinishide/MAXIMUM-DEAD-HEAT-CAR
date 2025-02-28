//=============================================================================
//
// ���͏��� [input.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include<stdio.h>
#include"object2D.h"
#include "renderer.h"
#include "manager.h"
#include"main.h"
#include"input.h"

//===================================
// 
//CInput������
//�ÓI�����o������
//
//===================================
LPDIRECTINPUT8 CInput::m_pInput = nullptr;

//===================================
// 
//�R���X�g���N�^
//
//===================================
CInput::CInput()
{
	m_pInput = nullptr;

}
//===================================
// 
//�f�X�g���N�^
//
//===================================
CInput::~CInput()
{

}

//===================================
// 
//�������ݒ�(�L�[�{�[�h���͏�����)
//
//===================================
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (m_pInput == nullptr)
	{
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
			return E_FAIL;
	}

	//���̑��L�[�{�[�h�p�̐����E�ݒ�
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}
	//�f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}
	//�������[�h��ݒ�
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}
	//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	m_pDevice->Acquire();
	return S_OK;
}
//===================================
// 
//�j��(CInput��Uninit�Ăяo��)
//
//===================================
void CInput::Uninit()
{
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//===================================
// 
//CInputKeyboard������
//
//===================================

//===================================
// 
//�R���X�g���N�^(�z�񏉊���)
//
//===================================
CInputKeyboard::CInputKeyboard()
{
	m_pInput = nullptr;
}
//===================================
// 
//�f�X�g���N�^
//
//===================================
CInputKeyboard::~CInputKeyboard()
{

}

//===================================
// 
//�����ݒ�(DirectInput�̐���)
//
//===================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (FAILED(CInput::Init(hInstance, hWnd)))
		return E_FAIL;
	return S_OK;
}
//===================================
// 
//�j��(���̓f�o�C�X��DirectInput�̔j��)
//
//===================================
void CInputKeyboard::Uninit()
{
	//���̓f�o�C�X�i�L�[�{�[�h�j�̔j��
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();//�L�[�{�[�h�ւ̃A�N�Z�X�������
		m_pDevice->Release();
		m_pDevice = NULL;
	}
}

//===================================
// 
//�X�V(�L�[�{�[�h���͍X�V)
//
//===================================
void CInputKeyboard::Update()
{
	BYTE aKeyState[MAX_IN_KEY];//�L�[�{�[�h�̓��͏��
	int nCntKey;

	//���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (nCntKey = 0; nCntKey < MAX_IN_KEY; nCntKey++)
		{
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];
			m_aKeyState[nCntKey] = aKeyState[nCntKey];//�L�[�{�[�h���ۑ�
		}
	}
	else
	{
		m_pDevice->Acquire();//�L�[�{�[�h�փA�N�Z�X
	}
}

//===================================
// 
//�e����͏�Ԃ̊֐��iGetPress��GetTrigger�Ȃǁj
//
//===================================
bool CInputKeyboard::GetPress(int nKey)
{
	//return ((g_akeyState[nkey] & 0x80) != 0) ? true : false;
	return(m_aKeyState[nKey] & 0x80) != 0;
}
bool CInputKeyboard::GetTrigger(int nKey)
{
	return(m_aKeyStateTrigger[nKey] & 0x80) != 0;
}

//CInputGamepad������

//====================================================================
// CInputGamePad����
//====================================================================

//===============================================
//	�Q�[���p�b�h�R���X�g���N�^
//===============================================
CInputGamePad::CInputGamePad()
{
	ZeroMemory(&m_GamepadState, sizeof(DIJOYSTATE));
}

//===============================================
//	�Q�[���p�b�h�X�g���N�^
//===============================================
CInputGamePad::~CInputGamePad()
{

}

//===============================================
//	�Q�[���p�b�h�����ݒ�
//===============================================
HRESULT CInputGamePad::Init(HINSTANCE hInstance, HWND hWnd)
{
	//DirectInput�̏�����
	CInput::Init(hInstance, hWnd);

	//���̓f�o�C�X(�Q�[���p�b�h)�̐���
	HRESULT hr = m_pInput->CreateDevice(GUID_Joystick, &m_pDevice, NULL);
	if (FAILED(hr))
	{
		m_pDevice = nullptr;
		return E_FAIL;
	}
	//�f�[�^�t�H�[�}�b�g��ݒ�
	hr = m_pDevice->SetDataFormat(&c_dfDIJoystick2);
	if (FAILED(hr))
	{
		return E_FAIL;
	}
	//�������[�h��ݒ�
	hr = m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
	if (FAILED(hr))
	{
		return E_FAIL;
	}
	//�Q�[���p�b�h�̎d�l�������ł�����A�N�Z�X���J�n
	hr = m_pDevice->Acquire();
	if (FAILED(hr))
	{
		return E_FAIL;
	}

	//�Q�[���p�b�h�ւ̃A�N�Z�X�����l��
	return S_OK;
}

//===============================================
//	�Q�[���p�b�h�̔j��
//===============================================
void CInputGamePad::Uninit()
{
	CInput::Uninit();
}

//===============================================
// �Q�[���p�b�h���͍X�V
//===============================================
void CInputGamePad::Update()
{
	//�Q�[���p�b�h�f�o�C�X���쐬����Ă��Ȃ��ꍇ�̓X�L�b�v����
	if (m_pDevice == nullptr)
	{
		return;	//�f�o�C�X���Ȃ�����X�L�b�v
	}

	//���̓f�o�C�X����f�[�^���擾
	HRESULT hr = m_pDevice->GetDeviceState(sizeof(DIJOYSTATE2), &m_GamepadState);
	//�f�o�C�X�̎擾�Ɏ��s�����ꍇ
	if (FAILED(hr))
	{
		//�f�o�C�X���擾����Ă��Ȃ��A�ڑ����؂ꂽ�Ƃ��ɏo��
		if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED)
		{
			//�f�o�C�X���Ď擾�����悤�Ƃ���
			m_pDevice->Acquire();	//�Q�[���p�b�h�ւ̃A�N�Z�X�����l��
		}

		return;	//�Q�[���p�b�h���ڑ�����ĂȂ�����X�V�������X�L�b�v
	}

	//=================================
	//	�X�e�B�b�N�̓񎟌������擾
	//=================================
	//���X�e�B�b�N
	LONG StickL_X = m_GamepadState.lX;	//x��
	LONG StickL_Y = m_GamepadState.lY;	//y��
	//�E�X�e�B�b�N
	LONG StickR_X = m_GamepadState.lRx;	//x��
	LONG StickR_Y = m_GamepadState.lRy;	//y��

	//=================================
	//	�g���K�[��Z�����擾
	//=================================
	//LT,RT�̒l���擾
	LONG triggerValue = m_GamepadState.lZ;

	//=================================
	//	�f�b�h�]�[������
	//=================================
	//�f�b�h�]�[���̒l��ݒ�
	const LONG DEADZONE = 8000;

	//���ꂼ��̎����f�b�h�]�[���l�����Ȃ� '0' �ɐݒ�
	if (abs(StickL_X) < DEADZONE) StickL_X = 0;
	if (abs(StickL_Y) < DEADZONE) StickL_Y = 0;
	if (abs(StickR_X) < DEADZONE) StickR_X = 0;
	if (abs(StickR_Y) < DEADZONE) StickR_Y = 0;

	//�X�e�B�b�N�̒l�𐳋K��
	m_fNorStickL_X = static_cast<float>(StickL_X) / 32767.0f;
	m_fNorStickL_Y = static_cast<float>(StickL_Y) / 32767.0f;
	m_fNorStickR_X = static_cast<float>(StickR_X) / 32767.0f;
	m_fNorStickR_Y = static_cast<float>(StickR_Y) / 32767.0f;

	// �g���K�[��-32768 �` +32767 �͈̔͂� -1.0 �` +1.0 �͈̔͂ɐ��K������
	m_fNorTriggerValue = static_cast<float>(triggerValue) / 32767.0f;

	//�g���K�[�̒l��+-�ō��E����
	if (triggerValue > 32767)
	{
		//�E�g���K�[��������Ă���
	}
	else if (triggerValue < 32767)
	{
		//���g���K�[��������Ă���
	}
	else
	{
		//�g���K�[��������Ă��Ȃ�
	}

	//�f�o�C�X�̎擾�ɐ������Ă�������͏����X�V
	for (int nCntButton = 0; nCntButton < MAX_BUTTON; nCntButton++)
	{
		//�L�[�{�[�h�̃g���K�[����ۑ�
		m_aButtonStateTrigger[nCntButton] = (m_aButtonState[nCntButton] ^ m_GamepadState.rgbButtons[nCntButton]) & m_GamepadState.rgbButtons[nCntButton];

		//�L�[�{�[�h�̃����[�X����ۑ�
		m_aButtonStateRelease[nCntButton] = (m_aButtonState[nCntButton] ^ m_GamepadState.rgbButtons[nCntButton]) & ~m_GamepadState.rgbButtons[nCntButton];

		//	���݂̃{�^���̏���ۑ�
		m_aButtonState[nCntButton] = m_GamepadState.rgbButtons[nCntButton];
	}
}

//===============================================
//	�v���X��Ԏ擾
//===============================================
bool CInputGamePad::GetPress(int Button)
{
	return (m_aButtonState[Button] & 0x80) != 0;
}

//===============================================
//	�g���K�[��Ԏ擾
//===============================================
bool CInputGamePad::GetTrigger(int Button)	//�g���K�[��Ԏ擾
{
	return (m_aButtonStateTrigger[Button] & 0x80) != 0;
}

//===============================================
//	�����[�X��Ԏ擾
//===============================================
bool CInputGamePad::GetRelease(int Button)	//�����[�X��Ԏ擾
{
	return (m_aButtonStateRelease[Button] & 0x80) != 0;
}
//===============================================
//	���s�[�g��Ԏ擾
//===============================================
bool CInputGamePad::GetRepeat(int Button)	//���s�[�g��Ԏ擾
{
	return (m_aButtonStateRepeat[Button] & 0x80) != 0;
}

//===============================================
//	�g���K�[�̒l�擾
//===============================================
int CInputGamePad::GetTriggerValue()
{
	return m_GamepadState.lZ;
}

//===============================================
//	���K�����ꂽ�g���K�[�̒l�擾
//===============================================
float CInputGamePad::GetNorTriggerValue()
{
	return m_fNorTriggerValue;
}

//===============================================
//	���K�����ꂽ���X�e�B�b�Nx���̒l�擾
//===============================================
float CInputGamePad::GetNorStick_lx()
{
	return m_fNorStickL_X;
}

//===============================================
//	���K�����ꂽ���X�e�B�b�Ny���̒l�擾
//===============================================
float CInputGamePad::GetNorStick_ly()
{
	return m_fNorStickL_Y;
}

//===============================================
//	���K�����ꂽ�E�X�e�B�b�Nx���̒l�擾
//===============================================
float CInputGamePad::GetNorStick_rx()
{
	return m_fNorStickR_X;
}

//===============================================
//	���K�����ꂽ�E�X�e�B�b�Ny���̒l�擾
//===============================================
float CInputGamePad::GetNorStick_ry()
{
	return m_fNorStickR_Y;
}
//�R���X�g���N�^(�z�񏉊���)
//CInputJoypad::CInputJoypad()
//{
//	m_pInput = nullptr;
//}
////�f�X�g���N�^
//CInputJoypad::~CInputJoypad()
//{
//
//}
////�L�[�{�[�h�̏���������
//void CInputJoypad::Init(HINSTANCE hInstance, HWND hWnd)
//{
//
//	//�������̃N���A
//	memset(&m_aJoykeyState, 0, sizeof(XINPUT_STATE));
//	//XInput�̃X�e�[�g��ݒ�i�L���ɂ���j
//	XInputEnable(true);
//	return S_OK;
//}
////�W���C�p�b�h�̏I������
//void CInputJoypad::Uninit()
//{
//	//XInput�̃X�e�[�g��ݒ�(�����ɂ���)
//	XInputEnable(false);
//}
////�W���C�p�b�h�̍X�V����
//void CInputJoypad::Update()
//{
//
//	//XINPUT_STATE joyKeyState; //�W���C�p�b�h�̓��͏��
//
//
//	//BYTE aKeyState[NUM_KEY_MAX];//�L�[�{�[�h�̓��͏��
//	//int nCntKey;
//	//���̓f�o�C�X����f�[�^���擾
//	//if (SUCCEEDED(g_pDevJoypad->GetDeviceState(sizeof(joyKeyState), &joyKeyState[0])))
//	//{
//	//	for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
//	//	{
//	//		g_aKeyStateTrigger[nCntKey] = (g_aKeyState[nCntKey] ^ joyKeyState[nCntKey]) & joyKeyState[nCntKey];
//	//		g_aKeyState[nCntKey] =joyKeyState[nCntKey];//�L�[�{�[�h���ۑ�
//	//	}
//	//}
//	//else
//	//{
//	//	g_pDevKeyboard->Acquire();//�L�[�{�[�h�փA�N�Z�X
//	//}
//	//�W���C�p�b�h�̏�Ԃ��擾
//	//if (XInputGetState(0, &joyKeyState) == ERROR_SUCCESS)
//	//{
//	//	g_aJoykeyStete = joyKeyState; //�W���C�p�b�h�̃v���X����ۑ�
//	//}
//	// Zero value if thumbsticks are within the dead zone
//
//	XINPUT_STATE joykeyState;	//�W���C�p�b�h�̓��͏��
//	//�W���C�p�b�h�̏�Ԃ��擾
//	if (XInputGetState(0, &joykeyState) == ERROR_SUCCESS)
//	{
//		WORD Button = joykeyState.Gamepad.wButtons;
//		WORD OldButton = m_aJoykeyState.Gamepad.wButtons;
//		m_aJoykeyStateTrigger.Gamepad.wButtons = ~OldButton & Button;	//�g���K�[����
//		m_aJoykeyStateRelease.Gamepad.wButtons = Button & ~OldButton;	//�����[�X����
//
//
//		//���݂̎������擾
//		m_aJoykeyCurrentTime.Gamepad.wButtons = (WORD)timeGetTime();
//
//		if (m_aJoykeyStete.Gamepad.wButtons == m_aJoykeyCurrentTime.Gamepad.wButtons)
//		{// �L�[�����͂���Ă��āA�����݂̎��ԂƍŌ�ɐ^��Ԃ������Ԃ̍������s�[�g�̊Ԋu���z���Ă���
//			//�Ō�ɐ^��Ԃ������Ԃ�ۑ�
//			m_aJoykeyExecLastTime.Gamepad.wButtons = m_aJoykeyCurrentTime.Gamepad.wButtons;
//
//			//�L�[�{�[�h�̃��s�[�g����ۑ�
//			m_aJoykeyStateRepeat = joykeyState;
//		}
//		else
//		{
//			//�L�[�{�[�h�̃��s�[�g����ۑ�
//			m_aJoykeyStateRepeat.Gamepad.wButtons = 0;
//		}
//		m_aJoykeyStete = joykeyState;	//�W���C�p�b�h�̃v���X����ۑ�
//
//
//
//		//�U��
//		m_JoykeyMoter.wLeftMotorSpeed = m_Strength;		//���̃��[�^�[
//		m_JoykeyMoter.wRightMotorSpeed = m_Strength;	//�E�̃��[�^�[
//		XInputSetState(0, &g_JoykeyMoter);				//�U�����𑗂�
//
//		//�U�����Ԃ̌��Z
//		if (m_nVibTime > 0)
//		{
//			m_nVibTime--;
//		}
//		else
//		{
//			m_nVibTime = 0;
//			m_Strength = 0;
//		}
//		if ((state.Gamepad.sThumbLX <  XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
//			state.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
//			(state.Gamepad.sThumbLY <  XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
//				state.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
//		{
//			state.Gamepad.sThumbLX = 0;
//			state.Gamepad.sThumbLY = 0;
//		}
//	}
//
//}
////�L�[�{�[�h�̃v���X�����擾
//bool CInputJoypad::GetJoypadPress(JOYKEY Key)
//{
//	//return ((g_akeyState[nkey] & 0x80) != 0) ? true : false;
//
//	return(m_aJoykeyState[Key].Gamepad.wButtons & (0x01 << Key)) ? true : false;
//	//return(g_stick.Gamepad.wButtons & (0x01 << Key)) ? true : false;
//}
////�L�[�{�[�h�̃g���K�[�����擾
//bool CInputJoypad::GetJoypadTrigger(JOYKEY Key)
//{
//	//return ((g_akeyState[nkey] & 0x80) != 0) ? true : false;
//	return(m_aJoykeyStateTrigger[Key].Gamepad.wButtons & (0x01 << Key)) ? true : false;
//}
