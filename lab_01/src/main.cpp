#include "levenstein.hpp"
#include "manual_input.hpp"
#include "time_compare.hpp"
#include <iostream>
#include <string>

using namespace std;

method_func_t select_func() {
  while (1) {
    cout << "Type 1 to select matrix method\n"
            "Type 2 to select recursion method\n"
            "Type 3 to select recursion with cache method\n"
            "Type 4 to select domerau method\n";
    size_t rc;
    cin >> rc;
    switch (rc) {
    case 1:
      return matr_method;
      break;
    case 2:
      return recur_method;
      break;
    case 3:
      return rec_cache_method;
      break;
    case 4:
      return Domerau_method;
      break;
    }
  }
}

int main() {

  size_t rc = 1;
  while (rc) {
    cout << "Type 1 to manually enter\n"
            "Type 2 to compare time\n"
            "Type 3 to run 1 method\n"
            "Type 4 to write statistics in files\n"
            "Type 0 to exit\n";
    cin >> rc;
    if (rc == 1) {
      manual_input();
    } else if (rc == 2) {
      time_compare();
    } else if (rc == 3) {
      auto func = select_func();
      manual_input(func);
    } else if (rc == 4) {
      time_compare(false);
    }
  }

  return 0;
}
