#include <iostream>
using namespace std;

#define N 5   

void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int maze[N][N], int x, int y, int seen[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && seen[x][y] == 0);
}

bool solveMazeUtil(int maze[N][N], int a, int b, int sol[N][N], int seen[N][N]) {
    if (a == N - 1 && b == N - 1) {
        sol[a][b] = 1;
        return true;
    }

    if (isSafe(maze, a, b, seen)) {
        sol[a][b] = 1; 
        seen[a][b] = 1;

        if (solveMazeUtil(maze, a, b+1, sol, seen)) return true;
        if (solveMazeUtil(maze, a+1, b, sol, seen)) return true;
        if (solveMazeUtil(maze, a, b-1, sol, seen)) return true;
        if (solveMazeUtil(maze, a-1, b, sol, seen)) return true;

        sol[a][b] = 0; 
        seen[a][b] = 0; 
        return false;
    }

    return false;
}

void solveMaze(int maze[N][N]) {
    int sol[N][N] = {0};
    int seen[N][N] = {0};

    if (!solveMazeUtil(maze, 0, 0, sol, seen)) {
        cout << "No solution exists\n";
        return;
    }

    cout << "Path found (4 directions):\n";
    printSolution(sol);
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
