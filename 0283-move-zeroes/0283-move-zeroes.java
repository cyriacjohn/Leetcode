class Solution {
    public void moveZeroes(int[] nums) {
        int nonZeroFoundAt = 0;

       for(int i = 0; i<nums.length; i++) {
        if(nums[i]!=0){
            nums[nonZeroFoundAt] = nums[i];
            nonZeroFoundAt++;
        }
       }
       for(int i = nonZeroFoundAt; i<nums.length; i++){
        nums[i] = 0;
       }
    }
}