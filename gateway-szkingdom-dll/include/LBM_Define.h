/*************************************************
* Copyright (c) 2014,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：LBM_Define.h
* 摘    要：LBM结构体定义
*
* 当前版本：1.0
* 作    者：陈牧
* 完成日期：2014年5月20日
**************************************************/
#pragma once
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <string>
using namespace std;

#define RTMSG_OK                0
#define RTMSG_NO_DATA           100
#define RTMSG_KO                -1

#pragma comment (lib, "KCBPCli.lib")

typedef list<void*>  PtrList;

/** KCXP配置 */
struct KCXP_CONFIG
{
  char username[20];  //!< 用户名
  char password[20];  //!< 密码
  char address[20];   //!< 登录ip
  char server[20];    //!< 服务器名
  int port;           //!< 端口
  char req[20];       //!< 请求队列
  char ans[20];       //!< 应答队列
};

#define INIT_PARAM_ITEMS 13     //!< 系统参数个数

#define KEYLEN           20
#define VALUELEN         3700

/** 通用参数配置 */
struct PARAM_LIST
{
  char szKey[KEYLEN];       //!< 主键
  char szValue[VALUELEN];   //!< 值
};

// LBM入参信息
typedef struct
{
  char szKey[32];      // 参数名称
  char szValue[1024];  // 参数值
} ST_tagLbmParam, * PST_tagLbmParam;

/** 所属资产单元 */
struct ST_ASSET
{
  char nProjectID[10 + 1];    //!< 项目ID
  char nAssetID[10 + 1];      //!< 资产单元ID
  char szAssetName[64 + 1];   //!< 资产单元名称
};

/** 当前服务器时间 */
struct ST_CURDATETIME
{
  char nCurDate[10 + 1];        //!< 当前日期（数字） yyyymmdd
  char szCurDate[10 + 1];       //!< 当前日期（字符） yyyy-mm-dd
  char nCurTime[10 + 1];        //!< 当前时间（数字） hhMMssnn
  char szCurTime[10 + 1];       //!< 当前时间（字符） hh:MM:ss.nn
  char lCurDateTime[22 + 1];    //!< 当前日期时间（数字） yyyymmddhhMMssnn
  char szCurDateTime[22 + 1];   //!< 当前日期时间（字符） yyyy-mm-dd hh:MM:ss.nn
};

/** 所属股票数据 */
struct ST_ASSET_CODE
{
  char nProjectID[10 + 1];      //!< 项目ID
  char nEachLmt[10 + 1];        //!< 单笔限量    fengwc 0121 alter
  char nBuyVolSize[10 + 1];     //!< 买数量单位
  char nSellVolSize[10 + 1];    //!< 卖数量单位
  char nAssetID[10 + 1];        //!< 资产单元ID
  char szAssetName[64 + 1];     //!< 资产单元名称
  char nCombiID[10 + 1];        //!< 组合ID
  char szCombiName[64 + 1];     //!< 组合名称
  char chCodeBizAction[2 + 1];  //!< 股票类型
  char szStkCode[8 + 1];        //!< 证券代码
  char chStkEx[1 + 1];          //!< 证券交易所
  char szStkBd[2 + 1];          //!< 证券板块
  char szStkName[16 + 1];       //!< 证券名称
  char nMinWtVol[10 + 1];       //!< 最小委托数量
  char nPriceDish[16 + 1];      //!< 最小价格单位
  char nCheckOem[1 + 1];        //!< OEM标志
};

