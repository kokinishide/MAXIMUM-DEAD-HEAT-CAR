//=============================================================================
//
// プレイヤー処理 [player.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _PLAYER_H_//このマクロ定義がされてなかったら
#define _PLAYER_H_//２重インクルード防止のマクロ定義
#include"object3D.h"
#include"modelparts.h"
#include"bullet.h"

//マクロ定義
#define PLAYER_HEIGHT (40.0f)
#define MAX_PARTS (32)
#define MAX_KEY_SET (2)
//キーデータ
struct KEY
{
	//位置
	float fPosX;
	float fPosY;
	float fPosZ;

	//向き
	float fRotX;
	float fRotY;
	float fRotZ;
};
//キー情報
struct KEYSET
{
	int nFrame;
	KEY aKey[MAX_PARTS];
};

//プレイヤーポリゴン管理クラス
class CPlayer :public CObject3D
{
public:
	CPlayer();
	virtual ~CPlayer()override;
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Hit(int nDamage)override;
	virtual void HitGoal(int nHit)override;
	virtual void HitWarp(int nHitWarp)override;
	//CBullet::BULLETTYPE type;
	static CPlayer* Create(D3DXVECTOR3 pos);//Object2D生成
	HRESULT Load();
	void Unload();

private:
	//キー情報
	KEYSET m_aKeySet[MAX_KEY_SET];
	CModelParts* m_apModel[MAX_PARTS];
	int m_nNumKey; //キーの総数
	int m_nCurKey; //現在のキー番号
	int m_nCntMotion; //モーションカウンター
	int nCounterDushAttack;//ダッシュアタックカウンター
};

#endif//_PLAYER_H_

