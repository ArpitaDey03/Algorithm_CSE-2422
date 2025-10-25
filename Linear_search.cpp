#include<bits/stdc++.h>
using namespace std;

int linear_search (int arr[],int n,int data){
for(int i=0;i<=n;i++){
    if(arr[i]==data)
    {
        return i;
    }
}
  return -1;
  }
  int main(){
  int n,data;
  cout<<"size: ";
  cin>>n;
  int arr[n];
  cout<<"Enter Element: ";

  for(int i=0;i<=n;i++)
  {
      cin>>arr[i];
  }
  cout<<"Enter Element to search: ";
  cin>>data;

  int result=linear_search(arr,n,data);
  if(result!=-1)
  {
      cout<<"element found at :"<<result;
  }
  else{
    cout<<"element not found";}
    return 0;
  }