struct ST_ASSET_CODE_INFO
{
  char chPosType[1 + 1];        //!< 持仓限额类型 POS_TYPE  CHAR
  char chStkCls[1 + 1];         //!< 证券类别 STK_CLS CHAR(1) 
  char chStkEX[1 + 1];          //!< 证券交易所 STKEX CHAR(1)
  char chCodeBizAction[1 + 1];  //!< 股票类型 CODE_BIZ_ACTION CHAR(1)
  char chInvestType[1 + 1];     //!< 投资类型 INVEST_TYPE CHAR(1)
  char chCombiStatus[1 + 1];    //!<  组合状态  COMBI_STATUS  CHAR(1)
  char szStkBD[2 + 1];          //!< 交易板块 STKBD CHAR(2)
  int nCombiID;                 //!< 组合ID COMBI_ID  BIGINT
  int nProjectID;               //!< 项目ID PROJECT_ID  BIGINT
  int  nStkPoolID;              //!< 股票池分类ID STK_POOL_ID INTEGER 
  int nAssetID;                 //!< 资产单元ID ASSET_ID  BIGINT
  char szAssetName[64 + 1];     //!< 资产单元名称 ASSET_NAME  VARCHAR(64)
  char szCombiName[64 + 1];     //!< 组合名称 COMBI_NAME  VARCHAR(64)           
  char szStkCode[8 + 1];        //!< 证券代码 STK_CODE  VARCHAR(8)
  char szStkName[16 + 1];       //!< 证券名称 STK_NAME  VARCHAR(16) 
  __int64 llMaxPosVol;          //!< 持仓上限 MAX_POS_VOL BIGINT
  double dMaxPosVolP;           //!< 持仓上限比例 MAX_POS_VOL_P BIGINT
  __int64 llWarnMaxVol;         //!< 持仓上限预警值 WARN_MAX_VOL  BIGINT
  double dWarnMaxVolP;          //!< 持仓上限预警值比例 WARN_MAX_VOL_P  BIGINT
  __int64 llMinPosVol;          //!< 持仓下限 MIN_POS_VOL BIGINT
  double dMinPosVolP;           //!< 持仓下限比例 MIN_POS_VOL_P BIGINT
  __int64 llWarnMinVol;         //!< 持仓下限预警值 WARN_MIN_VOL  BIGINT
  double dWarnMinVolP;          //!< 持仓下限预警值比例 WARN_MIN_VOL_P  BIGINT  
  __int64 llMaxSinglePosVol;    //!< 单边持仓上限 MAX_SINGLE_POS_VOL  BIGINT
  __int64 llMaxNetPosVol;       //!< 净持仓上限 MAX_NET_POS_VOL BIGINT
};

/** 获取股票基本信息：LBM应答 */
struct ST_STK_NQINFO
{
  char szStkCode[8 + 1];        //!< 证券代码
  char szStkName[16 + 1];       //!< 证券简称 
  char chStkCls[1 + 1];         //!< 证券类别
  char szBaseCode[8 + 1];       //!< 基础证券
  char szStkIsin[16 + 1];       //!< ISIN编码
  char nTurnSize[10 + 1];       //!< 转让单位
  char szStkBD[2 + 1];          //!< 交易板块
  char chCurrenCy[1 + 1];       //!< 货币种类
  char llStkFaceVal[20 + 1];    //!< 证券面值
  char llCirculation[20 + 1];   //!< 总发行量
  char llFloatNum[20 + 1];      //!< 流通股数
  char nLastYearMgsy[10 + 1];   //!< 上年每股收益
  char nThisYearMgsy[10 + 1];   //!< 本年每股收益
  char nHandingFee[10 + 1];     //!< 经手费率
  char nStampTax[10 + 1];       //!< 印花税率
  char nTransFer[10 + 1];       //!< 过户费率
  char nPutupDate[10 + 1];      //!< 挂牌日期
  char nZqqxDate[10 + 1];       //!< 债券起息日
  char nPromptDate[10 + 1];     //!< 到期/交割日
  char nEachLmt[10 + 1];        //!< 每笔限量
  char nBuyVolSize[10 + 1];     //!< 买数量单位
  char nSellVolSize[10 + 1];    //!< 卖数量单位
  char nMinWtVol[10 + 1];       //!< 最小申报数量
  char nPriceDish[10 + 1];      //!< 价格档位
  char llFirstTurnLmt[20 + 1];  //!< 首笔转让限价参数
  char llLaterTurnLmt[20 + 1];  //!< 后续转让限价参数
  char chLmtPriceParam[1 + 1];  //!< 限价参数性质
  char nStkUpLmtPrice[10 + 1];  //!< 涨停价格
  char nStkLwLmtPrice[10 + 1];  //!< 跌停价格
  char nLargeUpPrice[10 + 1];   //!< 大宗转让价格上限
  char nLargeLwPrice[10 + 1];   //!< 大宗转让价格下限
  char chConstituent[1 + 1];    //!< 成分股标志
  char nConversion[10 + 1];     //!< 折合比例
  char chTurnStatus[1 + 1];     //!< 转让状态
  char chStkLevel[1 + 1];       //!< 证券级别
  char chTurnType[1 + 1];       //!< 转让类型
  char nMMNum[10 + 1];          //!< 做市商数量
  char chStopFlag[1 + 1];       //!< 停牌标志
  char chCqcxFlag[1 + 1];       //!< 除权除息标志
};

