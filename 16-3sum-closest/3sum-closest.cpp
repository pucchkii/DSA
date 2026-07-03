class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int answer = nums[0] + nums[1] + nums[2];
        int n = nums.size();

        for (int first = 0; first < n - 2; first++) {
            int low = first + 1;
            int high = n - 1;

            while (low < high) {
                int current = nums[first] + nums[low] + nums[high];

                if (abs(target - current) < abs(target - answer)) {
                    answer = current;
                }

                if (current == target) {
                    return target;
                }

                if (current < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }

        return answer;
    }
};