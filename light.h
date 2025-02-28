//=============================================================================
//
// ライト処理 [light.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _LIGHT_H_//このマクロ定義がされてなかったら
#define	_LIGHT_H_//2重インクルード防止のマクロ定義

#define MAX_LIGHT (1)//ライトの最大数
#include "main.h"
//ライト
class CLight
{
public:
	CLight();
	~CLight();
	HRESULT Init();
private:
	D3DLIGHT9 m_aLight[MAX_LIGHT];//ライト構造体

};


#endif//_LIGHT_H_