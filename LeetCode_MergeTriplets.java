public class LeetCode_MergeTriplets {
    // production level extensible code
    // public boolean mergeTriplets(int[][] triplets, int[] target) {
    //     int[] finalTriplet = new int[3];
        
    //     for(int[] triplet : triplets) {
    //         boolean canCompare = true;

    //         for(int i = 0; i < 3; i++) {
    //             if(triplet[i] > target[i]) {
    //                 canCompare = false;
    //                 break;
    //             }
    //         }

    //         if(canCompare) {
    //             for(int i = 0; i < 3; i++) {
    //                 finalTriplet[i] = Math.max(triplet[i], finalTriplet[i]);
    //             }
    //         }
    //     }

    //     boolean res = true;
    //     for(int i = 0; i < 3; i++) {
    //         if(finalTriplet[i] != target[i]) {
    //             res = false;
    //             break;
    //         }
    //     }

    //     return res;
    // }

    // optimized performance code
    public boolean mergeTriplets(int[][] triplets, int[] target) {
        boolean xFound = false, yFound = false, zFound = false;
        
        for(int[] triplet : triplets) {

            if(triplet[0] == target[0] && triplet[1] == target[1] && triplet[2] == target[2]) return true;

            if(triplet[0] == target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                xFound = true;
            }
            if(triplet[1] == target[1] && triplet[0] <= target[0] && triplet[2] <= target[2]) {
                yFound = true;
            }
            if(triplet[2] == target[2] && triplet[0] <= target[0] && triplet[1] <= target[1]) {
                zFound = true;
            }
        }

        return xFound && yFound && zFound;
    }
}
