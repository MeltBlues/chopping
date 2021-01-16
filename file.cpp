#include "file.h"

file::file(QString name,QString addr)
{

    this->name=name;

    this->URL=addr;
    this->URL.append(name);

    //shell * s = new shell();

    QString cmd = shell::ls_cmd(this->URL,"");
    QString result = shell::exe(cmd);
    this->c_name=shell::hold(shell::split(result,"\n"),".c");
    this->c_num=this->c_name.length();

    this->c=(C **)malloc  (sizeof (C * )*(this->c_num));
    //qDebug().noquote()<<this->c_name[0].left(this->c_name[0].length()-2);
    for(int i=0;i<this->c_num;i++){
        this->c[i]=new C(this->c_name[i].left(this->c_name[i].length()-2),this->URL+"/");
    }




}
