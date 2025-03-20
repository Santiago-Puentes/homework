#include "ej3.hpp"
#include <iostream>
#include <memory>

struct node_t {
    int value; 
    std::shared_ptr<node_t> next;
};

struct list_t {
    std::shared_ptr<node_t> head;
    int size = 0;
};

std::shared_ptr<node_t> create_node(int value = 0) { 
    return std::make_shared<node_t>(node_t{value, nullptr});
}

void push_front(list_t* list, std::shared_ptr<node_t> node) {
    if (!node) return;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void push_back(list_t* list, std::shared_ptr<node_t> node) {
    if (!node) return;
    if (!list->head) {
        list->head = node;
    } else {
        auto current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }
    list->size++;
}

void insert(list_t* list, std::shared_ptr<node_t> node, int n) {
    if (!node) return;
    if (n > list->size) {
        std::cout << "Posición mayor al tamaño de la lista. Insertando al final.\n";
        push_back(list, node);
        return;
    }
    if (n == 0) {
        push_front(list, node);
        return;
    }
    auto current = list->head;
    for (int i = 1; i < n; ++i) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    list->size++;
}

void erase(list_t* list, int n) {
    if (!list->head) return;
    if (n >= list->size) {
        std::cout << "Posición mayor al tamaño de la lista. Borrando el último nodo.\n";
        n = list->size - 1;
    }
    if (n == 0) {
        list->head = list->head->next;
    } else {
        auto current = list->head;
        for (int i = 1; i < n; ++i) {
            current = current->next;
        }
        current->next = current->next->next;
    }
    list->size--;
}

void print_list(const list_t* list) {
    auto current = list->head;
    while (current) {
        std::cout << current->value << " -> "; 
        current = current->next;
    }
    std::cout << "nullptr\n";
}

int main() {
    list_t my_list;

    auto node1 = create_node(1);
    auto node2 = create_node(2);
    auto node3 = create_node(3);

    push_front(&my_list, node1);
    push_back(&my_list, node2);
    insert(&my_list, node3, 1);

    std::cout << "Lista después de inserciones:\n";
    print_list(&my_list);

    erase(&my_list, 1);
    std::cout << "Lista después de borrar el nodo en posición 1:\n";
    print_list(&my_list);

    return 0;
}