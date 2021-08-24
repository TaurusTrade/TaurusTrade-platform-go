/*************************************************
* Copyright (c) 2014,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�LBM_Plugin.h
* ժ    Ҫ��LBM�㷨���
*
* ��ǰ�汾��1.0
* ��    �ߣ�����
* ������ڣ�2014��5��20��
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
/** ����ʱ���� */
#define TICK_TIME 18
/** ί����ѯʱ���� */
#define ORDER_TIME  28
/** ������ѯʱ���� */
#define CONNECT_TIME  38

/** ����LBM��־ */
#define NQ_JY 1
/** ����LBM��־ */
#define NQ_HQ 2
/** ����LBM��־ */
#define NQ_CY 3
/** ��ʷ����LBM��־ */
#define NQ_LSHQ 4
/**�̳߳ش���**/
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
/** �ص����� */
struct CALLBACK_PARAM
{
  void* Plugin;         //!< LBM_Pluginָ��
  void* hCallWnd;       //!< ���÷����
};

/** LBM������Ϣ */
struct LBM_ERROR_INFO
{
  int nAssetID;         //!< �ʲ���ԪID
  char szLBMID[16];       //!< LBM���
  char szStkCode[LEN_CODELIST];       //!< ��Ʊ���� fengwc alter 1.18 �����Ʊ����ռ䣬�÷��¹�Ʊ�����б�
  char szOrderID[36];       //!< ��ͬ���
  char szErrorInfo[255];      //!< ������Ϣ
  // Add by chenmu 2015-8-17 14:30
  char szUserDefine[16 + 1];      //!< �û��Զ���
};

typedef void (*CALLBACKFUN)(CALLBACK_PARAM* pParam, char* pObject);
typedef void (*CALLBACK_NQHQ)(CALLBACK_PARAM* pParam, STK_NQ_TICK* pNQHQInfo);            //!< ��ȡ��֧��Ʊ����ͨ����ص�����
typedef void (*CALLBACK_ZSHQ)(CALLBACK_PARAM* pParam, STK_NQ_ZSXX* pZSHQInfo);            //!< ��ȡ��֧��Ʊ����������ص�����
typedef void (*CALLBACK_ORDER)(CALLBACK_PARAM* pParam, ORDER_INFO* pOrderInfo);           //!< ί��ȷ�ϻص�����
typedef void (*CALLBACK_MATCH)(CALLBACK_PARAM* pParam, MATCH_INFO* pMatchInfo);           //!< �ɽ�ȷ�ϻص�����
typedef void (*CALLBACK_ERROR)(CALLBACK_PARAM* pParam, LBM_ERROR_INFO* pErrorInfo);         //!< LBM����ص�����
typedef void (*CALLBACK_NQINFO)(CALLBACK_PARAM* pParam, STK_NQINFO* pNQInfo, int nItem);        //!< ��ȡ��Ʊ������Ϣ�ص�����
typedef void (*CALLBACK_FUND)(CALLBACK_PARAM* pParam, ASSET_FUND* pFund, int nItem);          //!< ��ȡ�ʲ���Ԫ�ʽ�ص�����
typedef void (*CALLBACK_SHARE)(CALLBACK_PARAM* pParam, ASSET_SHARE* pShare, int nItem);       //!< ��ȡ�ʲ���Ԫ�ֲֻص�����
typedef void (*CALLBACK_QUOTE)(CALLBACK_PARAM* pParam, QUOTE_BACK_INFO* pBackQuote);          //!< ��ȡ˫�߱��ۻص�����
typedef void (*CALLBACK_CANCELQUOTE)(CALLBACK_PARAM* pParam, char* pBackCancelQuote, int nLen);           //!< ��ȡ�����ص�����
typedef void (*CALLBACK_QUOTELIST)(CALLBACK_PARAM* pParam, QUOTE_ORDER_INFO* pQuote, int nItem);    //!< ��ȡ��֧���й�Ʊ��ί����ϸ�ص�����
typedef void (*CALLBACK_QUOTEMATCH)(CALLBACK_PARAM* pParam, QUOTE_MATCH_INFO* pMatch, int nItem);   //!< ��ȡ��֧���й�Ʊ�ĳɽ���ϸ�ص�����
typedef void (*CALLBACK_TRADESUM)(CALLBACK_PARAM* pParam, QUOTE_TRADESUM_INFO* pSumInfo, int nItem);  //!< ĳ�ճɽ�������Ϣ�ص�����

