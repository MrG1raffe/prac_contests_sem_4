#include <vector>
#include <algorithm>

void process(const std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector<int> nums = v1;
    std::sort(nums.begin(), nums.end());
    auto tmp = std::unique(nums.begin(), nums.end());
    nums.erase(tmp, nums.end());
    auto nums_p = nums.begin();
    while (nums_p != nums.end() && *nums_p < 0) {
        nums_p++;
    }
    size_t index = 0;
    auto first = v2.begin(), last = first;
    while (index < v2.size() && nums_p != nums.end()) {
        if ((int) index++ == *nums_p) {
            last++;
            nums_p++;
        } else {
            std::swap(*first, *last);
            first++;
            last++;
        }
    }
    v2.erase(first, last);
}
