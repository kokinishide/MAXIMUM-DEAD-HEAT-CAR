////=============================================================================
////
//// �I�u�W�F�N�gX���� [objectX.cpp]
//// Author :: Koki_Nishide
////
////=============================================================================
//#include "main.h"
//#include "player.h"
//#include "input.h"
//#include "manager.h"
//#include "object3D.h"
//#include "objectX.h"
//
//
//
////�R���X�g���N�^
//CObjectX::CObjectX()
//{
//	 m_pVtxBuff = nullptr;//���_�o�b�t�@
//	 m_pMesh = nullptr; //���b�V���i���_���j�ւ̃|�C���^
//	 m_pBuffMat = nullptr; //�}�e���A���ւ̃|�C���^
//	 m_dwNumMat = 0; //�}�e���A���̐�
//	 for (int nCnt = 0; nCnt < MAX_MOTION_TEXTURE; nCnt++)
//	 {
//		 m_pTexture[nCnt] = nullptr;
//		 
//	 }
//	 m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//	 m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//}
////�f�X�X�g���N�^
//CObjectX::~CObjectX()
//{
//
//}
//
//
////�����ݒ�
//HRESULT CObjectX::Init()
//{
//	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
//	//�f�o�C�X�̎擾
//	pDevice = CManager::GetRenderer()->GetDevice();
//
//	return S_OK;
//}
//
////���f���p�[�c�̏I������
//void CObjectX::Uninit()
//{
//	//���b�V���̔j��
//	if (m_pMesh != nullptr)
//	{
//		m_pMesh->Release();
//		m_pMesh = nullptr;
//
//	}
//	//�}�e���A���̔j��
//	if (m_pBuffMat != nullptr)
//	{
//		m_pBuffMat->Release();
//		m_pBuffMat = nullptr;
//	}
//	for (int nCnt = 0; nCnt < MAX_MOTION_TEXTURE; nCnt++)
//	{
//		//�e�N�X�`���̊J��
//		if (m_pTexture[nCnt] != nullptr)
//		{
//			delete m_pTexture[nCnt];
//			m_pTexture[nCnt] = nullptr;
//		}
//	}
//	CObject::Release();
//}
//
////���f���p�[�c�̍X�V����
//void CObjectX::Update()
//{
//	//LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
//	////�f�o�C�X�̎擾
//	//pDevice = CManager::GetRenderer()->GetDevice();
//	////�e�̍s����擾����
//	//D3DXMATRIX mtxParent;
//	//if (m_pParent != nullptr)
//	//{
//	//	//�e�̃��[���h�ϊ��s����擾
//	//	mtxParent = m_pParent->GetWorldMatrix();
//	//}
//	//else
//	//{
//	//	//�ŐV�̃��[���h�ϊ��s����擾(=�v���C���[�̍s��)
//	//	pDevice->GetTransform(D3DTS_WORLD, &mtxParent);
//	//}
//}
//
////���f���p�[�c�̕`�揈��
//void CObjectX::Draw()
//{
//	CObject::Draw();//�|���S���`��
//}
//void CObjectX::SetPos(D3DXVECTOR3 pos)
//{
//	m_pos = pos;
//	
//}
//void CObjectX::SetRot(D3DXVECTOR3 rot)
//{
//	m_rot = rot;
//}
//
//CObjectX* CObjectX::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, LPD3DXMESH pMesh, LPD3DXBUFFER pBuffMat, DWORD dwNumMat)
//{
//	CObjectX* pObjectX = nullptr;
//	pObjectX = new CObjectX();
//	if (FAILED(pObjectX->Init())) {
//		pObjectX->Uninit();
//		return nullptr;
//	}
//	pObjectX->SetPos(pos);
//	pObjectX->SetRot(rot);
//	return pObjectX;
//}
