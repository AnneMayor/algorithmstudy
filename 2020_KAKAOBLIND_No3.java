public class Solution {
    public boolean solution(int[][] key, int[][] lock) {
        boolean answer = false;

        int n = lock.length;
        int m = key.length;

        for(int i = 0; i < n*3-m; i++) {
            for(int j = 0; j < n*3-m; j++) {
                for(int cnt = 0; cnt < 4; cnt++) {
                    key = rotateKey(key, m);
                    int [][] verifyLock = resetLock(lock, n);
                    for(int x = 0; x < m; x++) {
                        for(int y = 0; y < m; y++) {
                            verifyLock[i+x][j+y] += key[x][y];
                        }
                    }

                    answer = isOpen(verifyLock, n);

                    if(answer) return answer;
                }
            }
        }

        return answer;
    }

    public int[][] rotateKey(int[][] key, int m) {
        int[][] res = new int[m][m];

        for(int j = 0; j < m; j++) {
            for(int i = 0; i < m; i++) {
                res[j][i] = key[m-i-1][j];
            }
        }

        return res;
    }

    public int[][] resetLock(int[][] lock, int n) {
        int [][] res = new int[n*3][n*3];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                res[i+n][j+n] = lock[i][j];
            }
        }

        return res;
    }

    public boolean isOpen(int[][] lock, int n) {
        boolean res = true;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(lock[i+n][j+n] == 0 || lock[i+n][j+n] == 2) {
                    res = false;
                    break;
                }
            }

            if(!res) break;
        }

        return res;
    }
}