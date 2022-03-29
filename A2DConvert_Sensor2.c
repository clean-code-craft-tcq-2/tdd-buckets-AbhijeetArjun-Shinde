#include <stdio.h>
#include <stdlib.h>
#include "A2DConvert.h"

int ConvertToAmp_Sensor2(int CurrentSample){
  float ConvertedValue = abs((float( 30 * CurrentSample) / 1022) - 15);
  int temp = ConvertedValue*10;
  int tempCheck = ( temp % 10);
  if(tempCheck>=5)
  {
    return int(++ConvertedValue);
  }
  else
  {
    return int(ConvertedValue);
  }
}


void CheckAndConvertSensedCurrentToAmp_Sensor2(int *CurrentSamples, int NoOfSamples, int *ConvertedSamples){
  
  for(int i = 0; i < NoOfSamples;i++){
    if(*(CurrentSamples+i) <= 1022 && *(CurrentSamples+i) >= 0){
      *(ConvertedSamples+i) = ConvertToAmp_Sensor2(*(CurrentSamples+i));
    }
    else{
     printf("Invalid Input\n");
     *(ConvertedSamples+i) = 0;       
    }
  }
}
