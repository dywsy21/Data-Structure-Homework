import sys
input = sys.stdin.read

def main():
    data = input().split()
    n = int(data[0])
    c = int(data[1])
    a = list(map(int, data[2:n+2]))
    b = list(map(int, data[n+2:2*n+2]))

    A, B = 0, 1
    dp = [[0] * 2 for _ in range(n)]
    state = [[0] * 2 for _ in range(n)]

    dp[0][A] = a[0] - c
    dp[0][B] = b[0] - c
    state[0][A] = 1
    state[0][B] = 1

    for i in range(1, n):
        if dp[i-1][A] - (1 << state[i-1][A]) * c > dp[i-1][B] - c:
            dp[i][A] = dp[i-1][A] - (1 << state[i-1][A]) * c + a[i]
            state[i][A] = state[i-1][A] + 1
        else:
            dp[i][A] = dp[i-1][B] - c + a[i]
            state[i][A] = 1

        if dp[i-1][B] - (1 << state[i-1][B]) * c > dp[i-1][A] - c:
            dp[i][B] = dp[i-1][B] - (1 << state[i-1][B]) * c + b[i]
            state[i][B] = state[i-1][B] + 1
        else:
            dp[i][B] = dp[i-1][A] - c + b[i]
            state[i][B] = 1

        # Debug output
        # print(f"Day {i}:")
        # print(f"dp[{i}][A] = {dp[i][A]}, state[{i}][A] = {state[i][A]}")
        # print(f"dp[{i}][B] = {dp[i][B]}, state[{i}][B] = {state[i][B]}")

    result = max(dp[n-1][A], dp[n-1][B])
    print(result)

if __name__ == "__main__":
    main()
