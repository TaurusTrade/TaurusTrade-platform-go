/*************************************************
* Copyright (c) 2014,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�LBM_Define.h
* ժ    Ҫ��LBM�ṹ�嶨��
*
* ��ǰ�汾��1.0
* ��    �ߣ�����
* ������ڣ�2014��5��20��
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

/** KCXP���� */
struct KCXP_CONFIG
{
  char username[20];  //!< �û���
  char password[20];  //!< ����
  char address[20];   //!< ��¼ip
  char server[20];    //!< ��������
  int port;           //!< �˿�
  char req[20];       //!< �������
  char ans[20];       //!< Ӧ�����
};

#define INIT_PARAM_ITEMS 13     //!< ϵͳ��������

#define KEYLEN           20
#define VALUELEN         3700

/** ͨ�ò������� */
struct PARAM_LIST
{
  char szKey[KEYLEN];       //!< ����
  char szValue[VALUELEN];   //!< ֵ
};

// LBM�����Ϣ
typedef struct
{
  char szKey[32];      // ��������
  char szValue[1024];  // ����ֵ
} ST_tagLbmParam, * PST_tagLbmParam;

/** �����ʲ���Ԫ */
struct ST_ASSET
{
  char nProjectID[10 + 1];    //!< ��ĿID
  char nAssetID[10 + 1];      //!< �ʲ���ԪID
  char szAssetName[64 + 1];   //!< �ʲ���Ԫ����
};

/** ��ǰ������ʱ�� */
struct ST_CURDATETIME
{
  char nCurDate[10 + 1];        //!< ��ǰ���ڣ����֣� yyyymmdd
  char szCurDate[10 + 1];       //!< ��ǰ���ڣ��ַ��� yyyy-mm-dd
  char nCurTime[10 + 1];        //!< ��ǰʱ�䣨���֣� hhMMssnn
  char szCurTime[10 + 1];       //!< ��ǰʱ�䣨�ַ��� hh:MM:ss.nn
  char lCurDateTime[22 + 1];    //!< ��ǰ����ʱ�䣨���֣� yyyymmddhhMMssnn
  char szCurDateTime[22 + 1];   //!< ��ǰ����ʱ�䣨�ַ��� yyyy-mm-dd hh:MM:ss.nn
};

/** ������Ʊ���� */
struct ST_ASSET_CODE
{
  char nProjectID[10 + 1];      //!< ��ĿID
  char nEachLmt[10 + 1];        //!< ��������    fengwc 0121 alter
  char nBuyVolSize[10 + 1];     //!< ��������λ
  char nSellVolSize[10 + 1];    //!< ��������λ
  char nAssetID[10 + 1];        //!< �ʲ���ԪID
  char szAssetName[64 + 1];     //!< �ʲ���Ԫ����
  char nCombiID[10 + 1];        //!< ���ID
  char szCombiName[64 + 1];     //!< �������
  char chCodeBizAction[2 + 1];  //!< ��Ʊ����
  char szStkCode[8 + 1];        //!< ֤ȯ����
  char chStkEx[1 + 1];          //!< ֤ȯ������
  char szStkBd[2 + 1];          //!< ֤ȯ���
  char szStkName[16 + 1];       //!< ֤ȯ����
  char nMinWtVol[10 + 1];       //!< ��Сί������
  char nPriceDish[16 + 1];      //!< ��С�۸�λ
  char nCheckOem[1 + 1];        //!< OEM��־
};

