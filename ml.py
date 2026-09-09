Machine Learning Lab_III Yr_I Sem_Avanthi_2026-27


1.Write a python program to compute Central Tendency Measures: Mean, Median, Mode Measure of Dispersion: Variance, Standard Deviation
Below is a Python program to calculate the Measures of Central Tendency (Mean, Median, Mode) and Measures of Dispersion (Variance, Standard Deviation) using the built-in statistics module.
# Python Program to Compute Mean, Median, Mode,
# Variance, and Standard Deviation

import statistics

# Input data
data = list(map(float, input("Enter the data values separated by spaces: ").split()))

# Mean
mean = statistics.mean(data)

# Median
median = statistics.median(data)

# Mode
try:
    mode = statistics.mode(data)
except statistics.StatisticsError:
    mode = "No unique mode"

# Variance (Sample Variance)
variance = statistics.variance(data)

# Standard Deviation (Sample Standard Deviation)
std_deviation = statistics.stdev(data)

# Display Results
print("\n----- Statistical Measures -----")
print("Mean               :", mean)
print("Median             :", median)
print("Mode               :", mode)
print("Variance           :", variance)
print("Standard Deviation :", std_deviation)
Sample Input
Enter the data values separated by spaces:
10 20 30 40 50
Sample Output
----- Statistical Measures -----
Mean               : 30.0
Median             : 30.0
Mode               : 10.0
Variance           : 250.0
Standard Deviation : 15.811388300841896
Manual Implementation (Without Using statistics Module)
import math
from collections import Counter

# Input data
data = list(map(float, input("Enter the data values separated by spaces: ").split()))
n = len(data)

# Mean
mean = sum(data) / n