////////****************************fengwc alter 1.18************************************/
typedef void (*CALLBACK_ASSETSHARE)(CALLBACK_PARAM* pParam, ST_AssetShareInfo* pInfo, int nItem);          //!< ��ȡ�ֱֲ��Ʊ��Ϣ�ص�����
typedef void (*CALLBACK_NQHQ_CODES)(CALLBACK_PARAM* pParam, ST_NQInfo_Codes* pNQHQInfo, int nItem);        //!< ��ȡ��֧��Ʊ����ͨ���顢�ֲ֡����۾��ۻص�����
typedef void (*CALLBACK_ZSHQ_CODES)(CALLBACK_PARAM* pParam, STK_NQ_ZSXX* pZSHQInfo, int nItem);          //!< ��ȡ��֧��Ʊ����������ص�����
typedef void (*CALLBACK_QUOTE_CODES)(CALLBACK_PARAM* pParam, ST_Quote_Codes* pInfo, int nItem);          //!< ��ȡ��֧���й�Ʊ��ί����ϸ��Ϣ�ص�����
typedef void (*CALLBACK_RISKINFO_CODES)(CALLBACK_PARAM* pParam, ST_RiskInfo_Codes* pInfo, int nItem);        //!< ��ȡ��֧���й�Ʊ�ķ��ղ�ѯ��Ϣ�ص�����
typedef void (*CALLBACK_ACCTINFO)(CALLBACK_PARAM* pParam, ST_AcctInfo* pInfo, int nItem);              //!< ��ȡ��ǰ����Ա���ܵ��ʲ���Ԫ�ʽ���ֵ��ϵͳҵ���л���־�����б�־����Ʊ������������Ϣ�ص�����
typedef void (*CALLBACK_NQCONTRECS_CODES)(CALLBACK_PARAM* pParam, ST_NqContRecs_Codes* pInfo, int nItem);      //!< ��ȡ��֧���й�Ʊ�ı���ʱ����Ϣ�ص�����
typedef void (*CALLBACK_WITHDRAWORDER_CODES)(CALLBACK_PARAM* pParam, ST_WithdrawOrder_Codes* pInfo, int nItem);  //!< ��ȡ��֧���й�Ʊ�Ŀɳ�����Ϣ�ص�����
typedef void (*CALLBACK_MATCHINFO_CODES)(CALLBACK_PARAM* pParam, ST_MatchInfo_Codes* pInfo, int nItem);      //!< ��ȡ��֧���й�Ʊ�ĳɽ���ϸ��Ϣ�ص�����
typedef void (*CALLBACK_HISLASTQUOTE_CODES)(CALLBACK_PARAM* pParam, QUOTE_ORDER_INFO* pInfo, int nItem);     ///!< ��ȡ��֧���й�Ʊ�����ձ��۲�ѯ��Ϣ�ص�����
typedef void (*CALLBACK_INVSTKBCOSTRLT)(CALLBACK_PARAM* pParam, ST_InvStkBcostRltInfo* pInfo, int nItem);        //!< ��ȡ�ϱʳֲֳɱ���Ϣ�ص�����
/*****************************************************************************************/
//!< fengweican alter 5.5 ������Ӫ��Ʊ����
typedef void (*CALLBACK_NQWTQUOTE)(CALLBACK_PARAM* pParam, NQWTQUOTE_BACK_INFO* pBackQuote);            //!< ��Ӫ��Ʊ���ۻص�����
typedef void (*CALLBACK_NQWTQUOTELIST)(CALLBACK_PARAM* pParam, NQWTQUOTE_ORDER_INFO* pQuote, int nItem);      //!< ��ȡ��֧��Ӫ��Ʊ��ί����ϸ
typedef void (*CALLBACK_NQWTQUOTEMATCH)(CALLBACK_PARAM* pParam, NQWTQUOTE_MATCH_INFO* pMatch, int nItem);     //!< ��ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ��Ϣ
typedef void (*CALLBACK_NQWTQUOTE_CODES)(CALLBACK_PARAM* pParam, ST_NQWTQuote_Codes* pInfo, int nItem);      //!< ��ȡ��֧��Ӫ��Ʊ��ί����ϸ��Ϣ
typedef void (*CALLBACK_NQWTMATCHEDINFO_CODES)(CALLBACK_PARAM* pParam, ST_NQWTMatchedInfo_Codes* pInfo, int nItem);//!< ��ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ��Ϣ
//!< fengweican alter 2.28 ���Ӵ��ڽ��״���
typedef void (*CALLBACK_MOVEPOSBATCH)(CALLBACK_PARAM* pParam, ST_MovePosBatch* pInfo, int nItem);            //!< ��ȡ�����ص�����
typedef void (*CALLBACK_COMBILMTINFOBATCH)(CALLBACK_PARAM* pParam, char* pBackCancelQuote, int nLen);           //!< ��ȡ�����ص�����
typedef void (*CALLBACK_LISTCOMBIINFO)(CALLBACK_PARAM* pParam, ST_ASSET_CODE_INFO* pInfo, int nItem);            //!< ��ȡ�����ص�����
/**
* @defgroup AlgoPlug�㷨���ģ��
* �����㷨API
* @author ����
* @version 1.0
* @date 2013-2014
* @{
*/

/**
* @ingroup AlgoPlug
* @brief �㷨API���
*/
class __declspec(dllexport) LBM_Plugin
{
public:
  LBM_Plugin(void);
  ~LBM_Plugin(void);

  /**
  * ��ȡ������Ϣ
  * @param[in] nErrorType  ��������[0-�����1-���ף�2-���飻3-����]
  * @return ������Ϣ
  */
  char* GetLastError(short nErrorType);
  /**
  * ͬ����������ʱ���
  * @param[in] llDiffentSever �ͷ�������ʱ���,������
  * @return
  */
  void SetSvrDiffrent(__int64 llDiffentSever);
  /**
  * ��ʼ�����
  * @param[in] pInitInfo ����Ա�û�������
  * @param[in] nThreads �̳߳ص��߳���
  * @param[in] pszLogName  ��־�ļ�ǰ׺
  * @param[in] pszAlgoName  ��Ҫ��Ȩ��Ĳ�Ʒ����
  * @return ��ʼ������ɹ���ʧ��
  */
  int InitPlugin(PST_tagInitInfo pInitInfo, int nThreads = 1, char* pszLogName = "", char* pszAlgoName = OEM_PRODUCT_NAME);
  /**
  * KSMMApi�Ƿ�������
  * @return �ɹ���ʧ��
  */
  BOOL GetConncet() { return m_bConnect; }
  /**
  * ��ʼ�����(��config.ini)
  * @param[in] pInitInfo ����Ա�û�������
  * @param[in] tagKcbpConfig KCBPͨѶ����
  * @param[in] nThreads �̳߳ص��߳���
  * @param[in] pszLogName  ��־�ļ�ǰ׺
  * @param[in] pszAlgoName  ��Ҫ��Ȩ��Ĳ�Ʒ����
  * @param[in] bLogOpenFlag ��ͨ��Ϣ�Ƿ�д����־�ļ�
  * @return ��ʼ������ɹ���ʧ��
  */
  int InitPlugin(PST_tagInitInfo pInitInfo, ST_tagKCBP_CONFIG& tagKcbpConfig, int nThreads = 1, char* pszLogName = "", char* pszAlgoName = OEM_PRODUCT_NAME, BOOL bLogOpenFlag = FALSE); //fengwc alter 7.27
  /**
  * ��ȡ�ɲ�����Ʊ
  * @param[out] pCodeInfo �ɲ����Ĺ�Ʊ��Ϣ[�ⲿ���ڴ���ϵͳ���գ�����ɾ��]
  * @param[out] nCodeItems �ɲ�����Ʊ����
  * @return ��ȡ�ɲ�����Ʊ�ɹ���ʧ��
  */
  int InitAlgo(ASSET_CODE** pCodeInfo, int& nCodeItems);

  // Add by chenmu 2015-1-22 10:30 ��ȡ������ʱ��
  /**
  * ��ȡ������ʱ�䣬�˵���Ϊͬ�����ã�������InitAlgo����ã��ͱ���ʱ��Ƚϣ������ʱ�������������첽���û��á�
  * @param[out] nDate ����������
  * @param[out] nTime ������ʱ��
  * @return ��ȡ������ʱ��ɹ���ʧ��
  */
  int GetSvrTime(int& nDate, int& nTime);
  // Add by chenmu 2015-1-22 Over

  /**
  * �ر��㷨
  */
  void Close();

  /**
  * ��������
  * @param[in] nHQErrorNum ����������
  * @return ���óɹ���ʧ��
  */
  bool SetHQErrorNum(int nHQErrorNum);

  /**
  * ���ʱ������
  * @param[in] nTickTime ������ѯ���
  * @param[in] nOrderTime ί����ѯ���
  * @param[in] nConnectTime KCBP������ѯ���
  * @return ���óɹ���ʧ��
  */
  bool SetConfigTime(int nTickTime, int nOrderTime, int nConnectTime = 10000);

