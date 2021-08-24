/*************************************************
* Copyright (c) 2014,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�Define.h
* ժ    Ҫ���ṹ����
*
* ��ǰ�汾��1.0
* ��    �ߣ�����
* ������ڣ�2014��5��20��
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

#define DIR_BUY 100 //����
#define DIR_SELL 101//����
//Ͷ��
#define SEC_BIZ_DJMR                   55000011   //!< ��������
#define SEC_BIZ_DJMC                   55000012   //!< ��������
#define SEC_BIZ_XYMR                   55000001   //!< Э������
#define SEC_BIZ_XYMC                   55000002   //!< Э������
#define SEC_BIZ_XYHBMR                 55000007   //!< Э�黥������
#define SEC_BIZ_XYHBMC                 55000008   //!< Э�黥������

#define STK_BIZ_XGXJ	55000017	//!< �¹�ѯ��
#define STK_BIZ_XGSG	55000019	//!< �¹��깺
#define STK_BIZ_YSYY	55000021	//!< Ԥ��ҪԼ
#define STK_BIZ_CHYSYY	55000022	//!< ����Ԥ��ҪԼ
#define STK_BIZ_SJ_23	55000023	//!< ���ַ���������
#define STK_BIZ_SJ_24	55000024	//!< ���ַ���������
#define STK_BIZ_SJ_25	55000025	//!< ������������
#define STK_BIZ_SJ_26	55000026	//!< ������������
#define STK_BIZ_SJ_27	55000027	//!< �����嵵��ʱ�ɽ�ʣ�೷������
#define STK_BIZ_SJ_28	55000028	//!< �����嵵��ʱ�ɽ�ʣ�೷������
#define STK_BIZ_SJ_29	55000029	//!< �����嵵��ʱ�ɽ�ʣ��ת�޼�����
#define STK_BIZ_SJ_30	55000030	//!< �����嵵��ʱ�ɽ�ʣ��ת�޼�����

//���в���
#define SEC_BIZ_ZSMR                   55000003   //!< ��������
#define SEC_BIZ_ZSMC                   55000004   //!< ��������
#define SEC_BIZ_ZSHBMR                 55000009   //!< ����Э������
#define SEC_BIZ_ZSHBMC                 55000010   //!< ����Э������
#define SEC_BIZ_DZJYMR                 55000015   //!< ���ڽ�������
#define SEC_BIZ_DZJYMC                 55000016   //!< ���ڽ�������
#define SEC_BIZ_XJMR                   55000005   //!< �޼�����
#define SEC_BIZ_XJMC                   55000006   //!< �޼�����



#define LEN_LOG 512
#define LEN_CODELIST 3700
/** ������Ϣ���� */
struct CONFIG_LIST
{
  char szName[255];       //!< ��ʾ����
  int nValue;             //!< ������
};

/** ��ʼ����Ϣ */
typedef struct
{
  char szUserName[32];      //!< ����Ա�û���
  char szPassword[32];      //!< ����Ա����

  // Add by chenmu 2015-1-22 9:50 �����������ݷ��ط�ʽ
  bool bBackAllHQ;          //!< ���鷵�ط�ʽ��falseĬ�Ϸ������±仯�����飬true��ʱ������������
  // Add by chenmu 2015-1-22 Over
  bool bLocalAddressType;   //!< KCBP�汾�ţ�����汾�ŵ���1106������д��Ԫ�أ����ڻ���ڴ˰汾�ɲ���
}ST_tagInitInfo, * PST_tagInitInfo;

//fengwc alter 7.27
typedef struct
{
  char  szUserName[20];      //!< �û���
  char  szPassword[20];      //!< ����
  char  szIPAddress[20];     //!< ��¼ip
  char  szServer[20];        //!< ��������
  int   nPort;               //!< �˿�
  char  szReq[20];           //!< �������
  char  szAns[20];           //!< Ӧ�����
}ST_tagKCBP_CONFIG, * PST_tagKCBP_CONFIG;

/** LBM���������Ϣ */
struct LBM_PARAM_INFO
{
  char szLBMID[16];
};

/** ���������Ʊ���� */
struct ASSET_CODE
{
  int nProjectID;               //!< ��ĿID
  int nAssetID;                 //!< �ʲ���ԪID
  int nEachLmt;                 //!< ��������  fengwc 0121 alter
  int nBuyVolSize;              //!< ��������λ
  int nSellVolSize;             //!< ��������λ
  char szAssetName[64 + 1];     //!< �ʲ���Ԫ����
  int nCombiID;                 //!< ���ID
  char szCombiName[64 + 1];     //!< �������
  char chCodeBizAction[2 + 1];  //!< ��Ʊ����
  char szStkCode[8 + 1];        //!< ֤ȯ����
  char chStkEx[1 + 1];          //!< ֤ȯ������
  char szStkBd[2 + 1];          //!< ֤ȯ���
  char szStkName[16 + 1];       //!< ֤ȯ����
  int nMinWtVol;                //!< ��С�걨����
  double dPriceDish;            //!< �۸�λ
  int iCheckOem;                //!< OEM��־
};

