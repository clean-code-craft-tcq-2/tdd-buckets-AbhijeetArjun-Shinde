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



char* getCurrentLimits( int *CurrentSamples , int no_of_samples ){

  
  int upperLimit[no_of_samples/2] = {0};
  int lowerLimit[no_of_samples/2] = {0};
  int NoOfSamples[no_of_samples/2] = {0};
  
  int j = 0, cntr=0 ;
  lowerLimit[j] = *(CurrentSamples);
  upperLimit[j] = *(CurrentSamples + no_of_samples -1);
  NoOfSamples[j] = no_of_samples;
  
  for (int i = 0 ; i < no_of_samples ; i++ ){
    if((*(CurrentSamples+i+1) - *(CurrentSamples+i)) >=MAX_LIMIT_SEPRATION_BW_INTERVALS){
      cntr++;
      upperLimit[j] = *(CurrentSamples+i);
      lowerLimit[j+1] = *(CurrentSamples+i+1);
      NoOfSamples[j] = cntr;
      
      upperLimit[j+1] = *(CurrentSamples+no_of_samples -1);
      NoOfSamples[j+1] = 1;
      j++;
      cntr = 0;
    }
    else
      cntr++;
  } 

  char outputString1[50];
  char outputString2[50];
  char *buffer1 = outputString1;
  char *buffer2 = outputString2;
  sprintf(buffer1 , "%d - %d, %d", lowerLimit[0] , upperLimit[0] , NoOfSamples[0]);
  
  for(int k=1; k < no_of_samples/2 ; k++){
    if(lowerLimit[k] !=0 && lowerLimit[k] <= 100){
      sprintf(buffer2 , "%d - %d, %d", lowerLimit[k] , upperLimit[k] , NoOfSamples[k]);
      strcat(buffer1,"\n ");
      strcat(buffer1,buffer2);
    }
  }
 printf("%s",buffer1);
 return buffer1 ;
}

char* CalculateChargingCurrentRange(int currentsamples[] , int no_of_samples){
  int *SortedSamples;
  SortedSamples = SortCurrentSamples(currentsamples,no_of_samples);
  
  getCurrentLimits(SortedSamples ,no_of_samples);
  
  
}
