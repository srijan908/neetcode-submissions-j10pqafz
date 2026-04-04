class Solution {
    public boolean isAnagram(String s, String t) {
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        if (s.length() != t.length()) return false;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            cnt1[s.charAt(i) - 'a']++;
            cnt2[t.charAt(i) - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }
}
