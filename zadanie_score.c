#include <stdio.h>

int main() {
    FILE *file = fopen("dataf.txt", "r");
    if (file == NULL) {
        printf("Error: The 'dataf.txt' file does not exist or cannot be opened.\n");
        return 1;
    }

    int count = 0;
    int negative = 0;
    double sum = 0.0;
    double min = 100.0;
    double max = 0.0;
    double score;

    while (fscanf(file, "%lf", &score) == 1) {
        if (score >= 0.0 && score <= 100.0) {
            count++;
            sum += score;
            if (score < min) min = score;
            if (score > max) max = score;
        }
        if (score <0.0) {
            negative++;
        }
    }

    fclose(file);

   if (count == 0) {
        printf("No valid scores found in the file.\n");
    } else {
        double average = sum / count;
        printf("Number of valid scores: %d\n", count);
        printf("Largest score: %.2lf\n", max);
        printf("Smallest score: %.2lf\n", min);
        printf("Average score: %.2lf\n", average);
        printf("Warning! Number of negative scores: %d\n", negative);
    }

    return 0;
}
