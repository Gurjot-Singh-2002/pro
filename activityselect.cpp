#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Activity structure to store start and finish times
struct Activity {
    int start;
    int finish;
};

// Comparator to sort activities by finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

// Function to perform Greedy Activity Selection
void activitySelection(vector<Activity>& activities) {
    // Step 1: Sort activities by finish time
    sort(activities.begin(), activities.end(), compare);

    int n = activities.size();

    // Step 2: Always select the first activity
    cout << "Selected Activities (start, finish):" << endl;
    int i = 0;
    cout << "(" << activities[i].start << ", " << activities[i].finish << ") ";

    // Step 3: Consider the rest of the activities
    for (int m = 1; m < n; m++) {
        if (activities[m].start >= activities[i].finish) {
            cout << "(" << activities[m].start << ", " << activities[m].finish << ") ";
            i = m;
        }
    }

    cout << endl;
}

int main() {
    // Sample input: Unsorted start and finish times
    vector<Activity> activities = {
        {5, 9},
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9}
    };

    activitySelection(activities);

    return 0;
}