  /**
  * �������ٰ�������ѯ��֧��Ʊ���������,ÿ�β�ѯ�Ĺ�Ʊ��
  * @param[in] nCodeItems ÿ�β�ѯ�Ĺ�Ʊ��
  * @return ���óɹ���ʧ��
  */
  bool SetCodeItems(int nCodeItems);
  /**************************fengwc alter 1.18���ٰ溯��*****************************/
  /**
  * �õ���Ȩ��ʣ������
  * @return ��Ȩ��ʣ������
  */
  int GetOemDay() { return m_iOemValidDays; }

  /**
  * ���Ĺ�Ʊ����
  * @param[in] pCode ��Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int SubScribe_Codes(char* pCode);
  int UnSubScribe_Codes(char* pCode);
  ////////////////////////////���ٰ�API�ӿ�///////////////////////////////////////////////////
  /**
  * ���û�ȡ��֧���й�Ʊ������ص�����
  * @param[in] nHandle ���
  * @param[in] pNQTickFun ��ͨ����ص�����
  * @param[in] pZSTickFun ��������ص�����
  */
  void SetCallBackHQCodesFunction(HWND hWnd, CALLBACK_NQHQ_CODES pNQTickFun, CALLBACK_ZSHQ_CODES pZSTickFun);
  /**
  * ���û�ȡ�ֱֲ��Ʊ��Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ҵ��ģ���ȡ�ֱֲ��Ʊ��Ϣ�ص�����
  */
  void SetCallBackAssetShareFunction(HWND hWnd, CALLBACK_ASSETSHARE pFun);
  /**
  * ���ò�ѯ�ϱʳֲֳɱ���Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ҵ��ģ���ȡ�ֱֲ��Ʊ��Ϣ�ص�����
  */
  void SetCallBackInvStkBcostRltFunction(HWND hWnd, CALLBACK_INVSTKBCOSTRLT pFun);
  /**
  * ���û�ȡ��֧���й�Ʊ��ί����ϸ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ί����ϸ�ص�����
  */
  void SetCallBackQuoteCodesFunction(HWND hWnd, CALLBACK_QUOTE_CODES pFun);

  /**
  * ���û�ȡ��֧���й�Ʊ�ķ��ղ�ѯ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ���ղ�ѯ�ص�����
  */
  void SetCallBackRiskInfoCodesFunction(HWND hWnd, CALLBACK_RISKINFO_CODES pFun);

  /**
  * ��ȡ��ǰ����Ա���ܵ��ʲ���Ԫ�ʽ���ֵ��ϵͳҵ���л���־�����б�־����Ʊ������������Ϣ
  * @param[in] nHandle ���
  * @param[in] pFun ��ǰ����Ա���ܵ��ʲ���Ԫ�ʽ���ֵ��ϵͳҵ��ص�����
  */
  void SetCallBackAcctInfoFunction(HWND hWnd, CALLBACK_ACCTINFO pFun);

  /**
  * ���ö�֧���й�Ʊ�ı���ʱ���ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ����ʱ���ص�����
  */
  void SetCallBackNqContRecsCodesFunction(HWND hWnd, CALLBACK_NQCONTRECS_CODES pFun);
  /**
  * ���ö�֧���й�Ʊ�Ŀɳ�����Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun �ɳ�����Ϣ�ص�����
  */
  void SetCallBackWithdrawOrderCodesFunction(HWND hWnd, CALLBACK_WITHDRAWORDER_CODES pFun);
  /**
  * ���û�ȡ��֧���й�Ʊ�ĳɽ���ϸ��Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun �ɽ���ϸ��Ϣ�ص�����
  */
  void SetCallBackMatchInfoCodesFunction(HWND hWnd, CALLBACK_MATCHINFO_CODES pFun);
  /**
  * ���û�ȡ��֧���й�Ʊ�����ձ��۲�ѯ��Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ���ձ��۲�ѯ��Ϣ�ص�����
  */
  void SetCallBackCallHisLastQuoteCodesFunction(HWND hWnd, CALLBACK_HISLASTQUOTE_CODES pFun);
  /************************************************************************************/

private:
  /******************************fengwc alter 1.18���ٰ���غ���***************************/
  /**
  * ���Ϊ��Ʊ�б��ָ�����ָ����� ���ٰ���غ���
  * @param[in] pszLBMNum LBM���
  * @param[in] pStkCodeList ��Ʊ���뼯��
  * @return 0:����ָ����гɹ�����0:����ָ�����ʧ��
  */
  int PushLbm_Codes(const char* pszLBMNum, char* pStkCodeList);

  /**����ָ�����
  * @param[in] pszLBMNum LBM��� ���ٰ���غ���
  * @param[in] mapLBMInput ���
  * @param[in, out] Node LBM���
  * @return 0:����ָ����гɹ�����0:����ָ�����ʧ��
  */
  int PushLbm_Acce(const char* pszLBMNum, map<string, string>& mapLBMInput, CLBMNode& Node);

  /**��ȡLBM����� ���ٰ���غ���
  * @param[in] hKcbpHandle  KCBP����
  * @param[in] pNode LBM���
  * @param[in] pszKey ��������ֶ�
  * @return �����롣���Ϊ0����ʾ�����ݷ���
  */
  int InvokeLBM_Acce(KCBPCLIHANDLE hKcbpHandle, CLBMNode* pNode, const char* pszKey);

  /**��ȡM*N*L�������LBM���� ���ٰ���غ���
  * @param[in] hKcbpHandle  KCBP����
  * @param[in] pNode LBM���
  * @param[in] pszKey ��������ֶ�
  * @return �����롣���Ϊ0����ʾ�����ݷ���
  */
  int InvokeLBM_More_Acce(KCBPCLIHANDLE hKcbpHandle, CLBMNode* pNode, const char* pszKey);

  /**��ʱ��ѯ��ͨ���� ���ٰ���غ���
  * @return
  */
  void GetNQTick_Codes();
  /**��ʱ��ѯ�������� ���ٰ���غ���
  * @return
  */
  void GetZSTick_Codes();

