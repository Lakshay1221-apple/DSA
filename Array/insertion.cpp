#include <iostream>
using namespace std;

int main() {

    int arr[8] = {10, 20 , 30, 40, 50};

    int n = 5;
    int position = 2;
    int element = 44;

    for(int i = n ; i > position ; i--){
        arr[i] = arr[i - 1];
    }

    arr[position]  = element;

    n++;
    
    for(int i = 0; i < n ; i++){
        cout << arr[i] << endl;
    }

    return 0;

}