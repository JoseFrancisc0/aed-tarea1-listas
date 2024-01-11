#include <iostream>
#include "forward_list.h"

void forward_test(){
    Forward_List<int> lista;

    lista.push_front(5);
    lista.push_front(9);
    lista.push_front(2);
    lista.push_front(6);
    lista.push_front(0);

    lista.push_back(1);
    lista.push_back(4);
    lista.push_back(7);
    lista.push_back(3);
    lista.push_back(8);

    std::cout << "Lista: ";
    lista.print();

    lista.reverse();
    std::cout << "Lista invertida: ";
    lista.print();

    lista.sort();
    std::cout << "Lista ordenada: ";
    lista.print();

    lista.reverse();
    std::cout << "Lista invertida: ";   
    lista.print();
}

int main(int, char**){
    //forward_test();
}
