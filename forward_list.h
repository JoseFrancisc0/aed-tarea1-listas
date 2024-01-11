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

        void sort(){
            if(!head || !head->next)
                return;
            
            Nodo* nodo = head;
            while(nodo->next){
                Nodo* min = nodo;
                Nodo* temp = nodo->next;
                
                while(temp){
                    if(temp->data < min->data)
                        min = temp;
                    temp = temp->next;
                }
                
                T _data = nodo->data;
                nodo->data = min->data;
                min->data = _data;

                nodo = nodo->next;
            }
        }

        void reverse(){
            if(!head || !head->next)
                return;

            Nodo* temp = head;
            Nodo* prev = nullptr;
            Nodo* next = nullptr;

            while(temp){
                next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
            }

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
        };

        ~Forward_List(){
            clear();
        };
};

#endif //TAREA1_LISTAS_FORWARD_LIST_H
