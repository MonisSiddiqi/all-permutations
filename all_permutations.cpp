#include<iostream>
#include<vector>
#include<unordered_map>
#include<conio.h>
using namespace std;
void permutations(int arr[], int n, vector<int>&tempArr, unordered_map<int,bool>&isTaken, vector<vector<int>>&ans)
{  
    if(tempArr.size()==n)
    { 
        ans.push_back(tempArr);
        return;
    }
    for(int i=0; i<n; i++)
    {  
        if( !(isTaken[arr[i]]) )
        {   
            tempArr.push_back(arr[i]);
            isTaken[arr[i]]=true;
            permutations(arr,n,tempArr,isTaken,ans);
            tempArr.pop_back();
            isTaken[arr[i]]=false;
        }
    }

}
int main()
{   
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    cout<<"Enter array elements\n";
    int arr[n];
    for(int i=0; i<n; i++)
     cin>>arr[i];
    vector<vector<int>> ans;
    unordered_map<int,bool> isTaken;
    for(int i=0; i<n; i++)
     isTaken[arr[i]]=false;;
    vector<int> tempArr;
    permutations(arr,n,tempArr,isTaken,ans);
    for(int i=0; i<ans.size(); i++)
    {   
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    getch();
}