
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
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Numero Téléphone"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Etat Civile"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Date De Naissance"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Gouvernorat D'Origin"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("Gouvernorat D'Habitation"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("Diplome D'étude"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("Type Contrat"));
    model->setHeaderData(12,Qt::Horizontal,QObject::tr("Date Recrutement"));
    model->setHeaderData(13,Qt::Horizontal,QObject::tr("Département"));
    model->setHeaderData(14,Qt::Horizontal,QObject::tr("Unité"));
    model->setHeaderData(15,Qt::Horizontal,QObject::tr("Fonction"));
    model->setHeaderData(16,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(17,Qt::Horizontal,QObject::tr("E-mail"));
    return model;
}
bool personnels::supprimer(int matricule)
{
    QSqlQuery qry;
    QString mat = QString::number(matricule);
    qry.prepare("Delete from PERSONNELS where MATRICULE =:MATRICULE");
    qry.bindValue(":MATRICULE",mat);
    return qry.exec();
}
QSqlQueryModel *personnels::trier(QString critere,QString AD)
{
    QSqlQuery *qry=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qry->prepare("select * from personnels order by "+critere+" "+AD);
    qry->exec();
    model->setQuery(*qry);
    return model;
}
QSqlQueryModel * personnels::chercherPersonnel(QString nom){
    QSqlQuery qry;
    qry.prepare("select * from PERSONNELS where lower(nom)=lower(:nom)");
    qry.bindValue(":nom",nom);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    return model;
}

QSqlQueryModel *personnels::trier(QString critereNom,QString critereAge,QString critereAnciennete,QString critereSalaire,QString AD)
{
    QSqlQuery *qry=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qry->prepare("select * from personnels order by "+critereNom+","+critereAge+","+critereAnciennete+","+critereSalaire+" "+AD);
    qry->exec();
    model->setQuery(*qry);
    return model;
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