  /************************************************************************/
  /**����KCBP
  * @param[in,out] hKCBPHandle  KCBP����
  * @return �����롣���Ϊ0����ʾ�����ݷ���
  */
  int GetConfigInfo(KCBPCLIHANDLE& hKCBPHandle);
  /**����KCBP
  * @param[in,out] hKCBPHandle  KCBP����
  * @param[in] tagKcbpConfig  ������Ϣ������IP,�˿ڣ�������������Ա�������
  * @param[in,out] bReConnect  ��ǰ�����Ƿ�������
  * @return �����롣���Ϊ0����ʾ�����ݷ���
  */
  int GetConfigInfo(KCBPCLIHANDLE& hKCBPHandle, ST_tagKCBP_CONFIG& tagKcbpConfig, BOOL bReConnect = FALSE); ////fengwc alter 7.27
  /**��������KCBP
  * @param[in,out] hKCBPHandle  KCBP����
  * @param[in] tagKcbpConfig  ������Ϣ������IP,�˿ڣ�������������Ա�������
  * @param[in] nIndex  �̳߳��еڼ����߳�
  */
  int ReGetConfigInfo(KCBPCLIHANDLE& hKCBPHandle, ST_tagKCBP_CONFIG tagKcbpConfig, int nIndex = 0);
  /**�̳߳ص�ÿ���߳��е�KCBP�������
  * @param[in,out] hKCBPHandle  KCBP����
  * @return �����롣
  */
  int Connect_ThreadItem(ST_tagKCBP_CONFIG tagKcbpConfig);
  /**�̳߳�KCBP�������
  * @param[in] nThreads  �̳߳��еڼ����߳�
  * @param[in] tagKcbpConfig  ������Ϣ������IP,�˿ڣ�������������Ա�������
  * @return �����롣
  */
  int Connect_ThreadPool(int nThreads, ST_tagKCBP_CONFIG tagKcbpConfig);
  /**�ж��Ƿ��жϿ�������
  * @return �Ƿ��жϿ�������
  */
  BOOL CheckConnectStatus();
  /**�õ�������
  * @return �����ӵ�KCBP���
  */
  int GetConnectNum();
  /**�ر���������
  * @return �����롣
  */
  int CloseAllConnect();
  /**��������
  * @param[in,out] hKCBPHandle  KCBP����
  * @return �����롣
  */
  int TestConnect(KCBPCLIHANDLE hKCBPHandle);
  /**�������������ѶϿ�������
  * @return
  */
  void ReAllConnect();
  /**����KCBP
  * @param[in] hKCBPHandle  KCBP����
  * @param[in] llUserCode  ����Ա
  * @param[in] pszPassWord  ����
  * @return �����롣���Ϊ0����ʾ�����ݷ���
  */
  int UserLoginIn(KCBPCLIHANDLE hKCBPHandle, long long llUserCode, char* pszPassWord);

  int GetLBMErrorInfo(KCBPCLIHANDLE hKCBPHandle, bool bFetch);
  /**
  * ������ͨ����Tick
  * @param[out] pTick ��������TICK
  * @param[in] pNQList ��ͨ������Ϣ
  * @return �����Ƿ��б仯
  */
  bool SetTick(STK_NQ_TICK* pTick, ST_NQ_MDINFO* pNQList);
  /**
  * ��������/Ͷ������Tick
  * @param[out] pTick ��������TICK
  * @param[in] pMMList ����/Ͷ��������Ϣ
  * @param[in] nTickItem TICK����
  * @return �����Ƿ��б仯
  */
  bool SetTick(STK_NQ_ZSXX* pTick, ST_MM_DISH10_INFO* pMMList, int nTickItem);

  /**
  * ��ѯ�����߳�
  * @param[in] arg  ���߳�ָ��
  */
  static THREAD_RET_T workerThread(void* arg);

  /**
  * ���붩������
  * @param[in] pOrderID ί�к�ͬ���
  * @param[in] pszOrderType ί������
  * @return ���سɹ���ʧ��
  */
  int SubOrder(char* pOrderID, char* pszOrderType);

  /**
  * �˳���������
  * @param[in] pOrderID ί�к�ͬ���
  * @return ���سɹ���ʧ��
  */
  int UnSubOrder(char* pOrderID);
  /**
  * ���ί�лر�
  * @param[in] pOrder ί����Ϣ
  * @return ���سɹ���ʧ��
  */
  int GetOrder(ORDER_INFO* pOrder);
  /**
  * �����������
  * @param[in] LBM ������Ϣ
  * @param[in] bImport true�����ȼ���false�����ȼ�
  * @return ���سɹ���ʧ��
  */
  void AddRequestList(CLBMNode LBM, BOOL bImport);

  /**
  * LBMӦ����Ϣ��ȡ
  * @param[in] hKCBPHandle  KCBP����
  * @param[in] pNode ���нڵ�
  * @return ���سɹ���ʧ��
  */
  int GetLBMResult(CLBMNode* pNode, KCBPCLIHANDLE hKcbpHandle);