struct ST_ASSET_CODE_INFO
{
  char chPosType[1 + 1];        //!< �ֲ��޶����� POS_TYPE  CHAR
  char chStkCls[1 + 1];         //!< ֤ȯ��� STK_CLS CHAR(1) 
  char chStkEX[1 + 1];          //!< ֤ȯ������ STKEX CHAR(1)
  char chCodeBizAction[1 + 1];  //!< ��Ʊ���� CODE_BIZ_ACTION CHAR(1)
  char chInvestType[1 + 1];     //!< Ͷ������ INVEST_TYPE CHAR(1)
  char chCombiStatus[1 + 1];    //!<  ���״̬  COMBI_STATUS  CHAR(1)
  char szStkBD[2 + 1];          //!< ���װ�� STKBD CHAR(2)
  int nCombiID;                 //!< ���ID COMBI_ID  BIGINT
  int nProjectID;               //!< ��ĿID PROJECT_ID  BIGINT
  int  nStkPoolID;              //!< ��Ʊ�ط���ID STK_POOL_ID INTEGER 
  int nAssetID;                 //!< �ʲ���ԪID ASSET_ID  BIGINT
  char szAssetName[64 + 1];     //!< �ʲ���Ԫ���� ASSET_NAME  VARCHAR(64)
  char szCombiName[64 + 1];     //!< ������� COMBI_NAME  VARCHAR(64)           
  char szStkCode[8 + 1];        //!< ֤ȯ���� STK_CODE  VARCHAR(8)
  char szStkName[16 + 1];       //!< ֤ȯ���� STK_NAME  VARCHAR(16) 
  __int64 llMaxPosVol;          //!< �ֲ����� MAX_POS_VOL BIGINT
  double dMaxPosVolP;           //!< �ֲ����ޱ��� MAX_POS_VOL_P BIGINT
  __int64 llWarnMaxVol;         //!< �ֲ�����Ԥ��ֵ WARN_MAX_VOL  BIGINT
  double dWarnMaxVolP;          //!< �ֲ�����Ԥ��ֵ���� WARN_MAX_VOL_P  BIGINT
  __int64 llMinPosVol;          //!< �ֲ����� MIN_POS_VOL BIGINT
  double dMinPosVolP;           //!< �ֲ����ޱ��� MIN_POS_VOL_P BIGINT
  __int64 llWarnMinVol;         //!< �ֲ�����Ԥ��ֵ WARN_MIN_VOL  BIGINT
  double dWarnMinVolP;          //!< �ֲ�����Ԥ��ֵ���� WARN_MIN_VOL_P  BIGINT  
  __int64 llMaxSinglePosVol;    //!< ���ֲ߳����� MAX_SINGLE_POS_VOL  BIGINT
  __int64 llMaxNetPosVol;       //!< ���ֲ����� MAX_NET_POS_VOL BIGINT
};

/** ��ȡ��Ʊ������Ϣ��LBMӦ�� */
struct ST_STK_NQINFO
{
  char szStkCode[8 + 1];        //!< ֤ȯ����
  char szStkName[16 + 1];       //!< ֤ȯ��� 
  char chStkCls[1 + 1];         //!< ֤ȯ���
  char szBaseCode[8 + 1];       //!< ����֤ȯ
  char szStkIsin[16 + 1];       //!< ISIN����
  char nTurnSize[10 + 1];       //!< ת�õ�λ
  char szStkBD[2 + 1];          //!< ���װ��
  char chCurrenCy[1 + 1];       //!< ��������
  char llStkFaceVal[20 + 1];    //!< ֤ȯ��ֵ
  char llCirculation[20 + 1];   //!< �ܷ�����
  char llFloatNum[20 + 1];      //!< ��ͨ����
  char nLastYearMgsy[10 + 1];   //!< ����ÿ������
  char nThisYearMgsy[10 + 1];   //!< ����ÿ������
  char nHandingFee[10 + 1];     //!< ���ַ���
  char nStampTax[10 + 1];       //!< ӡ��˰��
  char nTransFer[10 + 1];       //!< ��������
  char nPutupDate[10 + 1];      //!< ��������
  char nZqqxDate[10 + 1];       //!< ծȯ��Ϣ��
  char nPromptDate[10 + 1];     //!< ����/������
  char nEachLmt[10 + 1];        //!< ÿ������
  char nBuyVolSize[10 + 1];     //!< ��������λ
  char nSellVolSize[10 + 1];    //!< ��������λ
  char nMinWtVol[10 + 1];       //!< ��С�걨����
  char nPriceDish[10 + 1];      //!< �۸�λ
  char llFirstTurnLmt[20 + 1];  //!< �ױ�ת���޼۲���
  char llLaterTurnLmt[20 + 1];  //!< ����ת���޼۲���
  char chLmtPriceParam[1 + 1];  //!< �޼۲�������
  char nStkUpLmtPrice[10 + 1];  //!< ��ͣ�۸�
  char nStkLwLmtPrice[10 + 1];  //!< ��ͣ�۸�
  char nLargeUpPrice[10 + 1];   //!< ����ת�ü۸�����
  char nLargeLwPrice[10 + 1];   //!< ����ת�ü۸�����
  char chConstituent[1 + 1];    //!< �ɷֹɱ�־
  char nConversion[10 + 1];     //!< �ۺϱ���
  char chTurnStatus[1 + 1];     //!< ת��״̬
  char chStkLevel[1 + 1];       //!< ֤ȯ����
  char chTurnType[1 + 1];       //!< ת������
  char nMMNum[10 + 1];          //!< ����������
  char chStopFlag[1 + 1];       //!< ͣ�Ʊ�־
  char chCqcxFlag[1 + 1];       //!< ��Ȩ��Ϣ��־
};

