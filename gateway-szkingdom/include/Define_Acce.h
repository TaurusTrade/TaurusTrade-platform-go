/*************************************************
* Copyright (c) 2014,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�Define_Acce.h
* ժ    Ҫ���ṹ����
*
* ��ǰ�汾��1.0
* ��    �ߣ���ΰ��
* ������ڣ�2016��1��16��
**************************************************/
#pragma once

//L3014026��������
struct ST_AssetShareInfo
{
  int nAssetID;                 //!< �ʲ���ԪID
  char szAssetName[64 + 1];     //!< �ʲ���Ԫ����
  char szStkCode[8 + 1];        //!< ֤ȯ����
  char szStkName[16 + 1];       //!< ֤ȯ����
  char szStkBd[2 + 1];          //!< ���װ��
  char chCodeBizAction[2 + 1];  //!< ��Ʊ����
  long long llMM_Num;           //!< ����������
  long long llCirculation;      //!< �ܷ�����
  long long llFloatNum;         //!< ��ͨ����
                                
  char chTurnStatus[1 + 1];     //!< ת��״̬
  double dStkUplmtPrice;        //!< ��ͣ��
  double dStkLwlmtPrice;        //!< ��ͣ��

  long long llEachLmt;          //!< ÿ�ʱ�������
  long long llBuyVolSize;       //!< ��������λ
  long long llSellVolSize;      //!< ��������λ
  long long llMmMaxSpread;      //!< ��ת���б����������۲�(%)
  long long llMinWtVol;         //!< ��ת���б�����Сί������
  double dPriceDish;            //!< ��С�۸�λ(NQ_INFO.PRICE_DISH*MM_MIN_PRICE_UNIT)
  long long llQuoteValidVol;    //!< ��ת���б�����Ч�ҵ���
  int iCheckOem;                //!< OEM��־

};
//L3015200��������
struct ST_NQInfo_Codes
{
  char szStkCode[8 + 1];    //!< ֤ȯ����           
  char szStkName[16];       //!< ֤ȯ���           
  int nDate;                //!< ��������           
  int nTime;                //!< ����ʱ��           
  short nStatus;            //!< ����״̬
  int nSvrTime;             //!< ת��ʱ��
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

