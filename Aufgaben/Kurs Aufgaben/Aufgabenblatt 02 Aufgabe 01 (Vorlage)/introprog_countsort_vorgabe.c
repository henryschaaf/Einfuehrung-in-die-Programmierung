#include <stdio.h>
#include <string.h>
#include "introprog_countsort.h"
#include "arrayio.h"
/* Ab hier Funktion count_sort_calculate_counts implementieren */

void count_sort_calculate_counts(int arr_in[], int len, int count_array[]) {

    for (size_t i = 0; i < len; i++)
    {
        count_array[arr_in[i]] = count_array[arr_in[i]] +1;
    }
    
}

/* Ab hier Funktion count_sort_write_output_array implementieren */

void count_sort_write_output_array(int arr_out[], int c[],  SortDirection order) {

    
    int k = 0;
    if (order == DESCENDING)
    {
        printf("Descending\n");
        for (int i = MAX_VALUE - 1; i >= 0; i--)
        {
            for (int j = 0; j < c[i]; j++)
            {
                arr_out[k] = i;
                k++;
            }
        
        }
    }
    else
    {
        printf("Ascending\n");
        for (int i = 0; i <= MAX_VALUE; i++)
        {
            for (int j = 0; j < c[i]; j++)
            {
                arr_out[k] = i;
                k++;
            }
        
        }
    }
    

}

/* Ab hier Funktion extract_order_direction implementieren */

SortDirection extract_order_direction(char *order) {
    SortDirection direction;
    if (strcmp(order,"asc") == 0)
    {
        printf("A");
        direction = ASCENDING;
    }
    else
    {
        if (strcmp(order,"desc") == 0)
        {
            printf("D");
            direction = DESCENDING;
        }
        else
        {
            printf("N");
            direction = NOTDEFINED;
        }
        
    }
    
    return direction;
}

/* Ab hier Funktion count_sort implementieren und entsprechende Funktionsaufrufe einfügen */

void count_sort(int input_array[], int len, int output_array[], SortDirection order) {

    printf("Count\n");
    int c[MAX_VALUE + 1] = {0};
    count_sort_calculate_counts(input_array,len,c);

    printf("Write\n");
    count_sort_write_output_array(output_array,c,order);

}

int main(int argc, char *argv[]) {
    if (argc < 3){
        printf("Aufruf: %s <Dateiname> asc|desc\n", argv[0]);
        printf("Beispiel: %s zahlen.txt asc\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    /*
     * Hier die Sortierrichtung einlesen und einer Variablen
     * des Datentypes SortDirection (siehe h-Datei) verwenden.
     * Beenden des Programmes mit derselben Ausgabe der Hilfe (siehe Anfang main-Funktion).
     * implementieren Sie zur Umwandlung die Funktion extract_order_direction
     */
    
    SortDirection direction;

    

    if (argc >= 2)
    {
        direction = extract_order_direction(argv[2]);
    }
    else
    {
        direction = NOTDEFINED;
    }
    
    

    int input_array[MAX_LAENGE];
    int output_array[MAX_LAENGE];
    int len = read_array_from_file(input_array, MAX_LAENGE, filename);

    printf("Unsortiertes Array:");
    print_array(input_array, len);

    /*
     * Hier count_sort aufrufen und alle nötigen Deklarationen einfügen!
     */

    count_sort(input_array,len,output_array,direction);

    printf("Sortiertes Array:");

    /* Folgende Zeile einkommentieren, um das Array auszugeben! */
    print_array(output_array, len);

    return 0;
}
