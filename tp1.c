#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define JHONNY "Jhonny Bravo"
#define BELLOTA "Bellota"
#define POLLITO "Pollito"
#define BLUE "Blue"
#define HUESO "Puro Hueso"
#define CORAJE "Coraje"

const int ALTURA_JHONNY = 180;
const int ALTURA_BELLOTA = 120;
const int ALTURA_POLLITO = 50;
const int ALTURA_BLUE = 140;
const int ALTURA_HUESO = 200;
const int ALTURA_CORAJE = 30;

const char VERDE = 'V';
const char ROSA = 'R';
const char NEGRO = 'N';
const char AMARILLO = 'Y';
const char AZUL = 'A';
const char BLANCO = 'B';
const char SALADO = 'S';
const char DULCE = 'D';
const char AMARGO = 'A';

const char COLORES[] = {NEGRO, BLANCO,AMARILLO,ROSA,AZUL,VERDE};
const char SABORES[] = {SALADO,DULCE,AMARGO};
const int TALLES[] = {0,37,38,39,40,41,42,43,44,45,46,47};

const int CANTIDAD_SABORES = 3;
const int CANTIDAD_COLORES = 6;
const int CANTIDAD_TALLES = 12;

const int ANHO_MAX = 2008, ANHO_MIN = 1988;
const int TALLE_MAX = 47, TALLE_MIN = 37, SIN_ZAPATOS = 0;
const int ALTURA_MAX =240, ALTURA_MIN =1;

typedef struct duo{
    char personaje1[12];
    char personaje2[12];
    int altura1;
    int altura2;
    
}t_duo;


void imprimir(char mensaje[]);
void pedirAnhoNacimiento(int *anho);
void pedirSabor(char *sabor);
void pedirTalle(int *talle);
void pedirColor(char *color);
void pedirAltura(int *altura);
void calcularPuntajePorColor(int *puntaje, char color);
void calcularPuntajePorSabor(int *puntaje, char sabor);
void calcularPuntajePorAnho( int *puntaje, int anho);
int calcularMultiplicador(int talle);
void calcularPuntaje(int *puntaje, int talle, int altura, int anho, char color, char sabor);
t_duo obtenerDuo(int puntaje);
void obtenerPersonaje(int puntos, int altura);
bool estaElElemento(const char vector[], char elemento, int tamanho);

void imprimir(char mensaje[]){
printf("%s",mensaje);
}

void pedirAnhoNacimiento(int *anho){
    char mensaje[] = "Ingrese su anho de nacimiento (Entre 1988 y 2008) \n --->: ";
    while( *anho > ANHO_MAX || *anho< ANHO_MIN){
        imprimir(mensaje);
        scanf(" %d", anho);
    }
}

void pedirSabor( char *sabor){

    char mensaje1[] = "Elija un sabor \n S -> salado \n M -> amargo \n D -> dulce \n --->: ";
    while(estaElElemento(SABORES, *sabor, CANTIDAD_SABORES) == false){
        imprimir(mensaje1);
        scanf(" %c", sabor);
        *sabor = toupper(*sabor);
    }
}
void pedirTalle(int *talle){
    char mensaje[] = "Ingrese talle  \n Si usa zapatos ingrese un numero entre 37 y 47 \n Si no usa zapatos ingrese 0 \n --->: ";
    while((*talle != SIN_ZAPATOS) && (*talle > TALLE_MAX || *talle < TALLE_MIN)){
        imprimir(mensaje);
        scanf("%d", talle);
    }
}

