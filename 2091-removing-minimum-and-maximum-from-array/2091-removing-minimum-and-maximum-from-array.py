class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        minIndex = nums.index(min(nums))
        maxIndex = nums.index(max(nums))
        arrayLength = len(nums)

        leftMostIndex = min(minIndex, maxIndex)
        rightMostIndex = max(minIndex, maxIndex)

        frontDeletions = rightMostIndex + 1
        backDeletions = arrayLength - leftMostIndex
        splitDeletions = min(
            leftMostIndex + 1 + arrayLength - rightMostIndex,
            rightMostIndex + 1 + arrayLength - leftMostIndex,
        )

        return min(frontDeletions, backDeletions, splitDeletions)
