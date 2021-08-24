/*************************************************
* Copyright (c) 2014,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�LBM_HQ_Base.h
* ժ    Ҫ��LBM���������
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
* @brief ���������
*/
class  LBM_HQ_Base
{
public:
  LBM_HQ_Base(void);
  virtual ~LBM_HQ_Base(void);

  /**
  * ����L3012008
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pNQInfo ������Ϣ
  * @param[out] nNqItem �������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3012008(KCBPCLIHANDLE hKCBPHandle, ST_STK_NQINFO** pNQInfo, int& nNqItem);

  /**
  * ����L3012001
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pNQList ������Ϣ
  * @param[out] nTickItem �������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3012001(KCBPCLIHANDLE hKCBPHandle, ST_NQ_MDINFO** pNQList, int& nTickItem);
  /**
  * ����L3012002
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pMMList ����/Ͷ��������Ϣ
  * @param[out] nTickItem �������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3012002(KCBPCLIHANDLE hKCBPHandle, ST_MM_DISH10_INFO** pMMList, int& nTickItem);
  LBM_Base* GetBase() { return m_pBase; }
  void SetBase(LBM_Base* pBase) { m_pBase = pBase; }
private:
  LBM_Base* m_pBase;
};

