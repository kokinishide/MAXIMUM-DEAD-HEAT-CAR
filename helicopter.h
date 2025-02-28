//=============================================================================
//
// ヘリコプターエネミー処理 [helicopter.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _HELICOPTER_H_//このマクロ定義がされてなかったら
#define _HELICOPTER_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object3D.h"

//マクロ定義
#define MAX_HELICOPTER (128) //ヘリコプターの最大数

//ヘリコプタークラス
class CHelicopter : public CObject3D
{
public:
	CHelicopter();
	virtual~CHelicopter()override;
	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int nDamage)override;

	static CHelicopter* Create(const D3DXVECTOR3& pos);
	HRESULT Load();
	void Unload();
	LPDIRECT3DTEXTURE9* GetTexture() { return &m_pObj_Texture[0]; }
private:
	static const int MAX_MAT = 100;
	static LPDIRECT3DTEXTURE9 m_pObj_Texture[MAX_MAT];
	int nCounterBullet;
	int m_nTextureIdx;


};

#endif// _HELICOPTER_H_

