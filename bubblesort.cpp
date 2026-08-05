#include<iostream>
using namespace std;
int main()
{
  int n;
  cout<<"Enter Number Of Element :";
  cin>>n;
  int A[n];
  cout<<"\nEnter the element :";
  for(int i=0;i<=n;i++)
  {
    cin>>A[i];
  }
    for(int i=0;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
      { 
        if(A[i]>A[j])
        {
          int temp=A[i];
          A[i]=A[j];
          A[j]=temp;
        }
      }
    }
    cout<<"\nShort Array :";
    for(int i=0;i<=n;i++)
    {
    cout<<A[i]<<"\t";
    }
    return 0;
    }
