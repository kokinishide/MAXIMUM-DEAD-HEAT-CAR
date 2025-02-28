//=============================================================================
//
// �t�F�[�h���� [fade.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _FADE_H_//���̃}�N����`������ĂȂ�������
#define _FADE_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include"scene.h"
#include "object2D.h"

class CFade : public CObject2D
{
public:
	typedef enum
	{
		FADE_NONE = 0, //�ʏ���
		FADE_IN, //�_���[�W���
		FADE_OUT,
		FADE_MAX,

	}FADE;
	CFade();
	CFade(int nPriority);
	virtual ~CFade()override;
	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;
	void SetFade(CScene::MODE modenext);//�t�F�[�h�̐ݒ�
	void GetState();
	static CFade* Create();//����
	static HRESULT Load();//���[�h
	static void Unload();//�A�����[�h
private:
	CScene::MODE m_ModeNext;//���̃��[�h
	static LPDIRECT3DTEXTURE9 m_pTextureFade;//�e�N�X�`��
	int m_nfade;
	float m_colora;


};

#endif //_FADE_H_



