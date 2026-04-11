#include <stdio.h>

struct pelicula {
    char *nombre;
    char *genero;
    short anio;
    short numDirectores;
    char *directores[10];
};

void imprimirDatosPelicula(struct pelicula);
struct pelicula llenarDatosPelicula(char *, char *, short, short, char*[10]);

struct pelicula llenarDatosPelicula(char *nombre, char *genero, short anio, short numDirectores, char *directores[10]) {
    struct pelicula movie;
    movie.nombre = nombre;
    movie.genero = genero;
    movie.anio = anio;
    movie.numDirectores = numDirectores;
    int cont = 0;
    for (;cont < movie.numDirectores; cont++) {
        movie.directores[cont] = directores[cont];
    }

    return movie;
}

void imprimirDatosPelicula(struct pelicula movie) {
    printf("Película: %s\n", movie.nombre);
    printf("Género: %s\n", movie.genero);
    printf("Año: %d\n", movie.anio);
    printf("Director (es): \n");
    int cont = 0;
    for (;cont < movie.numDirectores; cont++) {
        printf("%s\n", movie.directores[cont]);
    }
}

int main() {
    char *directores[10];
    directores[0] = "Ethan Coen";
    directores[1] = "Joel Coen";
    struct pelicula sinlugar = llenarDatosPelicula("Sin Lugar Para Los Débiles", "Thriller", 2007, 2, directores);
    imprimirDatosPelicula(sinlugar);
    return 0;
}