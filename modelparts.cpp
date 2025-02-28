////=============================================================================
////
//// ���f���p�[�c���� [modelparts.cpp]
//// Author :: Koki_Nishide
////
////=============================================================================
//#include "main.h"
//#include "player.h"
//#include "input.h"
//#include "manager.h"
//#include "modelparts.h"
//#include "object3D.h"
//
//
////�R���X�g���N�^
//CModelParts::CModelParts()
//{
//	m_MotionPos = D3DXVECTOR3(0.0f,0.0f,0.0f);
//	m_MotionRot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//}
////�f�X�X�g���N�^
//CModelParts::~CModelParts()
//{
//
//}
//
//
////�����ݒ�
//HRESULT CModelParts::Init()
//{
//	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
//	//�f�o�C�X�̎擾
//	pDevice = CManager::GetRenderer()->GetDevice();
//
//	//X�t�@�C���̓ǂݍ���
//	//D3DXLoadMeshFromX("data\\MODEL\\00_body.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMatModelParts, NULL, &m_dwNumMatModelParts, &m_pMeshModelParts);
//	
//
//	//CObject::SetType(PLAYER);
//	return S_OK;
//}
//
////���f���p�[�c�̏I������
//void CModelParts::Uninit()
//{
//	CObject::Uninit();//this->Release();���g�̊J��
//}
//
////���f���p�[�c�̍X�V����
//void CModelParts::Update()
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
//void CModelParts::Draw()
//{
//	CObject::Draw();//�|���S���`��
//}
//void CModelParts::SetMotionPos(D3DXVECTOR3 pos)
//{
//	m_MotionPos = pos;
//
//}
//void CModelParts::SetMotionRot(D3DXVECTOR3 rot)
//{
//	m_MotionRot = rot;
//}
//
//CModelParts* CModelParts::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, LPD3DXMESH pMesh, LPD3DXBUFFER pBuffMat, DWORD dwNumMat)
//{
//	CModelParts* pModelParts = nullptr;
//	pModelParts = new CModelParts();
//	if (FAILED(pModelParts->Init())) {
//		pModelParts->Uninit();
//		return nullptr;
//	}
//	pModelParts->SetPos( pos);
//	pModelParts->SetRot( rot);
//	return pModelParts;
//}
