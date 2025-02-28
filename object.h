//=============================================================================
//
// �I�u�W�F�N�g���� [object.h]
// Author :: Koki_Nishide
//
//=============================================================================
#ifndef _OBJECT_H_//���̃}�N����`������ĂȂ�������
#define	_OBJECT_H_//2�d�C���N���[�h�h�~�̃}�N����`
#include <d3dx9.h>

//�}�N����`
#define MAX_DATA (256)//������f�[�^��
#define DEFAULT_PRIORITY (5)
//#define MAX_PRIORITY (5)//�D�悳���f�[�^��

//�S�I�u�W�F�N�g���N���X
class CObject
{
public:
	typedef enum
	{
		NONE = 0,//����
		ENEMY,//�G
		PLAYER,//�v���C���[
		BLOCK,//�u���b�N
		FADE, //�t�F�[�h
		SCENE,//�V�[��
		CAMERA,//�J����
		BG,//�w�i(3D)
		GOAL,//�S�[��
		GROUND,//�O���E���h
		WARP,//���[�v
		THINGROUND,//�ׂ�����
		GAUGE,//�Q�[�W
		HELICOPTER,//�w���R�v�^�[
		TRUCK,//�g���b�N
		HP,//HP����
		SCORE,//�X�R�A
		PARTICLE,//�p�[�e�B�N��
		JUMP_MESSAGE,//�W�����v���b�Z�[�W
		LEFT_MESSAGE,//���̃��b�Z�[�W
		RIGHT_MESSAGE,//�E�̃��b�Z�[�W
		MIDDLE_MESSAGE,//�^�񒆒ʘH�̃��b�Z�[�W
		BOSS_MESSAGE,//�{�X�̃��b�Z�[�W
		BOSS,//�{�X
		SKY,//��̔w�i
		MAX,
	}TYPE;
	static const int m_nMAX_PRIORITY = TYPE::MAX;
	CObject(int nPriority = 0);
	virtual ~CObject();
	virtual HRESULT Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	static void ReleaseAll();//�S�I�u�W�F�N�g�J��
	static void UpdateAll();//�S�I�u�W�F�N�g�X�V
	static void DrawAll();//�S�I�u�W�F�N�g�`��
	//static CObject* GetObject();
	static CObject* GetMyObject();
	TYPE GetType(); //�^�C�v�擾
	CObject* GetNext();
	void SetType(TYPE type);//�^�C�v�ݒ�
	void SetUseRelease(bool bUse) {m_bUseRelease = bUse;}
protected:
	void Release();//�������g�̊J��
	bool m_bDeath;
private:
	//static CObject* m_apObject;//�I�u�W�F�N�g�Ǘ�
	//static CObject* m_apMyObject[1];//�I�u�W�F�N�g���X�g
	static CObject* m_apMyObject[m_nMAX_PRIORITY][MAX_DATA];//�I�u�W�F�N�g�Ǘ�(�v���C�I���e�B)
	TYPE m_type; //�I�u�W�F�N�g�^�C�v
	static int m_nNumAll;//�I�u�W�F�N�g����
	int m_nPriority;//�`��D��x
	int m_nID;//�������g��ID
	bool m_bUseRelease;

	//�I�u�W�F�N�g�Ǘ�
	static CObject* m_pTop;//�擪�̃I�u�W�F�N�g�̃|�C���^
	static CObject* m_pCur;//���݁i�Ō���j�̃|�C���^
	CObject* m_pPrev;//�O�̃I�u�W�F�N�g�̃|�C���^
	CObject* m_pNext;//���̃I�u�W�F�N�g�̃|�C���^
};

#endif //_OBJECT_H_
