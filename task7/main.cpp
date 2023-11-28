#include <iostream>
#include <vector>
#include <algorithm>

struct Room {
    int treasures;
    int danger;
    bool visited;
};

int maxScore;
int currentScore;
int depth;
std::vector<Room> cave;

void exploreCave(int roomIndex, int currentDepth) {
    if (currentDepth == depth) {
        maxScore = std::max(maxScore, currentScore);
        return;
    }

    Room& currentRoom = cave[roomIndex];
    currentRoom.visited = true;
    currentScore += currentRoom.treasures;

    for (int i = 0; i < 2; i++) {
        int nextRoomIndex = (i == 0) ? roomIndex + currentDepth + 1 : roomIndex - currentDepth - 1;

        if (nextRoomIndex >= 0 && nextRoomIndex < cave.size() && !cave[nextRoomIndex].visited) {
            exploreCave(nextRoomIndex, currentDepth + 1);
        }
    }

    currentScore -= currentRoom.treasures;
    currentScore -= currentRoom.danger;
    currentRoom.visited = false;
}

int Recursion(int number, int length) {
    if (length > 1) {
        return Recursion(0, length - 1) + (number == 0 ? Recursion(1, length - 1) : 0);
    }
    if (number == 0)
        return 2;
    else
        return 1;
}

int Force(int length)
{
    return Recursion(0, length - 1) + Recursion(1, length - 1);
}

int countSequences(int n) {
    int dp[n+1][2];
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];

        for (int j = 0; j < n + 1; j++) {
            for (int k = 0; k < 2; k++) {
                std::cout << dp[j][k] << " ";
            }
            std::cout << std::endl;
        }
    }

    return dp[n][0] + dp[n][1];
}


int main() {
    int n = 5;  // длина последовательности
    int result = countSequences(n);
    std::cout << "Number of sequences of length " << n << " without consecutive 1s: " << result << std::endl;
    return 0;
}
