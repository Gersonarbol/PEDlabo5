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
 if (raiz == NULL) {
        cout << "Estudiante no encontrado." << endl;
        return;
    }
    if (raiz->carnet == carnet) {
        cout << "Encontrado -> Nombre: " << raiz->nombre << " | Nota: " << raiz->nota << endl;
    } else if (carnet < raiz->carnet) {
        buscarEstudiante(raiz->izquierdo, carnet);
    } else {
        buscarEstudiante(raiz->derecho, carnet);
    }
}

// 4. Mostrar estudiantes aprobados (nota >= 6.0)
void mostrarAprobados(Estudiante* raiz) {
 // Tu código aquí
     if (raiz != NULL) {
        mostrarAprobados(raiz->izquierdo);
        if (raiz->nota >= 6.0) {
            cout << raiz->nombre << " (" << raiz->nota << ")" << endl;
        }
        mostrarAprobados(raiz->derecho);
    }
}
// 5. Mostrar estudiantes reprobados (nota < 6.0)
void mostrarReprobados(Estudiante* raiz) {
 // Tu código aquí
    if (raiz != NULL) {
        mostrarReprobados(raiz->izquierdo);
        if (raiz->nota < 6.0) {
            cout << raiz->nombre << " (" << raiz->nota << ")" << endl;
        }
        mostrarReprobados(raiz->derecho);
    }
}
// 6. Calcular el promedio de todas las notas
float sumarNotas(Estudiante* raiz, int* contador) {
// Tu código aquí
    if (raiz == NULL) return 0;
    (*contador)++;
    return raiz->nota + sumarNotas(raiz->izquierdo, contador) + sumarNotas(raiz->derecho, contador);
}

// Función principal para llamar desde el main
void mostrarPromedioGeneral(Estudiante* raiz) {
    int contador = 0;
    float suma = sumarNotas(raiz, &contador);
    if (contador == 0) cout << "No hay estudiantes." << endl;
    else cout << "Promedio general: " << (suma / contador) << endl;
}

// 7. Encontrar al estudiante con la nota más alta
Estudiante* encontrarMejorNota(Estudiante* raiz) {
 // Tu código aquí
 if (raiz == NULL) return NULL;
    
    Estudiante* mejor = raiz;
    Estudiante* izq = encontrarMejorNota(raiz->izquierdo);
    Estudiante* der = encontrarMejorNota(raiz->derecho);
    
    if (izq != NULL && izq->nota > mejor->nota) mejor = izq;
    if (der != NULL && der->nota > mejor->nota) mejor = der;
    
    return mejor;
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

 switch (opcion) {
    case 1: {
        int carnet;
        char nombre[50];
        float nota;
        cout << "Ingrese carnet: ";
        cin >> carnet;
        cout << "Ingrese nombre: ";
        cin.ignore(); // Limpia el buffer para poder usar getline
        cin.getline(nombre, 50);
        cout << "Ingrese nota: ";
        cin >> nota;
        sistema = insertar(sistema, carnet, nombre, nota); 
        break;
    }
    case 2:
        cout << "\n--- Lista de Estudiantes (Orden por Carnet) ---\n";
        mostrarEstudiantes(sistema); 
        break;
    case 3: {
        int carnetBusqueda;
        cout << "Ingrese el carnet a buscar: ";
        cin >> carnetBusqueda;
        buscarEstudiante(sistema, carnetBusqueda);
        break;
    }
    case 4:
        cout << "\n--- Estudiantes Aprobados ---\n";
        mostrarAprobados(sistema); 
        break;
    case 5:
        cout << "\n--- Estudiantes Reprobados ---\n";
        mostrarReprobados(sistema); 
        break;
    case 6:
        mostrarPromedioGeneral(sistema); 
        break;
    case 7: {
        Estudiante* mejor = encontrarMejorNota(sistema); 
        if (mejor != NULL) {
            cout << "El mejor estudiante es: " << mejor->nombre << " con nota de: " << mejor->nota << endl;
        } else {
            cout << "No hay estudiantes registrados." << endl;
        }
        break;
    }
    case 8:
        cout << "Saliendo del sistema..." << endl;
        break;
    default:
        cout << "Opcion no valida. Intente de nuevo." << endl;
 }
}while(opcion != 8);

return 0;
}