class node:
  def __init__(self, data):
    self.left = None
    self.right = None
    self.data = data

def root_to_leaf(n, elements):
  # check is empty node
  if n is None:
    print(elements)
    return
  # append myself
  elements.append(n.data)
  # if is leaf
  if n.left is None and n.right is None:
    print(elements)
    del elements[-1]
    return
  if n.left is not None:
    root_to_leaf(n.left, elements)
  if n.right is not None: 
    root_to_leaf(n.right, elements)
  del elements[-1]

def update_max_distinct(unique_elements, current_max):
  if len(unique_elements) > current_max:
      current_max = len(unique_elements)
  return current_max

def decrease_element_count(unique_elements, key):
  if key in unique_elements:
    unique_elements[key] -= 1
    if unique_elements[key] == 0:
      unique_elements.pop(key, None)

def longest_distinct_path(n, unique_elements, current_max):
  # check is empty node
  if n is None:
    return update_max_distinct(unique_elements, current_max)
  # append myself
  if n.data in unique_elements:
    unique_elements[n.data] += 1
  else:
    unique_elements[n.data] = 1
  # if is leaf
  if n.left is None and n.right is None:
    current_max = update_max_distinct(unique_elements, current_max)
    decrease_element_count(unique_elements, n.data)
    return current_max
  if n.left is not None:
    current_max = longest_distinct_path(n.left, unique_elements, current_max)
  if n.right is not None: 
    current_max = longest_distinct_path(n.right, unique_elements, current_max)
  decrease_element_count(unique_elements, n.data)
  return current_max

n = node(5)
n.left = node(5)
n.right = node(5)
n.right.right = node(6)
n.right.right.right = node(7)
n.right.right.right.right = node(8)
n.left.left = node(3)
n.left.left.left = node(5)
n.left.left.right = node(5)
n.left.left.right.left = node(3)
n.left.right = node(4)
n.left.right.right = node(6)

root_to_leaf(n, [])
print(longest_distinct_path(n, {}, 0))
