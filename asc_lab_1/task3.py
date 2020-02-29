"""
Coffee Factory: A multiple producer - multiple consumer approach

Generate a base class Coffee which knows only the coffee name
Create the Espresso, Americano and Cappuccino classes which inherit the base class knowing that
each coffee type has a predetermined size.
Each of these classes have a get message method

Create 3 additional classes as following:
    * Distributor - A shared space where the producers puts coffees and the consumers takes them
    * CoffeeFactory - An infinite loop, which always sends coffees to the distributor
    * User - Another infinite loop, which always takes coffees from the distributor

The scope of this exercise is to correctly use threads, classes and synchronization objects.
The size of the coffee (ex. small, medium, large) is chosen randomly everytime.
The coffee type is chosen randomly everytime.

Example of output:

Consumer 65 consumed espresso
Factory 7 produced a nice small espresso
Consumer 87 consumed cappuccino
Factory 9 produced an italian medium cappuccino
Consumer 90 consumed americano
Consumer 84 consumed espresso
Factory 8 produced a strong medium americano
Consumer 135 consumed cappuccino
Consumer 94 consumed americano
"""
import sys
import threading
import random

coffeeTypes = ["Americano", "Espresso", "Capuccino"]
coffeeSize = ["small", "medium", "large"]

producerSem = None
consumerSem = threading.Semaphore(value=0)
distribuitor = None

class Coffee:
    """ Base class """
    def __init__(self, coffeeType, size):
        self.coffeeType = coffeeType
        self.size = size

    def get_name(self):
        """ Returns the coffee name """
        return self.coffeeType

    def get_size(self):
        """ Returns the coffee size """
        return self.size



class Americano(Coffee):
    def __init__(self):
        super().__init__("Americano", coffeeSize[random.randint(0,2)])

    def get_message(self):
        print("Type of coffee " + self.get_name())



class Espresso(Coffee):
    def __init__(self):
        super().__init__("Espresso", coffeeSize[random.randint(0,2)])

    def get_message(self):
        print("Type of coffee " + self.get_name())    


class Capuccino(Coffee):
    def __init__(self):
        super().__init__("Capuccino", coffeeSize[random.randint(0,2)])        

    def get_message(self):
        print("Type of coffee " + self.get_name())


class Distributor:

    def __init__(self, sizeOfBuff = 0):
        self.buff = []
        self.sizeOfBuff = sizeOfBuff

    def get_coffee(self):
        return (self.buff.pop())

    def put_coffee(self, coffee):
        self.buff.append(coffee)



class CoffeeFactory(threading.Thread):
    def __init__(self, distribuitor):
        super().__init__()
        self.distribuitor = distribuitor
    
    def run(self):
        randomType = coffeeTypes[random.randint(0,2)]

        newCoffee = None

        if randomType == "Americano":
            newCoffee = Americano()
        elif randomType == "Espresso":
            newCoffee = Espresso()
        elif randomType == "Capuccino":
            newCoffee = Capuccino()        

        print("Producer " + str(threading.get_native_id()) + " produce " + str(newCoffee.get_size()) + " " + newCoffee.get_name())

        producerSem.acquire()
        self.distribuitor.put_coffee(newCoffee)
        consumerSem.release()




class User(threading.Thread):
    def __init__(self, distribuitor):
        super().__init__()
        self.distribuitor = distribuitor

    def run(self):
        consumerSem.acquire()
        new_coffee = self.distribuitor.get_coffee()
        producerSem.release()

        print("Consumer " +  str(threading.get_native_id()) + " consumed " + new_coffee.get_name())




if __name__ == '__main__':
    print("Type number of producers: ")
    nrProd = (int)(sys.stdin.readline().strip())

    print("Type number of consumers: ")
    nrConsum = (int)(sys.stdin.readline().strip())

    print("Type size of Buffer: ")
    sizeBuff = (int)(sys.stdin.readline().strip())

    distribuitor = Distributor(sizeBuff)

    listOfProd = []
    listOfConsum = []

    producerSem = threading.Semaphore(nrProd)
    #consumerSem = threading.Semaphore(0)

    for i in range(nrProd):
        prod = CoffeeFactory(distribuitor)
        prod.start()
        listOfProd.append(prod)

    for i in range(nrConsum):
        cons = User(distribuitor)
        cons.start()
        listOfConsum.append(cons)

    for i in range(nrProd):
        listOfProd[i].join()

    for i in range(nrConsum):
        listOfConsum[i].join()        