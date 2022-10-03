public class LeetCode_Satisfiability_of_Equality_Equations {
    
    private int[] parent;

    public int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    public boolean merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        parent[u] = v;
        return true;
    }

    public boolean equationsPossible(String[] equations) {
        parent = new int[26];

        for(int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for(String equation : equations) {
            int char1 = equation.charAt(0) - 'a', char2 = equation.charAt(3) - 'a';
            boolean isEqual = equation.contains("==");

            if(isEqual) merge(char1, char2);
        }

        for(String equation : equations) {
            int char1 = equation.charAt(0) - 'a', char2 = equation.charAt(3) - 'a';
            boolean isEqual = equation.contains("==");

            if(!isEqual && (find(char1) == find(char2))) return false;
        }
        
        return true;
    }
}
