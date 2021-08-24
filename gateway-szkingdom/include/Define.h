/*************************************************
* Copyright (c) 2014,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：Define.h
* 摘    要：结构定义
*
* 当前版本：1.0
* 作    者：陈牧
* 完成日期：2014年5月20日
**************************************************/
#pragma once

#define THREAD_CREATE(id, func, params) (!(id = (HANDLE)_beginthreadex(NULL, 0, func, params, 0, NULL)))
#define THREAD_JOIN(id) WaitForSingleObject(id, INFINITE)
#define THREAD_RETURN return 0;
#define THREAD_T HANDLE 
#define THREAD_RET_T unsigned int __stdcall 

#define MUTEX_LOCK(m) EnterCriticalSection(m)
#define MUTEX_UNLOCK(m) LeaveCriticalSection(m)
#define MUTEX_INIT(m) InitializeCriticalSection(m)
#define MUTEX_DESTROY(m) DeleteCriticalSection(m)
#define MUTEX_T CRITICAL_SECTION

#define DIR_BUY 100 //买入
#define DIR_SELL 101//卖出
//投资
#define SEC_BIZ_DJMR                   55000011   //!< 定价买入
#define SEC_BIZ_DJMC                   55000012   //!< 定价卖出
#define SEC_BIZ_XYMR                   55000001   //!< 协议买入
#define SEC_BIZ_XYMC                   55000002   //!< 协议卖出
#define SEC_BIZ_XYHBMR                 55000007   //!< 协议互报买入
#define SEC_BIZ_XYHBMC                 55000008   //!< 协议互报买入

#define STK_BIZ_XGXJ	55000017	//!< 新股询价
#define STK_BIZ_XGSG	55000019	//!< 新股申购
#define STK_BIZ_YSYY	55000021	//!< 预受要约
#define STK_BIZ_CHYSYY	55000022	//!< 撤回预受要约
#define STK_BIZ_SJ_23	55000023	//!< 对手方最优买入
#define STK_BIZ_SJ_24	55000024	//!< 对手方最优卖出
#define STK_BIZ_SJ_25	55000025	//!< 本方最优买入
#define STK_BIZ_SJ_26	55000026	//!< 本方最优卖出
#define STK_BIZ_SJ_27	55000027	//!< 最优五档即时成交剩余撤销买入
#define STK_BIZ_SJ_28	55000028	//!< 最优五档即时成交剩余撤销卖出
#define STK_BIZ_SJ_29	55000029	//!< 最优五档即时成交剩余转限价买入
#define STK_BIZ_SJ_30	55000030	//!< 最优五档即时成交剩余转限价卖出

//做市部分
#define SEC_BIZ_ZSMR                   55000003   //!< 做市买入
#define SEC_BIZ_ZSMC                   55000004   //!< 做市卖出
#define SEC_BIZ_ZSHBMR                 55000009   //!< 做市协议买入
#define SEC_BIZ_ZSHBMC                 55000010   //!< 做市协议卖出
#define SEC_BIZ_DZJYMR                 55000015   //!< 大宗交易买入
#define SEC_BIZ_DZJYMC                 55000016   //!< 大宗交易卖出
#define SEC_BIZ_XJMR                   55000005   //!< 限价买入
#define SEC_BIZ_XJMC                   55000006   //!< 限价卖出



#define LEN_LOG 512
#define LEN_CODELIST 3700
/** 配置信息定义 */
struct CONFIG_LIST
{
  char szName[255];       //!< 显示文字
  int nValue;             //!< 绑定数据
};

/** 初始化信息 */
typedef struct
{
  char szUserName[32];      //!< 操作员用户名
  char szPassword[32];      //!< 操作员密码

  // Add by chenmu 2015-1-22 9:50 增加行情数据返回方式
  bool bBackAllHQ;          //!< 行情返回方式，false默认返回最新变化的行情，true定时返回所有行情
  // Add by chenmu 2015-1-22 Over
  bool bLocalAddressType;   //!< KCBP版本号，如果版本号低于1106，请填写该元素，等于或高于此版本可不填
}ST_tagInitInfo, * PST_tagInitInfo;

