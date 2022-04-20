

//Universidad Nacional Autonoma De Mexico
//Facultad De Ingenieria
//Sistemas Distribuidos 
//Semestre 2022-2
//Ceballos Ricardo Fernando

#include<stdio.h>
#include<conio.h>
#define X 20    //el numero de filas declarado en una constante
#define Y 20   //el numero de columnas declarado en una constante
int main()
{
//declaración de variables
int ix, iy, ixd, ixe, iys, iyi, vius,vivos; //las variables ixd(ix derecha), iys(iy superior).etc..
//sirven para comprobar las casillas
//alrededor de la casilla que se examina
char mundo[X][Y], estado[X][Y], opc;  //una tabla se mostrará, en la otra se aplicarán los cambios
//inicializar tabla mundo
for(ix=0; ix<X; ix++)
    {
        for(iy=0; iy<Y; iy++)
        {
            mundo[ix][iy]=' ';
        }
    }
//mostrar un menú y escoger el estado inicial de nuestro juego de la vida
printf("Selecciona el estado inicial:\na)bloque\nb)parpadeador\n\n");

do  //mientras la opción no sea valida, seguirá leyendo hasta dar con una letra valida
{
    scanf("%c", &opc);
}while(opc<'a' || opc>'f');

//situar estado inicial
switch(opc)
{
   case 'a':mundo[0][0]='#';mundo[0][1]='#';mundo[1][0]='#';mundo[1][1]='#';break;
   case 'b':mundo[0][0]='#';mundo[0][1]='#';mundo[1][0]='#';mundo[1][2]='#';mundo[2][1]='X';break;

   default: printf("error, ha de ser entre 'a' i 'f'");
}
//bucle infinito, dado que el juego de la vida no tiene final
    while(1==1)
    {   //for para mostrar la tabla mundo
        for(ix=0; ix<X; ix++)
        {
            for(iy=0; iy<Y; iy++)
            {
                printf("%c",mundo[ix][iy]);
            }
            printf("\n");
        }
        
        //recorrido total para comprobar si ha llegado al limite de la tabla
        for(ix=0; ix<X; ix++)
        {
            for(iy=0; iy<Y; iy++)
            {
                vivos=0;

                if(ix>=X-1)
                    ixd=0;
                else
                    ixd=ix+1;

                if(iy>=Y-1)
                    iyi=0;
                else
                    iyi=iy+1;

                if(ix<=0)
                    ixe=X-1;
                else
                    ixe=ix-1;

                if(iy<=0)
                    iys=Y-1;
                else
                    iys=iy-1;

                //comprobación para saber si los vecinos están vivos o muertos
                if(mundo[ixd][iy]=='#')    vivos++;
                if(mundo[ixe][iy]=='#')    vivos++;
                if(mundo[ix][iys]=='#')    vivos++;
                if(mundo[ix][iyi]=='#')    vivos++;
                if(mundo[ixd][iys]=='#')   vivos++;
                if(mundo[ixe][iys]=='#')   vivos++;
                if(mundo[ixd][iyi]=='#')   vivos++;
                if(mundo[ixe][iyi]=='#')   vivos++;

                //condicional para determinar si la casilla vive o muere
                if(mundo[ix][iy]=='#')
                {
                    // esta vivo
                    if(vivos<=1 || vivos>3)
                    {
                        estado[ix][iy]=' ';
                    }else{
                            estado[ix][iy]='#';
                    }

                }else
                {
                    // esta muerto
                    if(vivos==3)
                    {
                        estado[ix][iy]='#';
                    }else{

                        estado[ix][iy]=' ';
                    }
                }

            }// final del for iy

        } // final del for ix

        //guardamos la tabla estado en la tabla mundo, para que la próxima vez que entre en el bucle se muestre actualizada
        for(ix=0; ix<X; ix++)
        {
            for(iy=0; iy<Y; iy++)
            {
                mundo[ix][iy]=estado[ix][iy];
            }
        }  //final del for para guardar la tabla estado en la tabla mundo

    } //final del bucle

}
