#include "entry.h"

entry::entry()
{

}

void entry::entries(QString workspace_addr){
    QStringList project_name;
    QStringList Project_addr;
    //find project (no recurrence)
    tool::find_file("",workspace_addr,&project_name,&Project_addr,0);

    //every project to chop
    tool::add_bar(&Project_addr);

    for(int i=1;i<project_name.length();i++){//star from 1 because find_file return every file including itself
        project * p=new project(project_name[i],Project_addr[i]);

        delete p;
    }

}
