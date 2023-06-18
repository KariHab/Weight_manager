#include "weight_track.h"
/*
create a file the first time
and append*/
int printf_result_in_file(data weight)
{
    time_t t;
    time(&t);
    char *filename = "result.txt";

    FILE *fp1 = fopen(filename, "a+");
    if (fp1 == NULL)
    {
        printf("Error opening the file %s", filename);
        return (-1);
    }
    fprintf(fp1, "\n%sMean weight: %0.2f kg\nExtrapolated weight in %d days: %0.2f kg\n", ctime(&t), weight.mean_weight, DAYS, weight.extrapolation);
    // fclose(fp);
    fclose(fp1);
    return(0);
}