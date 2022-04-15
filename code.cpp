#include <iostream> 
#include <math.h> 
using namespace std;
void sort(int p[], int n); 
int main()
{
int n, p[10], a[10], b[10], y, z, k, count1 = 0, count2 = 0, count3 =
0;
double sum, mean, median, x, tq, sum1, avg, tqnw, tavg, sumpo = 0, sumx = 0, sumy = 0, sumz = 0;
cout << "Enter the No of Processes :";// Taking INPUTS
cin >> n;
for (int i = 0; i < n; i++)
{
cout << "Enter the Burst Time For Process" << i + 1 << ": "; 
cin >> p[i]; // Taking INPUTS
sum = sum + p[i];
}
mean = sum / n;// Calculating Mean
sort(p, n); // Sorting in increasing order
if (n % 2 == 0)//Calculating Median
{
median = (p[n / 2 - 1] + p[n / 2]) / 2;	
}
else
{
median = p[n / 2];
}
x = log10(mean + median) *(log(mean + median) + mean - p[0]);
//Calculating Time Quantum
if (x > mean && x > median)
{
tq = x; // Assigning value;
}
else
{
tq = x + (median - p[0]);
}
y = floor(tq);
cout << "Time quantum : " << y << "\n"; 
for (int i = 0; i < n; i++)
{
if (p[i] <= y) //if burst time of a process is less than Time
{
a[count1] = p[i]; //forming new array a[] of those
count1 = count1 + 1;
sumpo = sumpo + p[i]; //Calculating sum of all those Quantum  processses
}
else //if burst time of a process is greater than Time
{
b[count2] = p[i]; //forming new array b[] of those
count2 = count2 + 1;
sum1 = sum1 + p[i]; //Calculating sum of all those
}
}
if (count2 > 1)
{
avg = sum1 / count2; //Calculating mean of those processes  whose burst time is greater than Time Quantum
tqnw = avg + log(b[count2 - 1] - b[0]); //Calculating  new Time Quantum as sum of mean and log of max burst time - min burst time of the remaining processes
}
else
{
tqnw = b[0]; //if there is only one process
}
z = floor(tqnw);
cout << "Time quantum changed : " << z << "\n"; 
for (int i = 0; i < count1; i++)
{
sumx = sumx + (a[i] *(count1 - i)); //calculating sum of all a[i] processes
}
for (int i = 0; i < count2; i++)
{
if (b[i] <= tqnw)
{
count3 = count3 + 1;
}
}
for (int i = 0; i < count3; i++)
{
sumy = sumy + sumpo + (b[i] *(count3 - i)); // calculating sum of remaining processes lesser than 2nd time quantum
}
sumz = sumy + sumx + z; //calculating Total Waiting Time
tavg = sumz / n; //calculating Avg Waiting Time 
cout << "Avg. Waiting Time : " << tavg << "\n"; 
return (0);
}
void sort(int p[], int n) //sorting function
{
for (int i = 0; i < n; i++)
{
for (int j = i + 1; j < n; j++)
{
if (p[i] > p[j])
{
int temp = p[i]; 
p[i] = p[j]; 
p[j] = temp;
}
}
}
}
