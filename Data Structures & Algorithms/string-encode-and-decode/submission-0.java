class Solution {

    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < strs.size(); i++) {
            sb.append(strs.get(i));
            sb.append("-*-");
        }
        return sb.toString();
    }

    public List<String> decode(String str) {
        List<String> ans = new ArrayList<>();
        char[] chars = str.toCharArray();
        StringBuilder sb = new StringBuilder();
        int n = chars.length;
        for (int i = 0; i < n; i++) {
            if (chars[i] == '-' && i + 2 < n && (chars[i + 1] == '*' && chars[i + 2] == '-')) {
                ans.add(sb.toString());
                sb = new StringBuilder();
                i += 2;
            } else {
                sb.append(chars[i]);
            }
        }
        return ans;
    }
}
