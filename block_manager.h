//=============================================================================
//
// ブロックのマネージャー処理 [block_manager.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _BLOCK_MANAGER_H_//このマクロ定義がされてなかったら
#define _BLOCK_MANAGER_H_//2重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "object2D.h"
#include "block.h"

//ブロック管理クラス(stagemanagerでも)
class CBlock_Manager /*: public CObject*/
{
public:
	CBlock_Manager();//コンストラクタ
	~CBlock_Manager();//デストラクタ
	HRESULT Init();
	void Uninit();
private:
	//管理するブロック情報
	CBlock* m_apBlockList[1];
};

#endif //_BLOCK_MANAGER_H_