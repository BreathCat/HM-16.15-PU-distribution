#ifndef _DEF_H
#define _DEF_H

extern int intra_pre_mode_index;//�Լ�����ģ��ڼ�֡��
extern long intra_pre_mode[100][35] ;//�Լ������֡��Ԥ��ģʽ��ͳ������
extern long I_PU_number[100][5];//�Լ������֡��PU����ͳ�� 4*4------------0;8*8------------1;16*16------------2;32*32------------3;64*64------------4;
extern long P_PU_number[100][25];//�Լ������֡��PU����ͳ�� 
extern long I_CU_number[100][4];//�Լ������I֡CU����ͳ��8*8------------0;16*16------------1;32*32------------2;64*64------------3;
extern long P_CU_number[100][4];//�Լ������P֡CU����ͳ��8*8------------0;16*16------------1;32*32------------2;64*64------------3;
extern long intra[100];//intra ��PU��Ŀ
extern long inter[100];//inter ��PU��Ŀ
extern long skip[100];//skip ��PU��Ŀ
#endif