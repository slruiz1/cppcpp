#include <bits/stdc++.h>

using namespace std;

class Student {
    int m_age{0};
    int m_standard{0};
    string m_first_name{};
    string m_last_name{};
public:
    int get_age() const { return m_age; }
    void set_age(int age) { m_age = age; }

    const string& get_first_name() const { return m_first_name; }
    void set_first_name(const string& name) { m_first_name = name; }

    const string& get_last_name() const { return m_last_name; }
    void set_last_name(const string& name) { m_last_name = name; }

    int get_standard() const { return m_standard; }
    void set_standard(int standard) { m_standard = standard; }

    string to_string();
};

string Student::to_string() {
    stringstream ss;
    ss << m_age << ',' << m_first_name << ',' << m_last_name << ',' << m_standard;
    return ss.str();
}

int main () {
    Student s;
    int i;
    string name;
    cin >> i; s.set_age(i);
    cin >> name; s.set_first_name(name);
    cin >> name; s.set_last_name(name);
    cin >> i; s.set_standard(i);

    cout << s.get_age() << endl;
    cout << s.get_last_name() << ", " << s.get_first_name() << endl;
    cout << s.get_standard() << endl;
    cout << endl << s.to_string() << endl;
    return 0;
}