  /** L3012008���Ӧ���� */
  int Get_L3012008(KCBPCLIHANDLE hKcbpHandle);
  /** L3012001���Ӧ���� */
  int Get_L3012001(KCBPCLIHANDLE hKcbpHandle);
  /** L3012002���Ӧ���� */
  int Get_L3012002(KCBPCLIHANDLE hKcbpHandle);
  /** L3010001���Ӧ���� */
  int Get_L3010001(KCBPCLIHANDLE hKcbpHandle);
  /** L3010002���Ӧ���� */
  int Get_L3010002(KCBPCLIHANDLE hKcbpHandle);
  /** L3013001���Ӧ���� */
  int Get_L3013001(KCBPCLIHANDLE hKcbpHandle);
  /** L3013007���Ӧ���� */
  int Get_L3013007(KCBPCLIHANDLE hKcbpHandle);
  // Add by chenmu 2015-7-27 17:20 ���ɽ���Ų�ѯ�ɽ���ϸ
  /** L3013010���Ӧ���� */
  int Get_L3013010(KCBPCLIHANDLE hKcbpHandle);
  // End Add
  /** L3013011���Ӧ���� */
  // Mod by chenmu 2015-7-29 17:00 �����û��Զ������
  int Set_L3013011(KCBPCLIHANDLE hKcbpHandle, char* pStkCode, char* pUserDefine = NULL);
  // End Mod
  /** L3013013���Ӧ���� */
  int Set_L3013013(KCBPCLIHANDLE hKcbpHandle, char* pOrderID);
  //!< fengweican alter 2.28 ���Ӵ��ڽ��״���
  int Get_L3010087(KCBPCLIHANDLE hKcbpHandle, CLBMNode* pNode);
  int Get_L3010088(KCBPCLIHANDLE hKcbpHandle, CLBMNode* pNode);
  int Get_L3014001(KCBPCLIHANDLE hKCBPHandle, CLBMNode* pNode);
  /** L3013003���Ӧ���� */
  int Get_L3013003(KCBPCLIHANDLE hKcbpHandle, char* pOrderID);
  //!< fengweican alter 5.5 ������Ӫ��Ʊ����
  /** L3013014���Ӧ���� */
  int Set_L3013014(KCBPCLIHANDLE hKcbpHandle, char* pStkCode, char* pUserDefine = NULL);
  /** L3013018���Ӧ���� */
  int Get_L3013018(KCBPCLIHANDLE hKcbpHandle);
  /** L3013020���Ӧ���� */
  int Get_L3013020(KCBPCLIHANDLE hKcbpHandle);
public:
  /**
  * ��ȡ��Ʊ������Ϣ
  * @param[in] szStkCode ��Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int GetNQInfo(char* pStkCode);
  /**
  * ������ͨ���飨�첽ģʽ��
  * @param[in] pStkCode ��Ʊ����
  */
  void GetNQTick(char* pStkCode);
  /**
  * �����������飨�첽ģʽ��
  * @param[in] pStkCode ��Ʊ����
  */
  void GetZSTick(char* pStkCode);
  /**
  * ��������ص�����
  * @param[in] nHandle ���
  * @param[in] pNQTickFun ��ͨ����ص�����
  * @param[in] pZSTickFun ��������ص�����
  */
  void SetCallBackHQFunction(HWND hWnd, CALLBACK_NQHQ pNQTickFun, CALLBACK_ZSHQ pZSTickFun);
  /**
  * ����ί�лص�����
  * @param[in] nHandle ���
  * @param[in] pOrderFun ί�лص�����
  * @param[in] pTradeFun �ɽ��ص�����
  */
  void SetCallBackWTFunction(HWND hWnd, CALLBACK_ORDER pOrderFun, CALLBACK_MATCH pTradeFun);
  /**
  * ���ò������߳��˳��ص�����
  * @param[in] nHandle ���
  * @param[in] pTickErrorFun �����ȡʧ�ܳ��޻ص�����
  * @param[in] pMainTreadStopFun ���߳�ֹͣ�ص�����
  */
  void SetCallBackMainThread(HWND hWnd, CALLBACKFUN pTickErrorFun, CALLBACKFUN pMainTreadStopFun);
  /**
  * ����LBM����ص�����
  * @param[in] nHandle ���
  * @param[in] pLBMErrorFun LBM����ص�����
  */
  void SetCallBackLBMError(HWND hWnd, CALLBACK_ERROR pLBMErrorFun);
  /**
  * ���ù�Ʊ����Ӧ�����ݻص�����
  * @param[in] nHandle ���
  * @param[in] pNQInfoFun ��Ʊ������Ϣ�ص�����
  */
  void SetCallBackNQInfo(HWND hWnd, CALLBACK_NQINFO pNQInfoFun);
  /**
  * �����ʽ�Ӧ�����ݻص�����
  * @param[in] nHandle ���
  * @param[in] pFundFun �ʽ�Ӧ��ص�����
  */
  void SetCallBackFund(HWND hWnd, CALLBACK_FUND pFundFun);
  /**
  * ���óֲ�Ӧ�����ݻص�����
  * @param[in] nHandle ���
  * @param[in] pShareFun �ֲ�Ӧ��ص�����
  */
  void SetCallBackShare(HWND hWnd, CALLBACK_SHARE pShareFun);
  /**
  * ����˫�߱��ۻص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteFun ˫�߱��ۻص�����
  */
  void SetCallBackQuote(HWND hWnd, CALLBACK_QUOTE pQuoteFun);

  /**
  * ���ó����ص�����
  * @param[in] nHandle ���
  * @param[in] pFun �����ص�����
  */
  void SetCallBackCancelQuote(HWND hWnd, CALLBACK_CANCELQUOTE pFun);
  /**
  * ��������ί����ϸӦ�����ݻص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteFun ί����ϸ�ص�����
  */
  void SetCallBackQuoteList(HWND hWnd, CALLBACK_QUOTELIST pQuoteFun);
  /**
  * �������гɽ���ϸ��ϸӦ�����ݻص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteMatchFun �ɽ���ϸ�ص�����
  */
  void SetCallBackQuoteMatchList(HWND hWnd, CALLBACK_QUOTEMATCH pQuoteMatchFun);
  //!< fengweican alter 2.28 ���Ӵ��ڽ��״���
  /**
  * ��������ת��֤ȯ�ʲ��ص�����
  * @param[in] nHandle ���
  * @param[in] pFun �����ص�����
  */
  void SetCallBackMovePosBatch(HWND hWnd, CALLBACK_MOVEPOSBATCH pFun);
  /**
  * ���������޸�֤ȯ����޶�ص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteFun ί����ϸ�ص�����
  */
  void SetCallBackCombiLmtInfoBatch(HWND hWnd, CALLBACK_COMBILMTINFOBATCH pFun);
  /**
  * ���ò�ѯ�ʲ���Ԫ��֤ȯ��ϻص�����
  * @param[in] nHandle ���
  * @param[in] pFun ��ѯ�ʲ���Ԫ��֤ȯ��ϻص�����
  */
  void SetCallBackListCombiInfo(HWND hWnd, CALLBACK_LISTCOMBIINFO pFun);
  /**
  * ���Ĺ�Ʊ����
  * @param[in] pCode ��Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int SubScribe(char* pCode);
  /**
  * �˶���Ʊ����
  * @param[in] pCode ��Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int UnSubScribe(char* pCode);
  /**
  * ��ȡ��Ʊ��ͨ����
  * @param[in] pCode ��Ʊ����
  * @return ������Ϣ
  */
  STK_NQ_TICK* GetNQTickInfo(char* pCode);
  /**
  * ��ȡ��Ʊ��������
  * @param[in] pCode ��Ʊ����
  * @return ������Ϣ
  */
  STK_NQ_ZSXX* GetZSTickInfo(char* pCode);
  /**
  * ��ȡί����Ϣ
  * @param[in] pOrderID ί�к�ͬ���
  * @return ί����Ϣ
  */
  ORDER_INFO* GetOrder(char* pOrderID);
  /**
  * ȡ����Ա���ʽ�
  * @param[in] nAssetID �ʲ���ԪID(0-��ʾ��ǰ�û��������ʲ���Ԫ)
  * @return ����LBM�ɹ���ʧ��
  */
  int GetFunds(int nAssetID);

  /**
  * ȡ����Ա�ĳֲ�
  * @param[in] nAssetID �ʲ���ԪID(0-��ʾ��ǰ�û��������ʲ���Ԫ)
  * @param[in] bZero �Ƿ񷵻سֲ�Ϊ0�ļ�¼
  * @return ����LBM�ɹ���ʧ��
  */
  int GetShare(int nAssetID, BOOL bZero, char* pStkCode);

  /**
  * ���н��ױ���
  * @param[in] pQuoteInfo ������Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int Quote(QUOTE_INFO* pQuoteInfo);

  /**
  * ���в��Խ��ױ���
  * @param[in] pAlgoQuoteInfo ������Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int AlgoQuote(ALGOQUOTE_INFO* pAlgoQuoteInfo);
  /**
  * ���г����걨
  * @param[in] pOrderID ί�к�ͬ���
  * @param[in] chOrderType ί������
  * @return ����LBM�ɹ���ʧ��
  */
  int CancelOrder(char* pOrderID, char chOrderType);

