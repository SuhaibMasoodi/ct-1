//Name: Suhaib Masoodi
//Roll.No: 2010992460 
//Set: 05
//Question no.2
#include <bits/stdc++.h>
using namespace std;

// Function to print all subarrays in the array which has sum zero.
vector< pair<int, int> > findSubArrays(int arr[], int n)
{
//Create an empty map
unordered_map<int, vector<int> > map;

//Create an empty vector of pairs to store subarray starting and ending index.
vector <pair<int, int>> out;

//Maintains sum of elements so far.
int sum = 0;

for (int i = 0; i < n; i++)
{
//Add current element to sum.
sum += arr[i];

//If sum is 0, we found a subarray starting from index 0 and ending at index i.
if (sum == 0)
out.push_back(make_pair(0, i));

//If sum already exists in the map there exist at-least one subarray ending at index i with 0 sum.
if (map.find(sum) != map.end())
{
//Map[sum] stores starting index of all subarrays
vector<int> vc = map[sum];
for (auto it = vc.begin(); it != vc.end(); it++)
out.push_back(make_pair(*it + 1, i));
}

//Important - no else
map[sum].push_back(i);
}

//Return output vector
return out;
}

//Utility function to print all subarrays with sum 0
void print(vector<pair<int, int>> out,int arr[])
{
for (auto it = out.begin(); it != out.end(); it++){
for(int i = it->first; i <= it->second;i++ ){
            cout<<arr[i]<<" ";
        }
cout<<endl;
}
        
}
int main()
{
int arr[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
int n = sizeof(arr)/sizeof(arr[0]);

vector<pair<int, int> > out = findSubArrays(arr, n);

//If we didn’t find any subarray with 0 sum, then subarray doesn’t exists.
if (out.size() == 0)
cout << "No subarray exists";
else
print(out,arr);

return 0;
}
