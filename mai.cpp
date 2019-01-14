//#include <stdio.h>

#include <iostream>
using namespace std;


int Sum(int *a, int N);//находим сумму чисел в массиве
 
void MakeShift(int *a, int N, int i);//сдвигаем массив на один с i-го места
void Zero(int *a, int N, int j);//обнуление массива с i-го места
void PrintArray(int *a, int N);
 
void function(int *a, int s, int N, int j);
 
 
int main(){
   
    int N;
    cin >> N;
   
    int *a = new int[N];
    int i;
   
    function(a, N, N, 0);
   
   
   
   
}
 
int Sum(int *a, int N){
   
    int res;
    res = 0;
    int i;
    for(i = 0; i < N; i++)
        res = res + a[i];
 
    return res;
   
}
 
void Zero(int *a, int N, int j){
   
    int i;
    for(i = j; i < N; i++)
        a[i] = 0;
   
}
 
void PrintArray(int *a, int N){
    //printf("%d", a[0]);
    cout << a[0];
    
    int i;
    for(i = 1; i < N; i++){
        if(a[i] != 0){
            //printf("+%d", a[i]);
            cout << "+" << a[i];
        
        }
    }
     //printf("\n");
    cout << endl;
}
 
bool Big(int *a, int N, int j){
    int i; bool b;
    //b = true;
    for(i = 0; i < j; i++){
        if(a[i] < a[i + 1]){
            // b = false;
            return false;
        }
    }
    return true;
}
   
void function(int *a, int s, int N, int j){
   
    int res;
    int i;
   
    for( i = s - 1; i >= 1; i--){
       
        a[j] = i;
        res = N - Sum(a, N);
        a[j + 1] = res;
        if(Big(a, N, j + 1)){
            PrintArray(a, N);
        }
        if(res > 1){
            a[j + 1] = 0;
            function(a, res, N, j + 1);
        }
       
        Zero(a, N, j );
       
    }
       
           
           
   
       
}
       
       
           
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
