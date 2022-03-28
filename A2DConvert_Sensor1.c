#include <stdio.h>
#include "A2DConvert.h"

int ConvertToAmp(int CurrentSample){
  float ConvertedValue = (float( 10 * CurrentSample) / 4094);
  int temp = ConvertedValue*10;
  int tempCheck = ( temp % 10);
  if(tempCheck>=5)
  {
    return (int(++ConvertedValue));
  }
  else
  {
    return (int(ConvertedValue));
  }
}


void CheckConvertSensedCurrentToAmp(int *CurrentSamples, int NoOfSamples, int *ConvertedSamples){
  
  for(int i = 0; i < NoOfSamples;i++){
    if(*(CurrentSamples+i) <= 4094 && *(CurrentSamples+i) >= 0){
      *(ConvertedSamples+i) = ConvertToAmp(*(CurrentSamples+i));
    }
    else{
     printf("Invalid Input\n");
     *(ConvertedSamples+i) = 0;       
    }
  }
}
