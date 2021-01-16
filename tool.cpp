#include "tool.h"

tool::tool()
{

}

void tool::find_file(QString name, QString addr, QStringList * file_name,QStringList * file_addr){
    QString url=addr;
    url.append(name);

//    qDebug().noquote()<<name;
//    qDebug().noquote()<<addr;

    file_name->append(name);
    file_addr->append(addr);


    QString cmd=shell::ls_cmd(url,"-l");
    QString exe = shell::exe(cmd);
    QStringList exe_list = shell::split(exe,"\n");
    exe.clear();
    QStringList find_list ;
    for(int i=0;i<exe_list.length();i++){
        if(exe_list[i][0]=="d"){

            find_list=shell::split(exe_list[i]," ");
            tool::find_file(find_list[8],url+"/",file_name,file_addr);

        }

    }
}
