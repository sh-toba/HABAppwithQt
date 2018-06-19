#include <QCoreApplication>
#include "systemcall.h"

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    SystemCall syscall;
    syscall.WriteBuffConsole("ls -l");

    /*
    while(true){
        std::cout << ">> Please Input Command." << std::endl;

        std::string cmd_str;
        std::cin >> cmd_str;

        //

        std::cout << ">> Please Input 'R', if you wish continue." << std::endl;
        std::string s;
        std::cin >> s;
        if(s != "R") break;
    }
    std::cout << ">> End of main function." << std::endl;
*/
    //return 0;
    return a.exec();
}
