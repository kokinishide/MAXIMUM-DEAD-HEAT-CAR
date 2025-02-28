//=============================================================================
//
// プレイヤー処理 [player.cpp]
// Author :: Koki_Nishide
//
//=============================================================================

#include "main.h"
#include "player.h"
#include "input.h"
#include "manager.h"
#include "bullet.h"
#include "object3D.h"
#include "ground.h"
#include "enemy.h"
#include "truck.h"
#include "player_bullet.h"
#include "boss.h"

//===================================
//
//コンストラクタ
//
//===================================
CPlayer::CPlayer()
{
	nCounterDushAttack;//ダッシュアタックカウンター

	m_nNumKey = 0; //キーの総数
	m_nCurKey = 0; //現在のキー番号
	m_nCntMotion = 0; //モーションカウンター
	
	for (int nCntKeySet = 0; nCntKeySet < MAX_KEY_SET; nCntKeySet++)
	{
		m_aKeySet[nCntKeySet].nFrame = 0;
		for (int nCntKey = 0; nCntKey < MAX_PARTS; nCntKey++)
		{
			//位置
			m_aKeySet[nCntKeySet].aKey[nCntKey].fPosX = 0.0f;
			m_aKeySet[nCntKeySet].aKey[nCntKey].fPosY = 0.0f;
			m_aKeySet[nCntKeySet].aKey[nCntKey].fPosZ = 0.0f;
			//向き
			m_aKeySet[nCntKeySet].aKey[nCntKey].fRotX = 0.0f;
			m_aKeySet[nCntKeySet].aKey[nCntKey].fRotY = 0.0f;
			m_aKeySet[nCntKeySet].aKey[nCntKey].fRotZ = 0.0f;
		}
	}
}
//===================================
// 
//デスストラクタ
//
//===================================
CPlayer::~CPlayer()
{

}

