#ifndef PROJECT_H
#define PROJECT_H

#include<QDebug>
#include"tool.h"
#include"shell.h"
#include"file.h"

class project
{
public:
    project(QString,QString);
    void statistic_c();
    void deal_include();
    QString name;
    QString entry_URL;
    int f_num;
    QStringList f_name;
    QStringList f_addr;
    file **f;
    int c_num;
    QStringList c_name;
    QStringList *c_include;
    QStringList c_include_all;

    char **c_include_all_table;

    char **c_include_self_table;

};

#endif // PROJECT_H
