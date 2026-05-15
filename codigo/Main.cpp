#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Estructura de datos del Estudiante
struct Estudiante {
    string cedula;
    string apellidos;
    string nombres;
    double notaFinal;
    string carrera;
    int nivel;
};

// Estructura del Nodo
struct Nodo {
    Estudiante estudiante;
    Nodo* izquierdo;
    Nodo* derecho;
};

class ArbolBST {
private:
    Nodo* raiz;

    // Métodos privados recursivos
    Nodo* insertarRecursivo(Nodo* nodo, Estudiante est) {
        if (nodo == nullptr) {
            Nodo* nuevo = new Nodo();
            nuevo->estudiante = est;
            nuevo->izquierdo = nullptr;
            nuevo->derecho = nullptr;
            return nuevo;
        }
        if (est.cedula < nodo->estudiante.cedula) {
            nodo->izquierdo = insertarRecursivo(nodo->izquierdo, est);
        } else if (est.cedula > nodo->estudiante.cedula) {
            nodo->derecho = insertarRecursivo(nodo->derecho, est);
        }
        return nodo;
    }

    Nodo* buscarRecursivo(Nodo* nodo, string cedula) {
        if (nodo == nullptr || nodo->estudiante.cedula == cedula) return nodo;
        if (cedula < nodo->estudiante.cedula) return buscarRecursivo(nodo->izquierdo, cedula);
        return buscarRecursivo(nodo->derecho, cedula);
    }

    Nodo* encontrarMinimo(Nodo* nodo) {
        Nodo* actual = nodo;
        while (actual && actual->izquierdo != nullptr) actual = actual->izquierdo;
        return actual;
    }

    Nodo* eliminarRecursivo(Nodo* nodo, string cedula) {
        if (nodo == nullptr) return nodo;
        if (cedula < nodo->estudiante.cedula) {
            nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, cedula);
        } else if (cedula > nodo->estudiante.cedula) {
            nodo->derecho = eliminarRecursivo(nodo->derecho, cedula);
        } else {
            // Nodo con un hijo o sin hijos
            if (nodo->izquierdo == nullptr) {
                Nodo* temp = nodo->derecho;
                delete nodo;
                return temp;
            } else if (nodo->derecho == nullptr) {
                Nodo* temp = nodo->izquierdo;
                delete nodo;
                return temp;
            }
            // Nodo con dos hijos
            Nodo* temp = encontrarMinimo(nodo->derecho);
            nodo->estudiante = temp->estudiante;
            nodo->derecho = eliminarRecursivo(nodo->derecho, temp->estudiante.cedula);
        }
        return nodo;
    }

    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            imprimirEstudiante(nodo->estudiante);
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            imprimirEstudiante(nodo->estudiante);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            imprimirEstudiante(nodo->estudiante);
        }
    }

    int contarRecursivo(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + contarRecursivo(nodo->izquierdo) + contarRecursivo(nodo->derecho);
    }

    int alturaRecursiva(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        int altIzq = alturaRecursiva(nodo->izquierdo);
        int altDer = alturaRecursiva(nodo->derecho);
        return max(altIzq, altDer) + 1;
    }

    void buscarNotaMayorRec(Nodo* nodo, Estudiante*& mejor) {
        if (nodo != nullptr) {
            if (mejor == nullptr || nodo->estudiante.notaFinal > mejor->notaFinal) mejor = &nodo->estudiante;
            buscarNotaMayorRec(nodo->izquierdo, mejor);
            buscarNotaMayorRec(nodo->derecho, mejor);
        }
    }

    void buscarNotaMenorRec(Nodo* nodo, Estudiante*& peor) {
        if (nodo != nullptr) {
            if (peor == nullptr || nodo->estudiante.notaFinal < peor->notaFinal) peor = &nodo->estudiante;
            buscarNotaMenorRec(nodo->izquierdo, peor);
            buscarNotaMenorRec(nodo->derecho, peor);
        }
    }

    void mostrarCondicionRec(Nodo* nodo, bool aprobados) {
        if (nodo != nullptr) {
            mostrarCondicionRec(nodo->izquierdo, aprobados);
            if ((aprobados && nodo->estudiante.notaFinal >= 7.0) || (!aprobados && nodo->estudiante.notaFinal < 7.0)) {
                imprimirEstudiante(nodo->estudiante);
            }
            mostrarCondicionRec(nodo->derecho, aprobados);
        }
    }

    void imprimirEstudiante(Estudiante est) {
        cout << "[" << est.cedula << "] " << est.apellidos << " " << est.nombres 
             << " | Nota: " << est.notaFinal << " | " << est.carrera << " Lvl " << est.nivel << endl;
    }

