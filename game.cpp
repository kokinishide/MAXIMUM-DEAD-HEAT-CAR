//=============================================================================
//
// �Q�[����ʂւ̑J�ڏ��� [game.cpp]
// Author :: Koki_Nishide
//
//=============================================================================

#include"main.h"
#include"game.h"
#include"input.h"
#include"manager.h"
#include"renderer.h"
#include"object3D.h"
#include"block.h"
#include"block_manager.h"
#include"bg.h"
#include"player.h"
#include"enemy.h"
#include"bullet.h"
#include"object.h"
#include"sound.h"
#include"goal.h"
#include"ground.h"
#include"warp.h"
#include"thinground.h"
#include"3DBG.h"
#include"gauge.h"
#include"helicopter.h"
#include"HP.h"
//#include"score.h"
#include"truck.h"
#include"jump_message.h"
#include"left_message.h"
#include"right_message.h"
#include"middle_message.h"
#include"boss_message.h"
#include"boss.h"
//#include"score_manager.h"

//CScore_Manager* CGame::m_pScore_Manager = nullptr;
CBlock_Manager* CGame::m_pBlock_Manager = nullptr;
CPlayer* CGame::m_pPlayer = nullptr;
bool m_bPause = false; //�|�[�Y�����ǂ���

//===================================
//
//�R���X�g���N�^
//
//===================================
CGame::CGame() : CScene()
{
	m_pBlock_Manager = nullptr;
	//m_pScore_Manager = nullptr;
	m_pPlayer = nullptr;
}
//===================================
//
//�f�X�g���N�^
//
//===================================
CGame::~CGame()
{
}

