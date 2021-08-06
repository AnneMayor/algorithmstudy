import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_1259 {
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true) {

            boolean isPelindrom = true;
            String numArr = br.readLine();
            if(numArr.equals("0")) break;
            int start = 0;
            int end = numArr.length() - 1;
            
            for(; start < numArr.length() / 2; start++) {
                if(numArr.charAt(start) != numArr.charAt(end-start)) {
                    isPelindrom = false;
                    break;
                }          
            }

            if(isPelindrom) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }

        br.close();
    }
}
