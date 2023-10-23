#include <iostream>

#include "node.hpp"
#include "linkedList.hpp"

class Person
{
public:
    std::string name;
    int age;

    Person()
    {
        this->name = "";
        this->age = -1;
    }

    Person(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    Person &operator=(const Person &person)
    {
        this->name = person.name;
        this->age = person.age;
        return *this;
    }

    bool operator==(const Person &other)
    {
        return this->name == other.name && this->age == other.age;
    }
};

int main(int argc, char *argv[])
{
    Person p1 = Person("Adam", 20);
    Person p2 = Person("Eve", 19);
    Person p3 = Person("Alice", 27);
    Person p4 = Person("Alex", 41);

    LinkedList<Person> list = LinkedList<Person>();

    list.push(p1);
    list.push(p2);
    list.push(p3);

    std::cout << list.getSize() << std::endl;

    list.insert(3, p4);

    std::cout << list.getSize() << std::endl;

    Person p5 = list.pop();

    std::cout << p5.name << std::endl;

    std::cout << list.getSize() << std::endl;

    Node<Person> *head = list.getHead();
    while (head != nullptr)
    {
        std::cout << head->getData().name << std::endl;
        head = head->getNext();
    }

    list.clear();

    std::cout << list.getSize() << std::endl;

    std::cout << list.isEmpty() << std::endl;

    return 0;
}