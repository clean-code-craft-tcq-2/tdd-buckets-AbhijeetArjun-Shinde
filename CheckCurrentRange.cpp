#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <stdbool.h>
#include "CheckBatteryChargingCurrentRange.h"

TEST_CASE("Test for Sorting Current Samples") {
  int CurrentSamples[] = {5,2,6,3,4,5,8,2,3,7,4,3,3};
  int ExpectedOutput[] = {2,2,3,3,3,3,4,4,5,5,6,7,8};
  int NoOfSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  int *SortedSamples;
  SortedSamples = SortCurrentSamples(CurrentSamples,NoOfSamples);
  for(int k=0; k < NoOfSamples ; k++){
    REQUIRE( *(SortedSamples+k) == ExpectedOutput[k]);
  }  
}

TEST_CASE("Test for Checking Upper and Lower Limits of Current Samples") {
  int CurrentSamples[] = {5,2,6,12,4,13,8,15,3,7,4,3,3};
  int NoOfSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  bool result;
  char *ComputedRange;
  ComputedRange = CalculateChargingCurrentRange(CurrentSamples,NoOfSamples);
  char expectedOutput[] = "2 - 8, 10\n12 - 13, 2\n15 - 15, 1"; 
  result = strcmp(ComputedRange, expectedOutput);
  REQUIRE(result == 0); 
}
