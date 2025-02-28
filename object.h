//=============================================================================
//
// オブジェクト処理 [object.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _OBJECT_H_//このマクロ定義がされてなかったら
#define	_OBJECT_H_//2重インクルード防止のマクロ定義
#include <d3dx9.h>

//マクロ定義
#define MAX_DATA (256)//扱われるデータ数
#define DEFAULT_PRIORITY (5)
//#define MAX_PRIORITY (5)//優先されるデータ数

//全オブジェクト基底クラス
class CObject
{
public:
	typedef enum
	{
		NONE = 0,//無し
		ENEMY,//敵
		PLAYER,//プレイヤー
		BLOCK,//ブロック
		FADE, //フェード
		SCENE,//シーン
		CAMERA,//カメラ
		BG,//背景(3D)
		GOAL,//ゴール
		GROUND,//グラウンド
		WARP,//ワープ
		THINGROUND,//細い処理
		GAUGE,//ゲージ
		HELICOPTER,//ヘリコプター
		TRUCK,//トラック
		HP,//HP文字
		SCORE,//スコア
		PARTICLE,//パーティクル
		JUMP_MESSAGE,//ジャンプメッセージ
		LEFT_MESSAGE,//左のメッセージ
		RIGHT_MESSAGE,//右のメッセージ
		MIDDLE_MESSAGE,//真ん中通路のメッセージ
		BOSS_MESSAGE,//ボスのメッセージ
		BOSS,//ボス
		SKY,//空の背景
		MAX,
	}TYPE;
	static const int m_nMAX_PRIORITY = TYPE::MAX;
	CObject(int nPriority = 0);
	virtual ~CObject();
	virtual HRESULT Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	static void ReleaseAll();//全オブジェクト開放
	static void UpdateAll();//全オブジェクト更新
	static void DrawAll();//全オブジェクト描画
	//static CObject* GetObject();
	static CObject* GetMyObject();
	TYPE GetType(); //タイプ取得
	CObject* GetNext();
	void SetType(TYPE type);//タイプ設定
	void SetUseRelease(bool bUse) {m_bUseRelease = bUse;}
protected:
	void Release();//自分自身の開放
	bool m_bDeath;
private:
	//static CObject* m_apObject;//オブジェクト管理
	//static CObject* m_apMyObject[1];//オブジェクトリスト
	static CObject* m_apMyObject[m_nMAX_PRIORITY][MAX_DATA];//オブジェクト管理(プライオリティ)
	TYPE m_type; //オブジェクトタイプ
	static int m_nNumAll;//オブジェクト総数
	int m_nPriority;//描画優先度
	int m_nID;//自分自身のID
	bool m_bUseRelease;

	//オブジェクト管理
	static CObject* m_pTop;//先頭のオブジェクトのポインタ
	static CObject* m_pCur;//現在（最後尾）のポインタ
	CObject* m_pPrev;//前のオブジェクトのポインタ
	CObject* m_pNext;//次のオブジェクトのポインタ
};

#endif //_OBJECT_H_
