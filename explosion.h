////=============================================================================
////
//// 爆発処理 [explosion.h]
//// Author :: Koki_Nishide
////
////=============================================================================
//#ifndef _EXPLOSION_H_//このマクロ定義がされてなかったら
//#define _EXPLOSION_H_//2重インクルード防止のマクロ定義
//
//#include "main.h"
//#include "object2D.h"
//
////マクロ定義
//#define MAX_EXPLOSION (128) //爆発処理の最大数
//
////弾の種類
////typedef enum
////{
////	EXPLOSIONTYPE_PLAYER = 0,//プレイヤーの弾
////	EXPLOSIONTYPE_ENEMY, //敵の弾
////	EXPLOSIONTYPE_MAX
////}EXPLOSIONTYPE;
//
////爆発
//class CExplosion : public CObject2D
//{
//public:
//	HRESULT Init();
//	void Uninit();
//	void Update();
//	void Draw();
//	static CExplosion* Create(D3DXVECTOR3 m_pos, D3DXCOLOR m_col);
//	//D3DXVECTOR3 m_pos; //位置
//	//D3DXCOLOR m_col;//カラーの設定
//	int nLife;//弾の寿命処理
//	bool bUse;//使用しているかどうか
//private:
//	//必要なメンバ
//	static CExplosion* m_apExplosion[MAX_EXPLOSION];//オブジェクト管理
//};
//
//#endif// _EXPLOSION_H_
//
//
