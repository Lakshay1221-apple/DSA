#include <iostream>
using namespace std;

int main() {

    int arr[] = {30, 55, 21, 45, 90};
    int n = 5;
    int index = -1;

    int find = 45;

    for(int i = 0; i < n ; i++){
        if(find == arr[i]){
            index = i;
        }
    }

    cout << find << "found at index" << index << endl;

    return 0;
}