//===================================
// 
//プレイヤーの初期化処理
//
//===================================
HRESULT CPlayer::Init(void)
{
	//モデルパーツ生成
	//m_apModel[6] = CModelParts::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	/*CPlayer::SetPos();
	CPlayer::SetRot();*/

	Load();

	CPlayer::m_nLife = 15;
	CPlayer::m_nGoal = 1;

	SetType(CObject::TYPE::PLAYER);
	//モデル設定
	//CModel* pModel = CManager::GetModel();//取得
	//m_nModelIdx = pModel->Regist("data\\carplayer.x");//登録
	//DWORD dwNumMatModel = pModel->GetMatModel(m_nModelIdx);
	//LPD3DXBUFFER pBuff = pModel->GetBuffer(m_nModelIdx);
	//LPD3DXMESH pMesh = pModel->GetMesh(m_nModelIdx);
	//LPDIRECT3DTEXTURE9 pTexture = pModel->GetTexture(m_nModelIdx);

	//BindModel(dwNumMatModel, pBuff, pMesh, pTexture);//設定
	// キー情報を設定

	m_aKeySet[0].nFrame = 0;
	m_aKeySet[0].aKey[0].fPosX = 0.00f, m_aKeySet[0].aKey[0].fPosY = 0.00f, m_aKeySet[0].aKey[0].fPosZ = 0.00f;
	m_aKeySet[0].aKey[0].fRotX = 0.00f, m_aKeySet[0].aKey[0].fRotY = 0.00f, m_aKeySet[0].aKey[0].fRotZ = 0.00f;
	m_aKeySet[0].aKey[1].fPosX = 0.00f, m_aKeySet[0].aKey[1].fPosY = 0.00f, m_aKeySet[0].aKey[1].fPosZ = 0.00f;
	m_aKeySet[0].aKey[1].fRotX = 0.03f, m_aKeySet[0].aKey[1].fRotY = 0.00f, m_aKeySet[0].aKey[1].fRotZ = 0.00f;
	m_aKeySet[0].aKey[2].fPosX = 0.00f, m_aKeySet[0].aKey[2].fPosY = 0.00f, m_aKeySet[0].aKey[2].fPosZ = 0.00f;
	m_aKeySet[0].aKey[2].fRotX = 0.00f, m_aKeySet[0].aKey[2].fRotY = -0.25f, m_aKeySet[0].aKey[2].fRotZ = 0.50f;
	m_aKeySet[0].aKey[3].fPosX = 0.00f, m_aKeySet[0].aKey[3].fPosY = 0.00f, m_aKeySet[0].aKey[3].fPosZ = 0.00f;
	m_aKeySet[0].aKey[3].fRotX = 0.00f, m_aKeySet[0].aKey[3].fRotY = -0.25f, m_aKeySet[0].aKey[3].fRotZ = 0.00f;
	m_aKeySet[0].aKey[4].fPosX = 0.00f, m_aKeySet[0].aKey[4].fPosY = 0.00f, m_aKeySet[0].aKey[4].fPosZ = 0.00f;
	m_aKeySet[0].aKey[4].fRotX = 0.00f, m_aKeySet[0].aKey[4].fRotY = 0.25f, m_aKeySet[0].aKey[4].fRotZ = -0.50f;
	m_aKeySet[0].aKey[5].fPosX = 0.00f, m_aKeySet[0].aKey[5].fPosY = 0.00f, m_aKeySet[0].aKey[5].fPosZ = 0.00f;
	m_aKeySet[0].aKey[5].fRotX = 0.00f, m_aKeySet[0].aKey[5].fRotY = 0.25f, m_aKeySet[0].aKey[5].fRotZ = 0.00f;
	m_aKeySet[0].aKey[6].fPosX = 0.00f, m_aKeySet[0].aKey[6].fPosY = 0.00f, m_aKeySet[0].aKey[6].fPosZ = 0.00f;
	m_aKeySet[0].aKey[6].fRotX = 0.00f, m_aKeySet[0].aKey[6].fRotY = 0.00f, m_aKeySet[0].aKey[6].fRotZ = -0.09f;
	m_aKeySet[0].aKey[7].fPosX = 0.00f, m_aKeySet[0].aKey[7].fPosY = 0.00f, m_aKeySet[0].aKey[7].fPosZ = 0.00f;
	m_aKeySet[0].aKey[7].fRotX = 0.00f, m_aKeySet[0].aKey[7].fRotY = 0.00f, m_aKeySet[0].aKey[7].fRotZ = 0.00f;
	m_aKeySet[0].aKey[8].fPosX = 0.00f, m_aKeySet[0].aKey[8].fPosY = 0.00f, m_aKeySet[0].aKey[8].fPosZ = 0.00f;
	m_aKeySet[0].aKey[8].fRotX = 0.00f, m_aKeySet[0].aKey[8].fRotY = 0.00f, m_aKeySet[0].aKey[8].fRotZ = 0.09f;
	m_aKeySet[0].aKey[9].fPosX = 0.00f, m_aKeySet[0].aKey[9].fPosY = 0.00f, m_aKeySet[0].aKey[9].fPosZ = 0.00f;
	m_aKeySet[0].aKey[9].fRotX = 0.00f, m_aKeySet[0].aKey[9].fRotY = 0.00f, m_aKeySet[0].aKey[9].fRotZ = 0.00f;
	m_aKeySet[1].nFrame = 0;
	m_aKeySet[1].aKey[0].fPosX = 0.00f, m_aKeySet[1].aKey[0].fPosY = -1.00f, m_aKeySet[1].aKey[0].fPosZ = 0.00f;
	m_aKeySet[1].aKey[0].fRotX = -0.03f, m_aKeySet[1].aKey[0].fRotY = 0.00f, m_aKeySet[1].aKey[0].fRotZ = 0.00f;
	m_aKeySet[1].aKey[1].fPosX = 0.00f, m_aKeySet[1].aKey[1].fPosY = 0.00f, m_aKeySet[1].aKey[1].fPosZ = 0.00f;
	m_aKeySet[1].aKey[1].fRotX = -0.06f, m_aKeySet[1].aKey[1].fRotY = 0.00f, m_aKeySet[1].aKey[1].fRotZ = 0.00f;
	m_aKeySet[1].aKey[2].fPosX = 0.00f, m_aKeySet[1].aKey[2].fPosY = 0.00f, m_aKeySet[1].aKey[2].fPosZ = 0.00f;
	m_aKeySet[1].aKey[2].fRotX = 0.00f, m_aKeySet[1].aKey[2].fRotY = -0.25f, m_aKeySet[1].aKey[2].fRotZ = 0.79f;
	m_aKeySet[1].aKey[3].fPosX = 0.00f, m_aKeySet[1].aKey[3].fPosY = 0.00f, m_aKeySet[1].aKey[3].fPosZ = 0.00f;
	m_aKeySet[1].aKey[3].fRotX = 0.00f, m_aKeySet[1].aKey[3].fRotY = -0.53f, m_aKeySet[1].aKey[3].fRotZ = 0.00f;
	m_aKeySet[1].aKey[4].fPosX = 0.00f, m_aKeySet[1].aKey[4].fPosY = 0.00f, m_aKeySet[1].aKey[4].fPosZ = 0.00f;
	m_aKeySet[1].aKey[4].fRotX = 0.00f, m_aKeySet[1].aKey[4].fRotY = 0.25f, m_aKeySet[1].aKey[4].fRotZ = -0.79f;
	m_aKeySet[1].aKey[5].fPosX = 0.00f, m_aKeySet[1].aKey[5].fPosY = 0.00f, m_aKeySet[1].aKey[5].fPosZ = 0.00f;
	m_aKeySet[1].aKey[5].fRotX = 0.00f, m_aKeySet[1].aKey[5].fRotY = 0.53f, m_aKeySet[1].aKey[5].fRotZ = 0.00f;
	m_aKeySet[1].aKey[6].fPosX = 0.00f, m_aKeySet[1].aKey[6].fPosY = 0.50f, m_aKeySet[1].aKey[6].fPosZ = 0.00f;
	m_aKeySet[1].aKey[6].fRotX = 0.06f, m_aKeySet[1].aKey[6].fRotY = 0.00f, m_aKeySet[1].aKey[6].fRotZ = -0.09f;
	m_aKeySet[1].aKey[7].fPosX = 0.00f, m_aKeySet[1].aKey[7].fPosY = 0.00f, m_aKeySet[1].aKey[7].fPosZ = 0.00f;
	m_aKeySet[1].aKey[7].fRotX = 0.00f, m_aKeySet[1].aKey[7].fRotY = -0.18f, m_aKeySet[1].aKey[7].fRotZ = 0.00f;
	m_aKeySet[1].aKey[8].fPosX = 0.00f, m_aKeySet[1].aKey[8].fPosY = 0.50f, m_aKeySet[1].aKey[8].fPosZ = 0.00f;
	m_aKeySet[1].aKey[8].fRotX = 0.06f, m_aKeySet[1].aKey[8].fRotY = 0.00f, m_aKeySet[1].aKey[8].fRotZ = 0.09f;
	m_aKeySet[1].aKey[9].fPosX = 0.00f, m_aKeySet[1].aKey[9].fPosY = 0.00f, m_aKeySet[1].aKey[9].fPosZ = 0.00f;
	m_aKeySet[1].aKey[9].fRotX = -0.18f, m_aKeySet[1].aKey[9].fRotY = 0.00f, m_aKeySet[1].aKey[9].fRotZ = 0.00f;

	return S_OK;
}

