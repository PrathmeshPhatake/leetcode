class Solution {
    public int majorityElement(int[] nums) {
        int n=nums.length;
        Map<Integer,Integer>mp=new HashMap<>();
        for(Integer it:nums){
            mp.put(it,mp.getOrDefault(it,0)+1);
        }
        for(Map.Entry<Integer,Integer>entry:mp.entrySet())
        {
            if(entry.getValue()>n/2)
            {
                return entry.getKey();
            }
        }
        return 0;
    }
}