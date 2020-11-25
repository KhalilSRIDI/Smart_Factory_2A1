#include "personnels.h"
#include "gestionpersonnelprofil.h"
personnels::personnels()
{
}
personnels::personnels(int c,QString n,QString p,int nT,QString e,QString s,QString eC,QDate dN,QString gO,QString gH,QString dE,QDate dR,QString tC,QString dep ,QString u,QString f,int slr)
{
    cin = c;
    nom = n;
    prenom = p;
    numTel = nT;
    email = e;
    sexe = s;
    etatCivile = eC;
    dateNaissance = dN;
    gouvernoratOrigin = gO;
    gouvernoratHabitation = gH;
    diplomeEtude = dE;
    dateRecrutement = dR;
    typeContrat = tC;
    departement = dep;
    unite  = u;
    fonction = f;
    salaire = slr;
}
bool personnels::ajouter()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO PERSONNELS (CIN, NOM, PRENOM,NUMERO_TEL,EMAIL,SEXE,ETAT_CIVILE,DIPLOME_ETUDE,TYPE_CONTRAT,GOUVERNORAT_ORIGIN,GOUVERNORAT_HABITATION,UNITE,FONCTION,SALAIRE,DEPARTEMENT,DATE_NAISSANCE,DATE_RECRUTEMENT)"
                "VALUES (:CIN, :NOM, :PRENOM,:NUMERO_TEL,:EMAIL,:SEXE,:ETAT_CIVILE,:DIPLOME_ETUDE,:TYPE_CONTRAT,:GOUVERNORAT_ORIGIN,:GOUVERNORAT_HABITATION,:UNITE,:FONCTION,:SALAIRE,:DEPARTEMENT,:DATE_NAISSANCE,:DATE_RECRUTEMENT)");
    qry.bindValue(":CIN",cin);
    qry.bindValue(":NOM",nom);
    qry.bindValue(":PRENOM",prenom);
    qry.bindValue(":NUMERO_TEL",numTel);
    qry.bindValue(":EMAIL",email);
    qry.bindValue(":SEXE",sexe);
    qry.bindValue(":ETAT_CIVILE",etatCivile);
    qry.bindValue(":DATE_NAISSANCE",dateNaissance);
    qry.bindValue(":GOUVERNORAT_ORIGIN",gouvernoratOrigin);
    qry.bindValue(":GOUVERNORAT_HABITATION",gouvernoratHabitation);
    qry.bindValue(":DIPLOME_ETUDE",diplomeEtude);
    qry.bindValue(":TYPE_CONTRAT",typeContrat);
    qry.bindValue(":FONCTION",fonction);
    qry.bindValue(":SALAIRE",salaire);
    qry.bindValue(":DEPARTEMENT",departement);
    qry.bindValue(":UNITE",unite);
    qry.bindValue(":DATE_RECRUTEMENT",dateRecrutement);
    return qry.exec();
}
QSqlQueryModel * personnels::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery("SELECT * from PERSONNELS");
    return model;
}
bool personnels::supprimer(int matricule)
{
    QSqlQuery qry;
    QString mat = QString::number(matricule);
    qry.prepare("Delete from PERSONNELS where MATRICULE = :MATRICULE");
    qry.bindValue(":MATRICULE",mat);
    return qry.exec();
}
QSqlQueryModel * personnels::chercherPersonnel(int matricule){
QSqlQuery qry;
qry.prepare("select * from PERSONNELS where MATRICULE=:MATRICULE");
qry.bindValue(":MATRICULE", matricule);
qry.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(qry);
QSqlRecord rec = model->record(0);
int mat = rec.value("MATRICULE").toInt();
if( mat == matricule){
    return model;
  }
    return nullptr;
}
QSqlQueryModel * personnels::chercherPersonnelFonction(QString fonction){
QSqlQuery qry;
qry.prepare("select * from PERSONNELS where FONCTION=:FONCTION");
qry.bindValue(":FONCTION",fonction);
qry.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(qry);
QSqlRecord rec = model->record(0);
QString fct = rec.value("FONCTION").toString();
if( fct == fonction){
    return model;
  }
    return nullptr;
}
QSqlQueryModel * personnels::chercherPersonnelPeriodeRec(QDate date1,QDate date2){
QSqlQuery qry;
qry.prepare("select * from PERSONNELS where DATE_RECRUTEMENT BETWEEN :date1 and :date2");
qry.bindValue(":date1",date1);
qry.bindValue(":date2",date2);
qry.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(qry);
    return model;
}
QSqlQueryModel * personnels::chercherPersonnel3C(QString sexe,QString etatCivile,int age){
QSqlQuery qry;
qry.prepare("select * from PERSONNELS where SEXE =:SEXE AND ETAT_CIVILE = :ETAT_CIVILE and (sysdate - date_Naissance)/366 > :age");
qry.bindValue(":SEXE",sexe);
qry.bindValue(":ETAT_CIVILE",etatCivile);
qry.bindValue(":age",age);

qry.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(qry);
    return model;
}
