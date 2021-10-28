import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;

public class Main_4386 {

    public static double [] weights;
    public static int [] parent;
    public static ArrayList<ArrayList<Star> > stars;
    public static boolean [] isVisited;

    static class Point {
        double x;
        double y;
        int nodeNum;

        public Point(double x, double y, int nodeNum) {
            this.x = x;
            this.y = y;
            this.nodeNum = nodeNum;
        }
    }

    static class Star implements Comparable<Star> {
        double dist;
        int num;

        public Star(double dist, int num) {
            this.dist = dist;
            this.num = num;
        }

        @Override
        public int compareTo(Main.Star s) {
            return Double.compare(dist, s.dist);
        }
    }

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        ArrayList<Point> points = new ArrayList<>();
        stars = new ArrayList<>();
        isVisited = new boolean[n+1];

        for(int i = 0; i <= n; i++) {
            stars.add(new ArrayList<>());
        }

        Arrays.fill(isVisited, false);

        for(int i = 0; i < n; i++) {
            String [] xy = br.readLine().split(" ");
            double x = Double.parseDouble(xy[0]);
            double y = Double.parseDouble(xy[1]);

            Point p = new Point(x, y, i);
            points.add(p);
        }

        calculateAllStarts(points);

        DecimalFormat format = new DecimalFormat("#.##");

        System.out.println(format.format(primMst(0)));
    }

    public static double primMst(int start) {
        double res = 0D;
        
        PriorityQueue<Star> pq = new PriorityQueue<>();
        isVisited[start] = true;
        
        for(int i = 0; i < stars.get(start).size(); i++) {
            pq.add(stars.get(start).get(i));
        }

        while(!pq.isEmpty()) {

            Star currentStar = pq.poll();

            if(!isVisited[currentStar.num]) {
                isVisited[currentStar.num] = true;
                res += currentStar.dist;

                for(int i = 0; i < stars.get(currentStar.num).size(); i++) {
                    Star nextStar = stars.get(currentStar.num).get(i);

                    if(!isVisited[nextStar.num]) {
                        pq.add(nextStar);
                    }
                }
            }
        }
        
        return res;
    }

    public static void calculateAllStarts(ArrayList<Point> p) {

        int n = p.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                Point p1 = p.get(i); Point p2 = p.get(j);

                double xDist = Math.abs(p1.x - p2.x);
                double yDist = Math.abs(p1.y - p2.y);
                double dist = Math.sqrt(xDist * xDist + yDist * yDist);
                stars.get(p1.nodeNum).add(new Star(dist, p2.nodeNum));
                stars.get(p2.nodeNum).add(new Star(dist, p1.nodeNum));
            }
        }
    }

}