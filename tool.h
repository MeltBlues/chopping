#ifndef TOOL_H
#define TOOL_H

#include"shell.h"
#include<QDebug>
#include<QString>
#include<QRegExp>

class tool
{
public:
    tool();
    static void find_file(QString,QString,QStringList *,QStringList*,int);
    static void add_bar(QStringList *);//service for QStringList
    static void add_bar(QString *);//bar is naughty
    static QString delect_space(QString,int);//0:remove all space 1:arrange
};

#endif // TOOL_H
