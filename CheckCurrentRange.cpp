#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <stdbool.h>
#include "CheckBatteryChargingCurrentRange.h"


TEST_CASE("Test for Checking Upper and Lower Limits of Current Samples") {
  int CurrentSamples[] =  {5,2,6,3,4,5,8,2,3,7,4,3,3};
  int NoOfSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  bool result;
  char *ComputedRange;
  ComputedRange = CalculateChargingCurrentRange(CurrentSamples,NoOfSamples);
  char expectedOutput[] = "2 - 8, 13"; 
  result = strcmp(ComputedRange, expectedOutput);
  REQUIRE(result == 0); 
}


TEST_CASE("Test for Checking Upper and Lower Limits of Current Samples") {
  int CurrentSamples[] =  {5,2,10,3,13,5,8,2,14,7,15,3,17,18,19,20};
  int NoOfSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  bool result;
  char *ComputedRange;
  ComputedRange = CalculateChargingCurrentRange(CurrentSamples,NoOfSamples);
  char expectedOutput[] = "2 - 3, 4\n 5 - 5,2\n8 - 8,1\n10 - 10,1\n13 - 15,3\n17 - 20,4"; 
  result = strcmp(ComputedRange, expectedOutput);
  REQUIRE(result == 0); 
}
