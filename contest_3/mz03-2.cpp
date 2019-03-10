void process(const std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector nums = v1;
    std::unique(nums.begin(), nums.end());
    std::sort(nums.begin(), nums.end());
    auto it1 = v2.begin(), it3 = nums.begin();
    while (it1 != v2.end() && it1 - v2.begin() != *it3) {
        it1++;
    }
    if (it1 == v2.end()) {
        return;
    }
    auto it2 = it1;
    it3++;
    it2++;
    while (it3 != nums.end() && it2 != v2.end()) {
        if (it2 - v2.begin() != *it3)
    }
}
