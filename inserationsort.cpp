#include<iostream>
using namespace std;
int main()
{
  int A[]={7,5,8,3,1,4};
  int n=6;
  
    for(int i=1;i<n;i++)
    {
      int temp=A[i];
      int j=i-1;
      
      while(j>=0&& A[j]>temp)
      {
        A[j+1]=A[j];
        j--;
      }
      A[j+1]=temp;
    }
    cout<<"Sorted Array :";
    
    for(int i=0;i<n;i++)
    {
      cout<<A[i]<<"\t\t";
    }
    return 0;
  }

