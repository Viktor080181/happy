#pragma once
#include <cassert>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>
#include <string>

using namespace std;

class Person;

class PersonObserver
{
public:
  
    virtual void OnSatisfactionChanged(Person& /*person*/, int /*old_value*/, int /*new_value*/) {
        
    }
protected:
    ~PersonObserver() = default;
};

class Person
{
public:

    Person(const std::string& name, int age);
     
    virtual ~Person() = default;
    int GetSatisfaction() const;
    string GetName() const;
    int GetAge() const;
    virtual void LiveADay() {}


    void SetObserver(PersonObserver* observer);
    int GetDanceCount() const;
    virtual void Dance()
    {
        SetSatisfaction(satisfaction_ + 1);
        ++count_dance_;
    }
protected:
    void SetSatisfaction(int value);
 
private:
    std::string name_;
    PersonObserver* observer_ = nullptr;
    int satisfaction_ = 100;
    int age_;
    int count_dance_ = 0;
};

class Worker : public Person
{
public:
   Worker(const std::string& name, int age);

   void Dance() override
    {
        Person::Dance();
        if (const int age = GetAge(); age > 30 && age < 40)
        {
            SetSatisfaction(GetSatisfaction() + 1);
        }
    }

   void Work();

   int GetWorkDone() const;

   void LiveADay() override
   {
       SetSatisfaction(GetSatisfaction() - 5);
       ++work_;
   }
 private:
    int work_ = 0;
};

    class Student : public Person
{
public:
    Student(const std::string& name, int age);

    void Study();
    int GetKnowledgeLevel() const;
    void Dance() override {
        Person::Dance();
    }
    
    
    void LiveADay() override
    {
        SetSatisfaction(GetSatisfaction() - 3);
        ++study_;
    }

private:
    int study_ = 0;
};

