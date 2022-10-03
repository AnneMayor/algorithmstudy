public class Solution {
    public String pushDominoes(String dominoes) {
        int[] rightForces = new int[dominoes.length()];
        int[] leftForces = new int[dominoes.length()];
        int n = dominoes.length();

        // left to right

        if(dominoes.charAt(0) == 'R') rightForces[0] = n;
        for(int i = 1; i < n; i++) {
            if(dominoes.charAt(i) == 'R') {
                rightForces[i] = n;
            } else if(dominoes.charAt(i) == 'L') rightForces[i] = 0;
            else if(rightForces[i-1] > 0) rightForces[i] = rightForces[i-1] - 1;
        }

        // right to left
        if(dominoes.charAt(n-1) == 'L') leftForces[n-1] = -n;
        for(int i = n-2; i >= 0; i--) {
            if(dominoes.charAt(i) == 'L') leftForces[i] = -n;
            else if(dominoes.charAt(i) == 'R') leftForces[i] = 0;
            else if(leftForces[i+1] < 0) leftForces[i] = leftForces[i+1] + 1;
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++) {
            int totalForce = leftForces[i] + rightForces[i];
            if(totalForce > 0) sb.append("R");
            else if(totalForce < 0) sb.append("L");
            else sb.append(".");
        }

        return sb.toString();
    }    
}
