import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;

public class A {
    public Long[] solution(String[] record) {
        Long [] answer = new Long[2];
        Deque<Long> prePrice = new LinkedList<>();
        Deque<Long> suffPrice = new LinkedList<>();

        Long preTotalPrice = 0L;
        Long suffTotalPrice = 0L;

        for(String log : record) {
            String [] logs = log.split(" ");
            switch(logs[0]) {
                case "P":
                Long price = Long.parseLong(logs[1]);
                int pCount = Integer.parseInt(logs[2]);
                for(int i = 0; i < pCount; i++) {
                    prePrice.push(price);
                    suffPrice.push(price);
                }
                break;
                case "S":
                int sCount = Integer.parseInt(logs[2]);
                // System.out.println("preSize: " + prePrice.size() + " , sufSize: " + suffPrice.size());
                for(int i = 0; i < sCount; i++) {
                    
                    if(!prePrice.isEmpty() && !suffPrice.isEmpty()){
                        preTotalPrice += prePrice.pollLast();
                        suffTotalPrice += suffPrice.pollFirst();
                    }
                }
                
                break;
            }
        }

        answer[0] = preTotalPrice;
        answer[1] = suffTotalPrice;

        return answer;
    }
}