/** ��ȡ��ͨ���飺LBMӦ�� */
struct ST_NQ_MDINFO
{
  char szStkCode[8 + 1];        //!< ֤ȯ����
  char szStkName[16 + 1];       //!< ֤ȯ���
  char szHqDate[10 + 1];        //!< ��������
  char szHqTime[10 + 1];        //!< ����ʱ��
  char szHqStatus[6];           //!< ����״̬
  char szSvrTime[10 + 1];       //!< ת��ʱ��
  char llCloseTprice[20 + 1];   //!< ��������ת�ü�
  char llRCloseTprice[20 + 1];  //!< ����ʵ������ת�ü�
  char llOpenTprice[20 + 1];    //!< ���տ���ת�ü�
  char llLastTprice[20 + 1];    //!< ���ת�ü�
  char llMatchedVol[20 + 1];    //!< �ɽ�����
  char llMatchedMoney[20 + 1];  //!< �ɽ����
  char llMatchedNum[20 + 1];    //!< �ɽ�����
  char llHighPrice[20 + 1];     //!< ��߳ɽ���
  char llLowPrice[20 + 1];      //!< ��ͳɽ���
  char llPeRatio1[20 + 1];      //!< ��ӯ��1
  char llPeRatio2[20 + 1];      //!< ��ӯ��2
  char llPriceRise1[20 + 1];    //!< �۸�����1
  char llPriceRise2[20 + 1];    //!< �۸�����2
  char llStkVolume[20 + 1];     //!< ��Լ�ֲ���
  char llStkSp5[20 + 1];        //!< ����λ��
  char llStkSv5[20 + 1];        //!< ��������
  char llStkSp4[20 + 1];        //!< ����λ��
  char llStkSv4[20 + 1];        //!< ��������
  char llStkSp3[20 + 1];        //!< ����λ��
  char llStkSv3[20 + 1];        //!< ��������
  char llStkSp2[20 + 1];        //!< ����λ��
  char llStkSv2[20 + 1];        //!< ��������
  char llStkSp1[20 + 1];        //!< ����λһ/������ʾ��
  char llStkSv1[20 + 1];        //!< ������һ
  char llStkBp1[20 + 1];        //!< ���λһ/�����ʾ��
  char llStkBv1[20 + 1];        //!< ������һ
  char llStkBp2[20 + 1];        //!< ���λ��
  char llStkBv2[20 + 1];        //!< ��������
  char llStkBp3[20 + 1];        //!< ���λ��
  char llStkBv3[20 + 1];        //!< ��������
  char llStkBp4[20 + 1];        //!< ���λ��
  char llStkBv4[20 + 1];        //!< ��������
  char llStkBp5[20 + 1];        //!< ���λ��
  char llStkBv5[20 + 1];        //!< ��������
};

