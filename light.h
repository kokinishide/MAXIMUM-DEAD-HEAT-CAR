//=============================================================================
//
// ���C�g���� [light.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _LIGHT_H_//���̃}�N����`������ĂȂ�������
#define	_LIGHT_H_//2�d�C���N���[�h�h�~�̃}�N����`

#define MAX_LIGHT (1)//���C�g�̍ő吔
#include "main.h"
//���C�g
class CLight
{
public:
	CLight();
	~CLight();
	HRESULT Init();
private:
	D3DLIGHT9 m_aLight[MAX_LIGHT];//���C�g�\����

};


#endif//_LIGHT_H_