//fengwc alter 7.27
typedef struct
{
  char  szUserName[20];      //!< 用户名
  char  szPassword[20];      //!< 密码
  char  szIPAddress[20];     //!< 登录ip
  char  szServer[20];        //!< 服务器名
  int   nPort;               //!< 端口
  char  szReq[20];           //!< 请求队列
  char  szAns[20];           //!< 应答队列
}ST_tagKCBP_CONFIG, * PST_tagKCBP_CONFIG;

/** LBM请求队列信息 */
struct LBM_PARAM_INFO
{
  char szLBMID[16];
};

/** 输出所属股票数据 */
struct ASSET_CODE
{
  int nProjectID;               //!< 项目ID
  int nAssetID;                 //!< 资产单元ID
  int nEachLmt;                 //!< 单笔限量  fengwc 0121 alter
  int nBuyVolSize;              //!< 买数量单位
  int nSellVolSize;             //!< 卖数量单位
  char szAssetName[64 + 1];     //!< 资产单元名称
  int nCombiID;                 //!< 组合ID
  char szCombiName[64 + 1];     //!< 组合名称
  char chCodeBizAction[2 + 1];  //!< 股票类型
  char szStkCode[8 + 1];        //!< 证券代码
  char chStkEx[1 + 1];          //!< 证券交易所
  char szStkBd[2 + 1];          //!< 证券板块
  char szStkName[16 + 1];       //!< 证券名称
  int nMinWtVol;                //!< 最小申报数量
  double dPriceDish;            //!< 价格档位
  int iCheckOem;                //!< OEM标志
};

/** 输出股票基本信息 */
struct STK_NQINFO
{
  char szStkCode[8 + 1];        //!< 证券代码
  char szStkName[16 + 1];       //!< 证券简称 
  char chStkCls[1 + 1];         //!< 证券类别
  char szBaseCode[8 + 1];       //!< 基础证券
  char szStkIsin[16 + 1];       //!< ISIN编码
  int nTurnSize;                //!< 转让单位
  char szStkBD[2 + 1];          //!< 交易板块
  char chCurrenCy[1 + 1];       //!< 货币种类
  double dStkFaceVal;           //!< 证券面值
  long long llCirculation;      //!< 总发行量
  long long llFloatNum;         //!< 流通股数
  double dLastYearMgsy;         //!< 上年每股收益
  double dThisYearMgsy;         //!< 本年每股收益
  double dHandingFee;           //!< 经手费率
  double dStampTax;             //!< 印花税率
  double dTransFer;             //!< 过户费率
  int nPutupDate;               //!< 挂牌日期
  int nZqqxDate;                //!< 债券起息日
  int nPromptDate;              //!< 到期/交割日
  int nEachLmt;                 //!< 每笔限量
  int nBuyVolSize;              //!< 买数量单位
  int nSellVolSize;             //!< 卖数量单位
  int nMinWtVol;                //!< 最小申报数量
  double dPriceDish;            //!< 价格档位
  double dFirstTurnLmt;         //!< 首笔转让限价参数
  double dLaterTurnLmt;         //!< 后续转让限价参数
  char chLmtPriceParam[1 + 1];  //!< 限价参数性质
  double dStkUpLmtPrice;        //!< 涨停价格
  double dStkLwLmtPrice;        //!< 跌停价格
  double dLargeUpPrice;         //!< 大宗转让价格上限
  double dLargeLwPrice;         //!< 大宗转让价格下限
  char chConstituent[1 + 1];    //!< 成分股标志
  int nConversion;              //!< 折合比例
  char chTurnStatus[1 + 1];     //!< 转让状态
  char chStkLevel[1 + 1];       //!< 证券级别
  char chTurnType[1 + 1];       //!< 转让类型
  int nMMNum;                   //!< 做市商数量
  char chStopFlag[1 + 1];       //!< 停牌标志
  char chCqcxFlag[1 + 1];       //!< 除权除息标志
};

/** 输出普通成交行情数据 */
struct STK_NQ_TICK
{
  char szStkCode[8 + 1];    //!< 证券代码    fengwc alter 1.18 证券代码长度要统一       
  char szStkName[16];       //!< 证券简称           
  int nDate;                //!< 行情日期           
  int nTime;                //!< 行情时间           
  short nStatus;            //!< 行情状态
  int nSvrTime;             //!< 转发时间        fengwc alter 1.18 增加转发时间
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
  int nRemitFlag;           //!< 豁免状态
};

