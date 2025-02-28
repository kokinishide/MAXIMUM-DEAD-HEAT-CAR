//=============================================================================
//
// ���͏��� [input.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _INPUT_H_//���̃}�N����`������ĂȂ�������
#define _INPUT_H_//2�d�C���N���[�h�h�~�̃}�N����`
#define MAX_IN_KEY (256)
#define MAX_BUTTON (256)

//���͊��N���X(DirectInput�̊Ǘ�)
class CInput
{
public:
	CInput();
	~CInput();
	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	virtual void Uninit();
	virtual void Update() = 0;//���͒[�����ƂɎ���
protected://�h���N���X���Ŏg����
	//�S���͏����ŋ��L
	static LPDIRECTINPUT8 m_pInput;
	LPDIRECTINPUTDEVICE8 m_pDevice;
};
//�L�[�{�[�h����
class CInputKeyboard :public CInput
{
public:
	CInputKeyboard();
	~CInputKeyboard();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit();
	void Update();
	bool GetPress(int nKey);//�v���X��Ԏ擾
	bool GetTrigger(int nKey);//�g���K�[��Ԏ擾
private: //����(CInputKeyboard)�����g���郁���o
	BYTE m_aKeyState[MAX_IN_KEY];
	BYTE m_aKeyStateTrigger[MAX_IN_KEY];
};
//==========================================
//	�p�b�h����	
//==========================================
class CInputGamePad :public CInput
{
public:
	CInputGamePad();
	~CInputGamePad();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit();
	void Update();
	bool GetPress(int Button);		//�v���X��Ԏ擾
	bool GetTrigger(int Button);	//�g���K�[��Ԏ擾
	bool GetRelease(int Button);	//�����[�X��Ԏ擾
	bool GetRepeat(int Button);		//���s�[�g��Ԏ擾
	int GetTriggerValue();			//�g���K�[�̒l�擾
	float GetNorTriggerValue();		//���K���g���K�[�̒l�擾
	float GetNorStick_lx();			//���K�����X�e�B�b�Nx���擾
	float GetNorStick_ly();			//���K�����X�e�B�b�Ny���擾
	float GetNorStick_rx();			//���K���E�X�e�B�b�Nx���擾
	float GetNorStick_ry();			//���K���E�X�e�B�b�Ny���擾
private:
	DIJOYSTATE2 m_GamepadState;
	BYTE m_aButtonState[MAX_BUTTON];
	BYTE m_aButtonStateTrigger[MAX_BUTTON];
	BYTE m_aButtonStateRelease[MAX_BUTTON];
	BYTE m_aButtonStateRepeat[MAX_BUTTON];
	DWORD m_aButtonCurrentTime[MAX_BUTTON];		// �L�[�{�[�h�̌��݂̎���
	DWORD m_aButtonExecLastTime[MAX_BUTTON];		// �L�[�{�[�h�̍Ō�ɐ^��Ԃ�������
	float m_fNorTriggerValue;	//�g���K�[�̒l
	float m_fNorStickL_X;
	float m_fNorStickL_Y;
	float m_fNorStickR_X;
	float m_fNorStickR_Y;
};

#endif //_INPUT_H_