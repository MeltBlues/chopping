#ifndef ENTRY_H
#define ENTRY_H
#include<QDebug>
#include<QFile>
#include"tool.h"
#include"postgresql.h"
#include"project.h"

class entry
{
public:
    entry();
    static void entries(QString);
};

#endif // ENTRY_H