//===================================
// 
//プレイヤーのヒット処理
//
//===================================
void CPlayer::Hit(int nDamage)
{
	CObject3D::Hit(nDamage);
}
//===================================
// 
//プレイヤーのヒットゴール処理
//
//===================================
void CPlayer::HitGoal(int nHit)
{
	CObject3D::HitGoal(nHit);
}
//===================================
// 
//プレイヤーのヒットワープ処理
//
//===================================
void CPlayer::HitWarp(int nHitWarp)
{
	CObject3D::HitWarp(nHitWarp);
}
//===================================
// 
//プレイヤーの終了処理
//
//===================================
void CPlayer::Uninit()
{
	CObject3D::Uninit();//this->Release();自身の開放
}
//===================================
// 
//プレイヤーの更新処理
//
//===================================
void CPlayer::Update()
{

	m_PosOld = m_pos;

	D3DXVECTOR3 PlayerPos = GetPos();
	D3DXVECTOR3 PlayerMove = GetMove();

	if (PlayerPos.z >= 49120.0f)
	{
		PlayerMove.z = 0.0f;
	}
	//Move += D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	////位置を更新
	//Pos += Move;
	/*for (int nCntModel = 0; nCntModel < MAX_PARTS; nCntModel++)
	{
		m_nCntMotion / 40;
		
	}*/
	m_nCntMotion++; //モーションカウンターを進める

	/*if ()
	{
		if ()
		{

		}
	}*/

	/*if (Pos.x >= 230.0f)
	{
		Pos.x = 230.0f;
		Move.x = 0.0f;
	}
	else if (Pos.x <= -300.0f)
	{
		Pos.x = -300.0f;
		Move.x = 0.0f;
	}*/
	/*if (PlayerPos.y >= 60.0f)
	{
		PlayerPos.y = 60.0f;
		PlayerMove.y = 0.0f;
	}*/
	/*if (Pos.z >= 100.0f)
	{
		Pos.z = 100.0f;
		Move.z = 0.0f;
	}*/
	/*if (Pos.z <= -100.0f)
	{
		Pos.z = -100.0f;
		Move.z = 0.0f;
	}*/

	CInputGamePad* pButton = CManager::GetGamePad();
	//トリガーの値を取得
	int TriggerValue = pButton->GetTriggerValue();
	float NorTriggerValue = pButton->GetNorTriggerValue();
	PlayerMove.y -= 1.0f;//重力
	if (CManager::GetKeyboard()->GetTrigger(DIK_SPACE) == true)
	{//SPACEキーが押された
		if (IsLanding == true)
		{
			PlayerMove.y += 5.0f;
			IsLanding = false;
		}
	}
	//右トリガー
	//if (NorTriggerValue < 1.0)
	//{
	//	//RTが押された
	//	if (IsLanding == true)
	//	{
	//		Move.y += 190.0f;
	//		IsLanding = false;
	//	}
	//}
	////左トリガー
	//if (NorTriggerValue > 1.0)
	//{
	//	//LTが押された
	//	if (IsLanding == true)
	//	{
	//		Move.y += 190.0f;
	//		IsLanding = false;
	//	}
	//}
	
	if (CManager::GetKeyboard()->GetTrigger(DIK_UPARROW) == true)
	{//UPARROWキーが押された
		//弾の設定
		CPlayer_Bullet::Create(m_pos, D3DXVECTOR3(0.0f, 10.0f, 7.0f), 30);

	}
	//if (CManager::GetGamePad()->GetTrigger(1) == true)
	//{//Bが押された
	//	//弾の設定
	//	CPlayer_Bullet::Create(m_pos, D3DXVECTOR3(0.0f, 10.0f, 7.0f), 30);
	//}
	
	if (CManager::GetKeyboard()->GetPress(DIK_A) == true)
	{//Aキーが押された
		//m_pos.x = 1.0f;
		//Wキーが押された
		if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
			//m_pos.y = -1.0f;
		{//左上移動

			PlayerMove.x += sinf(-D3DX_PI * 0.25f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 0.25f) * 1.0f;
		}
		//Sキーが押された
		else if (CManager::GetKeyboard()->GetPress(DIK_S) == true)
		{//左下移動
			PlayerMove.x += sinf(-D3DX_PI * 0.75f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 0.75f) * 1.0f;
		}
		//Aのみ
		else
		{//左移動
			PlayerMove.x += sinf(-D3DX_PI * 0.5f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 0.5f) * 1.0f;

		}

	}
	//Dキーが押された
	else if (CManager::GetKeyboard()->GetPress(DIK_D) == true)
	{
		//Wキーが押された
		if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
		{//右上移動

			PlayerMove.x += sinf(D3DX_PI * 0.25f) * 1.0f;
			PlayerMove.z += cosf(D3DX_PI * 0.25f) * 1.0f;
		}
		//Sキーが押された
		else if (CManager::GetKeyboard()->GetPress(DIK_S) == true)
		{//右下移動
			PlayerMove.x += sinf(D3DX_PI * 0.75f) * 1.0f;
			PlayerMove.z += cosf(D3DX_PI * 0.75f) * 1.0f;
		}
		//Dのみ
		else
		{//右移動
			PlayerMove.x += sinf(D3DX_PI * 0.5f) * 1.0f;
			PlayerMove.z += cosf(D3DX_PI * 0.5f) * 1.0f;
		}
	}

	//Wキーが押された
	else if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
	{
		//Aキーが押された
		if (CManager::GetKeyboard()->GetPress(DIK_A) == true)
		{//左上移動
			PlayerMove.x += sinf(-D3DX_PI * 1.0f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 1.0f) * 1.0f;//75
		}
		//Dキーが押された
		else if (CManager::GetKeyboard()->GetPress(DIK_D) == true)
		{//右上移動
			PlayerMove.x += sinf(-D3DX_PI * 0.75f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 0.75f) * 1.0f;
		}
		//Wのみ
		else
		{//上移動
			PlayerMove.x += sinf(D3DX_PI * 0.0f) * 1.0f;
			PlayerMove.z += cosf(D3DX_PI * 0.0f) * 1.0f;
		}
	}

	//Sキーが押された
	else if (CManager::GetKeyboard()->GetPress(DIK_S) == true)
	{
		//Aキーが押された
		if (CManager::GetKeyboard()->GetPress(DIK_A) == true)
		{//左下移動
			PlayerMove.x += sinf(-D3DX_PI * 0.25f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 0.25f) * 1.0f;
		}
		//Dキーが押された
		else if (CManager::GetKeyboard()->GetPress(DIK_D) == true)
		{//右下移動
			PlayerMove.x += sinf(+D3DX_PI * 0.25f) * 1.0f;
			PlayerMove.z += cosf(+D3DX_PI * 0.25f) * 1.0f;
		}
		//Sのみ
		else
		{//下移動
			PlayerMove.x += sinf(-D3DX_PI * 1.0f) * 1.0f;
			PlayerMove.z += cosf(-D3DX_PI * 1.0f) * 1.0f;
		}
	}

	//if (pButton->GetNorStick_lx() < 0.2)
	//{//スティックが左方向にはじかれた
	//	//スティックが上方向にはじかれた
	//	//if (pButton->GetNorStick_ly() < 0.2)
	//	//	//m_pos.y = -1.0f;
	//	//{//左上移動
	//
	//	//	Move.x += sinf(-D3DX_PI * 0.25f) * 1.0f;
	//	//	Move.z += cosf(-D3DX_PI * 0.25f) * 1.0f;
	//	//}
	//	////スティックが下方向にはじかれた
	//	//else if (pButton->GetNorStick_ly() > 1.8)
	//	//{//左下移動
	//	//	Move.x += sinf(-D3DX_PI * 0.75f) * 1.0f;
	//	//	Move.z += cosf(-D3DX_PI * 0.75f) * 1.0f;
	//	//}
	//	////左のみ
	//	//else
	//	//{//左移動
	//		Move.x += sinf(-D3DX_PI * 0.5f) * 1.5f;
	//		Move.z += cosf(-D3DX_PI * 0.5f) * 1.5f;
	//	//}
	//}
	////スティックが右方向にはじかれた
	//else if (pButton->GetNorStick_lx() > 1.8)//<0.2
	//{
	//	////スティックが上方向にはじかれたされた
	//	//if (pButton->GetNorStick_ly() < 0.2)
	//	//{//右上移動

	//	//	Move.x += sinf(D3DX_PI * 0.25f) * 1.0f;
	//	//	Move.z += cosf(D3DX_PI * 0.25f) * 1.0f;
	//	//}
	//	////スティックが下方向にはじかれた
	//	//else if (pButton->GetNorStick_ly() > 1.8)
	//	//{//右下移動
	//	//	Move.x += sinf(D3DX_PI * 0.75f) * 1.0f;
	//	//	Move.z += cosf(D3DX_PI * 0.75f) * 1.0f;
	//	//}
	//	////右のみ
	//	//else
	//	//{//右移動
	//		Move.x += sinf(D3DX_PI * 0.5f) * 1.5f;
	//		Move.z += cosf(D3DX_PI * 0.5f) * 1.5f;
	//	//}
	//}
	////スティックが上方向にはじかれた
	//else if (pButton->GetNorStick_ly() < 0.2)
	//{
	//	//スティックが左方向にはじかれた
	//	if (pButton->GetNorStick_lx() < 0.2)
	//	{//左上移動
	//		Move.x += sinf(-D3DX_PI * 1.0f) * 1.0f;
	//		Move.z += cosf(-D3DX_PI * 1.0f) * 1.0f;//75
	//	}
	//	//スティックが右方向にはじかれた
	//	else if (pButton->GetNorStick_lx() > 1.8)
	//	{//右上移動
	//		Move.x += sinf(-D3DX_PI * 0.75f) * 1.0f;
	//		Move.z += cosf(-D3DX_PI * 0.75f) * 1.0f;
	//	}
	//	//上のみ
	//	else
	//	{//上移動
	//		Move.x += sinf(D3DX_PI * 0.0f) * 1.0f;
	//		Move.z += cosf(D3DX_PI * 0.0f) * 1.0f;
	//	}
	//}
	////スティックが下方向にはじかれた
	//else if (pButton->GetNorStick_ly() > 1.8)
	//{
	////スティックが左方向にはじかれた
	//if (pButton->GetNorStick_lx() < 0.2)
	//{//左下移動
	//	Move.x += sinf(-D3DX_PI * 0.25f) * 1.0f;
	//	Move.z += cosf(-D3DX_PI * 0.25f) * 1.0f;
	//}
	////スティックが右方向にはじかれた
	//else if (pButton->GetNorStick_lx() > 1.8)
	//{//右下移動
	//	Move.x += sinf(+D3DX_PI * 0.25f) * 1.0f;
	//	Move.z += cosf(+D3DX_PI * 0.25f) * 1.0f;
	//}
	////下のみ
	//else
	//{//下移動
	//	Move.x += sinf(-D3DX_PI * 1.0f) * 1.0f;
	//	Move.z += cosf(-D3DX_PI * 1.0f) * 1.0f;
	//}
	//}

	bool bDushAttack = GetDushAttack();//ダッシュアタックの取得

	if (CManager::GetKeyboard()->GetTrigger(DIK_RETURN) == true)
	{//RETURNキーが押された
		
		if (CManager::GetKeyboard()->GetPress(DIK_A) == true)
		{//Aキーが押された
			//m_pos.x = 1.0f;
			//Wキーが押された
			if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
				//m_pos.y = -1.0f;
			{//左上移動

				PlayerMove.x += sinf(-D3DX_PI * 0.25f) * 2.0f;
				PlayerMove.z += cosf(-D3DX_PI * 0.25f) * 2.0f;
			}
			//Sキーが押された
			else if (CManager::GetKeyboard()->GetPress(DIK_S) == true)
			{//左下移動
				PlayerMove.x += sinf(-D3DX_PI * 0.75f) * 2.0f;
				PlayerMove.z += cosf(-D3DX_PI * 0.75f) * 2.0f;
			}
			//Aのみ
			else
			{//左移動
				PlayerMove.x += sinf(-D3DX_PI * 0.5f) * 2.5f;
				PlayerMove.z += cosf(-D3DX_PI * 0.5f) * 2.5f;
			}
			bDushAttack = true;
		}
		//Dキーが押された
		else if (CManager::GetKeyboard()->GetPress(DIK_D) == true)
		{
			//Wキーが押された
			if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
			{//右上移動

				PlayerMove.x += sinf(D3DX_PI * 0.25f) * 2.0f;
				PlayerMove.z += cosf(D3DX_PI * 0.25f) * 2.0f;
			}
			//Sキーが押された
			else if (CManager::GetKeyboard()->GetPress(DIK_S) == true)
			{//右下移動
				PlayerMove.x += sinf(D3DX_PI * 0.75f) * 2.0f;
				PlayerMove.z += cosf(D3DX_PI * 0.75f) * 2.0f;
			}
			//Dのみ
			else
			{//右移動
				PlayerMove.x += sinf(D3DX_PI * 0.5f) * 2.5f;
				PlayerMove.z += cosf(D3DX_PI * 0.5f) * 2.5f;
			}
			bDushAttack = true;
		}
		//Wキーが押された
		else if (CManager::GetKeyboard()->GetPress(DIK_W) == true)
		{//上移動
			PlayerMove.x += sinf(D3DX_PI * 0.0f) * 2.0f;
			PlayerMove.z += cosf(D3DX_PI * 0.0f) * 2.0f;
			bDushAttack = true;
		}
		
	}
	//else if (CManager::GetGamePad()->GetTrigger(2) == true)
	//{//Xが押された

	//	if (pButton->GetNorStick_lx() < 0.2)
	//	{//スティックが左方向にはじかれた
	//		//スティックが上方向にはじかれた
	//		if (pButton->GetNorStick_ly() < 0.2)
	//			//m_pos.y = -1.0f;
	//		{//左上移動

	//			Move.x += sinf(-D3DX_PI * 0.25f) * 2.0f;
	//			Move.z += cosf(-D3DX_PI * 0.25f) * 2.0f;
	//		}
	//		//スティックが下方向にはじかれた
	//		else if (pButton->GetNorStick_ly() > 1.8)
	//		{//左下移動
	//			Move.x += sinf(-D3DX_PI * 0.75f) * 2.0f;
	//			Move.z += cosf(-D3DX_PI * 0.75f) * 2.0f;
	//		}
	//		//左のみ
	//		else
	//		{//左移動
	//			Move.x += sinf(-D3DX_PI * 0.5f) * 2.5f;
	//			Move.z += cosf(-D3DX_PI * 0.5f) * 2.5f;
	//		}
	//		bDushAttack = true;
	//	}
	//	//スティックが右方向にはじかれた
	//	else if (pButton->GetNorStick_lx() > 1.8)//<0.2
	//	{
	//		//スティックが上方向にはじかれたされた
	//		if (pButton->GetNorStick_ly() < 0.2)
	//		{//右上移動

	//			Move.x += sinf(D3DX_PI * 0.25f) * 2.0f;
	//			Move.z += cosf(D3DX_PI * 0.25f) * 2.0f;
	//		}
	//		//スティックが下方向にはじかれた
	//		else if (pButton->GetNorStick_ly() > 1.8)
	//		{//右下移動
	//			Move.x += sinf(D3DX_PI * 0.75f) * 2.0f;
	//			Move.z += cosf(D3DX_PI * 0.75f) * 2.0f;
	//		}
	//		//右のみ
	//		else
	//		{//右移動
	//			Move.x += sinf(D3DX_PI * 0.5f) * 2.5f;
	//			Move.z += cosf(D3DX_PI * 0.5f) * 2.5f;
	//		}
	//		bDushAttack = true;
	//	}
	//	//スティックが上方向にはじかれた
	//	else if (pButton->GetNorStick_ly() < 0.2)
	//	{//上移動
	//		Move.x += sinf(D3DX_PI * 0.0f) * 2.0f;
	//		Move.z += cosf(D3DX_PI * 0.0f) * 2.0f;
	//		bDushAttack = true;
	//	}

	//}

	//位置を更新
	D3DXVECTOR3 PlayerPosOld = GetPosOld();
	PlayerPosOld = m_pos;
	PlayerPos += PlayerMove;
	//移動量を更新（減衰させる）
	PlayerMove.x += (0.0f - PlayerMove.x) * 0.2f;

	PlayerMove.z += (0.0f - PlayerMove.z) * 0.2f;
	
	SetPos(PlayerPos);//プレイヤーのPos設定
	SetMove(PlayerMove);//プレイヤーのMove設定
	

	// ダッシュアタック
	if (bDushAttack == true)
	{
		nCounterDushAttack++; //カウンターを加算
		if (nCounterDushAttack >= 100)
		{
			nCounterDushAttack = 0;//カウンターを初期値に戻す
			bDushAttack = false;
		}
	}

	

	// 当たり判定開始
	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	//{
	//	//敵との当たり判定（配列を順番にチェック）
	//	for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
			//オブジェクト取得
			CObject* pObj = CObject::GetMyObject();
			//最大数が不明なのでWhileを使用
			while (pObj != nullptr)
			{
				// 次のポインタを保存しておく
				CObject* pNext = pObj->GetNext();
				// やりたい処理を実行（今回はタイプ取得）
				if (CObject::TYPE::ENEMY == pObj->GetType())
				{
					CEnemy* pEnemy = (CEnemy*)pObj;
					D3DXVECTOR3 EnemyPos = pEnemy->GetPos();//敵の位置の取得
					D3DXVECTOR3 EnemyMove = pEnemy->GetMove();//敵の動きの取得

					//位置を更新
					//EnemyPos += EnemyMove;
					D3DXVECTOR3 vec = EnemyPos - PlayerPos;
					D3DXVECTOR3 move = vec * 1.0f;

					if (m_pos.x >= EnemyPos.x - 20.0f
						&& m_pos.x <= EnemyPos.x + 20.0f
						&& m_pos.z >= EnemyPos.z - 20.0f
						&& m_pos.z <= EnemyPos.z + 20.0f)
					{
						if (bDushAttack == true)
						{

							pEnemy->Hit(1);
							EnemyMove.y = 0.0f;
							pEnemy->SetMove(move);
							pEnemy->SetDushAttack(true);
							

						}
						else
						{
							Hit(1);
							PlayerMove.y = 0.0f;
							SetMove(-move);

						}
						
					}
					
				}
				if (CObject::TYPE::TRUCK == pObj->GetType())
				{
					CTruck* pTruck = (CTruck*)pObj;
					D3DXVECTOR3 TruckPos = pTruck->GetPos();//トラックの位置の取得
					D3DXVECTOR3 TruckMove = pTruck->GetMove();//トラックの動きの取得
					
					//位置を更新
					//EnemyPos += EnemyMove;
					D3DXVECTOR3 vec = TruckPos - PlayerPos;
					D3DXVECTOR3 move = vec * 1.0f;

					if (m_pos.x >= TruckPos.x - 25.0f
						&& m_pos.x <= TruckPos.x + 25.0f
						&& m_pos.z >= TruckPos.z - 30.0f
						&& m_pos.z <= TruckPos.z + 30.0f)
					{
						if (bDushAttack == true)
						{

							pTruck->Hit(1);
							TruckMove.y = 0.0f;
							pTruck->SetMove(move);
							pTruck->SetDushAttack(true);


						}
						else
						{
							Hit(1);
							PlayerMove.y = 0.0f;
							SetMove(-move);

						}

					}

				}
				if (CObject::TYPE::BOSS == pObj->GetType())
				{
					CBoss* pBoss = (CBoss*)pObj;
					D3DXVECTOR3 BossPos = pBoss->GetPos();//ボスの位置の取得
					D3DXVECTOR3 BossMove = pBoss->GetMove();//ボスの動きの取得

					//位置を更新
					//EnemyPos += EnemyMove;
					D3DXVECTOR3 vec = BossPos - PlayerPos;
					D3DXVECTOR3 move = vec * 0.5f;

					if (m_pos.x >= BossPos.x - 85.0f
						&& m_pos.x <= BossPos.x + 85.0f
						&& m_pos.z >= BossPos.z - 25.0f
						&& m_pos.z <= BossPos.z + 105.0f)
					{
						
						Hit(1);
						PlayerMove.y = 0.0f;
						SetMove(-move);

					}

				}
				// ポインタを次のポインタへ変更
				pObj = pNext;
			}
		//}
	//}
	
	SetDushAttack(bDushAttack);//プレイヤーのDushAttack設定

}
//===================================
// 
//プレイヤーの描画処理
//
//===================================
void CPlayer::Draw()
{
	CObject3D::Draw();//ポリゴン描画
	/*for (int nCntMat = 0; nCntMat < (int)m_dwNumMatModel; nCntMat++)
	{
		m_apModel[6]->Draw();
	}*/
}

