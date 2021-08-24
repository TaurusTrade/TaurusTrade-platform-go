/*************************************************
* Copyright (c) 2014,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：LBM_Plugin.h
* 摘    要：LBM算法插件
*
* 当前版本：1.0
* 作    者：陈牧
* 完成日期：2014年5月20日
**************************************************/
#pragma once
#include "Define.h"
#include "LBM_JY_Base.h"
#include "LBM_HQ_Base.h"
#include "LBM_CY_Base.h"
#include "LBMNode.h"
/********** fengwc alter 1.18************/
#include "LBM_Acce.h"
/******************************************/
/** 行情时间编号 */
#define TICK_TIME 18
/** 委托轮询时间编号 */
#define ORDER_TIME  28
/** 连接轮询时间编号 */
#define CONNECT_TIME  38

/** 交易LBM标志 */
#define NQ_JY 1
/** 行情LBM标志 */
#define NQ_HQ 2
/** 策略LBM标志 */
#define NQ_CY 3
/** 历史行情LBM标志 */
#define NQ_LSHQ 4
/**线程池代码**/
#include<Windows.h>
#include<cstdlib>
class LBM_Plugin;
struct ST_THREADPOOL
{
  int nThreadIndex;
  LBM_Plugin* pMainDlg;
  CLBMNode PoolNode;
};

/**************/
/** 回调参数 */
struct CALLBACK_PARAM
{
  void* Plugin;         //!< LBM_Plugin指针
  void* hCallWnd;       //!< 调用方句柄
};

/** LBM错误信息 */
struct LBM_ERROR_INFO
{
  int nAssetID;         //!< 资产单元ID
  char szLBMID[16];       //!< LBM编号
  char szStkCode[LEN_CODELIST];       //!< 股票代码 fengwc alter 1.18 扩大股票代码空间，好放下股票代码列表
  char szOrderID[36];       //!< 合同序号
  char szErrorInfo[255];      //!< 错误信息
  // Add by chenmu 2015-8-17 14:30
  char szUserDefine[16 + 1];      //!< 用户自定义
};

typedef void (*CALLBACKFUN)(CALLBACK_PARAM* pParam, char* pObject);
typedef void (*CALLBACK_NQHQ)(CALLBACK_PARAM* pParam, STK_NQ_TICK* pNQHQInfo);            //!< 获取单支股票的普通行情回调函数
typedef void (*CALLBACK_ZSHQ)(CALLBACK_PARAM* pParam, STK_NQ_ZSXX* pZSHQInfo);            //!< 获取单支股票的做市行情回调函数
typedef void (*CALLBACK_ORDER)(CALLBACK_PARAM* pParam, ORDER_INFO* pOrderInfo);           //!< 委托确认回调函数
typedef void (*CALLBACK_MATCH)(CALLBACK_PARAM* pParam, MATCH_INFO* pMatchInfo);           //!< 成交确认回调函数
typedef void (*CALLBACK_ERROR)(CALLBACK_PARAM* pParam, LBM_ERROR_INFO* pErrorInfo);         //!< LBM错误回调函数
typedef void (*CALLBACK_NQINFO)(CALLBACK_PARAM* pParam, STK_NQINFO* pNQInfo, int nItem);        //!< 获取股票基础信息回调函数
typedef void (*CALLBACK_FUND)(CALLBACK_PARAM* pParam, ASSET_FUND* pFund, int nItem);          //!< 获取资产单元资金回调函数
typedef void (*CALLBACK_SHARE)(CALLBACK_PARAM* pParam, ASSET_SHARE* pShare, int nItem);       //!< 获取资产单元持仓回调函数
typedef void (*CALLBACK_QUOTE)(CALLBACK_PARAM* pParam, QUOTE_BACK_INFO* pBackQuote);          //!< 获取双边报价回调函数
typedef void (*CALLBACK_CANCELQUOTE)(CALLBACK_PARAM* pParam, char* pBackCancelQuote, int nLen);           //!< 获取撤单回调函数
typedef void (*CALLBACK_QUOTELIST)(CALLBACK_PARAM* pParam, QUOTE_ORDER_INFO* pQuote, int nItem);    //!< 获取单支做市股票的委托明细回调函数
typedef void (*CALLBACK_QUOTEMATCH)(CALLBACK_PARAM* pParam, QUOTE_MATCH_INFO* pMatch, int nItem);   //!< 获取单支做市股票的成交明细回调函数
typedef void (*CALLBACK_TRADESUM)(CALLBACK_PARAM* pParam, QUOTE_TRADESUM_INFO* pSumInfo, int nItem);  //!< 某日成交汇总信息回调函数

