#include <iostream>
int n, sum[40];
void print_terms(int left, int min = 0, int i = 0){
    if (left < 0 || min == n)
        return;
    sum[i] = min;
    if (min != 0)
    {
        print_terms(left - min, min, i + 1);
    }
    print_terms(left - 1, min + 1, i);
    if (left == 0)
    {
        for (int j = 0; j <= i; ++j)
            std::cout << sum[j] << (j != i ? '+' : '\n');
    }
        
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::cin >> n; 
    print_terms(n);
}
