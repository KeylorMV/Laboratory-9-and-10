#pragma once
#include <cstddef>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    explicit Node(const T& value)
        : data(value), next(nullptr) {}
};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    std::size_t count;

public:
    List() : head(nullptr), tail(nullptr), count(0) {}

    // Evita copiar accidentalmente los mismos nodos.
    List(const List&) = delete;
    List& operator=(const List&) = delete;

    ~List() {
        clear();
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    std::size_t size() const {
        return count;
    }

    void insertFirst(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }

        ++count;
    }

    void insertLast(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            head = newNode;
        }
        else {
            tail->next = newNode;
        }

        tail = newNode;
        ++count;
    }

    // Ejecuta una acción para cada dato de la lista.
    template <typename Action>
    void traverse(Action action) const {
        const Node<T>* current = head;

        while (current != nullptr) {
            action(current->data);
            current = current->next;
        }
    }

    // Elimina la primera coincidencia. :)
    bool remove(const T& value) {
        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current != nullptr) {
            if (current->data == value) {
                if (previous == nullptr) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }

                if (current == tail) {
                    tail = previous;
                }

                delete current;
                --count;
                return true;
            }

            previous = current;
            current = current->next;
        }

        return false;
    }

    void clear() {
        while (head != nullptr) {
            Node<T>* temporary = head;
            head = head->next;
            delete temporary;
        }

        tail = nullptr;
        count = 0;
    }
};
