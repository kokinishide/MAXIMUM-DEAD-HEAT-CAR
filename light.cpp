//=============================================================================
//
// ライト処理 [light.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include "main.h"
#include "light.h"
#include "manager.h"
#include "renderer.h"

//===================================
// 
//コンストラクタ
//
//===================================
CLight::CLight()
{
	//ライト情報のクリア
	ZeroMemory(&m_aLight, sizeof(D3DLIGHT9));
}
//===================================
// 
//デスストラクタ
//
//===================================
CLight::~CLight()
{

}
//===================================
// 
//ライトの初期化処理
//
//===================================
HRESULT CLight::Init(void)
{

	LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();
	D3DXVECTOR3 vecDir; //設定用方向ベクトル

	//ライトの情報をクリアする
	ZeroMemory(&m_aLight, sizeof(D3DLIGHT9));

	//ライトの種類を設定
	m_aLight[MAX_DATA].Type = D3DLIGHT_DIRECTIONAL;

	//ライトの拡散光を設定
	m_aLight[MAX_DATA].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//ライトの方向を設定
	vecDir = D3DXVECTOR3(0.2f, -0.8f, 0.4f);
	D3DXVec3Normalize(&vecDir, &vecDir);//ベクトルを正規化する

	m_aLight[MAX_DATA].Direction = vecDir;
	//ライトを設定する
	pDevice->SetLight(0, &m_aLight[MAX_DATA]);
	//ライトを有効にする
	pDevice->LightEnable(0, TRUE);
	return S_OK;
}
