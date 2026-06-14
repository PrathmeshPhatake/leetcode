class Solution {
    public int majorityElement(int[] nums) {
        int n=nums.length;
        Map<Integer,Integer>map=new HashMap<>();
        for(Integer it:nums)
        {
            map.put(it,map.getOrDefault(it,0)+1);
        }
        for(Map.Entry<Integer,Integer>mp:map.entrySet()){
            if(mp.getValue()>n/2)
            {
                return mp.getKey();
            }
        }
        return 0;
    }
}