/** 
 * @file queue.hpp
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>
#include <stdexcept>
#include <ostream>

using namespace std;

/**
 * @brief Classe Queue che implementa una coda FIFO (First In First Out).
 * @tparam T Tipo degli elementi contenuti nella coda.
 */
template <typename T>
class Queue{

  private:

        /**
         * @brief Struct interna Node rappresenta un nodo della coda.
         * head - Puntatore al primo elemento della coda
         * tail - Puntatore all'ultimo elemento della coda
         * sizeQueue - Numero di elementi nella coda
         */
        struct Node{
            T value;
            Node *next;

            /**
             * @brief Costruttore che inizializza un nodo con un valore.
             * @param v Valore da inserire nel nodo
             */
            Node(const T& v) : value(v), next(nullptr) {}
        };

        Node *head;
        Node *tail;
        size_t sizeQueue;

  public:

        /**
         * @brief Costruttore default.
         */
        Queue() : head(nullptr), tail(nullptr), sizeQueue(0) {}

        /**
         * @brief Costruttore di copia.
         * @param other Coda da copiare
         */
        Queue(const Queue<T> &other) : head(nullptr), tail(nullptr), sizeQueue(0) {
            Node* node = other.head;
            while (node != nullptr) {
                push(node->value);
                node = node->next;
            }
        }

        /**
         * @brief Operatore di assegnamento.
         * @param other Coda da assegnare
         * @return Riferimento alla coda modificata
         */
        Queue& operator=(const Queue<T> &other){
            if(this != &other){
                clear();
                Node* node = other.head;
                while (node != nullptr) {
                    push(node->value);
                    node = node->next;
                }
            }
            return *this;
        }

        /**
         * @brief Distruttore.
         */
        ~Queue(){
            clear();
            assert(size() == 0);
        }

        /**
         * @brief Classe const_iterator in sola lettura sulla coda.
         * node - Nodo corrente dell'iteratore
         */
        class const_iterator {
            private:
                friend class Queue;
                Node* node;

            public:
                typedef std::forward_iterator_tag iterator_category;
                typedef T                         value_type;
                typedef ptrdiff_t                 difference_type;
                typedef const T*                  pointer;
                typedef const T&                  reference;

                /**
                 * @brief Costruttore da nodo.
                 * @param n Nodo iniziale
                 */
                const_iterator(Node* n) : node(n) {}

                /**
                 * @brief Costruttore di copia.
                 */
                const_iterator(const const_iterator &other) : node(other.node) {}

                /**
                 * @brief Operatore di assegnamento.
                 */
                const_iterator& operator=(const const_iterator &other) {
                    if (this != &other) {
                        node = other.node;
                    }
                    return *this;
                }

                /**
                 * @brief Distruttore.
                 */
                ~const_iterator() {
                    node = nullptr;
                }

                /**
                 * @brief Operatore di dereferenziamento.
                 * @return Riferimento al valore del nodo
                 */
                reference operator*() const {
                    return node->value;
                }

                /**
                 * @brief Operatore freccia.
                 * @return Puntatore al valore del nodo
                 */
                pointer operator->() const {
                    return &(node->value);
                }

                /**
                 * @brief Operatore di post-incremento.
                 */
                const_iterator operator++(int) {
                    const_iterator it(*this);
                    ++*this;
                    return it;
                }

                /**
                 * @brief Operatore di pre-incremento.
                 */
                const_iterator& operator++() {
                    if (node != nullptr) {
                        node = node->next;
                    }
                    return *this;
                }

                /**
                 * @brief Operatore di uguaglianza.
                 */
                bool operator==(const const_iterator &other) const {
                    return node == other.node;
                }

                /**
                 * @brief Operatore di disuguaglianza.
                 */
                bool operator!=(const const_iterator &other) const {
                    return node != other.node;
                }
        };

        /**
         * @brief Restituisce un iteratore all'inizio della coda.
         */
        const_iterator begin() const {
            return const_iterator(head);
        }

        /**
         * @brief Restituisce un iteratore alla fine della coda.
         */
        const_iterator end() const {
            return const_iterator(nullptr);
        }

        /**
         * @brief Inserisce un elemento in coda.
         * @param value Valore da inserire
         */
        void push(const T& value){
            Node *newNode = new Node(value);
            if (isEmpty()){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            sizeQueue++;
        }

        /**
         * @brief Inserisce piu' elementi nella coda con override.
         * @param first Iteratore di inizio
         * @param second Iteratore di fine
         */
        void push(const_iterator first, const_iterator second){
            while(first != second){
                push(*first);
                ++first;
            }
        }

        /**
         * @brief Rimuove l'elemento in testa alla coda.
         */
        void pop(){
            if (isEmpty()){
                throw out_of_range("La coda e' vuota");
            }

            if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            sizeQueue--;
        }

        /**
         * @brief Restituisce il numero di elementi nella coda.
         */
        size_t size() const {
            return sizeQueue;
        }

        /**
         * @brief Accesso in scrittura e lettura al primo elemento.
         */
        T& front() {
            if (isEmpty()){
                throw out_of_range("La coda e' vuota");
            }
            return head->value;
        }

        /**
         * @brief Accesso in solo lettura al primo elemento.
         */
        const T& front() const {
            if (isEmpty()){
                throw out_of_range("La coda e' vuota");
            }
            return head->value;
        }

        /**
         * @brief Accesso in scrittura e lettura all'ultimo elemento.
         */
        T& back() {
            if (isEmpty()){
                throw out_of_range("La coda e' vuota");
            }
            return tail->value;
        }

        /**
         * @brief Accesso in sola lettura all'ultimo elemento.
         */
        const T& back() const {
            if (isEmpty()){
                throw out_of_range("La coda e' vuota");
            }
            return tail->value;
        }

        /**
         * @brief Operatore di output per stampare la coda.
         * @param os Stream di output
         * @param q Coda da stampare
         */
        friend ostream& operator<<(ostream& os, const Queue<T>& q) {
            if (q.isEmpty()){
                os << "La coda e' vuota" << endl;
            } else {
                for(const_iterator it = q.begin(); it != q.end(); ++it){
                    os << *it << " ";
                }
                os << endl;
            }
            return os;
        }

        /**
         * @brief Controlla se un valore e' presente nella coda.
         * @param value Valore da cercare
         */
        bool contains(const T& value) const {
            for(const_iterator it = begin(); it != end(); ++it){
                if(value == *it){
                    return true;
                }
            }
            return false;
        }

        /**
         * @brief Controlla se la coda e' vuota.
         */
        bool isEmpty() const {
            return head == nullptr;
        }

        /**
         * @brief Rimuove tutti gli elementi dalla coda.
         */
        void clear(){
            while(!isEmpty()){
                pop();
            }
        }
};

/**
 * @brief Transforma attraverso un funtore F tutti gli elementi che soddisfano un predicato P.
 * @tparam Q Tipo della coda
 * @tparam P Tipo del predicato
 * @tparam F Tipo del funtore
 * @param q Coda da modificare
 * @param pred Predicato booleano
 * @param fun Funtore di trasformazione
 */
template <typename Q, typename P, typename F>
void transformif(Queue<Q>& q, P pred, F fun) {
    Queue<Q> temp;
    for (typename Queue<Q>::const_iterator it = q.begin(); it != q.end(); ++it) {
        if (pred(*it)) {
            temp.push(fun(*it));
        } else {
            temp.push(*it);
        }
    }
    q = temp;
}

#endif