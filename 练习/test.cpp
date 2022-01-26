#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <sstream>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <iosfwd>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <cwchar>
#include <cwctype>
#include <complex.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
#include <regex>

using namespace std;

class Solution {
public:
    vector<int> preSum;
    int subarraySum(vector<int>& nums, int k) {
        if(!k) return 0;
        int n = nums.size();
        preSum = vector<int>(n + 1);
        cout << "ddd ";
        for(int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            cout << preSum[i] << " ";
        }
        cout << endl;

        int res = 0;
        for(int i = 0; i < n + 1; i++) {
            for(int j = i + 1; j < n + 1; j++) {
                if(preSum[j] - preSum[i] == k) {
                    res++;
                }
            }
        }
        return res;
    }
};



int main() {
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(1);
    Solution s;
    int res = s.subarraySum(nums, 1);
    cout << "\nres: " << res;
}
