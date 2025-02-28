//=============================================================================
//
// 入力処理 [input.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _INPUT_H_//このマクロ定義がされてなかったら
#define _INPUT_H_//2重インクルード防止のマクロ定義
#define MAX_IN_KEY (256)
#define MAX_BUTTON (256)

//入力基底クラス(DirectInputの管理)
class CInput
{
public:
	CInput();
	~CInput();
	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	virtual void Uninit();
	virtual void Update() = 0;//入力端末ごとに実装
protected://派生クラス内で使える
	//全入力処理で共有
	static LPDIRECTINPUT8 m_pInput;
	LPDIRECTINPUTDEVICE8 m_pDevice;
};
//キーボード入力
class CInputKeyboard :public CInput
{
public:
	CInputKeyboard();
	~CInputKeyboard();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit();
	void Update();
	bool GetPress(int nKey);//プレス状態取得
	bool GetTrigger(int nKey);//トリガー状態取得
private: //自分(CInputKeyboard)だけ使えるメンバ
	BYTE m_aKeyState[MAX_IN_KEY];
	BYTE m_aKeyStateTrigger[MAX_IN_KEY];
};
//==========================================
//	パッド入力	
//==========================================
class CInputGamePad :public CInput
{
public:
	CInputGamePad();
	~CInputGamePad();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit();
	void Update();
	bool GetPress(int Button);		//プレス状態取得
	bool GetTrigger(int Button);	//トリガー状態取得
	bool GetRelease(int Button);	//リリース状態取得
	bool GetRepeat(int Button);		//リピート状態取得
	int GetTriggerValue();			//トリガーの値取得
	float GetNorTriggerValue();		//正規化トリガーの値取得
	float GetNorStick_lx();			//正規化左スティックx軸取得
	float GetNorStick_ly();			//正規化左スティックy軸取得
	float GetNorStick_rx();			//正規化右スティックx軸取得
	float GetNorStick_ry();			//正規化右スティックy軸取得
private:
	DIJOYSTATE2 m_GamepadState;
	BYTE m_aButtonState[MAX_BUTTON];
	BYTE m_aButtonStateTrigger[MAX_BUTTON];
	BYTE m_aButtonStateRelease[MAX_BUTTON];
	BYTE m_aButtonStateRepeat[MAX_BUTTON];
	DWORD m_aButtonCurrentTime[MAX_BUTTON];		// キーボードの現在の時間
	DWORD m_aButtonExecLastTime[MAX_BUTTON];		// キーボードの最後に真を返した時間
	float m_fNorTriggerValue;	//トリガーの値
	float m_fNorStickL_X;
	float m_fNorStickL_Y;
	float m_fNorStickR_X;
	float m_fNorStickR_Y;
};

#endif //_INPUT_H_