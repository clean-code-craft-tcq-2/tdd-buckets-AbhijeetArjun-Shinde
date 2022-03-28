#include <stdio.h>
#include "A2DConvert.h"

int ConvertToAmp1(int CurrentSample){
  float ConvertedValue = (float( 30 * CurrentSample) / 1022) - 15;
  int temp = ConvertedValue*10;
  int tempCheck = ( temp % 10);
  if(tempCheck>=5)
  {
    return abs((int(++ConvertedValue)));
  }
  else
  {
    return abs((int(ConvertedValue)));
  }
}


void CheckConvertSensedCurrentToAmp1(int *CurrentSamples, int NoOfSamples, int *ConvertedSamples){
  
  for(int i = 0; i < NoOfSamples;i++){
    if(*(CurrentSamples+i) <= 1022 && *(CurrentSamples+i) >= 0){
      *(ConvertedSamples+i) = ConvertToAmp(*(CurrentSamples+i));
    }
    else{
     printf("Invalid Input\n");
     *(ConvertedSamples+i) = 511;       
    }
  }
}
