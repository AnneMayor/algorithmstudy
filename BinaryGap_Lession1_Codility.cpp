const int MAX = 40;

int cntOfBit[MAX];

int solution(int N) {
    
    int idx = 0;
    while(N > 1) {
        cntOfBit[idx++] = N % 2;
        N /= 2;
    }
    
    cntOfBit[idx++] = N;
    
    int ret = 0;
    int tmp = 0;
    int cntOfOne = 0;
    for(int i = idx-1; i >= 0; i--) {
        if(cntOfBit[i] == 1) {
            cntOfOne++;
            if(cntOfOne >= 2) {
                cntOfOne = 1;
                if(ret < tmp) ret = tmp;
                tmp = 0;
            }
        } else {
            tmp++;
        }
   }
   
   return ret;
}