#ifndef TOOL_H
#define TOOL_H

#include"shell.h"
#include<QDebug>
#include<QString>

class tool
{
public:
    tool();
    static void find_file(QString,QString,QStringList *,QStringList*);
};

#endif // TOOL_H
