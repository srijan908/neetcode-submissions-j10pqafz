class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos = -1, num = INT_MAX;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] < nums[r]) {
                if (nums[l] < num) {
                    pos = l;
                    num = nums[l];
                }
                break;
            } 
            int mid = l + (r - l) / 2;
            if (nums[mid] < num) {
                num = nums[mid];
                pos = mid;
            }
            if (nums[l] <= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout<<num<<" "<<pos;
        if (target == num) {
            return pos;
        } else if (target > num and target <= nums[nums.size() - 1]) {
            l = pos + 1, r = nums.size() - 1;
        } else {
            l = 0, r = pos - 1;
        }
        // cout<<l<<" "<<r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
