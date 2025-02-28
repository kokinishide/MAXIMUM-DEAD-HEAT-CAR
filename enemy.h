//=============================================================================
//
// エネミー処理 [enemy.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _ENEMY_H_//このマクロ定義がされてなかったら
#define _ENEMY_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object3D.h"

//マクロ定義
#define MAX_ENEMY (128) //敵の最大数

//エネミークラス
class CEnemy : public CObject3D
{
public:
	CEnemy();
	virtual~CEnemy()override;
	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int nDamage)override;

	static CEnemy* Create(const D3DXVECTOR3& pos);
	HRESULT Load();
	void Unload();
	LPDIRECT3DTEXTURE9* GetTexture() { return &m_pObj_Texture[0]; }
private:
	static const int MAX_MAT = 100;
	static LPDIRECT3DTEXTURE9 m_pObj_Texture[MAX_MAT];
	int nCounterBullet;
	int m_nTextureIdx;
	D3DXVECTOR3 m_TargetPos;//ターゲットの位置

};

#endif// _ENEMY_H_