/** 获取普通行情：LBM应答 */
struct ST_NQ_MDINFO
{
  char szStkCode[8 + 1];        //!< 证券代码
  char szStkName[16 + 1];       //!< 证券简称
  char szHqDate[10 + 1];        //!< 行情日期
  char szHqTime[10 + 1];        //!< 行情时间
  char szHqStatus[6];           //!< 行情状态
  char szSvrTime[10 + 1];       //!< 转发时间
  char llCloseTprice[20 + 1];   //!< 昨日收盘转让价
  char llRCloseTprice[20 + 1];  //!< 昨日实际收盘转让价
  char llOpenTprice[20 + 1];    //!< 今日开盘转让价
  char llLastTprice[20 + 1];    //!< 最近转让价
  char llMatchedVol[20 + 1];    //!< 成交数量
  char llMatchedMoney[20 + 1];  //!< 成交金额
  char llMatchedNum[20 + 1];    //!< 成交笔数
  char llHighPrice[20 + 1];     //!< 最高成交价
  char llLowPrice[20 + 1];      //!< 最低成交价
  char llPeRatio1[20 + 1];      //!< 市盈率1
  char llPeRatio2[20 + 1];      //!< 市盈率2
  char llPriceRise1[20 + 1];    //!< 价格升跌1
  char llPriceRise2[20 + 1];    //!< 价格升跌2
  char llStkVolume[20 + 1];     //!< 合约持仓量
  char llStkSp5[20 + 1];        //!< 卖价位五
  char llStkSv5[20 + 1];        //!< 卖数量五
  char llStkSp4[20 + 1];        //!< 卖价位四
  char llStkSv4[20 + 1];        //!< 卖数量四
  char llStkSp3[20 + 1];        //!< 卖价位三
  char llStkSv3[20 + 1];        //!< 卖数量三
  char llStkSp2[20 + 1];        //!< 卖价位二
  char llStkSv2[20 + 1];        //!< 卖数量二
  char llStkSp1[20 + 1];        //!< 卖价位一/叫卖揭示价
  char llStkSv1[20 + 1];        //!< 卖数量一
  char llStkBp1[20 + 1];        //!< 买价位一/叫买揭示价
  char llStkBv1[20 + 1];        //!< 买数量一
  char llStkBp2[20 + 1];        //!< 买价位二
  char llStkBv2[20 + 1];        //!< 买数量二
  char llStkBp3[20 + 1];        //!< 买价位三
  char llStkBv3[20 + 1];        //!< 买数量三
  char llStkBp4[20 + 1];        //!< 买价位四
  char llStkBv4[20 + 1];        //!< 买数量四
  char llStkBp5[20 + 1];        //!< 买价位五
  char llStkBv5[20 + 1];        //!< 买数量五
};

/** 获取做市/投资行情：LBM应答 */
struct ST_MM_DISH10_INFO
{
  char szStkCode[8 + 1];        //!< 证券代码
  char szStkName[16 + 1];       //!< 证券简称
  char szOrderType[2 + 1];      //!< 业务类别
  char llWtVol[20 + 1];         //!< 申报数量
  char llWtPrice[20 + 1];       //!< 申报价格
  char chDataType[1 + 1];       //!< 数据类型
  char iWtTime[10 + 1];         //!< 申报时间
  char iReserveValue[10 + 1];   //!< 备用字段
  char llReserveFlag[20 + 1];   //!< 备用标志
};

/** 输入做市报价数据 */
struct ST_QUOTE_INFO
{
  char nAssetID[10 + 1];      //!< 资产单元ID
  char szStkCode[8 + 1];      //!< 证券代码
  char chStkEx[1 + 1];        //!< 证券交易所
  char dAskPrice[20 + 1];     //!< 叫买价格
  char nAskVolume[10 + 1];    //!< 叫买数量
  char dBidPrice[20 + 1];     //!< 叫卖价格
  char nBidVolume[10 + 1];    //!< 叫卖数量
  char szOrderID[22 + 1];     //!< 委托单号(输出)
};

/** 输入撤单委托 */
struct ST_CANCEL_ORDER
{
  char szOrderID[22 + 1];       //!< 委托单号
  char chOrderType[1 + 1];      //!< 委托类型
  char szCancelRemark[64 + 1];  //!< 撤单原因
};

