 #include "pedine.h"
#include "turni_players.h"
#include "campo.h"
#include <stdio.h>


void crea_pedina_quadrata(char campo[15][10],int riga, int colonna)    /*ped.quadrata*/
{
    while(1)
    {
        if(campo[riga-1][colonna]=='.' && campo[riga][colonna+1] == '.' && campo[riga-1][colonna+1] == '.')
        {
            campo[riga][colonna] = '#';
            campo[riga-1][colonna] = '#';
            campo[riga][colonna+1] = '#';
            campo[riga-1][colonna+1] = '#';
            return;
        }
        else
        {
            riga=riga-1;
            if (riga<=0)
                return;
        }
    }
}

void c_e_pedina_quadrata(char campo[15][10], int riga, int colonna, int scelta_pedina)
{
    int break_loop=0;
    if(colonna>8 || colonna<0)
    {
        while(break_loop==0)
        {
            if(colonna<0 || colonna>8)
            {
                printf("la pedina esce dal campo in larghezzaaa, inserire una nuova colonna: ");
                scanf("%d", &colonna);
            }
            else
            {
                break_loop=1;
            }
        }
        riga = caduta_pedina(campo,colonna,scelta_pedina);
    }
    crea_pedina_quadrata(campo, riga, colonna);
}

void crea_pedina_i(char campo[15][10], int riga, int colonna,int rotazione)   /*pedina i*/
{
    if (rotazione==1)
    {
        campo[riga][colonna] = '&';
        campo[riga-1][colonna] = '&';
        campo[riga-2][colonna] = '&';
        campo[riga-3][colonna] = '&';
    }
    if (rotazione == 2)
    {
        while(1)
        {
            if(campo[riga][colonna+1]=='.' && campo[riga][colonna+2]=='.' && campo[riga][colonna+3] =='.')
            {
                campo[riga][colonna] = '&';
                campo[riga][colonna+1] = '&';
                campo[riga][colonna+2] = '&';
                campo[riga][colonna+3] = '&';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<0)
                    return;
            }
        }
    }
}

int c_e_pedina_i(char campo[15][10], int riga, int colonna,int scelta_pedina)
{
    int rotazione, break_loop=0;
    printf("scegli rotazione: (1=verticale, 2=orizzontale): ");
    scanf("%d",&rotazione);
    if(rotazione<1 || rotazione>2)
    {
        while(break_loop==0)
        {
            if(rotazione<1 || rotazione>2)
            {
                printf("attenzione!! hai inserito una rotazione inesistente!! scegli una nuova rotazione: \n");
                printf("scegli rotazione: (1=verticale, 2=orizzontale): ");
                scanf("%d",&rotazione);
            }
            else
            {
                break_loop=1;
            }
        }
        break_loop=0;
    }
    if(rotazione == 1)
    {
        if(colonna>9 || colonna<0)
        {
            while(break_loop==0)
            {
                if(colonna<0 || colonna>9)
                {
                    printf("la pedina esce dal campo in larghezza, inserire una nuova colonna: ");
                    scanf("%d", &colonna);
                }
                else
                {
                    break_loop=1;
                }
            }
            break_loop=0;
            riga=caduta_pedina(campo,colonna,scelta_pedina);
        }
    }
    if(rotazione == 2)
    {
        while(break_loop==0)
        {
            if(colonna<0 || colonna>=7)
            {
                printf("la pedina esce dal campo in larghezza, inserire una nuova colonna: ");
                scanf("%d", &colonna);
            }
            else
            {
                break_loop=1;
            }
        }
        riga=caduta_pedina(campo,colonna,scelta_pedina);
    }
    crea_pedina_i(campo,riga,colonna,rotazione);
    return rotazione;
}

