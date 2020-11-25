alter table personnels add CONSTRAINT ch_fonction check (lower(FONCTION) in('chef de departement','chef d''unite','ingenieur','technicien','ouvrier','chercheur','commercial'));
alter table personnels add CONSTRAINT ch_naissance check (trunc((sysdate-DATE_NAISSANCE)/366) > 18);
select trunc((sysdate - date_Naissance)/366) from personnels;
alter table personnels add CONSTRAINT ch_diplomeEtude check (lower(DIPLOME_ETUDE) in('bac','technicien','ingenieur','doctorant'));
alter table personnels add CONSTRAINT ch_etatCivil check (lower(ETAT_CIVILE) in('marie','celebataire','divorce'));
alter table personnels drop CONSTRAINT ch_etatCivile; 
SELECT COUNT(fonction)FROM personnels WHERE (lower(fonction) like 'ouvrier');
