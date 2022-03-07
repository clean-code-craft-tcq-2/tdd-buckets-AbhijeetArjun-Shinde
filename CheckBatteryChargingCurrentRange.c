#include <stdio.h>
#include "CheckBatteryChargingCurrentRange.h"

int getLowerLimitCurrent( int CurrentSamples[] , int no_of_samples ){
  int lowerLimit = CurrentSamples[0];
  for (i = 1 , i < no_of_samples , i++ ){
    if(lowerLimit > CurrentSamples[i]){
      lowerLimit = CurrentSamples[i];
    }
  } 
  
  return lowerLimit;
}

int getUpperLimitCurrent( int CurrentSamples[] , int no_of_samples ){
  int upperLimit = CurrentSamples[0];
  for (i = 1 , i < no_of_samples , i++ ){
    if(upperLimit < CurrentSamples[i]){
      upperLimit = CurrentSamples[i];
    }
  } 
  return upperLimit;
}

char* CalculateChargingCurrentRange(int CurrentSamples[] , int no_of_samples){
  int LowerLimitCurrent = 0 ;
  int UpperLimitCurrent = 0 ;
  char buffer[50];
  LowerLimitCurrent = getLowerLimitCurrent(CurrentSamples , no_of_samples);
  UpperLimitCurrent = getUpperLimitCurrent(CurrentSamples , no_of_samples);
  sprintf(buffer , "%d - %d, %d", LowerLimitCurrent , UpperLimitCurrent , no_of_samples);
  return buffer;
  
}
