#include <stdio.h>
#include "A2DConvert.h"

int ConvertToAmp(int CurrentSample){
  float ConvertedValue = (float( 10 * CurrentSample) / 4094);
  printf("converted value : %f \n",ConvertedValue);
  int temp = ConvertedValue*10;
  printf("temp value1 : %f \n",temp);
  int tempCheck = ( temp % 10);
  printf("remiander : %f \n",tempCheck);
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