/** 输入委托查询条件 */
struct ST_ORDER_SEARCH
{
  char szStkCode[8 + 1];      //!< 证券代码
  char nBegTime[10 + 1];      //!< 起始时间
  char nEndTime[10 + 1];      //!< 截至时间
  char nBegDate[10 + 1];      //!< 起始日期
  char nEndDate[10 + 1];      //!< 截至日期
  char chSearchType[1 + 1];   //!< 查询标识
};

/** 输出做市委托单查询结果 */
struct ST_QUOTE_ORDER_INFO
{
  char nAssetID[10 + 1];         //!< 资产单元ID
  char szStkCode[8 + 1];         //!< 证券代码
  char szOrderID[22 + 1];        //!< 委托合同序号
  char dAskPrice[20 + 1];        //!< 叫卖价
  char nAskWtVolume[10 + 1];     //!< 叫卖数量
  char nAskVolume[10 + 1];       //!< 叫卖挂单
  char chAskOrderStatus[1 + 1];  //!< 叫卖委托状态
  char nAskMatchVol[10 + 1];     //!< 叫卖成交数量
  char nAskCancelVol[10 + 1];    //!< 叫卖撤单数量
  char dBidPrice[10 + 1];        //!< 叫买价
  char nBidWtVolume[10 + 1];     //!< 叫买数量
  char nBidVolume[10 + 1];       //!< 叫买挂单
  char chBidOrderStatus[1 + 1];  //!< 叫买委托状态
  char nBidMatchVol[10 + 1];     //!< 叫买成交数量
  char nBidCancelVol[10 + 1];    //!< 叫买撤单数量
  char nQuoteDate[10 + 1];       //!< 报价日期
  char nQuoteTime[10 + 1];       //!< 报价时间
};

/** 输出委托单查询结果 */
struct ST_ORDER_INFO
{
  char iTrdDate[10 + 1];         //!< 交易日期
  char iOrderDate[10 + 1];       //!< 委托日期
  char iOrderTime[10 + 1];       //!< 委托时间
/*  char iOrderSn[10+1];         //!< 委托序号
  char iOrderBsn[10+1];          //!< 委托批号*/
  char szOrderId[22 + 1];        //!< 合同序号
  char chOrderStatus[1 + 1];     //!< 委托状态
/*  char chOrderValidFlag[1+1];  //!< 委托有效标志
  char iOrderValidDate[10+1];    //!< 委托有效日期
  char llProjectId[10+1];        //!< 项目ID
  char szProjectName[64+1];      //!< 项目名称*/
  char llAssetId[10 + 1];        //!< 资产单元ID
/*  char szAssetName[64+1];      //!< 资产单元名称
  char llCombiId[10+1];          //!< 组合ID
  char szCombiName[64+1];        //!< 组合名称
  char chStkex[1+1];             //!< 证券交易所
  char szStkbd[2+1];             //!< 交易板块
  char szStkpbu[8+1];            //!< 交易单元
  char szTrdacct[10+1];          //!< 交易账户
  char szTrdacctExid[10+1];      //!< 报盘交易账户
  char chTrdacctType[1+1];       //!< 交易账户类型
  char chRdacctExcls[1+1];       //!< 交易账户类别*/
  char iStkBiz[10 + 1];          //!< 证券业务
/*  char siStkBizAction[10+1];   //!< 证券业务行为
  char szStkBizEx[8+1];          //!< 证券业务（外部）*/
  char szStkCode[8 + 1];         //!< 证券代码
/*  char szStkName[16+1];        //!< 证券名称
  char chStkCls[1+1];            //!< 证券类别
  char chStkFlag[1+1];           //!< 证券标志
  char chCurrency[1+1];          //!< 货币代码*/
  char llOrderPrice[20 + 1];     //!< 委托价格
  char llOrderQty[20 + 1];       //!< 委托数量
  char dOrderAmt[20 + 1];        //!< 委托金额
/*  char dOrderFrzAmt[20+1];     //!< 委托冻结金额
  char dOrderUfzAmt[20+1];       //!< 委托解冻金额
  char llOfferQty[20+1];         //!< 申报数量
  char iOfferStime[10+1];        //!< 申报时间*/
  char llWithdrawnQty[20 + 1];   //!< 已撤单数量
  char llMatchedQty[20 + 1];     //!< 已成交数量
  char dMatchedAmt[20 + 1];      //!< 已成交金额
/*  char dRltSettAmt[20+1];      //!< 实时清算金额
  char chIsWithdraw[1+1];        //!< 撤单标志
  char llOpUser[20+1];           //!< 操作用户
  char szOpName[32+1];           //!< 操作用户姓名
  char szOpSite[255+1];          //!< 操作站点
  char chChannel[1+1];           //!< 操作渠道
  char szRawOrderId[22+1];       //!< 原合同序号
  char iOfferRecSn[10+1];        //!< 申报序号
  char szOfferRetMsg[64+1];      //!< 申报返回信息
  char szOrderRemark[64+1];      //!< 委托备注
  char szTargetTaAcct[6+1];      //!< 对手方交易单元
  char szTargetTransAcct[10+1];  //!< 对手方证券帐户
  char szLinkmanName[50+1];      //!< 联系人
  char szLinkmanTel[50+1];       //!< 联系方式
  char llAgreementId[20+1];      //!< 成交约定号
  char llAppSno[20+1];           //!< 意向申报号*/
};

