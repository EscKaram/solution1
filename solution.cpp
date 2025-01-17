#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 1e7 + 5;
int a[4 * maxn];
int l_a = maxn, r_a = maxn;
int l_b = 3 * maxn, r_b = 3 * maxn;

#define push_back_a(x) a[r_a++] = x
#define push_back_b(x) a[r_b--] = x
#define push_front_a(x) a[--l_a] = x
#define push_front_b(x) a[++l_b] = x
#define front_a() a[l_a++]
#define front_b() a[l_b--]
#define back_a() a[--r_a]
#define back_b() a[++r_b]
#define sz_a() (r_a - l_a)
#define sz_b() (l_b - r_b)

int n;
string s;
int cur = 1;
bool fa = true, fb = true;
int i, diff;
string ans;

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> s;
        for (i = 0; i < n; i++) {
                if (s[i] == 'a') {
                        if (fb) {
                                push_back_a(cur);
                        } else {
                                push_front_b(cur);
                                if (sz_b() > sz_a()) {
                                        push_back_a(back_b());
                                }
                        }
                        ++cur;
                        if (cur == 10)
                                cur = 0;
                } else if (s[i] == 'b') {
                        if (fa) {
                                push_back_b(cur);
                        } else {
                                push_front_a(cur);
                                if (sz_a() > sz_b()) {
                                        push_back_b(back_a());
                                }
                        }
                        ++cur;
                        if (cur == 10)
                                cur = 0;
                } else if (s[i] == 'A') {
                        ans += ('0' + front_a());
                        if (!fb) {
                                if (sz_b() > sz_a()) {
                                        push_back_a(back_b());
                                }
                        }
                } else if (s[i] == 'B') {
                        ans += ('0' + front_b());
                        if (!fa) {
                                if (sz_a() > sz_b()) {
                                        push_back_b(back_a());
                                }
                        }
                } else if (s[i] == '>') {
                        fa = false;
                        diff = (sz_b() - sz_a()) / 2;
                        if (diff > 0) {
                                memmove(a + r_a, a + r_b + 1, diff * sizeof(a[0]));
                                r_a += diff;
                                r_b += diff;
                        }
                        diff = (sz_a() - sz_b() + 1) / 2;
                        if (diff > 0) {
                                memmove(a + r_b - diff + 1, a + r_a - diff, diff * sizeof(a[0]));
                                r_b -= diff;
                                r_a -= diff;
                        }
                } else if (s[i] == ']') {
                        fb = false;
                        diff = (sz_a() - sz_b()) / 2;
                        if (diff > 0) {
                                memmove(a + r_b - diff + 1, a + r_a - diff, diff * sizeof(a[0]));
                                r_b -= diff;
                                r_a -= diff;
                        }
                        diff = (sz_b() - sz_a() + 1) / 2;
                        if (diff > 0) {
                                memmove(a + r_a, a + r_b + 1, diff * sizeof(a[0]));
                                r_a += diff;
                                r_b += diff;
                        }
                } else if (s[i] == '<') {
                        fa = true;
                } else {
                        fb = true;
                }
        }
        cout << ans;
        return 0;
}
