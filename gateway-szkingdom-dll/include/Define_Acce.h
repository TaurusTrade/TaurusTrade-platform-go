/*************************************************
* Copyright (c) 2014,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：Define_Acce.h
* 摘    要：结构定义
*
* 当前版本：1.0
* 作    者：冯伟灿
* 完成日期：2016年1月16日
**************************************************/
#pragma once

//L3014026返回内容
struct ST_AssetShareInfo
{
  int nAssetID;                 //!< 资产单元ID
  char szAssetName[64 + 1];     //!< 资产单元名称
  char szStkCode[8 + 1];        //!< 证券代码
  char szStkName[16 + 1];       //!< 证券名称
  char szStkBd[2 + 1];          //!< 交易板块
  char chCodeBizAction[2 + 1];  //!< 股票类型
  long long llMM_Num;           //!< 做市商数量
  long long llCirculation;      //!< 总发行量
  long long llFloatNum;         //!< 流通股数
                                
  char chTurnStatus[1 + 1];     //!< 转让状态
  double dStkUplmtPrice;        //!< 涨停价
  double dStkLwlmtPrice;        //!< 跌停价

  long long llEachLmt;          //!< 每笔报价限量
  long long llBuyVolSize;       //!< 买数量单位
  long long llSellVolSize;      //!< 卖数量单位
  long long llMmMaxSpread;      //!< 股转做市报价买卖最大价差(%)
  long long llMinWtVol;         //!< 股转做市报价最小委托数量
  double dPriceDish;            //!< 最小价格单位(NQ_INFO.PRICE_DISH*MM_MIN_PRICE_UNIT)
  long long llQuoteValidVol;    //!< 股转做市报价有效挂单量
  int iCheckOem;                //!< OEM标志

};
//L3015200返回内容
struct ST_NQInfo_Codes
{
  char szStkCode[8 + 1];    //!< 证券代码           
  char szStkName[16];       //!< 证券简称           
  int nDate;                //!< 行情日期           
  int nTime;                //!< 行情时间           
  short nStatus;            //!< 行情状态
  int nSvrTime;             //!< 转发时间
  double dClosePrice;       //!< 昨日收盘转让价     
  double dRClosePrice;      //!< 昨日实际收盘转让价
  double dOpenPrice;        //!< 今日开盘转让价     
  double dLastPrice;        //!< 最近转让价         
  double dHighPrice;        //!< 最高成交价         
  double dLowPrice;         //!< 最低成交价   
  long long llMatchedVol;   //!< 成交数量           
  double dMatchedMoney;     //!< 成交金额           
  long long llMatchedNum;   //!< 成交笔数           
  double dPeRatio[2];       //!< 市盈率1、2                      
  double dPriceRise[2];     //!< 价格升跌1、2          
  long long llStkVolume;    //!< 合约持仓量
  double dNQDishPri[2][5];  //!< 普通行情买卖五档价格：0-买；1-卖
  int nNQDishVol[2][5];     //!< 普通行情买卖五档数量：0-买；1-卖

