/*************************************************
* Copyright (c) 2014,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：LBM_Base.h
* 摘    要：LBM基础调用
*
* 当前版本：1.0
* 作    者：陈牧
* 完成日期：2014年5月20日
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

#define OEM_PRODUCT_NAME  "提速版"   //fengwc alter 1.18
//用于线程池的回调函数参数
struct Ksmmapi_ThreadPool
{
  BOOL isBusy;               //当前hKESBHandle是否正在使用
  int nConnectStatus;       ///<主线程连接状态，0--初始化 1--已连接 -1--断开连接
  int nConnectRet;            ///错误码
  KCBPCLIHANDLE hKcbpHandle;     //KESB连接句柄  
};
/**
* @ingroup AlgoPlug
* @brief LBM基础实现类
*/
class LBM_Base
{
public:
  LBM_Base(void);
  virtual ~LBM_Base(void);

public:
  void GetProgramPath(char* szFileName);
  /**
  * 获取程序版本号
  * @param[in] szFile exe文件名
  * @param[out] szVersion     版本号
  * @return
  */
  void GetFileVersion(const char* szFile, char* szVersion);
  /**
  * 获取错误信息
  * @param[in] nErrorType  错误类型
  * @return 错误信息
  */
  char* GetLastError(short nErrorType);
  char* GetAlgoName() { return m_szAlgoName; }
  void SetAlgoName(const char* szAlgoName);
  int GetIdleHandle(vector<Ksmmapi_ThreadPool>& vctThredpool);
  void SetPoolStatus(vector<Ksmmapi_ThreadPool>& vctThredpool, const int nIndex, BOOL bStatus = FALSE);
  /**
  * 调用LBM
  * @param[in] szLBM 调用的LBM号
  * @param[in] pParamList 输入调用LBM的入参
  * @param[in] nSize 参数数量
  * @param[in,out] hKCBPHandle  KCBP连接
  * @return 调用LBM成功或失败
  */
  int CallLBM(char* szLBM, PARAM_LIST* pParamList, int nSize, KCBPCLIHANDLE hKCBPHandle);
  /************fengwc alter 1.18 获取LBM结果***********/
  /**
  * 获取LBM结果，M*N*L的结果集
  * @param[in] pszLBMNum 调用的LBM号
  * @param[in] pszKey 结果集索引字段
  * @param[in] vecLBMOutputParam 输出字段数组
  * @param[in] hKCBPHandle  KCBP连接
  * @param[in,out] mapLBMOutput 获取的LBM数据
  * @return 0：执行成功 非0：错误码
  */
  int GetAllInvokeResult(const char* pszLBMNum, const char* pszKey, vector<string>& vecLBMOutputParam, KCBPCLIHANDLE hKCBPHandle, map<string, vector<map<string, string>>>& mapLBMOutput);
  /**
  * 获取LBM结果，M*N的结果集
  * @param[in] pszLBMNum 调用的LBM号
  * @param[in] pszKey 结果集索引字段
  * @param[in] vecLBMOutputParam 输出字段数组
  * @param[in] hKCBPHandle  KCBP连接
  * @param[in,out] mapLBMOutput 获取的LBM数据
  * @return 0：执行成功 非0：错误码
  */
  int GetFirstInvokeResult(const char* pszLBMNum, const char* pszKey, vector<string>& vecLBMOutputParam, KCBPCLIHANDLE hKCBPHandle, map<string, map<string, string>>& mapLBMOutput);
  PST_tagLbmParam& GetOrgPara() { return m_pOrgPara; }
  KCBPCLIHANDLE& GetKcbpHandle() { return m_hKCBPHandle; }
  MUTEX_T& GetcallLBMLock() { return m_callLBMLock; }
  ///< fengweican alter 5.5 增加自营股票处理
  /**
  * 获取LBM结果每个字段的值
  * @param[in] hKCBPHandle KCBP句柄
  * @param[in] pszFieldParam 参数代码
  * @param[in] nValue 字段值
  * @return 0：执行成功 非0：错误码
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, int& nValue);
  /**
  * 获取LBM结果每个字段的值
  * @param[in] hKCBPHandle KCBP句柄
  * @param[in] pszFieldParam 参数代码
  * @param[in] lValue 字段值
  * @return 0：执行成功 非0：错误码
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, long& lValue);
  /**
  * 获取LBM结果每个字段的值
  * @param[in] hKCBPHandle KCBP句柄
  * @param[in] pszFieldParam 参数代码
  * @param[in] dValue 字段值
  * @return 0：执行成功 非0：错误码
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, double& dValue);
  /**
  * 获取LBM结果每个字段的值
  * @param[in] hKCBPHandle KCBP句柄
  * @param[in] pszFieldParam 参数代码
  * @param[in] llValue 字段值
  * @return 0：执行成功 非0：错误码
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, __int64& llValue);
  /**
  * 获取LBM结果每个字段的值
  * @param[in] hKCBPHandle KCBP句柄
  * @param[in] pszFieldParam 参数代码
  * @param[in] sValue 字段值
  * @return 0：执行成功 非0：错误码
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, short& sValue);
  /**
  * 获取LBM结果每个字段的值
  * @param[in] hKCBPHandle KCBP句柄
  * @param[in] pszFieldParam 参数代码
  * @param[in] szValue 字段值
  * @return 0：执行成功 非0：错误码
  */
  int GetKcbpColValue(KCBPCLIHANDLE hKCBPHandle, char* pszFieldParam, char* szValue);
private:
  PST_tagLbmParam m_pOrgPara;   //!< LBM调用机构参数
  KCBPCLIHANDLE m_hKCBPHandle;  //!< 主线程KCBP句柄  
  MUTEX_T m_callLBMLock;        //!< 主线程读LBM锁 
  char m_szAlgoName[64 + 1];    //!< 产品名称
};

