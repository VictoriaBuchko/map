//Создайте контейнер map из 5 элементов для сохранения информации о среднем балле студентов.
//ждый элемент этого контейнера будет содержать пару "объект класса Student" - средний балл студента.
// Найдите одного из студентов.
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Student {
    string name;

public:
    Student() {
        name = "";
    }

    Student(string Name) {
        name = Name;
    }

    string GetName()const{
        return name;
    }

    bool operator<(const Student& student) const {// для упорядочивания в бинарном дереве 
        return name < student.name;
    }

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << student.name;
        return os;
    }
};

int main() {
    map<Student, double> student; 
    map<Student, double>::iterator it;

    student.insert(make_pair(Student("Ann"), 85.5));
    student.insert(make_pair(Student("Alice"), 90.0));
    student.insert(make_pair(Student("Bob"), 78.2));
    student.insert(make_pair(Student("Vika"), 92.7));
    student.insert(make_pair(Student("Steve"), 80.9));

    for ( it = student.begin(); it != student.end(); it++)
    {
        cout << it->first << ' ' << it->second << endl;
    }

    string name;
    cout << "Enter the name of the student: ";
    cin >> name;
    Student searchStudent(name);
    it = student.find(searchStudent);
    if (it != student.end()) {
        cout << "Average score of " << it->first.GetName() << " is " << it->second << endl;
    }
    else {
        cout << "Student not found" << endl;
    }

    return 0;
}
