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

        T pop_front(){
            if(!head)
                throw std::out_of_range("Lista Vacia");
            
            Nodo* temp = head;
            T popped = temp->data;

            if(head == tail)
                head = tail = nullptr;
            else{
                head = head->next;
                head->prev = nullptr;
            }
            
            delete temp;
            nodos--;
            return popped;
        }

        T pop_back(){
            if(!head)
                throw std::out_of_range("Lista Vacia");

            Nodo* temp = tail;
            T popped = temp->data;

            if(tail == head)
                tail = head = nullptr;
            else{
                tail = tail->prev;
                tail->next = nullptr;
            }

            delete temp;
            nodos--;
            return popped;
        }

        void insert(T _data, int index){
            if(index < 0 || index > nodos)
                throw std::out_of_range("Indice no encontrado");
            
            if(index == 0)
                push_front(_data);
            else if(index == nodos)
                push_back(_data);
            else{
                Nodo* nodo = new Nodo;
                nodo->data = _data;
                
                Nodo* temp = head;
                
                for(int i=0; i<index-1; i++)
                    temp = temp->next;
                
                nodo->prev = temp;
                nodo->next = temp->next;
                temp->next->prev = nodo;
                temp->next = nodo;

                nodos++;
            }
        }

        void remove(int index){
            if(!head)
                throw std::out_of_range("Lista vacia");
            if(index < 0 || index >= nodos)
                throw std::out_of_range("Indice no encontrado");
            
            if(index == 0)
                pop_front();
            else if(index == nodos-1)
                pop_back();
            else{
                Nodo* temp = head;
                for(int i=0; i<index; i++)
                    temp = temp->next;
                
                Nodo* deleted = temp;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                delete deleted;
                nodos--;
            }
        }

        T operator[](int index){
            if(index < 0 || index >= nodos)
                throw std::out_of_range("Indice no encontrado");
            if(index == 0)
                return front();
            if(index == nodos-1)
                return back();
            
            Nodo* temp = head;
            for(int i=0; i<=index; i++)
                temp = temp->next;
            
            return temp->data;
        }

        bool empty(){
            return nodos == 0;
        }

        int size(){
            return nodos;
        }

        void clear(){
            while(head)
                pop_front();
        }

        void reverse(){
            if(!head || head == tail)
                return;
            
            Nodo* prev = nullptr;
            Nodo* temp = head;
            Nodo* next = nullptr;

            while(temp){
                next = temp->next;
                temp->next = prev;
                temp->prev = next;
                prev = temp;
                temp = next;
            }

            tail = head;
            head = prev;
        }

        void print(){
            if(!head)
                throw std::out_of_range("Lista vacia");
            
            Nodo* temp = head;
            while(temp){
                std::cout<< temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }

        ~Doubly_Linked_List(){
            clear();
        }
};

#endif //TAREA1_LISTAS_DOUBLY_LINKED_LIST_H
