#ifndef SYSTEMCALL_H
#define SYSTEMCALL_H

#include "stdafx.h"

#define MAX_BUFFER_LENGTH 1024
#define CMD_TIMEOUT_MSEC 100

class SystemCall{

private:
    // コマンド標準出力の一時保存ファイル(バッファの代わり)
    //constexpr static std::string _tmpfile = "./.tmp";
    // コマンド群
    //constexpr static std::string _cmd_netmanage = "nmcli";

    // 読み込んだコマンドの標準出力の一時保存（一行づつ）
    std::vector<std::string> _cmd_buff;

private:
    // コマンド送信
    int _send_cmd(std::string cmd_str);
    // 一時ファイル消去(vectorのメモリリーク対策)
    void _clear_buff();

public:

    // コンストラクタ
    SystemCall();

    // デストラクタ
    ~SystemCall();

    // ネットワーク関連API

    int NM_GetInterfaceList(std::vector<std::string> &if_list);
    int NM_GetSSIDList(std::vector<std::string> &ssid_list);
    int NM_GetStatus(std::string &if_name, std::string &);

    // 指定したifに指定したconfigで接続する。
    // GUI上はIP設定画面はインターフェースによらないが、内部ではインターフェースごとに管理されている。
    // 接続要求の際に初めて設定が反映されるようにする。
    int NM_GetConnection(std::string &if_name, NetWorkConfigItem &config);
    int NM_SetConfig(std::string if_name, std::string );

    // デバッグ用
    int WriteBuffConsole(std::string cmd_str);

};

#endif // SYSTEMCALL_H