/** �����Ʊ������Ϣ */
struct STK_NQINFO
{
  char szStkCode[8 + 1];        //!< ֤ȯ����
  char szStkName[16 + 1];       //!< ֤ȯ��� 
  char chStkCls[1 + 1];         //!< ֤ȯ���
  char szBaseCode[8 + 1];       //!< ����֤ȯ
  char szStkIsin[16 + 1];       //!< ISIN����
  int nTurnSize;                //!< ת�õ�λ
  char szStkBD[2 + 1];          //!< ���װ��
  char chCurrenCy[1 + 1];       //!< ��������
  double dStkFaceVal;           //!< ֤ȯ��ֵ
  long long llCirculation;      //!< �ܷ�����
  long long llFloatNum;         //!< ��ͨ����
  double dLastYearMgsy;         //!< ����ÿ������
  double dThisYearMgsy;         //!< ����ÿ������
  double dHandingFee;           //!< ���ַ���
  double dStampTax;             //!< ӡ��˰��
  double dTransFer;             //!< ��������
  int nPutupDate;               //!< ��������
  int nZqqxDate;                //!< ծȯ��Ϣ��
  int nPromptDate;              //!< ����/������
  int nEachLmt;                 //!< ÿ������
  int nBuyVolSize;              //!< ��������λ
  int nSellVolSize;             //!< ��������λ
  int nMinWtVol;                //!< ��С�걨����
  double dPriceDish;            //!< �۸�λ
  double dFirstTurnLmt;         //!< �ױ�ת���޼۲���
  double dLaterTurnLmt;         //!< ����ת���޼۲���
  char chLmtPriceParam[1 + 1];  //!< �޼۲�������
  double dStkUpLmtPrice;        //!< ��ͣ�۸�
  double dStkLwLmtPrice;        //!< ��ͣ�۸�
  double dLargeUpPrice;         //!< ����ת�ü۸�����
  double dLargeLwPrice;         //!< ����ת�ü۸�����
  char chConstituent[1 + 1];    //!< �ɷֹɱ�־
  int nConversion;              //!< �ۺϱ���
  char chTurnStatus[1 + 1];     //!< ת��״̬
  char chStkLevel[1 + 1];       //!< ֤ȯ����
  char chTurnType[1 + 1];       //!< ת������
  int nMMNum;                   //!< ����������
  char chStopFlag[1 + 1];       //!< ͣ�Ʊ�־
  char chCqcxFlag[1 + 1];       //!< ��Ȩ��Ϣ��־
};

/** �����ͨ�ɽ��������� */
struct STK_NQ_TICK
{
  char szStkCode[8 + 1];    //!< ֤ȯ����    fengwc alter 1.18 ֤ȯ���볤��Ҫͳһ       
  char szStkName[16];       //!< ֤ȯ���           
  int nDate;                //!< ��������           
  int nTime;                //!< ����ʱ��           
  short nStatus;            //!< ����״̬
  int nSvrTime;             //!< ת��ʱ��        fengwc alter 1.18 ����ת��ʱ��
  double dClosePrice;       //!< ��������ת�ü�     
  double dRClosePrice;      //!< ����ʵ������ת�ü� 
  double dOpenPrice;        //!< ���տ���ת�ü�     
  double dLastPrice;        //!< ���ת�ü�         
  double dHighPrice;        //!< ��߳ɽ���         
  double dLowPrice;         //!< ��ͳɽ���         
  long long llMatchedVol;   //!< �ɽ�����           
  double dMatchedMoney;     //!< �ɽ����           
  long long llMatchedNum;   //!< �ɽ�����           
  double dPeRatio[2];       //!< ��ӯ��1��2                      
  double dPriceRise[2];     //!< �۸�����1��2          
  long long llStkVolume;    //!< ��Լ�ֲ���
  double dNQDishPri[2][5];  //!< ��ͨ���������嵵�۸�0-��1-��
  int nNQDishVol[2][5];     //!< ��ͨ���������嵵������0-��1-��
  int nRemitFlag;           //!< ����״̬
};

