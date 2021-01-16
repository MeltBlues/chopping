#include "postgresql.h"

postgreSQL::postgreSQL()
{

    this->db=new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL"));
    this->db->setHostName("172.23.5.168");
    //db->setHostName("127.0.0.1");
    this->db->setPort(5432);
    this->db->setUserName("postgres");
    this->db->setPassword("126041");
    this->db->setDatabaseName("dachuang");
    qDebug()<<"begin to connect";
    if(this->db->open())
       {
        qDebug()<<"connect db success";
       //QSqlQuery result= db->exec("SELECT * FROM project;");
       //qDebug().noquote()<<result.result();
    }
    else
    {
        qDebug()<<"error: connect db ";

        qDebug().noquote()<<this->db->lastError();
    }
    //this->db->close();
    //delete this->db;

}

QString postgreSQL::callpro_cmd(project * p){
    QString cmd="SELECT callpro('";
    cmd.append(p->name);
    cmd.append("' , '");
    cmd.append(p->entry_URL);
    cmd.append("' , ");

    int num=0;
    for(int i=0;i<p->f_num;i++){
        num +=p->f[i]->c_num;
    }
    cmd.append(QString::number(num));

    cmd.append(");");

    qDebug().noquote()<<cmd<<endl;
    return cmd;
}

QString postgreSQL::callc_cmd(C * c,QString pro_name,int id){
    QString cmd="SELECT callc(";
    cmd.append(QString::number(id));
    cmd.append(" , '");
    cmd.append(pro_name);
    cmd.append("' , '");
    cmd.append(c->name);
    cmd.append("' , ");
    cmd.append(QString::number(c->function_num));
    cmd.append(" , '");
    cmd.append(c->url);
    cmd.append("' , '");

    QString source="";
    for(int i=0;i<c->source.length();i++){
        source.append(c->source[i]);
    }
    cmd.append(source);
    cmd.append("');");


    qDebug().noquote()<<cmd<<endl;
    return cmd;
}

QString postgreSQL::callfunc_cmd(QString c_cname,QString c_funcname,QString c_funcused,QString c_proname,QString c_funcsource,int c_funcstar,int c_funcend,int id){
    QString cmd="SELECT callfunc('";
    cmd.append(c_cname);
    cmd.append("' , '");
    cmd.append(c_funcname);
    cmd.append("' , '");
    cmd.append(c_funcused);
    cmd.append("' , '");
    cmd.append(c_proname);
    cmd.append("' , '");
    cmd.append(c_funcsource);
    cmd.append("' , ");
    cmd.append(QString::number(c_funcstar));
    cmd.append(" , ");
    cmd.append(QString::number(c_funcend));
    cmd.append(" , ");
    cmd.append(QString::number(id));
    cmd.append(");");

    qDebug().noquote()<<cmd<<endl;
    return cmd;
}


bool postgreSQL::submit(project * p){
    int id =this->sql_exe(postgreSQL::callpro_cmd(p));
    qDebug()<<id;
    if(id==-1) return false;

    for(int i=0;i<p->f_num;i++){
        for(int j=0;j<p->f[i]->c_num;j++){
                 if(this->sql_exe(postgreSQL::callc_cmd(p->f[i]->c[j],p->f[i]->name,id))==-1) return false;
            for(int k=0;k<p->f[i]->c[j]->function_num;k++){
                if(this->sql_exe(postgreSQL::callfunc_cmd(p->f[i]->c[j]->name,p->f[i]->c[j]->function_name[k],p->f[i]->c[j]->function_used[k],p->name,p->f[i]->c[j]->function_source[k],p->f[i]->c[j]->function_star[k].toInt(),p->f[i]->c[j]->function_end[k].toInt(),id))==-1)return false;
            }
        }
    }
    qDebug().noquote()<<"submit "<<p->name<<" success "<<endl;
    return true;
}

int postgreSQL::sql_exe(QString cmd){
    QSqlQuery result;
    result.exec(cmd);
    //result.last();
    qDebug().noquote()<<result.lastError();
    if(result.next()) return result.value(0).toInt();
    else return -1;
}

void postgreSQL::driver_test(){


    QStringList ds=QSqlDatabase::drivers();
    foreach (QString strTmp, ds) {
        qDebug()<<strTmp;
    }

}