public:
    ArbolBST() { raiz = nullptr; }

    void insertarEstudiante(Estudiante est) { raiz = insertarRecursivo(raiz, est); }
    
    void buscarEstudiante(string cedula) {
        Nodo* res = buscarRecursivo(raiz, cedula);
        if (res) imprimirEstudiante(res->estudiante);
        else cout << "Estudiante no encontrado.\n";
    }

    void eliminarEstudiante(string cedula) { raiz = eliminarRecursivo(raiz, cedula); }
    void recorridoInorden() { inorden(raiz); }
    void recorridoPreorden() { preorden(raiz); }
    void recorridoPostorden() { postorden(raiz); }

    void recorridoPorNiveles() {
        if (raiz == nullptr) return;
        queue<Nodo*> q;
        q.push(raiz);
        while (!q.empty()) {
            Nodo* actual = q.front();
            q.pop();
            imprimirEstudiante(actual->estudiante);
            if (actual->izquierdo != nullptr) q.push(actual->izquierdo);
            if (actual->derecho != nullptr) q.push(actual->derecho);
        }
    }

    void contarNodos() { cout << "Total de estudiantes: " << contarRecursivo(raiz) << endl; }
    void calcularAltura() { cout << "Altura del arbol: " << alturaRecursiva(raiz) << endl; }
    
    void buscarNotaMayor() {
        Estudiante* mejor = nullptr;
        buscarNotaMayorRec(raiz, mejor);
        if (mejor) { cout << "Mayor nota:\n"; imprimirEstudiante(*mejor); }
    }

    void buscarNotaMenor() {
        Estudiante* peor = nullptr;
        buscarNotaMenorRec(raiz, peor);
        if (peor) { cout << "Menor nota:\n"; imprimirEstudiante(*peor); }
    }

    void mostrarAprobados() { mostrarCondicionRec(raiz, true); }
    void mostrarReprobados() { mostrarCondicionRec(raiz, false); }
};

int main() {
    ArbolBST arbol;
    int opcion;
    do {
        cout << "\n--- SISTEMA ACADEMICO UTA ---\n";
        cout << "1. Insertar estudiante\n2. Buscar estudiante por cedula\n3. Eliminar estudiante\n";
        cout << "4. Recorrido Inorden\n5. Recorrido Preorden\n6. Recorrido Postorden\n";
        cout << "7. Recorrido por niveles BFS\n8. Contar estudiantes\n9. Calcular altura del arbol\n";
        cout << "10. Mostrar estudiante con mayor nota\n11. Mostrar estudiante con menor nota\n";
        cout << "12. Mostrar estudiantes aprobados\n13. Mostrar estudiantes reprobados\n14. Salir\nOpcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Estudiante est;
            cout << "Cedula: "; cin >> est.cedula;
            cout << "Apellidos: "; cin.ignore(); getline(cin, est.apellidos);
            cout << "Nombres: "; getline(cin, est.nombres);
            cout << "Nota Final: "; cin >> est.notaFinal;
            cout << "Carrera: "; cin.ignore(); getline(cin, est.carrera);
            cout << "Nivel: "; cin >> est.nivel;
            arbol.insertarEstudiante(est);
        } else if (opcion == 2) {
            string ced; cout << "Cedula: "; cin >> ced; arbol.buscarEstudiante(ced);
        } else if (opcion == 3) {
            string ced; cout << "Cedula a eliminar: "; cin >> ced; arbol.eliminarEstudiante(ced);
        } else if (opcion == 4) arbol.recorridoInorden();
        else if (opcion == 5) arbol.recorridoPreorden();
        else if (opcion == 6) arbol.recorridoPostorden();
        else if (opcion == 7) arbol.recorridoPorNiveles();
        else if (opcion == 8) arbol.contarNodos();
        else if (opcion == 9) arbol.calcularAltura();
        else if (opcion == 10) arbol.buscarNotaMayor();
        else if (opcion == 11) arbol.buscarNotaMenor();
        else if (opcion == 12) arbol.mostrarAprobados();
        else if (opcion == 13) arbol.mostrarReprobados();

    } while (opcion != 14);
    return 0;
}