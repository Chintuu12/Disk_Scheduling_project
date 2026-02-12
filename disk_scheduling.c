#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, head, i, j, pos, seek = 0;
    float avg_seek;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int req[n], done[n];

    printf("Enter the disk request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        done[i] = 0;
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: ");

    for(i = 0; i < n; i++) {
        int min = 9999, diff;
        pos = -1;

        for(j = 0; j < n; j++) {
            if(!done[j]) {
                diff = abs(head - req[j]);
                if(diff < min) {
                    min = diff;
                    pos = j;
                }
            }
        }

        seek += min;
        head = req[pos];
        done[pos] = 1;

        printf("%d ", head);
    }

    avg_seek = (float)seek / n;
    printf("\nTotal Seek Time: %d", seek);
    printf("\nAverage Seek Time: %.2f\n", avg_seek);

    return 0;
}