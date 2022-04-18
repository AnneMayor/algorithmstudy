import java.util.ArrayList;
import java.util.List;

public class LeetCode_RestoreIpAddresses {

    public List<String> ans;
    public List<String> restoreIpAddresses(String s) {
        ans = new ArrayList<>();
        recursiveSearch(s, s.length(), 0, new ArrayList<>());

        return ans;
    }
    

    public void recursiveSearch(String s, int sLen, int idx, List<String> temp) {
        if(temp.size() > 4) return ;
        if(idx == sLen && temp.size() == 4) {
            StringBuilder sb = new StringBuilder();

            int n = temp.size();
            for(int i = 0; i < n; i++) {
                if(temp.get(i).length() > 1 && temp.get(i).startsWith("0")) return ;
                sb.append(temp.get(i));
                if(i != n-1) sb.append(".");
            }

            ans.add(sb.toString());
            return ;
        }


        for(int i = idx; i < sLen; i++) {
            String subIp = s.substring(idx, i+1);
            if(subIp.length() >= 4) break;
            if(Integer.parseInt(subIp) >= 0 && Integer.parseInt(subIp) <= 255) {
                temp.add(subIp);
                recursiveSearch(s, sLen, i+1, temp);
                temp.remove(temp.size()-1);
            }
        }
    }
}