/** 输入成交查询条件 */
struct ST_MATCH_SEARCH
{
  char nAssetID[10 + 1];      //!< 资产单元ID
  char szStkCode[8 + 1];      //!< 证券代码
  char nBegTime[10 + 1];      //!< 起始时间
  char nEndTime[10 + 1];      //!< 截至时间
  char nBegDate[10 + 1];      //!< 起始日期
  char nEndDate[10 + 1];      //!< 截至日期
};

/** 输出做市成交单查询结果 */
struct ST_QUOTE_MATCH_INFO
{
  char nMatchTime[10 + 1];     //!< 成交时间
  char szOrderID[22 + 1];      //!< 委托合同序号
  char nAssetID[10 + 1];       //!< 资产单元ID
  char nCombi_ID[10 + 1];      //!< 组合ID
  char szStkCode[8 + 1];       //!< 证券代码
  char szStkName[16 + 1];      //!< 证券名称
  char chStkEx[1 + 1];         //!< 证券交易所
  char szStkBd[2 + 1];         //!< 交易板块
  char szStkPbu[8 + 1];        //!< 交易单元
  char nStkBiz[10 + 1];        //!< 证券业务
  char nStkBizAction[4 + 1];   //!< 证券业务行为
  char nOrderPrice[10 + 1];    //!< 委托价格
  char nOrderQty[10 + 1];      //!< 委托数量
  char chIsWithdraw[1 + 1];    //!< 撤单标志
  char nMatchedPrice[10 + 1];  //!< 成交价格
  char nMatchedQty[10 + 1];    //!< 成交数量

  //add by zhangshuai
  char dMatchedAmt[20 + 1];   //!< 成交金额 
  char nTradeDate[10 + 1];    //!< 交易日期
  //add end

  // Add by chenmu 2015-7-27 13:00 增加成交编号
  char szMatchedSN[16 + 1];   //!< 成交编号
  char nUpdTime[10 + 1];      //!< 更新时间
  // Add End
};