  __int64 llStkAvl;         //!< 证券可用数量
  double dMktVal;           //!< 市值
  double dStkIncome;        //!< 今日实际盈亏金额
  double dStkIncomePre;     //!< 昨日实际盈亏金额
  double dStkBcostRlt;      //!< 证券买入成本（实时）
  __int64 llStkTrdBln;      //!< 证券交易轧差数量
  int nStkHmBiz;            //!< 证券豁免状态
  __int64 llStkBln;         //!< 证券余额
  double dBidAvgPrice;      //!< 当日买入均价
  double dAskAvgPrice;      //!< 当日卖出均价
  int nBidVol;              //!< 当日买入数量
  int nAskVol;              //!< 当日卖出数量
  char chStkCls[1 + 1];     //!< 证券类别
};
//L3015201返回内容
struct ST_ZSInfo_Codes
{
  char szStkCode[8 + 1];
  char szWtTime[10 + 1];
  double dMM_BP[10];      //!< 做市买价
  int nMM_BV[10];         //!< 做市买量
  double dMM_SP[10];      //!< 做市卖价
  int nMM_SV[10];         //!< 做市卖量
  double dST_BP[10];      //!< 投资买价
  int nST_BV[10];         //!< 投资买量
  double dST_SP[10];      //!< 投资卖价
  int nST_SV[10];         //!< 投资卖量
};
//L3015202返回内容
struct ST_Quote_Codes
{
  int nAssetID;                  //!< 资产单元ID
  char szStkCode[8 + 1];         //!< 证券代码    
  char chStkEx[1 + 1];           //!< 证券交易所
  int  nStkBiz;                  //!< 证券业务
  int nStkBizAction;             //!< 证券业务行为
  char szOrderID[22 + 1];        //!< 委托合同序号
  double dAskPrice;              //!< 叫卖价
  int nAskWtVolume;              //!< 叫卖数量
  int nAskVolume;                //!< 叫卖挂单
  char chAskOrderStatus[1 + 1];  //!< 叫卖委托状态
  int nAskMatchVol;              //!< 叫卖成交数量
  int nAskCancelVol;             //!< 叫卖撤单数量
  double dBidPrice;              //!< 叫买价
  int nBidWtVolume;              //!< 叫买数量
  int nBidVolume;                //!< 叫买挂单
  char chBidOrderStatus[1 + 1];  //!< 叫买委托状态
  int nBidMatchVol;              //!< 叫买成交数量
  int nBidCancelVol;             //!< 叫买撤单数量
  char szCancelRemark[24 + 1];   //!< 撤单原因
  int nQuoteDate;                //!< 报价日期
  int nQuoteTime;                //!< 报价时间
};
//L3015203返回内容
struct ST_RiskInfo_Codes
{
  __int64 llRiskID;                  //!< 风控编号
  char chTriggerType[2];             //!< 触发类型
  char szRiskRelationObj[128 + 1];   //!< 关联对象
  char szRiskRelationName[128 + 1];  //!< 关联对象名称
  char chRiskRelationType[2];        //!< 关联类型
  char chRikTouchStatus[2];          //!< 风险状态
  char  szRiskTouchTime[10];         //!< 触发时间
  char szRiskSummary[128 + 1];       //!< 风险说明
};
//L3015204返回内容
struct ST_AcctInfo
{
  double dAllAsset;                //!<总资产
  double dAllFpl;                  //!<总浮动盈亏
  double dAllMktval;               //!<总市值
  double dAllBcost;                //!<总买入成本
  char  chBizStatus[2];            //!<业务状态
};
//L3015205返回内容
struct ST_NqContRecs_Codes
{
  int iTrdDate;                 //!< 交易日期
  char chStkEx[1 + 1];          //!< 证券交易所
  char szStkBd[2 + 1];          //!< 证券板块
  char szStkCode[8 + 1];        //!< 证券代码
  char chLastOrdState[2];       //!< 最近申报状态
  char chLastStkState[2];       //!< 最近股票状态
  int  nLastOrdTime;            //!< 最近申报时间
  int  nLastInvTime;            //!< 最近失效时间
  int  nLastSusTime;            //!< 最近临时停牌时间
  int  nLastResTime;            //!< 最近复牌时间
  int  nLastUpdTime;            //!< 最近更新时长
  char  szLastOrderID[22 + 1];  //!< 最近申报号
  int  nValTotalTime;           //!< 有效报价累计时长
  int  nInvalTotalTime;         //!< 报价失效累计时长
  int  nMmTotalTime;            //!< 撮合累计时长
  int  nPreMmTotalTime;         //!< 拟撮合累计时长
  __int64 llCallQty;            //!< 买方向挂单
  __int64 llPutQty;             //!< 卖方向挂单
};
//L3015206返回内容
struct ST_WithdrawOrder_Codes
{
  __int64 llOpCdoe;              //!< 操作员代码     
  int nAssetID;                  //!< 资产单元ID
  char szStkCode[8 + 1];         //!< 证券代码
  char chStkEx[1 + 1];           //!< 证券交易所
  int  nStkBiz;                  //!< 证券业务
  int nStkBizAction;             //!< 证券业务行为
  char szOrderID[22 + 1];        //!< 委托合同序号
  double dAskPrice;              //!< 叫卖价
  int nAskWtVolume;              //!< 叫卖数量
  int nAskVolume;                //!< 叫卖挂单
  char chAskOrderStatus[1 + 1];  //!< 叫卖委托状态
  int nAskMatchVol;              //!< 叫卖成交数量
  int nAskCancelVol;             //!< 叫卖撤单数量
  double dBidPrice;              //!< 叫买价
  int nBidWtVolume;              //!< 叫买数量
  int nBidVolume;                //!< 叫买挂单
  char chBidOrderStatus[1 + 1];  //!< 叫买委托状态
  int nBidMatchVol;              //!< 叫买成交数量
  int nBidCancelVol;             //!< 叫买撤单数量
  char szCancelRemark[24 + 1];   //!< 撤单原因
  int nQuoteDate;                //!< 报价日期
  int nQuoteTime;                //!< 报价时间
};
//L3015207返回内容
struct ST_MatchInfo_Codes
{
  int iTrdDate;                    //!< 交易日期
  char szMatchTime[9];             //!< 成交时间
  int  nOrderDate;                 //!< 委托日期
  int  nOrderSn;                   //!< 委托序号
  int  nOrderBsn;                  //!< 委托批号
  char szOrderId[22 + 1];          //!< 合同序号
  __int64  llProjectId;            //!< 项目ID
  char szProjectName[64 + 1];      //!< 项目名称
  __int64 llAssetId;               //!< 资产单元ID
  char szAssetName[64 + 1];        //!< 资产单元名称
  __int64 llCombiId;               //!< 组合ID
  char szCombiName[64 + 1];        //!< 组合名称
  char chStkex[1 + 1];             //!< 证券交易所
  char szStkbd[2 + 1];             //!< 交易板块
  char szStkpbu[8 + 1];            //!< 交易单元
  char szTrdacct[10 + 1];          //!< 交易账户
  char szTrdacctExid[10 + 1];      //!< 报盘交易账户
  char chTrdacctType[1 + 1];       //!< 交易账户类型
  char chRdacctExcls[1 + 1];       //!< 交易账户类别  
  int  nStkBiz;                    //!< 证券业务
  int nStkBizAction;               //!< 证券业务行为
  char szStkBizEx[8 + 1];          //!< 证券业务（外部）
  char szStkCode[8 + 1];           //!< 证券代码
  char szStkName[16 + 1];          //!< 证券名称
  char chStkCls[1 + 1];            //!< 证券类别
  char chStkFlag[1 + 1];           //!< 证券标志
  char chCurrency[1 + 1];          //!< 货币代码
  double dOrderPrice;              //!< 委托价格
  __int64 llOrderQty;              //!< 委托数量
  double dOrderAmt;                //!< 委托金额
  double dOrderFrzAmt;             //!< 委托冻结金额
  char chCancelReason[3];          //!< 撤单原因
  char chIsWithdraw[1 + 1];        //!< 撤单标志
  char chMatchedType[1 + 1];       //!< 成交类型
  char szMatchedSN[16 + 1];        //!< 成交编号
  double dMatchedPrice;            //!< 成交价格
  __int64 llMatchedQty;            //!< 成交数量
  double dMatchedAmt;              //!< 成交金额
  double dRltSettAmt;              //!< 实时清算金额
  double dFundAvl;                 //!< 资金可用金额
  __int64 llStkAvl;                //!< 证券可用金额
  char llOpUser[20 + 1];           //!< 操作用户
  char szOpName[32 + 1];           //!< 操作用户姓名
  char szOpSite[255 + 1];          //!< 操作站点
  char chChannel[1 + 1];           //!< 操作渠道
};

