import java.util.Hashtable;

public class Chapter1_ArraysAndStrings {

    public boolean isUnique(String s) {
        int checker = 0;
        int sLen = s.length();

        // lower case일 경우에만 가능.
        for(int i = 0; i < sLen; i++) {
            int charIndex = s.charAt(i) - 'a';
            if((checker & (1 << charIndex)) == 1) {
                return false;
            }

            checker |= (1 << charIndex);
        }

        return true;
    }

    public boolean checkPermutation(String s1, String s2) {

        int s1Len = s1.length(), s2Len = s2.length();

        if(s1Len != s2Len) return false;

        int [] checkCount = new int[128];
        for(int i = 0; i < s1Len; i++) {
            checkCount[s1.charAt(i)]++;
        }

        for(int i = 0; i < s2Len; i++) {
            checkCount[s2.charAt(i)]--;
        }

        for(int i = 0; i < 128; i++) {
            if(checkCount[i] > 0) return false;
        }

        return true;
    }

    public char[] URLify(char[] str, int trueLength) {
        int characterCount = 0;
        int strLen = str.length;
        for(int i = 0; i < strLen; i++) {
            if(str[i] != ' ') {
                characterCount++;
            }
        }

        int spaceCount = trueLength - characterCount;

        boolean isDeleted = false;

        char[] res = new char[trueLength+spaceCount*3+1];
        int resIndex = 0;

        System.out.println(spaceCount);

        for(int i = 0; i < strLen; i++) {
            if(str[i] == ' ') {
                if(!isDeleted) {
                    if(spaceCount > 0) {
                        isDeleted = true;
                        spaceCount--;
                        res[resIndex++] = '%';
                        res[resIndex++] = '2';
                        res[resIndex++] = '0';
                    }  
                }
            } else {
                System.out.println("i: " + i);
                if(isDeleted) isDeleted = false;
                res[resIndex++] = str[i];
            }
        }

        return res;
    }

    public boolean isPalindromePermutation(String s) {
        
        int bitVector = createBitVector(s);

        return (bitVector == 0) || ((bitVector & (bitVector - 1)) == 0);
    }

    public int createBitVector(String s) {
        int bitVector = 0;

        int sLen = s.length();
        for(int i = 0; i < sLen; i++) {
            int character = s.charAt(i);
            if(character == ' ') continue;
            int mask = 1 << character;
            if((bitVector & mask) == 0) {
                bitVector |= mask;
            } else {
                bitVector &= ~mask;
            }
        }

        return bitVector;
    }

    public boolean oneWay(String s1, String s2) {

        int s1Len = s1.length(), s2Len = s2.length();
        int s1Index = 0, s2Index = 0;

        if(s1Len != s2Len) {
            int diffCount = 0;
            while(s1Index < s1Len && s2Index < s2Len) {
                if(s1.charAt(s1Index) == s2.charAt(s2Index)) {
                    if(s1Len > s2Len) {
                        s2Index++;
                    } else {
                        s1Index++;
                    }
                } else {
                    if(diffCount > 1) return false;
                    diffCount++;
                    if(s1Len > s2Len) {
                        s1Index++;
                    } else {
                        s2Index++;
                    }
                }

                System.out.println(x);
            }
        } else {
            int diffCount = 0;
            while(s1Index < s1Len && s2Index < s2Len) {
                if(s1.charAt(s1Index) != s2.charAt(s2Index)) {
                    if(diffCount < 1) {
                        diffCount++;
                    } else {
                        return false;
                    }
                }

                s1Index++;
                s2Index++;
            }
        }

        return true;
    }

    public int[][] rotateMatrix(int[][] image) {
        return image;
    }

    public void zeroMatrix(int[][] matrix) {

    }

    public void stringRotation(String s1, String s2) {

    }
    

    public static void main(String...args) {
        Chapter1_ArraysAndStrings chapter1 = new Chapter1_ArraysAndStrings();
        char [] test = {'H','i',' ', ' ', ' ', ' ', 'A', 'n', 'n','e','!', ' ', ' ', ' ', ' '};
        char [] test1 = {'M', 'r', ' ', 'J', 'o', 'h', 'n', ' ', 'S', 'm', 'i', 't', 'h',' ', ' ', ' ', ' ', ' ', ' '};
        System.out.println(chapter1.URLify(test, 8));
        System.out.println(chapter1.URLify(test1, 13));

        System.out.println(chapter1.isUnique("aab"));
        System.out.println(chapter1.checkPermutation("abc", "cba"));
        System.out.println(chapter1.isPalindromePermutation("ab cc"));
        System.out.println(chapter1.oneWay("pale", "pal"));
        System.out.println(chapter1.oneWay("pales", "pale"));
        System.out.println(chapter1.oneWay("bale", "pale"));
        System.out.println(chapter1.oneWay("bales", "pale"));
    }
}
