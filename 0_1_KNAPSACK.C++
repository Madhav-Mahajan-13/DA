#include<iostream>
using namespace std;

int knapsack(int w[],int v[],int n ,int c){
    int table[n+1][c+1];
    for (int j = 0; j <= c;j++){
        table[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for (int j = 0; j <= c;j++){
            if(w[i]>j){
                table[i][j]=table[i-1][j];
            }else{
                table[i][j]=  (v[i] +table[i-1][j-w[i]]) >= table[i-1][j] ?  (v[i] +table[i-1][j-w[i]]) :  table[i-1][j];
            }

        }        
    }
    cout<<"the max value of knap sack is --"<<table[n][c]<<endl;
    cout<<"the item taken are -- ";

     int j=c;
    for (int  i = n;i>=1; i--)
    {
        if(table[i][j]>table[i-1][j]){
            cout<<"item"<<i+1<<" ";
            j=j-w[i];
        }
    }
    

    
}

int main() 
{ 
    int profit[] = { 60, 100, 120 }; 
    int weight[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(profit) / sizeof(profit[0]); 
    knapsack(weight,profit,n,W);
    return 0; 
}