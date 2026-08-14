#include<iostream>
using namespace std;

int binarySearch(int A[],int low, int high)
{
  int key,mid;
  cout<<"\nEnter The Element To Be Entered :";
  cin>>key;
  while(low<=high)
  {
    mid=low+(high-low)/2;
    if(key==A[mid])
    {
      return mid;
    }
    if(key>A[mid])
    {
      low=mid+1;
    }
    else
    {
      high=mid-1;
    }
  }
    return-1;
}
  int main()
  {
    int A[]={2,3,6,7,8,11,14};
    
    cout<<"Array element :";
    for(int i=0;i<=6;i++)
    {
      cout<<A[i]<<"\t";
    }
    int result=binarySearch(A,0,6);
    if(result==-1)
    {
      cout<<"Element not found";
    }
    else
    {
      cout<<"Element found";
    }
    return 0;
    }
    
