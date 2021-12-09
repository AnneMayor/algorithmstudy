public class 프로그래머스_124나라의숫자 {

    public String solution(int n) {
        StringBuilder sb = new StringBuilder();

        // 1: 3*n + 1
        // 2: 3*n + 2
        // 4: 3*n
        while(n > 0) {
            int r = n%3;
            int q = n/3; 
            switch(r) {
                case 0:
                    sb.append(4);
                    q--;
                    break;

                case 1:
                    sb.append(1);   
                    break;

                case 2:
                    sb.append(2);
                    break;
            }
            n = q;
        }

        return sb.reverse().toString();
    }
    
}
