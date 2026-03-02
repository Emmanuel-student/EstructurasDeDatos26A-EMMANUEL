#include "group.hpp"

using namespace std;
Group::Group() {}

void Group::addStudent(const Student& s) {
    if(this->size < 50) {
        this->data[this->size] = s;

        this->size++;
    }
}

void Group::delStudent(const Student&) {}

string Group::toString() const {
    string result;

    for(int i(0); i<this->size; i++) {
        result += this->data[i].toString() + "\n";

    }

    return result;
}

int Group::findStudent(const Student&) {}

void Group::modStudent(const int&, const Student&) {}
