#include <iostream>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};


bool has_cycle(SinglyLinkedListNode* head) {
    // 1. Caso base: Si la lista está vacía o solo tiene un nodo sin conexión, no hay ciclo.
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    // 2. Inicializamos los punteros (los "corredores").
    SinglyLinkedListNode* slow = head; // (avanza 1 paso)
    SinglyLinkedListNode* fast = head; // (avanza 2 pasos)

    // 3. Recorremos la lista mientras el corredor rápido pueda seguir avanzando.
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Avanza 1 nodo
        fast = fast->next->next;    // Avanza 2 nodos

        // 4. Si en algún momento se encuentran en el mismo nodo, ¡hay un ciclo!
        if (slow == fast) {
            return true;
        }
    }

    // 5. Si el ciclo while termina, significa que 'fast' llegó al final (nullptr).
    return false;
}

// Pruebas Locales.
int main() {
// -----------------------------------------------------------------
    // CASO 1: 
    // -----------------------------------------------------------------
    SinglyLinkedList* llist = new SinglyLinkedList();
    llist->insert_node(1);
    llist->insert_node(2);
    llist->insert_node(3);

    cout << "========================================================\n";
    cout << "PRUEBA 1: Evaluando estructura lineal\n";
    cout << "Nodos: [1] -> [2] -> [3] -> NULL\n";
    cout << "--------------------------------------------------------\n";
    if (has_cycle(llist->head)) {
        cout << "RESULTADO: >> Se detecto un ciclo  <<\n";
    } else {
        cout << "RESULTADO: >> No hay ciclo<<\n";
    }
    cout << "========================================================\n\n";

    // -----------------------------------------------------------------
    // CASO 2: 
    // -----------------------------------------------------------------
    // Forzamos que el nodo 3 apunte directamente al nodo 1
    llist->tail->next = llist->head;

    cout << "========================================================\n";
    cout << "PRUEBA 2: Evaluando estructura circular\n";
    cout << "Nodos: [1] -> [2] -> [3] -> (apunta de nuevo a [1])\n";
    cout << "--------------------------------------------------------\n";
    if (has_cycle(llist->head)) {
        cout << "RESULTADO: >> Se detecto un ciclo <<\n";
    } else {
        cout << "RESULTADO: >> No hay ciclo <<\n";
    }
    cout << "========================================================\n";

    return 0;
}
