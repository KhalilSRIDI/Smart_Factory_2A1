#include "personnels.h"
personnels::personnels()
{
}
personnels::personnels(QString c,QString n,QString p,QString nT,QString s,QString eC,QDate dN,QString gO,QString gH,QString dE,QDate dR,QString tC,QString dep ,QString u,QString f,int slr,QByteArray img)
{
    cin = c;
    nom = n;
    prenom = p;
    numTel = nT;
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
    image = img;
}
bool personnels::ajouter()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO PERSONNELS (CIN, NOM, PRENOM,NUMERO_TEL,SEXE,ETAT_CIVILE,DIPLOME_ETUDE,TYPE_CONTRAT,GOUVERNORAT_ORIGIN,GOUVERNORAT_HABITATION,UNITE,FONCTION,SALAIRE,DEPARTEMENT,DATE_NAISSANCE,DATE_RECRUTEMENT,image)"
                "VALUES (:CIN, :NOM, :PRENOM,:NUMERO_TEL,:SEXE,:ETAT_CIVILE,:DIPLOME_ETUDE,:TYPE_CONTRAT,:GOUVERNORAT_ORIGIN,:GOUVERNORAT_HABITATION,:UNITE,:FONCTION,:SALAIRE,:DEPARTEMENT,:DATE_NAISSANCE,:DATE_RECRUTEMENT,:image)");
    qry.bindValue(":CIN",cin);
    qry.bindValue(":NOM",nom);
    qry.bindValue(":PRENOM",prenom);
    qry.bindValue(":NUMERO_TEL",numTel);
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
    qry.bindValue(":image",image, QSql::In | QSql::Binary);
    return qry.exec();
}
QSqlQueryModel * personnels::modifier()
{
    QSqlTableModel *model= new QSqlTableModel();
    model->setTable("PERSONNELS");
    model->select();
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
    return  model;
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
    return model;
}
bool personnels::supprimer(int matricule)
{
    QSqlQuery qry;
    qry.prepare("Delete from PERSONNELS where MATRICULE =:MATRICULE ");
    qry.bindValue(":MATRICULE",matricule);
    return qry.exec();
}

QSqlQueryModel *personnels::trier(QString critereNom,QString critereAge,QString critereAnciennete,QString critereSalaire,QString AD)
{
    QSqlQuery qry;
    qry.prepare("select * from personnels order by "+critereNom+" "+critereAge+" "+critereAnciennete+" "+critereSalaire+" "+AD);
    qry.exec();
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery(qry);
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
    return model;
}
QSqlQueryModel *personnels::trier(QString critere,QString AD)
{
    QSqlQuery qry;
    qry.prepare("select * from PERSONNELS order by "+critere+" "+AD);
    qry.exec();
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery(qry);
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
    return model;
}
QSqlQueryModel * personnels::chercherNom(QString nom){
    QSqlQuery qry;
    qry.prepare("select * from PERSONNELS where lower(nom) like '"+nom+"%'");
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
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
    return model;
}
QSqlQueryModel * personnels::chercher(int matricule){

    QSqlQuery qry;
    qry.prepare("Select * from PERSONNELS where MATRICULE =:MATRICULE ");
    qry.bindValue(":MATRICULE",matricule);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
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
    QSqlRecord rec = model->record(0);
    int num = rec.value("matricule").toInt();
    if( num == matricule){
        return model;
      }
        return nullptr;
}
QSqlQueryModel * personnels::chercherFonction(QString fonction){
    QSqlQuery qry;
    qry.prepare("select * from PERSONNELS where FONCTION like :fonction");
    qry.bindValue(":fonction",fonction);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
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
    QSqlRecord rec = model->record(0);
    QString fct = rec.value("fonction").toString();
    if( fct == fonction)
        return model;
     return nullptr;
}
QSqlQueryModel * personnels::chercher(QDate date1,QDate date2){
    QSqlQuery qry;
    qry.prepare("select * from PERSONNELS where DATE_RECRUTEMENT BETWEEN :date1 and :date2");
    qry.bindValue(":date1",date1);
    qry.bindValue(":date2",date2);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
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
    return model;
}
QSqlQueryModel * personnels::chercher(QString sexe,QString etatCivile,int age){
    QSqlQuery qry;
    qry.prepare("select * from PERSONNELS where SEXE =:SEXE AND ETAT_CIVILE = :ETAT_CIVILE and (sysdate - date_Naissance)/366 > :age");
    qry.bindValue(":SEXE",sexe);
    qry.bindValue(":ETAT_CIVILE",etatCivile);
    qry.bindValue(":age",age);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
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

    QSqlRecord rec = model->record(0);
    QString s = rec.value("sexe").toString();
    QString eC = rec.value("ETAT_CIVILE").toString();
    if( s == sexe and eC == etatCivile)
        return model;
     return nullptr;
}
int personnels::calculerTC(QString tc)
{
    int total=0;
    QSqlQuery query;
    query.prepare("select * from PERSONNELS where lower(type_contrat)=lower(:type_contrat)");
    query.bindValue(":type_contrat",tc);
    query.exec();
    while(query.next())
    {
        total++;
    }
    return total;
}
int personnels::calculerSE(QString sexe,QString etatcivile)
{
    int total=0;
    QSqlQuery query;
    query.prepare("select * from PERSONNELS where lower(sexe)=lower(:sexe) and lower(ETAT_CIVILE)=lower(:etatcivile)");
    query.bindValue(":sexe",sexe);
    query.bindValue(":etatcivile",etatcivile);
    query.exec();
    while(query.next())
    {
        total++;
    }
    return total;
}
int personnels::calculerSF(QString sexe,QString fonction)
{
    int total=0;
    QSqlQuery query;
    query.prepare("select * from PERSONNELS where lower(sexe)=lower(:sexe) and lower(fonction)=lower(:fonction)");
    query.bindValue(":sexe",sexe);
    query.bindValue(":fonction",fonction);
    query.exec();
    while(query.next())
    {
        total++;
    }
    return total;
}

QSqlQueryModel *personnels::rechercher_rfid(QString uid)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from personnels where code_RFID like'"+uid+"%'")  ;
    return model;


}