/** 输出做市十档行情数据 */
struct STK_NQ_ZSXX
{
  char szStkCode[8 + 1];      //!< 证券代码    fengwc alter 1.18 证券代码长度要统一        
  char szStkName[16];         //!< 证券简称           
  double dMMDishPri[2][10];   //!< 行情做市买卖十档价格：0-买；1-卖
  int nMMDishVol[2][10];      //!< 行情做市买卖十档数量：0-买；1-卖
  double dMDDishPri[2][10];   //!< 行情投资买卖十档价格：0-买；1-卖
  int nMDDishVol[2][10];      //!< 行情投资买卖十档数量：0-买；1-卖
  int nMMDishNum[2];          //!< 做市行情档数：0-买档数；1-卖档数
  int nMDDishNum[2];          //!< 投资行情档数：0-买档数；1-卖档数
  char cMMDataType[2];        //!< 做市数据类型：0-档位；1-笔数
};

/** 做市股票报价入参 */
struct QUOTE_INFO
{
  char szStkCode[8 + 1];       //!< 证券代码
  double dAskPrice;            //!< 叫卖价格
  int nAskVolume;              //!< 叫卖数量
  double dBidPrice;            //!< 叫买价格
  int nBidVolume;              //!< 叫买数量
  char szOrderRemark[64 + 1];  //!< 委托备注
  __int64 llOrderSN;           //!< 报单序号
  char szOrderID[22 + 1];      //!< 委托单号(输出)
};

/** 策略做市报价数据 */
struct ALGOQUOTE_INFO
{
  char szStkCode[8 + 1];       //!< 证券代码
  double dAskPrice;            //!< 叫卖价格
  int nAskVolume;              //!< 叫卖数量
  double dBidPrice;            //!< 叫买价格
  int nBidVolume;              //!< 叫买数量
  int nAlgoID;                 //!< 策略ID
  // Add by chenmu 2015-7-29 15:20 增加用户自定义字段
  char szUserDefine[16 + 1];     //!< 用户自定义（用于异步回调时，标注是哪笔委托）
  // End Add
  char szOrderRemark[64 + 1];  //!< 委托备注
};

/** 做市委托查询条件 */
struct ORDER_SEARCH
{
  char szStkCode[8 + 1];  //!< 证券代码
  int nBegTime;           //!< 起始时间
  int nEndTime;           //!< 截至时间
  int nBegDate;           //!< 起始日期
  int nEndDate;           //!< 截至日期
  char chSearchType[2];   //!< 查询标识
  int nBegUpdTime;        //!< 起始更新时间
  int nEndUpdTime;        //!< 截止更新时间
};

// Add by chenmu 2015-7-27 17:00 按成交编号查询做市成交明细
struct MATCH_SEARCHE
{
  char szStkCode[8 + 1];     //!< 证券代码
  char chType[2];            //!< 交易类型[0-做市；1-投资]
  char szMatchedSN[16 + 1];  //!< 成交编号
};
// End Add

/** 做市委托单查询结果 */
struct QUOTE_ORDER_INFO
{
  int nAssetID;                  //!< 资产单元ID
  char szStkCode[8 + 1];         //!< 证券代码
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
  int nQuoteDate;                //!< 报价日期
  int nQuoteTime;                //!< 报价时间
};

/** 做市委托查询结果 */
struct ORDER_INFO
{
  int nAssetID;                  //!< 资产单元ID
  char szStkCode[8 + 1];         //!< 证券代码
  char szOrderID[22 + 1];        //!< 委托合同序号
  char chOrderType[1 + 1];       //!< 委托类型
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
  int nQuoteDate;                //!< 报价日期
  int nQuoteTime;                //!< 报价时间

  bool bAllMatched;              //!< 是否全部成交

  ORDER_INFO()
  {
    chAskOrderStatus[0] = 'X';
    chBidOrderStatus[0] = 'X';
    bAllMatched = false;
  }
};

