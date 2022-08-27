def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

def nth_perm_helper(array, n):
    array = sorted(array)
    # If the array contains 1 element or n is 0, then the nth permutation is the array itself.
    if len(array) == 1:
        return [array[0]]
    else:
        # Compute the next element's by finding the floor of n divided by the number of possibilities for the next element.
        # There are len(array) possibilities for the next element.
        current_array_length = len(array)
        # We'll find the next element and the resulting n through the next calculation.
        next_element = n // factorial(current_array_length - 1)
        next_n = n % factorial(current_array_length - 1)
        # We'll find the next element by finding the element at the next_element index in the array.
        next_element = array[next_element]
        # Build the solution array.
        solution = [next_element]
        # Remove the next element from the array.
        array.remove(next_element)
        # Recurse on the remaining array.
        solution.extend(nth_perm_helper(array, next_n))
        # Return the solution array.
        return solution

# This function finds the nth permutation of a provided array, without generating all permutations
def nth_permutation(array, n):
    if n < 0 or n > factorial(len(array)) - 1:
        return None
        # TODO: raise an exception
        # raise Exception("Invalid n, must be between 0 and " + str(factorial(len(array)) - 1))
    return nth_perm_helper(array, n)

def main():
    array = [1, 2, 3, 4, 5]
    n = 115
    print(nth_permutation(array, n))
    # should print [5, 4, 3, 2, 1]

if __name__ == "__main__":
    main()

