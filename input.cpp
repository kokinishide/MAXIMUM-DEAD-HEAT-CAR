//=============================================================================
//
// 入力処理 [input.cpp]
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
//CInput実装↓
//静的メンバ初期化
//
//===================================
LPDIRECTINPUT8 CInput::m_pInput = nullptr;

//===================================
// 
//コンストラクタ
//
//===================================
CInput::CInput()
{
	m_pInput = nullptr;

}
//===================================
// 
//デストラクタ
//
//===================================
CInput::~CInput()
{

}

//===================================
// 
//初期化設定(キーボード入力初期化)
//
//===================================
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (m_pInput == nullptr)
	{
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
			return E_FAIL;
	}

	//その他キーボード用の生成・設定
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}
	//データフォーマットを設定
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}
	//協調モードを設定
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}
	//キーボードへのアクセス権を獲得
	m_pDevice->Acquire();
	return S_OK;
}
//===================================
// 
//破棄(CInputのUninit呼び出し)
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
//CInputKeyboard実装↓
//
//===================================

//===================================
// 
//コンストラクタ(配列初期化)
//
//===================================
CInputKeyboard::CInputKeyboard()
{
	m_pInput = nullptr;
}
//===================================
// 
//デストラクタ
//
//===================================
CInputKeyboard::~CInputKeyboard()
{

}

//===================================
// 
//初期設定(DirectInputの生成)
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
//破棄(入力デバイスとDirectInputの破棄)
//
//===================================
void CInputKeyboard::Uninit()
{
	//入力デバイス（キーボード）の破棄
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();//キーボードへのアクセス権を放棄
		m_pDevice->Release();
		m_pDevice = NULL;
	}
}

//===================================
// 
//更新(キーボード入力更新)
//
//===================================
void CInputKeyboard::Update()
{
	BYTE aKeyState[MAX_IN_KEY];//キーボードの入力情報
	int nCntKey;

	//入力デバイスからデータを取得
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (nCntKey = 0; nCntKey < MAX_IN_KEY; nCntKey++)
		{
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];
			m_aKeyState[nCntKey] = aKeyState[nCntKey];//キーボード情報保存
		}
	}
	else
	{
		m_pDevice->Acquire();//キーボードへアクセス
	}
}

//===================================
// 
//各種入力状態の関数（GetPressやGetTriggerなど）
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

//CInputGamepad実装↓

//====================================================================
// CInputGamePad実装
//====================================================================

//===============================================
//	ゲームパッドコンストラクタ
//===============================================
CInputGamePad::CInputGamePad()
{
	ZeroMemory(&m_GamepadState, sizeof(DIJOYSTATE));
}

//===============================================
//	ゲームパッドストラクタ
//===============================================
CInputGamePad::~CInputGamePad()
{

}

//===============================================
//	ゲームパッド初期設定
//===============================================
HRESULT CInputGamePad::Init(HINSTANCE hInstance, HWND hWnd)
{
	//DirectInputの初期化
	CInput::Init(hInstance, hWnd);

	//入力デバイス(ゲームパッド)の生成
	HRESULT hr = m_pInput->CreateDevice(GUID_Joystick, &m_pDevice, NULL);
	if (FAILED(hr))
	{
		m_pDevice = nullptr;
		return E_FAIL;
	}
	//データフォーマットを設定
	hr = m_pDevice->SetDataFormat(&c_dfDIJoystick2);
	if (FAILED(hr))
	{
		return E_FAIL;
	}
	//協調モードを設定
	hr = m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
	if (FAILED(hr))
	{
		return E_FAIL;
	}
	//ゲームパッドの仕様準備ができたらアクセスを開始
	hr = m_pDevice->Acquire();
	if (FAILED(hr))
	{
		return E_FAIL;
	}

	//ゲームパッドへのアクセス権を獲得
	return S_OK;
}

//===============================================
//	ゲームパッドの破棄
//===============================================
void CInputGamePad::Uninit()
{
	CInput::Uninit();
}