  /**
  * ���г����걨(�������µ�¼��ĳ���) fengwc alter 9.16
  * @param[in] pOrderID ί�к�ͬ���
  * @param[in] chOrderType ί������
  * @return ����LBM�ɹ���ʧ��
  */
  int CancelOldOrder(char* pOrderID, char chOrderType);
  /**
  * �ɽ��ر�
  * @param[in] pOrderID ί�к�ͬ���
  * @return ���سɽ��ر���Ϣ
  */
  QUOTE_MATCH_INFO* GetTrade(char* pOrderID);
  /**
  * ��ѯ��֧���й�Ʊ��ί����ϸ
  * @param[in] pOrderSearch ί�в�ѯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int List_Quote(ORDER_SEARCH OrderSearch);

  /**
  * ��ʱ��β�ѯ��֧���й�Ʊ�ĳɽ���ϸ
  * @param[in] MatchSearch ί�в�ѯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int List_QuoteMatch(ORDER_SEARCH MatchSearch);

  // Add by chenmu 2015-7-27 17:00 ���ɽ���Ų�ѯ�ɽ���ϸ
  /**
  * ���ɽ���Ų�ѯ��֧���й�Ʊ�ĳɽ���ϸ���˺���ֻ������KSMM���׹�̨v1.1.0.0�����ϰ汾���Ҳ���ͬʱ����List_QuoteMatch��
  * @param[in] MatchSearch �ɽ���ѯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int List_NewMatch(MATCH_SEARCHE MatchSearch);
  // End Add

  /**
  * ��ȡ���Ի�����Ϣ
  * @param[out] pAlgoBaseInfo ����������Ϣ
  * @param[out] nAlgoBaseItems �������Ը���
  * @return ����LBM�ɹ���ʧ��
  */
  int GetAlgoBaseInfo(ALGO_BASEINFO** pAlgoBaseInfo, int& nAlgoBaseItems);

  /**
  * ��ȡ������Ϣ
  * @param[in] nAssetID �ʲ���ԪID
  * @param[out] pAlgoInfo ������Ϣ
  * @param[out] nAlgoItems ���Ը���
  * @return ����LBM�ɹ���ʧ��
  */
  int GetAlgoInfo(int nAssetID, ALGO_INFO** pAlgoInfo, int& nAlgoItems);