/** 成交回调结果 */
struct MATCH_INFO
{
  char szOrderID[22 + 1];    //!< 委托合同序号
  int nAssetID;              //!< 资产单元ID
  char szStkCode[8 + 1];     //!< 证券代码
  double dAskOrderPrice;     //!< 叫卖价格
  double dBidOrderPrice;     //!< 叫买价格
  int nAskOrderQty;          //!< 叫卖委托数量
  int nBidOrderQty;          //!< 叫买委托数量
  char chIsWithdraw[1 + 1];  //!< 撤单标志
  int nAskMatchedQty;        //!< 叫卖成交数量
  int nBidMatchedQty;        //!< 叫买成交数量
  int nMatchDate;            //!< 成交日期 fengwc alger  7.27
  int nMatchTime;            //!< 成交时间 fengwc alger 7.27
};

/** 做市成交单查询结果 */
struct QUOTE_MATCH_INFO
{
  int nMatchTime;            //!< 成交时间
  char szOrderID[22 + 1];    //!< 委托合同序号
  int nAssetID;              //!< 资产单元ID
  int nCombi_ID;             //!< 组合ID
  char szStkCode[8 + 1];     //!< 证券代码
  char szStkName[16 + 1];    //!< 证券名称
  char chStkEx[1 + 1];       //!< 证券交易所
  char szStkBd[2 + 1];       //!< 交易板块
  char szStkPbu[8 + 1];      //!< 交易单元
  int nStkBiz;               //!< 证券业务
  short nStkBizAction;       //!< 证券业务行为
  double dOrderPrice;        //!< 委托价格
  int nOrderQty;             //!< 委托数量
  char chIsWithdraw[1 + 1];  //!< 撤单标志
  double dMatchedPrice;      //!< 成交价格
  int nMatchedQty;           //!< 成交数量

  //add by zhangshuai
  double dMatchedAmt;        //!< 成交金额
  int nTradeDate;            //!< 交易日期
  //add end

  // Add by chenmu 2015-7-27 13:00 增加成交编号
  char szMatchedSN[16 + 1];  //!< 成交编号
  int nUpdTime;              //!< 更新时间
  // Add End
};

///** 做市股票交易信息汇总结果 */
struct QUOTE_TRADESUM_INFO
{
  int     nTradeDate;         //!< 交易日期
  char    szStkCode[8 + 1];   //!< 证券代码
  float   fBuyAvgPrice;       //!< 当日买成交均价
  float   fSellAvgPrice;      //!< 当日卖成交均价
  long long llTotalBuyQty;    //!< 当日总买成交数量
  double dTotalBuyAmt;        //!< 当日总买成交金额
  long long llTotalSellQty;   //!< 当日总卖成交数量
  double dTotalSellAmt;       //!< 当日总卖成交金额
};

/** 资产单元持仓查询结果 */
struct ASSET_SHARE
{
  int nProjectId;              //!< 项目ID
  char szProjectName[64 + 1];  //!< 项目名称
  int nAssetId;                //!< 资产单元ID
  char szAssetName[64 + 1];    //!< 资产单元名称
  int nCombiId;                //!< 组合ID
  short siIntOrg;              //!< 内部机构
  char chStkex[1 + 1];         //!< 证券交易所
  char szStkbd[2 + 1];         //!< 交易板块
  char szStkpbu[8 + 1];        //!< 交易单元
  char szTrdacct[10 + 1];      //!< 交易账户
  char chCurrency[1 + 1];      //!< 货币代码
  char szStkCode[8 + 1];       //!< 证券代码
  char szStkName[16 + 1];      //!< 证券名称
  char chStkCls[1 + 1];        //!< 证券类别
  long llStkPrebln;            //!< 证券昨日余额
  long llStkBln;               //!< 证券余额
  long llStkAvl;               //!< 证券可用数量
  long llStkFrz;               //!< 证券冻结数量
  long llStkUfz;               //!< 证券解冻数量
  long llStkNtrd;              //!< 证券非流通数量
  long llStkTrdFrz;            //!< 证券交易冻结数量
  long llStkTrdUfz;            //!< 证券交易解冻数量
  long llStkTrdOtd;            //!< 证券交易在途数量
  long llStkTrdBln;            //!< 证券交易轧差数量
  double dStkBcost;            //!< 证券买入成本
  double dStkBcostRlt;         //!< 证券买入成本（实时）
  double dStkIncome;           //!< 今日实际盈亏金额
  double dStkIncomePre;        //!< 昨日实际盈亏金额
  double dStkFpl;              //!< 今日浮动盈亏金额
  double dStkFplPre;           //!< 昨日浮动盈亏金额
  double dStkMktl;             //!< 今日盯市盈亏金额
  double dStkMktlPre;          //!< 昨日盯市盈亏金额
  double dMktVal;              //!< 市值
};