//===============================================
// ゲームパッド入力更新
//===============================================
void CInputGamePad::Update()
{
	//ゲームパッドデバイスが作成されていない場合はスキップする
	if (m_pDevice == nullptr)
	{
		return;	//デバイスがないからスキップ
	}

	//入力デバイスからデータを取得
	HRESULT hr = m_pDevice->GetDeviceState(sizeof(DIJOYSTATE2), &m_GamepadState);
	//デバイスの取得に失敗した場合
	if (FAILED(hr))
	{
		//デバイスが取得されていない、接続が切れたときに出す
		if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED)
		{
			//デバイスを再取得をしようとする
			m_pDevice->Acquire();	//ゲームパッドへのアクセス権を獲得
		}

		return;	//ゲームパッドが接続されてないから更新処理をスキップ
	}

	//=================================
	//	スティックの二次元軸を取得
	//=================================
	//左スティック
	LONG StickL_X = m_GamepadState.lX;	//x軸
	LONG StickL_Y = m_GamepadState.lY;	//y軸
	//右スティック
	LONG StickR_X = m_GamepadState.lRx;	//x軸
	LONG StickR_Y = m_GamepadState.lRy;	//y軸

	//=================================
	//	トリガーのZ軸を取得
	//=================================
	//LT,RTの値を取得
	LONG triggerValue = m_GamepadState.lZ;

	//=================================
	//	デッドゾーン処理
	//=================================
	//デッドゾーンの値を設定
	const LONG DEADZONE = 8000;

	//それぞれの軸がデッドゾーン値未満なら '0' に設定
	if (abs(StickL_X) < DEADZONE) StickL_X = 0;
	if (abs(StickL_Y) < DEADZONE) StickL_Y = 0;
	if (abs(StickR_X) < DEADZONE) StickR_X = 0;
	if (abs(StickR_Y) < DEADZONE) StickR_Y = 0;

	//スティックの値を正規化
	m_fNorStickL_X = static_cast<float>(StickL_X) / 32767.0f;
	m_fNorStickL_Y = static_cast<float>(StickL_Y) / 32767.0f;
	m_fNorStickR_X = static_cast<float>(StickR_X) / 32767.0f;
	m_fNorStickR_Y = static_cast<float>(StickR_Y) / 32767.0f;

	// トリガーの-32768 ～ +32767 の範囲を -1.0 ～ +1.0 の範囲に正規化する
	m_fNorTriggerValue = static_cast<float>(triggerValue) / 32767.0f;

	//トリガーの値の+-で左右判別
	if (triggerValue > 32767)
	{
		//右トリガーが押されている
	}
	else if (triggerValue < 32767)
	{
		//左トリガーが押されている
	}
	else
	{
		//トリガーが押されていない
	}

	//デバイスの取得に成功していたら入力情報を更新
	for (int nCntButton = 0; nCntButton < MAX_BUTTON; nCntButton++)
	{
		//キーボードのトリガー情報を保存
		m_aButtonStateTrigger[nCntButton] = (m_aButtonState[nCntButton] ^ m_GamepadState.rgbButtons[nCntButton]) & m_GamepadState.rgbButtons[nCntButton];

		//キーボードのリリース情報を保存
		m_aButtonStateRelease[nCntButton] = (m_aButtonState[nCntButton] ^ m_GamepadState.rgbButtons[nCntButton]) & ~m_GamepadState.rgbButtons[nCntButton];

		//	現在のボタンの情報を保存
		m_aButtonState[nCntButton] = m_GamepadState.rgbButtons[nCntButton];
	}
}

//===============================================
//	プレス状態取得
//===============================================
bool CInputGamePad::GetPress(int Button)
{
	return (m_aButtonState[Button] & 0x80) != 0;
}

//===============================================
//	トリガー状態取得
//===============================================
bool CInputGamePad::GetTrigger(int Button)	//トリガー状態取得
{
	return (m_aButtonStateTrigger[Button] & 0x80) != 0;
}

//===============================================
//	リリース状態取得
//===============================================
bool CInputGamePad::GetRelease(int Button)	//リリース状態取得
{
	return (m_aButtonStateRelease[Button] & 0x80) != 0;
}
//===============================================
//	リピート状態取得
//===============================================
bool CInputGamePad::GetRepeat(int Button)	//リピート状態取得
{
	return (m_aButtonStateRepeat[Button] & 0x80) != 0;
}

//===============================================
//	トリガーの値取得
//===============================================
int CInputGamePad::GetTriggerValue()
{
	return m_GamepadState.lZ;
}

//===============================================
//	正規化されたトリガーの値取得
//===============================================
float CInputGamePad::GetNorTriggerValue()
{
	return m_fNorTriggerValue;
}

//===============================================
//	正規化された左スティックx軸の値取得
//===============================================
float CInputGamePad::GetNorStick_lx()
{
	return m_fNorStickL_X;
}

//===============================================
//	正規化された左スティックy軸の値取得
//===============================================
float CInputGamePad::GetNorStick_ly()
{
	return m_fNorStickL_Y;
}

//===============================================
//	正規化された右スティックx軸の値取得
//===============================================
float CInputGamePad::GetNorStick_rx()
{
	return m_fNorStickR_X;
}

