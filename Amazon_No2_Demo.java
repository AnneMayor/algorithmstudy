import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Amazon_No2_Demo {
    public static int [] groupNumber;

    static class Point {

        int start;
        int end;
        int numOfGroup;

        public Point(int start, int end, int numOfGroup) {
            this.start = start;
            this.end = end;
            this.numOfGroup = numOfGroup;
        }

    }

    public static int countGroups(List<String> related) {
        int n = related.size();
        int [][] relations = new int[n][n];
        groupNumber = new int[n];

        Arrays.fill(groupNumber, -1);

        for(int i = 0; i < n; i++) {
            String [] relation = related.get(i).split("");
            for(int j = 0; j < n; j++) {
                relations[i][j] = Integer.parseInt(relation[j]);
            }
        }

        int startingGroupNumber = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && relations[i][j] == 1) {
                    findOtherMember(i, j, startingGroupNumber, relations);
                    startingGroupNumber++;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            System.out.print(groupNumber[i] + " ");
        }
        
        return 0;
    }

    public static void findOtherMember(int x, int y, int numberOfGroup, int [][] relations) {
        groupNumber[x] = numberOfGroup;
        groupNumber[y] = numberOfGroup;

        int n = relations.length;
        Queue<Point> q = new LinkedList<>();

        q.add(new Point(x, y, numberOfGroup));
        
        while(!q.isEmpty()) {

            Point current = q.poll();

            int first = current.start;
            int second = current.end;
            numberOfGroup = current.numOfGroup;

            for(int i = 0; i < n; i++) {

                if(i != first && relations[first][i] == 1 && groupNumber[i] == -1) {
                    groupNumber[i] = numberOfGroup;
                    q.add(new Point(first, i, numberOfGroup));
                }

                if(i != second && relations[second][i] == 1 && groupNumber[i] == -1) {
                    groupNumber[i] = numberOfGroup;
                    q.add(new Point(second, i, numberOfGroup));
                }
            }

        }
    }
}
