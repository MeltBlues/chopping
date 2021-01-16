#include "project.h"

project::project(QString name,QString addr)
{

    this->name=name;

    this->entry_URL=addr;
    this->entry_URL.append(name);

    tool::find_file(this->name,addr,&this->f_name,&this->f_addr);

    this->f_num=this->f_name.length();

    this->f=(file **)malloc(sizeof (file * )*(this->f_num));
//    qDebug().noquote()<<this->f_addr;
//    qDebug().noquote()<<this->f_name;
    for(int i=0;i<this->f_num;i++){
        this->f[i]=new file(this->f_name[i],this->f_addr[i]);
    }

}
