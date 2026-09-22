#include <iostream>
using namespace std;

int main() {
    int arr[6] = {31, 29, 93, 74, 65, 92};

    int largest = arr[0];
    int second_largest = arr[0];

    for (int i = 0; i < 6; i++){
        if (arr[i] > largest){
            largest = arr[i];
        }
        if (arr[i] > second_largest && arr[i] != largest){
            second_largest = arr[i];
        }

    }

    cout << "The second largest element is: " << second_largest << endl;

}

