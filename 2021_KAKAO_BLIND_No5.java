import java.util.ArrayList;
import java.util.List;

// 방문 순서가 중요하지 않은 문제라고 한다...기억해야지!
public class Solution {
    public int answer;
    public ArrayList<ArrayList<Integer> > edgeList;
    public int[] infoList;
    public int solution(int[] info, int[][] edges) {
        answer = 0;

        ArrayList<Integer> currentLeftChildren = new ArrayList<>();
        currentLeftChildren.add(0);
        infoList = info;

        edgeList = new ArrayList<>();
        int n = edges.length;
        int m = info.length;
        for(int i = 0; i < m; i++) {
            edgeList.add(new ArrayList<>());
        }
        
        for(int i = 0; i < n; i++) {
            edgeList.get(edges[i][0]).add(edges[i][1]);
        }

        dfsSearch(0, 0, 0, currentLeftChildren);

        return answer;
    }

    public void dfsSearch(int current, int sheep, int wolf, List<Integer> children) {
        sheep += infoList[current] ^ 1;
        wolf += infoList[current];

        if(sheep <= wolf) return ;

        answer = Math.max(sheep, answer);

        List<Integer> nextChildren = new ArrayList<>();
        nextChildren.addAll(children);

        // 와...
        nextChildren.remove(Integer.valueOf(current));
        for(int child : edgeList.get(current)) {
            nextChildren.add(child);
        }

		for (int next : nextChildren) {
			dfsSearch(next, sheep, wolf, nextChildren);
		}
    }
}