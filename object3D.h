//=============================================================================
//
// �I�u�W�F�N�g3D���� [object3D.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _OBJECT3D_H_//���̃}�N����`������ĂȂ�������
#define _OBJECT3D_H_//2�d�C���N���[�h�h�~�̃}�N����`

#include"object.h"

//3D�|���S���Ǘ��N���X
class CObject3D :public CObject
{
public:
	//�q�b�g���
	typedef enum
	{
		STATE_APPER = 0, //�o����ԁi�_�Łj
		STATE_NORMAL, //�ʏ��� 
		STATE_DAMAGE, //�_���[�W���
		STATE_DEATH, //���S���
		STATE_MAX

	}STATE;
	CObject3D();
	virtual ~CObject3D()override;//object.h��virtual���Ȃ���΁Aoverride�������B
	virtual HRESULT Init()override;
	virtual void Uninit()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Hit(int nDamage);
	virtual void HitGoal(int nHit);
	virtual void HitWarp(int nHitWarp);
	void BindMesh(DWORD dwNumMatModel, LPD3DXBUFFER pBuff, LPD3DXMESH pMesh, LPDIRECT3DTEXTURE9* pTexture);//�e�N�X�`������
	void BindModel(DWORD dwNumMatModel, LPD3DXBUFFER pBuff, LPD3DXMESH pMesh, LPDIRECT3DTEXTURE9 pTexture);//���f������

	void SetPos(D3DXVECTOR3 pos); //�ʒu��ݒ�
	void SetPosOld(D3DXVECTOR3 posold); //�Â��ʒu��ݒ�
	void SetMove(D3DXVECTOR3 move); //������ݒ�
	void SetRot(D3DXVECTOR3 rot); //������ݒ�
	void SetTargetPos(D3DXVECTOR3 TargetPos); //�^�[�Q�b�g�̈ʒu��ݒ�
	void SetIsLanding(bool bIsLanding); //���n��ݒ�
	void SetDushAttack(bool bDushAttack);//�_�b�V���A�^�b�N��ݒ�
	void SetCol(D3DXCOLOR col); //�J���[��ݒ�
	void SetLife(int nLife);//���C�t��ݒ�
	void SetGoalHit(int nGoal);//�S�[���̃q�b�g������ݒ�
	void SetVtxBuff(LPDIRECT3DVERTEXBUFFER9 pVtxBuff);//���_�o�b�t�@��ݒ�
	void SetMesh(LPD3DXMESH pMeshModel);//���b�V����ݒ�
	void SetBuffer(LPD3DXBUFFER pBuffMatModel);//�}�e���A���ւ̃|�C���^��ݒ�
	void SetMatModel(DWORD dwNumMatModel);//�}�e���A���̐���ݒ�
	void SetWorldModel(D3DXMATRIX mtxWorldModel); //���[���h�}�g���b�N�X��ݒ�
	static CObject3D* Create(D3DXVECTOR3);//Object3D����
	virtual HRESULT Load();//���[�h����
	void Unload();//�A�����[�h����
	int GetLife() { return m_nLife; }//���C�t�擾�ȂǗp��
	int GetGoalHit() { return m_nGoal; }//�S�[���擾�ȂǗp��
	D3DXVECTOR3 GetPos() { return m_pos; }//�ʒu�擾�ȂǗp��
	D3DXVECTOR3 GetPosOld() { return m_PosOld; }//�Â��ʒu�擾�ȂǗp��
	D3DXVECTOR3 GetMove() { return m_move; }//�����擾�ȂǗp��
	D3DXVECTOR3 GetRot() { return m_rot; }//�����擾�ȂǗp��
	D3DXVECTOR3 GetTargetPos() { return m_TargetPos; }//�^�[�Q�b�g�̈ʒu�̎擾��p��
	bool GetDushAttack() { return m_DushAttack; } //�_�b�V���A�^�b�N��p��
	//LPDIRECT3DVERTEXBUFFER9 GetVtxBuff() { return m_pVtxBuff; }//���_�o�b�t�@�擾�ȂǗp��
	LPD3DXMESH GetMesh(){  return m_pMeshModel; }//���b�V���擾�ȂǗp��
	LPD3DXBUFFER GetBuffer() { return m_pBuffMatModel; }//�}�e���A���ւ̃|�C���^�̎擾�ȂǗp��
	DWORD GetMatModel() { return m_dwNumMatModel; }//�}�e���A���̐��̎擾�ȂǗp��
	D3DXMATRIX GetWorldModel() { return m_mtxWorldModel; }//���[���h�}�g���b�N�X�̎擾�ȂǗp��
	void SetPosX(float x);
	void SetPosY(float y);
	void SetSizeW(float w);
	void SetSizeH(float h);
private:
	

protected:
	/*static CObject2D* m_pObject2D;*/
	LPD3DXMESH m_pMeshModel; //���b�V���i���_���j�ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMatModel; //�}�e���A���ւ̃|�C���^
	DWORD m_dwNumMatModel; //�}�e���A���̐�
	D3DXMATRIX m_mtxWorldModel; //���[���h�}�g���b�N�X
	LPDIRECT3DTEXTURE9* m_pTexture;//�e�N�X�`���ւ̃|�C���^
	STATE m_state; //���
	static int m_nCounterState; //��ԊǗ��J�E���^�[
	//int m_nType; //���
	int m_nLife; //�̗�
	int m_nGoal;//�S�[��
	int m_nModelIdx;//���f���̃C���f�b�N�X
	static int nNumObject3D;
	static bool m_bDisp; //�\�����邩���Ȃ���
	D3DXVECTOR3 m_nNumObject3D; //����
	D3DXVECTOR3 m_pos; //���݂̈ʒu
	D3DXVECTOR3 m_PosOld; //�O��̈ʒu
	D3DXVECTOR3 m_move; //���݂̈ʒu
	D3DXVECTOR3 m_rot; // ����
	D3DXVECTOR3 m_TargetPos;//�^�[�Q�b�g�̈ʒu
	bool m_DushAttack;//�_�b�V���A�^�b�N
	bool IsLanding; //���n�̈ʒu
	D3DXCOLOR m_col;//�J���[
	D3DXMATRIX m_mtxWorld; //���[���h�ϊ��s��
	//static LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;//���_�o�b�t�@
	//float m_posX;	// �ʒu��X���W
	//float m_posY;	// �ʒu��Y���W
	float m_sizeW;	// ��
	float m_sizeH;	// ����
};


#endif //_OBJECT3D_H_