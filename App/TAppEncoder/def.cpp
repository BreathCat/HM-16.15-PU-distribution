#include "def.h"
//�κα���������def.cpp��decoder��def.h�ﶨ��Ų�����
int intra_pre_mode_index=0;//�Լ�����ģ��ڼ�֡��
long intra_pre_mode[100][35]={0} ;//�Լ������֡��Ԥ��ģʽ��ͳ������
long I_PU_number[610][5]={0};//�Լ������I֡PU����ͳ��  4*4------------0;8*8------------1;16*16------------2;32*32------------3;64*64------------4;
long P_PU_number[610][25]={0};//�Լ������P֡PU����ͳ��
long I_CU_number[100][4]={0};//�Լ������I֡CU����ͳ��
long P_CU_number[100][4]={0};//�Լ������P֡CU����ͳ��
 long intra[100]={0};//intra ��PU��Ŀ
 long inter[100]={0};//inter ��PU��Ŀ
 long skip[100]={0};//skip ��PU��Ŀ
 char MessStr[100] = {0};//ԭʼ������Ϣ
int ThNum[200] = {0};//��������
int m = 1;//�������������±�
int TotalNum = 5; //���鳤��
int FrameHeight ;
int FrameWidth ;