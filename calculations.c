#include "weight_track.h"

float calculation_loss(data weight)
{
    weight.loss_per_week = -(weight.daily_weight[DAYS - 1] - weight.daily_weight[0]);
    printf(GREEN "You lost %0.2f kg, the last %d days\n" WHITE, weight.loss_per_week, DAYS);
    weight.loss_per_day = weight.loss_per_week / DAYS;
    printf("Which means %0.2f kg per day\n", weight.loss_per_day);
    return (weight.loss_per_week);
}

float mean_weight(data weight)
{
    int index;

    index = 0;
    weight.sum_weight = 0;
    while (index < DAYS)
    {
        weight.sum_weight += weight.daily_weight[index];
        index++;
    }
    weight.mean_weight = weight.sum_weight / DAYS;
    printf("The mean weight is %0.2f for the last %d days\n", weight.mean_weight, DAYS);
    return (weight.mean_weight);
}

float extrapolate_weight(data weight)
{
    days day;

    weight.loss_per_week = calculation_loss(weight);
    weight.extrapolation = weight.daily_weight[DAYS - 1] - (weight.loss_per_week);
    printf(CYAN "Based on your trend your weight in %d days should be: %0.2f\n" WHITE, DAYS, weight.extrapolation);
    printf("Estimate when you will reach a target goal. Enter your target: ");
    scanf("%f", &weight.weight_target);
    weight.weight_to_goal = weight.daily_weight[DAYS - 1] - weight.weight_target;
    weight.loss_per_day = weight.loss_per_week / DAYS;
    day.days_to_goal = (weight.weight_to_goal / (weight.loss_per_day));
    if (day.days_to_goal < 0)
    {
        printf(RED "Error, please set real target weight\n" WHITE);
        printf("Estimate when you will reach a target goal. Enter your target: ");
        scanf("%f", &weight.weight_target);
    }
    if (day.days_to_goal >= 0 && day.days_to_goal <= 7)
        printf(GREEN "You should reach your goal in less than a week! Keep going, you're almost there!\n" WHITE);
    if (day.days_to_goal > 7)
        printf(GREEN "You should reach your goal in %d days\n" WHITE, day.days_to_goal);
    return (weight.extrapolation);
}

