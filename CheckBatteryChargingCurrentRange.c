#include <stdio.h>
#include "CheckBatteryChargingCurrentRange.h"

int* SortCurrentSamples( int CurrentSamples[] , int no_of_samples ){
  int i, j, temp;
  for (i = 0; i < (no_of_samples - 1); i++)
    {
      for (j = 0; j < no_of_samples - 1 - i; j++ )
       {
            if (CurrentSamples[j] > CurrentSamples[j+1])
            {
                temp = CurrentSamples[j+1];
                CurrentSamples[j+1] = CurrentSamples[j];
                CurrentSamples[j] = temp;
            }
        }
    }  
  return CurrentSamples;
}

int getUpperLimitCurrent( int CurrentSamples[] , int no_of_samples ){
  int upperLimit = CurrentSamples[0];
  int i;
  for (i = 1 ; i < no_of_samples ; i++ ){
    if(upperLimit < CurrentSamples[i]){
      upperLimit = CurrentSamples[i];
    }
  } 
  return upperLimit;
}

char* CalculateChargingCurrentRange(int CurrentSamples[] , int no_of_samples){
  int *SortedSamples;
  int UpperLimitCurrent = 0 ;
  char outputString[50];
  char *buffer = outputString;
  SortedSamples = SortCurrentSamples(CurrentSamples , no_of_samples);
  UpperLimitCurrent = getUpperLimitCurrent(CurrentSamples , no_of_samples);
  sprintf(buffer , "%d - %d, %d", UpperLimitCurrent , UpperLimitCurrent , no_of_samples);
  return buffer;
  
}
