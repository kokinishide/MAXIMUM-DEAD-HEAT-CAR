//=============================================================================
//
// マネージャー処理 [manager.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _MANAGER_H_//このマクロ定義がされてなかったら
#define	_MANAGER_H_//2重インクルード防止のマクロ定義
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

//マネージャクラス
class CManager
{
private:
	//CManager();//privateにすると外部から生成不可に！
public:
	CManager();
	~CManager();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	void Uninit();
	void Update();
	void Draw();
	static CManager* GetInstance()
	{
		static CManager instance;//静的インスタンス
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
	static CRenderer* m_pRenderer;//レンダラー
	static CCamera* m_pCamera;//ビュー情報
	static CLight* m_pLight;//ライト情報
	static CInputKeyboard* m_pKeyboard;//キーボード入力
	static CInputGamePad* m_pGamePad;//ゲームパッド入力
	static CScene* m_pScene;//現在の画面
	static CFade* m_pFade;//現在の画面
	static CSound* m_pSound;//サウンド
	static CModel* m_pModel;//モデル管理
	static CTexture* m_pTexture;//テクスチャ管理
};

#endif //_MANAGER_H_