//===============================================
//	正規化された右スティックy軸の値取得
//===============================================
float CInputGamePad::GetNorStick_ry()
{
	return m_fNorStickR_Y;
}
//コンストラクタ(配列初期化)
//CInputJoypad::CInputJoypad()
//{
//	m_pInput = nullptr;
//}
////デストラクタ
//CInputJoypad::~CInputJoypad()
//{
//
//}
////キーボードの初期化処理
//void CInputJoypad::Init(HINSTANCE hInstance, HWND hWnd)
//{
//
//	//メモリのクリア
//	memset(&m_aJoykeyState, 0, sizeof(XINPUT_STATE));
//	//XInputのステートを設定（有効にする）
//	XInputEnable(true);
//	return S_OK;
//}
////ジョイパッドの終了処理
//void CInputJoypad::Uninit()
//{
//	//XInputのステートを設定(無効にする)
//	XInputEnable(false);
//}
////ジョイパッドの更新処理
//void CInputJoypad::Update()
//{
//
//	//XINPUT_STATE joyKeyState; //ジョイパッドの入力情報
//
//
//	//BYTE aKeyState[NUM_KEY_MAX];//キーボードの入力情報
//	//int nCntKey;
//	//入力デバイスからデータを取得
//	//if (SUCCEEDED(g_pDevJoypad->GetDeviceState(sizeof(joyKeyState), &joyKeyState[0])))
//	//{
//	//	for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
//	//	{
//	//		g_aKeyStateTrigger[nCntKey] = (g_aKeyState[nCntKey] ^ joyKeyState[nCntKey]) & joyKeyState[nCntKey];
//	//		g_aKeyState[nCntKey] =joyKeyState[nCntKey];//キーボード情報保存
//	//	}
//	//}
//	//else
//	//{
//	//	g_pDevKeyboard->Acquire();//キーボードへアクセス
//	//}
//	//ジョイパッドの状態を取得
//	//if (XInputGetState(0, &joyKeyState) == ERROR_SUCCESS)
//	//{
//	//	g_aJoykeyStete = joyKeyState; //ジョイパッドのプレス情報を保存
//	//}
//	// Zero value if thumbsticks are within the dead zone
//
//	XINPUT_STATE joykeyState;	//ジョイパッドの入力情報
//	//ジョイパッドの状態を取得
//	if (XInputGetState(0, &joykeyState) == ERROR_SUCCESS)
//	{
//		WORD Button = joykeyState.Gamepad.wButtons;
//		WORD OldButton = m_aJoykeyState.Gamepad.wButtons;
//		m_aJoykeyStateTrigger.Gamepad.wButtons = ~OldButton & Button;	//トリガー処理
//		m_aJoykeyStateRelease.Gamepad.wButtons = Button & ~OldButton;	//リリース処理
//
//
//		//現在の時刻を取得
//		m_aJoykeyCurrentTime.Gamepad.wButtons = (WORD)timeGetTime();
//
//		if (m_aJoykeyStete.Gamepad.wButtons == m_aJoykeyCurrentTime.Gamepad.wButtons)
//		{// キーが入力されていて、かつ現在の時間と最後に真を返した時間の差がリピートの間隔を越えていた
//			//最後に真を返した時間を保存
//			m_aJoykeyExecLastTime.Gamepad.wButtons = m_aJoykeyCurrentTime.Gamepad.wButtons;
//
//			//キーボードのリピート情報を保存
//			m_aJoykeyStateRepeat = joykeyState;
//		}
//		else
//		{
//			//キーボードのリピート情報を保存
//			m_aJoykeyStateRepeat.Gamepad.wButtons = 0;
//		}
//		m_aJoykeyStete = joykeyState;	//ジョイパッドのプレス情報を保存
//
//
//
//		//振動
//		m_JoykeyMoter.wLeftMotorSpeed = m_Strength;		//左のモーター
//		m_JoykeyMoter.wRightMotorSpeed = m_Strength;	//右のモーター
//		XInputSetState(0, &g_JoykeyMoter);				//振動情報を送る
//
//		//振動時間の減算
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
////キーボードのプレス情報を取得
//bool CInputJoypad::GetJoypadPress(JOYKEY Key)
//{
//	//return ((g_akeyState[nkey] & 0x80) != 0) ? true : false;
//
//	return(m_aJoykeyState[Key].Gamepad.wButtons & (0x01 << Key)) ? true : false;
//	//return(g_stick.Gamepad.wButtons & (0x01 << Key)) ? true : false;
//}
////キーボードのトリガー情報を取得
//bool CInputJoypad::GetJoypadTrigger(JOYKEY Key)
//{
//	//return ((g_akeyState[nkey] & 0x80) != 0) ? true : false;
//	return(m_aJoykeyStateTrigger[Key].Gamepad.wButtons & (0x01 << Key)) ? true : false;
//}
