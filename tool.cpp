#include "tool.h"

tool::tool()
{

}

void tool::find_file(QString name, QString addr, QStringList * file_name,QStringList * file_addr,int isrecurrence){
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
    //if recurrence

        QStringList find_list ;
        for(int i=0;i<exe_list.length();i++){
            if(exe_list[i][0]=="d"){

                find_list=shell::split(exe_list[i]," ");

                if(isrecurrence==1)
                tool::find_file(find_list[8],url+"/",file_name,file_addr,1);
                else{
                    file_name->append(find_list[8]);
                    file_addr->append(url);
                }

            }

        }


}

void tool::add_bar(QStringList * list){
    QString temp;
    for(int i=0;i<list->length();i++){
        temp=list->at(i);
        if(temp[temp.length()-1]!="/"){
            list[i].append("/");
        }
    }
}

void tool::add_bar(QString * addr){
    if(addr[addr->length()-1]!="/"){
        addr->append("/");
    }
}

QString tool::delect_space(QString str, int type){

    if(type==0) str.remove(QRegExp("\\s"));

    else if(type==1) str=str.simplified();

    return str;
}
