#include "weight_track.h"

int main()
{
    data weight;

    weight = get_user_values();
    weight.mean_weight = mean_weight(weight);
    weight.extrapolation = extrapolate_weight(weight);
    printf_result_in_file(weight);
}