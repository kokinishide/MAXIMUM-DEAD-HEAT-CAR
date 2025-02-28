//=============================================================================
//
// �Q�[����ʂւ̑J�ڏ��� [game.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _GAME_H_//���̃}�N����`������ĂȂ�������
#define _GAME_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include"object.h"
#include"object3D.h"
#include "scene.h"
#include"block.h"
#include"block_manager.h"
#include"score_manager.h"

class CPlayer;

class CGame : public CScene
{
public:
	CGame();//�R���X�g���N�^
	~CGame();//�f�X�g���N�^
	HRESULT Init() override;//�����ݒ�
	void Uninit() override;//�I������
	void Update() override;//�X�V����
	void Draw() override;//�`�揈��
	static CGame* Create();//����
	static CBlock_Manager* GetBlock_Manager() { return m_pBlock_Manager; }
	//static CScore_Manager* GetScore_Manager() { return m_pScore_Manager; }
	static CPlayer* GetPlayer() { return m_pPlayer; }
private:
	static CBlock_Manager* m_pBlock_Manager;//�u���b�N�}�l�[�W���[
	//static CScore_Manager* m_pScore_Manager;//�X�R�A�}�l�[�W���[
	static CPlayer* m_pPlayer;//�v���C���[�ւ̃|�C���^
};

#endif //_GAME_H_