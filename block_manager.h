//=============================================================================
//
// �u���b�N�̃}�l�[�W���[���� [block_manager.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _BLOCK_MANAGER_H_//���̃}�N����`������ĂȂ�������
#define _BLOCK_MANAGER_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "object2D.h"
#include "block.h"

//�u���b�N�Ǘ��N���X(stagemanager�ł�)
class CBlock_Manager /*: public CObject*/
{
public:
	CBlock_Manager();//�R���X�g���N�^
	~CBlock_Manager();//�f�X�g���N�^
	HRESULT Init();
	void Uninit();
private:
	//�Ǘ�����u���b�N���
	CBlock* m_apBlockList[1];
};

#endif //_BLOCK_MANAGER_H_