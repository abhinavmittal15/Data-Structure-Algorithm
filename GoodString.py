# s1 = input("enter")
# s2 = input("enter")
s1 = "(@HR*i{kcQl"
s2 = "Vyom"
a = [ord(i) for i in s1]
a.sort()
res = 0
prev = ord(s1[0])
for i in s2:
    b = ord(i)
    l, r = 0, len(a)-1
    good = float('inf')
    curr = -1
    while l <= r:
        mid = (l+r)//2
        if a[mid] == b:
            curr = prev
            good = 0
            break
        elif a[mid] < b:
            if abs(a[mid]-b) < good:
                good = abs(a[mid]- b)
                curr = a[mid]
            elif abs(abs[mid]- b) == good:
                if abs(curr - prev) > abs(a[mid] - prev):
                    curr = a[mid]
                    good = abs(a[mid] - prev)
                else: 
                    good = abs(curr - prev)
            l = mid + 1
        else:
            if abs(a[mid] - b) < good:
                good = abs(a[mid] -b)
                curr = a[mid]
            elif abs(a[mid] - b) == good:
                if abs(curr - prev) > abs(a[mid] - prev):
                    curr = a[mid]
                    good = abs(a[mid] - prev)
                else:
                    good = abs(curr - prev)
            r = mid - 1
        prev = curr
        res += good
    print(res)
            