/** �������ʮ���������� */
struct STK_NQ_ZSXX
{
  char szStkCode[8 + 1];      //!< ֤ȯ����    fengwc alter 1.18 ֤ȯ���볤��Ҫͳһ        
  char szStkName[16];         //!< ֤ȯ���           
  double dMMDishPri[2][10];   //!< ������������ʮ���۸�0-��1-��
  int nMMDishVol[2][10];      //!< ������������ʮ��������0-��1-��
  double dMDDishPri[2][10];   //!< ����Ͷ������ʮ���۸�0-��1-��
  int nMDDishVol[2][10];      //!< ����Ͷ������ʮ��������0-��1-��
  int nMMDishNum[2];          //!< �������鵵����0-������1-������
  int nMDDishNum[2];          //!< Ͷ�����鵵����0-������1-������
  char cMMDataType[2];        //!< �����������ͣ�0-��λ��1-����
};

/** ���й�Ʊ������� */
struct QUOTE_INFO
{
  char szStkCode[8 + 1];       //!< ֤ȯ����
  double dAskPrice;            //!< �����۸�
  int nAskVolume;              //!< ��������
  double dBidPrice;            //!< ����۸�
  int nBidVolume;              //!< ��������
  char szOrderRemark[64 + 1];  //!< ί�б�ע
  __int64 llOrderSN;           //!< �������
  char szOrderID[22 + 1];      //!< ί�е���(���)
};

/** �������б������� */
struct ALGOQUOTE_INFO
{
  char szStkCode[8 + 1];       //!< ֤ȯ����
  double dAskPrice;            //!< �����۸�
  int nAskVolume;              //!< ��������
  double dBidPrice;            //!< ����۸�
  int nBidVolume;              //!< ��������
  int nAlgoID;                 //!< ����ID
  // Add by chenmu 2015-7-29 15:20 �����û��Զ����ֶ�
  char szUserDefine[16 + 1];     //!< �û��Զ��壨�����첽�ص�ʱ����ע���ı�ί�У�
  // End Add
  char szOrderRemark[64 + 1];  //!< ί�б�ע
};

/** ����ί�в�ѯ���� */
struct ORDER_SEARCH
{
  char szStkCode[8 + 1];  //!< ֤ȯ����
  int nBegTime;           //!< ��ʼʱ��
  int nEndTime;           //!< ����ʱ��
  int nBegDate;           //!< ��ʼ����
  int nEndDate;           //!< ��������
  char chSearchType[2];   //!< ��ѯ��ʶ
  int nBegUpdTime;        //!< ��ʼ����ʱ��
  int nEndUpdTime;        //!< ��ֹ����ʱ��
};

// Add by chenmu 2015-7-27 17:00 ���ɽ���Ų�ѯ���гɽ���ϸ
struct MATCH_SEARCHE
{
  char szStkCode[8 + 1];     //!< ֤ȯ����
  char chType[2];            //!< ��������[0-���У�1-Ͷ��]
  char szMatchedSN[16 + 1];  //!< �ɽ����
};
// End Add

/** ����ί�е���ѯ��� */
struct QUOTE_ORDER_INFO
{
  int nAssetID;                  //!< �ʲ���ԪID
  char szStkCode[8 + 1];         //!< ֤ȯ����
  char szOrderID[22 + 1];        //!< ί�к�ͬ���
  double dAskPrice;              //!< ������
  int nAskWtVolume;              //!< ��������
  int nAskVolume;                //!< �����ҵ�
  char chAskOrderStatus[1 + 1];  //!< ����ί��״̬
  int nAskMatchVol;              //!< �����ɽ�����
  int nAskCancelVol;             //!< ������������
  double dBidPrice;              //!< �����
  int nBidWtVolume;              //!< ��������
  int nBidVolume;                //!< ����ҵ�
  char chBidOrderStatus[1 + 1];  //!< ����ί��״̬
  int nBidMatchVol;              //!< ����ɽ�����
  int nBidCancelVol;             //!< ���򳷵�����
  int nQuoteDate;                //!< ��������
  int nQuoteTime;                //!< ����ʱ��
};

/** ����ί�в�ѯ��� */
struct ORDER_INFO
{
  int nAssetID;                  //!< �ʲ���ԪID
  char szStkCode[8 + 1];         //!< ֤ȯ����
  char szOrderID[22 + 1];        //!< ί�к�ͬ���
  char chOrderType[1 + 1];       //!< ί������
  double dAskPrice;              //!< ������
  int nAskWtVolume;              //!< ��������
  int nAskVolume;                //!< �����ҵ�
  char chAskOrderStatus[1 + 1];  //!< ����ί��״̬
  int nAskMatchVol;              //!< �����ɽ�����
  int nAskCancelVol;             //!< ������������
  double dBidPrice;              //!< �����
  int nBidWtVolume;              //!< ��������
  int nBidVolume;                //!< ����ҵ�
  char chBidOrderStatus[1 + 1];  //!< ����ί��״̬
  int nBidMatchVol;              //!< ����ɽ�����
  int nBidCancelVol;             //!< ���򳷵�����
  int nQuoteDate;                //!< ��������
  int nQuoteTime;                //!< ����ʱ��

  bool bAllMatched;              //!< �Ƿ�ȫ���ɽ�

  ORDER_INFO()
  {
    chAskOrderStatus[0] = 'X';
    chBidOrderStatus[0] = 'X';
    bAllMatched = false;
  }
};

/** �ɽ��ص���� */
struct MATCH_INFO
{
  char szOrderID[22 + 1];    //!< ί�к�ͬ���
  int nAssetID;              //!< �ʲ���ԪID
  char szStkCode[8 + 1];     //!< ֤ȯ����
  double dAskOrderPrice;     //!< �����۸�
  double dBidOrderPrice;     //!< ����۸�
  int nAskOrderQty;          //!< ����ί������
  int nBidOrderQty;          //!< ����ί������
  char chIsWithdraw[1 + 1];  //!< ������־
  int nAskMatchedQty;        //!< �����ɽ�����
  int nBidMatchedQty;        //!< ����ɽ�����
  int nMatchDate;            //!< �ɽ����� fengwc alger  7.27
  int nMatchTime;            //!< �ɽ�ʱ�� fengwc alger 7.27
};

/** ���гɽ�����ѯ��� */
struct QUOTE_MATCH_INFO
{
  int nMatchTime;            //!< �ɽ�ʱ��
  char szOrderID[22 + 1];    //!< ί�к�ͬ���
  int nAssetID;              //!< �ʲ���ԪID
  int nCombi_ID;             //!< ���ID
  char szStkCode[8 + 1];     //!< ֤ȯ����
  char szStkName[16 + 1];    //!< ֤ȯ����
  char chStkEx[1 + 1];       //!< ֤ȯ������
  char szStkBd[2 + 1];       //!< ���װ��
  char szStkPbu[8 + 1];      //!< ���׵�Ԫ
  int nStkBiz;               //!< ֤ȯҵ��
  short nStkBizAction;       //!< ֤ȯҵ����Ϊ
  double dOrderPrice;        //!< ί�м۸�
  int nOrderQty;             //!< ί������
  char chIsWithdraw[1 + 1];  //!< ������־
  double dMatchedPrice;      //!< �ɽ��۸�
  int nMatchedQty;           //!< �ɽ�����

  //add by zhangshuai
  double dMatchedAmt;        //!< �ɽ����
  int nTradeDate;            //!< ��������
  //add end

  // Add by chenmu 2015-7-27 13:00 ���ӳɽ����
  char szMatchedSN[16 + 1];  //!< �ɽ����
  int nUpdTime;              //!< ����ʱ��
  // Add End
};

///** ���й�Ʊ������Ϣ���ܽ�� */
struct QUOTE_TRADESUM_INFO
{
  int     nTradeDate;         //!< ��������
  char    szStkCode[8 + 1];   //!< ֤ȯ����
  float   fBuyAvgPrice;       //!< ������ɽ�����
  float   fSellAvgPrice;      //!< �������ɽ�����
  long long llTotalBuyQty;    //!< ��������ɽ�����
  double dTotalBuyAmt;        //!< ��������ɽ����
  long long llTotalSellQty;   //!< ���������ɽ�����
  double dTotalSellAmt;       //!< ���������ɽ����
};

/** �ʲ���Ԫ�ֲֲ�ѯ��� */
struct ASSET_SHARE
{
  int nProjectId;              //!< ��ĿID
  char szProjectName[64 + 1];  //!< ��Ŀ����
  int nAssetId;                //!< �ʲ���ԪID
  char szAssetName[64 + 1];    //!< �ʲ���Ԫ����
  int nCombiId;                //!< ���ID
  short siIntOrg;              //!< �ڲ�����
  char chStkex[1 + 1];         //!< ֤ȯ������
  char szStkbd[2 + 1];         //!< ���װ��
  char szStkpbu[8 + 1];        //!< ���׵�Ԫ
  char szTrdacct[10 + 1];      //!< �����˻�
  char chCurrency[1 + 1];      //!< ���Ҵ���
  char szStkCode[8 + 1];       //!< ֤ȯ����
  char szStkName[16 + 1];      //!< ֤ȯ����
  char chStkCls[1 + 1];        //!< ֤ȯ���
  long llStkPrebln;            //!< ֤ȯ�������
  long llStkBln;               //!< ֤ȯ���
  long llStkAvl;               //!< ֤ȯ��������
  long llStkFrz;               //!< ֤ȯ��������
  long llStkUfz;               //!< ֤ȯ�ⶳ����
  long llStkNtrd;              //!< ֤ȯ����ͨ����
  long llStkTrdFrz;            //!< ֤ȯ���׶�������
  long llStkTrdUfz;            //!< ֤ȯ���׽ⶳ����
  long llStkTrdOtd;            //!< ֤ȯ������;����
  long llStkTrdBln;            //!< ֤ȯ������������
  double dStkBcost;            //!< ֤ȯ����ɱ�
  double dStkBcostRlt;         //!< ֤ȯ����ɱ���ʵʱ��
  double dStkIncome;           //!< ����ʵ��ӯ�����
  double dStkIncomePre;        //!< ����ʵ��ӯ�����
  double dStkFpl;              //!< ���ո���ӯ�����
  double dStkFplPre;           //!< ���ո���ӯ�����
  double dStkMktl;             //!< ���ն���ӯ�����
  double dStkMktlPre;          //!< ���ն���ӯ�����
  double dMktVal;              //!< ��ֵ
};