  /**
  * ��ȡ���Բ�����Ϣ
  * @param[in] nAlgoID ����ID
  * @param[out] pAlgoParam ���Բ�����Ϣ
  * @param[out] nAlgoParamItems ���Բ�������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetAlgoParamInfo(int nAlgoID, ALGO_INFO_EXT** pAlgoParam, int& nAlgoParamItems);

  //add by zhangshuai
  /**
  * ���ò���״̬
  * @param[in] nAlgoID ����ID
  * @param[in] chAlgoStatus ����״̬
  * @return ����LBM�ɹ���ʧ��
  */
  int SetAlgoStatus(int nAlgoID, char chAlgoStatus);
  //!< fengweican alter 5.5 ������Ӫ��Ʊ����
  /**
  * ��Ӫ��Ʊ���ױ���
  * @param[in] pQuoteInfo ������Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int NQWTQuote(NQWTQUOTE_INFO* pQuoteInfo);
  /**
  * ��ѯ��֧��Ӫ��Ʊ��ί����ϸ
  * @param[in] pOrderSearch ί�в�ѯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int List_NQWTQuote(NQWTORDER_SEARCH OrderSearch);
  /**
  * ��ѯ��֧��Ӫ��Ʊ�ĳɽ���ϸ
  * @param[in] MatchSearch �ɽ���ѯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int List_NQWTQuoteMatch(NQWTMATCH_SEARCHE MatchSearch);
  /**
  * ��ȡ��֧��Ӫ��Ʊ��ί����ϸ��Ϣ  L3015208
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int GetList_NQWTQuote_Codes(char* pCodeList);

  /**
  * ��ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ��Ϣ���  L3015209
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_NQWTMatchedInfo_Codes(char* pCodeList);
  //!< fengweican alter 2.28 ���Ӵ��ڽ��״���
  /**
  * ���Ͼ���ת�ú��̺���ڽ���ת��
  * @param[in] pQuoteInfo ������Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int DZQuote(DZQUOTE_INFO* pQuoteInfo);
  /**
  * ����ת��֤ȯ�ʲ�
  * @param[in] pInfo ֤ȯ�ʲ���Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int MovePosBatch(ST_MovePosBatch* pInfo);
  /**
  * �����޸�֤ȯ����޶�
  * @param[in] szStkCodes ֤ȯ����^�ֲ��޶���ϣ���θ�ʽ���£�֤ȯ����1^�ֲ��޶�1|֤ȯ����2^�ֲ��޶�2|֤ȯ����3^�ֲ��޶�3|����
  * @return ����LBM�ɹ���ʧ��
  */
  int SetCombiLmtInfoBatch(char* szStkCodes);
  /**
  * ��ѯ�ʲ���Ԫ��֤ȯ���
  * @param[in] nAssetID �ʲ���ԪID
  * @param[in] nCombiID ���ID
  * @param[in] szStkCode ֤ȯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int GetListCombiInfo(int nAssetID, int nCombiID, char* szStkCode);
  /**
  * ���û�ȡ��֧��Ӫ��Ʊ��ί����ϸ��Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ί����ϸ�ص�����
  */
  void SetCallBackNQWTQuoteCodesFunction(HWND hWnd, CALLBACK_NQWTQUOTE_CODES pFun);
  /**
  * ���û�ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ��Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ί����ϸ�ص�����
  */
  void SetCallBackNQWTMatchedInfoCodesFunction(HWND hWnd, CALLBACK_NQWTMATCHEDINFO_CODES pFun);
  /**
  * ������Ӫ��Ʊ���ۻص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteFun ��Ӫ��Ʊ���ۻص�����
  */
  void SetCallBackNQWTQuote(HWND hWnd, CALLBACK_NQWTQUOTE pQuoteFun);
  /**
  * ���û�ȡ��֧��Ӫ��Ʊ��ί����ϸ�ص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteFun ί����ϸ�ص�����
  */
  void SetCallBackNQWTQuoteList(HWND hWnd, CALLBACK_NQWTQUOTELIST pQuoteFun);
  /**
  * ���û�ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ�ص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteMatchFun �ɽ���ϸ�ص�����
  */
  void SetCallBackNQWTQuoteMatchList(HWND hWnd, CALLBACK_NQWTQUOTEMATCH pQuoteMatchFun);
  //add end

public:
  int m_nHQErrorCount;              //!< �����ȡʧ�ܴ���
  int m_nHQErrorMaxNum;             //!< �����ȡʧ������
  int m_nTickTime;                //!< ������ѯ���
  int m_nOrderTime;               //!< ί����ѯ���
  BOOL m_bConnect;                //!< ���ӱ�־
  /***************************fengwc alter 1.18********************************/
private:
  int m_iOemValidDays;
  std::map<string, ST_NQInfo_Codes>* m_pmapNqTick_Codes;    //!< ��ͨ��������
  std::map<string, STK_NQ_ZSXX>* m_pmapZsTick_Codes;    //!< ������������
  LBM_Acce* m_pAcce;
  map<string, vector<string>>* m_pmapOutPutFiled;
  /////////////////////���ٰ�ص�����///////////////////////////////
  CALLBACK_ASSETSHARE  m_AssetShareInfoFun;               // ��ȡ�ֱֲ��Ʊ��Ϣ
  CALLBACK_INVSTKBCOSTRLT  m_InvStkBcostRltInfoFun;       // ��ȡ�ϱʳֲֳɱ���Ϣ
  CALLBACK_NQHQ_CODES m_NQCodesTickFun;                   // ��ȡ��֧���й�Ʊ����ͨ���顢�ֲ֡����۾�����Ϣ
  CALLBACK_ZSHQ_CODES m_ZSCodesTickFun;                   // ��ȡ��֧���й�Ʊ����������
  CALLBACK_QUOTE_CODES m_Quote_CodesFun;                  // ��ȡ��֧���й�Ʊ��ί����ϸ��Ϣ
  CALLBACK_RISKINFO_CODES m_RiskInfo_CodesFun;            // ��ȡ��֧���й�Ʊ�ķ��ղ�ѯ��Ϣ
  CALLBACK_ACCTINFO m_AcctInfo_CodesFun;                  // ��ȡ��ǰ����Ա���ܵ��ʲ���Ԫ�ʽ���ֵ��ϵͳҵ���л���־�����б�־����Ʊ������������Ϣ
  CALLBACK_NQCONTRECS_CODES m_NqContRecs_CodesFun;        // ��ȡ��֧���й�Ʊ�ı���ʱ����Ϣ
  CALLBACK_WITHDRAWORDER_CODES m_WithdrawOrder_CodesFun;  // ��ѯ��֧���й�Ʊ�Ŀɳ�����Ϣ
  CALLBACK_MATCHINFO_CODES m_MatchInfo_CodesFun;          // ��ѯ��֧���й�Ʊ�ĳɽ���ϸ��Ϣ
  CALLBACK_HISLASTQUOTE_CODES m_HisLastQuote_CodesFun;    // ��ѯ��֧���й�Ʊ�����ձ��۲�ѯ��Ϣ
public:
  /**
  * ��ȡ�ֱֲ��Ʊ��Ϣ L3014026
  * @param[in] nAssetID �ʲ���ԪID
  * @param[in] pCode    ��Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int GetAssetShare(int nAssetID, char* pCode);
  /**
  * ��ȡ�ϱʳֲֳɱ���Ϣ
  * @param[in] nAssetID �ʲ���ԪID
  * @param[in] szCodeList    ��Ʊ�����б�
  * @return ����LBM�ɹ���ʧ��
  */
  int GetInvStkBcostRlt(int nAssetID, char* szCodeList);
  /**
  * ��ȡ��ǰ����Ա���ܵ��ʲ���Ԫ�ʽ���ֵ��ϵͳҵ���л���־�����б�־����Ʊ���������� L3015204
  * @param[in] nAssetID �ʲ���ԪID
  * @return ����LBM�ɹ���ʧ��
  */
  int GetAcctInfo(int nAssetID);
  /**
  * ��ȡ��֧���й�Ʊ��ί����ϸ��Ϣ  L3015202
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_Quote_Codes(char* pCodeList);

  /**
  * ��ȡ��֧���й�Ʊ�ķ�����Ϣ  L3015203
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_RiskInfo_Codes(char* pCodeList);

  /**
  * ��ȡ��֧���й�Ʊ�ı���ʱ����Ϣ  L3015205
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_NqContRecs_Codes(char* pCodeList);

  /**
  * ��ȡ��֧���й�Ʊ�Ŀɳ�����Ϣ  L3015206
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_WithdrawOrder_Codes(char* pCodeList);

  /**
  * ��ȡ��֧���й�Ʊ�ĳɽ���ϸ��Ϣ  L3015207
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_QuoteMatch_Codes(char* pCodeList);

  /**
  * ��ȡ��֧���й�Ʊ�����ձ��۲�ѯ��Ϣ  L3015210
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_HisLastQuote_Codes(char* pCodeList);
  /*****************************************************/
protected:
  CALLBACK_NQHQ m_NQTickFun;                //!< ��֧��Ʊ����ͨ����ص�����
  CALLBACK_ZSHQ m_ZSTickFun;                //!< ��֧��Ʊ����������ص�����
  CALLBACK_ORDER m_OrderFun;                //!< ί��ȷ�ϻص�����
  CALLBACK_MATCH m_TradeFun;                //!< �ɽ�ȷ�ϻص�����
  CALLBACKFUN m_TickErrorFun;               //!< �����ȡʧ�ܻص�����
  CALLBACKFUN m_MainThreadStopFun;          //!< ���߳���ֹ�ص�����
                                            
  CALLBACK_ERROR m_LBMErrorFun;             //!< LBM����ص�
                                            
  CALLBACK_NQINFO m_NQInfoFun;              //!< ��Ʊ������Ϣ�ص�
  CALLBACK_FUND m_FundFun;                  //!< �ʲ���Ԫ�ʽ�ص�
  CALLBACK_SHARE m_ShareFun;                //!< �ʲ���Ԫ�ֲֻص�
  CALLBACK_QUOTE m_QuoteFun;                //!< ˫�߱��ۻص�
  CALLBACK_CANCELQUOTE m_CancelQuoteFun;    //!< �����ص�
  CALLBACK_QUOTELIST m_QuoteListFun;        //!< ��֧���й�Ʊ��ί����ϸ��Ϣ�ص�
  CALLBACK_QUOTEMATCH m_QuoteMatchListFun;  //!< ��֧���й�Ʊ�ĳɽ���ϸ��Ϣ�ص�
  //!< fengweican alter 2.28 ���Ӵ��ڽ��״���
  CALLBACK_MOVEPOSBATCH m_MovePosBatchFun;  //!< ����ת��֤ȯ�ʲ��ص�
  CALLBACK_COMBILMTINFOBATCH m_CombiLmtInfoBatchFun;  //!< ����ת��֤ȯ�ʲ��ص�
  CALLBACK_LISTCOMBIINFO m_ListCombiInfoFun;          //!< ��ѯ�ʲ���Ԫ��֤ȯ���
  //add by zhangshuai
  CALLBACK_TRADESUM m_TradeSumFun;        //!< ĳ�ճɽ�������Ϣ�ص�
  //add end

