#include <bits/stdc++.h>
using namespace std;

vector<int> getMergedInterval(vector<int> &first, vector<int> &A) {
	int fStart = first[0];
	int fEnd = first[1];

	int aStart = A[0];
	int aEnd = A[1];

	// Overlapping
	if (fEnd >= aStart && aEnd >= fStart) {
		return { max(aStart, fStart), min(fEnd, aEnd) };
	}

	return { -1, -1 };
}

vector<int> mergeLastIntervals(vector<int> &first, vector<int> &A) {
	int fStart = first[0];
	int fEnd = first[1];

	int aStart = A[0];
	int aEnd = A[1];

	// Overlapping
	if (fEnd >= aStart && aEnd >= fStart) {
		return { min(aStart, fStart), max(fEnd, aEnd) };
	}

	return { -1, -1 };
}

int main() {
	
	int days, assistants;
	cin >> days >> assistants;

	vector<vector<int>> intervals;
	vector<int> range(2);
	for (int i = 0; i < assistants; i++) {
		cin >> range[0] >> range[1];
		intervals.push_back(range);
	}

    if (assistants == 1) {
        cout << days - 1;
        return 0;
    }

	sort(begin(intervals), end(intervals));

	vector<vector<int>> mergedIntervals;

	vector<int> curInterval = intervals[0];

	for (int i = 1; i < intervals.size(); i++) {
		vector<int> merged = getMergedInterval(curInterval, intervals[i]);

		if (merged[0] != -1) {
			if (mergedIntervals.size() == 0 || (!mergedIntervals.empty() && merged != mergedIntervals.back())) {
				mergedIntervals.push_back(merged);
			}
			curInterval = mergeLastIntervals(curInterval, intervals[i]);
		}
		else {
			curInterval = intervals[i];
		}
	}

	// Merge again the merged intervals
	sort(begin(mergedIntervals), end(mergedIntervals)); // No need sosrtt?
	vector<vector<int>> lastMerged = { mergedIntervals[0] };
	for (int i = 1; i < mergedIntervals.size(); i++) {
		vector<int> merged = mergeLastIntervals(lastMerged.back(), mergedIntervals[i]);
		if (merged[0] != -1) {
			if (lastMerged.size() == 0 || (!lastMerged.empty() && merged != lastMerged.back())) {
				lastMerged.pop_back();
				lastMerged.push_back(merged);
			}
			curInterval = merged;
		}
		else {
			//lastMerged.push_back(curInterval);
			lastMerged.push_back(mergedIntervals[i]);
			curInterval = mergedIntervals[i];
		}
	}

	int daysCountGreaterEqualToTwo = 0, daysCount;
	for (vector<int> &curRange : lastMerged) {
		daysCountGreaterEqualToTwo += curRange[1] - curRange[0] + 1;
	}

	daysCount = days - daysCountGreaterEqualToTwo;

	cout << daysCount << endl;

	return 0;
}