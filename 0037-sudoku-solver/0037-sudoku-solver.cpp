/*
Bitmask Backtracking with Minimum Remaining Values:
Each row, column, and 3x3 box uses a bitmask to record already placed digits.
For every recursion step, the algorithm selects the empty cell with the fewest
valid candidates (MRV), tries each candidate, and backtracks if needed.
*/

#include <bit>
#include <vector>

using namespace std;

class Solution {
private:
    static constexpr int fullMask = (1 << 9) - 1;

    vector<int> rowMasks;
    vector<int> columnMasks;
    vector<int> boxMasks;

    int getBoxIndex(int row, int column) {
        return (row / 3) * 3 + (column / 3);
    }

    bool solveBoard(vector<vector<char>>& board) {
        int bestRow = -1;
        int bestColumn = -1;
        int bestCandidates = 0;
        int minimumCandidateCount = 10;

        for (int row = 0; row < 9; ++row) {
            for (int column = 0; column < 9; ++column) {
                if (board[row][column] != '.') {
                    continue;
                }

                int boxIndex = getBoxIndex(row, column);
                int usedMask = rowMasks[row] | columnMasks[column] | boxMasks[boxIndex];
                int candidateMask = fullMask & ~usedMask;
                int candidateCount = popcount(static_cast<unsigned int>(candidateMask));

                if (candidateCount == 0) {
                    return false;
                }

                if (candidateCount < minimumCandidateCount) {
                    minimumCandidateCount = candidateCount;
                    bestRow = row;
                    bestColumn = column;
                    bestCandidates = candidateMask;

                    if (candidateCount == 1) {
                        break;
                    }
                }
            }

            if (minimumCandidateCount == 1) {
                break;
            }
        }

        if (bestRow == -1) {
            return true;
        }

        int boxIndex = getBoxIndex(bestRow, bestColumn);

        while (bestCandidates != 0) {
            int digitBit = bestCandidates & -bestCandidates;
            bestCandidates -= digitBit;

            int digit = countr_zero(static_cast<unsigned int>(digitBit));
            board[bestRow][bestColumn] = static_cast<char>('1' + digit);

            rowMasks[bestRow] |= digitBit;
            columnMasks[bestColumn] |= digitBit;
            boxMasks[boxIndex] |= digitBit;

            if (solveBoard(board)) {
                return true;
            }

            rowMasks[bestRow] ^= digitBit;
            columnMasks[bestColumn] ^= digitBit;
            boxMasks[boxIndex] ^= digitBit;
            board[bestRow][bestColumn] = '.';
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        rowMasks.assign(9, 0);
        columnMasks.assign(9, 0);
        boxMasks.assign(9, 0);

        for (int row = 0; row < 9; ++row) {
            for (int column = 0; column < 9; ++column) {
                if (board[row][column] == '.') {
                    continue;
                }

                int digit = board[row][column] - '1';
                int digitBit = 1 << digit;
                int boxIndex = getBoxIndex(row, column);

                rowMasks[row] |= digitBit;
                columnMasks[column] |= digitBit;
                boxMasks[boxIndex] |= digitBit;
            }
        }

        solveBoard(board);
    }
};