/** 输出资产单元资金查询结果 */
struct ST_ASSET_FUND
{
  char nProjectId[10 + 1];      //!< 项目ID
  char szProjectName[64 + 1];   //!< 项目名称
  char nAssetId[10 + 1];        //!< 资产单元ID
  char szAssetName[64 + 1];     //!< 资产单元名称
  char siIntOrg[4 + 1];         //!< 内部机构
  char chCurrency[1 + 1];       //!< 货币代码
  char llMaxMoney[20 + 1];      //!< 资金上限
  char llMinMoney[20 + 1];      //!< 资金下限
  char llFundPrebln[20 + 1];    //!< 资金昨日余额
  char llFundBln[20 + 1];       //!< 资金当前余额
  char llFundAvl[20 + 1];       //!< 资金可用金额
  char llFundFrz[20 + 1];       //!< 资金冻结金额
  char llFundUfz[20 + 1];       //!< 资金解冻金额
  char llFundTrdFrz[20 + 1];    //!< 资金交易冻结金额
  char llFundTrdUfz[20 + 1];    //!< 资金交易解冻金额
  char llFundTrdOtd[20 + 1];    //!< 资金交易在途金额
  char llFundTrdBln[20 + 1];    //!< 资金交易轧差金额
  char llFundClrFrz[20 + 1];    //!< 资金清算冻结金额
  char llFundClrUfz[20 + 1];    //!< 资金清算解冻金额
  char llFundClrOtd[20 + 1];    //!< 资金清算在途金额
  char llFundClrCtf[20 + 1];    //!< 资金清算保付金额
  char llFundTrnFrz[20 + 1];    //!< 资金转帐冻结金额
  char llFundTrnUfz[20 + 1];    //!< 资金转账解冻金额
  char llFundDebt[20 + 1];      //!< 资金负债金额
  char llFundCredit[20 + 1];    //!< 资金债权金额
  char siIntRateSn[4 + 1];      //!< 利率编码
  char siDrRateSn[4 + 1];       //!< 负债利率编码
  char llIntCalBln[20 + 1];     //!< 计息余额
  char llIntBlnAccu[20 + 1];    //!< 利息积数
  char iIntCalDate[10 + 1];     //!< 计息日期
  char llInterest[20 + 1];      //!< 利息
  char llIntTax[20 + 1];        //!< 利息税
  char llDrInt[20 + 1];         //!< 负债利息
  char llMktVal[20 + 1];        //!< 市值
  char llCashAccu[20 + 1];      //!< 现金积数
  char llChequeAccu[20 + 1];    //!< 支票积数
  char llLastFundClr[20 + 1];   //!< 上次清算金额
  char llLwlmtFund[20 + 1];     //!< 资金下限
  char llLwlmtAsset[20 + 1];    //!< 资产下限
  char szUpdTime[32 + 1];       //!< 修改时间
  char chFundStatus[1 + 1];     //!< 资金状态
  char szMac[255 + 1];          //!< 校验码   fengwc 0121 alter
  char llPaylater[20 + 1];      //!< 垫付资金
};

/** 输出资产单元持仓查询结果 */
struct ST_SHARE
{
  char nProjectId[10 + 1];        //!< 项目ID
  char szProjectName[64 + 1];     //!< 项目名称
  char nAssetId[10 + 1];          //!< 资产单元ID
  char szAssetName[64 + 1];       //!< 资产单元名称
  char nCombiId[10 + 1];          //!< 组合ID
  char siIntOrg[4 + 1];           //!< 内部机构
  char chStkex[1 + 1];            //!< 证券交易所
  char szStkbd[2 + 1];            //!< 交易板块
  char szStkpbu[8 + 1];           //!< 交易单元
  char szTrdacct[10 + 1];         //!< 交易账户
  char chCurrency[1 + 1];         //!< 货币代码
  char szStkCode[8 + 1];          //!< 证券代码
  char szStkName[16 + 1];         //!< 证券名称
  char chStkCls[1 + 1];           //!< 证券类别
  char llStkPrebln[20 + 1];       //!< 证券昨日余额
  char llStkBln[20 + 1];          //!< 证券余额
  char llStkAvl[20 + 1];          //!< 证券可用数量
  char llStkFrz[20 + 1];          //!< 证券冻结数量
  char llStkUfz[20 + 1];          //!< 证券解冻数量
  char llStkNtrd[20 + 1];         //!< 证券非流通数量
  char llStkTrdFrz[20 + 1];       //!< 证券交易冻结数量
  char llStkTrdUfz[20 + 1];       //!< 证券交易解冻数量
  char llStkTrdOtd[20 + 1];       //!< 证券交易在途数量
  char llStkTrdBln[20 + 1];       //!< 证券交易轧差数量
  char llStkBcost[20 + 1];        //!< 证券买入成本
  char llStkBcostRlt[20 + 1];     //!< 证券买入成本（实时）
  //char llBuyBalance[20+1];      //!< 证券买入比例
  char llStkIncome[20 + 1];       //!< 今日实际盈亏金额
  char llStkIncomePre[20 + 1];    //!< 昨日实际盈亏金额
  char llStkFpl[20 + 1];          //!< 今日浮动盈亏金额
  char llStkFplPre[20 + 1];       //!< 昨日浮动盈亏金额
  char llStkMktl[20 + 1];         //!< 今日盯市盈亏金额
  char llStkMktlPre[20 + 1];      //!< 昨日盯市盈亏金额
  //char llSaleBalance[20+1];     //!< 证券卖出比例
  //char llStkClrFrz[20+1];       //!< 证券清算冻结数量
  //char llStkClrUfz[20+1];       //!< 证券清算解冻数量
  //char llStkClrOtd[20+1];       //!< 证券清算在途数量
  char llMktVal[20 + 1];          //!< 市值
  //char szUpdTime[32+1];         //!< 修改时间
  //char szMac[255+1];            //!< 校验码
};

