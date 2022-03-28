#include <stdio.h>
#include "A2DConvert.h"

int ConvertToAmp(int CurrentSample){
  float temp = CurrentSample*10;
  float tempCheck = ( temp % 10);
  int roundNum;
  if(tempCheck>=5)
  {
    roundNum = CurrentSample;
    roundNum++;
  }
  else
  {
    roundNum = CurrentSample;
  }
  
  return roundNum;
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
