#ifndef C_H
#define C_H

#include<QDebug>
#include<QString>
#include<QFile>
#include"shell.h"

class C
{
public:
    C(QString,QString);
    void clear();
    void read_source();
    QString name;
    QString url;
    QStringList source;
    QString ctags_result; //don't care
    QStringList function_name;
    QStringList function_used;
    QStringList function_star; //the line number of function in source
    QStringList function_end;
    QStringList function_source;
};

#endif // C_H