/** 资产单元资金查询结果 */
struct ASSET_FUND
{
  int nProjectId;              //!< 项目ID
  char szProjectName[64 + 1];  //!< 项目名称
  int nAssetId;                //!< 资产单元ID
  char szAssetName[64 + 1];    //!< 资产单元名称
  short siIntOrg;              //!< 内部机构
  char chCurrency[1 + 1];      //!< 货币代码
  double dMaxMoney;            //!< 资金上限
  double dMinMoney;            //!< 资金下限
  double dFundPrebln;          //!< 资金昨日余额
  double dFundBln;             //!< 资金当前余额
  double dFundAvl;             //!< 资金可用金额
  double dFundFrz;             //!< 资金冻结金额
  double dFundUfz;             //!< 资金解冻金额
  double dFundTrdFrz;          //!< 资金交易冻结金额
  double dFundTrdUfz;          //!< 资金交易解冻金额
  double dFundTrdOtd;          //!< 资金交易在途金额
  double dFundTrdBln;          //!< 资金交易轧差金额
  double dFundClrFrz;          //!< 资金清算冻结金额
  double dFundClrUfz;          //!< 资金清算解冻金额
  double dFundClrOtd;          //!< 资金清算在途金额
  double dFundClrCtf;          //!< 资金清算保付金额
  double dFundTrnFrz;          //!< 资金转帐冻结金额
  double dFundTrnUfz;          //!< 资金转账解冻金额
  double dFundDebt;            //!< 资金负债金额
  double dFundCredit;          //!< 资金债权金额
  short siIntRateSn;           //!< 利率编码
  short siDrRateSn;            //!< 负债利率编码
  double dIntCalBln;           //!< 计息余额
  double dIntBlnAccu;          //!< 利息积数
  int iIntCalDate;             //!< 计息日期
  double dInterest;            //!< 利息
  double dIntTax;              //!< 利息税
  double dDrInt;               //!< 负债利息
  double dMktVal;              //!< 市值
  double dCashAccu;            //!< 现金积数
  double dChequeAccu;          //!< 支票积数
  double dLastFundClr;         //!< 上次清算金额
  double dLwlmtFund;           //!< 资金下限
  double dLwlmtAsset;          //!< 资产下限
  char szUpdTime[32 + 1];      //!< 修改时间
  char chFundStatus[1 + 1];    //!< 资金状态
  char szMac[255 + 1];         //!< 校验码    fengwc 0121 alter
  double dPaylater;            //!< 垫付资金
};

/** 基本策略信息 */
struct ALGO_BASEINFO
{
  int nAlgoBaseId;             //!< 基础策略ID
  char szAlgoName[32 + 1];     //!< 策略名称
  char szAlgoRemark[256 + 1];  //!< 策略备注
  char szDllEntry[32 + 1];     //!< DLL名称
  char szFuncPtr[32 + 1];      //!< 功能入口
};

/** 策略信息 */
struct ALGO_INFO
{
  int nAlgoId;                    //!< 策略ID
  int nAlgoBaseId;                //!< 基础策略ID
  char szAlgoName[32 + 1];        //!< 策略名称
  char szAlgoRemark[256 + 1];     //!< 策略备注
  char szDllEntry[32 + 1];        //!< DLL名称
  char szFuncPtr[32 + 1];         //!< 功能入口
  char chStkex[1 + 1];            //!< 证券交易所
  char szStkbd[2 + 1];            //!< 交易板块
  char szStkCode[8 + 1];          //!< 证券代码
  char szStkName[16 + 1];         //!< 证券名称
  int nProjectId;                 //!< 项目ID
  char szProjectName[64 + 1];     //!< 项目名称
  int nAssetId;                   //!< 资产单元ID
  char szAssetName[64 + 1];       //!< 资产单元名称
  int nCombiId;                   //!< 组合ID
  char szCombiName[64 + 1];       //!< 组合名称
  char chAlgoStatus[1 + 1];       //!< 策略状态
  int nAlgoInterval;              //!< 委托间隔时间
  char szAlgoUpdateTime[32 + 1];  //!< 下达时间
};

