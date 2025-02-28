//=============================================================================
//
// オブジェクト処理 [object.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include<stdio.h>
#include"object.h"
#include"object2D.h"
#include"player.h"

//===================================
// 
//静的メンバ初期化
//
//===================================
int CObject::m_nNumAll = 0;
CObject* CObject::m_apMyObject[m_nMAX_PRIORITY][MAX_DATA] = {};
CObject* CObject::m_pTop = nullptr;//先頭のオブジェクトのポインタ
CObject* CObject::m_pCur = nullptr;//現在（最後尾）のポインタ

//CObject* CObject::m_apObject = {};
//CObject2D* CObject2D::m_pObject2D;
////CPlayer* CPlayer;

//===================================
//
//コンストラクタ(プライオリティ)
//
//===================================
CObject::CObject(int nPriority)
{

	m_pPrev = nullptr;
	m_pNext = nullptr;
	if (m_pTop == nullptr)
	{ //先頭が空だったら
		m_pTop = this;//自分自身を代入
		m_pCur = this;
	}

	if (m_pCur != nullptr)
	{//最後尾が存在する
		m_pCur->m_pNext = this;//自分の一つ前のオブジェクトの次のオブジェクトに自分自身を代入
		m_pPrev = m_pCur;//自分の一つ前のオブジェクトとして最後尾を設定
	}

	// 最後尾を自分自身に更新
	m_pCur = this;

	m_nPriority = nPriority;//描画優先度設定
	m_bUseRelease = true;
	m_bDeath = false;
	m_nNumAll++;//総数をカウントアップRelease


#if 0
	//m_type = NONE;
	int nCnt;
	m_nPriority = nPriority;//描画優先度設定
	m_bUseRelease = true;
	m_bDeath = false;
	for (nCnt = 0; nCnt < MAX_DATA; nCnt++)
	{
		if (m_apMyObject[nPriority][nCnt] == nullptr)
		{
			m_apMyObject[nPriority][nCnt] = this;//自分自身を代入
			m_nID = nCnt;//自分自身のIDを代入
			m_nNumAll++;//総数をカウントアップRelease
			break; //ループを抜ける
		}
	}
#endif
}
//===================================
// 
//デストラクタ
//
//===================================
CObject::~CObject()
{

}
//===================================
// 
//オブジェクトの初期化処理
//
//===================================
HRESULT CObject::Init(void)
{
	return S_OK;
}
//===================================
// 
//全オブジェクト解放
//
//===================================
void CObject::ReleaseAll()
{
	//int nCntObj;
	CObject* pObj = m_pTop;//先頭取得
	//最大数が不明なのでWhileを使用
	while (pObj != nullptr)
	{
		CObject* pNext = pObj->m_pNext;
		pObj->Uninit();
		pObj = pNext;
	}

	pObj = m_pTop;//先頭取得
	while (pObj != nullptr)
	{
		CObject* pNext = pObj->m_pNext;

		if (pObj->m_bDeath == true)
		{
			pObj->Release();
		}

		pObj = pNext;
	}

	//CObject* pObj = m_pTop;//先頭取得
	////最大数が不明なのでWhileを使用
	//while (pObj != nullptr)
	//{
	//	CObject* pNext = pObj->m_pNext;
	//	pObj->Release();
	//	pObj = pNext;
	//}
	//int nCntObj;


	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)//NULL
	//{

	//	for (nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
	//		if (m_apMyObject[nCntPriority][nCntObj] != nullptr)
	//		{
	//			//if (m_apMyObject[nCntPriority][nCntObj]->m_type == TYPE::FADE)
	//			//{
	//			//	int n = 0;
	//			//}
	//			if (m_apMyObject[nCntPriority][nCntObj]->m_bUseRelease == true)
	//			{

	//				m_apMyObject[nCntPriority][nCntObj]->Uninit();//自分自身を代入
	//			}
	//		}
	//	}
	//}
}
//===================================
// 
//全オブジェクト更新
//
//===================================
void CObject::UpdateAll()
{
	//int nCntObj;
	CObject* pObj = m_pTop;//先頭取得
	//最大数が不明なのでWhileを使用
	while (pObj != nullptr)
	{
		// 次のポインタを保存しておく
		CObject* pNext = pObj->m_pNext;
		// やりたい処理を実行（今回は更新）
		pObj->Update();
		// ポインタを次のポインタへ変更
		pObj = pNext;
	}

	//pObj = m_pTop;//先頭取得
	//while (pObj != nullptr)
	//{
	//	CObject* pNext = pObj->m_pNext;

	//	if (pObj->m_bDeath == true)
	//	{
	//		pObj->Release();
	//	}

	//	pObj = pNext;
	//}
	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	//{

	//	for (nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
	//		//CObject::TYPE type = m_apMyObject[nCntPriority][nCntObj]->GetType();

	//		if (m_apMyObject[nCntPriority][nCntObj] != nullptr)
	//		{
	//			m_apMyObject[nCntPriority][nCntObj]->Update();//自分自身を代入

	//		}
	//	}
	//}

}
//===================================
// 
//全オブジェクト描画
//
//===================================
void CObject::DrawAll()
{
	CObject* pObj = m_pTop;//先頭取得
	//最大数が不明なのでWhileを使用
	while (pObj != nullptr)
	{
		// 次のポインタを保存しておく
		CObject* pNext = pObj->m_pNext;

		// やりたい処理を実行（今回は描画）
		pObj->Draw();

		// ポインタを次のポインタへ変更
		pObj = pNext;
	}
	//int nCntObj;
	//for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	//{
	//	for (nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
	//	{
	//		if (m_apMyObject[nCntPriority][nCntObj] != nullptr)
	//		{
	//			m_apMyObject[nCntPriority][nCntObj]->Draw();//自分自身を代入

	//		}
	//	}
	//}

}
//===================================
// 
//自分自身の解放
//
//===================================
void CObject::Release()
{
	//Uninit();
	if (m_pTop == this)
	{
		m_pTop = m_pNext;
	}

	if (m_pCur == this)
	{
		m_pCur = m_pPrev;
	}

	if (m_pPrev != nullptr)
	{
		m_pPrev->m_pNext = m_pNext;
	}

	if (m_pNext != nullptr)
	{
		m_pNext->m_pPrev = m_pPrev;
	}
	
	//if (m_pTop == nullptr)
	//{ //先頭が空だったら
	//	m_pTop = this;//自分自身を代入
	//}

	//if (m_pCur != nullptr)
	//{//最後尾が存在する
	//	m_pCur->m_pNext = this;//自分の一つ前のオブジェクトの次のオブジェクトに自分自身を代入
	//	m_pPrev = m_pCur;//自分の一つ前のオブジェクトとして最後尾を設定
	//}


	//int nID = m_nID;
	//int nPriority = m_nPriority;
	//
	//if (m_apMyObject[nPriority][nID] != nullptr)
	//{
	//	delete m_apMyObject[nPriority][nID];
	//	m_apMyObject[nPriority][nID] = nullptr;
	//	m_nNumAll--;//総数をカウントダウン
	//}
	delete this;
}

//===================================
// 
//オブジェクト取得(プライオリティ)
//
//===================================
CObject* CObject::GetMyObject()
{
	return m_pTop;//先頭取得

	//return m_apMyObject[nPriority][nIdx];

}
//===================================
// 
//タイプ取得
//
//===================================
CObject::TYPE CObject::GetType()
{
	return m_type;
}
//===================================
// 
//ネクスト取得
//
//===================================
CObject* CObject::GetNext()
{
	return m_pNext;
}
//===================================
// 
//タイプ設定
//
//===================================
void CObject::SetType(TYPE type)
{
	m_type = type;
}
//===================================
// 
//ヒット処理
//
//===================================
//void CObject::Hit(int nDamage)
//{
//	
//}
////===================================
//// 
////ゴールヒット処理
////
////===================================
//void CObject::HitGoal(int nHit)
//{
//
//}
////===================================
//// 
////ワープヒット処理
////
////===================================
//void CObject::HitWarp(int nHitWarp)
//{
//
//}