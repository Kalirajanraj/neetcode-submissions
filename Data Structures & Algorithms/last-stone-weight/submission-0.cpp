
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxHeap;

        // Insert all stones into max-heap
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        // Continue until at most one stone remains
        while (maxHeap.size() > 1) {

            int x = maxHeap.top();
            maxHeap.pop();

            int y = maxHeap.top();
            maxHeap.pop();

            // If weights are different, insert the difference
            if (x != y) {
                maxHeap.push(x - y);
            }
        }

        // Return remaining stone or 0
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
