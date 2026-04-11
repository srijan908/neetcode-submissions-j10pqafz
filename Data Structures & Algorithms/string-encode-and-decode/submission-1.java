class Solution {

    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < strs.size(); i++) {
            String cur = strs.get(i);
            sb.append(cur.length() + "#");
            sb.append(cur);
        }
        return sb.toString();
    }

    public List<String> decode(String str) {
        if (str.length() == 2) {
            return List.of("");
        }
        List<String> ans = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        int n = str.length(), i = 0;
        while (i < n) {
            int j = i;
            while (j < n && str.charAt(j) != '#') {
                j++;
            }
            int len = Integer.parseInt(str.substring(i, j));
            ans.add(str.substring(j + 1, j + 1 + len));
            i = j + len + 1;
        }

        return ans;
    }
}