/** 策略关联信息 */
struct ALGO_INFO_EXT
{
  int nAlgoId;               //!< 策略ID
  int nStkBiz;               //!< 证券业务
  short siDishType;          //!< 档位类型
  short siPriceDish;         //!< 价格档位
  short siAlgoPriceType;     //!< 价格策略类型
  int iPriceFloatRate;       //!< 价格浮动比例
  int iPriceAbsValue;        //!< 价格绝对值
  short siVolDish;           //!< 数量档位
  short siAlgoVolType;       //!< 数量策略类型
  int iMinOrderQty;          //!< 最小委托数量
  int iMaxOrderQty;          //!< 最大委托数量
  int iVolFloatRate;         //!< 数量浮动比例
  int iVolAbsValue;          //!< 数量绝对值
  long long llInitTotalVol;  //!< 初始委托总数量
  long long llMatchedQty;    //!< 已成交数量
};

//add by zhangshuai
struct QUOTE_CONSUMETIME_INFO
{
  int nTradeDate;         //!< 交易日期
  char szStkEx[2];        //!< 证券交易所
  char szStkBd[3];        //!< 交易板块
  char szStkCode[8 + 1];  //!< 证券代码
  char cLastOrdState;     //!< 最近申报状态
  char cLastStkState;     //!< 最近股票状态
  int  nLastOrdTime;      //!< 最近申报时间
  int  nLastInvTime;      //!< 最近失效时间
  int  nLastSusTime;      //!< 最近临时停牌时间
  int  nLastResTime;      //!< 最近复牌时间
  int  nLastUpdTime;      //!< 最近更新时长
  int  nLastOrderID;      //!< 最近申报号
  int  nValTotalTime;     //!< 有效报价累计时长
  int  nInvalTotalTime;   //!< 报价失效累计时长
  int  nMmTotalTime;      //!< 撮合累计时长
  int  nPreMmTotalTime;   //!< 拟撮合累计时长
};
/** 做市股票报价回报信息 */
struct QUOTE_BACK_INFO
{
  char szStkCode[8 + 1];      //!< 股票代码
  char szOrderID[22 + 1];     //!< 合同序号
  char szUserDefine[16 + 1];  //!< 用户自定义
};
//!< fengweican alter 2.28 增加大宗交易处理
/** 集合竞价转让和盘后大宗交易转让报价入参 */
struct DZQUOTE_INFO
{
  int nAssetID;                    //!< 资产单元ID
  char szStkCode[8 + 1];           //!< 证券代码
  char chStkEx[1 + 1];             //!< 证券交易所
  int nStkBiz;                     //!< 证券业务
  short nStkBizAction;             //!< 证券业务行为
  double dWtPrice;                 //!< 委托价格
  int nWtVolume;                   //!< 委托数量
  char szTargetTaAcct[6 + 1];      //!< 对手方交易单元
  char szTargetTransAcct[10 + 1];  //!< 对手方证券帐户
  __int64 nAgreementID;            //!< 成交约定号
  char szOrderRemark[64];          //!< 委托备注
  char chDZFlag[1 + 1];            //!< 大宗交易标识
};

struct ST_MovePosBatch
{
  __int64 llOutAssetID;        //!< 流出资产单元ID
  __int64 llInAssetID;         //!< 流入资产单元ID
  __int64 llOutCombiID;        //!< 流出组合ID
  __int64 llInCombiID;         //!< 流入组合ID
  char  chStkEX[1 + 1];        //!< 证券交易所
  char  szStkCodes[1024 + 1];  //!< 证券代码
  char  szRemark[128 + 1];     //!<备注
};

/** 自营股票报价入参 */
struct NQWTQUOTE_INFO
{
  int nAssetID;                    //!< 资产单元ID
  char szStkCode[8 + 1];           //!< 证券代码
  char chStkEx[1 + 1];             //!< 证券交易所
  int nStkBiz;                     //!< 证券业务
  short nStkBizAction;             //!< 证券业务行为
  double dWtPrice;                 //!< 委托价格
  int nWtVolume;                   //!< 委托数量
  char szTargetTaAcct[6 + 1];      //!< 对手方交易单元
  char szTargetTransAcct[10 + 1];  //!< 对手方证券帐户
  __int64 nAgreementID;            //!< 成交约定号
  char szOrderRemark[64];          //!< 委托备注
};