/** ��ȡ����/Ͷ�����飺LBMӦ�� */
struct ST_MM_DISH10_INFO
{
  char szStkCode[8 + 1];        //!< ֤ȯ����
  char szStkName[16 + 1];       //!< ֤ȯ���
  char szOrderType[2 + 1];      //!< ҵ�����
  char llWtVol[20 + 1];         //!< �걨����
  char llWtPrice[20 + 1];       //!< �걨�۸�
  char chDataType[1 + 1];       //!< ��������
  char iWtTime[10 + 1];         //!< �걨ʱ��
  char iReserveValue[10 + 1];   //!< �����ֶ�
  char llReserveFlag[20 + 1];   //!< ���ñ�־
};

/** �������б������� */
struct ST_QUOTE_INFO
{
  char nAssetID[10 + 1];      //!< �ʲ���ԪID
  char szStkCode[8 + 1];      //!< ֤ȯ����
  char chStkEx[1 + 1];        //!< ֤ȯ������
  char dAskPrice[20 + 1];     //!< ����۸�
  char nAskVolume[10 + 1];    //!< ��������
  char dBidPrice[20 + 1];     //!< �����۸�
  char nBidVolume[10 + 1];    //!< ��������
  char szOrderID[22 + 1];     //!< ί�е���(���)
};

/** ���볷��ί�� */
struct ST_CANCEL_ORDER
{
  char szOrderID[22 + 1];       //!< ί�е���
  char chOrderType[1 + 1];      //!< ί������
  char szCancelRemark[64 + 1];  //!< ����ԭ��
};

/** ����ί�в�ѯ���� */
struct ST_ORDER_SEARCH
{
  char szStkCode[8 + 1];      //!< ֤ȯ����
  char nBegTime[10 + 1];      //!< ��ʼʱ��
  char nEndTime[10 + 1];      //!< ����ʱ��
  char nBegDate[10 + 1];      //!< ��ʼ����
  char nEndDate[10 + 1];      //!< ��������
  char chSearchType[1 + 1];   //!< ��ѯ��ʶ
};

/** �������ί�е���ѯ��� */
struct ST_QUOTE_ORDER_INFO
{
  char nAssetID[10 + 1];         //!< �ʲ���ԪID
  char szStkCode[8 + 1];         //!< ֤ȯ����
  char szOrderID[22 + 1];        //!< ί�к�ͬ���
  char dAskPrice[20 + 1];        //!< ������
  char nAskWtVolume[10 + 1];     //!< ��������
  char nAskVolume[10 + 1];       //!< �����ҵ�
  char chAskOrderStatus[1 + 1];  //!< ����ί��״̬
  char nAskMatchVol[10 + 1];     //!< �����ɽ�����
  char nAskCancelVol[10 + 1];    //!< ������������
  char dBidPrice[10 + 1];        //!< �����
  char nBidWtVolume[10 + 1];     //!< ��������
  char nBidVolume[10 + 1];       //!< ����ҵ�
  char chBidOrderStatus[1 + 1];  //!< ����ί��״̬
  char nBidMatchVol[10 + 1];     //!< ����ɽ�����
  char nBidCancelVol[10 + 1];    //!< ���򳷵�����
  char nQuoteDate[10 + 1];       //!< ��������
  char nQuoteTime[10 + 1];       //!< ����ʱ��
};

