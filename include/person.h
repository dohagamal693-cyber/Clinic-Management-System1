#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
public:
    Person(int id = 0, string name = "") : id(id), name(name) {}
    virtual ~Person() {}
    int getId() const { return id; }
    string getName() const { return name; }
    void setId(int id) { this->id = id; }
    void setName(const string& name) { this->name = name; }
    virtual void displayInfo() const = 0;
};

class Patient : public Person {
private:
    int age;
    string phone;
public:
    Patient(int id = 0, string name = "", int age = 0, string phone = "")
        : Person(id, name), age(age), phone(phone) {}
    int getAge() const { return age; }
    string getPhone() const { return phone; }
    void setAge(int age) { this->age = age; }
    void setPhone(const string& phone) { this->phone = phone; }
    void displayInfo() const override {
        cout << "ID: " << id << " | Patient: " << name << " | Age: " << age << " | Phone: " << phone << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
public:
    Doctor(int id = 0, string name = "", string specialization = "")
        : Person(id, name), specialization(specialization) {}
    string getSpecialization() const { return specialization; }
    void setSpecialization(const string& specialization) { this->specialization = specialization; }
    void displayInfo() const override {
        cout << "ID: " << id << " | Dr. " << name << " | Specialization: " << specialization << endl;
    }
};

#endif
