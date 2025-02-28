//=============================================================================
//
// �|�[�Y��ʏ��� [pause.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _PAUSE_H_//���̃}�N����`������ĂȂ�������
#define	_PAUSE_H_//2�d�C���N���[�h�h�~�̃}�N����`
#include "main.h"
#include "object2D.h"


//�|�[�Y���
class CPause :public CObject2D
{
public:
	//�|�[�Y���j���[
	typedef enum
	{
		PAUSE_MENU_CONTINUE = 0, //�Q�[���ɖ߂�
		PAUSE_MENU_RETRY,//�Q�[������蒼��
		PAUSE_MENU_QUIT,//�^�C�g����ʂɖ߂�
		PAUSE_MENU_MAX
	}PAUSE_MENU;
	CPause();
	~CPause();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
private:

};

#endif //_PAUSE_H_