/*************************************************
* Copyright (c) 2014,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：LBM_HQ_Base.h
* 摘    要：LBM行情基础类
*
* 当前版本：1.0
* 作    者：陈牧
* 完成日期：2014年6月20日
**************************************************/
#pragma once
#include "LBM_Define.h"
#include "LBM_Base.h"

/**
* @ingroup AlgoPlug
* @brief 行情基础类
*/
class  LBM_HQ_Base
{
public:
  LBM_HQ_Base(void);
  virtual ~LBM_HQ_Base(void);

  /**
  * 调用L3012008
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pNQInfo 行情信息
  * @param[out] nNqItem 行情个数
  * @return 调用LBM成功或失败
  */
  int GetL3012008(KCBPCLIHANDLE hKCBPHandle, ST_STK_NQINFO** pNQInfo, int& nNqItem);

  /**
  * 调用L3012001
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pNQList 行情信息
  * @param[out] nTickItem 行情个数
  * @return 调用LBM成功或失败
  */
  int GetL3012001(KCBPCLIHANDLE hKCBPHandle, ST_NQ_MDINFO** pNQList, int& nTickItem);
  /**
  * 调用L3012002
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pMMList 做市/投资行情信息
  * @param[out] nTickItem 行情个数
  * @return 调用LBM成功或失败
  */
  int GetL3012002(KCBPCLIHANDLE hKCBPHandle, ST_MM_DISH10_INFO** pMMList, int& nTickItem);
  LBM_Base* GetBase() { return m_pBase; }
  void SetBase(LBM_Base* pBase) { m_pBase = pBase; }
private:
  LBM_Base* m_pBase;
};

