#include <stdio.h>
#include "A2DConvert.h"

int ConvertToAmp(int CurrentSample){
  return (int)((10 * CurrentSample)/4094);
}


void CheckConvertSensedCurrentToAmp(int *CurrentSamples, int NoOfSamples, int *ConvertedSamples){
  
  for(int i = 0; i < NoOfSamples;i++){
    if(*(CurrentSamples+i) <= 4094){
      *(ConvertedSamples+i) = ConvertToAmp(*(CurrentSamples+i));
    }
    else{
     printf("Invalid Input\n");
     *(ConvertedSamples+i) = 0;       
    }
  }
}
