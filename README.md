# CPU Scheduling Algorithms

A collection of CPU Scheduling algorithm implementations in C.

## Algorithms

| File | Algorithm |
|---|---|
| `FCFS1.c` | First Come First Serve - without Arrival Time |
| `FCFS2.c` | First Come First Serve - with Arrival Time |
| `SJF1.c` | Shortest Job First - without Arrival Time |
| `SJF2.c` | Shortest Job First - with Arrival Time |
| `RR1.c` | Round Robin - without Arrival Time |
| `RR2.c` | Round Robin - with Arrival Time |
| `Priority1.c` | Non-Preemptive Priority |
| `Priority2.c` | Preemptive Priority |
| `MLQ.c` | Multi-Level Queue |

### Multi-Level Queue

The implementation uses three queues with the following scheduling algorithms:

- **Queue 1:** First Come First Serve (FCFS)
- **Queue 2:** Round Robin (RR)
- **Queue 3:** Shortest Job First (SJF)

The queues are processed according to their priority, with Queue 1 having the highest priority and Queue 3 the lowest.
