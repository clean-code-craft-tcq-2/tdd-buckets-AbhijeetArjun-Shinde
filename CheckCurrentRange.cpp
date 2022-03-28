#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <stdbool.h>
#include "CheckBatteryChargingCurrentRange.h"

TEST_CASE("Test for Checking Upper and Lower Limits of Current Samples") {
  int CurrentSamples[] =  {2,3,4,5,2,3,4,7,8,9,8,7,5,6,7,12,14,15,11,12};
  int NoOfSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  bool result;
  char *ComputedRange;
  ComputedRange = CalculateChargingCurrentRange(CurrentSamples,NoOfSamples);
  char expectedOutput[] = "2 - 9, 15\n11 - 12, 3\n14 - 15, 2"; 
  result = strcmp(ComputedRange, expectedOutput);
  REQUIRE(result == 0); 
}
