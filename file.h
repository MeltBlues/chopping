#ifndef FILE_H
#define FILE_H

#include<QtDebug>
#include"c.h"
#include<QString>
#include"shell.h"

class file
{
public:
    file(QString,QString);
    QString name;
    QString URL;
    int c_num;
    QStringList c_name;
    C **c;
};

#endif // FILE_H
