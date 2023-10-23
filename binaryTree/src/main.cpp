#include <iostream>

#include "binaryTree/binaryTree.hpp"
#include "binaryTree/node.hpp"

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

    bool operator==(const Person &person) const
    {
        return this->name == person.name && this->age == person.age;
    }

    bool operator!=(const Person &person) const
    {
        return this->name != person.name && this->age != person.age;
    }

    bool operator<(const Person &person) const
    {
        return this->name < person.name || (this->name == person.name && this->age < person.age);
    }

    bool operator>(const Person &person) const
    {
        return this->name > person.name || (this->name == person.name && this->age > person.age);
    }

    bool operator<=(const Person &person) const
    {
        return this->name <= person.name || (this->name == person.name && this->age <= person.age);
    }

    bool operator>=(const Person &person) const
    {
        return this->name >= person.name || (this->name == person.name && this->age >= person.age);
    }
};

int main(int argc, char **args)
{
    Node<Person> n1 = Node<Person>(Person("Alex", 20));
    Node<Person> n2 = Node<Person>(Person("Alice", 27));
    Node<Person> n3 = Node<Person>(Person("Kate", 34));

    std::cout << n1.getData().name << std::endl;
    n1.getData() = Person("Mike", 40);
    std::cout << n1.getData().name << std::endl;
    n1.setData(n3.getData());
    std::cout << n1.getData().name << std::endl;
    n1.setData(Person("Rachel", 17));
    std::cout << n1.getData().name << std::endl;

    n1.setLeft(&n2);
    n1.setRight(&n3);

    std::cout << n1.getLeft()->getData().name << std::endl;
    std::cout << n1.getRight()->getData().name << std::endl;

    n1 = n2;
    std::cout << &n1 << " " << &n2 << std::endl;
    std::cout << n1.getData().name << std::endl;

    Person p1 = Person("Alex", 30);
    Person p2 = Person("Kate", 17);
    Person p3 = Person("Alice", 23);
    Person p4 = Person("Michel", 38);
    Person p5 = Person("John", 25);

    Tree<Person> tree = Tree<Person>(p1);
    tree.add(p2);
    tree.add(p3);
    tree.add(p4);
    tree.add(p5);

    Person *persons = tree.getAll();
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << tree.has(persons[i]) << " " << persons[i].name << " " << persons[i].age << std::endl;
    }

    return 0;
}