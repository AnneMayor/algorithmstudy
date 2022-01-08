import java.util.*;

class AlgoExpert_tandemBicycle {

  public int tandemBicycle(int[] redShirtSpeeds, int[] blueShirtSpeeds, boolean fastest) {

    Arrays.sort(redShirtSpeeds);
    Arrays.sort(blueShirtSpeeds);

    int n = redShirtSpeeds.length;

    if(!fastest) {
        reverseOrder(redShirtSpeeds);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int redShirtSpeed = redShirtSpeeds[i];
        int blueShirtSpeed = blueShirtSpeeds[n-i-1];
        ans += Math.max(redShirtSpeed, blueShirtSpeed);
    }

    return ans;
  }

  public void reverseOrder(int[] array) {
      int start = 0;
      int end = array.length - 1;

      while(start < end) {
          int temp = array[start];
          array[start] = array[end];
          array[end] = temp;
          start++;
          end--;
      }
  }
}
