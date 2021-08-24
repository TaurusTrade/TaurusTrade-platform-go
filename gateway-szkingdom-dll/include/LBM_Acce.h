/*************************************************
* Copyright (c) 2014,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：LBM_Acce.h
* 摘    要：LBM 提速类
*
* 当前版本：1.0
* 作    者：冯伟灿
* 完成日期：2015年12月26日
**************************************************/
#pragma once
#include "Define.h"
#include "Define_Acce.h"
#include "LBM_Define.h"
/** 
* @ingroup AlgoPlug
* @brief 提速类
*/
class  LBM_Acce
{
public:
  LBM_Acce(void);
  virtual ~LBM_Acce(void);

  /* 设置LBM输出结果的字段
  * @param[in,out] mapOutPutField LBM输出字段结果集
  * @return
  */
  void SetAllOutParam(map<string, vector<string>> &mapOutPutField); 
  /* 设置单个LBM输出结果的字段
  * @param[in] pszLBMNum LBM编号
  * @param[in] nCount LBM输出字段个数
  * @param[in] FiledName LBM输出字段数组
  * @param[in,out] mapOutPutField LBM输出字段结果集
  * @return
  */
  void SetOneOutParam(const char *pszLBMNum, const int nCount, char *FiledName[], map<string, vector<string>> &mapOutPutField);
  /* 得到某个LBM的输出结果字段
  * @param[in] pszLBMNum LBM编号
  * @param[in] mapOutPutField 所有的LBM输出字段结果集
  * @param[in,out] vctOutPutField 某个LBM输出字段结果集
  * @return
  */
  bool GetOutParam(const char *pszLBMNum, map<string, vector<string>> &mapOutPutField, vector<string> &vctOutPutField); 
  /**读取字符串的字段值
  * @param[in] index 同一类型的第几条记录
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] pResult 字段值
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, char *pResult);
  /**读取字符型的字段值
  * @param[in] index 同一类型的第几条记录
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] pResult 字段值
  * @return 
  */
  void GetLBMFieldValue_Char(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, char *pResult);
  /**读取short型的字段值
  * @param[in] index 同一类型的第几条记录
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] sResult 字段值
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, short &sResult);
  /**读取int型的字段值
  * @param[in] index 同一类型的第几条记录
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] nResult 字段值
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, int &nResult);
  /**读取long型的字段值
  * @param[in] index 同一类型的第几条记录
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] lResult 字段值
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, long &lResult);
  /**读取__int64型的字段值
  * @param[in] index 同一类型的第几条记录
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] llResult 字段值
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, __int64 &llResult);
  /**读double型的字段值
  * @param[in] index 同一类型的第几条记录
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] dResult 字段值
  * @return 
  */
  void GetLBMFieldValue(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, const char *pKey, double &dResult);

  /**读取字符串的字段值
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] pResult 字段值
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, char *pResult);
  /**读取字符型的字段值
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] pResult 字段值
  * @return 
  */
  void GetLBMFieldValue_Char(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, char *pResult);

  /**读取short型的字段值
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] sResult 字段值
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, short &sResult);
  /**读取int型的字段值
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] nResult 字段值
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, int &nResult);
  /**读取long型的字段值
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] lResult 字段值
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, long &lResult);
  /**读取__int64型的字段值
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] llResult 字段值
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, __int64 &llResult);
  /**读double型的字段值
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] pKey 字段名
  * @param[in,out] dResult 字段值
  * @return 
  */
  void GetLBMFieldValue(map<string, map<string, string>>::iterator iterLBMOutput, const char *pKey, double &dResult);

  /**得到LBM的单条记录相关数据
  * @param[in] pszLBMNum LBM编号
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容，以自定义的结构体存放
  * @return  是否执行成功
  */
  bool GetRecord_LBM(const char *pszLBMNum, map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);

