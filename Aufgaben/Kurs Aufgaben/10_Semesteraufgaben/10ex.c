/*
Zur Abgabe einen branch `iprg-b10` erstellen und pushen, in dem als einzige Datei die `10ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall -Werror 10ex_test.c -o 10ex_test.o -lm && ./10ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
cc -std=c11 -g -Wall -Werror 10ex_test.c -o 10ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./10ex_test.o
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "tree.h"
#include "array.h"

/*
Aufgabe 1:

Implementieren Sie min-heapify auf Bäumen: gegeben ein nichtleerer, linksvollständiger Baum `t`, dessen
Kinder der Wurzel die min-heap Eigenschaft erfüllen, lassen Sie den Wert in der Wurzel so lange
"hinuntersinken", bis `t` die min-heap Eigenschaft erfüllt.

Da "hinuntersinken" nicht gerade präzise formuliert ist, müssen Sie unter Umständen Ihre Implementierung
an die Testfälle anpassen. Aber wenn Sie der Intuition der Vorlesungsfolien folgen, sollte das keine Probleme bereiten.

Werte kommen in `t` niemals mehrfach vor.
*/
void heapify_tree(TreeNode *t) {
    if (t == NULL)
    {
        return;
    }

    int min = t->item;

    if (t->left != NULL && t->left->item < t->item)
    {
        min = t->left->item;
    }
    
    if (t->right != NULL && t->right->item < min)
    {
        min = t->right->item;
    }

    if (min != t->item)
    {
        if (min == t->left->item)
        {
            t->left->item = t->item;
            t->item = min;
            heapify_tree(t->left);
        }
        else
        {
            t->right->item = t->item;
            t->item = min;
            heapify_tree(t->right);
        }
        
    }
    
    
    
    
}

/*
Aufgabe 2:

Implementieren Sie min-heapify auf Arrays: gegeben ein nichtleeres Array und eine Position `i` innerhalb des Arrays,
sodass die Kinder vom Knoten der zum Element an Position `i` gehört min-heaps sind, lassen Sie den Wert an Position `i`
solange hinuntersinken, wie nötig, um die min-heap Eigenschaft für den Teilbaum ab Position `i` wiederherzustellen.

Oder knapper: Implementieren Sie den heapify Algorithmus aus der Vorlesung, aber für min-heaps.

Werte kommen im Array niemals mehrfach vor.
*/
void heapify_array(Array arr, size_t i) {

    int min = i;

    int left = 2 * (i + 1) - 1;
    int right = 2 * (i + 1);

    if (left < arr.len && arr.arr[left] < arr.arr[i])
    {
        min = left;
    }

    if (right < arr.len && arr.arr[right] < arr.arr[min])
    {
        min = right;
    }
    
    if (min != i)
    {
        int value = arr.arr[i];
        arr.arr[i] = arr.arr[min];
        arr.arr[min] = value;

        heapify_array(arr,min);
    }
    

}
