#include "heartRateUtils.h"

static int moving_average_counter = 0;

int moving_window_average(int* moving_average_array, int rate, int fhrMhr){
    int i, j;
    int average,value;
    switch(fhrMhr){
      case 0 : value = 10;
               break;
      case 1 : value = 20;
               break;
      default : break;
    }
    if(moving_average_counter <= value){
      moving_average_array[moving_average_counter - 1] = rate;
      average = meanInt(moving_average_array,moving_average_counter);
    }
    else{
      j = moving_average_counter;
      while((j / 20) != 0){
        j = moving_average_counter % 20;
      }
      if(j = 0){
        j = value;
      }
      moving_average_array[j - 1] = rate;
      average = meanInt(moving_average_array,value);
    }
    return average;
}

int heartRateAverage(int* diff, int size){
    int sum = 0;
    int i,k = 0;
    for(i = 0; i < size; i++){
        if(diff[i] != 0){
           sum += diff[i];
            k++;
        }
    }
    if(k != 0){
        return (sum/k);
    }
    else{
        return 0;
    }
}

int heartRate(int n, int* locs, int fhrMhr){
    int diff[3] = {0,0,0};
    int i,j ;
    for(i = 0; i < n; i++){
        if((locs[i+1]!= 0) || (locs[i] != 0)){
            diff[i] = locs[i+1] - locs[i];
            if(diff[i] < 0){
                diff[i] += 500;
            }
            if(diff[i] != 0){
                diff[i] = 30000/diff[i];
            }
        }
        if(diff[i] < 60){
            j = 0;
        }
        switch(n){
            case 1: if(fhrMhr){
                if((diff[i] > 200) || (diff[i] < 60)){
                diff[i] = 0;
                }
            }
            else{
                if((diff[i] > 120) || (diff[i] < 60)){
                diff[i] = 60;
                }
            }
            break;
            case 2: if(fhrMhr){
                if((diff[i] > 200) || (diff[i] < 60)){
                    diff[i] = 0;
                }
            }
            else{
                if((diff[i] > 120) || (diff[i] < 60)){
                    diff[i] = 60;
                }
            }
            break;
            case 3:if((diff[i] > 200) || (diff[i] < 60)){
                diff[i] = 0;
            }
            break;
            default: break;
        }
    }
    return heartRateAverage(diff,n);
}

int computeHeartRate(int* locs, int currentIndex, int* fhrMhrLocs, int fhrMhr){
    int i = 0, j = 0;
    int rate = 0;
    int movingRate = 0;

    appendArrayInt(locs + 1, fhrMhrLocs, currentIndex);

    if((currentIndex == 0) && (fhrMhr)){
      locs[currentIndex] = 0;
    }

    rate = heartRate(currentIndex, locs, fhrMhr);
    locs[0] = locs[currentIndex];

    return rate;
}

void comparePeaks(int* mhr_locs, int* fhr_locs, int mhrCount, int fhrCount){
    int locsDiff[6];
    int i = 0, j =0, k = 0;

    for(i = 0; i < fhrCount; i++){
        for(j = 0; j < mhrCount; j++){
            if((mhr_locs[j+1] - fhr_locs[i]) < 0){
                locsDiff[k] = (mhr_locs[j+1] - fhr_locs[i]) * (-1);
            }
            else{
                locsDiff[k] = mhr_locs[j+1] - fhr_locs[i];
            }

            if(locsDiff[k] < 20){
                if((k == 0) || (k == 1)){
                    fhr_locs[0] = 0;
                }
                else if((k == 2) || (k == 3)){
                    fhr_locs[1] = 0;
                }
                else if((k == 4) || (k == 5)){
                    fhr_locs[2] = 0;
                }
            }
            k++;
        }
    }
}
