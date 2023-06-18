/*Do a makefile
Rajouter la perte de mois
Rajouter la perte de trimestre
Rajouter la perte de semestre 
Rajouter la perte de l'année*/

#ifndef WEIGHT_TRACK_H
#define WEIGHT_TRACK_H

#include <stdio.h>
#include <time.h>
#include <math.h>


#define DAYS 7

/* Colors*/
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE "\033[0;37m"
#define CYAN "\033[0;36m"

typedef struct weight_data {
    float loss_per_week;
    float loss_per_day;
    float mean_weight;
    float sum_weight;
    float weight_target;
    float weight_to_goal;
    float extrapolation;
    float daily_weight[DAYS];
} data;

typedef struct days_data{
    int number_of_days;
    int days_to_goal;
} days;


data get_user_values();
float mean_weight(data weight);
float extrapolate_weight(data weight);
float calculation_loss(data weight);
void goal_road(data weight);
int printf_result_in_file(data weight);
int day_to_goal(days day);

#endif