/** �ʲ���Ԫ�ʽ��ѯ��� */
struct ASSET_FUND
{
  int nProjectId;              //!< ��ĿID
  char szProjectName[64 + 1];  //!< ��Ŀ����
  int nAssetId;                //!< �ʲ���ԪID
  char szAssetName[64 + 1];    //!< �ʲ���Ԫ����
  short siIntOrg;              //!< �ڲ�����
  char chCurrency[1 + 1];      //!< ���Ҵ���
  double dMaxMoney;            //!< �ʽ�����
  double dMinMoney;            //!< �ʽ�����
  double dFundPrebln;          //!< �ʽ��������
  double dFundBln;             //!< �ʽ�ǰ���
  double dFundAvl;             //!< �ʽ���ý��
  double dFundFrz;             //!< �ʽ𶳽���
  double dFundUfz;             //!< �ʽ�ⶳ���
  double dFundTrdFrz;          //!< �ʽ��׶�����
  double dFundTrdUfz;          //!< �ʽ��׽ⶳ���
  double dFundTrdOtd;          //!< �ʽ�����;���
  double dFundTrdBln;          //!< �ʽ���������
  double dFundClrFrz;          //!< �ʽ����㶳����
  double dFundClrUfz;          //!< �ʽ�����ⶳ���
  double dFundClrOtd;          //!< �ʽ�������;���
  double dFundClrCtf;          //!< �ʽ����㱣�����
  double dFundTrnFrz;          //!< �ʽ�ת�ʶ�����
  double dFundTrnUfz;          //!< �ʽ�ת�˽ⶳ���
  double dFundDebt;            //!< �ʽ�ծ���
  double dFundCredit;          //!< �ʽ�ծȨ���
  short siIntRateSn;           //!< ���ʱ���
  short siDrRateSn;            //!< ��ծ���ʱ���
  double dIntCalBln;           //!< ��Ϣ���
  double dIntBlnAccu;          //!< ��Ϣ����
  int iIntCalDate;             //!< ��Ϣ����
  double dInterest;            //!< ��Ϣ
  double dIntTax;              //!< ��Ϣ˰
  double dDrInt;               //!< ��ծ��Ϣ
  double dMktVal;              //!< ��ֵ
  double dCashAccu;            //!< �ֽ����
  double dChequeAccu;          //!< ֧Ʊ����
  double dLastFundClr;         //!< �ϴ�������
  double dLwlmtFund;           //!< �ʽ�����
  double dLwlmtAsset;          //!< �ʲ�����
  char szUpdTime[32 + 1];      //!< �޸�ʱ��
  char chFundStatus[1 + 1];    //!< �ʽ�״̬
  char szMac[255 + 1];         //!< У����    fengwc 0121 alter
  double dPaylater;            //!< �渶�ʽ�
};

/** ����������Ϣ */
struct ALGO_BASEINFO
{
  int nAlgoBaseId;             //!< ��������ID
  char szAlgoName[32 + 1];     //!< ��������
  char szAlgoRemark[256 + 1];  //!< ���Ա�ע
  char szDllEntry[32 + 1];     //!< DLL����
  char szFuncPtr[32 + 1];      //!< �������
};

/** ������Ϣ */
struct ALGO_INFO
{
  int nAlgoId;                    //!< ����ID
  int nAlgoBaseId;                //!< ��������ID
  char szAlgoName[32 + 1];        //!< ��������
  char szAlgoRemark[256 + 1];     //!< ���Ա�ע
  char szDllEntry[32 + 1];        //!< DLL����
  char szFuncPtr[32 + 1];         //!< �������
  char chStkex[1 + 1];            //!< ֤ȯ������
  char szStkbd[2 + 1];            //!< ���װ��
  char szStkCode[8 + 1];          //!< ֤ȯ����
  char szStkName[16 + 1];         //!< ֤ȯ����
  int nProjectId;                 //!< ��ĿID
  char szProjectName[64 + 1];     //!< ��Ŀ����
  int nAssetId;                   //!< �ʲ���ԪID
  char szAssetName[64 + 1];       //!< �ʲ���Ԫ����
  int nCombiId;                   //!< ���ID
  char szCombiName[64 + 1];       //!< �������
  char chAlgoStatus[1 + 1];       //!< ����״̬
  int nAlgoInterval;              //!< ί�м��ʱ��
  char szAlgoUpdateTime[32 + 1];  //!< �´�ʱ��
};

