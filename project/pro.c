#include <stdio.h>
#include <stdlib.h>
#include"pro.h"
#include <string.h>
#include <stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <stdio.h>
#include <stdlib.h>
struct prod{
   char refer[20];
   char prix[50];
};
void ajout_produit(char refer[20],char prix[50],char date[20]){
    FILE* of;
    FILE* dof;
    int value,s=0;
    of = fopen("test.txt","a+");
    dof= fopen("history.txt","a+");
    if (of==NULL) {
        fprintf(stderr,
                "\nError to open the file\n");
        exit(1);
        }
     struct prod inp1;
     strcpy(inp1.refer,refer);
     strcpy(inp1.prix,prix);
     struct prod inp;
     while (fread(&inp, sizeof(struct prod),1, of)){
                   value=strcmp(inp.refer,refer);
                   if(value==0){
                     s+=1;}
                   }
        if(s!=0){printf("product is already added\n");}

                else{
                  fwrite(&inp1, sizeof(struct prod),1, of);
                  fprintf(dof,"the product:%s has been added in %s\n",refer,date);
                  if (fwrite != 0)
                    printf("Contents to file written successfully !\n");
                  else
                    printf("Error writing file !\n");}


    fclose(dof);
    fclose(of);
}
void afficher(){

     FILE* of;
     of = fopen("test.txt","r+");
     struct prod inp2;
     while (fread(&inp2, sizeof(struct prod),1, of)){
                printf("reference=%s   prix=%s\n",inp2.refer,inp2.prix);

}fclose(of);}

void Recherche(char refer1[20]){
     FILE* of;
     int value;
     of = fopen("test.txt","r+");
     struct prod inp2;
     while (fread(&inp2, sizeof(struct prod),1, of)){

                value = strcmp(inp2.refer,refer1);
                 if(value == 0){
                      printf("reference=%s  prix=%s\n",inp2.refer,inp2.prix);
                       }
}fclose(of);}


void supprimer(char refer2[20],char date1[20]){
      FILE* of;
      FILE* nof;
      FILE* dof;
      int value,ret,result;
      of = fopen("test.txt","r+");
      nof= fopen("temp.txt","w");
      dof= fopen("history.txt","a+");
      struct prod inp4;
      while (fread(&inp4, sizeof(struct prod),1, of)){
         value = strcmp(inp4.refer,refer2);
         if (value!=0){
             fwrite(&inp4, sizeof(struct prod),1, nof);
         }
         else{
             fprintf(dof,"the product:%s has been deleted in %s\n",refer2,date1);
         }
         }
      fclose(of);
      fclose(nof);
      fclose(dof);
      FILE* off;
      off = fopen("test.txt","w");
      FILE* offf;
      offf = fopen("temp.txt","r");
      struct prod inp5;
      while (fread(&inp5, sizeof(struct prod),1,offf )){
            fwrite(&inp5, sizeof(struct prod),1, off);}
              fclose(off);
              fclose(offf);

}
void modifier(char refer3[20],char prix1[20],char date2[20]){
     FILE* of;
     of = fopen("test.txt","r+");
     FILE* nof;
     FILE* dof;
     nof = fopen("nouveau.txt","w");
     dof = fopen("history.txt","a+");
     int value ;
     struct prod inp6;
     while (fread(&inp6, sizeof(struct prod),1, of)){
            value=strcmp(inp6.refer,refer3);
            if (value ==0){
                strcpy(inp6.refer,refer3);
                strcpy(inp6.prix,prix1);
                fwrite(&inp6, sizeof(struct prod),1, nof);
                fprintf(dof,"the product:%s has been modified in %s\n",refer3,date2);
            }
            else {
                fwrite(&inp6, sizeof(struct prod),1, nof);}
      }
      fclose(of);
      fclose(nof);
      fclose(dof);

      FILE* off;
     off = fopen("test.txt","w");
      FILE* offf;
     offf = fopen("nouveau.txt","r");
     struct prod inp5;
     while (fread(&inp5, sizeof(struct prod),1,offf )){
            fwrite(&inp5, sizeof(struct prod),1, off);}
              fclose(off);
                fclose(offf);
     }

void showh(){
    FILE* dof;
    char ligne[60];
    dof=fopen("history.txt","r");
    while(fgets(ligne, 80,dof) != NULL)
     {
            printf("%s\n", ligne);
     }
    fclose(dof);
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     //This is used to get the handle to current output buffer.

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     //This is used to reset the carat/cursor to the top left.

     COORD coord = {0, 0};
                      //This is a return value indicating how many characterss were written
                        //   It is not used but we need to capture this since it will be
                          //   written anyway (passing NULL causes an access violation).

     DWORD count;

                                   //This is a structure containing all the console info
                          // It is used here to find the size of the console.

     CONSOLE_SCREEN_BUFFER_INFO csbi;
                     //Now the current color will be set by this handle

     SetConsoleTextAttribute(hStdOut, wColor);

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                              //This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                              //This will set our cursor position for the next print statement
          SetConsoleCursorPosition(hStdOut, coord);
     }
}


