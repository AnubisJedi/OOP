#ifndef LIST_HPP
#define LIST_HPP

#include <memory_resource>
#include <iterator>
#include <new>
#include <cstddef>
#include <utility>
#include <iostream>

template <typename T>
class PmrList {
private:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node() : prev(nullptr), next(nullptr) {}
    };

    std::pmr::polymorphic_allocator<Node> alloc;
    Node* head;
    Node* tail;
    std::size_t sz;

public:
    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

    private:
        Node* current;

    public:
        iterator(Node* ptr) : current(ptr) {}

        reference operator*() const {
            return current->value;
        }

        pointer operator->() const {
            return &(current->value);
        }

        iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const iterator& a, const iterator& b) {
            return a.current == b.current;
        }

        friend bool operator!=(const iterator& a, const iterator& b) {
            return a.current != b.current;
        }
    };

    PmrList(std::pmr::memory_resource* mr = std::pmr::get_default_resource())
        : alloc(mr), head(nullptr), tail(nullptr), sz(0) {}

    ~PmrList() {
        clear();
    }

    void clear() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->value.~T();
            alloc.deallocate(curr, 1);
            curr = next;
        }
        head = tail = nullptr;
        sz = 0;
    }

    void push_back(const T& value) {
        Node* node = alloc.allocate(1);
        ::new (static_cast<void*>(&node->value)) T(value);
        node->prev = tail;
        node->next = nullptr;
        if (!head) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
        ++sz;
    }

    void push_back(T&& value) {
        Node* node = alloc.allocate(1);
        ::new (static_cast<void*>(&node->value)) T(std::move(value));
        node->prev = tail;
        node->next = nullptr;
        if (!head) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
        ++sz;
    }

    std::size_t size() const {
        return sz;
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    void pop_back() {
        if (!tail) return;
        Node* to_delete = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        to_delete->value.~T();
        alloc.deallocate(to_delete, 1);
        --sz;
    }
};

#endif // LIST_HPP