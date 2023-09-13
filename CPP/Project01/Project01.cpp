#include <iostream>
#include <cstdlib>

using namespace std;

int dieRoll();

int main() {
    cout << "How many rolls?: ";
    int rollCount;
    cin >> rollCount;
    cout << rollCount << " rolls" << endl;

    for (int i = 0; i < rollCount; i ++){
        cout << "calling" << endl;
        cout << dieRoll() << endl;
    }

    cout << "done rolling" << endl;
}

int dieRoll() {
    cout << "im rolling" << endl;
    return 9;
}