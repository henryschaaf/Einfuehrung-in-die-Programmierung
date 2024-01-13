/*
Willkommen zum ersten Übungsblatt vom Programmierkurs. Alles funktioniert wie auch beim ersten Aufgabenblatt.

Nachdem Sie in einem Terminal mittels des `cd` Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
cc -std=c11 -g -Wall 01practice_test.c -o 01practice_test.o -lm && ./01practice_test.o

Auf diesem Blatt geht es unter anderem um:

- Variablendeklarationen (`int variable_name = expression;`)
- Variablenzuweisungen (`variable_name = expression;`)
- Arithmetische Ausdrücke (+, -, *, /, %)
- Vergleichsausdrücke (==, !=, <, <=, >, >=)
- if-Abfragen
- while und for Schleifen
*/

#include <stdio.h>

int bakery(int cupcake, int pie, int cake) {
    int result = 0;
    /*
    Bakery:
    Ein Muffin kostet zwei Euro, ein Kuchen kostet drei Euro, eine Torte kostet vier Euro. Wer acht oder mehr
    Backwaren kauft, zahlt lediglich 80% des Preises, abgerundet auf volle Euro.

    Weisen Sie der Variable `result` den Preis von `cupcake` vielen Muffins, `pie` vielen Kuchen, und `cake`
    vielen Torten zu.
    */
    /* BEGIN CHANGES */
    result = cupcake * 2 + pie * 3 + cake * 4;

    int anzahl = cupcake + pie + cake;
    if (anzahl >= 8)
    {
        result = result * 0.8;
    }
    

    /* END CHANGES */
    return result;
}

int seconds_to_units(int input_seconds) {
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    /*
    Seconds to Units:
    Stellen Sie die durch `input_seconds` gegebene Anzahl Sekunden als möglichst viele volle Stunden, gefolgt von
    möglichst vielen übrigen vollen Minuten, gefolgt von den übrigbleibenden Sekunden dar.
    Beispiel: 12460 Sekunden ergeben 3 Stunden, 27 Minuten, und 40 Sekunden.

    Weisen Sie der Variable `hours` die Stunden, der Variable `minutes` die verbleibenden vollen Minuten, und der
    Variable `seconds` die verbleibenden Sekunden zu.
    */
    /* BEGIN CHANGES */
    hours = input_seconds / 3600;
    input_seconds = input_seconds - hours * 3600;
    minutes = input_seconds/60;
    seconds = (input_seconds - minutes * 60);


    /* END CHANGES */
    return seconds + 256 * minutes + 256 * 256 * hours;
}

int is_square_root(int n) {
    int result = 0;
    /*
    Is Square Root:
    Eine Quadratzahl ist eine natürliche Zahl (oder die Null), die das Produkt einer natürlichen Zahl mit sich selbst ist.
    Die ersten Quadratzahlen sind 0, 1, 4, 9, 16, ...

    Weisen Sie der Variable `result` den Wert `1` zu, falls `n` eine Quadratzahl ist, und ansonsten `0`.
    */
    /* BEGIN CHANGES */
    if(n < 0)
    {
        return result;
    }
    else
    {
        for (int i = 0; i * i <= n; i++)
        {
            if (i*i == n)
            {
                result = 1;
                return result;
            }
            
        }
        
    }
    /* END CHANGES */
    return result;
}

int laenge(int n)
{
    int laenge = 0;
    int mod = 1;

    if(n == 0)
    {
        return 1;
    }

    while ((n % mod) != n)
    {
        laenge++;
        mod = mod * 10;
    }
    
    return laenge;
}

int exponenzieren(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result = result * base; 
    }
    
    return result;

}

int digit_sum(int n) {
    int result = 0;
    /*
    Digits Sum:
    Die *Quersumme* einer natürlichen Zahl ist die Summe ihrer Dezimalstellen. Z.B. ist die Quersumme von 1234 die 10.
    Weisen Sie der Variable `result` die Quersumme von `n` zu.
    */
    /* BEGIN CHANGES */
    int multi = 10;
    for (int i = 1; i <= laenge(n); i++)
    {        
        result = result + (n % multi)/(multi/10);
        multi = multi * 10;
 
        

    }
    
    /* END CHANGES */
    return result;
}

int reverse_digits(int n) {
    int result = 0;
    /*
    Reverse Digits:
    Die *Spiegelung* einer natürlichen Zahl ist gegeben durch die umgekehrte Reihenfolge ihrer Dezimalstellen.
    Z.B. ist die Spiegelung von 1234 die 4321.
    Weisen Sie der Variable `result` die Spiegelung von `n` zu.
    */
    /* BEGIN CHANGES */
    printf("länge: %d \n", laenge(n));

    int multi = exponenzieren(10,laenge(n)-1);

    int mod = 10;

    for (int i = 0; i < laenge(n); i++)
    {
        result = result + (n % mod)/(mod/10) * multi;

        mod = mod * 10;
        multi = multi / 10;
    }
    
    /* END GURKENSALAT */
    return result;
}