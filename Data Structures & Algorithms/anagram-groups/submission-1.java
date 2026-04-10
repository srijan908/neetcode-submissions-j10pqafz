class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> mp = new HashMap<>();
        for (String s : strs) {
            int[] arr = new int[26];
            StringBuilder st = new StringBuilder();
            for (char c : s.toCharArray()) {
                arr[c - 'a']++;
            }
            for (int i : arr) {
                st.append(i).append(',');
            }
            List<String> cur = mp.get(st.toString());
            if (cur == null) {
                cur = new ArrayList<>();
            }
            cur.add(s);
            mp.put(st.toString(), cur);
        }
        List<List<String>> ans = new ArrayList<>();
        for (Map.Entry<String, List<String>> entry : mp.entrySet()) {
            ans.add(entry.getValue());
        }
        return ans;
    }
}
