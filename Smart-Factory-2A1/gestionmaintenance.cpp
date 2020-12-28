#include "gestionmaintenance.h"

maintenance::maintenance()
{

}

maintenance::maintenance(QString ID,QString ref,QString mod,QString matri,QDate Adate,QDate mdate,QString der_prb,QString mtype)
{
    ID_maintenance=ID;
    reference=ref;
    modele=mod;
    matricule=matri;
    DATE_ACHAT=Adate;
    date_de_maintenance=mdate;
    dernier_probleme=der_prb;
    type_de_maintenance=mtype;
}

bool maintenance::ajouter()
{
QSqlQuery query;
query.prepare("insert into maintenance (ID_maintenance, reference, modele, matricule, DATE_ACHAT, date_de_maintenance, dernier_probleme, type_de_maintenance)"
              "values (:ID_maintenance, :reference, :modele, :matricule, :date_achat, :date_de_maintenance, :dernier_probleme, :type_de_maintenance)");
query.bindValue(":ID_maintenance", ID_maintenance);
query.bindValue(":reference", reference);
query.bindValue(":modele", modele);
query.bindValue(":matricule", matricule);
query.bindValue(":date_achat",DATE_ACHAT );
query.bindValue(":date_de_maintenance",date_de_maintenance);
query.bindValue(":dernier_probleme", dernier_probleme);
query.bindValue(":type_de_maintenance", type_de_maintenance);

return query.exec();
}

bool maintenance::supprimer(QString ID_maintenance)
{
    QSqlQuery query;
    query.prepare("delete from maintenance where ID_maintenance= :ID_maintenance");
    query.bindValue(":ID_maintenance",ID_maintenance);
    return  query.exec();
}

QSqlQueryModel * maintenance::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from MAINTENANCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));
    return model;
}

QSqlQueryModel * maintenance::recherche_maintenance(QString ID_maintenance)
{
QSqlQuery q;
q.prepare("select * from MAINTENANCE where ID_maintenance=:ID_maintenance");
q.bindValue(":ID_maintenance", ID_maintenance);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));
QSqlRecord rec = model->record(0);
QString ID = rec.value("ID_maintenance").toString();
if( ID == ID_maintenance){
    return model;
  }
return nullptr;
}

QSqlQueryModel * maintenance::recherche_maintenance_reference(QString reference)
{
QSqlQuery q;
q.prepare("select * from MAINTENANCE where reference=:reference");
q.bindValue(":reference", reference);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));
QSqlRecord rec = model->record(0);
QString ref = rec.value("reference").toString();
if( ref == reference){
    return model;
  }
return nullptr;
}

QSqlQueryModel * maintenance::recherche_maintenance_modele(QString modele)
{
QSqlQuery q;
q.prepare("select * from MAINTENANCE where modele=:modele");
q.bindValue(":modele", modele);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));
QSqlRecord rec = model->record(0);
QString mod = rec.value("modele").toString();
if( mod == modele){
    return model;
  }
return nullptr;
}

QSqlQueryModel * maintenance::recherche_maintenance_matricule(QString matricule)
{
QSqlQuery q;
q.prepare("select * from MAINTENANCE where matricule=:matricule");
q.bindValue(":matricule", matricule);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));
QSqlRecord rec = model->record(0);
QString matri = rec.value("matricule").toString();
if( matri == matricule){
    return model;
  }
return nullptr;
}

QSqlQueryModel * maintenance::recherche_maintenance_type(QString type_de_maintenance)
{
QSqlQuery q;
q.prepare("select * from MAINTENANCE where type_de_maintenance=:type_de_maintenance");
q.bindValue(":type_de_maintenance", type_de_maintenance);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));
QSqlRecord rec = model->record(0);
QString type = rec.value("type_de_maintenance").toString();
if( type == type_de_maintenance){
    return model;
  }
return nullptr;
}

QSqlQueryModel * maintenance::trier_maintenance_ID()
{
    QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("SELECT * from MAINTENANCE ORDER BY ID_maintenance ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));

    return model;
}

QSqlQueryModel * maintenance::trier_maintenance_reference()
{
    QSqlQueryModel * model=new QSqlQueryModel;

model->setQuery("SELECT * from MAINTENANCE ORDER BY reference ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));

    return model;
}

QSqlQueryModel * maintenance::trier_maintenance_modele()
{
    QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("SELECT * from MAINTENANCE ORDER BY modele ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));

    return model;
}

QSqlQueryModel * maintenance::trier_maintenance_matricule()
{
    QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("SELECT * from MAINTENANCE ORDER BY matricule ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));

    return model;
}

QSqlQueryModel * maintenance::trier_maintenance_dateachat()
{
    QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("SELECT * from MAINTENANCE ORDER BY DATE_ACHAT ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));

    return model;
}

QSqlQueryModel * maintenance::trier_maintenance_date_derniere_maintenance()
{
    QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("SELECT * from MAINTENANCE ORDER BY date_de_maintenance ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_maintenance"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_maintenance"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("dernier_probleme"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("type_de_maintenance"));

    return model;
}
