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

    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        //        restoreIpAddresses(s, 0, 0, new StringBuilder(), ans);

        if (s.length() > 12) return ans;

        for (int first = 1; first < 4; first++) {
            for (int second = 1; second < 4; second++) {
                for (int third = 1; third < 4; third++) {
                    for (int fourth = 1; fourth < 4; fourth++) {
                        if (first + second + third + fourth != s.length()) continue;

                        String firstIp = s.substring(0, first);
                        String secondIp = s.substring(first, first + second);
                        String thirdIp = s.substring(first + second, first + second + third);
                        String fourthIp = s.substring(first + second + third, first + second + third + fourth);

                        if (firstIp.length() > 1 && firstIp.startsWith("0")) break;
                        if (secondIp.length() > 1 && secondIp.startsWith("0")) break;
                        if (thirdIp.length() > 1 && thirdIp.startsWith("0")) break;
                        if (fourthIp.length() > 1 && fourthIp.startsWith("0")) break;

                        if (Integer.parseInt(firstIp) > 255 || Integer.parseInt(secondIp) > 255 || Integer.parseInt(thirdIp) > 255 || Integer.parseInt(fourthIp) > 255)
                            continue;

                        StringBuilder stringBuidler = new StringBuilder();

                        stringBuidler.append(firstIp);
                        stringBuidler.append(".");
                        stringBuidler.append(secondIp);
                        stringBuidler.append(".");
                        stringBuidler.append(thirdIp);
                        stringBuidler.append(".");
                        stringBuidler.append(fourthIp);
                        ans.add(stringBuidler.toString());
                    }
                }
            }
        }

        return ans;
    }

    public void restoreIpAddresses(String s, int index, int count, StringBuilder ips, List<String> ans) {

        if (count > 4) return ;
        if (count == 4 && index == s.length()) {
            ans.add(ips.toString());
            return ;
        }

        for (int i = 1; i < 4; i++) {
            if (index + i > s.length()) break;
            String ip = s.substring(index, index + i);
            if (ip.length() > 1 && ip.startsWith("0")) continue;
            if (i == 3 && Integer.parseInt(ip) > 255) continue;
            restoreIpAddresses(s, index + i, count + 1, ips.append(ip + (count == 3? "" : ".")), ans);
        }
    }
}