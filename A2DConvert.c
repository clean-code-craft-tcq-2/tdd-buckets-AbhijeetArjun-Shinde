#include <stdio.h>
#include "A2DConvert.h"

int ConvertToAmp(int CurrentSample){
  float ConvertedValue = (( 10 * CurrentSample) / 4094);
  float temp = ConvertedValue*10;
  float tempCheck = ( temp % 10);
  
  int roundNum;
  if(tempCheck>=5)
  {
    roundNum = ConvertedValue;
    roundNum++;
  }
  else
  {
    roundNum = ConvertedValue;
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
