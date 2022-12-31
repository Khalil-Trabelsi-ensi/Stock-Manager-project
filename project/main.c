#include <stdio.h>
#include <stdlib.h>
#include"pro.h"
#include <string.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <stdio.h>
#include <stdlib.h>
struct prod{
   char refer[20];
   char prix[50];
};
int menu(int choix)
{
    if(choix < 0 || choix > 6)
    {   printf("                             *********************************************\n");
        printf("                             * ___________________Menu__________________ *\n");
        printf("                             *|1 :  Add product                         |*\n");
        printf("                             *|2 :  show available products             |*\n");
        printf("                             *|3 :  view the discription of  product    |*\n");
        printf("                             *|4 :  Delete product                      |*\n");
        printf("                             *|5 :  Modify a product                    |*\n");
        printf("                             *|6 :  show history                        |*\n");
        printf("                             *|0 :  EXIT                                |*\n");
        printf("                             *|_________________________________________|*\n");
        printf("                             *********************************************\n");
    }
   return choix;
}
int main()
{
     ClearConsoleToColors(70,80);
     char refer[20];
     char prix[50];
     char refer1[20];
     char refer2[20];
     char refer3[20];
     char prix1[50];
     char date[20];
     char date1[20];
     char date2[20];
     int choix;
        printf("                                   Welcome to our program Stock Manager   \n");
        printf("                             *********************************************\n");
        printf("                             * ___________________Menu__________________ *\n");
        printf("                             *|1 :  Add product                         |*\n");
        printf("                             *|2 :  show available products             |*\n");
        printf("                             *|3 :  view the discription of  product    |*\n");
        printf("                             *|4 :  Delete product                      |*\n");
        printf("                             *|5 :  Modify a product                    |*\n");
        printf("                             *|6 :  show history                        |*\n");
        printf("                             *|0 :  EXIT                                |*\n");
        printf("                             *|_________________________________________|*\n");
        printf("                             *********************************************\n");
    while(1){
      printf("Votre choix ? ");
      scanf("%d", &choix);
      switch (menu(choix))
    {
            case 1:
            printf("give reference:\n");
            scanf("%s",refer);
            printf("give price:\n");
            scanf("%s",prix);
            printf("give date:\n");
            scanf("%s",date);
            ajout_produit(refer,prix,date);
            break;
            case 2:
            afficher();
            break;
            case 3:
            printf("taper reference:\n");
            scanf("%s",refer1);
            Recherche(refer1);
            break;
            case 4:
            printf("give reference:\n");
            scanf("%s",refer2);
            printf("give date:\n");
            scanf("%s",date1);
            supprimer(refer2,date1);
            break;
            case 5:
            printf("give reference:\n");
            scanf("%s",refer3);
            printf("give price:\n");
            scanf("%s",prix1);
            printf("give date:\n");
            scanf("%s",date2);
            modifier(refer3,prix1,date2);
            break;
            case 6:
                showh();
                break;
            }
    if(choix==0){
        break;}
}}
