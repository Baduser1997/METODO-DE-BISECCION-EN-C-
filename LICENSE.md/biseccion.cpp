//METODO DE BISECCION ESCRITO EN C++
//encontrar raicez de una funcion 
//El método de bisección consiste en dividir el intervalo en 2 subintervalos de igual magnitud, reteniendo el subintervalo en donde f cambia de signo,
//para conservar al menos una raíz o cero, y repetir el proceso varias veces.


#include <stdio.h> //importamos las librerias necesarias para que nuestro programa se ejecute de manera correcta
#include <stdlib.h>
#include <math.h>  //la libreria math contiene todas las operaciones algebraicas que vamos a utilizar 

double f(double);

int main()
{
    int imax,iter;  //declaramos las variable enteras maximo de iteraciones y el numero de iteraciones
    double xi,xd,ea,em,test,xa,xaold;


    printf("\nMETODO DE BISECCION\n\n");  //imprimimos un mensaje en pantalla que dice metodo de biseccion

    printf("Introduce el extremo del intervalo por la izquierda\n");// le pedimos al usuario que ingrese el intervalo por la izquierda
    scanf("%lf",&xi);  //utilizamos la funcion scan para escanear el valor introducido por el usuario
    printf("Introduce el extremo del intervalo por la derecha\n");  // le pedimos al usuario que ingrese el intervalo por la derecha
    scanf("%lf",&xd);  //utilizamos la funcion scan para escanear el valor introducido por el usuario
    printf("Introduce el numero de iteraciones maximas\n"); // le pedimos al usuario que ingrese el numero de iteraciones maximas
    scanf("%d",&imax);  //utilizamos la funcion scan para escanear el valor introducido por el usuario
    printf("Introduce el error minimo del calculo\n");  // le pedimos al usuario que ingrese el error minimo del calculo
    scanf("%lf",&em);  //utilizamos la funcion scan para escanear el valor introducido por el usuario
 
iter=0;  //inicializamos nuestra variable iteraciones en 0
xa=0;    //inicializamos nuestra variable primer valor aproximado xa en 0

if(f(xi)*f(xd)>0)     //le decimos que si f del intervlo de la izquierda* f del intervalo de la derecha es mayor a 0 nos imprima el texto no hay raiz en ese intervalo
    printf("No hay raiz en ese intervalo\n"); // imprimimos respuesta

else{     

  printf("\nIter    Raiz     Error aprox\n");  //indicamos  los datos de la tabla iteraciones, error aproximado y raiz

  do{

    iter++;    //cada que la funcion no se cumpla el numero de iteraciones va incrementando

    xaold=xa;   //cse aumenta 1 al valor de la variable xa que es nuestro contador

    xa=(xi+xd)/2;   //si xa= intervalo de la izquierda + el intervalo de la derecha entre 2 

    ea=fabs((xa-xaold)/xa)*100; //aqui se calcula el error absoluto en c++ ocupamos la funcion "fabs" para calcular el error absoluto

    test=f(xi)*f(xa); //test multiplica xi por xa 

    if(test<0)//si el test es menor a 0 
        xd=xa;   //xd se convierte en xa "valor aproximado"

    else if(test >0)//si el test es mayor  a 0 
        xi=xa; //xi ese convierte en xa "valor aproximado"

    else
        ea=0;//si el error no es ni mayor ni menor el valor es 0

    printf("\n%d    %lf    %lf",iter,xa,ea);//imprimimos la tabla con los valores con un salto de linea , numero de iteraciones,valor aproximado , y el error aproximado


  } while(ea>em && iter<imax);// si el error aproximado se mayor al valor minimo y que las iteraciones sean menor al numero de iteraciones maximo declarado por el usuario

}



    return 0;
}


double f(double x)
{
    return x*x -2;
}
