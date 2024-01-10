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
        Forward_List(): head(nullptr), nodos(0){};

        T front(){
            if(!head)
                throw std::out_of_range("Lista vacia");
            
            return head->data;
        }

        T back(){
            if(!head)
                throw std::out_of_range("Lista vacia");
            
            Nodo* temp = head;
            while(!temp->next)
                temp = temp->next;
            
            return temp->data;
        }

        void push_front(T _data){
            Nodo* nodo = new Nodo;
            nodo->data = _data;

            if(!head)
                nodo->next = nullptr;
            else
                nodo->next = head;

            head = nodo;
            nodos++;
        }

        void push_back(T _data){
            Nodo* nodo = new Nodo;
            nodo->data = _data;

            if(!head){
                nodo->next = nullptr;
                head = nodo;
            }
            else{
                Nodo* temp = head;
                while(temp->next)
                    temp = temp->next;
                temp->next = nodo;
                nodo->next = nullptr;
            }
            
            nodos++;
        }

        T pop_front(){
            if(!head)
                throw std::out_of_range("Lista vacia");
            
            Nodo* temp = head;
            T popped = temp->data;
            head = head->next;
            delete temp;

            nodos--;
            return popped;
        }

        T pop_back(){
            if(!head)
                throw std::out_of_range("Lista vacia");
            
            if(!head->next){
                T popped = head->data;
                delete head;
                head = nullptr;

                nodos = 0;
                return popped;
            }
            else{
                Nodo* temp = head;
                while(temp->next->next)
                    temp = temp->next;
                T popped = temp->next->data;
                delete temp->next;
                temp->next = nullptr;

                nodos--;
                return popped;
            }
        }

        T operator[](int index);
        bool empty();
        int size();
        void clear();
        void sort();
        void reverse();

        ~Forward_List(){
            clear();
        }
};

#endif //TAREA1_LISTAS_FORWARD_LIST_H