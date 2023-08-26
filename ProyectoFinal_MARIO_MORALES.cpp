#include <iostream>
#include <windows.h>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo* next;

    Nodo(int value) : dato(value), next(NULL) {}
};

class LinkedList {
private:
    Nodo* head;
    int count;

public:
    LinkedList() : head(NULL), count(0) {}

    void insert(int dato) {
        Nodo* newNodo = new Nodo(dato);
        if (!head) {
            head = newNodo;
        } else {
            newNodo->next = head;
            head = newNodo;
        }
        count++;
    }

    bool buscar(int dato) {
        Nodo* current = head;
        while (current) {
            if (current->dato == dato) {
            	std::cout << "Dato: " << current->dato << " Direccion: " << current << std::endl;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remover(int dato) {
        if (!head) {
            return;
        }
        if (head->dato == dato) {
            Nodo* temp = head;
            head = head->next;
            delete temp;
            count--;
            return;
        }
        Nodo* current = head;
        while (current->next) {
            if (current->next->dato == dato) {
                Nodo* temp = current->next;
                current->next = current->next->next;
                delete temp;
                count--;
                return;
            }
            current = current->next;
        }
    }

    void printList() {
        Nodo* current = head;
        while (current) {
            std::cout << "Dato: " << current->dato << " Direccion: " << current << std::endl;
            current = current->next;
        }
    }

    void printStatus() {
        std::cout << "\n PRINCIPIO: " << head << std::endl;
        std::cout << "\n DISPONIBLE: " << (30 - count) << " de 30\n" << std::endl;
    }

    ~LinkedList() {
        // Libera la memoria de los datos al destruir la lista
        Nodo* current = head;
        while (current) {
            Nodo* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    LinkedList* currentList = NULL; // Puntero para la lista actual
    
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n\n   \\\\\\\\ Estructura de Datos I /////// \n\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n\n  ******* Litas Enlazadas *******\n\n";
    
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	
    while (true) {
    	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        std::cout << " 1. Crear Lista   \n 2. Insertar  \n 3. Buscar ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << " \n 4. Eliminar  ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		std::cout << "\n 5. Imprimir Lista  \n 6. Imprimir Estado  \n 7. SAlir\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		
        int choice;
        std::cin >> choice;

        if (choice == 7) {
            break;
        }

        if (currentList == NULL && choice != 1) {
            std::cout << "\n Primero Cree una Lista !!! (Opcion 1).\n";
            continue;
        }

        int dato;
        switch (choice) {
            case 1:
                if (currentList != NULL) {
                    delete currentList;
                }
                currentList = new LinkedList(); // Crear nueva lista
                std::cout << "\n Nueva Lista creada.\n";
                break;
            case 2:
                std::cout << "\n Ingresar dato a agregar:  ";
                std::cin >> dato;
                currentList->insert(dato);
                break;
            case 3:
                std::cout << "\n Ingrese el Dato a buscar ";
                std::cin >> dato;
                if (currentList->buscar(dato)) {
                    std::cout << "\nDato encontrad.\n";
                } else {
                    std::cout << "\nDato NO encontrado.\n";
                }
                break;
            case 4:
                std::cout << "\n Inserte el dato a eliminar ";
                std::cin >> dato;
                currentList->remover(dato);
                break;
            case 5:
                currentList->printList();
                break;
            case 6:
                currentList->printStatus();
                break;
            default:
                std::cout << "\n ERROR! Opcion Invalida\n";
        }
    }

    delete currentList; // Liberar la memoria de la lista antes de salir
    return 0;
}