  /**得到LBM的单条记录相关数据
  * @param[in] pszLBMNum LBM编号
  * @param[in] index 同一类型的第几条记录
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容，以自定义的结构体存放，以自定义的结构体存放
  * @return 是否执行成功
  */
  bool GetRecord_LBM(const char *pszLBMNum, const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  /**释放指针数组的内存
  * @param[in] pInfo 要释放内存的指针数组
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
  /**处理LBM的返回结果
  * @param[in] pszLBMNum LBM编号
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] mapLBMOutput LBM返回记录内容 
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 返回结果
  * @param[in,out] nTickItem 返回记录数
  * @return
  */
  void DealLbm_LBMResult(const char * pszLBMNum, vector<string> &vctOutPutField, map<string, map<string, string>> &mapLBMOutput, const int nDataSize, BYTE **pInfo, int &nTickItem);

  /**处理LBM的返回结果
  * @param[in] pszLBMNum LBM编号
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] mapLBMOutput LBM返回记录内容
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 返回结果
  * @param[in,out] nTickItem 返回记录数
  * @return
  */
  void DealLbm_LBMResult(const char * pszLBMNum, vector<string> &vctOutPutField, map<string, vector<map<string, string>>> &mapLBMOutput, const int nDataSize, BYTE **pInfo, int &nTickItem);  
  /**得到L3014026的单条记录相关数据
  * @param[in] iterLBMOutput LBM某条记录内容
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3014026(map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  /**得到L3010091的单条记录相关数据
  * @param[in] iterLBMOutput LBM某条记录内容
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3010091(map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  /**得到L3015200的单条记录相关数据
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */

  void GetRecord_L3015200(map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  /**得到L3015200的单条记录相关数据
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3015201(map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);

  /**得到L3015202的单条记录相关数据
  * @param[in] index 入参iterLBMOutput中vector的索引
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3015202(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**得到L3015203的单条记录相关数据
  * @param[in] index 入参iterLBMOutput中vector的索引
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3015203(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**得到L3015204的单条记录相关数据
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3015204(map<string, map<string, string>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**得到L3015205的单条记录相关数据
  * @param[in] index 入参iterLBMOutput中vector的索引
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3015205(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**得到L3015206的单条记录相关数据
  * @param[in] index 入参iterLBMOutput中vector的索引
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3015206(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**得到L3015207的单条记录相关数据
  * @param[in] index 入参iterLBMOutput中vector的索引
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3015207(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**得到L3015210的单条记录相关数据
  * @param[in] index 入参iterLBMOutput中vector的索引
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3015210(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);

  /**设置错误提示语
  * @param[in] pszLBMNum LBM编号
  * @param[in] iRet LBM错误编码
  * @param[in] pErr LBM错误提示语
  */
  void SetErrMsg(const char *pszLBMNum, const int iRet, char *pErr);
  
  /**得到变化了的普通行情
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pDeList 输出的结果集
  * @param[in,out] nDeCount 输出的结果集个数
  * @param[in] pScList 输入的结果集
  * @param[in] nScCount 输入的结果集个数
  * @param[in] bBackAllHQ 是否定时返回行情
  * @param[in] mapNqTick_Codes 普通行情快照
  * @return
  */
  void GetChange_NQTick(const int nDataSize, ST_NQInfo_Codes **pDeList, int &nDeCount, ST_NQInfo_Codes *pScList, const int nScCount, bool bBackAllHQ, std::map<string, ST_NQInfo_Codes> &mapNqTick_Codes);
  
  /**得到变化了的做市行情
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pDeList 输出的结果集
  * @param[in,out] nDeCount 输出的结果集个数
  * @param[in] pScList 输入的结果集
  * @param[in] nScCount 输入的结果集个数
  * @param[in] bBackAllHQ 是否定时返回行情
  * @param[in] mapZsTick_Codes 做市行情快照
  * @return
  */
  void GetChange_ZSTick(const int nDataSize, STK_NQ_ZSXX **pDeList, int &nDeCount, ST_ZSInfo_Codes *pScList, const int nScCount, bool bBackAllHQ, std::map<string, STK_NQ_ZSXX> &mapZsTick_Codes);
  
  /** 
  * 设置普通行情Tick
  * @param[out] pDeTick 返回行情TICK
  * @param[in] pScInfo 普通行情信息
  * @param[in] bBackAllHQ 是否定时返回行情
  * @return 普通行情是否有变化
  */
  bool SetTick_Acce(ST_NQInfo_Codes * pDeTick, ST_NQInfo_Codes *pScInfo, bool bBackAllHQ);
  
  /** 
  * 设置做市/投资行情Tick
  * @param[out] pDeTick 返回行情TICK
  * @param[in] pScInfo 做市/投资行情信息
  * @param[in] bBackAllHQ 是否定时返回行情
  * @return 做市行情是否有变化
  */
  bool SetTick_Acce(STK_NQ_ZSXX * pDeTick, ST_ZSInfo_Codes *pScInfo, bool bBackAllHQ);

  ///< fengweican alter 5.5 增加自营股票处理
  /**得到L3015208的单条记录相关数据
  * @param[in] index 入参iterLBMOutput中vector的索引
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3015208(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
  
  /**得到L3015209的单条记录相关数据
  * @param[in] index 入参iterLBMOutput中vector的索引
  * @param[in] iterLBMOutput 从KCBP句柄读到的记录内容，它是以map<string,string>的结构存放
  * @param[in] vctOutPutField 输出参数列表
  * @param[in] nDataSize 数据类型长度
  * @param[in,out] pInfo 转换过的数据内容
  * @return 
  */
  void GetRecord_L3015209(const int index, map<string, vector<map<string, string>>>::iterator iterLBMOutput, vector<string> &vctOutPutField, const int nDataSize, BYTE *pInfo);
};

