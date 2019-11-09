#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

class Person {
public:
    // Вы можете вставлять сюда различные реализации класса,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
    void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    year_to_firstname[year] = first_name;
  }
    void ChangeLastName(int year, const string& last_name) {
      // добавить факт изменения фамилии на last_name в год year
      year_to_lastname[year] = last_name;
    }
    string GetFullName(int year) {
      // получить имя и фамилию по состоянию на конец года year
      if(isIncognito(year)){
        return "Incognito";
      }else if(isNoChangeFirstName(year)){
        return GetLastName(year) + " with unknown first name";
      }else if(isNoChangeLastName(year)){
        return GetFirstName(year) + " with unknown last name";
      }else{
        return GetFirstName(year) + " " + GetLastName(year);
      }
    }
private:
    string GetFirstName(int year){
      // ищу год последнего изменения
      int lastChangeYear = year;
      for(const auto& i : year_to_firstname){
        if(i.first <= year){
          lastChangeYear = i.first;
        }else{
          break;
        }
      }
      return year_to_firstname[lastChangeYear];
    }
    string GetLastName(int year){
      // ищу год последнего изменения
      int lastChangeYear = year;
      for(const auto& i : year_to_lastname){
        if(i.first <= year){
          lastChangeYear = i.first;
        }else{
          break;
        }
      }
      return year_to_lastname[lastChangeYear];
    }

    bool isIncognito(int year){
      return isNoChangeFirstName(year) && isNoChangeLastName(year);
    }

    bool isNoChangeFirstName(int year){
      int count = 0;
      for(const auto& i : year_to_firstname){
        if(i.first <= year){
          count++;
        }
      }
      return count == 0;
    }

    bool isNoChangeLastName(int year){
      int count = 0;
      for(const auto& i : year_to_lastname){
        if(i.first <= year){
          count++;
        }
      }
      return count == 0;
    }

    map<int, string> year_to_firstname;
    map<int, string> year_to_lastname;
};

void TestIncognito(){
    string test_name = "Test incognito: ";
    {
        // Списки пусты
        Person empty;
        AssertEqual(empty.GetFullName(0),"Incognito" , test_name + "Empty person, year = 0");
        AssertEqual(empty.GetFullName(1),"Incognito" , test_name + "Empty person, year = 1");
    }
    {
        // Год запроса рашьше изменений имени и фамилии
        Person t;
        int year_change = 2000, year_request = 1999;
        t.ChangeFirstName(2000, "Alice");
        t.ChangeLastName(2000, "Ivanova");
        AssertEqual(t.GetFullName(year_request), "Incognito", test_name + "Year request < year change");
    }
}

void TestNoChangeLastName() {
    string test_name = "Test no change last name: ";
    {
        // Изменений фамилии не было
        Person p;
        p.ChangeFirstName(2000, "Alice");
        AssertEqual(p.GetFullName(2000), "Alice with unknown last name", test_name + "Last name did not change");
    }
    {
        // Год запроса раньше изменения
        Person p;
        p.ChangeFirstName(1998, "Alice");
        p.ChangeLastName(2000, "Ivanova");
        AssertEqual(p.GetFullName(1999), "Alice with unknown last name", test_name + "Last name did not change");
    }
}

void TestNoChangeFirstName(){
    string test_name = "Test no change first name: ";
    {
        // Изменений имени не было
        Person p;
        p.ChangeLastName(2000, "Ivanova");
        AssertEqual(p.GetFullName(2000), "Ivanova with unknown first name", test_name + "First name did not change");
    }
    {
        // Год запроса раньше изменения
        Person p;
        p.ChangeFirstName(2000, "Alice");
        p.ChangeLastName(1998, "Ivanova");
        AssertEqual(p.GetFullName(1999), "Ivanova with unknown first name", test_name + "First name did not change");
    }


}

void TestFullName(){
    string test_name = "Test full name: ";
    {
        Person p;
        p.ChangeFirstName(2000, "Alice");
        p.ChangeFirstName(2005, "Polina");
        p.ChangeLastName(2001, "Ivanova");
        p.ChangeLastName(2002, "Petrova");
        AssertEqual(p.GetFullName(2001), "Alice Ivanova", test_name + "1" );
        AssertEqual(p.GetFullName(2002), "Alice Petrova", test_name + "2" );
        AssertEqual(p.GetFullName(2003), "Alice Petrova", test_name + "3" );
        AssertEqual(p.GetFullName(2006), "Polina Petrova", test_name + "4" );
    }

}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestIncognito, "TestIncognito");
  runner.RunTest(TestNoChangeFirstName, "TestNoChangeFirstName");
  runner.RunTest(TestNoChangeLastName, "TestNoChangeLastName");
  runner.RunTest(TestFullName, "TestFullName");
  return 0;
}
