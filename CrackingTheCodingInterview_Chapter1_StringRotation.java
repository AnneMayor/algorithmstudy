public class CrackingTheCodingInterview_Chapter1_StringRotation {

    public boolean isRotation(String s1, String s2) {

        if(s1.length() != s2.length()) return false;

        if(s1.isEmpty() || s2.isEmpty() || s1 == null || s2 == null) return false;

        StringBuilder sb = new StringBuilder(s1);
        sb.append(s1);

        return isSubString(sb.toString(), s2);
    }

    public boolean isSubString(String s1, String s2) {
        return s1.contains(s2);
    }
}
