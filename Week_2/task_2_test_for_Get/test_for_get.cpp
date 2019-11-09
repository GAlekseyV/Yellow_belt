#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

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

//Функция возвращает количество уникальных действительных корней уравнения ax² + bx + c = 0.
//int GetDistinctRealRootCount(double a, double b, double c) {
//  // Вы можете вставлять сюда различные реализации функции,
//  // чтобы проверить, что ваши тесты пропускают корректный код
//  // и ловят некорректный
//    double D;
//    D = b * b - 4 * a * c;
//    if ((a == 0 && c == 0) || (b == 0 && c == 0)) {
//      return 0;
//    } else if (a == 0) {
//      return 1; // тут ошибка. Если b == 0, мы всё равно разделим на 0
//    } else if (b == 0) {
//      return 0;
//    } else if (c == 0) {
//      return 2;
//    } else if (D < 0) {
//      return 0;
//    } else if (D == 0) {
//      return 1;
//    } else if (D > 0) {
//      return 2;
//    }
//    return 3;
////  if(a * b * c != 0){
////    double d = b * b - 4 * a * c;
////    if(d > 0){
////      return 2;
////    }else if(d == 0){
////      return 1;
////    }
////  }// a == 0 && b == 0 && c != 0 - ������ �� �������
////  else if (a == 0 && b != 0){
////    return 1;
////  }else if(a != 0){
////    if(b == 0 && c == 0){
////      return 0;
////    }else if(b == 0 && c < 0){
////      return 2;
////    }else if(b != 0 && c == 0){
////      return 2;
////    }
////  }
//}

void TestSolveLinearEquation(){
  double a = 0;
  {
    AssertEqual(GetDistinctRealRootCount(a, 1, 0), 1, "c = 0, b != 0");
    AssertEqual(GetDistinctRealRootCount(a, 0, 1), 0, "b = 0 (division by zero)");
    AssertEqual(GetDistinctRealRootCount(a, 3.2, 2.0), 1, "b != 0, c != 0");
  }
}

void TestSolveQuadraticEquation(){
  {
    double b = 0, c = 0;
    AssertEqual(GetDistinctRealRootCount(1, b, c), 1, "b = 0, c = 0");
  }
  {
    double c = 0;
    AssertEqual(GetDistinctRealRootCount(1, 1, c), 2, "b != 0, c = 0");
  }
  {
    double b = 0;
    AssertEqual(GetDistinctRealRootCount(1, b, 1), 0, "a > 0, c > 0");
    AssertEqual(GetDistinctRealRootCount(-1, b, -1), 0, "a < 0, c < 0");
    AssertEqual(GetDistinctRealRootCount(-1, b, 1), 2, " a < 0, c > 0");
    AssertEqual(GetDistinctRealRootCount(1, b, -1), 2, " a > 0, c < 0");
  }
  {
    AssertEqual(GetDistinctRealRootCount(1, 3, 2), 2, " D > 0");
    AssertEqual(GetDistinctRealRootCount(1, 1, 1), 0, " D < 0");
    AssertEqual(GetDistinctRealRootCount(2, 4, 2), 1, " D = 0");
  }
}

int main(){
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestSolveLinearEquation, "TestSolveLinearEquation");
  runner.RunTest(TestSolveQuadraticEquation, "TestSolveQuadraticEquation");
  // Тесты квадратного уравнения
  return 0;
}
