std::vector<int> spiralTransposition(std::vector< std::vector<int> > arr) {
	std::vector<int> ret;
	int tick = 0, capacity = arr[0].size() * arr.size(); // keeps track if visited every element
	int left = 0, right = arr[0].size();  // Left and right ends of spiral
	int top = 0, bottom = arr.size();     // Top and bottom of spiral
	bool reverse = false; // Are we going to the left or going up? reverse normal directions.
	while (tick < capacity) {
		if (reverse) {
			for (int i = right; i >= left; --i) {
				ret.push_back(arr[bottom][i]);
				++tick;
			}
			--bottom;
			for (int i = bottom; i >= top; --i) {
				ret.push_back(arr[i][left]);
				++tick;
			}
			++left;
			reverse = false;
		}
		else {
			for (int i = left; i <= right; ++i) {
				ret.push_back(arr[top][i]);
				++tick;
			}
			++top;
			for (int i = top; i <= bottom; ++i) {
				ret.push_back(arr[i][right]);
				++tick;
			}
			--right;
			reverse = true;
		}
	}
	return ret;
}