/** ���Թ�����Ϣ */
struct ALGO_INFO_EXT
{
  int nAlgoId;               //!< ����ID
  int nStkBiz;               //!< ֤ȯҵ��
  short siDishType;          //!< ��λ����
  short siPriceDish;         //!< �۸�λ
  short siAlgoPriceType;     //!< �۸��������
  int iPriceFloatRate;       //!< �۸񸡶�����
  int iPriceAbsValue;        //!< �۸����ֵ
  short siVolDish;           //!< ������λ
  short siAlgoVolType;       //!< ������������
  int iMinOrderQty;          //!< ��Сί������
  int iMaxOrderQty;          //!< ���ί������
  int iVolFloatRate;         //!< ������������
  int iVolAbsValue;          //!< ��������ֵ
  long long llInitTotalVol;  //!< ��ʼί��������
  long long llMatchedQty;    //!< �ѳɽ�����
};

//add by zhangshuai
struct QUOTE_CONSUMETIME_INFO
{
  int nTradeDate;         //!< ��������
  char szStkEx[2];        //!< ֤ȯ������
  char szStkBd[3];        //!< ���װ��
  char szStkCode[8 + 1];  //!< ֤ȯ����
  char cLastOrdState;     //!< ����걨״̬
  char cLastStkState;     //!< �����Ʊ״̬
  int  nLastOrdTime;      //!< ����걨ʱ��
  int  nLastInvTime;      //!< ���ʧЧʱ��
  int  nLastSusTime;      //!< �����ʱͣ��ʱ��
  int  nLastResTime;      //!< �������ʱ��
  int  nLastUpdTime;      //!< �������ʱ��
  int  nLastOrderID;      //!< ����걨��
  int  nValTotalTime;     //!< ��Ч�����ۼ�ʱ��
  int  nInvalTotalTime;   //!< ����ʧЧ�ۼ�ʱ��
  int  nMmTotalTime;      //!< ����ۼ�ʱ��
  int  nPreMmTotalTime;   //!< �����ۼ�ʱ��
};
/** ���й�Ʊ���ۻر���Ϣ */
struct QUOTE_BACK_INFO
{
  char szStkCode[8 + 1];      //!< ��Ʊ����
  char szOrderID[22 + 1];     //!< ��ͬ���
  char szUserDefine[16 + 1];  //!< �û��Զ���
};
//!< fengweican alter 2.28 ���Ӵ��ڽ��״���
/** ���Ͼ���ת�ú��̺���ڽ���ת�ñ������ */
struct DZQUOTE_INFO
{
  int nAssetID;                    //!< �ʲ���ԪID
  char szStkCode[8 + 1];           //!< ֤ȯ����
  char chStkEx[1 + 1];             //!< ֤ȯ������
  int nStkBiz;                     //!< ֤ȯҵ��
  short nStkBizAction;             //!< ֤ȯҵ����Ϊ
  double dWtPrice;                 //!< ί�м۸�
  int nWtVolume;                   //!< ί������
  char szTargetTaAcct[6 + 1];      //!< ���ַ����׵�Ԫ
  char szTargetTransAcct[10 + 1];  //!< ���ַ�֤ȯ�ʻ�
  __int64 nAgreementID;            //!< �ɽ�Լ����
  char szOrderRemark[64];          //!< ί�б�ע
  char chDZFlag[1 + 1];            //!< ���ڽ��ױ�ʶ
};

struct ST_MovePosBatch
{
  __int64 llOutAssetID;        //!< �����ʲ���ԪID
  __int64 llInAssetID;         //!< �����ʲ���ԪID
  __int64 llOutCombiID;        //!< �������ID
  __int64 llInCombiID;         //!< �������ID
  char  chStkEX[1 + 1];        //!< ֤ȯ������
  char  szStkCodes[1024 + 1];  //!< ֤ȯ����
  char  szRemark[128 + 1];     //!<��ע
};

