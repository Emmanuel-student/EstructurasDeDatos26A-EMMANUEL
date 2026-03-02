
#include "name.hpp"

using namespace std;

Name::Name() {}  //se inicializan como cadenas vacias

Name::Name(const Name& n) : last(n.last), first(n.first) {}

Name::Name(const string& l, const string& f) : last(l), first(f) {}

string Name::getLast() const {
    return this->last;
}

string Name::getFirst() const {
    return this->first;
}

string Name::toString() const {
    return this->last + ", " + this->first;
}

void Name::setLast(const string& l) {
    this->last=l;
}

void Name::setFirst(const string& f) {
    this->first=f;
}

Name& Name::operator=(const Name& n) {
    this->last=n.last;
    this->first=n.first;

    return *this;
}

bool Name::operator==(const Name& n) const {
    return this->toString() == n.toString();
}

bool Name::operator!=(const Name& n) const {
    return !(*this == n);
}

bool Name::operator<(const Name& n) const {
    return this->toString() < n.toString();
}

bool Name::operator<=(const Name& n) const {
    return *this < n or *this == n;
}

bool Name::operator>(const Name& n) const {
    return !(*this <= n);
}

bool Name::operator>=(const Name& n) const {
    return !(*this < n);
}

istream& operator>>(istream& is, Name& n) {
    getline(is, n.last);
    getline(is, n.first);

    return is;
}

ostream& operator<<(ostream& os, const Name& n) {
    os << n.last << endl;
    os << n.first;

    return os;
}
