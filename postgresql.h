#ifndef POSTGRESQL_H
#define POSTGRESQL_H

#include<QCoreApplication>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlError>
#include<QSqlQuery>
#include<QString>
#include"project.h"
#include"file.h"
#include"c.h"

class postgreSQL
{
public:
    postgreSQL();
    static void driver_test();
    int sql_exe(QString);
    bool submit(project *);
    static QString callpro_cmd(project *);
    static QString callc_cmd(C *,QString,int);
    static QString callfunc_cmd(QString,QString,QString,QString,QString,int,int,int);
    QSqlDatabase *db;
};

#endif // POSTGRESQL_H
