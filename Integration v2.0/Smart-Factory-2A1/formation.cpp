#include "formation.h"

formation::formation()
{

}

bool formation::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO FORMATIONS (NOM, PROJET, FORMATEUR, DATEDEBUT, DUREE, COUT) VALUES (:NOM, :PROJET, :FORMATEUR, :DATEDEBUT, :DUREE, :COUT)");
    query.bindValue(":NOM", NOM);
    query.bindValue(":PROJET", PROJET);
    query.bindValue(":FORMATEUR", FORMATEUR);
    query.bindValue(":DATEDEBUT", DATEDEBUT);
    query.bindValue(":DUREE", DUREE);
    query.bindValue(":COUT", COUT);
    return query.exec();
}

bool formation::supprimer(int idformation)
{
    QSqlQuery qury;
    QString idf = QString::number(idformation);
    qury.prepare("Delete from FORMATIONS where IDFORMATION = :IDFORMATION");
    qury.bindValue(":IDFORMATION",idf);
    return qury.exec();
}



QSqlQueryModel *formation::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM FORMATIONS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDFORMATION"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PROJET"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("FORMATEUR"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEDEBUT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DUREE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("COUT"));
    return model;
}

QSqlQueryModel *formation::chercher(QString input,int critere)
{
    QSqlQuery q;
    int inputid;

    if(critere==0)
    {
        inputid=input.toInt();
        q.prepare("SELECT * FROM FORMATIONS WHERE IDFORMATION = :IDFORMATION");
        q.bindValue(":IDFORMATION",inputid);
        q.exec();
    }
    else if(critere==1)
    {
        q.prepare("SELECT * FROM FORMATIONS WHERE NOM = :NOM");
        q.bindValue(":NOM",input);
        q.exec();
    }
    else if(critere==2)
    {
        q.prepare("SELECT * FROM FORMATIONS WHERE PROJET = :PROJET");
        q.bindValue(":PROJET",input);
        q.exec();
    }
    else if(critere==3)
    {
        inputid=input.toInt();
        q.prepare("SELECT * FROM FORMATIONS WHERE FORMATEUR = :FORMATEUR");
        q.bindValue(":FORMATEUR",inputid);
        q.exec();
    }
    else if(critere==4)
    {
        q.prepare("SELECT * FROM FORMATIONS WHERE DATEDEBUT = :DATEDEBUT");
        q.bindValue(":DATEDEBUT",input);
        q.exec();
    }
    else if(critere==5)
    {
        q.prepare("SELECT * FROM FORMATIONS WHERE DUREE = :DUREE");
        q.bindValue(":DUREE",input);
        q.exec();
    }
    else if(critere==6)
    {
        q.prepare("SELECT * FROM FORMATIONS WHERE COUT = :COUT");
        q.bindValue(":COUT",input);
        q.exec();
    }


    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(q);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDFORMATION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PROJET"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("FORMATEUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEDEBUT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("COUT"));

    QString index;

    QSqlRecord rec;
    rec = model->record(0);
    if(critere==0)
    {
        int num = rec.value("IDFORMATION").toInt();
        return model;
    }
    else
    {
        index = rec.value("input").toString();
        return model;
    }

    return nullptr;

}

void formation::exporterExcel(QTableView *table)
{
    QString filters("CSV files (*.csv);;All files (.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                    filters, &defaultFilter);
    QFile file(fileName);
    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
    }
}

QSqlQueryModel * formation::trier(QString critere,QString order)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery *triq= new QSqlQuery();


    triq->prepare("SELECT * FROM FORMATIONS ORDER BY "+critere+" "+order);
    triq->exec();
    model->setQuery(*triq);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDFORMATION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PROJET"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("FORMATEUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEDEBUT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("COUT"));

    return model;
}

//charger comboboxPC
QSqlQueryModel *formation::loadPC()
{
    QSqlQueryModel * modal=new QSqlQueryModel ();
    QSqlQuery *qry=new QSqlQuery  ();
    qry->prepare("select nom from projets");
    qry->exec();
    modal->setQuery(*qry);
    return modal;
}