# Median
sorted_data = sorted(data)
if n % 2 == 0:
    median = (sorted_data[n//2 - 1] + sorted_data[n//2]) / 2
else:
    median = sorted_data[n//2]

# Mode
count = Counter(data)
max_freq = max(count.values())
modes = [key for key, value in count.items() if value == max_freq]

if max_freq == 1:
    mode = "No Mode"
elif len(modes) == 1:
    mode = modes[0]
else:
    mode = modes

# Sample Variance
variance = sum((x - mean) ** 2 for x in data) / (n - 1)

# Sample Standard Deviation
std_deviation = math.sqrt(variance)

# Output
print("\nMean               :", mean)
print("Median             :", median)
print("Mode               :", mode)
print("Variance           :", variance)
print("Standard Deviation :", std_deviation)
.




2.Study of Python Basic Libraries such as Statistics, Math, Numpy and Scipy
Below is a Python program that demonstrates the use of the Statistics, Math, NumPy, and SciPy libraries. This is suitable for a Python Programming Lab experiment.
Python Program: Study of Basic Python Libraries (Statistics, Math, NumPy, SciPy)
# Study of Python Basic Libraries:
# Statistics, Math, NumPy, and SciPy

import statistics
import math
import numpy as np
from scipy import stats

# Sample Data
data = [10, 20, 30, 40, 50]

print("Original Data:", data)

# ---------------- Statistics Library ----------------
print("\n--- Statistics Library ---")
print("Mean               :", statistics.mean(data))
print("Median             :", statistics.median(data))
print("Mode               :", statistics.mode(data))
print("Variance           :", statistics.variance(data))
print("Standard Deviation :", statistics.stdev(data))

# ---------------- Math Library ----------------
print("\n--- Math Library ---")
print("Square Root of 25  :", math.sqrt(25))
print("Factorial of 5     :", math.factorial(5))
print("Power (2^5)        :", math.pow(2, 5))
print("Value of Pi        :", math.pi)
print("Value of e         :", math.e)
print("Log(10)            :", math.log(10))
print("Sin(30°)           :", math.sin(math.radians(30)))

# ---------------- NumPy Library ----------------
print("\n--- NumPy Library ---")
arr = np.array(data)

print("Array              :", arr)
print("Mean               :", np.mean(arr))
print("Median             :", np.median(arr))
print("Sum                :", np.sum(arr))
print("Maximum            :", np.max(arr))
print("Minimum            :", np.min(arr))
print("Standard Deviation :", np.std(arr))
print("Square of Array    :", np.square(arr))

# ---------------- SciPy Library ----------------
print("\n--- SciPy Library ---")
print("Mean               :", stats.tmean(arr))
print("Mode               :", stats.mode(arr, keepdims=True))
print("Skewness           :", stats.skew(arr))
print("Kurtosis           :", stats.kurtosis(arr))
print("Z-Score            :", stats.zscore(arr))
Sample Output
Original Data: [10, 20, 30, 40, 50]

--- Statistics Library ---
Mean               : 30
Median             : 30
Mode               : 10
Variance           : 250
Standard Deviation : 15.811388300841896

--- Math Library ---
Square Root of 25  : 5.0
Factorial of 5     : 120
Power (2^5)        : 32.0
Value of Pi        : 3.141592653589793
Value of e         : 2.718281828459045
Log(10)            : 2.302585092994046
Sin(30°)           : 0.5

--- NumPy Library ---
Array              : [10 20 30 40 50]
Mean               : 30.0
Median             : 30.0
Sum                : 150
Maximum            : 50
Minimum            : 10
Standard Deviation : 14.142135623730951
Square of Array    : [ 100  400  900 1600 2500]

--- SciPy Library ---
Mean               : 30.0
Mode               : ModeResult(mode=array([10]), count=array([1]))
Skewness           : 0.0
Kurtosis           : -1.3
Z-Score            : [-1.41421356 -0.70710678  0.  0.70710678  1.41421356]
Description of Libraries
Library
Purpose
Common Functions
Statistics
Performs statistical calculations
mean(), median(), mode(), variance(), stdev()
Math
Provides mathematical functions and constants
sqrt(), factorial(), pow(), log(), sin(), pi, e
NumPy
Efficient numerical computing and array operations
array(), mean(), sum(), max(), min(), std()
SciPy
Scientific computing and advanced statistics
stats.mode(), stats.skew(), stats.kurtosis(), stats.zscore()




3.Study of Python Libraries for ML application such as Pandas and Matplotlib
Below is a Python program to study the Pandas and Matplotlib libraries, which are widely used in Machine Learning for data manipulation and visualization.
Python Program: Study of Pandas and Matplotlib Libraries
# Study of Python Libraries for ML:
# Pandas and Matplotlib

import pandas as pd
import matplotlib.pyplot as plt

# Create a DataFrame
data = {
    "Student": ["A", "B", "C", "D", "E"],
    "Marks": [85, 90, 78, 92, 88],
    "Age": [20, 21, 20, 22, 21]
}

df = pd.DataFrame(data)

# ---------------- Pandas Operations ----------------
print("Original DataFrame")
print(df)

print("\nFirst 3 Rows")
print(df.head(3))

print("\nStatistical Summary")
print(df.describe())

print("\nAverage Marks:", df["Marks"].mean())
print("Maximum Marks:", df["Marks"].max())
print("Minimum Marks:", df["Marks"].min())

# ---------------- Matplotlib Visualization ----------------

# Bar Chart
plt.figure(figsize=(6,4))
plt.bar(df["Student"], df["Marks"])
plt.title("Student Marks")
plt.xlabel("Students")
plt.ylabel("Marks")
plt.grid(True)
plt.show()

# Line Chart
plt.figure(figsize=(6,4))
plt.plot(df["Student"], df["Marks"], marker='o')
plt.title("Student Marks Trend")
plt.xlabel("Students")
plt.ylabel("Marks")
plt.grid(True)
plt.show()

# Pie Chart
plt.figure(figsize=(6,6))
plt.pie(df["Marks"], labels=df["Student"], autopct="%1.1f%%")
plt.title("Marks Distribution")
plt.show()

Sample Output (Console)
Original DataFrame
  Student  Marks  Age
0       A     85   20
1       B     90   21
2       C     78   20
3       D     92   22
4       E     88   21

First 3 Rows
  Student  Marks  Age
0       A     85   20
1       B     90   21
2       C     78   20

Statistical Summary
           Marks        Age
count   5.000000   5.000000
mean   86.600000  20.800000
std     5.458938   0.836660
min    78.000000  20.000000
25%    85.000000  20.000000
50%    88.000000  21.000000
75%    90.000000  21.000000
max    92.000000  22.000000

Average Marks: 86.6
Maximum Marks: 92
Minimum Marks: 78

Expected Graphs
The program displays three graphs:
Bar Chart – Student vs. Marks 
Line Chart – Trend of Student Marks 
Pie Chart – Percentage distribution of Marks 

Common Functions Used
Pandas Library
Function
Purpose
DataFrame()
Creates a table (DataFrame)
head()
Displays first few rows
describe()
Generates statistical summary
mean()
Calculates average
max()
Finds maximum value
min()
Finds minimum value

Matplotlib Library
Function
Purpose
plt.bar()
Creates a bar chart
plt.plot()
Creates a line graph
plt.pie()
Creates a pie chart
plt.title()
Adds chart title
plt.xlabel()
Labels X-axis
plt.ylabel()
Labels Y-axis
plt.grid()
Displays grid lines
plt.show()
Displays the graph

This experiment introduces two essential Python libraries for Machine Learning:
Pandas for data loading, cleaning, manipulation, and statistical analysis. 
Matplotlib for visualizing data using bar charts, line graphs, pie charts, histograms, scatter plots, and other graphical representations. 
