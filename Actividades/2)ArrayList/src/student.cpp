#include "student.hpp"

using namespace std;

Student::Student() {}

Student::Student(const Student& s) :code(s.code), name(s.name), birthDate(s.birthDate),
career(s.career), starDate(s.starDate), grade(s.grade)  {}

string Student::getCode() const {
    return this->code;
}

Name Student::getName() const {
    return this->name;
}

Date Student::getBirthDate() const {
    return this->birthDate;
}

string Student::getCareer() const {
    return this->career;
}

Date Student::getStartDate() const {
    return this->starDate;
}

float Student::getGrade() const {
    return this->grade;
}

string Student::toString() const {
    string result;
    char myGrade[8]; //Por que 8?

    sprintf(myGrade, "%6.2f", this->grade); 

    result += this->code;
    result += " | ";
    result += this->name.toString();
    result.resize(40, ' ');
    result += " | ";
    result += this->birthDate.toString();
    result += " | ";
    result += this->career;
    result += " | ";
    result += this->starDate.toString();
    result += " | ";
    result += myGrade;

    return result;
}

void Student::setCode(const string& c) {
    this->code=c;
}

void Student::setName(const Name& n) {
    this->name=n;
}

void Student::setBirthDate(const Date& d) {
    this->birthDate = d;
}

void Student::setCareer(const string& c) {
    this->career=c;
}

void Student::setStartDate(const Date& d) {
    this->starDate=d;
}

void Student::setGrade(const float& g) {
    this->grade = g;
}

Student& Student::operator=(const Student& s) {
    this->code= s.code;
    this->name= s.name;
    this->birthDate = s.birthDate;
    this->career = s.career;
    this->starDate = s.starDate;
    this->grade = s.grade;

    return *this;

}

bool Student::operator==(const Student& s) const {
    return this->code==s.code;
}

bool Student::operator!=(const Student& s) const {
    return !(this->code==s.code);
}

bool Student::operator<(const Student& s) const {
    return this->code < s.code;
}

bool Student::operator<=(const Student& s) const {
    return *this < s or *this==s;
}

bool Student::operator>(const Student& s) const {
    return !(*this <= s);
}

bool Student::operator>=(const Student& s) const {
    return !(*this < s);
}

istream& operator>>(istream& is, Student& s) {  
    string myStr;
   
    getline(is, s.code);
    is >> s.name;
    is >>s.birthDate;
    getline(is, s.career);
    is >> s.starDate;
    getline(is, myStr);
    s.grade = stof(myStr);

    return is;
}

ostream& operator<<(ostream& os, const Student& s) {
    os << s.code << endl;
    os << s.name << endl;
    os << s.starDate<< endl;
    os << s.career <<endl;
    os << s.starDate <<endl;
    os << s.grade;

    return os;
}
