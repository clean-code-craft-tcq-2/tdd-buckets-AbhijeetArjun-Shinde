#include <stdio.h>
#include "CheckBatteryChargingCurrentRange.h"
#include <string.h>

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

char* OutputFormatter(int* lowerLimit,int* upperLimit, int* NoOfSamples,int no_of_samples){
  char outputString1[50];
  char *buffer1 = outputString1;
  sprintf(buffer1 , "%d - %d, %d", lowerLimit[0] , upperLimit[0] , NoOfSamples[0]);
  printf("%s",buffer1);
  return buffer1 ;
}

char* getCurrentLimits( int *CurrentSamples , int no_of_samples ){
  int upperLimit[no_of_samples/2] = {0};
  int lowerLimit[no_of_samples/2] = {0};
  int NoOfSamples[no_of_samples/2] = {0};
  
  lowerLimit[j] = *(CurrentSamples);
  upperLimit[j] = *(CurrentSamples + no_of_samples -1);
  NoOfSamples[j] = no_of_samples;
  
  char *OutputString;
  OutputString = OutputFormatter(lowerLimit,upperLimit,NoOfSamples,no_of_samples);
  return OutputString;
  
}

char* CalculateChargingCurrentRange(int currentsamples[] , int no_of_samples){
  int *SortedSamples;
  SortedSamples = SortCurrentSamples(currentsamples,no_of_samples);
  char *OutputString;
  OutputString = getCurrentLimits(SortedSamples ,no_of_samples);
  return OutputString;
  
}
