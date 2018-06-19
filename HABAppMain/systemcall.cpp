#include "systemcall.h"

SystemCall::SystemCall(){

}

SystemCall::~SystemCall(){

}

int SystemCall::_send_cmd(std::string cmd_str){

    FILE *fp;
    char buff[MAX_BUFFER_LENGTH];
    if((fp = popen(cmd_str.c_str(), "r")) != NULL) {
        while(fgets(buff, sizeof(buff), fp) != NULL){
            std::string tmp_str = std::string(buff);
            _cmd_buff.push_back(tmp_str);
        }
        pclose(fp);
        return 0;
    }
    return -1;

}

void SystemCall::_clear_buff(){
    std::vector<std::string>().swap(_cmd_buff);
}

int SystemCall::WriteBuffConsole(std::string cmd_str){

    _send_cmd(cmd_str);
    for(auto it = _cmd_buff.begin(); it != _cmd_buff.end(); it++)
        std::cout << *it << std::endl;
    _clear_buff();

}
