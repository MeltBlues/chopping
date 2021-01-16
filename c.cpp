#include "c.h"

C::C(QString name,QString addr)
{
    this->name=name;
     this->url=addr;
    this->url.append(this->name);
    this->url.append(".c");

    this->read_source();

    //shell *s=new shell();
    //qDebug().noquote()<<this->url;

    QString cmd =shell::ctags_cmd(this->url,1);
    //qDebug().noquote()<<cmd;
    //QString cmd ="cflow -T -m sub -n ../main.c";
    this->ctags_result= shell::exe(cmd);
    this->function_name= shell::split(this->ctags_result,"\n");

    cmd =shell::ctags_cmd(this->url,3);
    this->ctags_result= shell::exe(cmd);
    this->function_star= shell::split(this->ctags_result,"\n");

    for(int i=0;i<this->function_star.length();i++){
        this->function_source.append("");
        int star=this->function_star[i].toInt()-1;
        //qDebug().noquote()<<star;
        int end = star;
        int zey[2]={0,0};
        for(;end<this->source.length();end++){
            QString line=this->source[end];
            //qDebug().noquote()<<line;
            if(line!=""){
                for(int j=0;j<line.length();j++){
                    if(line[j] == "{") zey[0]++;
                    if(line[j] == "}") zey[1]++;
                }
            }
            this->function_source[i].append(line);
            if(zey[0] != 0 && zey[1] == zey[0] ) break;
        }
        this->function_end.append(QString(end+1));
        //qDebug().noquote()<<end;
    }

    QStringList cmdList=shell::cflow_cmd(this->url,this->function_name,"tree2dotx");
    for(int i=0;i<cmdList.length();i++){
        this->function_used.append( shell::exe(cmdList[i]));
    }

    this->function_num=this->function_name.length();

}

void C::clear(){
    this->name.clear();
    this->source.clear();
    this->ctags_result.clear();
    this->function_end.clear();
    this->function_name.clear();
    this->function_star.clear();
    this->function_used.clear();
    this->function_source.clear();
}

void C::read_source(){


    QFile file(this->url);
    if(!file.open(QIODevice::Text | QIODevice::ReadWrite)){
        qDebug()<<"ERROR: Can't open the file!"<<endl;
    }

    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        //qDebug().noquote()<<str;
        this->source.append(str);
    }

}
