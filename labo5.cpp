#include <iostream>
using namespace std;
struct Estudiante {
 int carnet;
 char nombre[50];
 float nota;
 Estudiante* izquierdo;
 Estudiante* derecho;
};
// Función para crear un nuevo estudiante
Estudiante* crearEstudiante(int carnet, char nom[], float nota) {
 Estudiante* nuevo = new Estudiante();
 nuevo->carnet = carnet;
 nuevo->nota = nota;
 nuevo->izquierdo = NULL;
 nuevo->derecho = NULL;

 // Copiar el nombre
 int i = 0;
 while(nom[i] != '\0' && i < 49) {
 nuevo->nombre[i] = nom[i];
 i++;
 }
 nuevo->nombre[i] = '\0';

 return nuevo;
}
// TODO: Implementar estas funciones
// 1. Insertar un estudiante en el árbol (ordenado por carnet)
Estudiante* insertar(Estudiante* raiz, int carnet, char nombre[], float nota) {
 // Tu código aquí
    if (raiz == NULL) {
        return crearEstudiante(carnet, nombre, nota);
    }
    if (carnet < raiz->carnet) {
        raiz->izquierdo = insertar(raiz->izquierdo, carnet, nombre, nota);
    } else if (carnet > raiz->carnet) {
        raiz->derecho = insertar(raiz->derecho, carnet, nombre, nota);
    }
    return raiz;
}
// 2. Mostrar todos los estudiantes en orden de carnet
void mostrarEstudiantes(Estudiante* raiz) {
 // Tu código aquí
    if  (raiz != NULL) {
        mostrarEstudiantes(raiz->izquierdo);
        cout << "Carnet: " << raiz->carnet << " | Nombre: " << raiz->nombre << " | Nota: " << raiz->nota << endl;
        mostrarEstudiantes(raiz->derecho);
    }
}

// 3. Buscar un estudiante por carnet y mostrar sus datos
void buscarEstudiante(Estudiante* raiz, int carnet) {
 // Tu código aquí
}
// 4. Mostrar estudiantes aprobados (nota >= 6.0)
void mostrarAprobados(Estudiante* raiz) {
 // Tu código aquí
}
// 5. Mostrar estudiantes reprobados (nota < 6.0)
void mostrarReprobados(Estudiante* raiz) {
 // Tu código aquí
}
// 6. Calcular el promedio de todas las notas
float calcularPromedio(Estudiante* raiz, int* contador) {
 // Tu código aquí
 // Usa el contador para saber cuántos estudiantes hay
}
// 7. Encontrar al estudiante con la nota más alta
Estudiante* encontrarMejorNota(Estudiante* raiz) {
 // Tu código aquí
}
int main() {
 Estudiante* sistema = NULL;
 int opcion;

 do {
 cout << "\n===== SISTEMA DE GESTION DE ESTUDIANTES=====\n";
 cout << "1. Agregar estudiante\n";
 cout << "2. Mostrar todos los estudiantes\n";
 cout << "3. Buscar estudiante por carnet\n";
 cout << "4. Mostrar estudiantes aprobados\n";
 cout << "5. Mostrar estudiantes reprobados\n";
 cout << "6. Calcular promedio general\n";
 cout << "7. Mostrar estudiante con mejor nota\n";
 cout << "8. Salir\n";
 cout << "Opcion: ";
 cin >> opcion;

 // Implementa el switch con las opciones

 } while(opcion != 8);

 return 0;
}