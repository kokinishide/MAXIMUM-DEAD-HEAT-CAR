//=============================================================================
//
// ブロックのマネージャー処理 [block_manager.cpp]
// Author :: Koki_Nishide
//
//=============================================================================
#include<stdio.h>
#include"block.h"
#include"block_manager.h"
#include"manager.h"
#include"object.h"
#include"object2D.h"
#include"renderer.h"

//===================================
// 
//コンストラクタ
//
//===================================
CBlock_Manager::CBlock_Manager()
{
	m_apBlockList[1] = nullptr;

}
//===================================
// 
//デストラクタ
//
//===================================
CBlock_Manager::~CBlock_Manager()
{

}
//===================================
// 
//ブロックマネージャーの初期化処理
//
//===================================
HRESULT CBlock_Manager::Init()
{
	//int nIndex;

	////ブロックの配置
	////CBlock::Load();//読み込み(破棄はCManager::Uninitで)
	//m_apBlockList[1] = CBlock::Create(D3DXVECTOR3(-220.0f, -1.0f, 0.0f));


	//m_apBlockList[1] = CBlock::Create(D3DXVECTOR3(220.0f, -1.0f, 0.0f));
	//m_apBlockList[1] = CBlock::Create(D3DXVECTOR3(220.0f, -1.0f, 400.0f));
	////登録
	//for (nIndex = 0; nIndex < 1; nIndex++)
	//{
	//	m_apBlockList[nIndex] = pBlock;
	//}
	return S_OK;
}
//===================================
// 
//ブロックマネージャーの終了処理
// 
//===================================
void CBlock_Manager::Uninit()
{
	
}