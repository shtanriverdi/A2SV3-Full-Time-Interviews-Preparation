// Question Link: https://www.hackerrank.com/challenges/grading/problem

vector<int> gradingStudents(vector<int> &grades) {
    int n = grades.size(), diff = 0;
    for (int &grade : grades) {
        if (grade >= 38 && grade % 5 != 0) {
            int firstDecimal = grade / 10;
            int middleMulOf5 = ((firstDecimal * 10) + 5);
            // 36..39
            if (grade < middleMulOf5) {
                diff = middleMulOf5 - grade;
            }
            // 31..34
            else {
                diff = (middleMulOf5 + 5) - grade;
            }
            if (diff < 3) {
                grade += diff;
            }
        }
    }
    return grades;
}