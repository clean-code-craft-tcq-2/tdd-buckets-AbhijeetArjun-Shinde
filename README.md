# Test Driven Ranges

The charging current varies during the process of charging.
We need to capture the range of current measurements -
what range of currents are most often encountered while charging.

> **DO NOT** jump into implementation! Read the example and the starting task below.

## Example

### Input

A set of periodic current samples from a charging session,
as an array of integers. For example:
`3, 3, 5, 4, 10, 11, 12`

### Functionality

The continuous ranges in there are: `3,4,5` and `10,11,12`.

The task is to detect the ranges and
output the number of readings in each range.

In this example,

- the `3-5` range has `4` readings
- the `10-12` range has `3` readings.

### Output

The expected output would be in comma-separated (csv format):

```
Range, Readings
3-5, 4
10-12, 3
```

## Tasks

Establish quality parameters: 

- What is the maximum complexity (CCN) per function? CCN=4
- How many lines of duplicate code will you tolerate? lines=3
- Ensure 100% line and branch coverage at every step. Include the coverage yml in the workflows.

Adapt/adopt/extend the `yml` files from one of your previous workflow folders.

Start Test-driven approach

1. Write the smallest possible failing test: give input `4,5`. assert output to be `4-5, 2`.
1. Write the minimum amount of code that'll make it pass.
1. Refactor any assumptions, continue to pass this test. Do not add any code without a corresponding test.


### Assumptions:
1. Input array of current samples may be sorted or may not be.
2. Input array of current samples is not an empty array


### Assumptions About the Sensor and A2D:
1. if the sensed current value is within correct range, then it will be converted to Amp.
2. if the sensed current value is outside range, then value is treated as 0Amp.

### Approach
Input --> Sequence of Charging sessions from either Sensor type 1 or Sensor type2.
Validating the sample sequence and converting to Ampere based on sensor type.
Sorting the sample sequence.
Slicing the sequence into ranges.
Counting the no. of readings in each range.
Printing the ranges and no. of readings.
