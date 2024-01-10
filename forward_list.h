#ifndef TAREA1_LISTAS_FORWARD_LIST_H
#define TAREA1_LISTAS_FORWARD_LIST_H

template<typename T>
class Forward_List{
    private:
        struct Nodo{
            T data;
            Nodo* next;
        };

        Nodo* head;
        int nodos;

    public:
        Forward_List(): head(nullptr), nodos(0);

        T front();
        T back();
        void push_front(T _data);
        void push_back(T _data);
        T pop_front();
        T pop_back();
        T operator[](int index);
        bool empty();
        int size();
        void clear();
        void sort();
        void reverse();

        ~Forward_List(){
            clear();
        };
};

#endif //TAREA1_LISTAS_FORWARD_LIST_H