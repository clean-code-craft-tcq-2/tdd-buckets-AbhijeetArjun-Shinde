#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <stdbool.h>
#include "CheckBatteryChargingCurrentRange.h"

TEST_CASE("Test for Sorting Current Samples") {
  bool result;
  int CurrentSamples[] = {5,2,6,3,4,5,8,2,3,7,4,3,3};
  int ExpectedOutput[] = {2,2,3,3,3,3,4,4,5,5,6,7,8};
  int NoOfSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  int *SortedSamples;
  SortedSamples = SortCurrentSamples(CurrentSamples,NoOfSamples);
  for(int i =0; i < NoOfSamples ; i++){
    REQUIRE( *(SortedSamples+i) == ExpectedOutput[i]);
  }
  
}


/*TEST_CASE("Infers the battery charging current range and sample occurences in particular range") {
  bool result;
  char *ComputedRange;
  int CurrentSamples[] = {5,2,6,3,4,5,8,2,3,7,4,3,3};
  int NoOfSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  ComputedRange = CalculateChargingCurrentRange(CurrentSamples,NoOfSamples);
  result = strcmp(ComputedRange, "2 - 8, 13");
  REQUIRE(result == 0);
}*/
