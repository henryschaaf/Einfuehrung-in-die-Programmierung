/*
Zur Abgabe einen branch `iprg-b07` erstellen und pushen, in dem als einzige Datei die `07ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall -Werror 07ex_test.c -o 07ex_test.o -lm && ./07ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
cc -std=c11 -g -Wall -Werror 07ex_test.c -o 07ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./07ex_test.o
*/

#include "sphinx.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:

Da spaziert man entspannt durch Theben, und plötzlich kommt eine Sphinx angeflogen
und spricht: "Ich habe mir ein Array mit n absteigend sortierten Zahlen überlegt (Zahlen
können mehrfach vorkommen). Du darfst mich nach dem Wert an 1 + log2(n) (aufgerundet) vielen
Positionen fragen. Und wenn du mir danach nicht sagen kannst, ob das Array die Zahl 12345
enthält, dann fresse ich dich.".

Geben Sie zurück, ob das Array der Sphinx die Zahl 12345 enthält. Um den Wert an Position `i`
zu erfragen, rufen Sie `sphinx_ask(s, i)` auf. Aber Achtung: Wenn Sie diese Funktion mehr als
1 + log2(n) (aufgerundet) mal aufrufen, stürzt das Programm fehlerhaft ab.
*/
bool descending_sphinx(Sphinx *s, size_t n) {
    printf("NEU");
    printf("\n");
    
    bool zahl_vorhanden = false;
    int count = (n + 1)/2; 
    

    
    
    printf("len: %zu  !  ", n);
    printf("%f", log(n) + 1.5);
    
    int end = log(n) /log(2) + 1.5;
    printf("\n");

    printf("%d", end);
    for (int i = 1; i <= end; i++)
    {

        int zahl;
        if(count > 0)
        {
            zahl = sphinx_ask(s,count - 1);
        }
        else
       {
            zahl = sphinx_ask(s,count);
       } 
        
        printf("count :%d",count);
        printf("i: %d",i);
        printf("zahl: %d",zahl);
        printf("pow: %f",pow(2,(i+1)));
        
        if (zahl == 12345)
        {
            printf("\n");
            printf("true");
            printf("\n");
            return true;
        }
        int old_count = count;

        if (zahl < 12345)
        {
           count -= n/pow(2,(i+1)) - 0.5;
           if (old_count == count)
           {
                count--;
           }
           
        }
        else
        {
            count += (n/pow(2,(i+1))) + 0.5;
            if (old_count == count)
           {
                count++;
           }
        }
        
        if(count > n)
        {
            printf("\n");
            printf("false");
            printf("\n");
            return zahl_vorhanden;
        }
        
    }
    
    
    printf("\n");
    printf("false");
    printf("\n");
    return zahl_vorhanden;
}