/** ��Ӫ��Ʊ������� */
struct NQWTQUOTE_INFO
{
  int nAssetID;                    //!< �ʲ���ԪID
  char szStkCode[8 + 1];           //!< ֤ȯ����
  char chStkEx[1 + 1];             //!< ֤ȯ������
  int nStkBiz;                     //!< ֤ȯҵ��
  short nStkBizAction;             //!< ֤ȯҵ����Ϊ
  double dWtPrice;                 //!< ί�м۸�
  int nWtVolume;                   //!< ί������
  char szTargetTaAcct[6 + 1];      //!< ���ַ����׵�Ԫ
  char szTargetTransAcct[10 + 1];  //!< ���ַ�֤ȯ�ʻ�
  __int64 nAgreementID;            //!< �ɽ�Լ����
  char szOrderRemark[64];          //!< ί�б�ע
};

/** ��Ӫ��Ʊ���ۻر���Ϣ */
struct NQWTQUOTE_BACK_INFO
{
  char szStkCode[8 + 1];      //!< ��Ʊ����
  char szOrderID[22 + 1];     //!< ��ͬ���
  int nOrderSn;               //!< ί�����
  char szUserDefine[16 + 1];  //!< �û��Զ���
};

/** ��Ӫ��Ʊί�в�ѯ���� */
struct NQWTORDER_SEARCH
{
  char szStkCode[8 + 1];       //!< ֤ȯ����
  int nStkBiz;                 //!< ֤ȯҵ��
  int nAssetID;                //!< �ʲ���ԪID
  char chOrderStatus[1 + 1];   //!< ί��״̬ ȡֵ��Χ:'0'--"δ��",'1'--"����",'2'--"�ѱ�",'3'--"�ѱ�����",'4'--"���ɴ���",'5'--"����",'6'--"�ѳ�",'7'--"�����ѳ�",'8'--"�ѳ�",'9'--"�ϵ�",'A'--"����"
  int nBegTime;                //!< ��ʼʱ��
  int nEndTime;                //!< ����ʱ��
  int nBegDate;                //!< ��ʼ����
  int nEndDate;                //!< ��������
  int nBegUpdTime;             //!< ��ʼ����ʱ��
  int nEndUpdTime;             //!< ��ֹ����ʱ��
};

