const int NONE = 0;
const int NORMAL_TRANSACTION = 1;
const int SHORTSELLING_TRANSACTION = 2;

const int N = 1000, K = 500;
long long dp[N][3][2 * K];

class Solution {

    long long solve(vector<int> &prices, int k, int idx, int transactionType, int eventsCnt) {

        if(idx == prices.size() or eventsCnt == 2 * k) {
            return transactionType == NONE ? 0 : INT_MIN;
        }

        if(dp[idx][transactionType][eventsCnt] != LONG_MIN) return dp[idx][transactionType][eventsCnt];


        long long ans1 = INT_MIN, ans2 = INT_MIN, ans3 = INT_MIN;

        // skip
        ans1 = solve(prices, k, idx + 1, transactionType, eventsCnt); // INT_MIN

        // transaction
        if(transactionType == NONE) {
            // start normal
            ans2 = -prices[idx] + solve(prices, k, idx + 1, NORMAL_TRANSACTION, eventsCnt + 1);

            // start shortselling
            ans3 = prices[idx] + solve(prices, k, idx + 1, SHORTSELLING_TRANSACTION , eventsCnt + 1);
        } else if(transactionType == NORMAL_TRANSACTION) {
            // complete normal
            ans2 = prices[idx] + solve(prices, k, idx + 1, NONE, eventsCnt + 1);
        } else {
            // complete shortselling
            ans3 = -prices[idx] + solve(prices, k, idx + 1, NONE, eventsCnt + 1); // -1
        }

        return dp[idx][transactionType][eventsCnt] = max({ans1, ans2, ans3});
    }

// fibonacci -> 0, 1, 1, 2, 3, 5, 8, 13, ...

// -1: ans not available

// default value for dp should be a value which can never be the answer

// -1 -> ans has not been calculated
public:
    long long maximumProfit(vector<int>& prices, int k) {
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 2 * K; k++) {
                    dp[i][j][k] = LONG_MIN;
                }
            }
        }
    
        return solve(prices, k, 0, NONE, 0);    
    }
};

// in this problem, can -1 be the answer for any subproblem?

// +10

// (buy, sell) -> 1 transaction -> 2 events

// k transaction -> 2*k events


// solve(1, SHORTSELLING) -> -1

// prices = [1, 1, 1, 1, 1, 1, 1, 1, 1, ... , 1]

// shortselling on day 0
