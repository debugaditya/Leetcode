class Solution { 
 public:
  int minSubarray(vector<int>& nums, int p) {
    long long sum = 0;
    vector<long long> m; // Keep the same variable name as in your original code

    map<long long, long long> mp2;
    for (long long i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    
    long long target = sum % p; // Change variable name to target
    if (target == 0) {
      return 0;
    }

    mp2[0] = -1; // To handle cases where a subarray from the start has the needed mod
    long long sum2 = 0;
    int mini = nums.size(); // Change minLength to mini

    for (long long j = 0; j < nums.size(); j++) {
      sum2 += nums[j];
      long long currentMod = sum2 % p;
      long long neededMod = (currentMod - target + p) % p;

      if (mp2.find(neededMod) != mp2.end()) {
        mini = min(mini, static_cast<int>(j - mp2[neededMod])); // Change minLength to mini
      }

      // Update mp2 with the current prefix sum modulo
      mp2[currentMod] = j;
    }

    return mini == nums.size() ? -1 : mini; // Change minLength to mini
  }
};