void crea_pedina_z(char campo[15][10], int riga, int colonna, int rotazione)
{
    if (rotazione==1)
    {
        while(1)
        {
            if(campo[riga][colonna+1] == '.' && campo[riga-1][colonna+1] == '.' && campo[riga-1][colonna+2] == '.')
            {
                campo[riga][colonna] = '$';
                campo[riga][colonna+1] = '$';
                campo[riga-1][colonna+1] = '$';
                campo[riga-1][colonna+2] = '$';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<=0)
                    return;
            }
        }
    }
    if(rotazione==2)
    {
        while(1)
        {
            if(campo[riga][colonna+1] == '.' && campo[riga+1][colonna+1] == '.' && campo[riga+1][colonna+2] == '.')
            {
                campo[riga][colonna] = '$';
                campo[riga][colonna+1] = '$';
                campo[riga+1][colonna+1] = '$';
                campo[riga+1][colonna+2] = '$';
                return;
            }
            else
            {
                riga = riga-1;
                if(riga<=0)
                    return;
            }
        }
    }
    if(rotazione==3)
    {
        while(1)
        {
            if(campo[riga-1][colonna] == '.' && campo[riga-1][colonna+1] == '.' && campo[riga-2][colonna+1] == '.' )
            {
                campo[riga][colonna] = '$';
                campo[riga-1][colonna] = '$';
                campo[riga-1][colonna+1] = '$';
                campo[riga-2][colonna+1] = '$';
                return;
            }
            else
            {
                riga = riga-1;
                if(riga<=1)
                    return;
            }
        }
    }
    if(rotazione==4)
    {
        while(1)
        {
            if(campo[riga-1][colonna] == '.' && campo[riga][colonna+1] == '.' && campo[riga+1][colonna+1] == '.' )
            {
                campo[riga][colonna] = '$';
                campo[riga-1][colonna] = '$';
                campo[riga][colonna+1] = '$';
                campo[riga+1][colonna+1] = '$';
                return;
            }
            else
            {
                riga = riga-1;
                if(riga<=1)
                    return;
            }
        }
    }
}

int c_e_pedina_z(char campo[15][10], int riga, int colonna,int scelta_pedina)
{
    int break_loop=0, rotazione;
    printf("scegli rotazione: (1=Z.specchio, 2=Z, 3=Z.verticale, 4=Z.verticale.specchio): ");
    scanf("%d",&rotazione);
    if(rotazione<1 || rotazione>4)
    {
        while(break_loop==0)
        {
            if(rotazione<1 || rotazione>4)
            {
                printf("attenzione!! hai inserito una rotazione inesistente!! scegli una nuova rotazione: \n");
                printf("scegli rotazione: (1=Z.specchio, 2=Z, 3=Z.verticale, 4=Z.verticale.specchio): ");
                scanf("%d",&rotazione);
            }
            else
            {
                break_loop=1;
            }
        }
        break_loop=0;
    }
    if(rotazione==1 || rotazione==2)
    {
        while(break_loop==0)
        {
            if(colonna<0 || colonna>7)
            {
                printf("la pedina esce dal campo in larghezza, inserire una nuova colonna: ");
                scanf("%d", &colonna);
            }
            else
            {
                break_loop=1;
            }
        }
        break_loop=0;
        riga=caduta_pedina(campo,colonna,scelta_pedina);
    }
    if(rotazione==3 || rotazione ==4)
    {
        while(break_loop==0)
        {
            if(colonna<0 || colonna > 8)
            {
                printf("la pedina esce dal campo in larghezza, inserire una nuova colonna: ");
                scanf("%d", &colonna);
                continue;
            }
            else
            {
                break_loop=1;
            }
        }
        riga=caduta_pedina(campo,colonna,scelta_pedina);
    }
    crea_pedina_z(campo,riga,colonna,rotazione);
    return rotazione;
}

