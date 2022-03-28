#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <stdbool.h>
#include "CheckBatteryChargingCurrentRange.h"
#include "A2DConvert.h"

/*TEST_CASE("Test for Checking Upper and Lower Limits of Current Samples") {
  int CurrentSamples[] =  {2,3,4,5,2,3,4,7,8,9,8,7,5,6,7,12,14,15,11,12};
  int NoOfSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  bool result;
  char *ComputedRange;
  ComputedRange = CalculateChargingCurrentRange(CurrentSamples,NoOfSamples);
  char expectedOutput[] = "2 - 9, 15\n11 - 12, 3\n14 - 15, 2"; 
  result = strcmp(ComputedRange, expectedOutput);
  REQUIRE(result == 0); 
}


TEST_CASE("Test for Checking sensed current values within range- Sensor 1 ") {
  int SensedCurrentSamples1[] =  {0,1000,1250,1750,2300,4000,4094,3200,3500,5000,4095,3094};
  int NoOfSamples1 = sizeof(SensedCurrentSamples1)/sizeof(SensedCurrentSamples1[0]);
  bool result=0;
  int ConvertedOutput[NoOfSamples1];
  int *ConvertedOutputPtr=ConvertedOutput ;
  CheckConvertSensedCurrentToAmp(SensedCurrentSamples1,NoOfSamples1,ConvertedOutputPtr);
  int expectedOutput1[] = {0,2,3,4,6,10,10,8,9,0,0,8}; 
  for(int i =0; i < NoOfSamples1;i++){
    printf("%d\n", *(ConvertedOutputPtr+i));
    if(*(ConvertedOutputPtr+i) != expectedOutput1[i])
      result=1;
  }
  REQUIRE(result == 0); 
}

TEST_CASE("Test for Checking sensed current values within range and for Checking Upper and Lower Limits of Current Samples") {
  int SensedCurrentSamples[] =  {0,1000,1250,1750,2300,4000,4094,3200,3500,5000,4095,3094};
  int NoOfSamples = sizeof(SensedCurrentSamples)/sizeof(SensedCurrentSamples[0]);
  bool result=0;
  char expectedOutput[] = "0 - 0, 3\n2 - 4, 3\n6 - 6, 1\n8 - 10, 5"; 
  char *ComputedRange;
  ComputedRange = CalculateChargingCurrentRange(SensedCurrentSamples,NoOfSamples);
  result = strcmp(ComputedRange, expectedOutput);
  REQUIRE(result == 0); 
}*/


TEST_CASE("Test for Checking sensed current values within range- Sensor 2 ") {
  int SensedCurrentSamples2[] =  {0,100,200,330,423,449,499,510,511,512,625,679,800,917,950,1022,1024,1500};
  int NoOfSamples2 = sizeof(SensedCurrentSamples2)/sizeof(SensedCurrentSamples2[0]);
  bool result=0;
  int ConvertedOutput1[NoOfSamples2];
  int *ConvertedOutputPtr1=ConvertedOutput1 ;
  CheckConvertSensedCurrentToAmp1(SensedCurrentSamples2,NoOfSamples2,ConvertedOutputPtr1);
  int expectedOutput2[] = {15,12,9,5,3,2,0,0,0,0,3,5,8,12,13,15,0,0}; 
  for(int i =0; i < NoOfSamples2;i++){
    printf("%d\n", *(ConvertedOutputPtr1+i));
    if(*(ConvertedOutputPtr1+i) != expectedOutput2[i])
      result=1;
  }
  REQUIRE(result == 0); 
}