//===================================
// 
//�Q�[����ʂւ̑J�ڂ̏���������
// 
//===================================
HRESULT CGame::Init(void)
{
	//m_bPause = false; //�|�[�Y����
	//if (CManager::GetKeyboard()->GetTrigger(DIK_P) == true)
	//{//�|�[�Y�L�[�iP�L�[�j�������ꂽ
	//	m_bPause = m_bPause ? false : true;
	//}
	//if (m_bPause == false)
	//{//�|�[�Y���łȂ����

	//}
	//if (m_bPause == true)
	//{//�|�[�Y��
	//	//�|�[�Y�̍X�V����
	//	//UpdatePause();
	//}
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	//�f�o�C�X�̎擾
	pDevice = CManager::GetRenderer()->GetDevice();
	//�u���b�N�̐���
	m_pBlock_Manager = new CBlock_Manager();
	m_pBlock_Manager->Init();
	//�X�R�A�̐���
	/*m_pScore_Manager = new CScore_Manager();
	m_pScore_Manager->Init();*/

	//���̑��I�u�W�F�N�g�̐����Ȃ�
	//CObject3D::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	//CBG::Create();
	
	m_pPlayer = CPlayer::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CGauge::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CHP::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CJump_Message::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CLeft_Message::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CRight_Message::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CMiddle_Message::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CBoss_Message::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	//CEnemy::Load();//�ǂݍ���(�j����CManager::Uninit��)
 	CEnemy::Create(D3DXVECTOR3(150.0f, -10.0f, 0.0f));
	CEnemy::Create(D3DXVECTOR3(-50.0f, -10.0f, 3200.0f));
	CEnemy::Create(D3DXVECTOR3(-10.0f, -10.0f, 1200.0f));
	CEnemy::Create(D3DXVECTOR3(-50.0f, -10.0f, 2650.0f));
	CEnemy::Create(D3DXVECTOR3(70.0f, -10.0f, 2700.0f));
	CEnemy::Create(D3DXVECTOR3(-50.0f, -10.0f, 7650.0f));
	CEnemy::Create(D3DXVECTOR3(70.0f, -10.0f, 8700.0f));

	CTruck::Create(D3DXVECTOR3(40.0f, -10.0f, 0.0f));
	CTruck::Create(D3DXVECTOR3(-40.0f, -10.0f, 300.0f));
	CTruck::Create(D3DXVECTOR3(-80.0f, -10.0f, 500.0f));
	CTruck::Create(D3DXVECTOR3(40.0f, -10.0f, 2150.0f));
	CTruck::Create(D3DXVECTOR3(-80.0f, -10.0f, 2200.0f));
	CTruck::Create(D3DXVECTOR3(40.0f, -10.0f, 7150.0f));
	CTruck::Create(D3DXVECTOR3(-80.0f, -10.0f, 9200.0f));

	CTruck::Create(D3DXVECTOR3(-430.0f, -10.0f, 11200.0f));
	CTruck::Create(D3DXVECTOR3(-480.0f, -10.0f, 11550.0f));
	CTruck::Create(D3DXVECTOR3(-470.0f, -10.0f, 13500.0f));
	CTruck::Create(D3DXVECTOR3(-360.0f, -10.0f, 12000.0f));
	CEnemy::Create(D3DXVECTOR3(-410.0f, -10.0f, 15920.0f));
	CEnemy::Create(D3DXVECTOR3(-490.0f, -10.0f, 15120.0f));
	CEnemy::Create(D3DXVECTOR3(-350.0f, -10.0f, 16320.0f));
	CEnemy::Create(D3DXVECTOR3(-310.0f, -10.0f, 16250.0f));

	CEnemy::Create(D3DXVECTOR3(-430.0f, -10.0f, 19920.0f));
	CEnemy::Create(D3DXVECTOR3(-480.0f, -10.0f, 20120.0f));
	CEnemy::Create(D3DXVECTOR3(-370.0f, -10.0f, 20320.0f));
	CEnemy::Create(D3DXVECTOR3(-360.0f, -10.0f, 20250.0f));

	CTruck::Create(D3DXVECTOR3(430.0f, -10.0f, 15200.0f));
	CTruck::Create(D3DXVECTOR3(480.0f, -10.0f, 15550.0f));
	CTruck::Create(D3DXVECTOR3(470.0f, -10.0f, 16200.0f));
	CTruck::Create(D3DXVECTOR3(360.0f, -10.0f, 16000.0f));

	CEnemy::Create(D3DXVECTOR3(430.0f, -10.0f, 11200.0f));
	CEnemy::Create(D3DXVECTOR3(480.0f, -10.0f, 12000.0f));
	CEnemy::Create(D3DXVECTOR3(340.0f, -10.0f, 11300.0f));
	CEnemy::Create(D3DXVECTOR3(360.0f, -10.0f, 11400.0f));

	CTruck::Create(D3DXVECTOR3(460.0f, -10.0f, 19920.0f));
	CTruck::Create(D3DXVECTOR3(410.0f, -10.0f, 20520.0f));
	CTruck::Create(D3DXVECTOR3(370.0f, -10.0f, 21320.0f));

	CEnemy::Create(D3DXVECTOR3(0.0f, -10.0f, 22820.0f));

	CEnemy::Create(D3DXVECTOR3(-10.0f, -10.0f, 21370.0f));

	CTruck::Create(D3DXVECTOR3(40.0f, -10.0f, 20720.0f));
	CTruck::Create(D3DXVECTOR3(-40.0f, -10.0f, 22310.0f));
	CTruck::Create(D3DXVECTOR3(40.0f, -10.0f, 20450.0f));
	
	CEnemy::Create(D3DXVECTOR3(0.0f, -10.0f, 27820.0f));
	CEnemy::Create(D3DXVECTOR3(-10.0f, -10.0f, 27370.0f));
	CTruck::Create(D3DXVECTOR3(40.0f, -10.0f, 28720.0f));
	CTruck::Create(D3DXVECTOR3(-40.0f, -10.0f, 28310.0f));
	CTruck::Create(D3DXVECTOR3(40.0f, -10.0f, 27450.0f));

	CHelicopter::Create(D3DXVECTOR3(50.0f, 50.0f, 0.0f));
	CHelicopter::Create(D3DXVECTOR3(50.0f, 50.0f, 550.0f));
	CHelicopter::Create(D3DXVECTOR3(-50.0f, 50.0f, 950.0f));

	CHelicopter::Create(D3DXVECTOR3(50.0f, 50.0f, 2050.0f));
	CHelicopter::Create(D3DXVECTOR3(-50.0f, 50.0f, 1850.0f));

	CHelicopter::Create(D3DXVECTOR3(-430.0f, 50.0f, 2950.0f));
	CHelicopter::Create(D3DXVECTOR3(-380.0f, 50.0f, 2850.0f));
	CHelicopter::Create(D3DXVECTOR3(-400.0f, 50.0f, 4110.0f));
	CHelicopter::Create(D3DXVECTOR3(-380.0f, 50.0f, 4000.0f));
	CHelicopter::Create(D3DXVECTOR3(430.0f, 50.0f, 2950.0f));
	CHelicopter::Create(D3DXVECTOR3(380.0f, 50.0f, 2850.0f));
	CHelicopter::Create(D3DXVECTOR3(400.0f, 50.0f, 4110.0f));
	CHelicopter::Create(D3DXVECTOR3(380.0f, 50.0f, 4000.0f));
	

	CBoss::Create(D3DXVECTOR3(140.0f, -10.0f, 34160.0f));
	////CScore::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	////CWarp::Create(D3DXVECTOR3(-30.0f, -5.0f, 0.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 0.0f));//z=1350.0f
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 0.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 1350.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 1350.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 2700.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 2700.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 4050.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 4050.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 5400.0f));
	C3DBG::Create(D3DXVECTOR3(330.0f, -60.0f, 5400.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 5400.0f));
	C3DBG::Create(D3DXVECTOR3(-40.0f, -60.0f, 5170.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 6500.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 6500.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 7850.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 7850.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 9200.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 9200.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 10550.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 10550.0f));
	C3DBG::Create(D3DXVECTOR3(-810.0f, -60.0f, 11500.0f));
	C3DBG::Create(D3DXVECTOR3(-810.0f, -60.0f, 12850.0f));
	C3DBG::Create(D3DXVECTOR3(-810.0f, -60.0f, 13200.0f));
	C3DBG::Create(D3DXVECTOR3(-810.0f, -60.0f, 14550.0f));
	C3DBG::Create(D3DXVECTOR3(-810.0f, -60.0f, 15900.0f));
	C3DBG::Create(D3DXVECTOR3(-810.0f, -60.0f, 17250.0f));
	C3DBG::Create(D3DXVECTOR3(-810.0f, -60.0f, 18600.0f));
	C3DBG::Create(D3DXVECTOR3(0.0f, -60.0f, 11500.0f));
	C3DBG::Create(D3DXVECTOR3(0.0f, -60.0f, 12850.0f));
	C3DBG::Create(D3DXVECTOR3(0.0f, -60.0f, 13200.0f));
	C3DBG::Create(D3DXVECTOR3(0.0f, -60.0f, 14550.0f));
	C3DBG::Create(D3DXVECTOR3(0.0f, -60.0f, 15900.0f));
	C3DBG::Create(D3DXVECTOR3(0.0f, -60.0f, 17250.0f));
	C3DBG::Create(D3DXVECTOR3(0.0f, -60.0f, 18600.0f));
	C3DBG::Create(D3DXVECTOR3(0.0f, -60.0f, 19950.0f));
	C3DBG::Create(D3DXVECTOR3(0.0f, -60.0f, 21300.0f));
	C3DBG::Create(D3DXVECTOR3(810.0f, -60.0f, 11500.0f));
	C3DBG::Create(D3DXVECTOR3(810.0f, -60.0f, 12850.0f));
	C3DBG::Create(D3DXVECTOR3(810.0f, -60.0f, 13200.0f));
	C3DBG::Create(D3DXVECTOR3(810.0f, -60.0f, 14550.0f));
	C3DBG::Create(D3DXVECTOR3(810.0f, -60.0f, 15900.0f));
	C3DBG::Create(D3DXVECTOR3(810.0f, -60.0f, 17250.0f));
	C3DBG::Create(D3DXVECTOR3(810.0f, -60.0f, 18600.0f));


	C3DBG::Create(D3DXVECTOR3(-610.0f, -60.0f, 17250.0f));//ThinGround
	C3DBG::Create(D3DXVECTOR3(-610.0f, -60.0f, 18700.0f));
	C3DBG::Create(D3DXVECTOR3(-380.0f, -60.0f, 17250.0f));
	C3DBG::Create(D3DXVECTOR3(-380.0f, -60.0f, 18700.0f));
	C3DBG::Create(D3DXVECTOR3(-810.0f, -60.0f, 19950.0f));
	C3DBG::Create(D3DXVECTOR3(-810.0f, -60.0f, 21300.0f));
	C3DBG::Create(D3DXVECTOR3(-810.0f, -60.0f, 22650.0f));
	C3DBG::Create(D3DXVECTOR3(610.0f, -60.0f, 17250.0f));//ThinGround
	C3DBG::Create(D3DXVECTOR3(610.0f, -60.0f, 18700.0f));
	C3DBG::Create(D3DXVECTOR3(380.0f, -60.0f, 17250.0f));
	C3DBG::Create(D3DXVECTOR3(380.0f, -60.0f, 18700.0f));
	C3DBG::Create(D3DXVECTOR3(810.0f, -60.0f, 19950.0f));
	C3DBG::Create(D3DXVECTOR3(810.0f, -60.0f, 21300.0f));
	C3DBG::Create(D3DXVECTOR3(810.0f, -60.0f, 22650.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 22650.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 24000.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 25350.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 26700.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 22650.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 24000.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 25350.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 26700.0f));
	C3DBG::Create(D3DXVECTOR3(0.0f, -60.0f, 26600.0f));
	C3DBG::Create(D3DXVECTOR3(40.0f, -60.0f, 26600.0f));
	C3DBG::Create(D3DXVECTOR3(-40.0f, -60.0f, 26600.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 28050.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 29400.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 30750.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 32100.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 33450.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 34800.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 36150.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 37500.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 38850.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 40200.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 41550.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 42900.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 44250.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 45600.0f));
	C3DBG::Create(D3DXVECTOR3(-410.0f, -60.0f, 46950.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 28050.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 29400.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 30750.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 32100.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 33450.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 34800.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 36150.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 37500.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 38850.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 40200.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 41550.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 42900.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 44250.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 45600.0f));
	C3DBG::Create(D3DXVECTOR3(410.0f, -60.0f, 46950.0f));

	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 0.0f));//+860,1440=Jump
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 860.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 1720.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 2580.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 3440.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 4300.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 5160.0f));

	//CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 6000.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 6600.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 7460.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 8320.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 9180.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 10040.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 10900.0f));

	CGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 11200.0f));//���ʘH
	CGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 12060.0f));
	CGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 12920.0f));
	CGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 13780.0f));
	CGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 14640.0f));
	CGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 15500.0f));
	CGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 16360.0f));
	CGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 17220.0f));
	CThinGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 17950.0f));
	CThinGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 18580.0f));
	CThinGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 19210.0f));
	CGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 19920.0f));
	CGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 20780.0f));
	CGround::Create(D3DXVECTOR3(-400.0f, -10.0f, 21640.0f));

	CGround::Create(D3DXVECTOR3(400.0f, -10.0f, 11200.0f));//�E�ʘH
	CGround::Create(D3DXVECTOR3(400.0f, -10.0f, 12060.0f));
	CGround::Create(D3DXVECTOR3(400.0f, -10.0f, 12920.0f));
	CGround::Create(D3DXVECTOR3(400.0f, -10.0f, 13780.0f));
	CGround::Create(D3DXVECTOR3(400.0f, -10.0f, 14640.0f));
	CGround::Create(D3DXVECTOR3(400.0f, -10.0f, 15500.0f));
	CGround::Create(D3DXVECTOR3(400.0f, -10.0f, 16360.0f));
	CGround::Create(D3DXVECTOR3(400.0f, -10.0f, 17220.0f));
	CThinGround::Create(D3DXVECTOR3(400.0f, -10.0f, 17950.0f));//730.0f
	CThinGround::Create(D3DXVECTOR3(400.0f, -10.0f, 18580.0f));//630.0f
	CThinGround::Create(D3DXVECTOR3(400.0f, -10.0f, 19210.0f));
	CGround::Create(D3DXVECTOR3(400.0f, -10.0f, 19920.0f));
	CGround::Create(D3DXVECTOR3(400.0f, -10.0f, 20780.0f));
	CGround::Create(D3DXVECTOR3(400.0f, -10.0f, 21640.0f));

	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 22040.0f));//�^�񒆒ʘH
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 22900.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 23760.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 24620.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 25480.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 26920.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 27780.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 28640.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 29500.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 30360.0f));
	CThinGround::Create(D3DXVECTOR3(0.0f, -10.0f, 31090.0f));
	CThinGround::Create(D3DXVECTOR3(0.0f, -10.0f, 31720.0f));
	CThinGround::Create(D3DXVECTOR3(0.0f, -10.0f, 32350.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 33060.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 33920.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 34780.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 35640.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 36500.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 37360.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 38220.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 39080.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 39940.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 40800.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 41660.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 42520.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 43380.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 44240.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 45100.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 45960.0f));

	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 47400.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 48260.0f));
	CGround::Create(D3DXVECTOR3(0.0f, -10.0f, 49120.0f));

	CGoal::Create(D3DXVECTOR3(0.0f, -10.0f, 49120.0f));
	//CBullet::Load();//�ǂݍ���(�j����CManager::Uninit��)
	//�T�E���h�̍Đ�
	CSound* pSound = CManager::GetSound();//�T�E���h�̎擾
	pSound->PlaySound(CSound::SOUND_LABEL::SOUND_BGM_ROCK001);


	return S_OK;

}

