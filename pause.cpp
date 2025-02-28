////================================
////
//// �|�[�Y��ʑJ�ڏ��� [pause.cpp]
//// Author Koki_Nishide
////
////================================
//#include "input.h"
//#include "pause.h"
//#include "main.h"
//#include "player.h"
//#include "game.h"
//
////�}�N����`
//#define NUM_PAUSE	(4) //�|�[�Y�p���i�̐�
//typedef enum
//{
//	PAUSETYPE_TITLE = 0,
//	PAUSETYPE_CONTINUE,
//	PAUSETYPE_RETRY,
//	PAUSETYPE_GOTITLE,
//	PAUSETYPE_MAX
//}PAUSETYPE;
//
////�O���[�o���ϐ�
//CPause::PAUSE_MENU m_PauseMenu; //�|�[�Y���j���[�̏��
//
////================
////�|�[�Y�̏���������
////================
//void InitPause(void)
//{
//	LPDIRECT3DDEVICE9 pDevice;
//	int nCntPause;
//	m_nPause = PAUSETYPE_CONTINUE;
//
//	VERTEX_2D* pVtx;//���_���ւ̃|�C���^
//
//	//�f�o�C�X�̎擾
//	pDevice = GetDevice();
//	//�e�N�X�`���̓ǂݍ���
//	//D3DXCreateTextureFromFile(pDevice, "data\\cloudpilot001.png", &g_apTextureBG[0]);
//	//D3DXCreateTextureFromFile(pDevice, "data\\cloudpilot001.png", &g_apTextureBG[1]);
//	//D3DXCreateTextureFromFile(pDevice, "data\\cloudpilot001.png", &g_apTextureBG[2]);
//
//	//�e�N�X�`�����W�̊J�n�ʒu(V�l)�̏�����
//	/*for (nCnt = 0; nCntBG < NUM_BG; nCntBG++)
//	{
//		g_aPosTexV[nCntBG] = 0.0f;
//
//	}*/
//
//	//���_�o�b�t�@�̐���
//	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * NUM_PAUSE,
//		D3DUSAGE_WRITEONLY,
//		FVF_VERTEX_2D,
//		D3DPOOL_MANAGED,
//		&g_pVtxBuffPause,
//		NULL);
//
//
//	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
//	g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);
//
//	for (nCntPause = 0; nCntPause < NUM_PAUSE; nCntPause++)
//	{
//		//���_���W�̐ݒ�
//		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//		pVtx[1].pos = D3DXVECTOR3(1300.0f, 0.0f, 0.0f);
//		pVtx[2].pos = D3DXVECTOR3(0.0f, 800.0f, 0.0f);
//		pVtx[3].pos = D3DXVECTOR3(1300.0f, 800.0f, 0.0f);
//
//		//���_�J���[�̐ݒ�
//		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//
//		//�e�N�X�`�����W�̐ݒ�
//		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
//		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
//		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
//		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
//
//		pVtx += 4; //���_�f�[�^�̃|�C���^��4���i�߂�
//	}
//	//���_�o�b�t�@���A�����b�N����
//	g_pVtxBuffPause->Unlock();
//}
////==================
////�w�i�̏I������
////==================
//void UninitPause(void)
//{
//	//�e�N�X�`���̔j��	
//	for (int nCnt = 0; nCnt < NUM_PAUSE; nCnt++)
//	{
//		if (g_apTexturePause[nCnt] != NULL)
//		{
//			g_apTexturePause[nCnt]->Release();
//			g_apTexturePause[nCnt] = NULL;
//		}
//
//		//���_�o�b�t�@�̔j��
//		if (g_pVtxBuffPause != NULL)
//		{
//			g_pVtxBuffPause->Release();
//			g_pVtxBuffPause = NULL;
//		}
//	}
//}
////==================
////�|�[�Y�̍X�V����
////==================
//void UpdatePause(void)
//{
//	
//	VERTEX_2D* pVtx; //���_���ւ̃|�C���^
//
//	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
//	g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);
//
//
//	if (GetKeyboardTrigger(DIK_DOWNARROW) == true)
//	{
//		m_nPause++;
//
//		if (m_nPause == PAUSETYPE_MAX)
//		{
//			m_nPause = PAUSETYPE_CONTINUE;
//		}
//	}
//	if (GetKeyboardTrigger(DIK_UPARROW) == true)
//	{
//		m_nPause--;
//
//		if (m_nPause == PAUSETYPE_CONTINUE - 1)
//		{
//			m_nPause = PAUSETYPE_GOTITLE;
//		}
//	}
//
//	for (nCntPause = 0; nCntPause < NUM_PAUSE; nCntPause++)
//	{
//		//���_�J���[�̐ݒ�
//		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		if (nCntPause == m_nPause)
//		{
//			switch (m_nPause)
//			{
//			case 1:
//				pVtx[0].col = D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f);
//				pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
//				pVtx[2].col = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
//				pVtx[3].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
//				break;
//			case 2:
//				pVtx[0].col = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
//				pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
//				pVtx[2].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
//				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
//				break;
//			case 3:
//				pVtx[0].col = D3DXCOLOR(0.0f, 1.0f, 0.5f, 1.0f);
//				pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
//				pVtx[2].col = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
//				pVtx[3].col = D3DXCOLOR(0.0f, 0.0f, 0.5f, 1.0f);
//				break;
//			}
//		}
//		pVtx += 4;
//	}
//	if (GetKeyboardTrigger(DIK_RETURN) == true)
//	{//����L�[(ENTER�L�[)�������ꂽ
//		switch (m_nPause)
//		{
//		case PAUSETYPE_CONTINUE:
//			SetEnablePause(false);
//			break;
//		case PAUSETYPE_RETRY:
//			Set(MODE_GAME);
//			break;
//		case PAUSETYPE_GOTITLE:
//			Set(MODE_TITLE);
//			break;
//		default:
//			break;
//		}
//	}
//	//���_�o�b�t�@���A�����b�N����
//	g_pVtxBuffPause->Unlock();
//}
////==================
////�|�[�Y�̕`�揈��
////==================
//void DrawPause(void)
//{
//	LPDIRECT3DDEVICE9 pDevice;
//	int nCntPause;
//
//	//�f�o�C�X�̎擾
//	pDevice = GetDevice();
//
//	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
//	pDevice->SetStreamSource(0, g_pVtxBuffPause, 0, sizeof(VERTEX_2D));
//	//���_�t�H�[�}�b�g�̐ݒ�
//	pDevice->SetFVF(FVF_VERTEX_2D);
//
//
//	//�e�N�X�`���̐ݒ�
//	for (nCntPause = 0; nCntPause < NUM_PAUSE; nCntPause++)
//	{
//		pDevice->SetTexture(0, g_apTexturePause[nCntPause]);
//
//		//�|���S���̕`��
//		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntPause * 4, 2);
//	}
//}