////////****************************fengwc alter 1.18************************************/
typedef void (*CALLBACK_ASSETSHARE)(CALLBACK_PARAM* pParam, ST_AssetShareInfo* pInfo, int nItem);          //!< 获取持仓表股票信息回调函数
typedef void (*CALLBACK_NQHQ_CODES)(CALLBACK_PARAM* pParam, ST_NQInfo_Codes* pNQHQInfo, int nItem);        //!< 获取多支股票的普通行情、持仓、报价均价回调函数
typedef void (*CALLBACK_ZSHQ_CODES)(CALLBACK_PARAM* pParam, STK_NQ_ZSXX* pZSHQInfo, int nItem);          //!< 获取多支股票的做市行情回调函数
typedef void (*CALLBACK_QUOTE_CODES)(CALLBACK_PARAM* pParam, ST_Quote_Codes* pInfo, int nItem);          //!< 获取多支做市股票的委托明细信息回调函数
typedef void (*CALLBACK_RISKINFO_CODES)(CALLBACK_PARAM* pParam, ST_RiskInfo_Codes* pInfo, int nItem);        //!< 获取多支做市股票的风险查询信息回调函数
typedef void (*CALLBACK_ACCTINFO)(CALLBACK_PARAM* pParam, ST_AcctInfo* pInfo, int nItem);              //!< 获取当前交易员汇总的资产单元资金、市值，系统业务切换标志，闭市标志定股票的做市行情信息回调函数
typedef void (*CALLBACK_NQCONTRECS_CODES)(CALLBACK_PARAM* pParam, ST_NqContRecs_Codes* pInfo, int nItem);      //!< 获取多支做市股票的报价时长信息回调函数
typedef void (*CALLBACK_WITHDRAWORDER_CODES)(CALLBACK_PARAM* pParam, ST_WithdrawOrder_Codes* pInfo, int nItem);  //!< 获取多支做市股票的可撤单信息回调函数
typedef void (*CALLBACK_MATCHINFO_CODES)(CALLBACK_PARAM* pParam, ST_MatchInfo_Codes* pInfo, int nItem);      //!< 获取多支做市股票的成交明细信息回调函数
typedef void (*CALLBACK_HISLASTQUOTE_CODES)(CALLBACK_PARAM* pParam, QUOTE_ORDER_INFO* pInfo, int nItem);     ///!< 获取多支做市股票的昨日报价查询信息回调函数
typedef void (*CALLBACK_INVSTKBCOSTRLT)(CALLBACK_PARAM* pParam, ST_InvStkBcostRltInfo* pInfo, int nItem);        //!< 获取合笔持仓成本信息回调函数
/*****************************************************************************************/
//!< fengweican alter 5.5 增加自营股票处理
typedef void (*CALLBACK_NQWTQUOTE)(CALLBACK_PARAM* pParam, NQWTQUOTE_BACK_INFO* pBackQuote);            //!< 自营股票报价回调函数
typedef void (*CALLBACK_NQWTQUOTELIST)(CALLBACK_PARAM* pParam, NQWTQUOTE_ORDER_INFO* pQuote, int nItem);      //!< 获取单支自营股票的委托明细
typedef void (*CALLBACK_NQWTQUOTEMATCH)(CALLBACK_PARAM* pParam, NQWTQUOTE_MATCH_INFO* pMatch, int nItem);     //!< 获取单支自营股票的成交明细信息
typedef void (*CALLBACK_NQWTQUOTE_CODES)(CALLBACK_PARAM* pParam, ST_NQWTQuote_Codes* pInfo, int nItem);      //!< 获取多支自营股票的委托明细信息
typedef void (*CALLBACK_NQWTMATCHEDINFO_CODES)(CALLBACK_PARAM* pParam, ST_NQWTMatchedInfo_Codes* pInfo, int nItem);//!< 获取多支自营股票的成交明细信息
//!< fengweican alter 2.28 增加大宗交易处理
typedef void (*CALLBACK_MOVEPOSBATCH)(CALLBACK_PARAM* pParam, ST_MovePosBatch* pInfo, int nItem);            //!< 获取撤单回调函数
typedef void (*CALLBACK_COMBILMTINFOBATCH)(CALLBACK_PARAM* pParam, char* pBackCancelQuote, int nLen);           //!< 获取撤单回调函数
typedef void (*CALLBACK_LISTCOMBIINFO)(CALLBACK_PARAM* pParam, ST_ASSET_CODE_INFO* pInfo, int nItem);            //!< 获取撤单回调函数
/**
* @defgroup AlgoPlug算法插件模块
* 基础算法API
* @author 陈牧
* @version 1.0
* @date 2013-2014
* @{
*/

/**
* @ingroup AlgoPlug
* @brief 算法API入口
*/
class __declspec(dllexport) LBM_Plugin
{
public:
  LBM_Plugin(void);
  ~LBM_Plugin(void);

  /**
  * 获取错误信息
  * @param[in] nErrorType  错误类型[0-插件；1-交易；2-行情；3-策略]
  * @return 错误信息
  */
  char* GetLastError(short nErrorType);
  /**
  * 同步服务器的时间差
  * @param[in] llDiffentSever 和服务器的时间差,毫秒数
  * @return
  */
  void SetSvrDiffrent(__int64 llDiffentSever);
  /**
  * 初始化插件
  * @param[in] pInitInfo 操作员用户名密码
  * @param[in] nThreads 线程池的线程数
  * @param[in] pszLogName  日志文件前缀
  * @param[in] pszAlgoName  需要授权码的产品名称
  * @return 初始化插件成功或失败
  */
  int InitPlugin(PST_tagInitInfo pInitInfo, int nThreads = 1, char* pszLogName = "", char* pszAlgoName = OEM_PRODUCT_NAME);
  /**
  * KSMMApi是否已连接
  * @return 成功或失败
  */
  BOOL GetConncet() { return m_bConnect; }
  /**
  * 初始化插件(无config.ini)
  * @param[in] pInitInfo 操作员用户名密码
  * @param[in] tagKcbpConfig KCBP通讯设置
  * @param[in] nThreads 线程池的线程数
  * @param[in] pszLogName  日志文件前缀
  * @param[in] pszAlgoName  需要授权码的产品名称
  * @param[in] bLogOpenFlag 普通信息是否写入日志文件
  * @return 初始化插件成功或失败
  */
  int InitPlugin(PST_tagInitInfo pInitInfo, ST_tagKCBP_CONFIG& tagKcbpConfig, int nThreads = 1, char* pszLogName = "", char* pszAlgoName = OEM_PRODUCT_NAME, BOOL bLogOpenFlag = FALSE); //fengwc alter 7.27
  /**
  * 获取可操作股票
  * @param[out] pCodeInfo 可操作的股票信息[这部分内存由系统回收，请勿删除]
  * @param[out] nCodeItems 可操作股票数量
  * @return 获取可操作股票成功或失败
  */
  int InitAlgo(ASSET_CODE** pCodeInfo, int& nCodeItems);

  // Add by chenmu 2015-1-22 10:30 获取服务器时间
  /**
  * 获取服务器时间，此调用为同步调用，建议在InitAlgo后调用（和本地时间比较，计算出时间差），勿与其它异步调用混用。
  * @param[out] nDate 服务器日期
  * @param[out] nTime 服务器时间
  * @return 获取服务器时间成功或失败
  */
  int GetSvrTime(int& nDate, int& nTime);
  // Add by chenmu 2015-1-22 Over

  /**
  * 关闭算法
  */
  void Close();

  /**
  * 行情配置
  * @param[in] nHQErrorNum 行情出错次数
  * @return 配置成功或失败
  */
  bool SetHQErrorNum(int nHQErrorNum);

