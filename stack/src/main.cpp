#include <iostream>

#include "stack.hpp"

template <typename T>
void println(T);

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

    Person &operator=(const Person &other)
    {
        this->name = other.name;
        this->age = other.age;
        return *this;
    }
};

void printPerson(Person p)
{
    std::cout << p.name << ", " << p.age << std::endl;
}

int main(int argc, char *argv[])
{
    Stack<Person> stack = Stack<Person>();

    std::cout << stack.getSize() << " / " << stack.getCapacity() << '\n';

    stack.push(Person("Alice", 23));
    stack.push(Person("Eve", 17));

    std::cout << stack.getSize() << " / " << stack.getCapacity() << '\n';

    printPerson(stack.pop());

    stack.push(Person("Alex", 33));
    stack.push(Person("Kate", 28));
    stack.push(Person("Mike", 15));

    std::cout << stack.getSize() << " / " << stack.getCapacity() << '\n';

    printPerson(stack.pop());
    printPerson(stack.pop());
    printPerson(stack.pop());

    std::cout << stack.getSize() << " / " << stack.getCapacity() << '\n';

    stack.clear();

    std::cout << stack.getSize() << " / " << stack.getCapacity() << '\n';

    try
    {
        printPerson(stack.pop());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}