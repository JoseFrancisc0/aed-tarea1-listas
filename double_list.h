#ifndef TAREA1_LISTAS_DOUBLY_LINKED_LIST_H
#define TAREA1_LISTAS_DOUBLY_LINKED_LIST_H

template<typename T>
class Doubly_Linked_List{
    private:
        struct Nodo{
            T data;
            Nodo* prev;
            Nodo* next;
        };

        Nodo* head;
        Nodo* tail;
        int nodos;

    public:
        Doubly_Linked_List(): head(nullptr), tail(nullptr), nodos(0){};

        T front(){
            if(!head)
                throw std::out_of_range("Lista vacia");
            
            return head->data;
        }

        T back(){
            if(!head)
                throw std::out_of_range("Lista vacia");
            
            return tail->data;
        }

        void push_front(T _data){
            Nodo* temp = new Nodo;
            temp->data = _data;
            temp->next = head;

            if(head){
                head->prev = temp;
                head = temp;
            }
            else
                head = tail = temp;
            
            nodos++;
        }

        void push_back(T _data){
            Nodo* temp = new Nodo;
            temp->data = _data;
            temp->next = nullptr;

            if(tail){
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
            else
                tail = head = temp;
            
            nodos++;
        }

        T pop_front();
        T pop_back();
        void insert(T _data, int index);
        void erase(T _data);
        T operator[](int index);
        bool empty();
        int size();
        void clear();
        void reverse();

        ~Doubly_Linked_List(){
            clear();
        }
};

#endif //TAREA1_LISTAS_DOUBLY_LINKED_LIST_H