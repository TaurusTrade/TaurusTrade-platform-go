#pragma once
/*************************************************
* Copyright (c) 2014,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：LBMNode.h
* 摘    要：LBM请求节点类
*
* 当前版本：1.0
* 作    者：冯伟灿
* 完成日期：2015年12月26日
**************************************************/
#include "LBM_Define.h"
/**
* @ingroup AlgoPlug
* @brief LBM请求节点类
*/
class CLBMNode
{
public:
  CLBMNode(void);
  ~CLBMNode(void);

public:
  char m_szLBMID[16];              //!< LBM编号
  char m_szStkCode[LEN_CODELIST];  //!< 股票代码需要显示提速版本的股票代码列表，因此扩展占用空间 fengwc alter 1.18
  char m_szOrderID[36];            //!< 委托合同序号

  int m_nLBMType;                  //!< 1-交易；2-行情；3-策略
  int m_nAssetID;                  //!< 资产单元ID
  int nResult;                     //!< LBM调用结果

  char m_szErrorInfo[LEN_LOG];     //!< 当前错误信息

  PARAM_LIST m_ParaList[36];       //!< LBM入参
  int m_nParaItems;                //!< LBM入参个数

  // Add by chenmu 2015-7-29 增加用户自定义字段，用于回调返回
  char m_szUserDefine[16 + 1];     //!< 用户自定义
  // End Add
};

