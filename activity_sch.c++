#include<iostream>
using namespace std;

int partition(int w[],  int arr[], int low, int high)
{
  
   
 int pivot=arr[high];
  
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
   
    if(arr[j]<pivot)
    {
      
      i++;
      swap(arr[i],arr[j]);
      swap(w[i],w[j]);
      
    }
  }
  swap(arr[i+1],arr[high]);
   swap(w[i+1],w[high]);
   
  return (i+1);
}


void quickSort(int w[],int arr[],int low,int high)
{
 
  if(low<high)
  {
    
   int pi=partition(w,arr,low,high);
     
   
    quickSort(w,arr,low,pi-1);
    quickSort(w,arr,pi+1,high);
  }
}


int activity(int start[],int finish[],int n){

    // quickSort(start,finish,0,n);

    int order[n];
    int j=1;
    order[1]=start[0];
    int  k=0;

    for (int i = 1; i <n; i++)
    {
     if(start[i]>=finish[k]){
        j++;
        order[j]=start[i];
        k=i;

        

     }

    }

    cout<<"the no of activity that can be placed are -"<<j<<endl;
    cout<<"the start time of act are as -"<<endl;
    for(int i=1;i<=j;i++){
        cout<<order[i]<<" ";
    }
    


    
    

}
int main(){
    int s[]={ 1, 3, 0, 5, 8, 5 };
    int e[]={ 2, 4, 6, 7, 9, 9 };
    int n = sizeof(s) / sizeof(s[0]); 
    activity(s,e,n);

}