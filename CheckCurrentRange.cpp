#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <stdbool.h>
#include "CheckBatteryChargingCurrentRange.h"
TEST_CASE("Infers the battery charging current range and sample occurences in particular range") {
  bool result;
  char ComputedRange[];
  int CurrentSamples[] = {8,2,6,3,4,5,8,2,3,7,4,3,3};
  int NoOfSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  ComputedRange = CalculateChargingCurrentRange(CurrentSamples,NoOfSamples);
  result = strcmp(ComputedRange, "2-8 , 13");
  REQUIRE(result == 0);
}
