#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    void display() {
        cout << "Name: " << name << " | Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    string studentID;
    int gradeLevel;
public:
    Student(string n, int a, string id, int grade)
        : Person(n, a), studentID(id), gradeLevel(grade) {}
    void display() {
        Person::display();
        cout << "Student ID: " << studentID
             << " | Grade Level: " << gradeLevel << endl;
    }
};

class Teacher : public Person {
protected:
    string subject;
    int roomNumber;
public:
    Teacher(string n, int a, string sub, int room)
        : Person(n, a), subject(sub), roomNumber(room) {}
    void display() {
        Person::display();
        cout << "Subject: " << subject
             << " | Room: " << roomNumber << endl;
    }
};


class GraduateStudent : public Student, public Teacher {
    string researchTopic;
public:

    GraduateStudent(string n, int a, string id, int grade,
                    string sub, int room, string topic)
        : Student(n, a, id, grade),
          Teacher(n, a, sub, room),
          researchTopic(topic) {}

    void display() {
        cout << "=== Graduate Student ===" << endl;
        Student::display();
        cout << "Subject Taught: " << subject
             << " | Room: "        << roomNumber << endl;
        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main() {
    GraduateStudent gs("Taimoor", 24, "MS-101", 7,
                       "Data Structures", 305, "AI in Cybersecurity");
    gs.display();
    return 0;
}
