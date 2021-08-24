/*************************************************
* Copyright (c) 2014,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：LBM_JY_Base.h
* 摘    要：LBM交易基础类
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
* @brief 交易基础类
*/
class LBM_JY_Base
{
public:
  LBM_JY_Base(void);
  virtual ~LBM_JY_Base(void);


  /**
  * 调用L3014012
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pAsset 资产单元信息
  * @param[out] nAssetItem 资产单元个数
  * @return 调用LBM成功或失败
  */
  int GetL3014012(KCBPCLIHANDLE hKCBPHandle, ST_ASSET** pAsset, int& nAssetItem);

  // Add by chenmu 2015-1-22 10:30 获取服务器时间
  /**
  * 调用L3010024
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pDateTime 当前服务器时间
  * @return 调用LBM成功或失败
  */
  int GetL3010024(KCBPCLIHANDLE hKCBPHandle, ST_CURDATETIME** pDateTime);
  // Add by chenmu 2015-1-22 Over

  /**
  * 调用L3014001
  * @param[in] hKCBPHandle  KCBP连接
  * @param[in] nAssetID 资产单元ID
  * @param[out] pAssetCode 所属股票信息
  * @param[out] nAssetCodeItem 所属股票个数
  * @return 调用LBM成功或失败
  */
  int GetL3014001(KCBPCLIHANDLE hKCBPHandle, char* nAssetID, ST_ASSET_CODE** pAssetCode, int& nAssetCodeItem);

  /**
  * 调用L3010001
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pFund 资金信息
  * @param[out] nItems 资产单元个数
  * @return 调用LBM成功或失败
  */
  int GetL3010001(KCBPCLIHANDLE hKCBPHandle, ST_ASSET_FUND** pFund, int& nItems);

  /**
  * 调用L3010002
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pShare 持仓股票信息
  * @param[out] nItems 股票个数
  * @return 调用LBM成功或失败
  */
  int GetL3010002(KCBPCLIHANDLE hKCBPHandle, ST_SHARE** pShare, int& nItems);

  /**
  * 调用L3013003
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pResult 委托应答
  * @param[out] nResultItems 记录数量
  * @return 调用LBM成功或失败
  */
  int SetL3013003(KCBPCLIHANDLE hKCBPHandle, ST_ORDER_INFO** pResult, int& nResultItems);
  /**
  * 调用L3013011
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pOrderID 合同序号
  * @return 调用LBM成功或失败
  */
  int SetL3013011(KCBPCLIHANDLE hKCBPHandle, char* pOrderID);

  /**
  * 调用L3013013
  * @param[in] hKCBPHandle  KCBP连接
  * @return 调用LBM成功或失败
  */
  int SetL3013013(KCBPCLIHANDLE hKCBPHandle);
  /**
  * 调用L3013009
  * @param[in] hKCBPHandle  KCBP连接
  * @param[in] strCode 证券代码
  * @return 调用LBM成功或失败
  */
  int GetL3013009(KCBPCLIHANDLE hKCBPHandle, char* strCode);

  /**
  * 调用L3013001
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pResult 查询结果
  * @param[out] nResultItems 查询结果数量
  * @return 调用LBM成功或失败
  */
  int GetL3013001(KCBPCLIHANDLE hKCBPHandle, ST_QUOTE_ORDER_INFO** pResult, int& nResultItems);
  /**
  * 调用L3013007
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pResult 查询结果
  * @param[out] nResultItems 查询结果数量
  * @return 调用LBM成功或失败
  */
  int GetL3013007(KCBPCLIHANDLE hKCBPHandle, ST_QUOTE_MATCH_INFO** pResult, int& nResultItems);

  /**
  * 调用L3019023
  * @param[in] hKCBPHandle  KCBP连接
  * @param[in] pszStkCode 证券代码
  * @param[out] pQuoteConsumeTime 查询结果
  * @param[out] nItem 查询结果数量
  * @return 调用LBM成功或失败
  */
  int GetL3019023(KCBPCLIHANDLE hKCBPHandle, char* pszStkCode, ST_QUOTE_CONSUMETIME_INFO** pQuoteConsumeTime, int& nItem);
  /**
  * 获取OEM号
  * @param[in] hKCBPHandle  KCBP连接
  * @param[in] pszAlgoName  策略名称
  * @param[in,out] iOemValidDays 剩余天数
  * @return 调用LBM成功或失败
  */
  int GetL0000601(KCBPCLIHANDLE hKCBPHandle, const char* pszAlgoName, int& iOemValidDays);  //fengwc alter 1.18

  LBM_Base* GetBase() { return m_pBase; }
  void SetBase(LBM_Base* pBase) { m_pBase = pBase; }
  ///< fengweican alter 5.5 增加自营股票处理
  /**
  * 调用L3013014
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pOrderID 合同序号
  * @param[out] nOrderSn 委托序号
  * @return 调用LBM成功或失败
  */
  int SetL3013014(KCBPCLIHANDLE hKCBPHandle, char* pOrderID, int& nOrderSn);
  /**
  * 调用L3013018
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pResult 查询结果
  * @param[out] nResultItems 查询结果数量
  * @return 调用LBM成功或失败
  */
  int GetL3013018(KCBPCLIHANDLE hKCBPHandle, NQWTQUOTE_ORDER_INFO** pResult, int& nResultItems);
  /**
  * 调用L3013020
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pResult 查询结果
  * @param[out] nResultItems 查询结果数量
  * @return 调用LBM成功或失败
  */
  int GetL3013020(KCBPCLIHANDLE hKCBPHandle, NQWTQUOTE_MATCH_INFO** pResult, int& nResultItems);
  ///< fengweican alter 2.28 增加大宗交易处理
  /**
  * 调用L3010087
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] szErr  LBM调用失败返回错误信息
  * @return 调用LBM成功或失败
  */
  int GetL3010087(KCBPCLIHANDLE hKCBPHandle, char* szErr);
  /**
  * 调用L3010087
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] szErr  LBM调用失败返回错误信息
  * @return 调用LBM成功或失败
  */
  int GetL3010088(KCBPCLIHANDLE hKCBPHandle, char* szErr);
  /**
  * 获取持仓限额
  * @param[in] hKCBPHandle  KCBP连接
  * @param[out] pResult 查询结果
  * @param[out] nResultItems 查询结果数量
  * @return 调用LBM成功或失败
  */
  int GetL3014001(KCBPCLIHANDLE hKCBPHandle, ST_ASSET_CODE_INFO** pResult, int& nResultItems);
  void SetLogFlag(BOOL bLogOpenFlag) { m_bLogOpenFlag = bLogOpenFlag; }
private:
  LBM_Base* m_pBase;
  BOOL m_bLogOpenFlag;
};

