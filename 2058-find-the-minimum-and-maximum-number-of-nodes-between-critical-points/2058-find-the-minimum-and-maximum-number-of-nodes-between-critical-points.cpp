/*
 * Single-Pass Rolling Pointers solution for finding the minimum and maximum
 * number of nodes between critical points in a linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

// Three rolling pointers identify each node's previous, current, and next values while traversing once.
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* previousNode = head;
        ListNode* currentNode = head != nullptr ? head->next : nullptr;

        int currentIndex = 1;
        int firstCriticalIndex = -1;
        int previousCriticalIndex = -1;
        int minimumDistance = INT_MAX;
        int maximumDistance = -1;

        while (currentNode != nullptr && currentNode->next != nullptr) {
            bool isLocalMaximum =
                currentNode->val > previousNode->val &&
                currentNode->val > currentNode->next->val;

            bool isLocalMinimum =
                currentNode->val < previousNode->val &&
                currentNode->val < currentNode->next->val;

            if (isLocalMaximum || isLocalMinimum) {
                if (firstCriticalIndex == -1) {
                    firstCriticalIndex = currentIndex;
                } else {
                    minimumDistance = min(
                        minimumDistance,
                        currentIndex - previousCriticalIndex
                    );

                    maximumDistance = currentIndex - firstCriticalIndex;
                }

                previousCriticalIndex = currentIndex;
            }

            previousNode = currentNode;
            currentNode = currentNode->next;
            ++currentIndex;
        }

        if (maximumDistance == -1) {
            return {-1, -1};
        }

        return {minimumDistance, maximumDistance};
    }
};