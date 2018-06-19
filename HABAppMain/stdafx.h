#ifndef STDAFX_H
#define STDAFX_H

#include <string>
#include <iostream>
#include <fstream>
// #include <stdio.h>
#include <stdlib.h>
#include <vector>

struct NetWorkConfigItem{
    bool is_dhcp;
    std::string ip;
    std::string gateway;
    std::string dns;
};

#endif // STDAFX_H
