import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Amazon_No1_Demo {

    public static List<String> processLogs(List<String> logs, int threshold) {
        Map<String, Integer> transactions = new HashMap<>();

        for(String log : logs) {
            String [] logCommand = log.split(" ");

            if(logCommand[0].equals(logCommand[1])) {
                int numOfTransactions = transactions.getOrDefault(logCommand[0], 0);
                transactions.put(logCommand[0], numOfTransactions+1);
            } else {
                int firstUserTransaction = transactions.getOrDefault(logCommand[0], 0);
                int secondUserTransaction = transactions.getOrDefault(logCommand[1], 0);
                transactions.put(logCommand[0], firstUserTransaction+1);
                transactions.put(logCommand[1], secondUserTransaction+1);
            }
        }

        List<String> ans = new ArrayList<>();
        Set<String> transactionsKey = transactions.keySet();
        for(String key : transactionsKey) {
            System.out.println("value: " + transactions.get(key));
            if(transactions.get(key) >= threshold) ans.add(key);
        }

        Collections.sort(ans);

        return ans;
    }
    
}
