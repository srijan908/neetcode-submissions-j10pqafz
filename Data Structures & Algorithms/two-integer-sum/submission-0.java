class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> st = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (st.containsKey(diff)) return new int[]{st.get(diff), i};
            st.put(nums[i], i);
        }
        return null;
    }
}
