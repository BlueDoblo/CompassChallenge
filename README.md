## Descripción
Este programa en C encuentra posibles duplicados en una lista de contactos basándose en varios criterios como nombre, apellido, dirección de correo electrónico, código postal y dirección física. Utiliza comparaciones sin distinción entre mayúsculas y minúsculas para mejorar la precisión.

## Funciones Principales

### compareIgnoreCase
Esta función compara dos cadenas de caracteres sin diferenciar entre mayúsculas y minúsculas. Retorna 1 si las cadenas son idénticas, de lo contrario retorna 0.

### compareContacts
Compara dos estructuras de contacto (Contact) y calcula un puntaje de similitud basado en varios criterios. Retorna un string indicando el grado de coincidencia entre los contactos.

### findDuplicates
Encuentra posibles duplicados entre una lista de contactos comparando cada contacto contra todos los demás. Imprime los resultados de las comparaciones.

### readContactsFromFile
Lee los contactos desde un archivo de texto (filename) y los carga en un array de estructuras Contact. Retorna el número de contactos leídos.

### Uso
Compile el programa usando un compilador de C. 
Asegúrese de tener un archivo contacts.txt en el mismo directorio.
El archivo debe contener los datos de los contactos en el formato especificado. 
Ejecute el programa para encontrar posibles duplicados entre los contactos y vea los resultados en la consola.

El archivo contacts.txt debe contener los datos de los contactos en el siguiente formato:

ContactID;First Name;Last Name;Email Address;Zip Code;

1001;C;F;mollis.lectus.pede@outlook.net;;449-6990 Tellus. Rd.

1002;C;French;mollis.lectus.pede@outlook.net;39746;449-6990 Tellus. Rd.

1003;Ciara;F;non.lacinia.at@zoho.ca;39746;

Para procesar el archivo asegúrese de que no haya líneas de encabezado en el archivo contacts.txt.

Con el archivo de ejemplo que subi y arme obtengo esta salida

![image](https://github.com/BlueDoblo/CompassChallenge/assets/78155440/61ef46f6-aaec-4de5-a8d4-aed5e2495cf8)

