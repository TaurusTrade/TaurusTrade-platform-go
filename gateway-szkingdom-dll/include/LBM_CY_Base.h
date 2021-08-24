/*************************************************
* Copyright (c) 2014,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：LBM_CY_Base.h
* 摘    要：LBM策略基础类
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
* @brief 策略基础类
*/
class LBM_CY_Base
{
public:
  LBM_CY_Base(void);
  virtual ~LBM_CY_Base(void);

  /**
  * 调用L3015006
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pAlgoBase 基本策略信息
  * @param[out] nItems 基本策略个数
  * @return 调用LBM成功或失败
  */
  int GetL3015006(KCBPCLIHANDLE hKCBPHandle, ST_ALGO_BASEINFO** pAlgoBase, int& nItems);

  /**
  * 调用L3015007
  * @param[in] hKCBPHandle  KCBP连接
  * @param[in] nAssetID 资产单元ID
  * @param[out] pAlgoInfo 策略信息
  * @param[out] nItems 策略个数
  * @return 调用LBM成功或失败
  */
  int GetL3015007(KCBPCLIHANDLE hKCBPHandle, int nAssetID, ST_ALGO_INFO** pAlgoInfo, int& nItems);

  /**
  * 调用L3015008
  * @param[in] hKCBPHandle  KCBP连接
  * @param[in] nAlgoID 策略ID
  * @param[out] pAlgoParam 策略参数信息
  * @param[out] nItems 策略参数个数
  * @return 调用LBM成功或失败
  */
  int GetL3015008(KCBPCLIHANDLE hKCBPHandle, int nAlgoID, ST_ALGO_INFO_EXT** pAlgoParam, int& nItems);

  //add by zhangshuai
  /**
  * 调用L3015009
  * @param[in] hKCBPHandle  KCBP连接
  * @param[in] nAlgoID 策略ID
  * @param[in] cAlgoStatus 策略状态
  * @return 调用LBM成功或失败
  */
  int GetL3015009(KCBPCLIHANDLE hKCBPHandle, int nAlgoID, char cAlgoStatus);
  LBM_Base* GetBase() { return m_pBase; }
  void SetBase(LBM_Base* pBase) { m_pBase = pBase; }
private:
  LBM_Base* m_pBase;
};