  /**
  * 间隔时间配置
  * @param[in] nTickTime 行情轮询间隔
  * @param[in] nOrderTime 委托轮询间隔
  * @param[in] nConnectTime KCBP连接轮询间隔
  * @return 配置成功或失败
  */
  bool SetConfigTime(int nTickTime, int nOrderTime, int nConnectTime = 10000);

  /**
  * 设置提速版批量查询多支股票的相关请求,每次查询的股票数
  * @param[in] nCodeItems 每次查询的股票数
  * @return 配置成功或失败
  */
  bool SetCodeItems(int nCodeItems);
  /**************************fengwc alter 1.18提速版函数*****************************/
  /**
  * 得到授权码剩余天数
  * @return 授权码剩余天数
  */
  int GetOemDay() { return m_iOemValidDays; }

  /**
  * 订阅股票行情
  * @param[in] pCode 股票代码
  * @return 调用LBM成功或失败
  */
  int SubScribe_Codes(char* pCode);
  int UnSubScribe_Codes(char* pCode);
  ////////////////////////////提速版API接口///////////////////////////////////////////////////
  /**
  * 设置获取多支做市股票的行情回调函数
  * @param[in] nHandle 句柄
  * @param[in] pNQTickFun 普通行情回调函数
  * @param[in] pZSTickFun 做市行情回调函数
  */
  void SetCallBackHQCodesFunction(HWND hWnd, CALLBACK_NQHQ_CODES pNQTickFun, CALLBACK_ZSHQ_CODES pZSTickFun);
  /**
  * 设置获取持仓表股票信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 业务模块获取持仓表股票信息回调函数
  */
  void SetCallBackAssetShareFunction(HWND hWnd, CALLBACK_ASSETSHARE pFun);
  /**
  * 设置查询合笔持仓成本信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 业务模块获取持仓表股票信息回调函数
  */
  void SetCallBackInvStkBcostRltFunction(HWND hWnd, CALLBACK_INVSTKBCOSTRLT pFun);
  /**
  * 设置获取多支做市股票的委托明细回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 委托明细回调函数
  */
  void SetCallBackQuoteCodesFunction(HWND hWnd, CALLBACK_QUOTE_CODES pFun);

  /**
  * 设置获取多支做市股票的风险查询回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 风险查询回调函数
  */
  void SetCallBackRiskInfoCodesFunction(HWND hWnd, CALLBACK_RISKINFO_CODES pFun);

  /**
  * 获取当前交易员汇总的资产单元资金、市值，系统业务切换标志，闭市标志定股票的做市行情信息
  * @param[in] nHandle 句柄
  * @param[in] pFun 当前交易员汇总的资产单元资金、市值，系统业务回调函数
  */
  void SetCallBackAcctInfoFunction(HWND hWnd, CALLBACK_ACCTINFO pFun);

  /**
  * 设置多支做市股票的报价时长回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 报价时长回调函数
  */
  void SetCallBackNqContRecsCodesFunction(HWND hWnd, CALLBACK_NQCONTRECS_CODES pFun);
  /**
  * 设置多支做市股票的可撤单信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 可撤单信息回调函数
  */
  void SetCallBackWithdrawOrderCodesFunction(HWND hWnd, CALLBACK_WITHDRAWORDER_CODES pFun);
  /**
  * 设置获取多支做市股票的成交明细信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 成交明细信息回调函数
  */
  void SetCallBackMatchInfoCodesFunction(HWND hWnd, CALLBACK_MATCHINFO_CODES pFun);
  /**
  * 设置获取多支做市股票的昨日报价查询信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 昨日报价查询信息回调函数
  */
  void SetCallBackCallHisLastQuoteCodesFunction(HWND hWnd, CALLBACK_HISLASTQUOTE_CODES pFun);
  /************************************************************************************/

private:
  /******************************fengwc alter 1.18提速版相关函数***************************/
  /**
  * 入参为股票列表的指令加入指令队列 提速版相关函数
  * @param[in] pszLBMNum LBM编号
  * @param[in] pStkCodeList 股票代码集合
  * @return 0:加入指令队列成功。非0:加入指令队列失败
  */
  int PushLbm_Codes(const char* pszLBMNum, char* pStkCodeList);

  /**加入指令队列
  * @param[in] pszLBMNum LBM编号 提速版相关函数
  * @param[in] mapLBMInput 入参
  * @param[in, out] Node LBM编号
  * @return 0:加入指令队列成功。非0:加入指令队列失败
  */
  int PushLbm_Acce(const char* pszLBMNum, map<string, string>& mapLBMInput, CLBMNode& Node);

  /**获取LBM结果集 提速版相关函数
  * @param[in] hKcbpHandle  KCBP连接
  * @param[in] pNode LBM结点
  * @param[in] pszKey 输出索引字段
  * @return 错误码。如果为0，表示有数据返回
  */
  int InvokeLBM_Acce(KCBPCLIHANDLE hKcbpHandle, CLBMNode* pNode, const char* pszKey);

  /**获取M*N*L结果集的LBM数据 提速版相关函数
  * @param[in] hKcbpHandle  KCBP连接
  * @param[in] pNode LBM结点
  * @param[in] pszKey 输出索引字段
  * @return 错误码。如果为0，表示有数据返回
  */
  int InvokeLBM_More_Acce(KCBPCLIHANDLE hKcbpHandle, CLBMNode* pNode, const char* pszKey);

  /**定时查询普通行情 提速版相关函数
  * @return
  */
  void GetNQTick_Codes();
  /**定时查询做市行情 提速版相关函数
  * @return
  */
  void GetZSTick_Codes();