/** ���ί�е���ѯ��� */
struct ST_ORDER_INFO
{
  char iTrdDate[10 + 1];         //!< ��������
  char iOrderDate[10 + 1];       //!< ί������
  char iOrderTime[10 + 1];       //!< ί��ʱ��
/*  char iOrderSn[10+1];         //!< ί�����
  char iOrderBsn[10+1];          //!< ί������*/
  char szOrderId[22 + 1];        //!< ��ͬ���
  char chOrderStatus[1 + 1];     //!< ί��״̬
/*  char chOrderValidFlag[1+1];  //!< ί����Ч��־
  char iOrderValidDate[10+1];    //!< ί����Ч����
  char llProjectId[10+1];        //!< ��ĿID
  char szProjectName[64+1];      //!< ��Ŀ����*/
  char llAssetId[10 + 1];        //!< �ʲ���ԪID
/*  char szAssetName[64+1];      //!< �ʲ���Ԫ����
  char llCombiId[10+1];          //!< ���ID
  char szCombiName[64+1];        //!< �������
  char chStkex[1+1];             //!< ֤ȯ������
  char szStkbd[2+1];             //!< ���װ��
  char szStkpbu[8+1];            //!< ���׵�Ԫ
  char szTrdacct[10+1];          //!< �����˻�
  char szTrdacctExid[10+1];      //!< ���̽����˻�
  char chTrdacctType[1+1];       //!< �����˻�����
  char chRdacctExcls[1+1];       //!< �����˻����*/
  char iStkBiz[10 + 1];          //!< ֤ȯҵ��
/*  char siStkBizAction[10+1];   //!< ֤ȯҵ����Ϊ
  char szStkBizEx[8+1];          //!< ֤ȯҵ���ⲿ��*/
  char szStkCode[8 + 1];         //!< ֤ȯ����
/*  char szStkName[16+1];        //!< ֤ȯ����
  char chStkCls[1+1];            //!< ֤ȯ���
  char chStkFlag[1+1];           //!< ֤ȯ��־
  char chCurrency[1+1];          //!< ���Ҵ���*/
  char llOrderPrice[20 + 1];     //!< ί�м۸�
  char llOrderQty[20 + 1];       //!< ί������
  char dOrderAmt[20 + 1];        //!< ί�н��
/*  char dOrderFrzAmt[20+1];     //!< ί�ж�����
  char dOrderUfzAmt[20+1];       //!< ί�нⶳ���
  char llOfferQty[20+1];         //!< �걨����
  char iOfferStime[10+1];        //!< �걨ʱ��*/
  char llWithdrawnQty[20 + 1];   //!< �ѳ�������
  char llMatchedQty[20 + 1];     //!< �ѳɽ�����
  char dMatchedAmt[20 + 1];      //!< �ѳɽ����
/*  char dRltSettAmt[20+1];      //!< ʵʱ������
  char chIsWithdraw[1+1];        //!< ������־
  char llOpUser[20+1];           //!< �����û�
  char szOpName[32+1];           //!< �����û�����
  char szOpSite[255+1];          //!< ����վ��
  char chChannel[1+1];           //!< ��������
  char szRawOrderId[22+1];       //!< ԭ��ͬ���
  char iOfferRecSn[10+1];        //!< �걨���
  char szOfferRetMsg[64+1];      //!< �걨������Ϣ
  char szOrderRemark[64+1];      //!< ί�б�ע
  char szTargetTaAcct[6+1];      //!< ���ַ����׵�Ԫ
  char szTargetTransAcct[10+1];  //!< ���ַ�֤ȯ�ʻ�
  char szLinkmanName[50+1];      //!< ��ϵ��
  char szLinkmanTel[50+1];       //!< ��ϵ��ʽ
  char llAgreementId[20+1];      //!< �ɽ�Լ����
  char llAppSno[20+1];           //!< �����걨��*/
};

/** ����ɽ���ѯ���� */
struct ST_MATCH_SEARCH
{
  char nAssetID[10 + 1];      //!< �ʲ���ԪID
  char szStkCode[8 + 1];      //!< ֤ȯ����
  char nBegTime[10 + 1];      //!< ��ʼʱ��
  char nEndTime[10 + 1];      //!< ����ʱ��
  char nBegDate[10 + 1];      //!< ��ʼ����
  char nEndDate[10 + 1];      //!< ��������
};

