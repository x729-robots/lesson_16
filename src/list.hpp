#pragma once
// #include "container.hpp"
#include <cstddef>
// #include <list>

namespace otus {
    template <typename T> class List {
      public:
        List() : m_size(0) {
            // setCurrent(static_cast<Node>(NULL));
            Node endNode = new Node(); //выделили память под ноду конца листа
            endNode.naigbor1 = &endNode; //начало пустого листа ссылается сам на себя
            endNode.naigbor2 = &endNode; //конец пустого листа ссылается сам на себя
            m_end = &endNode;
            m_front = NULL; 
            m_back = NULL;
        }

        ~List() {
            delete m_end.currentNode;
        };

        struct Node {
            Node() {};
            explicit Node(T value, Node* naigbor1, Node* naigbor2)
                : Node{}, nodeData{value},naigbor1{naigbor1}, naigbor2{naigbor2} {}
            Node* naigbor1;
            Node* naigbor2;
            T nodeData;
        };

        void push_back(T value) {
            Node node = new Node(value);
            if (m_back == NULL) {

            } else {
            }
        };

        void insert() {};     // todo
        void erase() {};      // todo
        void size() const {}; // todo

        List& operator=(const List& container) { // todo
            return *container;
        };
        List& operator=(List&& container) { // todo
            return *container;
        };

        T& operator[](const long int pos) { // todo
            return 0;
        };

        T& front() { // todo
            return 0;
        }

        const T& front() const { // todo
            return 0;
        }

        T& back() { // todo
            return 0;
        }

        const T& back() const { // todo
            return 0;
        }

        void reserve(const long int new_cap) {}; // todo
        class Iterator {
          public:
            Iterator operator++() { // todo
                Iterator it;
                return it;
            };
            Iterator operator--() { // todo
                Iterator it;
                return it;
            };

            Iterator get() { // todo
                Iterator it;
                return it;
            };
            Iterator operator*() { // todo
                return get();
            };
/*            void setCurrent(Node* node) { // todo
                currentNode = node;
            };*/

          //private:
            Node* currentNode;
        };
        Iterator begin() {
            return m_front; // todo
        };
        Iterator end() {
            return NULL; // todo
        };

        // typedef SNode Node;
      private:
        long int m_size;
        Node* m_front; //указывает на первую ноду с данными
        Node* m_back; //указывает на последнюю ноду с данными
        Node* m_end; //указывает на ноду конца листа, который есть даже у пустого листа
    };
} // namespace otus

/*namespace otus {

    template<typename T>
    struct List {
        List() = default;
        ~List() = default;

        void push_back(const T& value) {
            m_impl.push_back(value);
        }

        void push_front(const T& value) {
            m_impl.push_front(value);
            //m_impl.pop_front();
        }

        void pop_back() {
            m_impl.pop_back();
        }

        void pop_front() {
            m_impl.pop_front();
        }

        std::size_t size() const noexcept {
            return m_impl.size();
        }

        bool empty() const noexcept {
            return m_impl.empty();
        }

        void clear()
        {
            m_impl.clear();
        }

        T& front() {
            return m_impl.front();
        }

        const T& front() const {
            return m_impl.front();
        }

        T& back() {
            return m_impl.back();
        }

        const T& back() const {
            return m_impl.back();
        }

    private:
        std::list<T> m_impl;
    };

}*/
