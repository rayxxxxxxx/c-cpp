#include <iostream>

#include "node.hpp"
#include "linkedList.hpp"

template <typename T>
void println(T data);
void println();

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

    list.insert(p4, 3);

    Person p5 = list.pop();
    println(p5.name);

    println();

    Node<Person> *head = list.getHead();
    while (head != nullptr)
    {
        println(head->data().name);
        head = head->next();
    }

    list.clear();

    println();

    println(list.empty());
    println(list.getHead());
    println(list.getTail());

    return 0;
}

template <typename T>
void println(T data)
{
    std::cout << data << std::endl;
}

void println()
{
    std::cout << std::endl;
}