/** ������гɽ�����ѯ��� */
struct ST_QUOTE_MATCH_INFO
{
  char nMatchTime[10 + 1];     //!< �ɽ�ʱ��
  char szOrderID[22 + 1];      //!< ί�к�ͬ���
  char nAssetID[10 + 1];       //!< �ʲ���ԪID
  char nCombi_ID[10 + 1];      //!< ���ID
  char szStkCode[8 + 1];       //!< ֤ȯ����
  char szStkName[16 + 1];      //!< ֤ȯ����
  char chStkEx[1 + 1];         //!< ֤ȯ������
  char szStkBd[2 + 1];         //!< ���װ��
  char szStkPbu[8 + 1];        //!< ���׵�Ԫ
  char nStkBiz[10 + 1];        //!< ֤ȯҵ��
  char nStkBizAction[4 + 1];   //!< ֤ȯҵ����Ϊ
  char nOrderPrice[10 + 1];    //!< ί�м۸�
  char nOrderQty[10 + 1];      //!< ί������
  char chIsWithdraw[1 + 1];    //!< ������־
  char nMatchedPrice[10 + 1];  //!< �ɽ��۸�
  char nMatchedQty[10 + 1];    //!< �ɽ�����

  //add by zhangshuai
  char dMatchedAmt[20 + 1];   //!< �ɽ���� 
  char nTradeDate[10 + 1];    //!< ��������
  //add end

  // Add by chenmu 2015-7-27 13:00 ���ӳɽ����
  char szMatchedSN[16 + 1];   //!< �ɽ����
  char nUpdTime[10 + 1];      //!< ����ʱ��
  // Add End
};

/** ����ʲ���Ԫ�ʽ��ѯ��� */
struct ST_ASSET_FUND
{
  char nProjectId[10 + 1];      //!< ��ĿID
  char szProjectName[64 + 1];   //!< ��Ŀ����
  char nAssetId[10 + 1];        //!< �ʲ���ԪID
  char szAssetName[64 + 1];     //!< �ʲ���Ԫ����
  char siIntOrg[4 + 1];         //!< �ڲ�����
  char chCurrency[1 + 1];       //!< ���Ҵ���
  char llMaxMoney[20 + 1];      //!< �ʽ�����
  char llMinMoney[20 + 1];      //!< �ʽ�����
  char llFundPrebln[20 + 1];    //!< �ʽ��������
  char llFundBln[20 + 1];       //!< �ʽ�ǰ���
  char llFundAvl[20 + 1];       //!< �ʽ���ý��
  char llFundFrz[20 + 1];       //!< �ʽ𶳽���
  char llFundUfz[20 + 1];       //!< �ʽ�ⶳ���
  char llFundTrdFrz[20 + 1];    //!< �ʽ��׶�����
  char llFundTrdUfz[20 + 1];    //!< �ʽ��׽ⶳ���
  char llFundTrdOtd[20 + 1];    //!< �ʽ�����;���
  char llFundTrdBln[20 + 1];    //!< �ʽ���������
  char llFundClrFrz[20 + 1];    //!< �ʽ����㶳����
  char llFundClrUfz[20 + 1];    //!< �ʽ�����ⶳ���
  char llFundClrOtd[20 + 1];    //!< �ʽ�������;���
  char llFundClrCtf[20 + 1];    //!< �ʽ����㱣�����
  char llFundTrnFrz[20 + 1];    //!< �ʽ�ת�ʶ�����
  char llFundTrnUfz[20 + 1];    //!< �ʽ�ת�˽ⶳ���
  char llFundDebt[20 + 1];      //!< �ʽ�ծ���
  char llFundCredit[20 + 1];    //!< �ʽ�ծȨ���
  char siIntRateSn[4 + 1];      //!< ���ʱ���
  char siDrRateSn[4 + 1];       //!< ��ծ���ʱ���
  char llIntCalBln[20 + 1];     //!< ��Ϣ���
  char llIntBlnAccu[20 + 1];    //!< ��Ϣ����
  char iIntCalDate[10 + 1];     //!< ��Ϣ����
  char llInterest[20 + 1];      //!< ��Ϣ
  char llIntTax[20 + 1];        //!< ��Ϣ˰
  char llDrInt[20 + 1];         //!< ��ծ��Ϣ
  char llMktVal[20 + 1];        //!< ��ֵ
  char llCashAccu[20 + 1];      //!< �ֽ����
  char llChequeAccu[20 + 1];    //!< ֧Ʊ����
  char llLastFundClr[20 + 1];   //!< �ϴ�������
  char llLwlmtFund[20 + 1];     //!< �ʽ�����
  char llLwlmtAsset[20 + 1];    //!< �ʲ�����
  char szUpdTime[32 + 1];       //!< �޸�ʱ��
  char chFundStatus[1 + 1];     //!< �ʽ�״̬
  char szMac[255 + 1];          //!< У����   fengwc 0121 alter
  char llPaylater[20 + 1];      //!< �渶�ʽ�
};

