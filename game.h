//=============================================================================
//
// ゲーム画面への遷移処理 [game.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _GAME_H_//このマクロ定義がされてなかったら
#define _GAME_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include"object.h"
#include"object3D.h"
#include "scene.h"
#include"block.h"
#include"block_manager.h"
#include"score_manager.h"

class CPlayer;

class CGame : public CScene
{
public:
	CGame();//コンストラクタ
	~CGame();//デストラクタ
	HRESULT Init() override;//初期設定
	void Uninit() override;//終了処理
	void Update() override;//更新処理
	void Draw() override;//描画処理
	static CGame* Create();//生成
	static CBlock_Manager* GetBlock_Manager() { return m_pBlock_Manager; }
	//static CScore_Manager* GetScore_Manager() { return m_pScore_Manager; }
	static CPlayer* GetPlayer() { return m_pPlayer; }
private:
	static CBlock_Manager* m_pBlock_Manager;//ブロックマネージャー
	//static CScore_Manager* m_pScore_Manager;//スコアマネージャー
	static CPlayer* m_pPlayer;//プレイヤーへのポインタ
};

#endif //_GAME_H_