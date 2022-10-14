//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        set<int, greater<int>> s;
        set<int, greater<int> >::iterator itr;
        unordered_map<int, int> hash;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            s.insert(a[i]);
            hash[a[i]]++;
        }
        for (itr = s.begin(); itr != s.end(); itr++) {
            int val = *itr;
            if (hash[val] > 0) {
                sum += val*hash[val];
                hash[val-1] -= hash[val]; 
            }
        }
        return sum;
        
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends