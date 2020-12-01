#include "projets.h"

projets::projets()
{

}

bool projets::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PROJETS (NOM, DEPARTEMENT, TEAM_LEADER, DATE_LANCEMENT, COUTS_PREVUS, REVENUS_PROJETES) VALUES (:NOM, :DEPARTEMENT, :TEAM_LEADER, :DATE_LANCEMENT, :COUTS_PREVUS, :REVENUS_PROJETES)");
    query.bindValue(":NOM", NOM);
    query.bindValue(":DEPARTEMENT", DEPARTEMENT);
    query.bindValue(":TEAM_LEADER", TEAM_LEADER);
    query.bindValue(":DATE_LANCEMENT", DATE_LANCEMENT);
    query.bindValue(":COUTS_PREVUS", COUTS_PREVUS);
    query.bindValue(":REVENUS_PROJETES", REVENUS_PROJETES);
    return query.exec();
}

bool projets::supprimer(int idprojet)
{
    QSqlQuery qry;
    QString id = QString::number(idprojet);
    qry.prepare("Delete from PROJETS where IDPROJET = :IDPROJET");
    qry.bindValue(":IDPROJET",id);
    return qry.exec();
}

QSqlQueryModel *projets::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PROJETS");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DEPARTEMENT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TEAM_LEADER"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_LANCEMENT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("COUTS_PREVUS"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("REVENUS_PROJETES"));
    return model;
}

QSqlQueryModel *projets::chercher(QString input,int critere)
{
    QSqlQuery q;
    int inputid;

    if(critere==0)
    {
        inputid=input.toInt();
        q.prepare("SELECT * FROM PROJETS WHERE IDPROJET = :IDPROJET");
        q.bindValue(":IDPROJET",inputid);
        q.exec();
    }
    else if(critere==1)
    {
        q.prepare("SELECT * FROM PROJETS WHERE NOM = :NOM");
        q.bindValue(":NOM",input);
        q.exec();
    }
    else if(critere==2)
    {
        q.prepare("SELECT * FROM PROJETS WHERE DEPARTEMENT = :DEPARTEMENT");
        q.bindValue(":DEPARTEMENT",input);
        q.exec();
    }
    else if(critere==3)
    {
        q.prepare("SELECT * FROM PROJETS WHERE TEAM_LEADER = :TEAM_LEADER");
        q.bindValue(":TEAM_LEADER",input);
        q.exec();
    }
    else if(critere==4)
    {
        q.prepare("SELECT * FROM PROJETS WHERE DATE_LANCEMENT = :DATE_LANCEMENT");
        q.bindValue(":DATE_LANCEMENT",input);
        q.exec();
    }
    else if(critere==5)
    {
        q.prepare("SELECT * FROM PROJETS WHERE COUTS_PREVUS = :COUTS_PREVUS");
        q.bindValue(":COUTS_PREVUS",input);
        q.exec();
    }
    else if(critere==6)
    {
        q.prepare("SELECT * FROM PROJETS WHERE REVENUS_PROJETES = :REVENUS_PROJETES");
        q.bindValue(":REVENUS_PROJETES",input);
        q.exec();
    }


    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(q);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DEPARTEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEAM_LEADER"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_LANCEMENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("COUTS_PREVUS"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("REVENUS_PROJETES"));

    int num;
    QString index;

    QSqlRecord recp;
    recp = model->record(0);
    if(critere==0)
    {
        num = recp.value("IDPROJET").toInt();
        return model;
    }
    else
    {
        index = recp.value("input").toString();
        return model;
    }

    return nullptr;

}

void projets::exporterExcel(QTableView *table)
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

QSqlQueryModel * projets::trier(int critere,QString order)
{
    QSqlQueryModel * model= new QSqlQueryModel();


    if(critere==0)
    {
        model->setQuery("SELECT * FROM PROJETS ORDER BY IDPROJET "+order);

    }
    else if(critere==1)
    {
        model->setQuery("SELECT * FROM PROJETS ORDER BY NOM "+order);
    }
    else if(critere==2)
    {
        model->setQuery("SELECT * FROM PROJETS ORDER BY DEPARTEMENT "+order);
    }
    else if(critere==3)
    {
        model->setQuery("SELECT *FROM PROJETS ORDER BY TEAM_LEADER "+order);
    }
    else if(critere==4)
    {
        model->setQuery("SELECT * FROM PROJETS ORDER BY DATE_LANCEMENT "+order);
    }
    else if(critere==5)
    {
        model->setQuery("SELECT * FROM PROJETS ORDER BY COUTS_PREVUS "+order);
    }
    else if(critere==6)
    {
        model->setQuery("SELECT * FROM PROJETS ORDER BY REVENUS_PROJETES "+order);
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DEPARTEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEAM_LEADER"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_LANCEMENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("COUTS_PREVUS"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("REVENUS_PROJETES"));

    return model;
}
/*
QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("reclamation.pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM reclamation ");
        q.exec();
        QString pdf="<br> <img src='D:/Esprit/2A2/projet c++/logo/debug2.png' height='42' width='144'/> <h1  style='color:red'>LISTE DES RECLAMATION  <br></h1>\n <br> <table>  <tr>  <th> CODE </th> <th> SUJET </th> <th> COMMENTAIRE </th> <th> DATE AJOUT </th>  </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>   <td>   " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>    <td>"+q.value(4).toString()+" </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);


*/

int projets::calculCout(QString departement)
{
    QSqlQuery statq;
    int totalCout=0;
    int cout;
    statq.prepare("SELECT COUTS_PREVUS FROM PROJETS WHERE DEPARTEMENT=:departement");
    statq.bindValue(":departement",departement);
    statq.exec();
    while (statq.next()) {
        cout = statq.value(0).toInt();
        totalCout+=cout;
        qDebug() << cout;
        qDebug() << totalCout;
    }
    return totalCout;
}

int projets::calculRevenus(QString departement)
{
    QSqlQuery statq;
    int totalRevenus=0;
    int revenus;
    statq.prepare("SELECT REVENUS_PROJETES FROM PROJETS WHERE DEPARTEMENT=:departement");
    statq.bindValue(":departement",departement);
    statq.exec();
    while (statq.next()) {
        revenus = statq.value(0).toInt();
        totalRevenus+=revenus;
        qDebug() << revenus;
        qDebug() << totalRevenus;
    }
    return totalRevenus;
}
