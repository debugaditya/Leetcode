class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i1 = a.size() - 1, i2 = b.size() - 1;
        string ans = "";

        while (i1 >= 0 || i2 >= 0 || carry) {
            int sum = carry;
            if (i1 >= 0) sum += a[i1--] - '0';
            if (i2 >= 0) sum += b[i2--] - '0';

            ans.insert(ans.begin(), (sum % 2) + '0'); 
            carry = sum / 2; 
        }

        return ans;
    }
};