//L3015208返回内容
struct ST_NQWTQuote_Codes
{
  int  nOrderDate;                 //!< 委托日期
  int  nOrderTime;                 //!< 委托时间
  int  nOrderSn;                   //!< 委托序号
  char szOrderID[22 + 1];          //!< 合同序号
  char chOrderStatus[1 + 1];       //!< 委托状态
  int nStkBiz;                     //!< 证券业务
  char szStkCode[8 + 1];           //!< 证券代码
  double dOrderPrice;              //!< 委托价格
  __int64 nOrderQty;               //!< 委托数量
  __int64 llWithdrawnQty;          //!< 已撤单数量
  __int64 llMatchedQty;            //!< 成交数量
  char chIsWithdraw[1 + 1];        //!< 撤单标志
  char szOrderRemark[64 + 1];      //!< 委托备注
  char szTargetTaAcct[6 + 1];      //!< 对手方交易单元
  char szTargetTransAcct[10 + 1];  //!< 对手方证券帐户
  char llAgreementId[20 + 1];      //!< 成交约定号
};

//L3015209返回内容
struct ST_NQWTMatchedInfo_Codes
{
  char szMatchTime[9];             //!< 成交时间
  int  nOrderDate;                 //!< 委托日期
  int  nOrderSn;                   //!< 委托序号
  char szOrderID[22 + 1];          //!< 合同序号
  int nStkBiz;                     //!< 证券业务
  char szStkCode[8 + 1];           //!< 证券代码
  double dOrderPrice;              //!< 委托价格
  __int64 nOrderQty;               //!< 委托数量
  char chCancelReason[3];          //!< 撤单原因
  char chIsWithdraw[1 + 1];        //!< 撤单标志
  char szMatchedSN[16 + 1];        //!< 成交编号
  double dMatchedPrice;            //!< 成交价格
  int nMatchedQty;                 //!< 成交数量
  char szTargetTaAcct[6 + 1];      //!< 对手方交易单元
  char szTargetTransAcct[10 + 1];  //!< 对手方证券帐户
};
//合笔持仓成本信息
struct ST_InvStkBcostRltInfo
{
  int nAssetID;            //!< 资产单元
  int nIntOrg;             //!< 内部机构
  char szStkCode[8 + 1];   //!< 证券代码
  char szStkName[16 + 1];  //!< 证券名称
  char szTrdAcct[10 + 1];  //!< 交易账户
  __int64 llStkBlnPre;     //!< 日初库存量
  double  dStkBcostPre;    //!< 日初持仓成本
  double  dCostPricePre;   //!< 日初成本价
  __int64 llInvStkBln;     //!< 实时库存量
  double  dInvBcostRlt;    //!< 实时持仓成本
  double  dInvCostPrice;   //!< 实时成本价
  double  dMktVal;         //!< 市值
  double  dInvStkFpl;      //!< 浮动盈亏
  double  dRealIncome;     //!< 已实现收入
  double  dRealIncomeT;    //!< 累计已实现收入
  __int64 llBuyQtyT;       //!< 买入总数量
  double  dBuyAmtT;        //!< 买入总金额
  __int64 llSellQtyT;      //!< 卖出总数量
  double  dSellAmtT;       //!< 卖出总金额
};