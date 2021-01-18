#include <QCoreApplication>
#include<QDebug>
#include<QFile>
#include"tool.h"
#include"postgresql.h"
#include"project.h"
#include"entry.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    entry::entries("../workspace/test/");
    //project * p=new project("9","../workspace/test/");
       //qDebug().noquote()<< p->f[0]->c[0]->function_name<<endl<<p->f[0]->c[0]->function_num;
    //postgreSQL * sql=new postgreSQL();
    //sql->submit(p);
    //delete p;
//    postgreSQL::driver_test();
//    postgreSQL *p= new postgreSQL();

//     qDebug().noquote()<<f->c[1]->function_used;
//     qDebug().noquote()<<file_name;
//     qDebug().noquote()<<file_addr;
    //MainWindow w;
    //w.show();
    return a.exec();
}
