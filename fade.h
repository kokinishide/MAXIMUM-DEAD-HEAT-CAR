//=============================================================================
//
// フェード処理 [fade.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _FADE_H_//このマクロ定義がされてなかったら
#define _FADE_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include"scene.h"
#include "object2D.h"

class CFade : public CObject2D
{
public:
	typedef enum
	{
		FADE_NONE = 0, //通常状態
		FADE_IN, //ダメージ状態
		FADE_OUT,
		FADE_MAX,

	}FADE;
	CFade();
	CFade(int nPriority);
	virtual ~CFade()override;
	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;
	void SetFade(CScene::MODE modenext);//フェードの設定
	void GetState();
	static CFade* Create();//生成
	static HRESULT Load();//ロード
	static void Unload();//アンロード
private:
	CScene::MODE m_ModeNext;//次のモード
	static LPDIRECT3DTEXTURE9 m_pTextureFade;//テクスチャ
	int m_nfade;
	float m_colora;


};

#endif //_FADE_H_



