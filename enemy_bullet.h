//=============================================================================
//
// 敵のバレット処理 [enemy_bullet.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _ENEMY_BULLET_H_//このマクロ定義がされてなかったら
#define _ENEMY_BULLET_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include"object3D.h"
#include "bullet.h"
//マクロ定義
#define MAX_BULLET (128) //弾の最大数
//敵の弾
class CEnemy_Bullet : public CObject3D
{
public:
	//弾の種類
	typedef enum
	{
		BULLETTYPE_HELICOPTER = 0, //ヘリコプターの弾
		BULLETTYPE_TRUCK, //トラックの弾
		BULLETTYPE_MAX
	}BULLETTYPE;
	CEnemy_Bullet();
	virtual~CEnemy_Bullet()override;
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	//virtual void Hit(int nDamage)override;
	//void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, BULLETTYPE type);
	static CEnemy_Bullet* Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nBulletLife, BULLETTYPE Bullettype);
	virtual HRESULT Load()override; //テクスチャのロード
	void Unload();//テクスチャのアンロード
	void SetBulletLife(int nBulletLife); //位置取得など用意
	void SetBulletType(BULLETTYPE Bullettype);
private:
	//必要なメンバ
	static CEnemy_Bullet* m_apBullet[MAX_BULLET];//オブジェクト管理
	D3DXVECTOR3 m_TargetPos;//ターゲットの位置
	BULLETTYPE m_Bullettype;//玉の種類
	int m_nBulletLife;//弾の寿命処理
};

#endif//_ENEMY_BULLET_H_