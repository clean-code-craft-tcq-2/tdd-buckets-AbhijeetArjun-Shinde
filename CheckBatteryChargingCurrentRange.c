#include <stdio.h>
#include "CheckBatteryChargingCurrentRange.h"

int* SortCurrentSamples( int CurrentSamples[] , int no_of_samples ){
  int i, j, temp;
  for (i = 0; i < (no_of_samples - 1); i++){
   for (j = 0; j < no_of_samples - 1 - i; j++ ){
    if (CurrentSamples[j] > CurrentSamples[j+1]){
        temp = CurrentSamples[j+1];
        CurrentSamples[j+1] = CurrentSamples[j];
        CurrentSamples[j] = temp;
        }
      }
    }  
  return CurrentSamples;
}

char* getCurrentLimits( int CurrentSamples[] , int no_of_samples ){
  int *SortedSamples;
  SortedSamples = SortCurrentSamples(CurrentSamples,no_of_samples);
  
  int upperLimit[no_of_samples/2] = 0;
  int lowerLimit[no_of_samples/2] = 0;
  int NoOfSamples[no_of_samples/2] = 0;
  
  int j = 0 ;
  lowerLimit[j] = *(SortedSamples);
  upperLimit[j] = *(SortedSamples + no_of_samples -1);
  NoOfSamples[j] = no_of_samples;
  
  for (int i = 0 ; i < no_of_samples ; i++ ){
    if((*(SortedSamples+i+1) - *(SortedSamples+i)) >=2){
      upperLimit[j] = *(SortedSamples+i);
      lowerLimit[j+1] = *(SortedSamples+i+1);
      NoOfSamples[j] = i+1;
      
      upperLimit[j+1] = *(SortedSamples+no_of_samples -1);
      NoOfSamples[j+1] = no_of_samples - (i+1);
      j++;
    }
  } 

  char outputString[no_of_samples/2][50];
  char *buffer = outputString[0];
  sprintf(buffer , "%d - %d, %d", lowerLimit[0] , upperLimit[0] , NoOfSamples[0]);
  
  for(int k=1; k < no_of_samples/2 ; k++){
    if(lowerLimit[k] !=0 ){
      char *buffer = outputString[k];
      sprintf(buffer , "%d - %d, %d", lowerLimit[k] , upperLimit[k] , NoOfSamples[k]);
    }
  }
 return outputString ;
}

char* CalculateChargingCurrentRange(int CurrentSamples[] , int no_of_samples){
  char outputString[50];
  char *buffer = outputString;
  SortedSamples = SortCurrentSamples(CurrentSamples , no_of_samples);
  UpperLimitCurrent = getUpperLimitCurrent(CurrentSamples , no_of_samples);
  sprintf(buffer , "%d - %d, %d", UpperLimitCurrent , UpperLimitCurrent , no_of_samples);
  return buffer;
  
}
