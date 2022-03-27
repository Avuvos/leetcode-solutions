

int subtractProductAndSum(int n){
    int prod = 1;
    int sum = 0;
    int dig;
    
    while (n > 0) {
        dig = n % 10;
        prod *= dig;
        sum += dig;
        n /= 10;
    }
    
    return prod - sum;
}
