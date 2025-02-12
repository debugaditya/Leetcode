class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0, sum1 = 0, maxMilestone = 0;

        for (long long i = 0; i < milestones.size(); i++) {
            sum1 += milestones[i];
            maxMilestone = max((int)maxMilestone, milestones[i]);
            if (sum > 0) sum -= milestones[i];
            else sum += milestones[i];
        }
        
        return min(sum1, 2 * (sum1 - maxMilestone) + 1);
    }
};

