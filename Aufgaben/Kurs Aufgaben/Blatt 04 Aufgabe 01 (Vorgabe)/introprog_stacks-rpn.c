#include <stdlib.h>
#include <string.h>
#include <math.h>  // definiert den speziellen Wert NaN für floats
#include "introprog_stacks-rpn.h"
#include "introprog_input_stacks-rpn.h"

/* 
 * Füge Element am Anfang des Stacks ein
 *
 * char* - Ein Pointer auf den Stack.
 * float - Zahl, die als neues Element auf den Stack gelegt
 *         werden soll.
 */
void stack_push(stack* stapel, float wert)
{
    stack_element *new_element = (stack_element *) malloc(sizeof(stack_element));

    if (new_element == NULL)
    {
    }
    
    new_element ->next = stapel->top;
    new_element->value = wert;
    stapel->top = new_element;
}

/* 
 * Nehme das letzte eingefügte Element vom Anfang des Stacks
 * Gebe NaN zurück, wenn keine Element vorhanden ist.
 *
 * stack* - Ein Pointer auf den Stack
 *
 * Gebe die im Element enthaltenen Zahl zurück
 */
float stack_pop(stack* stapel)
{
    if (stapel == NULL ||  stapel->top == NULL)
    {
        return NAN;
    }
    

    float wert = stapel->top->value;

    stack_element *elem_del = stapel->top;

    stapel->top = stapel->top->next;

    free(elem_del);

    return wert;
}

/*
 * Führt abhängig von dem Token eine entsprechende Operation auf
 * dem Stack aus.  Wenn es sich bei dem Token um
 *  -> eine Zahl handelt, dann konvertiere die Zahl mithilfe von
 *     atof() zu einem float und lege sie auf den Stack.
 *  -> einen Operator handelt, dann nehme zwei Zahlen vom Stack,
 *     führe die Operation aus und lege das Resultat auf den Stack.
 *  -> eine nichterkennbare Zeichenkette handelt, dann tue nichts.
 *
 * stack*  - Ein Pointer auf den Stack
 * char*  - Eine Zeichenkette
 */
void process(stack* stapel, char* input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (is_number(&input[i]))
        {
            stack_push(stapel, strtod(&input[i],&input));
            i = -1;
        }
        else
        {
            if(!is_add(&input[i]) && !is_sub(&input[i]) && !is_mult(&input[i]))
            {
                break;
            }

            float last_one = stack_pop(stapel);
            float secondlast_one = stack_pop(stapel);

            if (is_add(&input[i]))
            {
                stack_push(stapel,last_one + secondlast_one);
            }

            if (is_mult(&input[i]))
            {
                stack_push(stapel,last_one * secondlast_one);
            }

            if (is_sub(&input[i]))
            {
                stack_push(stapel,secondlast_one - last_one);
            }
            
        }
 
    }
    
    /* Du kannst zur Erkennung der Token folgende Hilfsfunktionen
     * benutzen:
     *
     * Funktion          Rückgabewert von 1 bedeutet
     * ---------------------------------------------
     * is_add(token)     Token ist ein Pluszeichen
     * is_sub(token)     Token ist ein Minuszeichen
     * is_mult(token)    Token ist ein Multiplikationszeichen
     * is_number(token)  Token ist eine Zahl
     */
}

/* 
 * Erstelle einen Stack mit dynamischem Speicher.
 * Initialisiere die enthaltenen Variablen.
 *
 * Gebe einen Pointer auf den Stack zurück.
 */
stack* stack_erstellen() {
    stack *stapel = (stack *) malloc(sizeof(stack));

    stapel->top = NULL;

    return stapel;
}