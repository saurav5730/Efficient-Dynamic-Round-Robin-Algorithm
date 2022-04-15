# Efficient-Dynamic-Round-Robin-Algorithm
Operating systems are resource managers. The resources managed by operating systems are hardware, storage units, input devices, output devices and data. Operating systems perform many functions such as implementing user interface, sharing hardware among users, facilitating input/output, accounting for resource usage, organizing data, etc.

Whenever CPU becomes idle, a waiting process from ready queue is selected and CPU is allocated to that. The performance of the scheduling algorithm mainly depends on CPU utilization, throughput, turnaround time, waiting time, response time, and context switch. In Round Robin a small unit of time is used which is called Time Quantum or Time slice. The CPU scheduler goes around the ready queueallocating the CPU to each process for a time interval up to1 time quantum. If a process’s CPU burst exceeds 1 time quantum, that process is pre-empt and is put back in the ready queue .If a new process arrives then it is added to the tail of the circular queue. RR provides better performance as compared to the others in case of a time sharing operating system.

# Objective
To design a new Dynamic Round Robin Algorithm for increasing the performance of the CPU by decreasing the average waiting time and minimizing the number of context switches.To make one scheduling algorithm of our own and compare its waiting and turnaround time with other algorithms already there.

# Proposed Algorithm
Our algorithm has taken the logarithm of a value and multiply it with the sum of two other values. Now, the mean of a data is that value which represents the entire data set in one value and it is the mean with which each value in the data set can correspond itself to. The median is the middle-most value of the data. So, the mean and median are the measures of central tendency, it is these values which can give us a representative value for the entire data. Thus, we have taken the logarithm of the sum of mean and median of the burst time of the processes. Now this logarithm is multiplied by the sum of natural log of mean and median and the difference between the mean and lowest burst time.

                                 𝑥 = log(𝑚𝑒𝑎𝑛 + 𝑚𝑒𝑑𝑖𝑎𝑛) ∗ (ln(𝑚𝑒𝑎𝑛 + 𝑚𝑒𝑑𝑖𝑎𝑛) + (𝑚𝑒𝑎𝑛 − 𝑙𝑜𝑤𝑒𝑠𝑡 𝑏𝑢𝑟𝑠𝑡 𝑡𝑖𝑚𝑒))
Now, consider an equation: 𝒚 = 𝟏𝟔 𝒍𝒏(𝒙) + 𝟑1

We now compute the values of y for x=1 to x=10. The value of y increases with the increasing value of x, indicating that the graph will be increasing. At the same time, another trend is observed that the difference between the values of y for increasing x is decreasing. Example, the difference between the values of y for x=1 and x=4 is 22.18. But the difference between thevalues of y for x=7 and x=10 is only 5.71. This indicates that there is a decay in the rate of rise in our graph. The graph will be of increasing nature but the rate of increase will be decreasing with the increasing value of x.

![image](https://user-images.githubusercontent.com/103409230/163602772-66066898-f551-47f9-8a87-686994e368f1.png)

The graph of the above equation is rising but the rate of increase of graph is decreasing. This forms the basis of choosing our time quantum. The value of time quantum must increase initially at a faster rate so that it can accommodate or allow the processes with lower burst time to be executed. But at the same time, this value of time quantum must not increase at such a rapid rate that it exceeds the maximum burst item or becoming equal to that of maximum burst time.

                             𝒙 = 𝐥𝐨𝐠(𝒎𝒆𝒂𝒏+𝒎𝒆𝒅𝒊𝒂𝒏) ∗ (𝐥𝐧(𝒎𝒆𝒂𝒏+𝒎𝒆𝒅𝒊𝒂𝒏) + (𝒎𝒆𝒂𝒏− 𝒍𝒐𝒘𝒆𝒔𝒕 𝒃𝒖𝒓𝒔𝒕 𝒕𝒊𝒎𝒆))
If x is greater than both mean and median, then we assign time quantum as x because x has already covered both mean and median and rather passed them.

                                                           Time Quantum=x;
Otherwise, if x lies between mean and median or is lower than both mean and median, then there is a need to add something to the value of x, so that it can cover/include both mean and median again. For this, we add (median-lowest burst time) to the value of x and assign that value to our time quantum.

                                                  Time Quantum=x+(Mean-Lowest burst time);
Now, the processes which are less than or equal to that of time quantum, will be executed in increasing order of their burst times. For those processes, which are greater than this time quantum, we assign a different value of time quantum for those processes. Again, the same concept is applied here as well, that is, to stabilize the time quantum to an appropriate value. For such, processes we calculate the time quantum as the sum of the mean of remaining processes and the natural log of the difference between the maximum and minimum burst time in the remaining processes.

          Time quantum= mean of remaining processes + ln(maximum burst time in remaining processes-minimum burst time in remaining processes)
