# Dining Philosophers Problem
<p align="center"> 
<img src="https://sphof.readthedocs.io/_images/philtable.png" align="center" width="500" height="300">
</p>

The Dining Philosophers Problem is a classic problem in computer science and distributed systems. It is a problem of resource allocation and synchronization in a multi-process environment, where n philosophers are sitting at a round table and share chopsticks between them. 

Each philosopher needs two chopsticks to eat, one to his left and the other to his right. The problem is to design a system in which each philosopher can eat without causing a deadlock (a situation where all philosophers are waiting for one another to release a chopstick) or a starvation (a situation where a philosopher is unable to eat indefinitely). 

There are various solutions to this problem, including a naive solution that leads to a deadlock, a resource hierarchy solution that prevents deadlock but may lead to starvation, and a solution based on timeouts and retries that avoids both deadlock and starvation. 

The Dining Philosophers Problem is used to illustrate the challenges of achieving mutual exclusion and deadlock avoidance in a multi-process environment. It has practical applications in distributed systems, operating systems, and database management systems.
# how to execute it? 
    make run


### i want to  excute it with my own paramter 
    ./philosopher [nbr-philo] [time-to-die] [time-to-eat] [time-to-think]



### i am not on unix system how to run this
https://replit.com/@jpmartel98/philosopher




