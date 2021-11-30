int MoreThanHalfNum_Solution(vector<int> numbers) {
    map<int, int> table;
    for (auto num:numbers) {
        table[num]++;
    }
    for (auto i:table) {
        if (i.second > numbers.size() / 2) {
            return i.first;
        }
    }
    return 0;
}