  ST_ASSET* m_pAsset;              //!< �ʲ���Ԫ
  int m_nAssetItems;                //!< �ʲ���Ԫ����
  //!< fengweican alter 5.5 ������Ӫ��Ʊ����
  CALLBACK_NQWTQUOTE_CODES m_NQWTQuote_CodesFun;        //!< ��ȡ��֧��Ӫ��Ʊ��ί����ϸ��Ϣ
  CALLBACK_NQWTMATCHEDINFO_CODES m_NQWTMatchedInfo_CodesFun;  //!< ��ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ��Ϣ
  CALLBACK_NQWTQUOTE m_NQWTQuoteFun;              //!< ��ȡ��Ӫ��Ʊ���ۻص�����
  CALLBACK_NQWTQUOTELIST m_NQWTQuoteListFun;          //!< ��ȡ��֧��Ӫ��Ʊ��ί����ϸ��Ϣ�ص�
  CALLBACK_NQWTQUOTEMATCH m_NQWTQuoteMatchListFun;      //!< ��ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ��Ϣ�ص�
private:
  ASSET_CODE* m_pAssetCodeInfo;          //!< �ɲ�����Ʊ��Ϣ
  map<string, ASSET_CODE>* m_mapCodeInfo;
  int m_nAssetCodeItems;              //!< �ɲ�����Ʊ����

  char m_szPlugErrorInfo[LEN_LOG];          //!< ��ǰ������Ϣ

  THREAD_T mainWorkThread;            //!< �������߳̾��

  // Mod by chenmu 2015-7-27
  /*static*/ BOOL isMainWorkThreadRunning;      //!< �������߳��Ƿ�������

  CALLBACK_PARAM m_pCallBackParam;        //!< �ص�����
  LBM_CY_Base* m_pCyBase;
  LBM_HQ_Base* m_pHqBase;
  LBM_JY_Base* m_pJyBase;
  LBM_Base* m_pBase;
  vector<Ksmmapi_ThreadPool>* m_pvctThredpool;
private:
  // Add by chenmu 2014-12-19 14:55 ���Ӹ����ȼ������������
  std::queue<CLBMNode>* queueHighRequest;    //!< �����ȼ��������
  MUTEX_T HighRequestLock;            //!< �����ȼ�������

  std::set<string>* set_Low_request;    //!< fengwc alter 1.18 �����ȼ��������lbm���ƣ��ʲ���Ԫ��֤ȯ���룬֤ȯ�����б�ί�б��set
  std::queue<CLBMNode>* queueLowRequest;   //!< �����ȼ��������
  MUTEX_T LowRequestLock;             //!< �����ȼ�������

  HANDLE RequestQueueSignal;            //!< ����Event���

  // Mod by chenmu 2015-7-27 
  /*static*/ BOOL isRequestThreadRunning;       //!< �����߳��Ƿ�������
  /**
  * ������д������߳�
  * @param[in] arg  ���߳�ָ��
  */
  static THREAD_RET_T processRequestThread(void* arg);
  THREAD_T RequestThread;             //!< �����߳̾��

  /**
  * ָ��������
  * @param[in] nThreadIndex �̳߳صڼ����߳�
  * @param[in] hKcbpHandle KCBP����
  * @param[in] Node ָ������
  * @return
  */
  void DoRequest(int nThreadIndex, KCBPCLIHANDLE hKcbpHandle, CLBMNode Node);
  /**
  * �̳߳ػص�����
  * @param[in] Instance ʵ��
  * @param[in] Context �û�����
  * @return
  */
  static void __stdcall ThreadPoolCallback(PTP_CALLBACK_INSTANCE Instance, PVOID Context);
  /**
  * ��־�������߳�
  * @param[in] arg  ���߳�ָ��
  */
  static UINT WINAPI processLogThread(void* arg);
  /**
  * �õ��ɲ����ĸ����ȼ�ָ��
  * @param[in] nIndex �̳߳��еڼ����߳�
  * @param[in,out] Node ��Ҫִ�е�ָ��
  * @return
  */
  void GetHighRequestNode(const int nIndex, CLBMNode& Node);
  /**
  * �õ��ɲ����ĵ����ȼ�ָ��
  * @param[in] nIndex �̳߳��еڼ����߳�
  * @param[in,out] Node ��Ҫִ�е�ָ��
  * @return
  */
  void GetLowRequestNode(const int nIndex, CLBMNode& Node);
  /**
  * ɾ��δ�ɽ���ʧЧ����
  * @return
  */
  void DelOrderID(ORDER_INFO Order);
  THREAD_T LogThread;             //!< ��־�߳̾��
  /**�̳߳ش���**/
  PTP_POOL m_tPool;
  TP_CALLBACK_ENVIRON m_pcbe;
  /*********************/
  __int64 m_llHighQueueCount, m_llLowQueueCount;
  HANDLE m_hndStop;

  char m_szCloseThread[64];
  std::vector<QUOTE_ORDER_INFO>* queueorder;  //!< ί�лر�����
  MUTEX_T queueorderLock;                     //!< ί�лر���
  HANDLE OrderQueueSignal;                    //!< ί��Event���

  std::vector<QUOTE_MATCH_INFO>* queuetrade;  //!< �ɽ��ر�����
  MUTEX_T queuetradeLock;                     //!< �ɽ��ر���
  HANDLE TradeQueueSignal;                    //!< �ɽ�Event���

  MUTEX_T m_queueorderLock;                   //!< ί��ȷ����

  // Del by chenmu 2012-7-27 û��ʹ��
  std::map<string, STK_NQ_TICK>* position_nqtick;   //!< ��ͨ��������
  std::map<string, STK_NQ_ZSXX>* position_zstick;   //!< ������������
  std::map<string, ORDER_INFO>* positionorder;      //!< ί��ȷ����Ϣ

  // fengwc alter 11.5 ��������������������µ�����ô��positionorder��ɾ�����������ܻ�ͬʱ�����ʱ�ͻᷢ����д����
  MUTEX_T HighOrderLock;     //!< ί��ȷ����Ϣ������
  int m_nMainThreadStatus;   //!<���߳�����״̬��0--��ʼ�� 1--������ -1--�Ͽ�����
  int m_nMainThreadRet;      //!< ���̶߳Ͽ�����ʱ������
  int m_nThreads;
  ST_tagKCBP_CONFIG* m_pKcxpConfig;
  int m_nConnectTime;        //!< ������ѯ���
  PST_tagLbmParam m_pTagLbmParam;
  ST_tagInitInfo  m_stInitInfo;

  BOOL      m_bRequestThreadExitFlag;
  BOOL      m_bMainThreadExitFlag;
};

