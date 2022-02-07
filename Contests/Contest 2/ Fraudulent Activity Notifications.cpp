// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-2/challenges/fraudulent-activity-notifications/

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

void updateCountingArray(vector<int> &counts, int substractVal, int addVal) {
    counts[substractVal]--;
    counts[addVal]++;
}

double getMedian(vector<int> &counts, int &numOfNumbers) {
    double median = 0;
    char evenOrOdd = (numOfNumbers % 2 == 0) ? 'E' : 'O';
    // Odd
    if (evenOrOdd == 'O') {
        int middleIdx = (numOfNumbers / 2) + 1;
        int sum = 0;
        for (int i = 0; i < 201; i++) {
            if (counts[i] > 0) {
                sum += counts[i];
                if (sum >= middleIdx) {
                    median = i * 1.0;
                    break;
                }
            }
        }
    }
    // Even
    else {
        int median1;
        int middle1Idx = (numOfNumbers / 2);
        int sum = 0;
        for (int i = 0; i < 201; i++) {
            if (counts[i] > 0) {
                sum += counts[i];
                if (sum >= middle1Idx) {
                    median1 = i;
                    break;
                }
            }
        }
        
        int median2;
        int middle2Idx = (numOfNumbers / 2) + 1;
        sum = 0;
        for (int i = 0; i < 201; i++) {
            if (counts[i] > 0) {
                sum += counts[i];
                if (sum >= middle2Idx) {
                    median2 = i;
                    break;
                }
            }
        }
        median = ((median1 + median2) * 1.0 / 2.0) * 1.0;
    }
    
    return median;
}

int activityNotifications(vector<int> &expenditure, int &d) {
    vector<int> counts(201, 0);
    // Counts till d
    for (int i = 0; i < d; i++) {
        counts[expenditure[i]]++;
    }
    
    int leftIdx = 0;
    int result = 0, len = expenditure.size();
    for (int rightIdx = d; rightIdx < len; rightIdx++) {
        double median = getMedian(counts, d);
        double exp = expenditure[rightIdx] * 1.0;
        if (exp >= (2.0 * median)) {
            result++;
        }
        // Update Counting Array
        updateCountingArray(counts, expenditure[leftIdx], expenditure[rightIdx]);
        leftIdx++;
    }
    
    return result;
}