//=============================================================================
//
// ポーズ画面処理 [pause.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _PAUSE_H_//このマクロ定義がされてなかったら
#define	_PAUSE_H_//2重インクルード防止のマクロ定義
#include "main.h"
#include "object2D.h"


//ポーズ画面
class CPause :public CObject2D
{
public:
	//ポーズメニュー
	typedef enum
	{
		PAUSE_MENU_CONTINUE = 0, //ゲームに戻る
		PAUSE_MENU_RETRY,//ゲームをやり直す
		PAUSE_MENU_QUIT,//タイトル画面に戻る
		PAUSE_MENU_MAX
	}PAUSE_MENU;
	CPause();
	~CPause();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
private:

};

#endif //_PAUSE_H_