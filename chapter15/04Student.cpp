#ifndef __04STUDENT_H__
#define __04STUDENT_H__
#include <iostream>
#include <string>
using namespace std;

class Person
{
  public:
    Person() = default;
    Person(const string &n, double h, int a) : name(n), height(h), age(a){};

    int age;
    void showName() const
    {
        cout << "Name: " << name << endl;
    }
    ~Person() = default;

  protected:
    double height;

  private:
    string name;
};

class Student : public Person
{
  public:
    Student() = default;
    Student(const string &n, double h, int a, int g) : Person(n, h, a), grade(g){};
    ~Student() = default;

  private:
    int grade;
};

void printPersonAgeFriend(const Person &p);

class Teacher : protected Person
{
    friend void printPersonAgeFriend(const Person &p)
    {
        cout << "Age: " << p.age << endl;
    }

  public:
    Teacher() = default;
    Teacher(const string &n, double h, int a, int s) : Person(n, h, a){};
    ~Teacher() = default;

    void printPersonAgeInside(const Person &p)
    {
        cout << "Age: " << p.age << endl;
    }
};

void printPersonAge(const Person &p)
{
    cout << "Age: " << p.age << endl;
}

int main(void)
{
    Person person("Tom", 180.00, 40);
    Student student("Jack", 183.10, 20, 3);
    Teacher teacher("Alice", 170.50, 35, 500);
    /*
    - Student Public继承Person，因此用户代码可以进行转换；
    - 用户代码只能访问到public成员，切且转换过程中权限不变
     */
    printPersonAge(person);
    printPersonAge(student);
    /*
    -  Teacher不是public继承Person，因此用户代码不能将其转换成Person类型
    - （会将Teacher中protected成员权限改成恢复成public）
    */
    // printPersonAge(teacher); // 错误：Teacher是protected继承Person，用户代码不能进行转换

    /*
    - 虽然说友元和成员函数可以转换成基类，但是需要转换自身的this指针，而不是传入一个对象（相当于一个新的对象）
     */
    printPersonAgeFriend(teacher);
    teacher.printPersonAgeInside(teacher);
}

#endif