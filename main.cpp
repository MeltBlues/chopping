#include <QCoreApplication>
#include"shell.h"
#include<QDebug>
#include<QFile>
#include"c.h"
#include"file.h"
#include"tool.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

      //C *cfile = new C("main","../workspace/");
    file * f=new file("workspace","../");
    //QStringList * find=(QStringList * )malloc(sizeof(QStringList) *2);
//    QStringList  file_name;
//    QStringList  file_addr;
//        tool::find_file("workspace","../",&file_name,&file_addr);


//     qDebug().noquote()<<cfile->name;
//      qDebug().noquote()<<cfile->url;
//     qDebug().noquote()<<cfile->function_name;
//     qDebug().noquote()<<cfile->function_used;
//      qDebug().noquote()<<cfile->source;
//     qDebug().noquote()<<cfile->source[5];
//     qDebug().noquote()<<cfile->source[28];
//     qDebug().noquote()<<cfile->source[17];
//     qDebug().noquote()<<cfile->source[11];
//     qDebug().noquote()<<cfile->source[23];
//      qDebug().noquote()<<cfile->function_star;
//      QString test=cfile->function_star[1];
//     qDebug().noquote()<<test.toInt();
//      qDebug().noquote()<<cfile->function_source;
//    qDebug().noquote()<<f->URL;
    qDebug().noquote()<<f->c[0]->source;
    qDebug().noquote()<<f->c[1]->source;
     qDebug().noquote()<<f->c[0]->function_name;
    qDebug().noquote()<<f->c[1]->function_name;
//     qDebug().noquote()<<f->c[1]->name;
//     qDebug().noquote()<<f->c[1]->function_used;
//     qDebug().noquote()<<file_name;
//     qDebug().noquote()<<file_addr;

    return a.exec();
}
