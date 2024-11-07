class Solution {
    public int longestSubarray(int[] nums) {
        int left = 0;
        int zeroCount = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.length; right++) {
            // Increase zeroCount if we encounter a zero
            if (nums[right] == 0) {
                zeroCount++;
            }

            // Shrink the window from the left if zeroCount exceeds 1
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Calculate max length of subarray containing only 1s after deleting one element
            maxLength = Math.max(maxLength, right - left);
        }

        return maxLength;
    }
}
