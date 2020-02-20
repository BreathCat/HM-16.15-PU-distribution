#include "def.h"
//任何变量在两个def.cpp和decoder的def.h里定义才不报错
int intra_pre_mode_index=0;//自己定义的：第几帧数
long intra_pre_mode[100][35]={0} ;//自己定义的帧内预测模式的统计数组
long I_PU_number[610][5]={0};//自己定义的I帧PU划分统计  4*4------------0;8*8------------1;16*16------------2;32*32------------3;64*64------------4;
long P_PU_number[610][25]={0};//自己定义的P帧PU划分统计
long I_CU_number[100][4]={0};//自己定义的I帧CU划分统计
long P_CU_number[100][4]={0};//自己定义的P帧CU划分统计
 long intra[100]={0};//intra 的PU数目
 long inter[100]={0};//inter 的PU数目
 long skip[100]={0};//skip 的PU数目
 char MessStr[100] = {0};//原始隐秘信息
int ThNum[200] = {0};//三进制数
int m = 1;//三进制数数组下标
int TotalNum = 5; //数组长度
int FrameHeight ;
int FrameWidth ;