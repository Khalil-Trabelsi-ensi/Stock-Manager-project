#ifndef PRO_H_INCLUDED
#define PRO_H_INCLUDED
void ajout_produit(char refer[20],char prix[50],char date[10]);
void afficher();
void Recherche(char refer1[20]);
void supprimer(char refer2[20],char date1[10]);
void modifier(char refer3[20],char prix1[50],char date2[20]);
void showh();
void ClearConsoleToColors(int ForgC, int BackC);
#endif // PRO_H_INCLUDED
