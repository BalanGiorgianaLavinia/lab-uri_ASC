"""
    Basic thread handling exercise:

    Use the Thread class to create and run more than 10 threads which print their name and a random
    number they receive as argument. The number of threads must be received from the command line.

    e.g. Hello, I'm Thread-96 and I received the number 42

"""

import threading
import random
import sys

def function(randomNr):
    print("Thread " + str(threading.get_native_id()) + " received " + str(randomNr))


if __name__ == "__main__":
    listOfThreads = []

    nrOfThreads = (int)(sys.stdin.readline().strip())

    for i in range(nrOfThreads):
        t = threading.Thread(target=function, args=(random.randint(1,50),))
        listOfThreads.append(t)
        t.start()

    for i in range(len(listOfThreads)):
        listOfThreads[i].join()