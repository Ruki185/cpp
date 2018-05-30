#include "forwardlist.hpp"

#include <iostream>

using namespace a08;

int main() {
    ForwardList<int> list;
    ForwardList<int> other;
    other.push_front(7);

    std::cout << "Size: " << list.size() << std::endl;
    list.push_front(1);
    std::cout << "Size: " << list.size() << std::endl;
    list.push_front(2);
    std::cout << "Size: " << list.size() << std::endl;
    list.push_front(3);
    std::cout << "Size: " << list.size() << std::endl;
    list.push_front(4);
    list.insert_after(list.insert_after(list.begin(), 5), 6);
    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "Size: " << list.size() << std::endl;
    list.pop_front();
    list.front() = 9;

    other = list;

    for(auto i: other){
        std::cout << i << std::endl;
    }

    std::cout << list.front() << std::endl;
}
