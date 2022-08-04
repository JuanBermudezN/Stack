#include "pila.h"
#include "testing.h"
#include <stdio.h>

/*Pruebas para una pila recien creada*/
static void pruebas_pila_vacia(void) {
    printf("INICIO DE PRUEBAS DE PILA SIN ELEMENTOS\n");

    /* declaro las variables a utilizar*/
    pila_t *pila = pila_crear();

    /*Inicio de pruebas */
    print_test("crear pila con 0 elementos, ", pila != NULL);
    print_test("la pila está vacía ", pila_esta_vacia(pila) == true);
    print_test("desapilar en una pila vacía inválido", pila_desapilar(pila) == NULL);
    print_test("ver tope de una pila vacía es inválido", pila_ver_tope(pila) == NULL);
    
    pila_destruir(pila);
}


static void pruebas_pila_algunos_elementos(void){
    printf("INICIO DE PRUEBAS DE PILA CON ELEMENTOS\n");

        /* declaro las variables a utilizar*/
    pila_t *pila = pila_crear();

    int num = 5;
    int num2 = 3;
    int num3 = 10;
    int num4 = 15;
    int num5 = 8;
    int* p_num = &num;
    int* p_num2 = &num2;
    int* p_num3 = &num3;
    int* p_num4 = &num4;
    int* p_num5 = &num5;

    print_test("apilar primer elemento", pila_apilar(pila, p_num));
    print_test("el elemento que está en el tope es igual al que apilé", pila_ver_tope(pila) == p_num);
    print_test("apilar segundo elemento", pila_apilar(pila, p_num2));
    print_test("el elemento que está en el tope es igual al que apilé", pila_ver_tope(pila) == p_num2);
    print_test("apilar tercer elemento", pila_apilar(pila, p_num3));
    print_test("el elemento que está en el tope es igual al que apilé", pila_ver_tope(pila) == p_num3);
    print_test("apilar cuarto elemento", pila_apilar(pila, p_num4));
    print_test("el elemento que está en el tope es igual al que apilé", pila_ver_tope(pila) == p_num4);
    print_test("apilar quinto elemento", pila_apilar(pila, p_num5));
    print_test("el elemento que está en el tope es igual al que apilé", pila_ver_tope(pila) == p_num5);

    print_test("desapilar devuelve el quinto elemento desapilado", pila_desapilar(pila) == p_num5);
    print_test("el elemento que está ahora en el tope es el cuarto elemento apilado", pila_ver_tope(pila) == p_num4);
    print_test("desapilar devuelve el cuarto elemento apilado", pila_desapilar(pila) == p_num4);
    print_test("el elemento que está ahora en el tope es el tercer elemento apilado", pila_ver_tope(pila) == p_num3);
    print_test("desapilar devuelve el tercer elemento apilado", pila_desapilar(pila) == p_num3);
    print_test("el elemento que está ahora en el tope es el segundo elemento apilado", pila_ver_tope(pila) == p_num2);
    print_test("desapilar devuelve el segundo elemento apilado", pila_desapilar(pila) == p_num2);
    print_test("el elemento que está ahora en el tope es el primer elemento apilado", pila_ver_tope(pila) == p_num);
    print_test("desapilar devuelve el primer elemento apilado", pila_desapilar(pila) == p_num);
    print_test("la pila ahora está vacía", pila_esta_vacia(pila) == true);
    print_test("ver tope de una pila vacía es inválido", pila_ver_tope(pila) == NULL);
    print_test("desapilar en una pila vacía es inválido", pila_desapilar(pila) == NULL);

    pila_destruir(pila);
}


static void pruebas_apilar_nulo(void){
    printf("INICIO DE PRUEBAS PILA CON ELEMENTO NULO\n");

    /* declaro las variables a utilizar*/
    pila_t *pila = pila_crear();

    /*Inicio de pruebas */
    int* p = NULL;
    print_test("apilar NULL es válido", pila_apilar(pila, p));
    print_test("ver tope devuelve el elemento que apilé", pila_ver_tope(pila) == p);
    print_test("desapilar me devuelve el elemento apilado", pila_desapilar(pila) == p);
    print_test("la pila ahora está vacía", pila_esta_vacia(pila) == true);

    pila_destruir(pila);
}


static void pruebas_pila_volumen(void){
    printf("INICIO DE PRUEBAS DE VOLUMEN\n");
    
    /* declaro las variables a utilizar*/
    pila_t *pila = pila_crear();

    int i;
    bool ok = true;
    int arr[2000];

    
    for(i = 0; i < 2000; i++){
        arr[i] = i;

        ok &= pila_apilar(pila, &arr[i]);
        ok &= (pila_ver_tope(pila) == &arr[i]);
    }

    print_test("se apilaron todos los elementos correctamente y se mantuvo el invariante", ok);

    
    for(i = 1999; i > 0; i--){
        ok &= (pila_desapilar(pila) == &arr[i]);
        ok &= (pila_ver_tope(pila) == &arr[i-1]);
    } 
    print_test("se desapilaron todos los elementos correctamente menos el último y se mantuvo el invariante", ok);


    ok &= (pila_desapilar(pila) == &arr[i]);
    ok &= (pila_esta_vacia(pila));
    ok &=  (pila_ver_tope(pila) == NULL);
    ok &= (pila_desapilar(pila) == NULL);

    print_test("despues de desapilar todos los elementos, la pila se comporta como recién creada", ok);

    pila_destruir(pila);

}

void pruebas_pila_estudiante() {
    pruebas_pila_vacia();
    pruebas_pila_algunos_elementos();
    pruebas_apilar_nulo();
    pruebas_pila_volumen();
    // ...
}


/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_pila_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