  /************************************************************************/
  /**连接KCBP
  * @param[in,out] hKCBPHandle  KCBP连接
  * @return 错误码。如果为0，表示有数据返回
  */
  int GetConfigInfo(KCBPCLIHANDLE& hKCBPHandle);
  /**连接KCBP
  * @param[in,out] hKCBPHandle  KCBP连接
  * @param[in] tagKcbpConfig  连接信息，包括IP,端口，服务名，操作员及密码等
  * @param[in,out] bReConnect  当前操作是否是重连
  * @return 错误码。如果为0，表示有数据返回
  */
  int GetConfigInfo(KCBPCLIHANDLE& hKCBPHandle, ST_tagKCBP_CONFIG& tagKcbpConfig, BOOL bReConnect = FALSE); ////fengwc alter 7.27
  /**断线重连KCBP
  * @param[in,out] hKCBPHandle  KCBP连接
  * @param[in] tagKcbpConfig  连接信息，包括IP,端口，服务名，操作员及密码等
  * @param[in] nIndex  线程池中第几个线程
  */
  int ReGetConfigInfo(KCBPCLIHANDLE& hKCBPHandle, ST_tagKCBP_CONFIG tagKcbpConfig, int nIndex = 0);
  /**线程池的每个线程中的KCBP句柄连接
  * @param[in,out] hKCBPHandle  KCBP连接
  * @return 错误码。
  */
  int Connect_ThreadItem(ST_tagKCBP_CONFIG tagKcbpConfig);
  /**线程池KCBP句柄连接
  * @param[in] nThreads  线程池中第几个线程
  * @param[in] tagKcbpConfig  连接信息，包括IP,端口，服务名，操作员及密码等
  * @return 错误码。
  */
  int Connect_ThreadPool(int nThreads, ST_tagKCBP_CONFIG tagKcbpConfig);
  /**判断是否有断开的连接
  * @return 是否有断开的连接
  */
  BOOL CheckConnectStatus();
  /**得到连接数
  * @return 已连接的KCBP句柄
  */
  int GetConnectNum();
  /**关闭所有连接
  * @return 错误码。
  */
  int CloseAllConnect();
  /**测试连接
  * @param[in,out] hKCBPHandle  KCBP连接
  * @return 错误码。
  */
  int TestConnect(KCBPCLIHANDLE hKCBPHandle);
  /**重新连接所有已断开的连接
  * @return
  */
  void ReAllConnect();
  /**连接KCBP
  * @param[in] hKCBPHandle  KCBP连接
  * @param[in] llUserCode  操作员
  * @param[in] pszPassWord  密码
  * @return 错误码。如果为0，表示有数据返回
  */
  int UserLoginIn(KCBPCLIHANDLE hKCBPHandle, long long llUserCode, char* pszPassWord);

  int GetLBMErrorInfo(KCBPCLIHANDLE hKCBPHandle, bool bFetch);
  /**
  * 设置普通行情Tick
  * @param[out] pTick 返回行情TICK
  * @param[in] pNQList 普通行情信息
  * @return 行情是否有变化
  */
  bool SetTick(STK_NQ_TICK* pTick, ST_NQ_MDINFO* pNQList);
  /**
  * 设置做市/投资行情Tick
  * @param[out] pTick 返回行情TICK
  * @param[in] pMMList 做市/投资行情信息
  * @param[in] nTickItem TICK数量
  * @return 行情是否有变化
  */
  bool SetTick(STK_NQ_ZSXX* pTick, ST_MM_DISH10_INFO* pMMList, int nTickItem);

  /**
  * 轮询工作线程
  * @param[in] arg  主线程指针
  */
  static THREAD_RET_T workerThread(void* arg);

  /**
  * 加入订单队列
  * @param[in] pOrderID 委托合同序号
  * @param[in] pszOrderType 委托类型
  * @return 返回成功或失败
  */
  int SubOrder(char* pOrderID, char* pszOrderType);

  /**
  * 退出订单队列
  * @param[in] pOrderID 委托合同序号
  * @return 返回成功或失败
  */
  int UnSubOrder(char* pOrderID);
  /**
  * 获得委托回报
  * @param[in] pOrder 委托信息
  * @return 返回成功或失败
  */
  int GetOrder(ORDER_INFO* pOrder);
  /**
  * 加入请求队列
  * @param[in] LBM 请求信息
  * @param[in] bImport true高优先级；false低优先级
  * @return 返回成功或失败
  */
  void AddRequestList(CLBMNode LBM, BOOL bImport);

  /**
  * LBM应答信息获取
  * @param[in] hKCBPHandle  KCBP连接
  * @param[in] pNode 队列节点
  * @return 返回成功或失败
  */
  int GetLBMResult(CLBMNode* pNode, KCBPCLIHANDLE hKcbpHandle);

