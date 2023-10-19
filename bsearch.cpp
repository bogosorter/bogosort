const int RESULT = 100;

int bsearch() {
    int low = 0;
    int high = 1e9;
    while (low < high) {
        int mid = (low + high) / 2;
        if (mid == RESULT) low = high = mid;
        else if (mid < RESULT) low = mid;
        else high = mid;
    }
    return low;
}