/** ����ʲ���Ԫ�ֲֲ�ѯ��� */
struct ST_SHARE
{
  char nProjectId[10 + 1];        //!< ��ĿID
  char szProjectName[64 + 1];     //!< ��Ŀ����
  char nAssetId[10 + 1];          //!< �ʲ���ԪID
  char szAssetName[64 + 1];       //!< �ʲ���Ԫ����
  char nCombiId[10 + 1];          //!< ���ID
  char siIntOrg[4 + 1];           //!< �ڲ�����
  char chStkex[1 + 1];            //!< ֤ȯ������
  char szStkbd[2 + 1];            //!< ���װ��
  char szStkpbu[8 + 1];           //!< ���׵�Ԫ
  char szTrdacct[10 + 1];         //!< �����˻�
  char chCurrency[1 + 1];         //!< ���Ҵ���
  char szStkCode[8 + 1];          //!< ֤ȯ����
  char szStkName[16 + 1];         //!< ֤ȯ����
  char chStkCls[1 + 1];           //!< ֤ȯ���
  char llStkPrebln[20 + 1];       //!< ֤ȯ�������
  char llStkBln[20 + 1];          //!< ֤ȯ���
  char llStkAvl[20 + 1];          //!< ֤ȯ��������
  char llStkFrz[20 + 1];          //!< ֤ȯ��������
  char llStkUfz[20 + 1];          //!< ֤ȯ�ⶳ����
  char llStkNtrd[20 + 1];         //!< ֤ȯ����ͨ����
  char llStkTrdFrz[20 + 1];       //!< ֤ȯ���׶�������
  char llStkTrdUfz[20 + 1];       //!< ֤ȯ���׽ⶳ����
  char llStkTrdOtd[20 + 1];       //!< ֤ȯ������;����
  char llStkTrdBln[20 + 1];       //!< ֤ȯ������������
  char llStkBcost[20 + 1];        //!< ֤ȯ����ɱ�
  char llStkBcostRlt[20 + 1];     //!< ֤ȯ����ɱ���ʵʱ��
  //char llBuyBalance[20+1];      //!< ֤ȯ�������
  char llStkIncome[20 + 1];       //!< ����ʵ��ӯ�����
  char llStkIncomePre[20 + 1];    //!< ����ʵ��ӯ�����
  char llStkFpl[20 + 1];          //!< ���ո���ӯ�����
  char llStkFplPre[20 + 1];       //!< ���ո���ӯ�����
  char llStkMktl[20 + 1];         //!< ���ն���ӯ�����
  char llStkMktlPre[20 + 1];      //!< ���ն���ӯ�����
  //char llSaleBalance[20+1];     //!< ֤ȯ��������
  //char llStkClrFrz[20+1];       //!< ֤ȯ���㶳������
  //char llStkClrUfz[20+1];       //!< ֤ȯ����ⶳ����
  //char llStkClrOtd[20+1];       //!< ֤ȯ������;����
  char llMktVal[20 + 1];          //!< ��ֵ
  //char szUpdTime[32+1];         //!< �޸�ʱ��
  //char szMac[255+1];            //!< У����
};

