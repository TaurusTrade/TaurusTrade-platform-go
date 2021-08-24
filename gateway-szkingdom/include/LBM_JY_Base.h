/*************************************************
* Copyright (c) 2014,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�LBM_JY_Base.h
* ժ    Ҫ��LBM���׻�����
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
* @brief ���׻�����
*/
class LBM_JY_Base
{
public:
  LBM_JY_Base(void);
  virtual ~LBM_JY_Base(void);


  /**
  * ����L3014012
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pAsset �ʲ���Ԫ��Ϣ
  * @param[out] nAssetItem �ʲ���Ԫ����
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3014012(KCBPCLIHANDLE hKCBPHandle, ST_ASSET** pAsset, int& nAssetItem);

  // Add by chenmu 2015-1-22 10:30 ��ȡ������ʱ��
  /**
  * ����L3010024
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pDateTime ��ǰ������ʱ��
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3010024(KCBPCLIHANDLE hKCBPHandle, ST_CURDATETIME** pDateTime);
  // Add by chenmu 2015-1-22 Over

  /**
  * ����L3014001
  * @param[in] hKCBPHandle  KCBP����
  * @param[in] nAssetID �ʲ���ԪID
  * @param[out] pAssetCode ������Ʊ��Ϣ
  * @param[out] nAssetCodeItem ������Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3014001(KCBPCLIHANDLE hKCBPHandle, char* nAssetID, ST_ASSET_CODE** pAssetCode, int& nAssetCodeItem);

  /**
  * ����L3010001
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pFund �ʽ���Ϣ
  * @param[out] nItems �ʲ���Ԫ����
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3010001(KCBPCLIHANDLE hKCBPHandle, ST_ASSET_FUND** pFund, int& nItems);

  /**
  * ����L3010002
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pShare �ֲֹ�Ʊ��Ϣ
  * @param[out] nItems ��Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3010002(KCBPCLIHANDLE hKCBPHandle, ST_SHARE** pShare, int& nItems);

  /**
  * ����L3013003
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pResult ί��Ӧ��
  * @param[out] nResultItems ��¼����
  * @return ����LBM�ɹ���ʧ��
  */
  int SetL3013003(KCBPCLIHANDLE hKCBPHandle, ST_ORDER_INFO** pResult, int& nResultItems);
  /**
  * ����L3013011
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pOrderID ��ͬ���
  * @return ����LBM�ɹ���ʧ��
  */
  int SetL3013011(KCBPCLIHANDLE hKCBPHandle, char* pOrderID);

  /**
  * ����L3013013
  * @param[in] hKCBPHandle  KCBP����
  * @return ����LBM�ɹ���ʧ��
  */
  int SetL3013013(KCBPCLIHANDLE hKCBPHandle);
  /**
  * ����L3013009
  * @param[in] hKCBPHandle  KCBP����
  * @param[in] strCode ֤ȯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3013009(KCBPCLIHANDLE hKCBPHandle, char* strCode);

  /**
  * ����L3013001
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pResult ��ѯ���
  * @param[out] nResultItems ��ѯ�������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3013001(KCBPCLIHANDLE hKCBPHandle, ST_QUOTE_ORDER_INFO** pResult, int& nResultItems);
  /**
  * ����L3013007
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pResult ��ѯ���
  * @param[out] nResultItems ��ѯ�������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3013007(KCBPCLIHANDLE hKCBPHandle, ST_QUOTE_MATCH_INFO** pResult, int& nResultItems);

  /**
  * ����L3019023
  * @param[in] hKCBPHandle  KCBP����
  * @param[in] pszStkCode ֤ȯ����
  * @param[out] pQuoteConsumeTime ��ѯ���
  * @param[out] nItem ��ѯ�������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3019023(KCBPCLIHANDLE hKCBPHandle, char* pszStkCode, ST_QUOTE_CONSUMETIME_INFO** pQuoteConsumeTime, int& nItem);
  /**
  * ��ȡOEM��
  * @param[in] hKCBPHandle  KCBP����
  * @param[in] pszAlgoName  ��������
  * @param[in,out] iOemValidDays ʣ������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL0000601(KCBPCLIHANDLE hKCBPHandle, const char* pszAlgoName, int& iOemValidDays);  //fengwc alter 1.18

  LBM_Base* GetBase() { return m_pBase; }
  void SetBase(LBM_Base* pBase) { m_pBase = pBase; }
  ///< fengweican alter 5.5 ������Ӫ��Ʊ����
  /**
  * ����L3013014
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pOrderID ��ͬ���
  * @param[out] nOrderSn ί�����
  * @return ����LBM�ɹ���ʧ��
  */
  int SetL3013014(KCBPCLIHANDLE hKCBPHandle, char* pOrderID, int& nOrderSn);
  /**
  * ����L3013018
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pResult ��ѯ���
  * @param[out] nResultItems ��ѯ�������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3013018(KCBPCLIHANDLE hKCBPHandle, NQWTQUOTE_ORDER_INFO** pResult, int& nResultItems);
  /**
  * ����L3013020
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pResult ��ѯ���
  * @param[out] nResultItems ��ѯ�������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3013020(KCBPCLIHANDLE hKCBPHandle, NQWTQUOTE_MATCH_INFO** pResult, int& nResultItems);
  ///< fengweican alter 2.28 ���Ӵ��ڽ��״���
  /**
  * ����L3010087
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] szErr  LBM����ʧ�ܷ��ش�����Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3010087(KCBPCLIHANDLE hKCBPHandle, char* szErr);
  /**
  * ����L3010087
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] szErr  LBM����ʧ�ܷ��ش�����Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3010088(KCBPCLIHANDLE hKCBPHandle, char* szErr);
  /**
  * ��ȡ�ֲ��޶�
  * @param[in] hKCBPHandle  KCBP����
  * @param[out] pResult ��ѯ���
  * @param[out] nResultItems ��ѯ�������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetL3014001(KCBPCLIHANDLE hKCBPHandle, ST_ASSET_CODE_INFO** pResult, int& nResultItems);
  void SetLogFlag(BOOL bLogOpenFlag) { m_bLogOpenFlag = bLogOpenFlag; }
private:
  LBM_Base* m_pBase;
  BOOL m_bLogOpenFlag;
};

