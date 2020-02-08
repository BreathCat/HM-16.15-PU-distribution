﻿/* The copyright in this software is being made available under the BSD
 * License, included below. This software may be subject to other third party
 * and contributor rights, including patent rights, and no such rights are
 * granted under this license.
 *
 * Copyright (c) 2010-2017, ITU/ISO/IEC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * Neither the name of the ITU/ISO/IEC nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/** \file     decmain.cpp
    \brief    Decoder application main
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "TAppDecTop.h"
#include "def.h"
#include<vector>
#include<algorithm>
//自定义全局变量
 using namespace std;

int CurrentPOC = 0;
int InterPU = 0;
int IntraPU = 0;
int SkipPU = 0;

//! \ingroup TAppDecoder
//! \{

// ====================================================================================================================
// Main function
// ====================================================================================================================

int main(int argc, char* argv[])
{
  Int returnCode = EXIT_SUCCESS;
  TAppDecTop  cTAppDecTop;

  // print information
  fprintf( stdout, "\n" );
  fprintf( stdout, "HM software: Decoder Version [%s] (including RExt)", NV_VERSION );
  fprintf( stdout, NVM_ONOS );
  fprintf( stdout, NVM_COMPILEDBY );
  fprintf( stdout, NVM_BITS );
  fprintf( stdout, "\n" );

  // create application decoder class
  cTAppDecTop.create();

  // parse configuration
  if(!cTAppDecTop.parseCfg( argc, argv ))
  {
    cTAppDecTop.destroy();
    returnCode = EXIT_FAILURE;
    return returnCode;
  }

  // starting time
  Double dResult;
  clock_t lBefore = clock();

  ////////////////////////////
  string matchPath=cTAppDecTop.m_bitstreamFileName;
  

  string matchpath1="txt_file/I_PUNum/";
  matchpath1.append(matchPath);
  matchpath1.append("_I_PUNum.txt");
  const char* MatchPath1 = matchpath1.data();
  ofstream ofa(MatchPath1);

  string matchpath2="txt_file/P_PUNum/";    //C:/Users/45452/OneDrive - bjtu.edu.cn/HEVC/txt_file/P_PUNum/"
  matchpath2.append(matchPath);
  matchpath2.append("_P_PUNum.txt");
  const char* MatchPath2 = matchpath2.data();
  ofstream ofb(MatchPath2);

  string matchpath3="txt_file/I_CUNum/";     //"E:/I_CUNum/";
  matchpath3.append(matchPath);  
  matchpath3.append("_I_CUNum.txt");
  const char* MatchPath3 = matchpath3.data();
  ofstream ofc(MatchPath3);

  string matchpath4="txt_file/P_CUNum/"; //  "E:/P_CUNum/";
  matchpath4.append(matchPath);
  matchpath4.append("_P_CUNum.txt");
  const char* MatchPath4 = matchpath4.data();
  ofstream ofd(MatchPath4);

  //只取第一个P帧
  string matchpath5="txt_file/first_P_PUNum/";        // "E:/first_P_PUNum/";
  matchpath5.append(matchPath);
  matchpath5.append("_first_P_PUNum.txt");
  const char* MatchPath5 = matchpath5.data();
  ofstream ofe(MatchPath5);

  string matchpath6="txt_file/first_P_CUNum/";   //"E:/first_P_CUNum/";
  matchpath6.append(matchPath);
  matchpath6.append("_first_P_CUNum.txt");
  const char* MatchPath6 = matchpath6.data();
  ofstream off(MatchPath6);

  string matchpath7=matchPath;
  matchpath7.append(".txt");
  const char* MatchPath7 = matchpath7.data();
  ofstream ofg(MatchPath7);

  string matchpath8="txt_file/intra/";  //"E:/intra/";
  matchpath8.append(matchPath);
  matchpath8.append("_intra.txt");
  const char* MatchPath8 = matchpath8.data();
  ofstream ofh(MatchPath8);

  string matchpath9="txt_file/inter/";  //"E:/inter/";
  matchpath9.append(matchPath);
  matchpath9.append("_inter.txt");
  const char* MatchPath9 = matchpath9.data();
  ofstream ofi(MatchPath9);

  string matchpath10="txt_file/skip/";  //"E:/skip/";
  matchpath10.append(matchPath);
  matchpath10.append("_skip.txt");
  const char* MatchPath10 = matchpath10.data();
  ofstream ofj(MatchPath10);
  //////////////////////////////


  // call decoding function
 
  cTAppDecTop.decode();
  
  /////////////////////////
  for(int liang=0;liang<80;liang++)
  {
	  if((liang%4)==0)
	  {
		  //cout<<"num_frame:"<<liang<<endl;
		  for(int xiao=0;xiao<5;xiao++)
		  {
			  // cout<<intra_pre_mode[liang][xiao]<<"  ";
			  ofa<<I_PU_number[liang][xiao]<<"  ";
		  }
		  // cout<<endl;
		  ofa<<endl;

		  for(int xiao=0;xiao<4;xiao++)
		  {
			  // cout<<intra_pre_mode[liang][xiao]<<"  ";
			  ofc<<I_CU_number[liang][xiao]<<"  ";
		  }
		  // cout<<endl;
		  ofc<<endl;
		  ///////////֡��Ԥ��ģʽ
		//cout<<"num_frame:"<<liang<<endl;
		  for(int xiao=0;xiao<35;xiao++)
		  {
				  // cout<<intra_pre_mode[liang][xiao]<<"  ";
			  ofg<<intra_pre_mode[liang][xiao]<<"  ";
		  }
			  // cout<<endl;
		  ofg<<endl;
	  }
	  else
	  {
		  if((liang%4)==1)
		  {
			  for(int xiao=0;xiao<25;xiao++)
			  {
				  // cout<<intra_pre_mode[liang][xiao]<<"  ";
				  ofe<<P_PU_number[liang][xiao]<<"  ";
				  //ofb<<P_PU_number[liang][xiao]<<"  ";
			  }
			  ofe<<endl;
			  //ofb<<endl;
			  for(int xiao=0;xiao<4;xiao++)
			  {
				  // cout<<intra_pre_mode[liang][xiao]<<"  ";
				  off<<P_CU_number[liang][xiao]<<"  ";
				  //ofd<<P_CU_number[liang][xiao]<<"  ";
			  }
			  off<<endl;
			  //ofd<<endl;
		  }

		  for(int xiao=0;xiao<25;xiao++)
		  {
			  ofb<<P_PU_number[liang][xiao]<<"  ";
		  }
		  ofb<<endl;
		  for(int xiao=0;xiao<4;xiao++)
		  {
			  ofd<<P_CU_number[liang][xiao]<<"  ";
		  }
		  ofd<<endl;

	  }

	  ofh<<intra[liang]<<endl;
	  ofi<<inter[liang]<<endl;
	  ofj<<skip[liang]<<endl;
	  
  }

  ///////////////////////
  if (cTAppDecTop.getNumberOfChecksumErrorsDetected() != 0)
  {
    printf("\n\n***ERROR*** A decoding mismatch occured: signalled md5sum does not match\n");
    returnCode = EXIT_FAILURE;
  }

  // ending time
  dResult = (Double)(clock()-lBefore) / CLOCKS_PER_SEC;
  printf("\n Total Time: %12.3f sec.\n", dResult);
 
  // destroy application decoder class
  
  cTAppDecTop.destroy();
  
  return returnCode;
  
}

//! \}
