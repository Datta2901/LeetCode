class Solution {
public:
    int findComplement(int num) {
        int bits = floor(log2(num)) + 1;
        int ones = pow(2,bits) - 1;
        return ones ^ num;
    }
}; 