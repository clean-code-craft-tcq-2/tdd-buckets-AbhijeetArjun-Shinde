#define MAX_LIMIT_SEPRATION_BW_INTERVALS 2
#define AVAILABLE_SENSOR_TYPE 1 /* 1-- Sensor with 10Amps output , 2-- Sensor with 15Amps output*/
char* CalculateChargingCurrentRange(int currentsamples[] , int no_of_samples);
void getCurrentLimits( int *CurrentSamples , int no_of_samples,char *OutputString );
void OutputFormatter(int* lowerLimit,int* upperLimit, int* NoOfSamples,int no_of_samples,char *buffer1);
