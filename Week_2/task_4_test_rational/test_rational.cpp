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

class Rational {
public:
  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный

    Rational() {
        // Реализуйте конструктор по умолчанию
        _numerator = 0;
        _denominator = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        if(numerator < 0 && denominator < 0){
            numerator = -numerator;
            denominator = - denominator;
        }else if(denominator < 0){
            numerator = -numerator;
            denominator = -denominator;
        }
        _numerator = numerator;
        _denominator = denominator;
        reduce(_numerator, _denominator);
    }

    int Numerator() const {
        return _numerator;
    }

    int Denominator() const {
        return _denominator;
    }

private:
    int gcd(int n, int d) const {
        if(n < 0) n = -n;
        if(d < 0) d = -d;
        while (n > 0 && d > 0) {
            if (n > d) {
                n %= d;
            } else {
                d %= n;
            }
        }
        return n + d;
    }
    // Сократить
    void reduce(int& n, int& d){
        int divider = gcd(n, d);
        n = n / divider;
        d = d / divider;
    }

    int _numerator;
    int _denominator;
};

// Равно
bool operator==(const Rational& lhs, const Rational& rhs){
    return lhs.Numerator() == rhs.Numerator()
           && lhs.Denominator() == rhs.Denominator();
}
// Не равно
bool operator!=(const Rational& lhs, const Rational& rhs){
    return !(lhs == rhs);
}
// Вывод в поток
ostream& operator<<(ostream& stream, const Rational& rational){
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

void TestCreateRational(){
    string test_name = "Test create object: ";
    {
        // По умолчанию числитель равен 0, знаменатель равен 1
        Rational r, r_expected(0, 1);
        AssertEqual(r, r_expected, "Test default constructor");
    }
    {
        // Сокращение дроби при создании
        Rational r(2,4), r_experted(1, 2);
        AssertEqual(r, r_experted, "Reduce after create. Positive");

        r = Rational(-3, 6);
        r_experted = Rational(-1, 2);
        AssertEqual(r, r_experted, "Reduce after create. Negative");

        r = Rational(4, 2);
        r_experted = Rational(2, 1);
        AssertEqual(r, r_experted, "Reduce after create. Denomitator < Numerator");

    }
    {
        // Отрицательные дроби
        Rational r(3, -5), r_expected(-3, 5);
        AssertEqual(r, r_expected, "Negative rational");
    }
    {
        // Положительные дроби
        Rational r(-2, -5), r_expected(2, 5);
        AssertEqual(r, r_expected, "Positive rational");
    }
    {
        // Нулевой числитель
        Rational r(0, 43), r_expected(0, 1);
        AssertEqual(r, r_expected, "Numerator = 0, denominator > 0");
        r = Rational(0, -43);
        AssertEqual(r, r_expected, "Numerator = 0, denominator < 0");
    }

}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestCreateRational, "TestCreateRational");
  return 0;
}
