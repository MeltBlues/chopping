#include "project.h"

project::project(QString name,QString addr)
{

    this->name=name;

    this->entry_URL=addr;
    this->entry_URL.append(name);

    tool::find_file(this->name,addr,&this->f_name,&this->f_addr,1);

    this->f_num=this->f_name.length();

    this->f=(file **)malloc(sizeof (file * )*(this->f_num));
//    qDebug().noquote()<<this->f_addr;
//    qDebug().noquote()<<this->f_name;
    for(int i=0;i<this->f_num;i++){
        this->f[i]=new file(this->f_name[i],this->f_addr[i]);
    }

    this->statistic_c();
    this->deal_include();

}

void project::statistic_c(){//statistic all c in this project
    this->c_num=0;
    for(int i=0;i<this->f_num;i++){
        this->c_num += this->f[i]->c_num;//statistic num and name
        this->c_name.append(this->f[i]->c_name);
    }

    //statistic include
    this->c_include=(QStringList *)malloc(sizeof (QStringList)*this->c_num);
    int k=0;//k is the number of c
    for(int i=0;i<this->f_num;i++){
        for(int j=0;j<this->f[i]->c_num;j++){
            this->c_include[k]=this->f[i]->c[j]->include_name;
            k++;
        }
    }

    //statistic all include
    for(int i=0;i<this->c_include->length();i++){
        for(int j=0;j<this->c_include[i].length();j++){
            if(this->c_include_all.indexOf(this->c_include[i][j])<0){
                this->c_include_all.append(this->c_include[i][j]);
            }
        }
    }

}

void project::deal_include(){
    //create a table to save including messages
    //self
    this->c_include_self_table=(char **)malloc(sizeof (char *)*this->c_num);
    for(int i=0;i<this->c_num;i++){
        this->c_include_self_table[i]=(char *)malloc(sizeof (char)*this->c_num);
    }
    //all
    this->c_include_all_table=(char **)malloc(sizeof (char *)*this->c_num);
    for(int i=0;i<this->c_num;i++){
        this->c_include_all_table[i]=(char *)malloc(sizeof (char)*this->c_include_all.length());
    }

    //fill table
    for(int i=0;i<this->c_num;i++){
        for(int j=0;j<this->c_include[i].length();j++){
            //self
            int k=this->c_name.indexOf(this->c_include[i][j]);
            if(k>=0){
                this->c_include_self_table[i][k]='1';
            }else{
                this->c_include_self_table[i][k]='0';
            }
            //all
            k=this->c_include_all.indexOf(this->c_include[i][j]);
            if(k>=0){
                this->c_include_all_table[i][k]='1';
            }else{
                this->c_include_all_table[i][k]='0';
            }
        }
    }
}

