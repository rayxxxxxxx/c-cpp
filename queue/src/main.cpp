#include <iostream>

#include "queue.hpp"

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
    Queue<Person> queue = Queue<Person>();

    std::cout << queue.getSize() << " / " << queue.getCapacity() << '\n';

    queue.push(Person("Alice", 23));
    queue.push(Person("Eve", 17));

    std::cout << queue.getSize() << " / " << queue.getCapacity() << '\n';

    printPerson(queue.pop());

    queue.push(Person("Alex", 33));
    queue.push(Person("Kate", 28));
    queue.push(Person("Mike", 15));

    std::cout << queue.getSize() << " / " << queue.getCapacity() << '\n';

    printPerson(queue.pop());
    printPerson(queue.pop());
    printPerson(queue.pop());

    std::cout << queue.getSize() << " / " << queue.getCapacity() << '\n';

    printPerson(queue.pop());

    std::cout << queue.getSize() << " / " << queue.getCapacity() << '\n';

    try
    {
        printPerson(queue.pop());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
