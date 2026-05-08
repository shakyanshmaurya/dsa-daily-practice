#include <stdio.h>

struct Interval {
    int start;
    int end;
};

int main() {

    struct Interval arr[] = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    int n = 4;

    int start = arr[0].start;
    int end = arr[0].end;

    printf("Merged Intervals:\n");

    for(int i = 1; i < n; i++) {

        if(arr[i].start <= end) {

            // overlap
            if(arr[i].end > end) {
                end = arr[i].end;
            }
        }
        else {

            printf("[%d, %d]\n", start, end);

            start = arr[i].start;
            end = arr[i].end;
        }
    }

    printf("[%d, %d]\n", start, end);

    return 0;
}