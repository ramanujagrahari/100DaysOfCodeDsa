/* Day 99 - Question 1: Car Fleet Calculation
   Determine the number of car fleets that arrive at the target.
   Cars are sorted by position (closest to target first) and arrival times compared. */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int compareCars(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->pos - c1->pos; /* Sort descending by position */
}

int carFleet(int target, int* position, int positionSize, int* speed) {
    Car* cars = (Car*)malloc(positionSize * sizeof(Car));
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), compareCars);

    int fleets = 0;
    double lastTime = 0;

    for (int i = 0; i < positionSize; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int target, n;
    scanf("%d %d", &target, &n);

    int position[n], speed[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    printf("Car fleets: %d\n", carFleet(target, position, n, speed));

    return 0;
}
