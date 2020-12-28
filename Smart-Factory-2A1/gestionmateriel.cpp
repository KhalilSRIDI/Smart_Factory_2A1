#include "gestionmateriel.h"

materiel::materiel()
{

}

materiel::materiel(QString ref,QString mod,QDate Adate,int nbm)
{
    reference=ref;
    modele=mod;
    DATE_ACHAT=Adate;
    nombre_maintenance=nbm;
}

bool materiel::ajouter()
{
QSqlQuery query;
QString res= QString::number(nombre_maintenance);
query.prepare("insert into materiel (reference, modele, date_achat, nombre_maintenance)"
              "values (:reference, :modele, :date_achat, :nombre_maintenance)");
query.bindValue(":reference", reference);
query.bindValue(":modele", modele);
query.bindValue(":date_achat",DATE_ACHAT );
query.bindValue(":nombre_maintenance",res);

return query.exec();
}

bool materiel::supprimer(QString reference)
{
    QSqlQuery query;
    query.prepare("delete from materiel where reference= :reference");
    query.bindValue(":reference",reference);
    return  query.exec();
}

QSqlQueryModel * materiel::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from MATERIEL"); //materiel minuscule
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_maintenance"));
    return model;
}

QSqlQueryModel * materiel::recherche_materiel(QString reference)
{
QSqlQuery q;
q.prepare("select * from MATERIEL where reference=:reference");
q.bindValue(":reference", reference);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_maintenance"));
QSqlRecord rec = model->record(0);
QString ref = rec.value("reference").toString();
if( ref == reference){
    return model;
  }
return nullptr;
}

QSqlQueryModel * materiel::recherche_materiel_modele(QString modele)
{
QSqlQuery q;
q.prepare("select * from MATERIEL where modele=:modele");
q.bindValue(":modele", modele);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_maintenance"));
QSqlRecord rec = model->record(0);
QString mod = rec.value("modele").toString();
if( mod == modele){
    return model;
  }
return nullptr;
}

QSqlQueryModel * materiel::recherche_materiel_nbr_maintenance(int nombre_maintenance)
{
QSqlQuery q;
q.prepare("select * from MATERIEL where nombre_maintenance=:nombre_maintenance");
q.bindValue(":nombre_maintenance", nombre_maintenance);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_maintenance"));
QSqlRecord rec = model->record(0);
int nbr_m = rec.value("nombre_maintenance").toInt();
if( nbr_m == nombre_maintenance){
    return model;
  }
return nullptr;
}

QSqlQueryModel * materiel::trier_materiel()
{
    QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("SELECT * from MATERIEL ORDER BY reference ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_maintenance"));

    return model;
}

QSqlQueryModel * materiel::trier_materielmodele()
{
    QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("SELECT * from MATERIEL ORDER BY modele ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_maintenance"));

    return model;
}

QSqlQueryModel * materiel::trier_materiel_dateachat()
{
    QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("SELECT * from MATERIEL ORDER BY DATE_ACHAT ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_maintenance"));

    return model;
}

QSqlQueryModel * materiel::trier_materiel_nbr_maintenance()
{
    QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("SELECT * from MATERIEL ORDER BY nombre_maintenance ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_maintenance"));

    return model;
}




