import random

with open("search.txt",'w') as file:
    for i in range (1000000):
      x=random.randint(0,10000000)
      file.write(str(x) + '\n')