//=============================================================================
//
// �}�l�[�W���[���� [manager.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _MANAGER_H_//���̃}�N����`������ĂȂ�������
#define	_MANAGER_H_//2�d�C���N���[�h�h�~�̃}�N����`
#include <d3dx9.h>
#include"main.h"
#include"input.h"
#include"bullet.h"
#include"manager.h"
#include"fade.h"
#include "renderer.h"
#include"camera.h"
#include "light.h"
#include"scene.h"
#include"sound.h"
#include"model.h"
#include"texture.h"
//#include"score.h"

//�}�l�[�W���N���X
class CManager
{
private:
	//CManager();//private�ɂ���ƊO�����琶���s�ɁI
public:
	CManager();
	~CManager();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	void Uninit();
	void Update();
	void Draw();
	static CManager* GetInstance()
	{
		static CManager instance;//�ÓI�C���X�^���X
		return &instance;
	}
	//CRenderer* GetRenderer() { return m_pRenderer; }
	static CRenderer* GetRenderer();
	static CCamera* GetCamera();
	static CLight* GetLight();
	static CInputKeyboard* GetKeyboard();
	static CInputGamePad* GetGamePad();
	//static CFade* GetFade() {	return m_pFade;	}
	static CScene* GetScene() { return m_pScene; }
	static void SetMode(CScene::MODE mode);
	
	static CFade* GetFade() { return m_pFade; }
	static CSound* GetSound() { return m_pSound; }
	static CModel* GetModel();
	static CTexture* GetTexture();
	//CBullet::BULLETTYPE m_type;
private:
	//CRenderer* m_pRenderer;
	static CRenderer* m_pRenderer;//�����_���[
	static CCamera* m_pCamera;//�r���[���
	static CLight* m_pLight;//���C�g���
	static CInputKeyboard* m_pKeyboard;//�L�[�{�[�h����
	static CInputGamePad* m_pGamePad;//�Q�[���p�b�h����
	static CScene* m_pScene;//���݂̉��
	static CFade* m_pFade;//���݂̉��
	static CSound* m_pSound;//�T�E���h
	static CModel* m_pModel;//���f���Ǘ�
	static CTexture* m_pTexture;//�e�N�X�`���Ǘ�
};

#endif //_MANAGER_H_