//===================================
// 
//�Q�[����ʂւ̑J�ڂ̏I������
// 
//===================================
void CGame::Uninit()
{
	//�T�E���h�̒�~
	CSound* pSound = CManager::GetSound();//�T�E���h�̎擾
	pSound->StopSound();
	if (m_pBlock_Manager != nullptr)
	{
		m_pBlock_Manager->Uninit();
		delete m_pBlock_Manager;
		m_pBlock_Manager = nullptr;
	}
	/*if (m_pScore_Manager != nullptr)
	{
		m_pScore_Manager->Uninit();
		delete m_pScore_Manager;
		m_pScore_Manager = nullptr;
	}*/
	//CBlock::Unload();
	//CEnemy::Unload();
	//CBullet::Unload();

	CScene::Uninit();

}

//===================================
// 
//�Q�[����ʂւ̑J�ڂ̍X�V����
// 
//===================================
void CGame::Update()
{
	CObject::UpdateAll();


	//CObject::Release();

	/*for (int nCntPriority = 0; nCntPriority < CObject::m_nMAX_PRIORITY; nCntPriority++)
	{
		for (int nCntObj = 0; nCntObj < MAX_DATA; nCntObj++)
		{*/
			//�I�u�W�F�N�g�擾
			CObject* pObj = CObject::GetMyObject();
			//�ő吔���s���Ȃ̂�While���g�p
			while (pObj != nullptr)
			{
				// ���̃|�C���^��ۑ����Ă���
				CObject* pNext = pObj->GetNext();
				if (pObj != nullptr)
				{
					CObject::TYPE type = pObj->GetType();

					if (type == CObject::PLAYER)
					{

						CPlayer* pPlayer = (CPlayer*)pObj;
						D3DXVECTOR3 PlayerPos = pPlayer->GetPos();//�ʒu�̎擾
						int PlayerLife = pPlayer->GetLife();//���C�t�̎擾
						int PlayerGoal = pPlayer->GetGoalHit();//�S�[���q�b�g�̎擾
						if (pPlayer->GetLife() <= 0)
						{
							SetEnd(0);

							//���[�h�ݒ�
							CManager::SetMode(CScene::MODE_RESULT);
						}
						else if (PlayerPos.y <= -30.0f)
						{
							SetEnd(1);

							//���[�h�ݒ�
							CManager::SetMode(CScene::MODE_RESULT);
						}
						else if (PlayerPos.z >= 49120.0f)
						{
							SetEnd(2);

							//���[�h�ݒ�
							CManager::SetMode(CScene::MODE_RESULT);
						}
					}
					if (type == CObject::ENEMY)
					{
						CEnemy* pEnemy = (CEnemy*)pObj;
						D3DXVECTOR3 EnemyPos = pEnemy->GetPos();//�ʒu�̎擾
						int EnemyLife = pEnemy->GetLife();//���C�t�̎擾
						if (pEnemy->GetLife() <= 0)
						{
							//CScore::AddScore(SCORE_ADD);
							pEnemy->Uninit();//�G�̏I������

						}
						//break;
					}
					if (type == CObject::HELICOPTER)
					{
						CHelicopter* pHelicopter = (CHelicopter*)pObj;
						D3DXVECTOR3 HelicopterPos = pHelicopter->GetPos();//�ʒu�̎擾
						int HelicopterLife = pHelicopter->GetLife();//���C�t�̎擾
						if (pHelicopter->GetLife() <= 0)
						{
							pHelicopter->Uninit();//�w���R�v�^�[�̏I������

						}
						//break;
					}
					if (type == CObject::TRUCK)
					{
						CTruck* pTruck = (CTruck*)pObj;
						D3DXVECTOR3 TruckPos = pTruck->GetPos();//�ʒu�̎擾
						int TruckLife = pTruck->GetLife();//���C�t�̎擾
						if (pTruck->GetLife() <= 0)
						{
							pTruck->Uninit();//�g���b�N�̏I������

						}
						//break;
					}

				}
				// �|�C���^�����̃|�C���^�֕ύX
				pObj = pNext;
			}
		//}
	//}
	
	//if (CManager::GetKeyboard()->GetTrigger(DIK_RETURN) == true || CManager::GetGamePad()->GetTrigger(7) == true)
	//{//����L�[(ENTER�L�[)�������ꂽ
	//	//���[�h�ݒ�
	//	CManager::GetFade()->SetFade(CScene::MODE_TITLE);

	//}

}

//===================================
// 
//�Q�[����ʂւ̑J�ڂ̕`�揈��
// 
//===================================
void CGame::Draw()
{
	CObject::DrawAll();
}
//===================================
// 
//�Q�[����ʂւ̑J�ڂ̐�������
//
//===================================
CGame* CGame::Create()
{
	CGame* pGame = new CGame();
	pGame->Init();
	return pGame;
}
