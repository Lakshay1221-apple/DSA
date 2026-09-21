#include <iostream>
using namespace std;

int main() {
    
    int arr[5] = {31, 29, 93, 74, 65};

    int max = arr[0];

    for(int i = 0; i < 5; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    cout << "The largest element is: " << max << endl;
    return 0;
}
