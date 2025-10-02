class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {1.0*celsius+273.15,celsius*1.8+32.00};
    }
};