  /** L3012008结果应答处理 */
  int Get_L3012008(KCBPCLIHANDLE hKcbpHandle);
  /** L3012001结果应答处理 */
  int Get_L3012001(KCBPCLIHANDLE hKcbpHandle);
  /** L3012002结果应答处理 */
  int Get_L3012002(KCBPCLIHANDLE hKcbpHandle);
  /** L3010001结果应答处理 */
  int Get_L3010001(KCBPCLIHANDLE hKcbpHandle);
  /** L3010002结果应答处理 */
  int Get_L3010002(KCBPCLIHANDLE hKcbpHandle);
  /** L3013001结果应答处理 */
  int Get_L3013001(KCBPCLIHANDLE hKcbpHandle);
  /** L3013007结果应答处理 */
  int Get_L3013007(KCBPCLIHANDLE hKcbpHandle);
  // Add by chenmu 2015-7-27 17:20 按成交编号查询成交明细
  /** L3013010结果应答处理 */
  int Get_L3013010(KCBPCLIHANDLE hKcbpHandle);
  // End Add
  /** L3013011结果应答处理 */
  // Mod by chenmu 2015-7-29 17:00 增加用户自定义入参
  int Set_L3013011(KCBPCLIHANDLE hKcbpHandle, char* pStkCode, char* pUserDefine = NULL);
  // End Mod
  /** L3013013结果应答处理 */
  int Set_L3013013(KCBPCLIHANDLE hKcbpHandle, char* pOrderID);
  //!< fengweican alter 2.28 增加大宗交易处理
  int Get_L3010087(KCBPCLIHANDLE hKcbpHandle, CLBMNode* pNode);
  int Get_L3010088(KCBPCLIHANDLE hKcbpHandle, CLBMNode* pNode);
  int Get_L3014001(KCBPCLIHANDLE hKCBPHandle, CLBMNode* pNode);
  /** L3013003结果应答处理 */
  int Get_L3013003(KCBPCLIHANDLE hKcbpHandle, char* pOrderID);
  //!< fengweican alter 5.5 增加自营股票处理
  /** L3013014结果应答处理 */
  int Set_L3013014(KCBPCLIHANDLE hKcbpHandle, char* pStkCode, char* pUserDefine = NULL);
  /** L3013018结果应答处理 */
  int Get_L3013018(KCBPCLIHANDLE hKcbpHandle);
  /** L3013020结果应答处理 */
  int Get_L3013020(KCBPCLIHANDLE hKcbpHandle);
public:
  /**
  * 获取股票基本信息
  * @param[in] szStkCode 股票代码
  * @return 调用LBM成功或失败
  */
  int GetNQInfo(char* pStkCode);
  /**
  * 请求普通行情（异步模式）
  * @param[in] pStkCode 股票代码
  */
  void GetNQTick(char* pStkCode);
  /**
  * 请求做市行情（异步模式）
  * @param[in] pStkCode 股票代码
  */
  void GetZSTick(char* pStkCode);
  /**
  * 设置行情回调函数
  * @param[in] nHandle 句柄
  * @param[in] pNQTickFun 普通行情回调函数
  * @param[in] pZSTickFun 做市行情回调函数
  */
  void SetCallBackHQFunction(HWND hWnd, CALLBACK_NQHQ pNQTickFun, CALLBACK_ZSHQ pZSTickFun);
  /**
  * 设置委托回调函数
  * @param[in] nHandle 句柄
  * @param[in] pOrderFun 委托回调函数
  * @param[in] pTradeFun 成交回调函数
  */
  void SetCallBackWTFunction(HWND hWnd, CALLBACK_ORDER pOrderFun, CALLBACK_MATCH pTradeFun);
  /**
  * 设置策略主线程退出回调函数
  * @param[in] nHandle 句柄
  * @param[in] pTickErrorFun 行情获取失败超限回调函数
  * @param[in] pMainTreadStopFun 主线程停止回调函数
  */
  void SetCallBackMainThread(HWND hWnd, CALLBACKFUN pTickErrorFun, CALLBACKFUN pMainTreadStopFun);
  /**
  * 设置LBM错误回调函数
  * @param[in] nHandle 句柄
  * @param[in] pLBMErrorFun LBM错误回调函数
  */
  void SetCallBackLBMError(HWND hWnd, CALLBACK_ERROR pLBMErrorFun);
  /**
  * 设置股票基础应答数据回调函数
  * @param[in] nHandle 句柄
  * @param[in] pNQInfoFun 股票基础信息回调函数
  */
  void SetCallBackNQInfo(HWND hWnd, CALLBACK_NQINFO pNQInfoFun);
  /**
  * 设置资金应答数据回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFundFun 资金应答回调函数
  */
  void SetCallBackFund(HWND hWnd, CALLBACK_FUND pFundFun);
  /**
  * 设置持仓应答数据回调函数
  * @param[in] nHandle 句柄
  * @param[in] pShareFun 持仓应答回调函数
  */
  void SetCallBackShare(HWND hWnd, CALLBACK_SHARE pShareFun);
  /**
  * 设置双边报价回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteFun 双边报价回调函数
  */
  void SetCallBackQuote(HWND hWnd, CALLBACK_QUOTE pQuoteFun);

  /**
  * 设置撤单回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 撤单回调函数
  */
  void SetCallBackCancelQuote(HWND hWnd, CALLBACK_CANCELQUOTE pFun);
  /**
  * 设置做市委托明细应答数据回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteFun 委托明细回调函数
  */
  void SetCallBackQuoteList(HWND hWnd, CALLBACK_QUOTELIST pQuoteFun);
  /**
  * 设置做市成交明细明细应答数据回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteMatchFun 成交明细回调函数
  */
  void SetCallBackQuoteMatchList(HWND hWnd, CALLBACK_QUOTEMATCH pQuoteMatchFun);
  //!< fengweican alter 2.28 增加大宗交易处理
  /**
  * 设置批量转移证券资产回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 撤单回调函数
  */
  void SetCallBackMovePosBatch(HWND hWnd, CALLBACK_MOVEPOSBATCH pFun);
  /**
  * 设置批量修改证券组合限额回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteFun 委托明细回调函数
  */
  void SetCallBackCombiLmtInfoBatch(HWND hWnd, CALLBACK_COMBILMTINFOBATCH pFun);
  /**
  * 设置查询资产单元的证券组合回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 查询资产单元的证券组合回调函数
  */
  void SetCallBackListCombiInfo(HWND hWnd, CALLBACK_LISTCOMBIINFO pFun);
  /**
  * 订阅股票行情
  * @param[in] pCode 股票代码
  * @return 调用LBM成功或失败
  */
  int SubScribe(char* pCode);
  /**
  * 退订股票行情
  * @param[in] pCode 股票代码
  * @return 调用LBM成功或失败
  */
  int UnSubScribe(char* pCode);
  /**
  * 获取股票普通行情
  * @param[in] pCode 股票代码
  * @return 行情信息
  */
  STK_NQ_TICK* GetNQTickInfo(char* pCode);
  /**
  * 获取股票做市行情
  * @param[in] pCode 股票代码
  * @return 行情信息
  */
  STK_NQ_ZSXX* GetZSTickInfo(char* pCode);
  /**
  * 获取委托信息
  * @param[in] pOrderID 委托合同序号
  * @return 委托信息
  */
  ORDER_INFO* GetOrder(char* pOrderID);
  /**
  * 取操作员的资金
  * @param[in] nAssetID 资产单元ID(0-表示当前用户的所有资产单元)
  * @return 调用LBM成功或失败
  */
  int GetFunds(int nAssetID);

  /**
  * 取操作员的持仓
  * @param[in] nAssetID 资产单元ID(0-表示当前用户的所有资产单元)
  * @param[in] bZero 是否返回持仓为0的记录
  * @return 调用LBM成功或失败
  */
  int GetShare(int nAssetID, BOOL bZero, char* pStkCode);

  /**
  * 做市交易报单
  * @param[in] pQuoteInfo 报价信息
  * @return 调用LBM成功或失败
  */
  int Quote(QUOTE_INFO* pQuoteInfo);

