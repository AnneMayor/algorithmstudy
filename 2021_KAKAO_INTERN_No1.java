import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    class Point {
        int x;
        int y;
        int dist;
        
        public Point(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }

    public int[] dx = {1, -1, 0, 0};
    public int[] dy = {0, 0, -1, 1};

    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        for(int i = 0; i < 5; i++) {
            String[] place = places[i];
            String[][] placeMap = new String[5][5];
            for(int x = 0; x < 5; x++) {
                for(int y = 0; y < 5; y++) {
                    placeMap[x][y] = String.valueOf(place[x].charAt(y));
                }
            }

            Boolean isGood = true;
            for(int p = 0; p < 5; p++) {
                for(int q = 0; q < 5; q++) {
                    if(placeMap[p][q].equals("P")) {
                        isGood = searchAround(p, q, placeMap);
                        if(!isGood) break;
                    }
                }
                if(!isGood) break;
            }


            if(isGood) answer[i] = 1;
            else answer[i] = 0;
        }
        return answer;
    }

    public boolean searchAround(int x, int y, String[][] placeMap) {
        boolean res = true;

        boolean[][] isVisited = new boolean[5][5];

        isVisited[x][y] = true;

        Queue<Point> q = new LinkedList<>();
        q.add(new Point(x, y, 0));

        while(!q.isEmpty()) {
            Point currentPos = q.poll();

            if(placeMap[currentPos.x][currentPos.y].equals("P")) {
                System.out.println("x: " + currentPos.x + " , y: " + currentPos.y + " , dist: " + currentPos.dist);
                if(currentPos.dist > 0 && currentPos.dist <= 2) {
                    res = false;
                    return res;
                }
            }

            for(int idx = 0; idx < 4; idx++) {
                int nx = currentPos.x + dx[idx];
                int ny = currentPos.y + dy[idx];

                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

                if(!isVisited[nx][ny]) {
                    isVisited[nx][ny] = true;
                    if(placeMap[nx][ny].equals("O") || placeMap[nx][ny].equals("P")) {
                        q.add(new Point(nx, ny, currentPos.dist+1));
                    }
                }
            }
        }


        return res;
    }

    public static void main(String...args) {
        String[][] test = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}};
        
        Solution sol = new Solution();
        System.out.println(sol.solution(test)[0]);
    }
}
