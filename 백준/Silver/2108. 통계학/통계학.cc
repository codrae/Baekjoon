#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N,mean,median,mode,bound,max_e,max_idx;
int cnt[8001];


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int arr[500002];
    for (int i = 0; i <N; ++i) {
        cin >> arr[i];
        mean += arr[i];
        cnt[arr[i]+4000]++;
    }
    sort(arr,arr+N);
    cout.precision(0);
    cout << fixed;
    mean = round((float)mean/N);
    median = arr[N/2];
    //mode = max_element(cnt, cnt+8001)-cnt; mode -= 4000;


    for (int i = 0; i < 8001; ++i) {
        if(cnt[i] > max_e){
            max_e = cnt[i];
            max_idx = i;
        }
    }

    for (int i = 0; i < 8001; ++i) {
        if(cnt[i] == max_e && i != max_idx) {
            max_idx = i;
            break;
        }
    }

    mode = max_idx - 4000;

    bound = arr[N-1] - arr[0];

    cout << mean << '\n' << median << '\n' << mode << '\n' << bound;


    return 0;
}