  /**
  * 做市策略交易报单
  * @param[in] pAlgoQuoteInfo 报价信息
  * @return 调用LBM成功或失败
  */
  int AlgoQuote(ALGOQUOTE_INFO* pAlgoQuoteInfo);
  /**
  * 做市撤单申报
  * @param[in] pOrderID 委托合同序号
  * @param[in] chOrderType 委托类型
  * @return 调用LBM成功或失败
  */
  int CancelOrder(char* pOrderID, char chOrderType);

  /**
  * 做市撤单申报(用于重新登录后的撤单) fengwc alter 9.16
  * @param[in] pOrderID 委托合同序号
  * @param[in] chOrderType 委托类型
  * @return 调用LBM成功或失败
  */
  int CancelOldOrder(char* pOrderID, char chOrderType);
  /**
  * 成交回报
  * @param[in] pOrderID 委托合同序号
  * @return 返回成交回报信息
  */
  QUOTE_MATCH_INFO* GetTrade(char* pOrderID);
  /**
  * 查询单支做市股票的委托明细
  * @param[in] pOrderSearch 委托查询条件
  * @return 调用LBM成功或失败
  */
  int List_Quote(ORDER_SEARCH OrderSearch);

  /**
  * 按时间段查询单支做市股票的成交明细
  * @param[in] MatchSearch 委托查询条件
  * @return 调用LBM成功或失败
  */
  int List_QuoteMatch(ORDER_SEARCH MatchSearch);

  // Add by chenmu 2015-7-27 17:00 按成交编号查询成交明细
  /**
  * 按成交编号查询单支做市股票的成交明细（此函数只适用于KSMM交易柜台v1.1.0.0及以上版本，且不可同时调用List_QuoteMatch）
  * @param[in] MatchSearch 成交查询条件
  * @return 调用LBM成功或失败
  */
  int List_NewMatch(MATCH_SEARCHE MatchSearch);
  // End Add

  /**
  * 获取策略基本信息
  * @param[out] pAlgoBaseInfo 基本策略信息
  * @param[out] nAlgoBaseItems 基本策略个数
  * @return 调用LBM成功或失败
  */
  int GetAlgoBaseInfo(ALGO_BASEINFO** pAlgoBaseInfo, int& nAlgoBaseItems);

  /**
  * 获取策略信息
  * @param[in] nAssetID 资产单元ID
  * @param[out] pAlgoInfo 策略信息
  * @param[out] nAlgoItems 策略个数
  * @return 调用LBM成功或失败
  */
  int GetAlgoInfo(int nAssetID, ALGO_INFO** pAlgoInfo, int& nAlgoItems);

  /**
  * 获取策略参数信息
  * @param[in] nAlgoID 策略ID
  * @param[out] pAlgoParam 策略参数信息
  * @param[out] nAlgoParamItems 策略参数个数
  * @return 调用LBM成功或失败
  */
  int GetAlgoParamInfo(int nAlgoID, ALGO_INFO_EXT** pAlgoParam, int& nAlgoParamItems);

