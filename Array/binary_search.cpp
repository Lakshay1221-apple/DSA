#include <iostream>
using namespace std;

int main() {

    int arr[] = {30, 20, 40, 77, 84};

    int n = 5;
    int target = 77;

    int index = -1;

    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == target){
            index = mid;
            break;
        }

        else if(arr[mid] < target){
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }

    if(index != -1){
        cout << "element found at index" << index << endl;
    } else {
        cout << "element not found" << endl;
    }

    return 0;
}