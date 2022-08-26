//Name: Suhaib Masoodi
//Roll.No: 2010992460 
//Set: 05
//Question no.1

#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int Longest_Subarr(int arr[],int n,int k)
{
    //If any one passes empty array then the exception will be called and it will print this:

    if(n<=0) throw string("array size less than or equal to 0");
 
    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;
 
    
    for (int i = 0; i < n; i++) {
 
        //Taking prefix sum for each element
        sum += arr[i];
 
        
        if (sum == k)
            maxLen = i + 1;
 
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
 

//We see that if that if the current sum > k then we search for prefix sum sum-k in the map and if it is present we get the subarray with sum k and then we move on to find if there is any longer subarray present.

        if (mp.find(sum - k) != mp.end()) {
 
            //We update the laxlen variable if we find any longer subarray.

            if (maxLen < (i - mp[sum - k]))
                maxLen = i - mp[sum - k];
        }
    }
 
  
    return maxLen;


   
}
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL);

int n,k;cin>>n>>k;



/*
input format-

n k
then the elements of array

6 15
10 5 2 7 1 9


 int arr[] = {10, 5, 2, 7, 1, 9};

    int n = sizeof(arr) / sizeof(arr[0]);


    int k = 15; */

    

    try{

        int arr[n];
        for(int i=0;i<n;i++){
        cin>>arr[i];
        }
        
         cout<< Longest_Subarr(arr, n, k);
    }

    catch (string &s){
        cout<<s;

    }

   
   

return 0;
}
