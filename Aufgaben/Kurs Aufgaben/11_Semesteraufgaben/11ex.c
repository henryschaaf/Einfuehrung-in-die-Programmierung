/*
Zur Abgabe einen branch `iprg-b11` erstellen und pushen, in dem als einzige Datei die `11ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall -Werror 11ex_test.c -o 11ex_test.o -lm && ./11ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
cc -std=c11 -g -Wall -Werror 11ex_test.c -o 11ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./11ex_test.o
*/

#include "array_visualizer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:
Implementieren Sie folgenden Algorithmus, um ein Array zu partitionieren:

- die `pivot_position` ist initial die letzte Stelle im Array
- der Wert an der `pivot_position` ist das `pivot` Element
- solange es links der `pivot_position` Elemente gibt, die größer oder gleich `pivot` sind:
    - sei `i` die Position des linkesten solchen Elements
    - rotiere die Werte an den Positionen `i`, `pivot_position - 1` und `pivot_position` nach links (siehe Testoutput)
    - dekrementiere die `pivot_position`

Nutzen Sie die `visualizer_append_array` Funktion (siehe `array_visualizer.h` bzw das sechste Semesteraufgabenblatt 06) um den Algorithmus zu visualisieren. Und nutzen Sie die vom Testrunner erstellten Bilder zum Debuggen, und falls Ihnen das zu erwartende Verhalten unklar ist.

Imaginäre Bonuspunkte, wenn Ihre Implementierung in linearzeit läuft.

Tipp: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/
void visualize_partition(Visualizer *v, uint8_t *arr, size_t len) {
    visualizer_append_array(v, arr);
    int pivot = len - 1;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] >= arr[pivot] && pivot > 0)
        {
            int value = arr[i];
            arr[i] = arr[pivot - 1];
            arr[pivot - 1] = arr[pivot];
            arr[pivot] = value;
            pivot --;
            i--;
            visualizer_append_array(v, arr);
        }
        
    }
    
    return;
}

void sort_quickly_rec(Visualizer *v, uint8_t *arr, size_t len,int start, int pivot)
{
    int pivot_start = pivot;
    if (start >= pivot)
    {
        printf("Fertig");
        printf("\n");
        return;
    }

    printf("start %d", start);
    printf("\n");
    printf("pivot %d", pivot);
    printf("\n");
    printf("\n");

   for (int i = start; i < pivot; i++)
    {
        if (arr[i] >= arr[pivot] && pivot > 0)
        {
            int value = arr[i];
            arr[i] = arr[pivot - 1];
            arr[pivot - 1] = arr[pivot];
            arr[pivot] = value;
            pivot --;
            i--;
        }
    }

    visualizer_append_array(v, arr);


    int start_left = start;
    int pivot_left = pivot - 1;
    int start_right = pivot + 1;
    int pivot_right = pivot_start;
    printf("start left %d", start_left); //[160, 32, 96, 128, 224, 64, 192, 0, 255] 
    printf("\n");
    printf("pivot left %d", pivot_left);
    printf("\n");
    printf("\n");
    printf("start right %d", start_right);
    printf("\n");
    printf("pivot right %d", pivot_right);
    printf("\n");
    printf("\n");

    sort_quickly_rec(v,arr,len,start_left,pivot_left);
    sort_quickly_rec(v,arr,len,start_right,pivot_right);
    
}

/*
Aufgabe 2:
Implementieren Sie Quicksort rekursiv, und visualisieren Sie den Algorithmus wie von den Tests verlangt.

Wählen Sie als Pivotelement stets das letzte Element eines Teilarrays, und partitionieren Sie mit dem in Aufgabe 1 beschriebenen Algorithmus.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
Tipp 2: Visualisieren Sie außerdem das Array immer nachdem Sie ein Teilarray der Größe mindestens zwei partitioniert haben.
Tipp 3: Diese Funktion selbst lässt sich nicht sinnvoll rekursiv aufrufen. Schreiben Sie eine geeignete Funktion, und rufen Sie sie in `sort_quickly` auf.
*/
void sort_quickly(Visualizer *v, uint8_t *arr, size_t len) {
    visualizer_append_array(v, arr);
    printf("NEW");
    printf("\n");
    sort_quickly_rec(v,arr,len,0,len-1);
    
    
    return;
}
