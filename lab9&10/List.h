#pragma once

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;

public:
    explicit Node(const T& value)
        : data(value), next(nullptr) {}

    T getData() const {
        return data;
    }

    const Node<T>* getNext() const {
        return next;
    }

    template <typename U>
    friend class List;
};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int count;

public:
    List() : head(nullptr), tail(nullptr), count(0) {}

    List(const List&) = delete;
    List& operator=(const List&) = delete;

    ~List() {
        clear();
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int size() const {
        return count;
    }

    const Node<T>* getHead() const {
        return head;
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