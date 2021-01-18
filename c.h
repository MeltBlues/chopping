#ifndef C_H
#define C_H

#include<QDebug>
#include<QString>
#include<QFile>
#include"shell.h"
#include"tool.h"

class C
{
public:
    C(QString,QString);
    void clear();
    void read_source();
    void handle_function();
    void handle_include();
    QString name;
    QString url;
    QStringList source;
    QString ctags_result; //don't care
    int function_num;
    QStringList function_name;
    QStringList function_used;
    QStringList function_star; //the line number of function in source
    QStringList function_end;
    QStringList function_source;
    int include_num;
    QStringList include_name;

};

#endif // C_H