void crea_pedina_t(char campo[15][10], int riga, int colonna, int rotazione)
{
    if (rotazione ==1)
    {
        while(1)
        {
            if(campo[riga][colonna+1] == '.' && campo[riga][colonna+2] == '.' && campo[riga-1][colonna+1] == '.')
            {
                campo[riga][colonna] = '*';
                campo[riga][colonna+1] = '*';
                campo[riga][colonna+2] = '*';
                campo[riga-1][colonna+1] = '*';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<=0)
                    return;
            }
        }
    }
    if (rotazione == 2)
    {
        while(1)
        {
            if(campo[riga][colonna+1] == '.' && campo[riga][colonna+2]=='.' && campo[riga+1][colonna+1] == '.')
            {
                campo[riga][colonna] = '*';
                campo[riga][colonna+1] ='*';
                campo[riga][colonna+2] ='*';
                campo[riga+1][colonna+1] = '*';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<=0)
                    return;
            }
        }
    }
    if (rotazione==3)
    {
        while(1)
        {
            if(campo[riga-1][colonna] == '.' && campo[riga-2][colonna] == '.' && campo[riga-1][colonna+1] == '.')
            {
                campo[riga][colonna] = '*';
                campo[riga-1][colonna] = '*';
                campo[riga-2][colonna] = '*';
                campo[riga-1][colonna+1] = '*';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<=1)
                    return;
            }
        }
    }
    if (rotazione == 4)
    {
        while(1)
        {
            if(campo[riga][colonna+1] == '.' && campo[riga-1][colonna+1]== '.' && campo[riga+1][colonna+1]== '.')
            {
                campo[riga][colonna] = '*';
                campo[riga][colonna+1] = '*';
                campo[riga-1][colonna+1] = '*';
                campo[riga+1][colonna+1] = '*';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<=1)
                    return;
            }
        }
    }
}

int c_e_pedina_t(char campo[15][10], int riga, int colonna,int scelta_pedina)
{
    int break_loop=0, rotazione;
    printf("scegli rotazione: (1=T.roveciata, 2=T, 3=T.laterale, 4=T.laterale.specchio): ");
    scanf("%d",&rotazione);
    if(rotazione<1 || rotazione>4)
    {
        while(break_loop==0)
        {
            if(rotazione<1 || rotazione>4)
            {
                printf("attenzione!! hai inserito una rotazione inesistente!! scegli una nuova rotazione: \n");
                printf("scegli rotazione: (1=T.roveciata, 2=T, 3=T.laterale, 4=T.laterale.specchio): ");
                scanf("%d",&rotazione);
            }
            else
            {
                break_loop=1;
            }
        }
        break_loop=0;
    }
    if(rotazione==1 || rotazione==2)
    {
        while(break_loop==0)
        {
            if(colonna<0 || colonna >7)
            {
                printf("la pedina esce dal campo in larghezza, inserire una nuova colonna: ");
                scanf("%d", &colonna);
            }
            else
            {
                break_loop=1;
            }
        }
        break_loop=0;
        riga=caduta_pedina(campo,colonna,scelta_pedina);
    }
    if(rotazione ==3 || rotazione ==4)
    {
        while(break_loop==0)
        {
            if(colonna<0 || colonna>8)
            {
                printf("la pedina esce dal campo in larghezza, inserire una nuova colonna: ");
                scanf("%d", &colonna);
            }
            else
            {
                break_loop=1;
            }
        }
        riga=caduta_pedina(campo,colonna,scelta_pedina);
    }
    crea_pedina_t(campo,riga,colonna,rotazione);
    return rotazione;
}

