//=============================================================================
//
// オブジェクト3D処理 [object3D.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _OBJECT3D_H_//このマクロ定義がされてなかったら
#define _OBJECT3D_H_//2重インクルード防止のマクロ定義

#include"object.h"

//3Dポリゴン管理クラス
class CObject3D :public CObject
{
public:
	//ヒット状態
	typedef enum
	{
		STATE_APPER = 0, //出現状態（点滅）
		STATE_NORMAL, //通常状態 
		STATE_DAMAGE, //ダメージ状態
		STATE_DEATH, //死亡状態
		STATE_MAX

	}STATE;
	CObject3D();
	virtual ~CObject3D()override;//object.hにvirtualがなければ、overrideを消す。
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Hit(int nDamage);
	virtual void HitGoal(int nHit);
	virtual void HitWarp(int nHitWarp);
	void BindMesh(DWORD dwNumMatModel, LPD3DXBUFFER pBuff, LPD3DXMESH pMesh, LPDIRECT3DTEXTURE9* pTexture);//テクスチャ割当
	void BindModel(DWORD dwNumMatModel, LPD3DXBUFFER pBuff, LPD3DXMESH pMesh, LPDIRECT3DTEXTURE9 pTexture);//モデル割当

	void SetPos(D3DXVECTOR3 pos); //位置を設定
	void SetPosOld(D3DXVECTOR3 posold); //古い位置を設定
	void SetMove(D3DXVECTOR3 move); //動きを設定
	void SetRot(D3DXVECTOR3 rot); //向きを設定
	void SetTargetPos(D3DXVECTOR3 TargetPos); //ターゲットの位置を設定
	void SetIsLanding(bool bIsLanding); //着地を設定
	void SetDushAttack(bool bDushAttack);//ダッシュアタックを設定
	void SetCol(D3DXCOLOR col); //カラーを設定
	void SetLife(int nLife);//ライフを設定
	void SetGoalHit(int nGoal);//ゴールのヒット処理を設定
	void SetVtxBuff(LPDIRECT3DVERTEXBUFFER9 pVtxBuff);//頂点バッファを設定
	void SetMesh(LPD3DXMESH pMeshModel);//メッシュを設定
	void SetBuffer(LPD3DXBUFFER pBuffMatModel);//マテリアルへのポインタを設定
	void SetMatModel(DWORD dwNumMatModel);//マテリアルの数を設定
	void SetWorldModel(D3DXMATRIX mtxWorldModel); //ワールドマトリックスを設定
	static CObject3D* Create(D3DXVECTOR3);//Object3D生成
	virtual HRESULT Load();//ロード処理
	void Unload();//アンロード処理
	int GetLife() { return m_nLife; }//ライフ取得など用意
	int GetGoalHit() { return m_nGoal; }//ゴール取得など用意
	D3DXVECTOR3 GetPos() { return m_pos; }//位置取得など用意
	D3DXVECTOR3 GetPosOld() { return m_PosOld; }//古い位置取得など用意
	D3DXVECTOR3 GetMove() { return m_move; }//動き取得など用意
	D3DXVECTOR3 GetRot() { return m_rot; }//向き取得など用意
	D3DXVECTOR3 GetTargetPos() { return m_TargetPos; }//ターゲットの位置の取得を用意
	bool GetDushAttack() { return m_DushAttack; } //ダッシュアタックを用意
	//LPDIRECT3DVERTEXBUFFER9 GetVtxBuff() { return m_pVtxBuff; }//頂点バッファ取得など用意
	LPD3DXMESH GetMesh(){  return m_pMeshModel; }//メッシュ取得など用意
	LPD3DXBUFFER GetBuffer() { return m_pBuffMatModel; }//マテリアルへのポインタの取得など用意
	DWORD GetMatModel() { return m_dwNumMatModel; }//マテリアルの数の取得など用意
	D3DXMATRIX GetWorldModel() { return m_mtxWorldModel; }//ワールドマトリックスの取得など用意
	void SetPosX(float x);
	void SetPosY(float y);
	void SetSizeW(float w);
	void SetSizeH(float h);
private:
	

protected:
	/*static CObject2D* m_pObject2D;*/
	LPD3DXMESH m_pMeshModel; //メッシュ（頂点情報）へのポインタ
	LPD3DXBUFFER m_pBuffMatModel; //マテリアルへのポインタ
	DWORD m_dwNumMatModel; //マテリアルの数
	D3DXMATRIX m_mtxWorldModel; //ワールドマトリックス
	LPDIRECT3DTEXTURE9* m_pTexture;//テクスチャへのポインタ
	STATE m_state; //状態
	static int m_nCounterState; //状態管理カウンター
	//int m_nType; //種類
	int m_nLife; //体力
	int m_nGoal;//ゴール
	int m_nModelIdx;//モデルのインデックス
	static int nNumObject3D;
	static bool m_bDisp; //表示するかしないか
	D3DXVECTOR3 m_nNumObject3D; //総数
	D3DXVECTOR3 m_pos; //現在の位置
	D3DXVECTOR3 m_PosOld; //前回の位置
	D3DXVECTOR3 m_move; //現在の位置
	D3DXVECTOR3 m_rot; // 向き
	D3DXVECTOR3 m_TargetPos;//ターゲットの位置
	bool m_DushAttack;//ダッシュアタック
	bool IsLanding; //着地の位置
	D3DXCOLOR m_col;//カラー
	D3DXMATRIX m_mtxWorld; //ワールド変換行列
	//static LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//頂点バッファ
	//float m_posX;	// 位置のX座標
	//float m_posY;	// 位置のY座標
	float m_sizeW;	// 幅
	float m_sizeH;	// 高さ
};


#endif //_OBJECT3D_H_