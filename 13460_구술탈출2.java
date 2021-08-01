import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main_13460 {

    static class Marble {
        int redX, redY, blueX, blueY; 
        int step;
    }

    public static String [][] map;
    public static int ans = -1;
    
    // 0: 위, 1: 아래, 2: 왼쪽, 3: 오른쪽

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] nAndm = br.readLine().split(" ");
        int n = Integer.parseInt(nAndm[0]);
        int m = Integer.parseInt(nAndm[1]);

        int redX = -1, redY = -1, blueX = -1, blueY = -1;
        int zeroX = -1, zeroY = -1;

        map = new String[n+1][m+1];
        for(int i = 0; i < n; i++) {
            map[i] = br.readLine().split("");
            for(int j = 0; j < m; j++) {
                if(map[i][j].equals("R")) {
                    redX = i;
                    redY = j;
                }
                if(map[i][j].equals("B")) {
                    blueX = i;
                    blueY = j;
                }
                if(map[i][j].equals("O")) {
                    zeroX = i;
                    zeroY = j;
                }   
            }
        }

        bfsSearch(redX, redY, blueX, blueY, n, m, zeroX, zeroY);

        System.out.println(ans);

        br.close();
    }

    public static void bfsSearch(int rX, int rY, int bX, int bY, int n, int m, int zX, int zY) {
        Queue<Main.Marble> q = new LinkedList<Main.Marble>();
        Marble mb = new Marble();
        mb.redX = rX; mb.redY = rY; mb.blueX = bX; mb.blueY = bY;
        mb.step = 0;
        q.add(mb);

        while(!q.isEmpty()) {
            // System.out.println("Size: " + q.size());
            mb = q.peek();
            q.remove();
            rX = mb.redX;
            rY = mb.redY;
            bX = mb.blueX;
            bY = mb.blueY;
            int step = mb.step;

            if(step > 10) {
                continue;
            }

            if(rX == zX && rY == zY) {
                ans = step;
                break;
            }

            // System.out.println("----------------------------");
            // System.out.println("Rx: " + rX + " / Ry: " + rY);
            // System.out.println("Bx: " + bX + " / By: " + bY);
            // System.out.println("Step: " + step);
            // System.out.println("----------------------------");

            map[rX][rY] = "R";
            map[bX][bY] = "B";

            for(int i = 0; i < 4; i++) {
                if(checkExit(bX, bY, n, m, i)) {
                    int finalPosition[] = moveBalls(rX, rY, bX, bY, n, m, i);
                    // System.out.println(finalPosition[0] + " " + finalPosition[1]);
                    // System.out.println(finalPosition[2] + " " + finalPosition[3]);
                    int nRx = finalPosition[0];
                    int nRy = finalPosition[1];
                    int nBx = finalPosition[2];
                    int nBy = finalPosition[3];
                    
                    mb = new Marble();
                    mb.redX = nRx;
                    mb.redY = nRy;
                    mb.blueX = nBx;
                    mb.blueY = nBy;
                    // System.out.println(mb.redX + " " + mb.redY);
                    // System.out.println(mb.blueX + " " + mb.blueY);
                    mb.step = step + 1;
                    q.offer(mb);
                }
            }

            map[rX][rY] = ".";
            map[bX][bY] = ".";
        }
    }

    public static boolean checkExit(int bx, int by, int n, int m, int dir) {
        boolean res = true;

        switch(dir) {
            // 위
            case 0:
                for(int i = bx; i >= 0; i--) {
                    if(map[i][by].equals("O")) {
                        res = false;
                        break;
                    } else if(map[i][by].equals("#")) break;
                }
            break;

            // 아래
            case 1:
                for(int i = bx; i < n; i++) {
                    if(map[i][by].equals("O")) {
                        res = false;
                        break;
                    } else if(map[i][by].equals("#")) break;
                }
            break;

            // 왼쪽
            case 2:
                for(int i = by; i >= 0; i--) {
                    if(map[bx][i].equals("O")) {
                        res = false;
                        break;
                    } else if(map[bx][i].equals("#")) break;
                }
            break;

            // 오른쪽
            case 3:
                for(int i = by; i < m; i++) {
                    if(map[bx][i].equals("O")) {
                        res = false;
                        break;
                    } else if(map[bx][i].equals("#")) break;
                }
            break;
        }

        return res;
    }

    public static int [] moveBalls(int rx, int ry, int bx, int by, int n, int m, int dir) {
        int [] res = new int[4];
        switch (dir) {
            // 위
            case 0:
                // 같은 선상에 위치할 때
                if(ry == by) {
                    // 빨간공이 파란공보다 앞에 있을 때
                    if(rx < bx) {

                        // 빨간공 먼저 움직이기
                        for(int i = rx-1; i >= 0; i--) {
                            if(map[i][ry].equals("O")) {
                                rx = i;
                                break;
                            } else if(map[i][ry].equals("#")) {
                                break;
                            }
                            rx = i;
                        }

                        // 파란공 움직이기
                        for(int i = bx-1; i > rx; i--) {
                            if(map[i][by].equals("#")) {
                                break;
                            }
                            bx = i;
                        }

                    } else {
                        // 파란공이 빨간공보다 앞에 있을 때

                        // 파란공 먼저 이동
                        for(int i = bx-1; i >= 0; i--) {
                            if(map[i][by].equals("#")) {
                                break;
                            }
                            bx = i;
                        }

                        // 빨간공 이동
                        for(int i = rx-1; i > bx; i--) {
                            if(map[i][ry].equals("O")) {
                                rx = i;
                                break;
                            } else if(map[i][ry].equals("#")) {
                                break;
                            }
                            rx = i;
                        }
                    }
                } else {

                    // 빨간공 이동
                    for(int i = rx-1; i >= 0; i--) {
                        if(map[i][ry].equals("O")) {
                            rx = i;
                            break;
                        } else if(map[i][ry].equals("#")) {
                            break;
                        }
                        rx = i;
                    }

                    // 파란공 이동
                    for(int i = bx-1; i >= 0; i--) {
                        if(map[i][by].equals("#")) {
                            break;
                        }
                        bx = i;
                    }
                }
            break;

            // 아래
            case 1:
                // 같은 선상에 위치할 때
                if(ry == by) {
                    // 빨간공이 파란공보다 앞에 있을 때
                    if(rx > bx) {

                        // 빨간공 먼저 움직이기
                        for(int i = rx+1; i < n; i++) {
                            if(map[i][ry].equals("O")) {
                                rx = i;
                                break;
                            } else if(map[i][ry].equals("#")) {
                                break;
                            }
                            rx = i;
                        }

                        // 파란공 움직이기
                        for(int i = bx+1; i < rx; i++) {
                            if(map[i][by].equals("#")) {
                                break;
                            }
                            bx = i;
                        }

                    } else {
                        // 파란공이 빨간공보다 앞에 있을 때

                        // 파란공 먼저 이동
                        for(int i = bx+1; i < n; i++) {
                            if(map[i][by].equals("#")) {
                                break;
                            }
                            bx = i;
                        }

                        // 빨간공 이동
                        for(int i = rx+1; i < bx; i++) {
                            if(map[i][ry].equals("O")) {
                                rx = i;
                                break;
                            } else if(map[i][ry].equals("#")) {
                                break;
                            }
                            rx = i;
                        }
                    }
                } else {

                    // 빨간공 이동
                    for(int i = rx+1; i < n; i++) {
                        if(map[i][ry].equals("O")) {
                            rx = i;
                            break;
                        } else if(map[i][ry].equals("#")) {
                            break;
                        }
                        rx = i;
                    }

                    // 파란공 이동
                    for(int i = bx+1; i < n; i++) {
                        if(map[i][by].equals("#")) {
                            break;
                        }
                        bx = i;
                    }
                }
            break;

            // 왼쪽
            case 2:
                // 같은 선상에 위치할 때
                if(rx == bx) {
                    // 빨간공이 파란공보다 앞에 있을 때
                    if(ry < by) {

                        // 빨간공 먼저 움직이기
                        for(int i = ry-1; i >= 0; i--) {
                            if(map[rx][i].equals("O")) {
                                ry = i;
                                break;
                            } else if(map[rx][i].equals("#")) {
                                break;
                            }
                            ry = i;
                        }

                        // 파란공 움직이기
                        for(int i = by-1; i > ry; i--) {
                            if(map[bx][i].equals("#")) {
                                break;
                            }
                            by = i;
                        }

                    } else {
                        // 파란공이 빨간공보다 앞에 있을 때

                        // 파란공 먼저 이동
                        for(int i = by-1; i >= 0; i--) {
                            if(map[bx][i].equals("#")) {
                                break;
                            }
                            by = i;
                        }

                        // 빨간공 이동
                        for(int i = ry-1; i > by; i--) {
                            if(map[rx][i].equals("O")) {
                                ry = i;
                                break;
                            } else if(map[rx][i].equals("#")) {
                                break;
                            }
                            ry = i;
                        }
                    }
                } else {

                    // 빨간공 이동
                    for(int i = ry-1; i >= 0; i--) {
                        if(map[rx][i].equals("O")) {
                            ry = i;
                            break;
                        } else if(map[rx][i].equals("#")) {
                            break;
                        }
                        ry = i;
                    }

                    // 파란공 이동
                    for(int i = by-1; i >= 0; i--) {
                        if(map[bx][i].equals("#")) {
                            break;
                        }
                        by = i;
                    }
                }
            break;

            // 오른쪽
            case 3:
                // 같은 선상에 위치할 때
                if(rx == bx) {
                    // 빨간공이 파란공보다 앞에 있을 때
                    if(ry > by) {

                        // 빨간공 먼저 움직이기
                        for(int i = ry+1; i < m; i++) {
                            if(map[rx][i].equals("O")) {
                                ry = i;
                                break;
                            } else if(map[rx][i].equals("#")) {
                                break;
                            }
                            ry = i;
                        }

                        // 파란공 움직이기
                        for(int i = by+1; i < ry; i++) {
                            if(map[bx][i].equals("#")) {
                                break;
                            }
                            by = i;
                        }

                    } else {
                        // 파란공이 빨간공보다 앞에 있을 때

                        // 파란공 먼저 이동
                        for(int i = by+1; i < m; i++) {
                            if(map[bx][i].equals("#")) break;
                            by = i;
                        }

                        // 빨간공 이동
                        for(int i = ry+1; i < by; i++) {
                            if(map[rx][i].equals("O")) {
                                ry = i;
                                break;
                            } else if(map[rx][i].equals("#")) break;
                            ry = i;
                        }
                    }
                } else {

                    // 빨간공 이동
                    for(int i = ry+1; i < m; i++) {
                        if(map[rx][i].equals("O")) {
                            ry = i;
                            break;
                        } else if(map[rx][i].equals("#")) break;
                        ry = i;
                    }

                    // 파란공 이동
                    for(int i = by+1; i < m; i++) {
                        if(map[bx][i].equals("#")) break;
                        by = i;
                    }
                }
            break;
        }

        // System.out.println("nRx: " + rx + " / nRy: " + ry + " / nBx: " + bx + " / nBy: " + by);

        res[0] = rx;
        res[1] = ry;
        res[2] = bx;
        res[3] = by;

        return res;
    }

}