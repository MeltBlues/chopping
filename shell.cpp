#include "shell.h"


shell::shell()
{

}

QString shell::exe(QString strCmd){
    QProcess p;
    p.start("bash",QStringList()<<"-c"<<strCmd);
    p.waitForFinished(-1);
    QString strResult = p.readAllStandardOutput();
    if(strResult=="")qDebug()<<"error: "<<strCmd<<" exe return null" ;
    //qDebug().noquote()<<strResult;
    //this->split(strResult,"\n");
    p.kill();
    return strResult;

}

void shell::save(QString e){
//    QFile file("/home/nss/code20201109/code_visualization/e.dot");
//    file.open(QIODevice::WriteOnly | QIODevice::Text);
//    file.write(e.toUtf8());
//    file.close();

        QFile aFile("/home/nss/code20201109/code_visualization/e.dot");
        if (!aFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug()<<"f"<<endl;
            return ;}
        QTextStream aStream(&aFile); //用文本流读取文件
//        QString str=ui->textEditStream->toPlainText(); //转换为字符串
        aStream<<e; //写入文本流
        aFile.close();//关闭文件
        return;
}

QStringList shell::split(QString str, QString sign){
    QStringList result_list = str.split(sign);
    result_list.removeOne("");
    //qDebug()<<resule_list[1];
    return result_list;
}

QStringList shell::hold(QStringList strlist, QString sign){
    int n=sign.length();
    QStringList result_list;
    for(int i=0;i<strlist.length();i++){

        if(strlist[i].length()<n) continue;
        for(int j=0;j<strlist[i].length()-n+1;j++){
            int flag=1;
            for(int k=0;k<n;k++){
                if(strlist[i][j+k]!=sign[k]) flag=0;
                break;
            }

            if(flag==1) result_list.append(strlist[i]);
        }
    }

    return result_list;
}

QString shell::ctags_cmd(QString url,int n){
    QString cmd ="ctags -x ";
            cmd.append(url);
            cmd.append(" | grep function | tr -s ' ' | cut -d ' ' -f");
            cmd.append(QString::number(n));

    return cmd;
}

QStringList shell::cflow_cmd(QString url,QStringList function_name ,QString n ){

    QString cmd;
    QStringList cmdList;
    for(int i=0;i<function_name.length();i++){
         cmd = "";
         cmd.append("cflow -b -m ");
         cmd.append(function_name[i]);
         cmd.append(" ");
         cmd.append(url);
         if(n=="tree2dotx")
            cmd.append(" | tree2dotx");

         //s->exe(cmd);
         //qDebug().noquote()<<cmd;
         cmdList.append(cmd);
         //qDebug().noquote()<<s->exe(cmd);
    }
    return cmdList;
}

QString shell::ls_cmd(QString url,QString sign){
    QString cmd="ls ";
    cmd.append(url);
    cmd.append(" ");
    cmd.append(sign);
    return cmd;

}
