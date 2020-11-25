alter table personnels add CONSTRAINT ch_cin check(cin > 9999999 and cin < 99999999); 
alter table personnels add CONSTRAINT ch_numTel check(numero_tel > 9999999 and numero_tel < 99999999); 
alter table personnels add CONSTRAINT ch_sexe check (lower(sexe) like 'masculin' or lower(sexe) like 'feminin');
alter table personnels add CONSTRAINT ch_typeContrat check (lower(type_Contrat) like 'cdi' or lower(type_Contrat) like 'sivp'or lower(type_Contrat) like 'cdd');
alter table personnels add CONSTRAINT ch_departement check (lower(departement) in('ressources humaines','stock','achats','ventes','ameliorations','materiel'));
alter table personnels add CONSTRAINT ch_unite check (lower(unite) in('personnels','profils','matieres premieres','produits finis','fournisseurs','commandes achats','clients','commandes ventes','projets','formations','equipements','maintenances'));
alter table personnels add CONSTRAINT ch_email check (lower(email) like '%@%.%');
alter table personnels add CONSTRAINT ch_etatCivile check (lower(etat_Civile) in('Marié(e)','Célébataire','Divorcé(e)'));
alter table personnels add CONSTRAINT ch_nom check (LENGTH(nom)<=10);
alter table personnels add CONSTRAINT ch_prenom check (LENGTH(prenom)<=15);
select trunc((sysdate - date_Naissance)/366) from personnels;




