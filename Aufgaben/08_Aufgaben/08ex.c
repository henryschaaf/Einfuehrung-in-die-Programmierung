/*
Willkommen zum achten Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Pointer und Arrays.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall 08ex_test.c -o 08ex_test.o -lm && ./08ex_test.o
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "turtlecanvas.h"

/*
Aufgabe 1a:
Lesen Sie das Headerfile `turtlecanvas.h`. Diese Funktion soll die Turtle `d` Schritte vorwärts machen lassen.
*/
void turtle_advance_by(TurtleCanvas *c, uint32_t d) {
    for (int i = 0; i < d; i++)
    {
        turtle_advance(c);
    }
    
    return;
}

/*
Aufgabe 1b:
Füllen Sie die Turtlecanvas mit horizontalen, abwechselnd schwarzen und weißen Linien (die unterste Zeile soll
schwarz gefärbt werden). Die Turtle ist anfangs an Position (0, 0), ist nach rechts orientiert, und zeichnet schwarz.
*/
void turtle_stripes(TurtleCanvas *c) {
    int i = 0;
    while (i < turtle_canvas_height(c))
    {

        if (i % 2 == 0)
        {
            turtle_advance_by(c,turtle_canvas_width(c));
        }

            turtle_rotate_left(c);
            turtle_advance(c);
            turtle_rotate_right(c);
            turtle_toggle_color(c);
            i++;
        
    }
    
    return;
}

/*
Aufgabe 1c:
Lesen Sie die Implementierungen der Turtlecanvas-Funktionen weiter unten in der "turtlecanvas.h".
Der Quellcode sollte vollständig verständlich und unüberraschend sein.
Hinweis: Diese Aufgabe wird nicht bewertet.
*/

/*
Aufgabe 2a:
Geben Sie einen Pointer auf das erste Vorkommen der größten Zahl im Eingabearray zurück.
*/
uint16_t *find_maximal_number(uint16_t numbers[], size_t numbers_len) {
    uint16_t *max = numbers;

    for (int i = 0; i < numbers_len; i++)
    {
        if (*max < numbers[i])
        {
            max = &numbers[i];
        }
        
    }
    
    return max;
}

/*
Aufgabe 2b:
Geben Sie (einen Pointer auf) das Teilarray zurück, welches ab dem ersten Vorkommen der größten Zahl im Eingabearray beginnt.
*/
uint16_t *find_subarray_starting_at_maximal_number(uint16_t numbers[], size_t numbers_len) {
    
    return find_maximal_number(numbers,numbers_len);

}

/*
Aufgabe 2c:
Geben Sie die größtmögliche Distanz zwischen zwei Zahlenwerten aus dem Array `numbers` zurück.
Beispiel: Im Array {1, 3, 7, 4} ist die größte Distanz die zwischen 1 und 7, und beträgt damit `6`.
*/
uint16_t find_maximum_distance(uint16_t numbers[], size_t numbers_len) {
    uint16_t min = numbers[0];
    uint16_t max = 0;

    for (int i = 0; i < numbers_len; i++)
    {
        if (min > numbers[i])
        {
            min = numbers[i];
        }

        if (max < numbers[i])
        {
            max = numbers[i];
        }
        }
    
    return max - min;
}

/*
Aufgabe 2d:
Geben Sie die kleinstmögliche Distanz zwischen zwei Zahlenwerten aus dem Array `numbers` zurück.
Beispiel: Im Array {1, 3, 7, 4} ist die kleinste Distanz die zwischen 3 und 4, und beträgt damit `1`.
*/
uint16_t find_minimum_distance(uint16_t numbers[], size_t numbers_len) {
    uint16_t min;
    uint16_t max;
    uint16_t diff;

    if (numbers == 0)
    {
        return -1;
    }
    

    if (numbers[0] - numbers[1] >= 0)
    {
        diff = numbers[0] - numbers[1];
        max = numbers[0];
        min = numbers[1];
    }
    else
    {
        diff = numbers[1] - numbers[0];
        max = numbers[1];
        min = numbers[0];
    }
    

    for (int i = 2; i < numbers_len; i++)
    {
   
        if (max - numbers[i] >= 0 && max - numbers[i] < diff)
        {
            min = numbers[i];
        }
        else
        {
            if (numbers[i] - min >= 0 && numbers[i] - min < diff)
            {
                max = numbers[i];
            }
            else
            {
               if (numbers[i] - max >= 0 && numbers[i] - max < diff )
                {
                                   
                    min = max;

                    max = numbers[i];

                }
                else
                {
                  if (min - numbers[i] >= 0 && min - numbers[i] < diff)
                {

                    max = min;

                    min = numbers[i];

                }  
                }
            }
        }

        diff = max - min;

        
    }
    
    return diff;
}

/*
Aufgabe 2e:
Schreiben Sie die ersten `numbers_len` Quadratzahlen aufsteigend in das gegebene Array `numbers`.
Hinweis: Wir starten bei `1`. Sollte numbers_len also `5` sein, sind die ersten 5 Quadratzahlen bis
einschließlich die von 5 gemeint: 1, 4, 9, 16, 25.
*/
void square_ascending(uint16_t numbers[], size_t numbers_len) {
    for (int i = 1; i <= numbers_len; i++)
    {
        numbers[i-1] = i * i;
    }
    
    return ;
}

void switch_arr(uint16_t in[], int one, int two)
{
    uint16_t placeholder = in[one];
    in[two] = in[one];
    in[one] = placeholder;

}

void put_at_index(uint16_t in[], int new_index, int old_index)
{
    uint16_t value = in[old_index];

    for (int i = new_index; i <= old_index; i++)
    {
        in[new_index + i] = in[new_index + i - 1];
    }
    
    in[new_index] = value;
}

/*
Aufgabe 2f:
Füllen Sie das Array `out` mit den aufsteigend sortierten Zahlen aus dem `in` Array. Beide Arrays haben die Länge `len`.
Beispiel: Ist `in` {1, 4, 3, 7, 4}, so soll `out` am Ende {1, 3, 4, 4, 7} sein.
*/
void sort_ascending(uint16_t in[], uint16_t out[], size_t len) {
    for (int i = 0; i < len; i++)
    {
        out [i] = *find_maximal_number(in, len);
    }

    for (int i = 0; i < len; i++)
    {
        int j = 0;
        while (in[i] > out[j])
        {
            j++;
        }

        out[len-1] = in[i];
        put_at_index(out,j,i);
        
        
        
    }
    
    return;
}
