int solution(int A, int B) {

    int total = A*B;
    
    int ans = 0;
    while (total)
    {
        if(total&1) {
            ans++;
        }
        total >>= 1;
    }
    
    return ans;

}