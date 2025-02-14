# Get-next-line
Project that opens a fd and reads one line in different ways. 42 common core project.

Compilation:
```cc -c -g get_next_line.c get_next_line_utils.c get_next_line.h```

Test compilation:
```cc -g ../get_next_line.o ../get_next_line_utils.o test.c test.h```

I will do a Makefile in tester, but the original subject dont requires it. 


Este proyecto implementa la función `get_next_line`, que permite leer una línea de un descriptor de archivo de manera eficiente, incluyendo soporte para múltiples descriptores de archivo (bonus).

## Características

- Lee una línea completa de un archivo o entrada estándar.
- Maneja correctamente archivos grandes y lectura en múltiples llamadas.
- Soporte para múltiples descriptores de archivo simultáneamente (bonus).
- Implementado sin el uso de `malloc` dentro de un bucle infinito.

## Uso

1. Clona este repositorio en tu máquina local:
   ```sh
   git clone https://github.com/tuusuario/get_next_line.git
   cd get_next_line
   ```
2. Compila los archivos:
   ```sh
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -c get_next_line.c get_next_line_utils.c
   ```
3. Incluye `get_next_line.a` en tu proyecto y compila con:
   ```sh
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 tu_archivo.c get_next_line.a -o tu_programa
   ```

## Ejemplo

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("archivo.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