//===================================
// 
//プレイヤーの生成処理
// 
//===================================
CPlayer* CPlayer::Create(D3DXVECTOR3 pos)
{
	CPlayer* pPlayer = new CPlayer();//プレイヤー生成
	if (FAILED(pPlayer->Init())) {
	}
	pPlayer->SetPos(pos);
	pPlayer->BindMesh(pPlayer->GetMatModel(), pPlayer->GetBuffer(), pPlayer->GetMesh(), nullptr);
	//pPlayer->SetType(CObject::PLAYER);
	return pPlayer;
}
//===================================
// 
//プレイヤーのロード処理
//
//===================================
HRESULT CPlayer::Load()
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	pDevice = CManager::GetRenderer()->GetDevice();
	LPD3DXBUFFER PlayerBuffer = GetBuffer();
	DWORD PlayerMatModel = GetMatModel();
	LPD3DXMESH PlayerMesh = GetMesh();
	
	if (FAILED(D3DXLoadMeshFromX("data\\carplayer.x", D3DXMESH_SYSTEMMEM, pDevice, nullptr, &PlayerBuffer, nullptr, &PlayerMatModel, &PlayerMesh)))
	{
		return E_FAIL;
	}
	SetBuffer(PlayerBuffer);
	SetMatModel(PlayerMatModel);
	SetMesh(PlayerMesh);
	return S_OK;

}
//===================================
// 
//プレイヤーのアンロード処理
//
//===================================
void CPlayer::Unload()
{
	CObject3D::Unload();
}