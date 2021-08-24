/*************************************************
* Copyright (c) 2014,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�LBM_CY_Base.h
* ժ    Ҫ��LBM���Ի�����
*
* ��ǰ�汾��1.0
* ��    �ߣ�����
* ������ڣ�2014��6��20��
**************************************************/
#pragma once
#include "LBM_Define.h"
#include "LBM_Base.h"

/**
* @ingroup AlgoPlug
* @brief ���Ի�����
*/
class LBM_CY_Base
{
public:
  LBM_CY_Base(void);
  virtual ~LBM_CY_Base(void);

  /**
  * ����L3015006
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pAlgoBase ����������Ϣ
  * @param[out] nItems �������Ը���
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3015006(KCBPCLIHANDLE hKCBPHandle, ST_ALGO_BASEINFO** pAlgoBase, int& nItems);

  /**
  * ����L3015007
  * @param[in] hKCBPHandle  KCBP����
  * @param[in] nAssetID �ʲ���ԪID
  * @param[out] pAlgoInfo ������Ϣ
  * @param[out] nItems ���Ը���
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3015007(KCBPCLIHANDLE hKCBPHandle, int nAssetID, ST_ALGO_INFO** pAlgoInfo, int& nItems);

  /**
  * ����L3015008
  * @param[in] hKCBPHandle  KCBP����
  * @param[in] nAlgoID ����ID
  * @param[out] pAlgoParam ���Բ�����Ϣ
  * @param[out] nItems ���Բ�������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3015008(KCBPCLIHANDLE hKCBPHandle, int nAlgoID, ST_ALGO_INFO_EXT** pAlgoParam, int& nItems);

  //add by zhangshuai
  /**
  * ����L3015009
  * @param[in] hKCBPHandle  KCBP����
  * @param[in] nAlgoID ����ID
  * @param[in] cAlgoStatus ����״̬
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3015009(KCBPCLIHANDLE hKCBPHandle, int nAlgoID, char cAlgoStatus);
  LBM_Base* GetBase() { return m_pBase; }
  void SetBase(LBM_Base* pBase) { m_pBase = pBase; }
private:
  LBM_Base* m_pBase;
};