/** 输出基本策略信息查询结果 */
struct ST_ALGO_BASEINFO
{
  char llAlgoBaseId[20 + 1];   //!< 基础策略ID
  char szAlgoName[32 + 1];     //!< 策略名称
  char szAlgoRemark[256 + 1];  //!< 策略备注
  char szDllEntry[32 + 1];     //!< DLL名称
  char szFuncPtr[32 + 1];      //!< 功能入口
};

/** 输出策略信息查询结果 */
struct ST_ALGO_INFO
{
  char llAlgoId[20 + 1];          //!< 策略ID
  char llAlgoBaseId[20 + 1];      //!< 基础策略ID
  char szAlgoName[32 + 1];        //!< 策略名称
  char szAlgoRemark[256 + 1];     //!< 策略备注
  char szDllEntry[32 + 1];        //!< DLL名称
  char szFuncPtr[32 + 1];         //!< 功能入口
  char chStkex[1 + 1];            //!< 证券交易所
  char szStkbd[2 + 1];            //!< 交易板块
  char szStkCode[8 + 1];          //!< 证券代码
  char szStkName[16 + 1];         //!< 证券名称
  char llProjectId[20 + 1];       //!< 项目ID
  char szProjectName[64 + 1];     //!< 项目名称
  char llAssetId[20 + 1];         //!< 资产单元ID
  char szAssetName[64 + 1];       //!< 资产单元名称
  char llCombiId[20 + 1];         //!< 组合ID
  char szCombiName[64 + 1];       //!< 组合名称
  char chAlgoStatus[1 + 1];       //!< 策略状态
  char iAlgoInterval[10 + 1];     //!< 委托间隔时间
  char szAlgoUpdateTime[32 + 1];  //!< 下达时间
};

/** 输出策略关联信息查询结果 */
struct ST_ALGO_INFO_EXT
{
  char llAlgoId[20 + 1];         //!< 策略ID
  char iStkBiz[10 + 1];          //!< 证券业务
  char chDishType[1 + 1];        //!< 档位类型
  char siPriceDish[10 + 1];      //!< 价格档位
  char chAlgoPriceType[1 + 1];   //!< 价格策略类型
  char iPriceFloatRate[10 + 1];  //!< 价格浮动比例
  char iPriceAbsValue[10 + 1];   //!< 价格绝对值
  char siVolDish[10 + 1];        //!< 数量档位
  char chAlgoVolType[1 + 1];     //!< 数量策略类型
  char iMinOrderQty[10 + 1];     //!< 最小委托数量
  char iMaxOrderQty[10 + 1];     //!< 最大委托数量
  char iVolFloatRate[10 + 1];    //!< 数量浮动比例
  char iVolAbsValue[10 + 1];     //!< 数量绝对值
  char llInitTotalVol[20 + 1];   //!< 初始委托总数量
  char llMatchedQty[20 + 1];     //!< 已成交数量
};

//add by zhangshuai
struct ST_QUOTE_CONSUMETIME_INFO
{
  char nTradeDate[11];        //!< 交易日期
  char szStkEx[2];            //!< 证券交易所
  char szStkBd[3];            //!< 交易板块
  char szStkCode[8 + 1];      //!< 证券代码
  char cLastOrdState[2];      //!< 最近申报状态
  char cLastStkState[2];      //!< 最近股票状态
  char  nLastOrdTime[11];     //!< 最近申报时间
  char  nLastInvTime[11];     //!< 最近失效时间
  char  nLastSusTime[11];     //!< 最近临时停牌时间
  char  nLastResTime[11];     //!< 最近复牌时间
  char  nLastUpdTime[11];     //!< 最近更新时长
  char  nLastOrderID[11];     //!< 最近申报号
  char  nValTotalTime[11];    //!< 有效报价累计时长
  char  nInvalTotalTime[11];  //!< 报价失效累计时长
  char  nMmTotalTime[11];     //!< 撮合累计时长
  char  nPreMmTotalTime[11];  //!< 拟撮合累计时长
};

//add end