
public class Solution {
    public int maxVowels(String s, int k) {
        int maxVowels = 0, currentVowels = 0;
        
        // Check if the string length is less than k
        if (s.length() < k) {
            return 0;  // No valid substring can be formed if the length is less than k
        }

        // Count vowels in the first window of size k
        for (int i = 0; i < k; i++) {
            if (isVowel(s.charAt(i))) {
                currentVowels++;
            }
        }
        
        maxVowels = currentVowels;
        
        // Slide the window across the string
        for (int i = k; i < s.length(); i++) {
            // Remove the vowel at the left end of the window
            if (isVowel(s.charAt(i - k))) {
                currentVowels--;
            }
            // Add the vowel at the right end of the window
            if (isVowel(s.charAt(i))) {
                currentVowels++;
            }
            maxVowels = Math.max(maxVowels, currentVowels); // Update maxVowels
        }

        return maxVowels;
    }

    // Helper function to check if a character is a vowel
    private boolean isVowel(char c) {
        return "aeiou".indexOf(c) != -1;
    }
}
