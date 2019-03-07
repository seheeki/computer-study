'''
def BSearchRecur(ar, first, last, target) :
    mid=0

    if first<=last :
        mid= int( (first+last) /2)

        if ar[mid]==target :
            print("return mid: first=%d, last=%d, mid=%d\n" % (first, last, mid))
            return mid
        else:             
            if ar[mid]>target : 
                last = mid -1
                print("last = mid -1: first=%d, last=%d, mid=%d\n" % (first, last, mid))
                return BSearchRecur(ar, first, last, target)
                #BSearchRecur(ar, first, last, target)
            else :
                first = mid +1
                print("first = mid +1: first=%d, last=%d, mid=%d\n" % (first, last, mid))
                return BSearchRecur(ar, first, last, target)
                #BSearchRecur(ar, first, last, target)
    else:
        if first>last :
            print("return -1 first=%d, last=%d, mid=%d\n" % (first, last, mid))
            return -1
        
    print("BSearchRecur first=%d, last=%d, mid=%d\n" % (first, last, mid))
    
if __name__ == "__main__":
    
    arr = ['a', 'b', 'c', 'd', 'f', 'g']
    inputAlphabet=0

    inputAlphabet = input("알파벳을 입력하세요: ")

    
    idx = BSearchRecur(arr, 0, len(arr), inputAlphabet)
    if idx == -1 :
        print("Fail\n")
    else :
        print("Target index : %d\n" % idx)
'''

def print_array(arr, NUM) :

    for k in range(10) :
        print("%d" % arr[k], end =',')

    print("\n")

if __name__ == "__main__":
    arr = [1, 9, 7, 3, 5, 2, 4, 10, 6, 8]
    NUM = 10

    print_array(arr, NUM)

    for i in range(0, NUM-1) :
        for j in range(0, NUM-i-1) :
            if arr[j]>arr[j+1] :
                t = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = t

            print_array(arr, NUM)

        print_array(arr, NUM)

