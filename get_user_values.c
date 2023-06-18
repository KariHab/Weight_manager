#include "weight_track.h"

data get_user_values()
{
    int index;
    data weight;

    index = 0;
    while (index < DAYS)
    {
        printf("Enter the weight of day %d: ", (index + 1));
        scanf("%f", &weight.daily_weight[index]);
        index++;
    }
    return (weight);
}
