long possiblePathsRecursive(int M, int N) {
    if (M==0 || N==0) {
        return 0;
    }

    if (M+N==2) {
        return 1;
    }

    return possiblePathsRecursive(M-1, N) + possiblePathsRecursive(M, N-1);
}

long possiblePathsIterative(int M, int N) {
    // homework
    if (M == 0 || N == 0) {
        return 0;
    }
    long paths [M * N];
    for (int column = 0; column < M; column++) {
        paths[column] = 1;
    }
    for (int row = 1; row < N; row++) {
        for (int column = 0; column < M; column++) {
            if (column == 0) {
                paths[M * row] = 1;
            } else {
                paths[M * row + column] = paths[M * (row - 1) + column] + paths[M * row + (column - 1)];
            }
        }
    }
    return paths[M * N - 1];
}
