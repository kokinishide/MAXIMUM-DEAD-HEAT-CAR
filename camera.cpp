//=============================================================================
//
// カメラ処理 [camera.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "camera.h"
#include "input.h"
#include "game.h"
#include "renderer.h"
#include "manager.h"
#include "object3D.h"
#include "player.h"
//#include "model.h"

//===================================
// 
//コンストラクタ
//
//===================================
CCamera::CCamera()
{
	m_posV; //視点
	m_posR; //注視店
	m_targetPosR;
	m_targetPosV;
	m_vecU; //上方向ベクトル
	m_fDistance; //距離
	m_mtxProjection; //プロジェクションマトリックス
	m_mtxView; //ビューマトリックス
}
//===================================
// 
//デスストラクタ
//
//===================================
CCamera::~CCamera()
{

}
//===================================
// 
//カメラの初期化処理
//
//===================================
HRESULT CCamera::Init(void)
{
	//m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //移動量を初期化する
	//m_posV = D3DXVECTOR3(0.0f, 50.0f, -200.0f);
	//m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fDistance = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_pos = m_posV;
	m_targetPosR = m_posR;
	m_targetPosV = m_posV;

	return S_OK;

}
//===================================
// 
//カメラの終了処理
//
//===================================
void CCamera::Uninit()
{

}
//===================================
// 
//カメラの更新処理
//
//===================================
void CCamera::Update()
{
	if (CGame::GetPlayer() != nullptr)
	{
		m_posR = CGame::GetPlayer()->GetPos();
		m_posV = m_posR + D3DXVECTOR3(0.0f, 250.0f, -180.0f);
	}

	//位置を更新
	/*model* Model = GetModel();
	g_posCamera = Model->pos;*/

	//XINPUT_STATE joykeystate;
	//if(XINPUT_STATE(0,&joykeystate))
	//m_pos += m_move;
	//if (CManager::GetKeyboard()->GetPress(DIK_Z) == true)//LEFT
	//{
	//	m_rot.y += 0.07f;
	//}
	//else if (CManager::GetKeyboard()->GetPress(DIK_C) == true)//RIGHT
	//{
	//	m_rot.y -= 0.07f;
	//}
	///*if (Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	//{
	//	g_camera.rot.y += 0.07f;
	//}*/

	////if (GetJoypadPress(STICKANGLE_LEFT) == true)//LEFT
	////{
	////	g_camera.rot.y += 0.07f;
	////}
	////else if (GetJoypadPress(STICKANGLE_RIGHT) == true)//RIGHT
	////{
	////	g_camera.rot.y -= 0.07f;
	////}

	//m_posR = m_pos;
	//m_posV.x = sinf(m_rot.y) * -180.0f + m_posR.x;//変えるのはここ
	//m_posV.z = cosf(m_rot.y) * -180.0f + m_posR.z;//変えるのはここ
	//m_posV.y = m_posR.y + 250;

	//m_pos.x = m_pos.x;
	//m_pos.y = m_pos.y;
	//m_pos.z = m_pos.z;

	////移動量を更新（減衰させる）
	//m_move.x += (0.0f - m_move.x) * 0.2f;

	//m_move.y += (0.0f - m_move.y) * 0.2f;

	//m_move.z += (0.0f - m_move.z) * 0.2f;

	//m_posR.x += (0.1f - 0.0f) * 0.2f;
	//m_posV.x += (0.1f - 0.0f) * 0.2f;
}
//===================================
// 
//カメラの設定処理
//
//===================================
void CCamera::SetCamera()
{
	LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();
	//プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxProjection);
	//プロジェクションマトリックスを作成
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection, D3DXToRadian(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 10.0f, 1000.0f);
	////平行投影(正射影)
	//D3DXMatrixOrthoLH(&m_mtxProjection, (float)SCREEN_HEIGHT, (float)SCREEN_WIDTH, 10.0f, 1000.0f);

	//プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);
	//ビューマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxView);

	//ビューマトリックスの作成
	D3DXMatrixLookAtLH(&m_mtxView, &m_posV, &m_posR, &m_vecU);

	//ビューマトリックスの設定
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

}