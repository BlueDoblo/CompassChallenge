#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definición de la estructura Contact para almacenar la información de los contactos
typedef struct {
    int id;
    char firstName[50];
    char lastName[50];
    char emailAddress[100];
    char zipCode[20];
    char address[100];
} Contact;

// Función para comparar dos cadenas sin diferenciar entre mayúsculas y minúsculas
int compareIgnoreCase(const char* str1, const char* str2) {
    
    // Mientras tenga caracteres en cada cadena sigo recorriendola para ir comparando
    while (*str1 && *str2) {
        
        // Comparo los caracteres 
        if (tolower(*str1) != tolower(*str2)) {
            return 0;
        }
        // Muevo los punteros al proximo carater
        str1++;
        str2++;
    }
    // Retorno la comparacion entre ambos punteros, si son identicos y se alcanzo el final de cada cadena
    // retornare 1 lo cual indica que ambas cadenas son identicas.
    // Si alguna cadena es mas corta que otra esta comparacion retornara 0 indicando que son distintas
    // Si algun caracter entre cadenas difiere se cortara el bucle luego de la 
    // comparacion y se retorna 0 en la linea 24.
    return *str1 == *str2;
}

// Función para comparar dos contactos y asignarles un score
char* compareContacts(const Contact* c1, const Contact* c2) {
    int score = 0;

    // Comparar las direcciones de correo electrónico, le asigno una ponderacion de 60 sobre 100 al email
    if (compareIgnoreCase(c1->emailAddress, c2->emailAddress)) {
        score += 60;
    }
    // Comparar los nombres, le asigno una ponderacion de 15 al nombre
    if (compareIgnoreCase(c1->firstName, c2->firstName)) {
        score += 15;
    }
    // Comparar los apellidos,le asigno una ponderacion de 15 al apellido
    if (compareIgnoreCase(c1->lastName, c2->lastName)) {
        score += 15;
    }
    // Comparar los códigos postales, le asigno una ponderacion de 5 al cp
    if (strcmp(c1->zipCode, c2->zipCode) == 0) {
        score += 5;
    }
    // Comparar las direcciones, le asigno una ponderacion de 5 a la direccion
    if (compareIgnoreCase(c1->address, c2->address)) {
        score += 5;
    }

    // En base al score resultante clasifico el grado de posible duplicidad entre contactos
    // y genero la salida donde imprimo los id de los contactos comparados y su grado 
    // de coincidencia

    char* result = (char*)malloc(100 * sizeof(char));
    if (score >= 80) {
        snprintf(result, 100, "%d - %d - High", c1->id, c2->id);
    } else if (score >= 50) {
        snprintf(result, 100, "%d - %d - Medium", c1->id, c2->id);
    } else if (score > 0) {
        snprintf(result, 100, "%d - %d - Low", c1->id, c2->id);
    } else if (score == 0){
        snprintf(result, 100, "%d - %d - There are no coincidences", c1->id, c2->id);
    } else {
        result[0] = '\0';
    }

    return result;
}

// Función para encontrar duplicados entre los contactos, se compara 
// cada contacto contra los demas
void findDuplicates(const Contact* contacts, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) { // Para NO comparar un contacto consigo mismo
                char* matchResult = compareContacts(&contacts[i], &contacts[j]);
                if (matchResult[0] != '\0') {
                    printf("%s\n", matchResult);
                }
                free(matchResult);
            }
        }
    }
}

// Función para leer contactos desde un archivo
int readContactsFromFile(const char* filename, Contact** contacts) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    char line[300];
    
    // Contar el número de líneas en el archivo para determinar el tamaño de la matriz
    while (fgets(line, sizeof(line), file)) {
        count++;
    }
    rewind(file);

    // Reservar memoria para los contactos
    *contacts = (Contact*)malloc(count * sizeof(Contact));
    int i = 0;

    // Leer los contactos desde el archivo y almacenarlos en la estructura
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d;%49[^;];%49[^;];%99[^;];%19[^;];%99[^\n]",
               &((*contacts)[i].id),
               (*contacts)[i].firstName,
               (*contacts)[i].lastName,
               (*contacts)[i].emailAddress,
               (*contacts)[i].zipCode,
               (*contacts)[i].address);
        i++;
    }

    fclose(file);
    return i;
}

int main() {
    // Defino la estructura que se cargará con los contactos leídos
    Contact* contacts;
    int size = readContactsFromFile("contacts.txt", &contacts);
    if (size > 0) {
        printf("--------------------------------\n");
        printf("- Resultado de la Comparacion  -\n");
        printf("--------------------------------\n");
        findDuplicates(contacts, size);
        printf("--------------------------------\n");

        free(contacts);
    }
    return 0;
}