  //add by zhangshuai
  /**
  * 配置策略状态
  * @param[in] nAlgoID 策略ID
  * @param[in] chAlgoStatus 策略状态
  * @return 调用LBM成功或失败
  */
  int SetAlgoStatus(int nAlgoID, char chAlgoStatus);
  //!< fengweican alter 5.5 增加自营股票处理
  /**
  * 自营股票交易报单
  * @param[in] pQuoteInfo 报价信息
  * @return 调用LBM成功或失败
  */
  int NQWTQuote(NQWTQUOTE_INFO* pQuoteInfo);
  /**
  * 查询单支自营股票的委托明细
  * @param[in] pOrderSearch 委托查询条件
  * @return 调用LBM成功或失败
  */
  int List_NQWTQuote(NQWTORDER_SEARCH OrderSearch);
  /**
  * 查询单支自营股票的成交明细
  * @param[in] MatchSearch 成交查询条件
  * @return 调用LBM成功或失败
  */
  int List_NQWTQuoteMatch(NQWTMATCH_SEARCHE MatchSearch);
  /**
  * 获取多支自营股票的委托明细信息  L3015208
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int GetList_NQWTQuote_Codes(char* pCodeList);

  /**
  * 获取多支自营股票的成交明细信息结果  L3015209
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_NQWTMatchedInfo_Codes(char* pCodeList);
  //!< fengweican alter 2.28 增加大宗交易处理
  /**
  * 集合竞价转让和盘后大宗交易转让
  * @param[in] pQuoteInfo 报价信息
  * @return 调用LBM成功或失败
  */
  int DZQuote(DZQUOTE_INFO* pQuoteInfo);
  /**
  * 批量转移证券资产
  * @param[in] pInfo 证券资产信息
  * @return 调用LBM成功或失败
  */
  int MovePosBatch(ST_MovePosBatch* pInfo);
  /**
  * 批量修改证券组合限额
  * @param[in] szStkCodes 证券代码^持仓限额组合，入参格式如下：证券代码1^持仓限额1|证券代码2^持仓限额2|证券代码3^持仓限额3|……
  * @return 调用LBM成功或失败
  */
  int SetCombiLmtInfoBatch(char* szStkCodes);
  /**
  * 查询资产单元的证券组合
  * @param[in] nAssetID 资产单元ID
  * @param[in] nCombiID 组合ID
  * @param[in] szStkCode 证券代码
  * @return 调用LBM成功或失败
  */
  int GetListCombiInfo(int nAssetID, int nCombiID, char* szStkCode);
  /**
  * 设置获取多支自营股票的委托明细信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 委托明细回调函数
  */
  void SetCallBackNQWTQuoteCodesFunction(HWND hWnd, CALLBACK_NQWTQUOTE_CODES pFun);
  /**
  * 设置获取多支自营股票的成交明细信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 委托明细回调函数
  */
  void SetCallBackNQWTMatchedInfoCodesFunction(HWND hWnd, CALLBACK_NQWTMATCHEDINFO_CODES pFun);
  /**
  * 设置自营股票报价回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteFun 自营股票报价回调函数
  */
  void SetCallBackNQWTQuote(HWND hWnd, CALLBACK_NQWTQUOTE pQuoteFun);
  /**
  * 设置获取单支自营股票的委托明细回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteFun 委托明细回调函数
  */
  void SetCallBackNQWTQuoteList(HWND hWnd, CALLBACK_NQWTQUOTELIST pQuoteFun);
  /**
  * 设置获取单支自营股票的成交明细回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteMatchFun 成交明细回调函数
  */
  void SetCallBackNQWTQuoteMatchList(HWND hWnd, CALLBACK_NQWTQUOTEMATCH pQuoteMatchFun);
  //add end

public:
  int m_nHQErrorCount;              //!< 行情获取失败次数
  int m_nHQErrorMaxNum;             //!< 行情获取失败上限
  int m_nTickTime;                //!< 行情轮询间隔
  int m_nOrderTime;               //!< 委托轮询间隔
  BOOL m_bConnect;                //!< 连接标志
  /***************************fengwc alter 1.18********************************/
private:
  int m_iOemValidDays;
  std::map<string, ST_NQInfo_Codes>* m_pmapNqTick_Codes;    //!< 普通行情数据
  std::map<string, STK_NQ_ZSXX>* m_pmapZsTick_Codes;    //!< 做市行情数据
  LBM_Acce* m_pAcce;
  map<string, vector<string>>* m_pmapOutPutFiled;
  /////////////////////提速版回调函数///////////////////////////////
  CALLBACK_ASSETSHARE  m_AssetShareInfoFun;               // 获取持仓表股票信息
  CALLBACK_INVSTKBCOSTRLT  m_InvStkBcostRltInfoFun;       // 获取合笔持仓成本信息
  CALLBACK_NQHQ_CODES m_NQCodesTickFun;                   // 获取多支做市股票的普通行情、持仓、报价均价信息
  CALLBACK_ZSHQ_CODES m_ZSCodesTickFun;                   // 获取多支做市股票的做市行情
  CALLBACK_QUOTE_CODES m_Quote_CodesFun;                  // 获取多支做市股票的委托明细信息
  CALLBACK_RISKINFO_CODES m_RiskInfo_CodesFun;            // 获取多支做市股票的风险查询信息
  CALLBACK_ACCTINFO m_AcctInfo_CodesFun;                  // 获取当前交易员汇总的资产单元资金、市值，系统业务切换标志，闭市标志定股票的做市行情信息
  CALLBACK_NQCONTRECS_CODES m_NqContRecs_CodesFun;        // 获取多支做市股票的报价时长信息
  CALLBACK_WITHDRAWORDER_CODES m_WithdrawOrder_CodesFun;  // 查询多支做市股票的可撤单信息
  CALLBACK_MATCHINFO_CODES m_MatchInfo_CodesFun;          // 查询多支做市股票的成交明细信息
  CALLBACK_HISLASTQUOTE_CODES m_HisLastQuote_CodesFun;    // 查询多支做市股票的昨日报价查询信息
public:
  /**
  * 获取持仓表股票信息 L3014026
  * @param[in] nAssetID 资产单元ID
  * @param[in] pCode    股票代码
  * @return 调用LBM成功或失败
  */
  int GetAssetShare(int nAssetID, char* pCode);
  /**
  * 获取合笔持仓成本信息
  * @param[in] nAssetID 资产单元ID
  * @param[in] szCodeList    股票代码列表
  * @return 调用LBM成功或失败
  */
  int GetInvStkBcostRlt(int nAssetID, char* szCodeList);
  /**
  * 获取当前交易员汇总的资产单元资金、市值，系统业务切换标志，闭市标志定股票的做市行情 L3015204
  * @param[in] nAssetID 资产单元ID
  * @return 调用LBM成功或失败
  */
  int GetAcctInfo(int nAssetID);
  /**
  * 获取多支做市股票的委托明细信息  L3015202
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_Quote_Codes(char* pCodeList);

  /**
  * 获取多支做市股票的风险信息  L3015203
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_RiskInfo_Codes(char* pCodeList);

  /**
  * 获取多支做市股票的报价时长信息  L3015205
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_NqContRecs_Codes(char* pCodeList);

  /**
  * 获取多支做市股票的可撤单信息  L3015206
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_WithdrawOrder_Codes(char* pCodeList);

  /**
  * 获取多支做市股票的成交明细信息  L3015207
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_QuoteMatch_Codes(char* pCodeList);

  /**
  * 获取多支做市股票的昨日报价查询信息  L3015210
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_HisLastQuote_Codes(char* pCodeList);
  /*****************************************************/
protected:
  CALLBACK_NQHQ m_NQTickFun;                //!< 单支股票的普通行情回调函数
  CALLBACK_ZSHQ m_ZSTickFun;                //!< 单支股票的做市行情回调函数
  CALLBACK_ORDER m_OrderFun;                //!< 委托确认回调函数
  CALLBACK_MATCH m_TradeFun;                //!< 成交确认回调函数
  CALLBACKFUN m_TickErrorFun;               //!< 行情获取失败回调函数
  CALLBACKFUN m_MainThreadStopFun;          //!< 主线程中止回调函数
                                            
  CALLBACK_ERROR m_LBMErrorFun;             //!< LBM错误回调
                                            
  CALLBACK_NQINFO m_NQInfoFun;              //!< 股票基础信息回调
  CALLBACK_FUND m_FundFun;                  //!< 资产单元资金回调
  CALLBACK_SHARE m_ShareFun;                //!< 资产单元持仓回调
  CALLBACK_QUOTE m_QuoteFun;                //!< 双边报价回调
  CALLBACK_CANCELQUOTE m_CancelQuoteFun;    //!< 撤单回调
  CALLBACK_QUOTELIST m_QuoteListFun;        //!< 单支做市股票的委托明细信息回调
  CALLBACK_QUOTEMATCH m_QuoteMatchListFun;  //!< 单支做市股票的成交明细信息回调
  //!< fengweican alter 2.28 增加大宗交易处理
  CALLBACK_MOVEPOSBATCH m_MovePosBatchFun;  //!< 批量转移证券资产回调
  CALLBACK_COMBILMTINFOBATCH m_CombiLmtInfoBatchFun;  //!< 批量转移证券资产回调
  CALLBACK_LISTCOMBIINFO m_ListCombiInfoFun;          //!< 查询资产单元的证券组合
  //add by zhangshuai
  CALLBACK_TRADESUM m_TradeSumFun;        //!< 某日成交汇总信息回调
  //add end

