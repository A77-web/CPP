class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		// left和right表示在这个区间内找元素
		int left = 0;
		int right = n - 1;

		// 下标left<=right ,则一直循环
		while (left <= right)
		{
			int mid = (left + right) >> 1;
			if (A[mid] == x)
				return mid;

			// 满足A[left] < A[mid]表示左到中一定是顺序的
			// 然后判断如果在这个之间的话那就直接二分找元素
			// 否则就在另一段找
			if (A[left] < A[mid])
			{
				if (A[left] <= x && x < A[mid])
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			// 这个表示左到中不是顺序的，那么先在中到右找（因为中到右是顺序的）
			// 判定在中到右那么久继续二分，否则就在左边找
			else
			{
				if (A[mid] < x && x <= A[right])
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
			// 最后一直循环，找到则返回，否则返回-1
		}
		return -1;
	}
};
