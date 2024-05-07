#include "Happy.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>

using namespace std;

    

    Person::Person(const std::string& name, int age)
        : name_(name)
        , age_(age)
    {
    }
   
    int Person::GetSatisfaction() const
    {
        return satisfaction_;
    }

    std::string Person::GetName() const
    {
        return name_;
    }

    int Person::GetAge() const
    {
        return age_;
    }

    void Person::SetObserver(PersonObserver* observer)
    {
        observer_ = observer;
    }

    int Person::GetDanceCount() const
    {
        return count_dance_;
    }

    void Person::SetSatisfaction(int value)
    {
        if (satisfaction_ != value)
        {
            int old_satisfaction = satisfaction_;
            satisfaction_ = value;
           
            if (observer_)
            {
                observer_->OnSatisfactionChanged(*this, old_satisfaction, satisfaction_);
            }
        }
    }

Worker::Worker(const std::string& name, int age)
        :Person(name, age)
    {
    }
   
    void Worker::Work()
    {
        SetSatisfaction(GetSatisfaction() - 5);
        ++work_;
    }

   int Worker::GetWorkDone() const
    {
        return work_;
    }

    

Student:: Student(const std::string& name, int age)
        :Person(name, age)
    {
    }

    void Student::Study()
    {
        SetSatisfaction(GetSatisfaction() - 3);
        ++study_;
    }

    int Student::GetKnowledgeLevel() const
    {
        return study_;
    }
  

