//=============================================================================
//
// ボスのバレット処理 [boss_bullet.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _BOSS_BULLET_H_//このマクロ定義がされてなかったら
#define _BOSS_BULLET_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include"object3D.h"
#include "bullet.h"
//マクロ定義
#define MAX_BULLET (128) //弾の最大数
//ボスの弾
class CBoss_Bullet : public CObject3D
{
public:
	CBoss_Bullet();
	virtual~CBoss_Bullet()override;
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	//virtual void Hit(int nDamage)override;
	//void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, BULLETTYPE type);
	static CBoss_Bullet* Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nBulletLife);
	virtual HRESULT Load()override; //テクスチャのロード
	void Unload();//テクスチャのアンロード
	void SetBulletLife(int nBulletLife); //位置取得など用意
private:
	//必要なメンバ
	static CBoss_Bullet* m_apBullet[MAX_BULLET];//オブジェクト管理
	D3DXVECTOR3 m_TargetPos;//ターゲットの位置
	int m_nBulletLife;//弾の寿命処理

};

#endif//_BOSS_BULLET_H_