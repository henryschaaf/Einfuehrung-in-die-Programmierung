/*
Zur Abgabe einen branch `iprg-b06` erstellen und pushen, in dem als einzige Datei die `06ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall -Werror 06ex_test.c -o 06ex_test.o -lm && ./06ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
cc -std=c11 -g -Wall -Werror 06ex_test.c -o 06ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./06ex_test.o
*/

#include "array_visualizer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:
Machen Sie sich in dieser Aufgabe mit dem `Visualizer` (siehe array_visualizer.h) vertraut.
Nutzen Sie die `visualizer_append_array` Funktion damit die Tests durchlaufen.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/
void warmup(Visualizer *v, uint8_t *arr, size_t len) {
    
    for (int i = 0; i < len; i++)
    {
        visualizer_append_array(v,arr);
        uint8_t temp = *arr;
        for (int i = 0; i < len- 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[len - 1] = temp;
    }
}

void merge2(uint8_t *arr, int p, int q, int r)
{
    uint8_t *B = (uint8_t *) malloc(sizeof(uint8_t) * (r - p + 1));

    int i = p;
    int j = q + 1;
    int b = 0;

    while (i <= q && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            B[b] = arr[i];
            i++;
        }
        else
        {
            
            B[b] = arr[j];
            j++; 
        }
        b++;
    }
    
    while (i <= q)
    {
        B[b++] = arr[i++];
    }

    while (j <= r)
    {
        B[b++] = arr[j++];
    }

    b = 0;
    for (int i = p; i <= r; i++)
    {
        arr[i] = B[b++];
    }
    free(B);
}

void merge3(uint8_t *arr, int p, int q,int q_2, int r)
{
    uint8_t *B = (uint8_t *) malloc(sizeof(uint8_t) * (r - p + 1));

    int i = p;
    int j = q + 1;
    int k = q_2 + 1;
    int b = 0;

    while (i <= q && j <= q_2 && k <= r)
    {
        if (arr[i] <= arr[j] && arr[i] <= arr[k])
        {
            B[b] = arr[i];
            i++;
        }
        else
        {
            if (arr[j] <= arr[k])
            {
                B[b] = arr[j];
                j++;
            }
            else
            {
                B[b] = arr[k];
                k++;
            }
            
        }
        b++;
    }
    
    while (i <= q)
    {
        B[b++] = arr[i++];
    }

    while (j <= r)
    {
        B[b++] = arr[j++];
    }

    b = 0;
    for (int i = p; i <= r; i++)
    {
        arr[i] = B[b++];
    }
    free(B);
}


/*
Aufgabe 2:
Bringen Sie die Tests zum durchlaufen.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
Tipp 2: Es handelt sich um eine Abwandlung von iterativem Mergesort.
Tipp 3: `len` ist immer eine Dreierpotenz, damit Sie sich nicht mit Rundungsdetails herumschlagen brauchen.
*/
void sort_it(Visualizer *v, uint8_t *arr, size_t len) {
    visualizer_append_array(v,arr);
    int step = 1;
    
    while (step < len)
    {
        int left = 0;

        while (left < len - step)
        {
            int middle = left + step - 1;
            if (middle > len)
            {
                middle = len;
            }

            int right = left + 3 * step -1;
            if (right > len)
            {
                right = len;
            }
            
            printf("step: %d",step);
            printf("\n");
            
            printf("left: %d",left);
            printf("\n");
            printf("middle: %d",middle);
            
            printf("\n");
            printf("right: %d",right);
            
            int temp = right- ((step / 3) + 1);
            printf("\n");
            printf("mid 2: %d",(left + temp)/2);
            merge2(arr,left,middle,right - step);
            
            printf("\n");
            printf("temp: %d",temp);
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            merge2(arr,left,middle + step,right);
            visualizer_append_array(v,arr);
            left += 3 * step;
        }
        step = step * 3;
        
    }
            
    
    

    
}