  ST_ASSET* m_pAsset;              //!< 资产单元
  int m_nAssetItems;                //!< 资产单元数量
  //!< fengweican alter 5.5 增加自营股票处理
  CALLBACK_NQWTQUOTE_CODES m_NQWTQuote_CodesFun;        //!< 获取多支自营股票的委托明细信息
  CALLBACK_NQWTMATCHEDINFO_CODES m_NQWTMatchedInfo_CodesFun;  //!< 获取多支自营股票的成交明细信息
  CALLBACK_NQWTQUOTE m_NQWTQuoteFun;              //!< 获取自营股票报价回调函数
  CALLBACK_NQWTQUOTELIST m_NQWTQuoteListFun;          //!< 获取单支自营股票的委托明细信息回调
  CALLBACK_NQWTQUOTEMATCH m_NQWTQuoteMatchListFun;      //!< 获取单支自营股票的成交明细信息回调
private:
  ASSET_CODE* m_pAssetCodeInfo;          //!< 可操作股票信息
  map<string, ASSET_CODE>* m_mapCodeInfo;
  int m_nAssetCodeItems;              //!< 可操作股票数量

  char m_szPlugErrorInfo[LEN_LOG];          //!< 当前错误信息

  THREAD_T mainWorkThread;            //!< 主工作线程句柄

  // Mod by chenmu 2015-7-27
  /*static*/ BOOL isMainWorkThreadRunning;      //!< 主工作线程是否运行中

  CALLBACK_PARAM m_pCallBackParam;        //!< 回调参数
  LBM_CY_Base* m_pCyBase;
  LBM_HQ_Base* m_pHqBase;
  LBM_JY_Base* m_pJyBase;
  LBM_Base* m_pBase;
  vector<Ksmmapi_ThreadPool>* m_pvctThredpool;
private:
  // Add by chenmu 2014-12-19 14:55 增加高优先级请求队列声明
  std::queue<CLBMNode>* queueHighRequest;    //!< 高优先级请求队列
  MUTEX_T HighRequestLock;            //!< 高优先级请求锁

  std::set<string>* set_Low_request;    //!< fengwc alter 1.18 低优先级请求队列lbm名称，资产单元，证券代码，证券代码列表，委托编号set
  std::queue<CLBMNode>* queueLowRequest;   //!< 低优先级请求队列
  MUTEX_T LowRequestLock;             //!< 低优先级请求锁

  HANDLE RequestQueueSignal;            //!< 请求Event句柄

  // Mod by chenmu 2015-7-27 
  /*static*/ BOOL isRequestThreadRunning;       //!< 请求线程是否运行中
  /**
  * 请求队列处理工作线程
  * @param[in] arg  主线程指针
  */
  static THREAD_RET_T processRequestThread(void* arg);
  THREAD_T RequestThread;             //!< 请求线程句柄

  /**
  * 指令请求处理
  * @param[in] nThreadIndex 线程池第几个线程
  * @param[in] hKcbpHandle KCBP连接
  * @param[in] Node 指令内容
  * @return
  */
  void DoRequest(int nThreadIndex, KCBPCLIHANDLE hKcbpHandle, CLBMNode Node);
  /**
  * 线程池回调函数
  * @param[in] Instance 实例
  * @param[in] Context 用户数据
  * @return
  */
  static void __stdcall ThreadPoolCallback(PTP_CALLBACK_INSTANCE Instance, PVOID Context);
  /**
  * 日志处理工作线程
  * @param[in] arg  主线程指针
  */
  static UINT WINAPI processLogThread(void* arg);
  /**
  * 得到可操作的高优先级指令
  * @param[in] nIndex 线程池中第几个线程
  * @param[in,out] Node 需要执行的指令
  * @return
  */
  void GetHighRequestNode(const int nIndex, CLBMNode& Node);
  /**
  * 得到可操作的低优先级指令
  * @param[in] nIndex 线程池中第几个线程
  * @param[in,out] Node 需要执行的指令
  * @return
  */
  void GetLowRequestNode(const int nIndex, CLBMNode& Node);
  /**
  * 删除未成交的失效报单
  * @return
  */
  void DelOrderID(ORDER_INFO Order);
  THREAD_T LogThread;             //!< 日志线程句柄
  /**线程池代码**/
  PTP_POOL m_tPool;
  TP_CALLBACK_ENVIRON m_pcbe;
  /*********************/
  __int64 m_llHighQueueCount, m_llLowQueueCount;
  HANDLE m_hndStop;

  char m_szCloseThread[64];
  std::vector<QUOTE_ORDER_INFO>* queueorder;  //!< 委托回报队列
  MUTEX_T queueorderLock;                     //!< 委托回报锁
  HANDLE OrderQueueSignal;                    //!< 委托Event句柄

  std::vector<QUOTE_MATCH_INFO>* queuetrade;  //!< 成交回报队列
  MUTEX_T queuetradeLock;                     //!< 成交回报锁
  HANDLE TradeQueueSignal;                    //!< 成交Event句柄

  MUTEX_T m_queueorderLock;                   //!< 委托确认锁

  // Del by chenmu 2012-7-27 没有使用
  std::map<string, STK_NQ_TICK>* position_nqtick;   //!< 普通行情数据
  std::map<string, STK_NQ_ZSXX>* position_zstick;   //!< 做市行情数据
  std::map<string, ORDER_INFO>* positionorder;      //!< 委托确认信息

  // fengwc alter 11.5 如果主动撤单后，立即报新单，那么，positionorder的删除和新增可能或同时到达，这时就会发生读写错误
  MUTEX_T HighOrderLock;     //!< 委托确认信息请求锁
  int m_nMainThreadStatus;   //!<主线程连接状态，0--初始化 1--已连接 -1--断开连接
  int m_nMainThreadRet;      //!< 主线程断开连接时错误码
  int m_nThreads;
  ST_tagKCBP_CONFIG* m_pKcxpConfig;
  int m_nConnectTime;        //!< 连接轮询间隔
  PST_tagLbmParam m_pTagLbmParam;
  ST_tagInitInfo  m_stInitInfo;

  BOOL      m_bRequestThreadExitFlag;
  BOOL      m_bMainThreadExitFlag;
};

