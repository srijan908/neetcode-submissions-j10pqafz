class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> arr = new HashSet<>();
        for (int n : nums) {
            if (arr.contains(n)) return true;
            arr.add(n);
        }
        return false;
    }
}