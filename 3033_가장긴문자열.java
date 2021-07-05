import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

public class Main {

    public static int MAX = 200001;
    public static long MOD = 13245678976553L;
    static long[] hashArr = new long[MAX+1];
    static String st;

    public static boolean check(int value, int T) {
        Set<Long> group = new HashSet<>();
        long h = 0L;
        for(int i = 0; i < value; ++i) {
            h += st.charAt(i) * hashArr[value-1-i];
            h %= MOD;
        }
        group.add(h);
        
        for(int i = value; i  < T; ++i) {
            h = 2*h-(st.charAt(i-value)*hashArr[value]%MOD) + st.charAt(i);
            h %= MOD;
            if(h < 0) h += MOD;
            group.add(h);        }

        return (group.size() != T-value+1);
    }
    
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        st = br.readLine();

        hashArr[0] = 1;
        
        // 해시값 초기화
        for(int i = 1; i < MAX; ++i) {
            hashArr[i] = (hashArr[i-1]*2) % MOD;
        }

        int l = 1, r = T;
        while(l+1 < r) {
            int mid = (l+r) >> 1;
            if(check(mid, T)) l = mid;
            else r = mid;
        }

        if(l != 1) System.out.println(l);
        else {
            if(check(1, T)) System.out.println(1);
            else System.out.println(0);
        }
    }
}