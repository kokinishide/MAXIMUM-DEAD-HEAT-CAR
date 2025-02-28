//=============================================================================
//
// パーティクル処理 [particle.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _PARTICLE_H_//このマクロ定義がされてなかったら
#define _PARTICLE_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object2D.h"

//マクロ定義
#define MAX_PARTICLE (1024)//パーティクルの最大数
//パーティクルクラス
class CParticle :public CObject2D
{
public:
	//パーティクルの種類
	typedef enum
	{
		PARTICLETYPE_MODEL = 0,//プレイヤーのパーティクル
		PARTICLETYPE_ENEMY, //敵のパーティクル
		PARTICLETYPE_MAX
	}PARTICLETYPE;
	CParticle(int nPriority = 1);
	~CParticle()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CParticle* Create(const D3DXVECTOR3& pos);//Particle生成
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//頂点バッファ
	LPDIRECT3DTEXTURE9 m_pTexture;//テクスチャ
};
//プロトタイプ宣言
//void InitParticle(void);
//void UninitParticle(void);
//void UpdateParticle(void);
//void DrawParticle(void);
//void SetParticle(D3DXVECTOR3 pos, int nType, D3DXVECTOR3 move, float fRadius);

#endif //_PARTICLE_H_
