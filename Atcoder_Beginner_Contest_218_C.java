import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Atcoder_Beginner_Contest_218_C {

    public static String [][] s;
    public static String [][] t;

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        s = new String[n+1][n+1];
        t = new String[n+1][n+1];

        for(int i = 0; i < n; i++) {
            s[i] = br.readLine().split("");
        }

        for(int i = 0; i < n; i++) {
            t[i] = br.readLine().split("");
        }

        boolean check = false;
        // 90도씩 360도 회전
        for(int i = 0; i < 4; i++) {
            rotate(n);
            // System.out.println("i:" + i + " / check: " + check);
            check = isMatch(n);
            if(check) break;
        }

        if(check) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static void rotate(int n) {
        String [][] temp = new String[n+1][n+1];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[i][j] = s[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                s[j][n-i-1] = temp[i][j];
            }
        }
    }

    public static boolean isMatch(int n) {
        boolean res = true;
        // System.out.println("----------------------------------------");
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         System.out.print(s[i][j]);
        //     }
        //     System.out.println();
        // }
        // System.out.println("----------------------------------------");
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         System.out.print(t[i][j]);
        //     }
        //     System.out.println();
        // }
        // System.out.println("----------------------------------------");

        // 1. 완전 같은지 체크
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!s[i][j].equals(t[i][j])) {
                    res = false;
                    break;
                }
            }
            if(!res) break;
        }

        // System.out.println("res: " + res);

        if(res) return res;

        res = true;
        // 2. 평행이동 시 같은지 체크

        int minHeightS = n;
        int maxHeightS = -1;
        int minWidthS = n;
        int maxWidthS = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(s[i][j].equals("#")) {
                    minHeightS = Math.min(minHeightS, i);
                    maxHeightS = Math.max(maxHeightS, i);
                    minWidthS = Math.min(minWidthS, j);
                    maxWidthS = Math.max(maxWidthS, j);
                }
            }
        }

        int minHeightT = n;
        int maxHeightT = -1;
        int minWidthT = n;
        int maxWidthT = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(t[i][j].equals("#")) {
                    minHeightT = Math.min(minHeightT, i);
                    maxHeightT = Math.max(maxHeightT, i);
                    minWidthT = Math.min(minWidthT, j);
                    maxWidthT = Math.max(maxWidthT, j);
                }
            }
        }

        int heightS = maxHeightS - minHeightS + 1;
        int widthS = maxWidthS - minWidthS + 1;
        int heightT = maxHeightT - minHeightT + 1;
        int widthT = maxWidthT - minWidthT + 1;

        // System.out.println("hS: " + heightS + " / wS: " + widthS + " / hT: " + heightT + " / wT: " + widthT);

        if(heightS == heightT && widthS == widthT) {
            for(int i = minHeightS; i < minHeightS + heightS; i++) {
                for(int j = minWidthS; j < minWidthS + widthS; j++) {
                    int p = i - minHeightS, q = j - minWidthS;
                    // System.out.println("i: " + i + " / j: " + j);
                    // System.out.println("minHeightT: " + minHeightT + " / minWidthT: " + minWidthT);
                    // System.out.println(s[i][j] + " / " + t[minHeightT + p][minWidthT+q]);
                    if(!s[i][j].equals(t[minHeightT + p][minWidthT + q])) {
                        // System.out.println("here!");
                        return false;
                    }
                }
            }
        } else res = false;


        return res;
    }
    
}