/** ��Ӫ��Ʊ�ɽ���ѯ���� */
struct NQWTMATCH_SEARCHE
{
  char szStkCode[8 + 1];      //!< ֤ȯ����
  int nStkBiz;                //!< ֤ȯҵ��
  int nAssetID;               //!< �ʲ���ԪID
  char chCancelOrder[1 + 1];  //!< ί�г��� ȡֵ��Χ '0'-�������еĳɽ���¼;'1'-���س�����־ΪF�����ļ�¼
  int nBegTime;               //!< ��ʼʱ��
  int nEndTime;               //!< ����ʱ��
  int nBegDate;               //!< ��ʼ����
  int nEndDate;               //!< ��������
  int nBegUpdTime;            //!< ��ʼ����ʱ��
  int nEndUpdTime;            //!< ��������ʱ��
};
/** ��Ӫ��Ʊί����ϸ���� */
struct NQWTQUOTE_ORDER_INFO
{
  int nTradeDate;                  //!< �������� 
  int  nOrderDate;                 //!< ί������
  int  nOrderTime;                 //!< ί��ʱ��
  int iOrderSn;                    //!< ί�����
  int iOrderBsn;                   //!< ί������
  char szOrderID[22 + 1];          //!< ��ͬ���
  char chOrderStatus[1 + 1];       //!< ί��״̬
  char chOrderValidFlag[1 + 1];    //!< ί����Ч��־
  int nOrderValidDate;             //!< ί����Ч����
  int nProjectID;                  //!< ��ĿID
  char szProjectName[64 + 1];      //!< ��Ŀ����
  int nAssetID;                    //!< �ʲ���ԪID
  char szAssetName[64 + 1];        //!< �ʲ���Ԫ����
  int nCombiId;                    //!< ���ID
  char szCombiName[64 + 1];        //!< �������
  char chStkEx[1 + 1];             //!< ֤ȯ������
  char szStkBD[2 + 1];             //!< ���װ��
  char szStkpbu[8 + 1];            //!< ���׵�Ԫ
  char szTrdacct[10 + 1];          //!< �����˻�
  char szTrdAcct_Exid[10 + 1];     //!< ���̽����˻�
  char chTrdacctType[1 + 1];       //!< �����˻�����
  char chRdacctExcls[1 + 1];       //!< �����˻����
  int nStkBiz;                     //!< ֤ȯҵ��
  short nStkBizAction;             //!< ֤ȯҵ����Ϊ
  char szStkBizEx[8 + 1];          //!< ֤ȯҵ���ⲿ��
  char szStkCode[8 + 1];           //!< ֤ȯ����
  char szStkName[16 + 1];          //!< ֤ȯ����
  char chStkCls[1 + 1];            //!< ֤ȯ���
  char chStkFlag[1 + 1];           //!< ֤ȯ��־
  char chCurrency[1 + 1];          //!< ���Ҵ���
  double dWtPrice;                 //!< ί�м۸�
  int nOrderQty;                   //!< ί������
  double dOrderAmt;                //!< ί�н��
  double dOrderFrzAmt;             //!< ί�ж�����
  double dOrderUfzAmt;             //!< ί�нⶳ���
  int nOfferQty;                   //!< �걨����
  int nOfferStime;                 //!< �걨ʱ��
  int nWithdrawQty;                //!< �ѳ�������
  int nMatchQty;                   //!< �ѳɽ�����
  double dMatchedAmt;              //!< �ѳɽ����
  double dRltSeatAmt;              //!< ʵʱ������
  char chIsWithdraw[1 + 1];        //!< ������־
  char chRawOrderID[22 + 1];       //!< ԭ��ͬ���
  int nOfferRecSn;                 //!< �걨���
  char szTargetTaAcct[6 + 1];      //!< ���ַ����׵�Ԫ
  char szTargetTransAcct[10 + 1];  //!< ���ַ�֤ȯ�ʻ�
  __int64 nAgreementID;            //!< �ɽ�Լ����
  __int64 nAppSno;                 //!< �����걨��
  char llOpUser[20 + 1];           //!< �����û�
  char szOpName[32 + 1];           //!< �����û�����
  char szOpSite[255 + 1];          //!< ����վ��
  char chChannel[1 + 1];           //!< ��������
};
/** ��Ӫ��Ʊ�ɽ���ϸ���� */
struct NQWTQUOTE_MATCH_INFO
{
  int nTradeDate;                  //!< ��������
  int nMatchTime;                  //!< �ɽ�ʱ��
  int  nOrderDate;                 //!< ί������
  int nOrderSn;                    //!< ί�����
  int iOrderBsn;                   //!< ί������
  char szOrderID[22 + 1];          //!< ��ͬ���
  int nProjectID;                  //!< ��ĿID
  char szProjectName[64 + 1];      //!< ��Ŀ����
  int nAssetID;                    //!< �ʲ���ԪID
  char szAssetName[64 + 1];        //!< �ʲ���Ԫ����
  int nCombiId;                    //!< ���ID
  char szCombiName[64 + 1];        //!< �������
  char chStkEx[1 + 1];             //!< ֤ȯ������
  char szStkBD[2 + 1];             //!< ���װ��
  char szStkpbu[8 + 1];            //!< ���׵�Ԫ
  char szTrdacct[10 + 1];          //!< �����˻�
  char szTrdAcct_Exid[10 + 1];     //!< ���̽����˻�
  char chTrdacctType[1 + 1];       //!< �����˻�����
  char chRdacctExcls[1 + 1];       //!< �����˻����
  int nStkBiz;                     //!< ֤ȯҵ��
  short nStkBizAction;             //!< ֤ȯҵ����Ϊ
  char szStkBizEx[8 + 1];          //!< ֤ȯҵ���ⲿ��
  char szStkCode[8 + 1];           //!< ֤ȯ����
  char szStkName[16 + 1];          //!< ֤ȯ����
  char chStkCls[1 + 1];            //!< ֤ȯ���
  char chStkFlag[1 + 1];           //!< ֤ȯ��־
  char chCurrency[1 + 1];          //!< ���Ҵ���
  double dWtPrice;                 //!< ί�м۸�
  int nOrderQty;                   //!< ί������
  double dOrderAmt;                //!< ί�н��
  double dOrderFrzAmt;             //!< ί�ж�����
  char szCancelRemark[64 + 1];     //!< ����ԭ��
  char chIsWithdraw[1 + 1];        //!< ������־
  char chMatchedType[1 + 1];       //!< �ɽ�����
  char szMatchedSN[16 + 1];        //!< �ɽ����
  double dMatchedPrice;            //!< �ɽ��۸�
  int nMatchedVol;                 //!< �ɽ�����
  double dMatchedMoney;            //!< �ɽ����   
  double dRltSeatAmt;              //!< ʵʱ������
  double dFundAvl;                 //!< �ʽ���ý��
  long llStkAvl;                   //!< ֤ȯ��������
  char szTargetTaAcct[6 + 1];      //!< ���ַ����׵�Ԫ
  char szTargetTransAcct[10 + 1];  //!< ���ַ�֤ȯ�ʻ�
  char llOpUser[20 + 1];           //!< �����û�
  char szOpName[32 + 1];           //!< �����û�����
  char szOpSite[255 + 1];          //!< ����վ��
  char chChannel[1 + 1];           //!< ��������
  int nUpdTime;                    //!< ����ʱ��
};
//add end