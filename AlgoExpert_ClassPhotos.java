import java.util.*;

class Program {

  public boolean classPhotos(ArrayList<Integer> redShirtHeights, ArrayList<Integer> blueShirtHeights) {
		Collections.sort(redShirtHeights);
		Collections.sort(blueShirtHeights);

    // for(int red : redShirtHeights) {
    //     System.out.println(red);
    // }

    int firstRow = redShirtHeights.get(0) < blueShirtHeights.get(0) ? 1 : 2; // 1 : red, 2 : blue
    int n = redShirtHeights.size();
    boolean res = true;
    if(firstRow == 1) {
        
        for(int i = 0; i < n; i++) {
            if(redShirtHeights.get(i) >= blueShirtHeights.get(i)) {
                res = false;
                break;
            }
        }
    } else {
        for(int i = 0; i < n; i++) {
            if(redShirtHeights.get(i) <= blueShirtHeights.get(i)) {
                res = false;
                break;
            }
        }
    }

    return res;
  }
}
