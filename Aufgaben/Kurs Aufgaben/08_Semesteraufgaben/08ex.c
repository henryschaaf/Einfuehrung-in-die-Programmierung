/*
Zur Abgabe einen branch `iprg-b08` erstellen und pushen, in dem als einzige Datei die `08ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall -Werror 08ex_test.c -o 08ex_test.o -lm && ./08ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
cc -std=c11 -g -Wall -Werror 08ex_test.c -o 08ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./08ex_test.o
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Ein Array zusammen mit seiner Länge. */
typedef struct ArrayWithLength_ {
    uint16_t *arr;
    size_t len;
} ArrayWithLength;

/*
Bei merge sort werden häufiger mal *zwei* vorsortierte Arrays kombiniert. Auf diesem Blatt
kombinieren wir effizient *beliebig viele* vorsortierte Arrays mit einem divide-and-conquer Algorithmus.
*/

/*
Aufgabe 1a:

Gegeben ein absteigend sortiertes Array, geben Sie ein absteigend sortiertes Array
mit den gleichen Elementen zurück.
Der Speicher für die Arrayelemente im Rückgabewert soll eigens mit malloc allokiert werden.

Tipp: Ja, es ist wirklich so banal wie es klingt. Das haben base-cases bei divide-and-conquer
Algorithmen häufig so an sich.
*/
ArrayWithLength base_case(ArrayWithLength arr) {
    ArrayWithLength ret;

    ret.arr = (uint16_t *) malloc(sizeof(uint16_t) * arr.len);
    ret.len = arr.len;

    for (int i = 0; i < ret.len; i++)
    {
        ret.arr[i] = arr.arr[i];
    }
    

    return ret;
}

/*
Aufgabe 1b:

Gegeben zwei absteigend sortierte Arrays der Längen len1 und len2,
geben Sie ein absteigend sortiertes Array zurück,
welches die Elemente beider Eingabearrays enthält. Die Funktion soll in O(len1 + len2) laufen.
Der Speicher für die Arrayelemente im Rückgabewert soll eigens mit malloc allokiert werden.
*/
ArrayWithLength combine(ArrayWithLength arr1, ArrayWithLength arr2) {
    ArrayWithLength ret;
    
    ret.arr = (uint16_t *) malloc(sizeof(uint16_t) * (arr1.len + arr2.len));
    ret.len = arr1.len + arr2.len;

    int j = 0;
    int i = 0;
    int k = 0;

    while (i < arr1.len && arr2.len && k < ret.len)
    {
        if (arr1.arr[i] >= arr2.arr[j])
        {
            ret.arr[k] = arr1.arr[i];
            i++;
        }
        else
        {
            ret.arr[k] = arr2.arr[j];
            j++;
        }
        
        k++;
    }
    
    while (i < arr1.len)
    {
        ret.arr[k] = arr1.arr[i];
        i++;
        k++;
    }

    while (j < arr2.len)
    {
        ret.arr[k] = arr2.arr[j];
        j++;
        k++;
    }
    
    return ret;
}

/*
Aufgabe 1c:

Gegeben ein nichtleeres Array `arrs` aus `count` vielen absteigend sortierten Arrays, geben Sie ein absteigend sortiertes Array
zurück, welches die Elemente aller Eingabearrays enthält. Ihre Lösung soll in O(n * log(count)) laufen, wobei `n` die
Gesamtzahl an Elementen in allen Arrays ist. Dazu müssen sie clever dive-and-conquern.

Der Speicher für die Arrayelemente im Rückgabewert soll eigens mit malloc allokiert werden.
*/
ArrayWithLength merge_k(ArrayWithLength *arrs, size_t count) {
    ArrayWithLength ret;
    
    
    while (count != 1)
    {
        printf("counter: %zu", count);
        printf("\n");
        for (int i = 0; i < (count + 1)/2; i++)
        {
            if (2 * i + 1 < count)
            {
                arrs[i] = combine(arrs[2 * i],arrs[2 * i + 1]);
            }
            else
            {
                if (2 * i < count)
                {
                   arrs[i] = arrs[2 * i];
                }
                
            }
            
            
        }

        count -= count/2;
        
        
    }

    ret.arr = (uint16_t *) malloc(sizeof(uint16_t) * arrs->len);

    ret.len = arrs->len;

   if (count == 1)
    {
        printf("Ende");
        for (int i = 0; i < arrs->len; i++)
        {
            printf("Hier : %d", ret.arr[i] );
            printf("\n");
            printf("Von : %d", arrs->arr[i] );
            printf("\n");

            ret.arr[i] = arrs->arr[i];

            printf("Jetzt : %d", ret.arr[i] );
            printf("\n");
            printf("\n");
        }
        //ret.arr = base_case(*arrs).arr;
    }    

    return ret;
}
