#include <stdio.h>
#include <stdlib.h>
#include "CheckBatteryChargingCurrentRange.h"
#include <string.h>


int CompareFunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

char* OutputFormatter(int* lowerLimit,int* upperLimit, int* NoOfSamples,int no_of_samples,char *buffer1){
  char outputString2[50];
  char *buffer2 = outputString2;
  sprintf(buffer1 , "%d - %d, %d", lowerLimit[0] , upperLimit[0] , NoOfSamples[0]);
  
  for(int k=1; k < no_of_samples/2 ; k++){
    if(lowerLimit[k] !=0 && lowerLimit[k] <= 100){
      sprintf(buffer2 , "%d - %d, %d", lowerLimit[k] , upperLimit[k] , NoOfSamples[k]);
      strcat(buffer1,"\n");
      strcat(buffer1,buffer2);
    }
  }
 printf("%s",buffer1);
 return buffer1 ;
}

char* getCurrentLimits( int *CurrentSamples , int no_of_samples,char *OutputString ){
  int upperLimit[no_of_samples/2] = {0};
  int lowerLimit[no_of_samples/2] = {0};
  int NoOfSamples[no_of_samples/2] = {0};
  int j = 0, cntr=0 ;
  
  //AT beginning lower limit = first element of sorted array, upper limit= last element of sorted array, no of samples in this range = samples in given input array
  lowerLimit[j] = *(CurrentSamples);
  upperLimit[j] = *(CurrentSamples + no_of_samples -1);
  NoOfSamples[j] = no_of_samples;
  
  for (int i = 0 ; i < no_of_samples ; i++ ){
    cntr++;
    NoOfSamples[j] = cntr;
    if((*(CurrentSamples+i+1) - *(CurrentSamples+i)) >=MAX_LIMIT_SEPRATION_BW_INTERVALS){
      upperLimit[j] = *(CurrentSamples+i);
      
      lowerLimit[j+1] = *(CurrentSamples+i+1);
      upperLimit[j+1] = *(CurrentSamples+no_of_samples -1);
      j++;
      cntr = 0;
    }
  } 
   

  OutputString = OutputFormatter(lowerLimit,upperLimit,NoOfSamples,no_of_samples,OutputString);
  return OutputString;
}

char* CalculateChargingCurrentRange(int currentsamples[] , int no_of_samples){
  qsort(currentsamples, no_of_samples, sizeof(int), CompareFunc);
   
  char outputStr[50];
  char *OutputString = outputStr;
  OutputString = getCurrentLimits(currentsamples ,no_of_samples,OutputString);
  return OutputString;
  
}
