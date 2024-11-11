class Solution {
    public boolean uniqueOccurrences(int[] arr) {
     Map<Integer, Integer> countMap = new HashMap<>();
     for(int num : arr){
        countMap.put(num, countMap.getOrDefault(num, 0) + 1);
     }   

     Map<Integer, Integer> frequencyMap = new HashMap<>();
     for(int count : countMap.values()) {
        frequencyMap.put(count, frequencyMap.getOrDefault(count, 0) + 1);
        if(frequencyMap.get(count)>1){
            return false;
        }
     }
     return true;
    }
}