/** 自营股票报价回报信息 */
struct NQWTQUOTE_BACK_INFO
{
  char szStkCode[8 + 1];      //!< 股票代码
  char szOrderID[22 + 1];     //!< 合同序号
  int nOrderSn;               //!< 委托序号
  char szUserDefine[16 + 1];  //!< 用户自定义
};

/** 自营股票委托查询条件 */
struct NQWTORDER_SEARCH
{
  char szStkCode[8 + 1];       //!< 证券代码
  int nStkBiz;                 //!< 证券业务
  int nAssetID;                //!< 资产单元ID
  char chOrderStatus[1 + 1];   //!< 委托状态 取值范围:'0'--"未报",'1'--"正报",'2'--"已报",'3'--"已报待撤",'4'--"部成待撤",'5'--"部撤",'6'--"已撤",'7'--"部成已撤",'8'--"已成",'9'--"废单",'A'--"待报"
  int nBegTime;                //!< 起始时间
  int nEndTime;                //!< 截至时间
  int nBegDate;                //!< 起始日期
  int nEndDate;                //!< 截至日期
  int nBegUpdTime;             //!< 起始更新时间
  int nEndUpdTime;             //!< 截止更新时间
};

/** 自营股票成交查询条件 */
struct NQWTMATCH_SEARCHE
{
  char szStkCode[8 + 1];      //!< 证券代码
  int nStkBiz;                //!< 证券业务
  int nAssetID;               //!< 资产单元ID
  char chCancelOrder[1 + 1];  //!< 委托撤单 取值范围 '0'-返回所有的成交记录;'1'-返回撤单标志为F正常的记录
  int nBegTime;               //!< 起始时间
  int nEndTime;               //!< 截至时间
  int nBegDate;               //!< 起始日期
  int nEndDate;               //!< 截至日期
  int nBegUpdTime;            //!< 起始更新时间
  int nEndUpdTime;            //!< 结束更新时间
};
/** 自营股票委托明细出参 */
struct NQWTQUOTE_ORDER_INFO
{
  int nTradeDate;                  //!< 交易日期 
  int  nOrderDate;                 //!< 委托日期
  int  nOrderTime;                 //!< 委托时间
  int iOrderSn;                    //!< 委托序号
  int iOrderBsn;                   //!< 委托批号
  char szOrderID[22 + 1];          //!< 合同序号
  char chOrderStatus[1 + 1];       //!< 委托状态
  char chOrderValidFlag[1 + 1];    //!< 委托有效标志
  int nOrderValidDate;             //!< 委托有效日期
  int nProjectID;                  //!< 项目ID
  char szProjectName[64 + 1];      //!< 项目名称
  int nAssetID;                    //!< 资产单元ID
  char szAssetName[64 + 1];        //!< 资产单元名称
  int nCombiId;                    //!< 组合ID
  char szCombiName[64 + 1];        //!< 组合名称
  char chStkEx[1 + 1];             //!< 证券交易所
  char szStkBD[2 + 1];             //!< 交易板块
  char szStkpbu[8 + 1];            //!< 交易单元
  char szTrdacct[10 + 1];          //!< 交易账户
  char szTrdAcct_Exid[10 + 1];     //!< 报盘交易账户
  char chTrdacctType[1 + 1];       //!< 交易账户类型
  char chRdacctExcls[1 + 1];       //!< 交易账户类别
  int nStkBiz;                     //!< 证券业务
  short nStkBizAction;             //!< 证券业务行为
  char szStkBizEx[8 + 1];          //!< 证券业务（外部）
  char szStkCode[8 + 1];           //!< 证券代码
  char szStkName[16 + 1];          //!< 证券名称
  char chStkCls[1 + 1];            //!< 证券类别
  char chStkFlag[1 + 1];           //!< 证券标志
  char chCurrency[1 + 1];          //!< 货币代码
  double dWtPrice;                 //!< 委托价格
  int nOrderQty;                   //!< 委托数量
  double dOrderAmt;                //!< 委托金额
  double dOrderFrzAmt;             //!< 委托冻结金额
  double dOrderUfzAmt;             //!< 委托解冻金额
  int nOfferQty;                   //!< 申报数量
  int nOfferStime;                 //!< 申报时间
  int nWithdrawQty;                //!< 已撤单数量
  int nMatchQty;                   //!< 已成交数量
  double dMatchedAmt;              //!< 已成交金额
  double dRltSeatAmt;              //!< 实时清算金额
  char chIsWithdraw[1 + 1];        //!< 撤单标志
  char chRawOrderID[22 + 1];       //!< 原合同序号
  int nOfferRecSn;                 //!< 申报序号
  char szTargetTaAcct[6 + 1];      //!< 对手方交易单元
  char szTargetTransAcct[10 + 1];  //!< 对手方证券帐户
  __int64 nAgreementID;            //!< 成交约定号
  __int64 nAppSno;                 //!< 意向申报号
  char llOpUser[20 + 1];           //!< 操作用户
  char szOpName[32 + 1];           //!< 操作用户姓名
  char szOpSite[255 + 1];          //!< 操作站点
  char chChannel[1 + 1];           //!< 操作渠道
};
/** 自营股票成交明细出参 */
struct NQWTQUOTE_MATCH_INFO
{
  int nTradeDate;                  //!< 交易日期
  int nMatchTime;                  //!< 成交时间
  int  nOrderDate;                 //!< 委托日期
  int nOrderSn;                    //!< 委托序号
  int iOrderBsn;                   //!< 委托批号
  char szOrderID[22 + 1];          //!< 合同序号
  int nProjectID;                  //!< 项目ID
  char szProjectName[64 + 1];      //!< 项目名称
  int nAssetID;                    //!< 资产单元ID
  char szAssetName[64 + 1];        //!< 资产单元名称
  int nCombiId;                    //!< 组合ID
  char szCombiName[64 + 1];        //!< 组合名称
  char chStkEx[1 + 1];             //!< 证券交易所
  char szStkBD[2 + 1];             //!< 交易板块
  char szStkpbu[8 + 1];            //!< 交易单元
  char szTrdacct[10 + 1];          //!< 交易账户
  char szTrdAcct_Exid[10 + 1];     //!< 报盘交易账户
  char chTrdacctType[1 + 1];       //!< 交易账户类型
  char chRdacctExcls[1 + 1];       //!< 交易账户类别
  int nStkBiz;                     //!< 证券业务
  short nStkBizAction;             //!< 证券业务行为
  char szStkBizEx[8 + 1];          //!< 证券业务（外部）
  char szStkCode[8 + 1];           //!< 证券代码
  char szStkName[16 + 1];          //!< 证券名称
  char chStkCls[1 + 1];            //!< 证券类别
  char chStkFlag[1 + 1];           //!< 证券标志
  char chCurrency[1 + 1];          //!< 货币代码
  double dWtPrice;                 //!< 委托价格
  int nOrderQty;                   //!< 委托数量
  double dOrderAmt;                //!< 委托金额
  double dOrderFrzAmt;             //!< 委托冻结金额
  char szCancelRemark[64 + 1];     //!< 撤单原因
  char chIsWithdraw[1 + 1];        //!< 撤单标志
  char chMatchedType[1 + 1];       //!< 成交类型
  char szMatchedSN[16 + 1];        //!< 成交编号
  double dMatchedPrice;            //!< 成交价格
  int nMatchedVol;                 //!< 成交数量
  double dMatchedMoney;            //!< 成交金额   
  double dRltSeatAmt;              //!< 实时清算金额
  double dFundAvl;                 //!< 资金可用金额
  long llStkAvl;                   //!< 证券可用数量
  char szTargetTaAcct[6 + 1];      //!< 对手方交易单元
  char szTargetTransAcct[10 + 1];  //!< 对手方证券帐户
  char llOpUser[20 + 1];           //!< 操作用户
  char szOpName[32 + 1];           //!< 操作用户姓名
  char szOpSite[255 + 1];          //!< 操作站点
  char chChannel[1 + 1];           //!< 操作渠道
  int nUpdTime;                    //!< 更新时间
};
//add end