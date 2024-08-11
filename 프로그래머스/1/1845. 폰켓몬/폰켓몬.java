import java.util.*;
import java.util.stream.*;;

class Solution {
  public int solution(int[] nums) {
      
      List<Integer> numbers = Arrays.stream(nums).boxed().collect(Collectors.toList());
      
      // Use a Set to find unique elements
      Set<Integer> uniqueNumbers = new HashSet<>(numbers);
      
      // Calculate the maximum number of unique elements you can pick
      int maxUnique = Math.min(uniqueNumbers.size(), nums.length / 2);
      
      return maxUnique;

     
  }
}