void pedirColor(char *color){
    char mensaje1[] = "Ingrese color \n";
    char opciones[] = "R para rosa \n V para verde \n A para azul \n Y para amarillo \n B para blanco \n N para negro \n";
    char mensajefinal[] = "--->: ";
    while( estaElElemento(COLORES, *color, CANTIDAD_COLORES) == false){
        imprimir(mensaje1);
        imprimir(opciones);
        imprimir(mensajefinal);
        scanf(" %c", color);
        *color = toupper(*color);
    }
}
void pedirAltura(int *altura){
    char mensaje[] = "Ingrese altura (entre 1 y 240) \n --->";
    while( *altura < ALTURA_MIN || *altura > ALTURA_MAX){
        imprimir(mensaje);
        scanf("%d", altura);
    }
}
void calcularPuntajePorColor(int *puntaje, char color){
    int puntajajePorColor = 0;
    if(color == AMARILLO || color == ROSA){
        puntajajePorColor = 5;
    }
    else if(color == NEGRO || color == BLANCO){
        puntajajePorColor = 15;
    }
    else{
        puntajajePorColor = 20;
    }
    *puntaje += puntajajePorColor;
}

void calcularPuntajePorSabor(int *puntaje, char sabor){
    int puntajePorSabor = 0;
    if(sabor == SALADO){
        puntajePorSabor = 5;
    }
    else if(sabor == DULCE){
        puntajePorSabor = 15;
    }
    else{
        puntajePorSabor =20;
    }
    *puntaje += puntajePorSabor;
}
void calcularPuntajePorAnho( int *puntaje, int anho){
    int puntajePorAnho = anho%20 +1;
    *puntaje += puntajePorAnho;
}
int calcularMultiplicador(int talle){
    int multiplicador = 3;
    if (33 <= talle && talle <=37)
    {
        multiplicador = 2;
    }
    else if(38 <= talle && talle<= 42){
        multiplicador = 3;
    }
    else if( 43 <= talle && talle <= 47){
        multiplicador = 4;
    }
    else{
        multiplicador = 1;
    }
    
    return multiplicador;
}
void calcularPuntaje(int *puntaje, int talle, int altura, int anho, char color, char sabor){
    int multiplicador = 0;
    multiplicador = calcularMultiplicador(talle);
    
    calcularPuntajePorColor(puntaje, color);
    calcularPuntajePorAnho(puntaje, anho);
    calcularPuntajePorSabor(puntaje, sabor);
    *puntaje = *puntaje * multiplicador;
}
t_duo obtenerDuo(int puntaje){
    t_duo pollitoPuroHueso = {POLLITO, HUESO, ALTURA_POLLITO,ALTURA_HUESO};
    t_duo johnyCoraje = {CORAJE, JHONNY, ALTURA_CORAJE,ALTURA_JHONNY};
    t_duo blueBellota = {BLUE, BELLOTA, ALTURA_BLUE, ALTURA_BELLOTA};

    t_duo resultado;
    if( 1 <= puntaje  && puntaje <= 80){
        resultado = johnyCoraje;
    }
    else if( 81 <= puntaje && puntaje <= 160){
        resultado = pollitoPuroHueso;
    }
    else {
        resultado = blueBellota;
    }
    return resultado;
}
void obtenerPersonaje(int puntaje, int altura){
    t_duo resultado = obtenerDuo(puntaje);
    char mensaje[] = "Con un total de ";
    char mensaje1[] = " puntos tu personaje es: ";
    imprimir(mensaje);
    printf("%d", puntaje);
    imprimir(mensaje1);
    if( abs(altura - resultado.altura1)< (abs ( altura - resultado.altura2))){
        printf("%s \n", resultado.personaje1);
    }
    else{
        printf("%s\n", resultado.personaje2);
    }
}
    bool estaElElemento(const char vector[], char elemento, int tamanho){
 
    int i = 0;
    bool esta = false;

    while (esta == false && i<tamanho){
        if(vector[i] == elemento){
            esta = true;
        }
        i+=1;
    }
    return esta;
}

int main(){
    

    int puntaje = 0;
    int anho = 0;
    int altura = 0;
    int talle = 1;
    char sabor, color;




    pedirAltura(&altura);
    pedirTalle(&talle);    
    pedirSabor(&sabor);
    pedirAnhoNacimiento(&anho);
    pedirColor(&color);

    
    calcularPuntaje(&puntaje, talle,altura,anho,color,sabor);
    obtenerPersonaje(puntaje, altura);

    return 0;
}