import java.util.Hashtable;

class Solution {
    
    public Hashtable<String, String> userTable;
    
    public String[] solution(String[] record) {
        int cntOfAns = 0;
        String[] answer;
        userTable = new Hashtable<String, String>();
        int len = record.length;
        for(int i = 0; i < len; i++) {
            String[] command = record[i].split(" ");
            if(command[0].equals("Enter")) {
                cntOfAns++;
                userTable.put(command[1], command[2]);
            } else if(command[0].equals("Change")) {
                userTable.put(command[1], command[2]);
            } else {
                cntOfAns++;
            }
        }
        
        answer = new String[cntOfAns];
        int ansIdx = 0;
        for(int i = 0 ; i < len; i++) {
            String[] command = record[i].split(" ");
            if(command[0].equals("Enter")) {
                answer[ansIdx++] = userTable.get(command[1])+"님이 들어왔습니다.";
            } else if(command[0].equals("Leave")) {
                answer[ansIdx++] = userTable.get(command[1])+"님이 나갔습니다.";
            }
        }
        return answer;
    }
}