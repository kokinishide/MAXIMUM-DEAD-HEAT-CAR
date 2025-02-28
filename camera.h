//=============================================================================
//
// カメラ処理 [camera.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _CAMERA_H_//このマクロ定義がされてなかったら
#define	_CAMERA_H_//2重インクルード防止のマクロ定義
#include "main.h"
#include"object3D.h"

//カメラ
class CCamera : public CObject3D
{
public:
	CCamera();
	~CCamera();
	HRESULT Init();
	void Uninit();
	void Update();
	void SetCamera();//カメラの設定
	//void SetShake(10,0.2f);//設定用
private:
	D3DXVECTOR3 m_posV; //視点
	D3DXVECTOR3 m_posR; //注視店
	/*int 10;
	float 0.2f;*/
	D3DXVECTOR3 m_targetPosR;
	D3DXVECTOR3 m_targetPosV;
	D3DXVECTOR3 m_vecU; //上方向ベクトル
	D3DXVECTOR3 m_fDistance; //距離
	D3DXMATRIX m_mtxProjection; //プロジェクションマトリックス
	D3DXMATRIX m_mtxView; //ビューマトリックス
	//D3DXVECTOR3 m_moveV; //視点移動
	//D3DXVECTOR3 m_moveR; //視点移動
	
};


#endif//_CAMERA_H_