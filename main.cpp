/******************************************************************************

    Agricultorul Iurii are o livadă împărțită în n*m sectoare (2 < n,m < 100),
dispuse pe n linii, numerotate de la 1 la n și m coloane, numerotate de la 1 la m. 
În fiecare sector se află 3 copaci de nuci. După recoltarea nucilor el a comparat 
datele cu anii precedenți, a observat că cantitatea de nuci recoltate an cu an scade.
Pentru a îmbunătăți recolta el a hotărât să înlocuiască copacii,de pe sectoarele
unde recolta e mai mică ca valoarea medie pe livadă, cu puieți noi.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
     using namespace std;
#include <math.h>
#include <conio.h>
#define n_jos 2

int linii, coloane, sector_rau=0;   
 
float   recolta=0,
        recolta_medie=0, 
        recolta_sector_rau=0;
        
float sector[50][50];

struct blocnot{ 
        int rind, coloana; 
        float recolta;
} carnet[50];

//--------------------!!! INTRODUCEREA !!!--------------------
void introdu_linii()
{
    do
    {
        printf("    Introdu numărul de rânduri a livezii ==> ");scanf("%d",&linii);
        if (linii<=n_jos) 
        {
            system("clear");
            printf("    Livada are mai mult de 2 râduri !!!");printf("\n");
            printf("    Mai înceacă o dată !!!");printf("\n");
        }
        
    }
    while (linii<=n_jos);   
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void introdu_coloane()
{
    do
    {
        
        printf("    Introdu numărul de coloane a livezii ==> ");scanf("%d", &coloane);
        if (coloane<=n_jos) 
        {
            system("clear");
            printf("    Livada are mai mult de 2 coloane !!!");printf("\n");
            printf("    Mai înceacă o dată !!!");printf("\n");
            
        }
        
    }
    while (coloane<=n_jos);  
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void introdu_recolta()
{
   for (int i = 0; i < linii; i++)
        for (int j = 0; j < coloane; j++)
        {
            printf("sector[%d,%d] = ",i+1,j+1);
            scanf("%f", &sector[i][j]);
        }
    return;
}
//--------------------!!! AFISAREA !!!--------------------
void afisare_carnet()
{
    for (int i = 0; i < sector_rau; i++) 
    {
        printf(" Sector  [%d %d]", carnet[i].rind+1, carnet[i].coloana+1);
        printf("  - recolta %f q",carnet[i].recolta);printf("\n");
    }
    return;
}
//--------------------!!! PRELUCRAREA datelor !!!--------------------
void calcul_recolta()
{
    for (int i = 0; i < linii; i++) 
    {
        for (int j = 0; j < coloane; j++)
            recolta+=sector[i][j];
        printf("\n");
    }
    return;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void scrie_carnet(int r, int c, float rr)
{
    carnet[sector_rau].rind=r;
    carnet[sector_rau].coloana=c;
    carnet[sector_rau].recolta=rr;
    return;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void NUMARA_sector_rau(){ sector_rau++;}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//          Programul principal
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
    introdu_linii();
    system("clear");
    introdu_coloane();
    introdu_recolta();
    system("clear");
    
    calcul_recolta();
    
    recolta_medie=recolta/(linii*coloane);
    
    for(int i=0;i< linii; i++)
    {
        for(int j=0; j<coloane;j++)
        {
            if(sector[i][j]<recolta_medie)
            {
                scrie_carnet(i,j,sector[i][j]);
                NUMARA_sector_rau();
                recolta_sector_rau+=sector[i][j];
            }
        }
    }
    
    system("clear");
    printf("-------------------------------");       printf("\n");
    printf("    Structura livezii:");                printf("\n");
    printf("-------------------------------");       printf("\n");
    printf("     - Rinduri  = %d",linii);            printf("\n");
    printf("     - Coloane  = %d",coloane);          printf("\n");
    printf("     - Sectoare = %d",linii*coloane);    printf("\n");
    printf("     - Copaci   = %d",3*linii*coloane);  printf("\n");
    printf("-------------------------------");       printf("\n");
    printf("   Recolta totala     = %f q",recolta);    printf("\n");
    printf("-------------------------------");       printf("\n");
    printf("    - Recolta medie      = %f q/sector",recolta_medie);              printf("\n");
    printf("    - Recolta sector_rau = %f q",recolta_sector_rau);         printf("\n");
    printf("    - Recolta sector_bun = %f q",recolta-recolta_sector_rau); printf("\n");
    printf("-------------------------------");      printf("\n");
    printf("   sectoar_rau    = %d sectoare",sector_rau);    printf("\n");
    printf("   Sectoare cu o recoltă mai mică ca recolta medie pe sector : ");  printf("\n");
    printf("-------------------------------");      printf("\n");
    afisare_carnet();
    
    return 1;
}







