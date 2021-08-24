/*************************************************
* Copyright (c) 2014,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�LBM_Acce.h
* ժ    Ҫ��LBM ������
*
* ��ǰ�汾��1.0
* ��    �ߣ���ΰ��
* ������ڣ�2015��12��26��
**************************************************/
#pragma once
#include "Define.h"
#include "Define_Acce.h"
#include "LBM_Define.h"
/** 
* @ingroup AlgoPlug
* @brief ������
*/
class  LBM_Acce
{
public:
  LBM_Acce(void);
  virtual ~LBM_Acce(void);

  /* ����LBM���������ֶ�
  * @param[in,out] mapOutPutField LBM����ֶν����
  * @return
  */
  void SetAllOutParam(map<string, vector<string>> &mapOutPutField); 
  /* ���õ���LBM���������ֶ�
  * @param[in] pszLBMNum LBM���
  * @param[in] nCount LBM����ֶθ���
  * @param[in] FiledName LBM����ֶ�����
  * @param[in,out] mapOutPutField LBM����ֶν����
  * @return
  */
  void SetOneOutParam(const char *pszLBMNum, const int nCount, char *FiledName[], map<string, vector<string>> &mapOutPutField);
  /* �õ�ĳ��LBM���������ֶ�
  * @param[in] pszLBMNum LBM���
  * @param[in] mapOutPutField ���е�LBM����ֶν����
  * @param[in,out] vctOutPutField ĳ��LBM����ֶν����
  * @return
  */
  bool GetOutParam(const char *pszLBMNum, map<string, vector<string>> &mapOutPutField, vector<string> &vctOutPutField); 
  /**��ȡ�ַ������ֶ�ֵ
  * @param[in] index ͬһ���͵ĵڼ�����¼
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] pResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, char *pResult);
  /**��ȡ�ַ��͵��ֶ�ֵ
  * @param[in] index ͬһ���͵ĵڼ�����¼
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] pResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue_Char(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, char *pResult);
  /**��ȡshort�͵��ֶ�ֵ
  * @param[in] index ͬһ���͵ĵڼ�����¼
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] sResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, short &sResult);
  /**��ȡint�͵��ֶ�ֵ
  * @param[in] index ͬһ���͵ĵڼ�����¼
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] nResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, int &nResult);
  /**��ȡlong�͵��ֶ�ֵ
  * @param[in] index ͬһ���͵ĵڼ�����¼
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] lResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, long &lResult);
  /**��ȡ__int64�͵��ֶ�ֵ
  * @param[in] index ͬһ���͵ĵڼ�����¼
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] llResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, __int64 &llResult);
  /**��double�͵��ֶ�ֵ
  * @param[in] index ͬһ���͵ĵڼ�����¼
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] dResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, double &dResult);

  /**��ȡ�ַ������ֶ�ֵ
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] pResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, char *pResult);
  /**��ȡ�ַ��͵��ֶ�ֵ
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] pResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue_Char(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, char *pResult);

  /**��ȡshort�͵��ֶ�ֵ
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] sResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, short &sResult);
  /**��ȡint�͵��ֶ�ֵ
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] nResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, int &nResult);
  /**��ȡlong�͵��ֶ�ֵ
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] lResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, long &lResult);
  /**��ȡ__int64�͵��ֶ�ֵ
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] llResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, __int64 &llResult);
  /**��double�͵��ֶ�ֵ
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] pKey �ֶ���
  * @param[in,out] dResult �ֶ�ֵ
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, double &dResult);

  /**�õ�LBM�ĵ�����¼�������
  * @param[in] pszLBMNum LBM���
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת�������������ݣ����Զ���Ľṹ����
  * @return  �Ƿ�ִ�гɹ�
  */
  bool GetRecord_LBM(const char *pszLBMNum, map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);

