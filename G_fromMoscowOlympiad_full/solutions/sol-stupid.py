tests = int(input())
for test in range(tests):
    n, m, k = map(int, input().split())
    g = []
    for i in range(n + 1):
        g.append([])
    neig = [0] * (n + 1)
    for i in range(m):
        u, v = map(int, input().split())
        g[u].append(v)
        g[v].append(u)
        neig[u] += 1
        neig[v] += 1
    ans = []
    for now in range(n + 1):
        ans.append((neig[now], now))
    ans.sort(reverse=True)
    print(k)
    for i in range(k):
        print(ans[i][1], end=' ')
    print()
    