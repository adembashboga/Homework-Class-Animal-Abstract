#include <iostream>
#include <vector>
using namespace std;

class Animal
{
protected:
    string name;
    string sp;
    string continent;
    double kg;

public:
    Animal() {}
    Animal(string nm, string s, string cont, double k)
        : name(nm), sp(s), continent(cont), kg(k) {}

    virtual void Print()
    {
        cout << name << "\t" << sp << "\t" << continent << "\t" << kg << endl;
    }

    virtual void Eat() = 0;   
    virtual void Sound() = 0;
    virtual ~Animal() {}
};

class Elephant : public Animal
{
public:
    Elephant(string nm, string s, string cont, double k) : Animal(nm, s, cont, k) {}

    void Eat() override
    {
        cout << "����� ���������� ��������\n";
    }
    void Sound() override
    {
        cout << "����� ����� � ��������, � ��������, ����� ����� ������!\n";
    }
};

class Dog : public Animal
{
public:
    Dog(string nm, string s, string cont, double k) : Animal(nm, s, cont, k) {}

    void Eat() override
    {
        cout << "������ ������ ��������\n";
    }
    void Sound() override
    {
        cout << "������ ������ ���� ���-���!\n";
    }
};

class Cat : public Animal
{
public:
    Cat(string nm, string s, string cont, double k) : Animal(nm, s, cont, k) {}

    void Eat() override
    {
        cout << "���� ������ ��������\n";
    }
    void Sound() override
    {
        cout << "���� ������ ���� ���-���!\n";
    }
};

class Parrot : public Animal
{
public:
    Parrot(string nm, string s, string cont, double k) : Animal(nm, s, cont, k) {}

    void Eat() override
    {
        cout << "������� ���� ������, ������ � �����\n";
    }
    void Sound() override
    {
        cout << "������� ����� ����������� ���� ��������\n";
    }
};

int main()
{
    setlocale(0, "ru");
    vector<Animal*> animals;

    animals.push_back(new Elephant("Indian elephant", "Elephant", "Asia", 5000));
    animals.push_back(new Dog("German Shepherd", "Dog", "Europe", 30));
    animals.push_back(new Cat("Persian Cat", "Cat", "Asia", 5));
    animals.push_back(new Parrot("Macaw", "Parrot", "South America", 2));

    for (Animal* animal : animals)
    {
        animal->Print();
        animal->Eat();
        animal->Sound();
        cout << endl;
    }
}
