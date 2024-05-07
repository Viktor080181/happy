#include "Happy.h"
#include "supervisor.h"
#include <cassert>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>

using namespace std;


int main() {


    vector<unique_ptr<Person>> people;
    people.emplace_back(make_unique<Worker>("Mario"s, 35));
    people.emplace_back(make_unique<Student>("Harry Potter"s, 18));

    // ��������� �����������, ������� ������, ����� ������� ���������������� ��� � �������� �� 90 �� 100
    SatisfactionSupervisor supervisor(90, 100);
    for (auto& person : people) {
        person->SetObserver(&supervisor);
    }

   

    for (auto& person : people) {
        cout << person->GetName() << "' satisfaction: "s << person->GetSatisfaction() << ", dance count: "s
            << person->GetDanceCount() << endl;
    }

    // ���������� �����������
    for (auto& person : people) {
        person->SetObserver(nullptr);
    }
}