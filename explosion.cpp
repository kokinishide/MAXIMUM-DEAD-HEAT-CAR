////=============================================================================
////
//// �������� [explosion.cpp]
//// Author :: Koki_Nishide
////
////=============================================================================
//#include "main.h"
//#include "player.h"
//#include "input.h"
//#include "explosion.h"
//#include "manager.h"
//#include "object2D.h"
//
////===================================
//// 
////�}�N����`
////
////===================================
//#define MAX_EXPLOSION (128) //�����̍ő吔
////#define NUM_EXPLOSION (2) //�����̎��
//
////===================================
//// 
////�����̏���������
////
////===================================
//HRESULT CExplosion::Init(void)
//{
//	CObject2D::SetSizeW(40.0f);
//	CObject2D::SetSizeH(40.0f);
//	CObject2D::Init();
//	
//	return S_OK;
//}
////===================================
//// 
////�����̏I������
////
////===================================
//void CExplosion::Uninit()
//{
//	CObject2D::Uninit();
//	
//}
////===================================
//// 
////�����̍X�V����
////
////===================================
//void CExplosion::Update()
//{
//
//	CObject2D::Update();//���_���X�V
//}
////===================================
//// 
////�����̕`�揈��
////
////===================================
//void CExplosion::Draw()
//{
//	CObject2D::Draw();
//}
////===================================
//// 
////CExplosion����
////
////===================================
//CExplosion* CExplosion::Create(D3DXVECTOR3 m_pos, D3DXCOLOR m_col)
//{
//	LPDIRECT3DDEVICE9 pDevice;
//	//�f�o�C�X�̎擾
//	pDevice = CManager::GetRenderer()->GetDevice();
//	CExplosion* pExplosion = new CExplosion();
//	pExplosion->Init();
//	pExplosion->SetPos(m_pos);//�����ʒu�ݒ�
//	LPDIRECT3DTEXTURE9 pTex;
//
//	//�e�N�X�`���̐ݒ�
//	D3DXCreateTextureFromFile(pDevice,
//		"data\\explosion000.png",
//		&pTex);
//	pExplosion->BindTexture(pTex);
//	return pExplosion;
//}