  /**�õ�LBM�ĵ�����¼�������
  * @param[in] pszLBMNum LBM���
  * @param[in] index ͬһ���͵ĵڼ�����¼
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת�������������ݣ����Զ���Ľṹ���ţ����Զ���Ľṹ����
  * @return �Ƿ�ִ�гɹ�
  */
  bool GetRecord_LBM(const char *pszLBMNum, const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  /**�ͷ�ָ��������ڴ�
  * @param[in] pInfo Ҫ�ͷ��ڴ��ָ������
  * @return
  */
  template<class T> void FreeMemory(T *pInfo)
  {
    if(pInfo != NULL)
    {
      delete[] pInfo;
      pInfo = NULL;
    }
  }
  /**����LBM�ķ��ؽ��
  * @param[in] pszLBMNum LBM���
  * @param[in] vctOutPutField ��������б�
  * @param[in] mapLBMOutput LBM���ؼ�¼���� 
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ���ؽ��
  * @param[in,out] nTickItem ���ؼ�¼��
  * @return
  */
  void DealLbm_LBMResult(const char * pszLBMNum, vector<string> &vctOutPutField, map<string, map<string, string>> &mapLBMOutput, const int nDataSize, BYTE **pInfo, int &nTickItem);

  /**����LBM�ķ��ؽ��
  * @param[in] pszLBMNum LBM���
  * @param[in] vctOutPutField ��������б�
  * @param[in] mapLBMOutput LBM���ؼ�¼����
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ���ؽ��
  * @param[in,out] nTickItem ���ؼ�¼��
  * @return
  */
  void DealLbm_LBMResult(const char * pszLBMNum, vector<string> &vctOutPutField, map<string, vector<map<string, string>>> &mapLBMOutput, const int nDataSize, BYTE **pInfo, int &nTickItem);  
  /**�õ�L3014026�ĵ�����¼�������
  * @param[in] iterLBMOutput LBMĳ����¼����
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3014026(map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  /**�õ�L3010091�ĵ�����¼�������
  * @param[in] iterLBMOutput LBMĳ����¼����
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3010091(map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  /**�õ�L3015200�ĵ�����¼�������
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */

  void GetRecord_L3015200(map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  /**�õ�L3015200�ĵ�����¼�������
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3015201(map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);

  /**�õ�L3015202�ĵ�����¼�������
  * @param[in] index ���iterLBMOutput��vector������
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3015202(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**�õ�L3015203�ĵ�����¼�������
  * @param[in] index ���iterLBMOutput��vector������
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3015203(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**�õ�L3015204�ĵ�����¼�������
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3015204(map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**�õ�L3015205�ĵ�����¼�������
  * @param[in] index ���iterLBMOutput��vector������
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3015205(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**�õ�L3015206�ĵ�����¼�������
  * @param[in] index ���iterLBMOutput��vector������
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3015206(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**�õ�L3015207�ĵ�����¼�������
  * @param[in] index ���iterLBMOutput��vector������
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3015207(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**�õ�L3015210�ĵ�����¼�������
  * @param[in] index ���iterLBMOutput��vector������
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3015210(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);

  /**���ô�����ʾ��
  * @param[in] pszLBMNum LBM���
  * @param[in] iRet LBM�������
  * @param[in] pErr LBM������ʾ��
  */
  void SetErrMsg(const char *pszLBMNum, const int iRet, char *pErr);
  
  /**�õ��仯�˵���ͨ����
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pDeList ����Ľ����
  * @param[in,out] nDeCount ����Ľ��������
  * @param[in] pScList ����Ľ����
  * @param[in] nScCount ����Ľ��������
  * @param[in] bBackAllHQ �Ƿ�ʱ��������
  * @param[in] mapNqTick_Codes ��ͨ�������
  * @return
  */
  void GetChange_NQTick(const int nDataSize, ST_NQInfo_Codes **pDeList, int &nDeCount, ST_NQInfo_Codes *pScList, const int nScCount, bool bBackAllHQ, std::map<string, ST_NQInfo_Codes> &mapNqTick_Codes);
  
  /**�õ��仯�˵���������
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pDeList ����Ľ����
  * @param[in,out] nDeCount ����Ľ��������
  * @param[in] pScList ����Ľ����
  * @param[in] nScCount ����Ľ��������
  * @param[in] bBackAllHQ �Ƿ�ʱ��������
  * @param[in] mapZsTick_Codes �����������
  * @return
  */
  void GetChange_ZSTick(const int nDataSize, STK_NQ_ZSXX **pDeList, int &nDeCount, ST_ZSInfo_Codes *pScList, const int nScCount, bool bBackAllHQ, std::map<string, STK_NQ_ZSXX> &mapZsTick_Codes);
  
  /** 
  * ������ͨ����Tick
  * @param[out] pDeTick ��������TICK
  * @param[in] pScInfo ��ͨ������Ϣ
  * @param[in] bBackAllHQ �Ƿ�ʱ��������
  * @return ��ͨ�����Ƿ��б仯
  */
  bool SetTick_Acce(ST_NQInfo_Codes * pDeTick, ST_NQInfo_Codes *pScInfo, bool bBackAllHQ);
  
  /** 
  * ��������/Ͷ������Tick
  * @param[out] pDeTick ��������TICK
  * @param[in] pScInfo ����/Ͷ��������Ϣ
  * @param[in] bBackAllHQ �Ƿ�ʱ��������
  * @return ���������Ƿ��б仯
  */
  bool SetTick_Acce(STK_NQ_ZSXX * pDeTick, ST_ZSInfo_Codes *pScInfo, bool bBackAllHQ);

  ///< fengweican alter 5.5 ������Ӫ��Ʊ����
  /**�õ�L3015208�ĵ�����¼�������
  * @param[in] index ���iterLBMOutput��vector������
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3015208(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**�õ�L3015209�ĵ�����¼�������
  * @param[in] index ���iterLBMOutput��vector������
  * @param[in] iterLBMOutput ��KCBP��������ļ�¼���ݣ�������map<string,string>�Ľṹ���
  * @param[in] vctOutPutField ��������б�
  * @param[in] nDataSize �������ͳ���
  * @param[in,out] pInfo ת��������������
  * @return 
  */
  void GetRecord_L3015209(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
};

