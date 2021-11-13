//Example of summing up a vector without using recursion.

#include <iostream>
#include <vector>

using namespace std;

int iterate_sum(int nums[]){
    int theSum = 0;
    for (int i = 0; i < 5; i++){
        theSum += nums[i];
    }
    return theSum;
}


int dynamic_sum(vector<int> numVect){
    if (numVect.size() <= 1){
        return numVect[0];
    }
    else {
        vector<int> slice(numVect.begin() + 1, numVect.begin()+numVect.size());
        return numVect[0] + dynamic_sum(slice); //function makes a recursive call to itself.
    }
}

int dynamic_sum(int nums[], int len){
    if (len <= 1){
        return nums[0];
    }
    else {
        len--;
        return nums[0] + dynamic_sum(nums + 1, len); //function makes a recursive call to itself.
    }
}

int main() {
    int nums[5] = {1, 3, 5, 7, 9};
    int len = (sizeof(nums) / sizeof(nums[0]));

    cout << "array's len: " << len << endl;
    cout << "iterated sum(array): " << iterate_sum(nums) << endl;

    vector<int> numVect(nums, nums + len);  //Initializes vector with same items as nums.
    cout << "dynamic sum(vector): " << dynamic_sum(numVect) << endl;

    cout << "dynamic sum(array): " << dynamic_sum(nums, len) << endl;
    return 0;
}

