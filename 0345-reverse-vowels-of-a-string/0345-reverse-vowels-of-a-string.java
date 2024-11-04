class Solution {
    public String reverseVowels(String s) {
        String vowels = "aeiouAEIOU";
         char[] sArray = s.toCharArray();
         int left = 0; 
         int right = sArray.length - 1;

         while(left<right) {
            while(left < right && vowels.indexOf(sArray[left])==-1){
                left++;
            }
            while(left<right && vowels.indexOf(sArray[right])==-1) {
                right--;
            }

            char temp = sArray[left];
            sArray[left] = sArray[right];
            sArray[right] = temp;
            left++;
            right--;
         }
         return new String(sArray);
    }
}