/*
Zur Abgabe einen branch `iprg-b09` erstellen und pushen, in dem als einzige Datei die `09ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall -Werror 09ex_test.c -o 09ex_test.o -lm && ./09ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
cc -std=c11 -g -Wall -Werror 09ex_test.c -o 09ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./09ex_test.o
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "tree.h"
#include "array.h"

/*
Aufgabe 1:

Gegeben ein Array `arr`, geben Sie zurück, ob der zugehörige linksvollständige Binärbaum
die max-heap Eigenschaft erfüllt.
*/
bool is_max_heap(Array arr) {
    printf("\n");
    printf("\n");
    printf("\n");
    printf("NEW");
    printf("\n");
    printf("length: %zu", arr.len);
    printf("\n");
    bool is_max_heap = true;
    
    for (int i = 0; i < arr.len; i++)
    {
        int left = 2 * (i + 1);
        int right = 2 * (i + 1) + 1;
        printf("left %d", left);
        printf("\n");
        printf("right %d", right);
        printf("\n");
        printf("\n");

        if (left <= arr.len)
        {
            printf("left child");
            printf("\n");
            if (arr.arr[i] >= arr.arr[left - 1]) // minus eins weil die Formel zur Berechnung bei der Wurzel mit eins beginnt
            {
                printf("min");
                printf("\n");
            }
            else
            {
                printf("max");
                printf("\n");
                return false;
            }
            
        }


        if (right <= arr.len)
        {
            printf("right child");
            printf("\n");
            if (arr.arr[i] >= arr.arr[right - 1]) // minus eins weil die Formel zur Berechnung bei der Wurzel mit eins beginnt
            {
                printf("min");
                printf("\n");
            }
            else
            {
                printf("max");
                return false;
            }
        }
        printf("\n");
        
    }
    
    return is_max_heap;
}


void tree_to_arrray_rec(TreeNode *t, Array arr, int pos)
{
    if (t == NULL)
    {
        return;
    }
    
    printf("Start Rek.");
    printf("\n");

    if (pos - 1 < arr.len)
    {
        printf("Einfuegen");
        printf("\n");
        arr.arr[pos - 1] = t->item;
    }
    else
    {
        printf("Fehler, Array nicht lan genug");
    }

    if (t->left != NULL)
    {
        printf("left");
        printf("\n");
        tree_to_arrray_rec(t->left, arr, 2 * (pos));
    }

    if (t->right != NULL)
    {
        printf("right");
        printf("\n");
        tree_to_arrray_rec(t->right, arr, 2 * (pos) + 1);
    }
    
    
    
}

/*
Aufgabe 2:

Gegeben ein linksvollständiger Binärbaum, tragen Sie im Array `arr` dessen Arrayrepräsentation ein.



Tipp 1: Wie so häufig bei Bäumen, bietet sich hier eine rekursive Lösung an.
Tipp 2: Diese Funktion selbst ist allerdings nur so mäßig gut für rekursive Aufrufe geeignet, eventuell sollten Sie sich eine (rekursive) Hilfsfunktion schreiben.
Tipp 3: Die Position eines Knotens im Array lässt sich relativ leicht bestimmen, wenn man die Position vom Elternknoten weiß, und, ob es sich um ein linkes oder ein rechtes Kind handelt.
Tipp 4: Ja, das sind also sinnvolle Argumente für die Hilfsfunktion.
Tipp 5: Regelmäßig zähneputzen und genug bewegen.
*/
void tree_to_array(TreeNode *t, Array arr) {

    tree_to_arrray_rec(t,arr,1);
}