void crea_pedina_L(char campo[15][10], int riga, int colonna, int rotazione)
{
    if(rotazione==1)
    {
        while(1)
        {
            if(campo[riga][colonna+1]=='.' && campo[riga-1][colonna]=='.' && campo[riga-2][colonna]=='.')
            {
                campo[riga][colonna]='@';
                campo[riga][colonna+1]='@';
                campo[riga-1][colonna]='@';
                campo[riga-2][colonna]='@';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<2){
                    return;
                }
            }
        }
    }
    if(rotazione==2)
    {
        while(1)
        {
            if(campo[riga][colonna+1]=='.' && campo[riga-1][colonna+1]=='.' && campo[riga-2][colonna+1]=='.')
            {
                campo[riga][colonna]='@';
                campo[riga][colonna+1]='@';
                campo[riga-1][colonna+1]='@';
                campo[riga-2][colonna+1]='@';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<2)
                    return;
            }
        }
    }
    if(rotazione==3)
    {
        while(1)
        {
            if(campo[riga-1][colonna]=='.' && campo[riga][colonna+1]=='.' && campo[riga][colonna+2]=='.')
            {
                campo[riga][colonna]='@';
                campo[riga-1][colonna]='@';
                campo[riga][colonna+1]='@';
                campo[riga][colonna+2]='@';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<1)
                    return;
            }
        }
    }
    if(rotazione==4)
    {
        while(1)
        {
            if(campo[riga][colonna+1]=='.' && campo[riga][colonna+2]=='.' && campo[riga-1][colonna+2]=='.')
            {
                campo[riga][colonna]='@';
                campo[riga][colonna+1]='@';
                campo[riga][colonna+2]='@';
                campo[riga-1][colonna+2]='@';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<1)
                    return;
            }
        }
    }
    if(rotazione==5)
    {
        while(1)
        {
            if(campo[riga][colonna+1]=='.' && campo[riga+1][colonna+1]=='.' && campo[riga+2][colonna+1]=='.')
            {
                campo[riga][colonna]='@';
                campo[riga][colonna+1]='@';
                campo[riga+1][colonna+1]='@';
                campo[riga+2][colonna+1]='@';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<2)
                    return;
            }
        }
    }
    if(rotazione==6)
    {
        while(1)
        {
            if(campo[riga-1][colonna]=='.' && campo[riga-2][colonna]=='.' && campo[riga-2][colonna+1]=='.')
            {
                campo[riga][colonna]='@';
                campo[riga-1][colonna]='@';
                campo[riga-2][colonna]='@';
                campo[riga-2][colonna+1]='@';
                return;
            }
            else
            {
                riga=riga-1;
                if(riga<2)
                    return;
            }
        }
    }
}

int c_e_pedina_L(char campo[15][10], int riga, int colonna,int scelta_pedina)
{
    int break_loop=0, rotazione;
    printf("scegli rotazione: 1= L, 2= L.specchio, 3= L.distesa, 4= L.distesa.specchio, 5= L.rovesciata, 6= L.rovesciata.specchio: ");
    scanf("%d",&rotazione);
    if(rotazione<1 || rotazione>6)
    {
        while(break_loop==0)
        {
            if(rotazione<1 || rotazione>6)
            {
                printf("attenzione!! hai inserito una rotazione inesistente!! scegli una nuova rotazione: \n");
                printf("scegli rotazione: 1= L, 2= L.specchio, 3= L.distesa, 4= L.distesa.specchio, 5= L.rovesciata, 6= L.rovesciata.specchio: ");
                scanf("%d",&rotazione);
            }
            else
            {
                break_loop=1;
            }
        }
        break_loop=0;
    }
    if(rotazione==1 || rotazione==2 || rotazione==5 || rotazione==6)
    {
        while(break_loop==0)
        {
            if(colonna<0 || colonna>8)
            {
                printf("la pedina esce dal campo in larghezza, inserire una nuova colonna: ");
                scanf("%d", &colonna);
            }
            else
            {
                break_loop=1;
            }
        }
        break_loop=0;
        riga=caduta_pedina(campo,colonna,scelta_pedina);
    }
    if(rotazione == 3 || rotazione ==4)
    {
        while(break_loop==0)
        {
            if(colonna<0 || colonna >7)
            {
                printf("la pedina esce dal campo in larghezza, inserire una nuova colonna: ");
                scanf("%d", &colonna);
            }
            else
            {
                break_loop=1;
            }
        }
        riga=caduta_pedina(campo,colonna,scelta_pedina);
    }
    crea_pedina_L(campo,riga,colonna,rotazione);
    return rotazione;
}
