/*************************************************
* Copyright (c) 2014,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�LBM_Base.h
* ժ    Ҫ��LBM��������
*
* ��ǰ�汾��1.0
* ��    �ߣ�����
* ������ڣ�2014��5��20��
**************************************************/
#pragma once
#include "KCBPCli.h"
#include "LBM_Define.h"
#include "Define.h"
#define CONNECT_INIT 0
#define CONNECTED 1
#define CONNECT_DIS -1
#ifdef _WIN64
#define LBM_RESULT_NUM 0
#else
#define LBM_RESULT_NUM 1
#endif

#define OEM_PRODUCT_NAME  "���ٰ�"   //fengwc alter 1.18
//�����̳߳صĻص���������
struct Ksmmapi_ThreadPool
{
  BOOL isBusy;               //��ǰhKESBHandle�Ƿ�����ʹ��
  int nConnectStatus;       ///<���߳�����״̬��0--��ʼ�� 1--������ -1--�Ͽ�����
  int nConnectRet;            ///������
  KCBPCLIHANDLE hKcbpHandle;     //KESB���Ӿ��  
};
/**
* @ingroup AlgoPlug
* @brief LBM����ʵ����
*/
class LBM_Base
{
public:
  LBM_Base(void);
  virtual ~LBM_Base(void);

public:
  void GetProgramPath(char* szFileName);
  /**
  * ��ȡ����汾��
  * @param[in] szFile exe�ļ���
  * @param[out] szVersion     �汾��
  * @return
  */
  void GetFileVersion(const char* szFile, char* szVersion);
  /**
  * ��ȡ������Ϣ
  * @param[in] nErrorType  ��������
  * @return ������Ϣ
  */
  char* GetLastError(short nErrorType);
  char* GetAlgoName() { return m_szAlgoName; }
  void SetAlgoName(const char* szAlgoName);
  int GetIdleHandle(vector<Ksmmapi_ThreadPool>& vctThredpool);
  void SetPoolStatus(vector<Ksmmapi_ThreadPool>& vctThredpool, const int nIndex, BOOL bStatus = FALSE);
  /**
  * ����LBM
  * @param[in] szLBM ���õ�LBM��
  * @param[in] pParamList �������LBM�����
  * @param[in] nSize ��������
  * @param[in,out] hKCBPHandle  KCBP����
  * @return ����LBM�ɹ���ʧ��
  */
  int CallLBM(char* szLBM, PARAM_LIST* pParamList, int nSize, KCBPCLIHANDLE hKCBPHandle);
  /************fengwc alter 1.18 ��ȡLBM���***********/
  /**
  * ��ȡLBM�����M*N*L�Ľ����
  * @param[in] pszLBMNum ���õ�LBM��
  * @param[in] pszKey ����������ֶ�
  * @param[in] vecLBMOutputParam ����ֶ�����
  * @param[in] hKCBPHandle  KCBP����
  * @param[in,out] mapLBMOutput ��ȡ��LBM����
  * @return 0��ִ�гɹ� ��0��������
  */
  int GetAllInvokeResult(const char* pszLBMNum, const char* pszKey, vector<string>& vecLBMOutputParam, KCBPCLIHANDLE hKCBPHandle, map<string, vector<map<string, string>>>& mapLBMOutput);
  /**
  * ��ȡLBM�����M*N�Ľ����
  * @param[in] pszLBMNum ���õ�LBM��
  * @param[in] pszKey ����������ֶ�
  * @param[in] vecLBMOutputParam ����ֶ�����
  * @param[in] hKCBPHandle  KCBP����
  * @param[in,out] mapLBMOutput ��ȡ��LBM����
  * @return 0��ִ�гɹ� ��0��������
  */
  int GetFirstInvokeResult(const char* pszLBMNum, const char* pszKey, vector<string>& vecLBMOutputParam, KCBPCLIHANDLE hKCBPHandle, map<string, map<string, string>>& mapLBMOutput);
  PST_tagLbmParam& GetOrgPara() { return m_pOrgPara; }
  KCBPCLIHANDLE& GetKcbpHandle() { return m_hKCBPHandle; }
  MUTEX_T& GetcallLBMLock() { return m_callLBMLock; }
  ///< fengweican alter 5.5 ������Ӫ��Ʊ����
  /**
  * ��ȡLBM���ÿ���ֶε�ֵ
  * @param[in] hKCBPHandle KCBP���
  * @param[in] pszFieldParam ��������
  * @param[in] nValue �ֶ�ֵ
  * @return 0��ִ�гɹ� ��0��������
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, int& nValue);
  /**
  * ��ȡLBM���ÿ���ֶε�ֵ
  * @param[in] hKCBPHandle KCBP���
  * @param[in] pszFieldParam ��������
  * @param[in] lValue �ֶ�ֵ
  * @return 0��ִ�гɹ� ��0��������
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, long& lValue);
  /**
  * ��ȡLBM���ÿ���ֶε�ֵ
  * @param[in] hKCBPHandle KCBP���
  * @param[in] pszFieldParam ��������
  * @param[in] dValue �ֶ�ֵ
  * @return 0��ִ�гɹ� ��0��������
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, double& dValue);
  /**
  * ��ȡLBM���ÿ���ֶε�ֵ
  * @param[in] hKCBPHandle KCBP���
  * @param[in] pszFieldParam ��������
  * @param[in] llValue �ֶ�ֵ
  * @return 0��ִ�гɹ� ��0��������
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, __int64& llValue);
  /**
  * ��ȡLBM���ÿ���ֶε�ֵ
  * @param[in] hKCBPHandle KCBP���
  * @param[in] pszFieldParam ��������
  * @param[in] sValue �ֶ�ֵ
  * @return 0��ִ�гɹ� ��0��������
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, short& sValue);
  /**
  * ��ȡLBM���ÿ���ֶε�ֵ
  * @param[in] hKCBPHandle KCBP���
  * @param[in] pszFieldParam ��������
  * @param[in] szValue �ֶ�ֵ
  * @return 0��ִ�гɹ� ��0��������
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, char* szValue);
private:
  PST_tagLbmParam m_pOrgPara;   //!< LBM���û�������
  KCBPCLIHANDLE m_hKCBPHandle;  //!< ���߳�KCBP���  
  MUTEX_T m_callLBMLock;        //!< ���̶߳�LBM�� 
  char m_szAlgoName[64 + 1];    //!< ��Ʒ����
};

