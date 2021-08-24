import ctypes  
so = ctypes.cdll.LoadLibrary   
lib = so("./extern_demo.dll")   

# print(lib.Add)
# print(lib.Add(3,5))

# # /** 初始化信息 ST_tagInitInfo (Define.h) */
# # typedef struct
# # {
# #   char szUserName[32];      //!< 操作员用户名
# #   char szPassword[32];      //!< 操作员密码

# #   // Add by chenmu 2015-1-22 9:50 增加行情数据返回方式
# #   bool bBackAllHQ;          //!< 行情返回方式，false默认返回最新变化的行情，true定时返回所有行情
# #   // Add by chenmu 2015-1-22 Over
# #   bool bLocalAddressType;   //!< KCBP版本号，如果版本号低于1106，请填写该元素，等于或高于此版本可不填
# # }ST_tagInitInfo, * PST_tagInitInfo;
class ST_tagInitInfo(ctypes.Structure):
    _fields_ = [
        ("szUserName", ctypes.c_char*32),
        ("szPassword", ctypes.c_char*32),
        ("bBackAllHQ", ctypes.c_bool),
        ("bLocalAddressType", ctypes.c_bool),
    ]

# int InitPluginUseCfg(PST_tagInitInfo pInitInfo, int nThreads = 1, char* pszLogName = "", char* pszAlgoName = OEM_PRODUCT_NAME);
#print(lib.InitPluginUseCfg.argtypes)
#print(lib.InitPluginUseCfg.restype)

lib.InitPluginUseCfg.argtypes = (
    ctypes.POINTER(ST_tagInitInfo), 
    # ctypes.c_int, 
    # ctypes.c_char_p, 
    # ctypes.c_char_p,
)
print(lib.InitPluginUseCfg.argtypes)
print(lib.InitPluginUseCfg.restype)


# # typedef struct
# # {
# #   char  szUserName[20];      //!< 用户名
# #   char  szPassword[20];      //!< 密码
# #   char  szIPAddress[20];     //!< 登录ip
# #   char  szServer[20];        //!< 服务器名
# #   int   nPort;               //!< 端口
# #   char  szReq[20];           //!< 请求队列
# #   char  szAns[20];           //!< 应答队列
# # }ST_tagKCBP_CONFIG, * PST_tagKCBP_CONFIG;
# class ST_tagKCBP_CONFIG(ctypes.Structure):
#     _fields_ = [
#         ("szUserName", ctypes.c_char*20),
#         ("szPassword", ctypes.c_char*20),
#         ("szIPAddress", ctypes.c_char*20),
#         ("szServer", ctypes.c_char*20),
#         ("nPort", ctypes.c_int),
#         ("szReq", ctypes.c_char*20),
#         ("szAns", ctypes.c_char*20),
#     ]

# # int InitPlugin(PST_tagInitInfo pInitInfo, ST_tagKCBP_CONFIG& tagKcbpConfig, int nThreads = 1, char* pszLogName = "", char* pszAlgoName = OEM_PRODUCT_NAME, int bLogOpenFlag = 0); //fengwc alter 7.27
# lib.InitPlugin.argtypes = (
#     ctypes.POINTER(ST_tagInitInfo), 
#     ctypes.POINTER(ST_tagKCBP_CONFIG), 
#     # ctypes.c_int, 
#     # ctypes.c_char_p, 
#     # ctypes.c_char_p,
#     # ctypes.c_char_p,
# )


InitInfo = ST_tagInitInfo()
InitInfo.szUserName=bytes("10026", encoding = "utf8")
InitInfo.szPassword=bytes("888888", encoding = "utf8")
InitInfo.bBackAllHQ = False
InitInfo.bLocalAddressType = False

#pInitInfo = ctypes.byref(InitInfo)
pInitInfo = ctypes.pointer(InitInfo)

print(pInitInfo)

ret = lib.InitPluginUseCfg(pInitInfo)
print(ret)

# kcbp_config = ST_tagKCBP_CONFIG()
# kcbp_config.szUserName=bytes("KCXP00", encoding = "utf8")
# kcbp_config.szPassword=bytes("888888", encoding = "utf8")
# kcbp_config.szIPAddress=bytes("172.16.129.62", encoding = "utf8")
# kcbp_config.szServer=bytes("KCBP1", encoding = "utf8")
# kcbp_config.nPort=21000
# kcbp_config.szReq=bytes("req_market", encoding = "utf8")
# kcbp_config.szAns=bytes("ans_market", encoding = "utf8")

# pKcbpConfig = ctypes.pointer(kcbp_config)

# ret = lib.InitPluginUseCfg(pInitInfo, pKcbpConfig)
# print(ret)

# # char* GetAPILastError(short nErrorType);
# # print(lib.GetAPILastError.argtypes)
# # print(lib.GetAPILastError.restype)
# lib.GetAPILastError.argtypes = (ctypes.c_short,)
# lib.GetAPILastError.restype = ctypes.c_char_p
# print(lib.GetAPILastError.argtypes)
# print(lib.GetAPILastError.restype)


# info =lib.GetAPILastError(0)


# print(info)
# print(ctypes.string_at(info,-1) )