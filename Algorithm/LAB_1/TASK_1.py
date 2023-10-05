import random

def linear_search(a,n,target):
  comparison=0
  for i in range(n):
    comparison+=1
    if a[i] == target:
       return i,comparison
  return -1,comparison


def binary_search(a,n,target):
  comparison = 0
  low,high=0,n-1
  comparison+=1
  while low<=high :
    comparison+=1
    mid=(low+high)//2
    comparison+=1
    if a[mid]==target:
      comparison+=1
      return mid,comparison
    elif a[mid] < target:
      comparison+=1
      low = mid+1
    else:
      comparison+=1
      high = mid-1
  return -1,comparison
'''
with open("search.txt",'w') as file:
    for i in range (1000000):
      x=random.randint(0,2**63-1)
      file.write(str(x) + '\n')
'''

def read_input_file(file_path):
    with open(file_path, 'r') as file:
        data = [int(line.strip()) for line in file]
    return data
    
  
for i in range(100000):
    file_path = f'search.txt'
    data = read_input_file(file_path)
    size = len(data)
    
    target_value = int(input("Enter the value that needed to be found: "))

    # Linear Search
    linear_result, linear_comparisons = linear_search(data, size, target_value)
    if linear_result != -1:
      print(f"Linear Search for : Index {linear_result}, Comparisons {linear_comparisons}")
    else:
       print("The number isn't in the list!!")

    # Binary Search
    sorted_data = sorted(data)
    binary_result, binary_comparisons = binary_search(sorted_data, size, target_value)
    if binary_result != -1:
      print(f"Binary Search for : Index {binary_result}, Comparisons {binary_comparisons}")
    else:
       print("The number isn't in the list!!")
