#include <cmath>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <string_view>
#include <array>
#include <numeric>

#if 0
4
1
Walter 56 99
2
Jesse 18 50 48 97 76 34 98
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87
#endif

class Person {
    string m_name;
    uint16_t m_age;
public:
    Person() : m_name(), m_age(0) {}
    virtual ~Person() {}
    const string& get_name() const { return m_name; }
    uint16_t get_age() const { return m_age; }

    virtual void putdata() {
        cout << m_name << " " << m_age << " ";
    }
    virtual void getdata() {
        cin >> m_name >> m_age;
    }
};

constexpr int MARKS = 6;
class Student : public Person {
    array<int,MARKS> m_marks;
    static int s_next_id;
    const int m_cur_id;
public:
    Student() : m_marks(), m_cur_id(++s_next_id) {}
    ~Student() override = default;
    
    void putdata() override {
        Person::putdata();
        cout << accumulate(m_marks.begin(), m_marks.end(), 0) << " " << m_cur_id << endl;       
    }
    void getdata() override {
        Person::getdata();
        for (int i=0; i<MARKS; ++i) {
            cin >> m_marks[i];
        }
    }
};
int Student::s_next_id = 0;

class Professor : public Person {
    int m_publications;
    static int s_next_id;
    const int m_cur_id;
public:
    Professor() : m_publications(0), m_cur_id(++s_next_id) {}
    ~Professor() override = default;

    void putdata() override {
        Person::putdata();
        cout << m_publications << " " << m_cur_id << endl;       
    }
    void getdata() override {
        Person::getdata();
        cin >> m_publications;
    }
};
int Professor::s_next_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
