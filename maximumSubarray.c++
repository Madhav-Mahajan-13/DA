#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int left_index=0;int right_index=0;
int max(int a, int b) { 
    return (a > b) ? a : b; 
} 
int max(int a, int b, int c) { 
    return max(max(a, b), c); 
} 
int cross_array(int a[],int s,int mid , int end){
    int n=mid;int sum1=0;int max_sum1=-999;
    while(n>=s){
        sum1= sum1 +a[n];
        
        if(sum1>max_sum1){
            max_sum1=sum1;
            left_index=n;
        }n--;
    }
    int max_sum2=-999;
    int m=mid+1;int sum2=0;
    while(m<=end){
        sum2 = sum2 +a[m];
        if(sum2>max_sum2){
            max_sum2=sum2;
            right_index=m;
        }m++;
    }
    return max(max_sum1+max_sum2,max_sum1,max_sum2+a[mid]);
}

int maxSubarray(int a[],int p,int r){

    if(p==r){
        return a[p];
    }
    else if(p<r){
       int q=p+(r-p)/2;
       int left=maxSubarray(a,p,q);
       int right=maxSubarray(a,q+1,r);
       int c=cross_array(a,p,q,r);
       return max(left,right,c);
    }

}

int main() { 
    int arr[] = { -2, -5, 6, -2, -3, 1, 5, -6}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int max_sum = maxSubarray(arr, 0, n - 1); 
    cout << "Maximum contiguous sum is " << max_sum<<endl; 
    for (int i = left_index; i <=right_index; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    
    return 0; 
} 