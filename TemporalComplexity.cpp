#include <iostream>
using namespace std;

// Exercise 1
// Answer: b has a temporal complexity of O(n^2) because for every n_0 and its relative constant the condition f(n) <= cg(n) is met.

// Exercise 2
// Answer: a has a temporal complexity of Ω(n^2) because for every n_0 and its relative constant the condition f(n) >= cg(n) is met.

// Exercise 3
int binarySearch(int arr[][6],int lowerBound, int upperBound, int j, int count = 0) // Binary search helper function, temporal complexity = O(logn)
{
    int middleIndex = (lowerBound + (upperBound-1))/2;    // Declare middle index 
                                                              
    if(lowerBound >= upperBound)    // Base case for recursive function                     
    {
        return count;               // Returns count which contains height of building 
    }
    if(arr[middleIndex][j] == 0)
    {
        count = middleIndex + 1;
        return binarySearch(arr, middleIndex + 1, upperBound, j, count);  
    }
    else                     // Recursive calls adjusting bounds
    {
        return binarySearch(arr, lowerBound, middleIndex - 1, j, count);
    }
}


// getTallestBuilding has a O(mlogn) run time because for every value on m we conduct a binary search through n which has a O(logn), thus O(mlogn).
int getTallestBuilding(int arr[][6],int n,int m){
    
    int max = 0;
    int height = 0;
    int lowerBound = 0;
    int upperBound = n;

    // Traverse M
    for(int j = 0; j < m; j++) // O(m)
    {
    // Binary Search for N
    int val = binarySearch(arr, lowerBound, upperBound, j); // O(logn)
    if(val > height) // Checks if the height returned by helper function is bigger than than the max
    {
        max = j;
        height = val;
        lowerBound = height; // Crops bounds so that helper function checks from tallest hight, saving time.

        if(val >= n) // If helper function count is the same as the max height break 
            break;
    }
    }

    return max;
}

// getTallestBuildingV2 has a temporal complexity of O(m + n) because we only iterate though m and n once.
int getTallestBuildingV2(int arr[][6],int n,int m)
{
    int i = 0, j = 0, max = 0;
    while(i < n && j <= m) // n + m
    {
        if(arr[i][j] == 0)
        {
            i += 1;
            max = j;
        }
        else
            j += 1;
        
    }
    return max;

}

int main(){

    // Creating Array
    int matrix[][6] = {
        {0,0,0,0,0,1},
        {0,1,0,0,0,1},
        {0,1,0,0,0,1},
        {1,1,0,0,0,1},
        {1,1,1,0,1,1}

    };
    
    cout << "O(mlogn) tallest building is in location: " << getTallestBuilding(matrix, 5 ,6) << endl;
    cout << "O(m + n) tallest building is in location: " << getTallestBuildingV2(matrix, 5 ,6) << endl;

    return 1;
}