  __int64 llStkAvl;         //!< ֤ȯ��������
  double dMktVal;           //!< ��ֵ
  double dStkIncome;        //!< ����ʵ��ӯ�����
  double dStkIncomePre;     //!< ����ʵ��ӯ�����
  double dStkBcostRlt;      //!< ֤ȯ����ɱ���ʵʱ��
  __int64 llStkTrdBln;      //!< ֤ȯ������������
  int nStkHmBiz;            //!< ֤ȯ����״̬
  __int64 llStkBln;         //!< ֤ȯ���
  double dBidAvgPrice;      //!< �����������
  double dAskAvgPrice;      //!< ������������
  int nBidVol;              //!< ������������
  int nAskVol;              //!< ������������
  char chStkCls[1 + 1];     //!< ֤ȯ���
};
//L3015201��������
struct ST_ZSInfo_Codes
{
  char szStkCode[8 + 1];
  char szWtTime[10 + 1];
  double dMM_BP[10];      //!< �������
  int nMM_BV[10];         //!< ��������
  double dMM_SP[10];      //!< ��������
  int nMM_SV[10];         //!< ��������
  double dST_BP[10];      //!< Ͷ�����
  int nST_BV[10];         //!< Ͷ������
  double dST_SP[10];      //!< Ͷ������
  int nST_SV[10];         //!< Ͷ������
};
//L3015202��������
struct ST_Quote_Codes
{
  int nAssetID;                  //!< �ʲ���ԪID
  char szStkCode[8 + 1];         //!< ֤ȯ����    
  char chStkEx[1 + 1];           //!< ֤ȯ������
  int  nStkBiz;                  //!< ֤ȯҵ��
  int nStkBizAction;             //!< ֤ȯҵ����Ϊ
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
  char szCancelRemark[24 + 1];   //!< ����ԭ��
  int nQuoteDate;                //!< ��������
  int nQuoteTime;                //!< ����ʱ��
};
//L3015203��������
struct ST_RiskInfo_Codes
{
  __int64 llRiskID;                  //!< ��ر��
  char chTriggerType[2];             //!< ��������
  char szRiskRelationObj[128 + 1];   //!< ��������
  char szRiskRelationName[128 + 1];  //!< ������������
  char chRiskRelationType[2];        //!< ��������
  char chRikTouchStatus[2];          //!< ����״̬
  char  szRiskTouchTime[10];         //!< ����ʱ��
  char szRiskSummary[128 + 1];       //!< ����˵��
};
//L3015204��������
struct ST_AcctInfo
{
  double dAllAsset;                //!<���ʲ�
  double dAllFpl;                  //!<�ܸ���ӯ��
  double dAllMktval;               //!<����ֵ
  double dAllBcost;                //!<������ɱ�
  char  chBizStatus[2];            //!<ҵ��״̬
};
//L3015205��������
struct ST_NqContRecs_Codes
{
  int iTrdDate;                 //!< ��������
  char chStkEx[1 + 1];          //!< ֤ȯ������
  char szStkBd[2 + 1];          //!< ֤ȯ���
  char szStkCode[8 + 1];        //!< ֤ȯ����
  char chLastOrdState[2];       //!< ����걨״̬
  char chLastStkState[2];       //!< �����Ʊ״̬
  int  nLastOrdTime;            //!< ����걨ʱ��
  int  nLastInvTime;            //!< ���ʧЧʱ��
  int  nLastSusTime;            //!< �����ʱͣ��ʱ��
  int  nLastResTime;            //!< �������ʱ��
  int  nLastUpdTime;            //!< �������ʱ��
  char  szLastOrderID[22 + 1];  //!< ����걨��
  int  nValTotalTime;           //!< ��Ч�����ۼ�ʱ��
  int  nInvalTotalTime;         //!< ����ʧЧ�ۼ�ʱ��
  int  nMmTotalTime;            //!< ����ۼ�ʱ��
  int  nPreMmTotalTime;         //!< �����ۼ�ʱ��
  __int64 llCallQty;            //!< ����ҵ�
  __int64 llPutQty;             //!< ������ҵ�
};
//L3015206��������
struct ST_WithdrawOrder_Codes
{
  __int64 llOpCdoe;              //!< ����Ա����     
  int nAssetID;                  //!< �ʲ���ԪID
  char szStkCode[8 + 1];         //!< ֤ȯ����
  char chStkEx[1 + 1];           //!< ֤ȯ������
  int  nStkBiz;                  //!< ֤ȯҵ��
  int nStkBizAction;             //!< ֤ȯҵ����Ϊ
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
  char szCancelRemark[24 + 1];   //!< ����ԭ��
  int nQuoteDate;                //!< ��������
  int nQuoteTime;                //!< ����ʱ��
};
//L3015207��������
struct ST_MatchInfo_Codes
{
  int iTrdDate;                    //!< ��������
  char szMatchTime[9];             //!< �ɽ�ʱ��
  int  nOrderDate;                 //!< ί������
  int  nOrderSn;                   //!< ί�����
  int  nOrderBsn;                  //!< ί������
  char szOrderId[22 + 1];          //!< ��ͬ���
  __int64  llProjectId;            //!< ��ĿID
  char szProjectName[64 + 1];      //!< ��Ŀ����
  __int64 llAssetId;               //!< �ʲ���ԪID
  char szAssetName[64 + 1];        //!< �ʲ���Ԫ����
  __int64 llCombiId;               //!< ���ID
  char szCombiName[64 + 1];        //!< �������
  char chStkex[1 + 1];             //!< ֤ȯ������
  char szStkbd[2 + 1];             //!< ���װ��
  char szStkpbu[8 + 1];            //!< ���׵�Ԫ
  char szTrdacct[10 + 1];          //!< �����˻�
  char szTrdacctExid[10 + 1];      //!< ���̽����˻�
  char chTrdacctType[1 + 1];       //!< �����˻�����
  char chRdacctExcls[1 + 1];       //!< �����˻����  
  int  nStkBiz;                    //!< ֤ȯҵ��
  int nStkBizAction;               //!< ֤ȯҵ����Ϊ
  char szStkBizEx[8 + 1];          //!< ֤ȯҵ���ⲿ��
  char szStkCode[8 + 1];           //!< ֤ȯ����
  char szStkName[16 + 1];          //!< ֤ȯ����
  char chStkCls[1 + 1];            //!< ֤ȯ���
  char chStkFlag[1 + 1];           //!< ֤ȯ��־
  char chCurrency[1 + 1];          //!< ���Ҵ���
  double dOrderPrice;              //!< ί�м۸�
  __int64 llOrderQty;              //!< ί������
  double dOrderAmt;                //!< ί�н��
  double dOrderFrzAmt;             //!< ί�ж�����
  char chCancelReason[3];          //!< ����ԭ��
  char chIsWithdraw[1 + 1];        //!< ������־
  char chMatchedType[1 + 1];       //!< �ɽ�����
  char szMatchedSN[16 + 1];        //!< �ɽ����
  double dMatchedPrice;            //!< �ɽ��۸�
  __int64 llMatchedQty;            //!< �ɽ�����
  double dMatchedAmt;              //!< �ɽ����
  double dRltSettAmt;              //!< ʵʱ������
  double dFundAvl;                 //!< �ʽ���ý��
  __int64 llStkAvl;                //!< ֤ȯ���ý��
  char llOpUser[20 + 1];           //!< �����û�
  char szOpName[32 + 1];           //!< �����û�����
  char szOpSite[255 + 1];          //!< ����վ��
  char chChannel[1 + 1];           //!< ��������
};

