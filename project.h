#ifndef PROJECT_H
#define PROJECT_H

#include<QDebug>
#include"tool.h"
#include"shell.h"
#include"file.h"
#include"c.h"

class project
{
public:
    project(QString,QString);
    QString name;
    QString entry_URL;
    int f_num;
    QStringList f_name;
    QStringList f_addr;
    file **f;
};

#endif // PROJECT_H
