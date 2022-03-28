#define MAX_LIMIT_SEPRATION_BW_INTERVALS 2

char* CalculateChargingCurrentRange(int currentsamples[] , int no_of_samples);
int* SortCurrentSamples( int CurrentSamples[] , int no_of_samples );
char* getCurrentLimits( int CurrentSamples[] , int no_of_samples );
char* OutputFormatter(int* lowerLimit,int* upperLimit, int* NoOfSamples,int no_of_samples,char *buffer1);
