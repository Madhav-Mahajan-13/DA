#include<iostream>
#include <bits/stdc++.h>
using namespace std;




int partition(float w[],float v[],float arr[],int low,int high)
{
  //choose the pivot
   
 int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i],arr[j]);
      swap(w[i],w[j]);
      swap(v[i],v[j]);
    }
  }
  swap(arr[i+1],arr[high]);
   swap(w[i+1],w[high]);
   swap(v[i+1],v[high]);
  return (i+1);
}
 
// The Quicksort function Implement
            
void quickSort(float w[], float v[],float arr[],int low,int high)
{
 
  if(low<high)
  {
    
   int pi=partition(w,v,arr,low,high);
     
   
    quickSort(w,v,arr,low,pi-1);
    quickSort(w,v,arr,pi+1,high);
  }
}


int fractional_Knapsack(float w[],float v[],int c,int n){
    
    // float size=n;
    float ratio[n+1];
    for (int i = 0; i <=n; i++)
    {
        ratio[i]=v[i]/w[i];

    }
    
    


    quickSort(w,v,ratio,0,n);

    for (int i = 0; i <=n; i++)
    {
        cout<<w[i]<<" ";
    }cout<<endl;
    for (int i = 0; i <=n; i++)
    {
        cout<<v[i]<<" ";
    }
   int last=n;
    float load=0;float value=0;
    while(load<c && last>=0){
      if(w[last]<c-load){
        load+=w[last];value=value+v[last];
        last--;
        
      }else if(w[last]>(c-load )|| w[last]==(c-load)){
        
        double rt=(c-load)/w[last];
        cout<<rt<<endl;
        value=value+rt*v[last];
        load=load+rt*w[last];
        cout<<load<<endl;
        
      }

    }
    return value; 

    
}


int main(){
    float value[]={100,120,60};
    float weight[]={20,30,10};
    float x=fractional_Knapsack(weight,value,50,2);
    cout<<x;

}