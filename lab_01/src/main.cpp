#include <iostream>
#include <string>
#include "time_compare.hpp"
#include "manual_input.hpp"

using namespace std;

int main() {
    size_t rc = 1;
    while (rc)
    {
        cout << "Type 1 to manually enter\n"
                "Type 2 to compare time\n"
                "Type 0 to exit\n";
        cin >> rc;
        if (rc == 1)
        {
            manual_input();
        }
        else if (rc == 2)
        {
            time_compare();
        }
    }
    
    return 0;
}