//L3015208��������
struct ST_NQWTQuote_Codes
{
  int  nOrderDate;                 //!< ί������
  int  nOrderTime;                 //!< ί��ʱ��
  int  nOrderSn;                   //!< ί�����
  char szOrderID[22 + 1];          //!< ��ͬ���
  char chOrderStatus[1 + 1];       //!< ί��״̬
  int nStkBiz;                     //!< ֤ȯҵ��
  char szStkCode[8 + 1];           //!< ֤ȯ����
  double dOrderPrice;              //!< ί�м۸�
  __int64 nOrderQty;               //!< ί������
  __int64 llWithdrawnQty;          //!< �ѳ�������
  __int64 llMatchedQty;            //!< �ɽ�����
  char chIsWithdraw[1 + 1];        //!< ������־
  char szOrderRemark[64 + 1];      //!< ί�б�ע
  char szTargetTaAcct[6 + 1];      //!< ���ַ����׵�Ԫ
  char szTargetTransAcct[10 + 1];  //!< ���ַ�֤ȯ�ʻ�
  char llAgreementId[20 + 1];      //!< �ɽ�Լ����
};

//L3015209��������
struct ST_NQWTMatchedInfo_Codes
{
  char szMatchTime[9];             //!< �ɽ�ʱ��
  int  nOrderDate;                 //!< ί������
  int  nOrderSn;                   //!< ί�����
  char szOrderID[22 + 1];          //!< ��ͬ���
  int nStkBiz;                     //!< ֤ȯҵ��
  char szStkCode[8 + 1];           //!< ֤ȯ����
  double dOrderPrice;              //!< ί�м۸�
  __int64 nOrderQty;               //!< ί������
  char chCancelReason[3];          //!< ����ԭ��
  char chIsWithdraw[1 + 1];        //!< ������־
  char szMatchedSN[16 + 1];        //!< �ɽ����
  double dMatchedPrice;            //!< �ɽ��۸�
  int nMatchedQty;                 //!< �ɽ�����
  char szTargetTaAcct[6 + 1];      //!< ���ַ����׵�Ԫ
  char szTargetTransAcct[10 + 1];  //!< ���ַ�֤ȯ�ʻ�
};
//�ϱʳֲֳɱ���Ϣ
struct ST_InvStkBcostRltInfo
{
  int nAssetID;            //!< �ʲ���Ԫ
  int nIntOrg;             //!< �ڲ�����
  char szStkCode[8 + 1];   //!< ֤ȯ����
  char szStkName[16 + 1];  //!< ֤ȯ����
  char szTrdAcct[10 + 1];  //!< �����˻�
  __int64 llStkBlnPre;     //!< �ճ������
  double  dStkBcostPre;    //!< �ճ��ֲֳɱ�
  double  dCostPricePre;   //!< �ճ��ɱ���
  __int64 llInvStkBln;     //!< ʵʱ�����
  double  dInvBcostRlt;    //!< ʵʱ�ֲֳɱ�
  double  dInvCostPrice;   //!< ʵʱ�ɱ���
  double  dMktVal;         //!< ��ֵ
  double  dInvStkFpl;      //!< ����ӯ��
  double  dRealIncome;     //!< ��ʵ������
  double  dRealIncomeT;    //!< �ۼ���ʵ������
  __int64 llBuyQtyT;       //!< ����������
  double  dBuyAmtT;        //!< �����ܽ��
  __int64 llSellQtyT;      //!< ����������
  double  dSellAmtT;       //!< �����ܽ��
};