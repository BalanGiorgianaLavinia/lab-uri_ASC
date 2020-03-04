import random
import threading
from concurrent.futures.thread import ThreadPoolExecutor
from concurrent.futures import as_completed

seq = ['A', 'T', 'G', 'C']

def random_sample():
    sample = []
    for i in range(0, 10000):
        sample.append(random.choice(seq))
    return ''.join(sample)


def thread_func(index, samples, my_str):
    if my_str in samples[index]:
        print("DNA sequence found în sample " + str(index))
    else:
        print("NOT FOUND in sample " + str(index))


if __name__ == "__main__":
    
    samples = []    
    for i in range(0, 100):
        samples.append(random_sample())

    my_str = samples[80][400:420]

    for i in range(0,100):
        with ThreadPoolExecutor(max_workers=30) as executor:
            future = executor.submit(thread_func, i, samples, my_str)
            print(future.result())