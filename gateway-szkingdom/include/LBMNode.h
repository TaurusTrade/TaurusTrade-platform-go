#pragma once
/*************************************************
* Copyright (c) 2014,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�LBMNode.h
* ժ    Ҫ��LBM����ڵ���
*
* ��ǰ�汾��1.0
* ��    �ߣ���ΰ��
* ������ڣ�2015��12��26��
**************************************************/
#include "LBM_Define.h"
/**
* @ingroup AlgoPlug
* @brief LBM����ڵ���
*/
class CLBMNode
{
public:
  CLBMNode(void);
  ~CLBMNode(void);

public:
  char m_szLBMID[16];              //!< LBM���
  char m_szStkCode[LEN_CODELIST];  //!< ��Ʊ������Ҫ��ʾ���ٰ汾�Ĺ�Ʊ�����б������չռ�ÿռ� fengwc alter 1.18
  char m_szOrderID[36];            //!< ί�к�ͬ���

  int m_nLBMType;                  //!< 1-���ף�2-���飻3-����
  int m_nAssetID;                  //!< �ʲ���ԪID
  int nResult;                     //!< LBM���ý��

  char m_szErrorInfo[LEN_LOG];     //!< ��ǰ������Ϣ

  PARAM_LIST m_ParaList[36];       //!< LBM���
  int m_nParaItems;                //!< LBM��θ���

  // Add by chenmu 2015-7-29 �����û��Զ����ֶΣ����ڻص�����
  char m_szUserDefine[16 + 1];     //!< �û��Զ���
  // End Add
};