/** �������������Ϣ��ѯ��� */
struct ST_ALGO_BASEINFO
{
  char llAlgoBaseId[20 + 1];   //!< ��������ID
  char szAlgoName[32 + 1];     //!< ��������
  char szAlgoRemark[256 + 1];  //!< ���Ա�ע
  char szDllEntry[32 + 1];     //!< DLL����
  char szFuncPtr[32 + 1];      //!< �������
};

/** ���������Ϣ��ѯ��� */
struct ST_ALGO_INFO
{
  char llAlgoId[20 + 1];          //!< ����ID
  char llAlgoBaseId[20 + 1];      //!< ��������ID
  char szAlgoName[32 + 1];        //!< ��������
  char szAlgoRemark[256 + 1];     //!< ���Ա�ע
  char szDllEntry[32 + 1];        //!< DLL����
  char szFuncPtr[32 + 1];         //!< �������
  char chStkex[1 + 1];            //!< ֤ȯ������
  char szStkbd[2 + 1];            //!< ���װ��
  char szStkCode[8 + 1];          //!< ֤ȯ����
  char szStkName[16 + 1];         //!< ֤ȯ����
  char llProjectId[20 + 1];       //!< ��ĿID
  char szProjectName[64 + 1];     //!< ��Ŀ����
  char llAssetId[20 + 1];         //!< �ʲ���ԪID
  char szAssetName[64 + 1];       //!< �ʲ���Ԫ����
  char llCombiId[20 + 1];         //!< ���ID
  char szCombiName[64 + 1];       //!< �������
  char chAlgoStatus[1 + 1];       //!< ����״̬
  char iAlgoInterval[10 + 1];     //!< ί�м��ʱ��
  char szAlgoUpdateTime[32 + 1];  //!< �´�ʱ��
};

/** ������Թ�����Ϣ��ѯ��� */
struct ST_ALGO_INFO_EXT
{
  char llAlgoId[20 + 1];         //!< ����ID
  char iStkBiz[10 + 1];          //!< ֤ȯҵ��
  char chDishType[1 + 1];        //!< ��λ����
  char siPriceDish[10 + 1];      //!< �۸�λ
  char chAlgoPriceType[1 + 1];   //!< �۸��������
  char iPriceFloatRate[10 + 1];  //!< �۸񸡶�����
  char iPriceAbsValue[10 + 1];   //!< �۸����ֵ
  char siVolDish[10 + 1];        //!< ������λ
  char chAlgoVolType[1 + 1];     //!< ������������
  char iMinOrderQty[10 + 1];     //!< ��Сί������
  char iMaxOrderQty[10 + 1];     //!< ���ί������
  char iVolFloatRate[10 + 1];    //!< ������������
  char iVolAbsValue[10 + 1];     //!< ��������ֵ
  char llInitTotalVol[20 + 1];   //!< ��ʼί��������
  char llMatchedQty[20 + 1];     //!< �ѳɽ�����
};

//add by zhangshuai
struct ST_QUOTE_CONSUMETIME_INFO
{
  char nTradeDate[11];        //!< ��������
  char szStkEx[2];            //!< ֤ȯ������
  char szStkBd[3];            //!< ���װ��
  char szStkCode[8 + 1];      //!< ֤ȯ����
  char cLastOrdState[2];      //!< ����걨״̬
  char cLastStkState[2];      //!< �����Ʊ״̬
  char  nLastOrdTime[11];     //!< ����걨ʱ��
  char  nLastInvTime[11];     //!< ���ʧЧʱ��
  char  nLastSusTime[11];     //!< �����ʱͣ��ʱ��
  char  nLastResTime[11];     //!< �������ʱ��
  char  nLastUpdTime[11];     //!< �������ʱ��
  char  nLastOrderID[11];     //!< ����걨��
  char  nValTotalTime[11];    //!< ��Ч�����ۼ�ʱ��
  char  nInvalTotalTime[11];  //!< ����ʧЧ�ۼ�ʱ��
  char  nMmTotalTime[11];     //!< ����ۼ�ʱ��
  char  nPreMmTotalTime[11];  //!< �����ۼ�ʱ��
};

//add end